#include "command_parser.h"
#include "environment.h"
#include "commands.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <stdio.h>
#include <wait.h>
#include "file_processing.h"
#include "variables.h"
#include "signal.h"

typedef enum {
    false = 0, true = 1
} bool;
int parent_id;
static bool keep_running = true;
FILE *batch_file;
char **file_arg;


void shell_loop(bool input_from_file);



int main(int argc, char *argv[]) {

    parent_id = getpid();

    setup_environment();

    file_arg = argv;
    if (argc > 1) {
        start(true);
    } else {
        // let shell starts from home
        char **temp = malloc(100);
        temp[1] = lookup_variable("HOME");
        cd(temp, 2);
        start(false);
    }

    return 0;
}

void start(bool read_from_file) {

    if (read_from_file) {
        printf("read from file\n\n");
        open_commands_batch_file(file_arg[1]);
        batch_file = get_commands_batch_file();
        if (batch_file) {
            printf("file found\n\n");
        } else {
            printf("no such batch file\n");
            read_from_file = false;
        }

        shell_loop(read_from_file);
    } else {
        shell_loop(read_from_file);
    }
}

void shell_loop(bool input_from_file) {
    bool from_file = input_from_file;
    while (keep_running) {
        char *command = malloc(1000);
        if (from_file) {
            //read instruction from file
            if (fgets(command, 520, batch_file) != NULL) {
                printf("COMMAND FROM FILE :%s\n", command);
                command[strlen(command) - 1] = '\0';
            } else {
                close_commands_batch_file();
                break;
            }

        } else {
            //read next instruction from console
            printf("%s/ ", lookup_variable("PWD"));
            printf("Shell>");
            if (gets(command) == NULL) {
                keep_running = false;
                continue;
            }
        }

        if (parse_command(command) == 1)
            break;
        free(command);
    }
}
