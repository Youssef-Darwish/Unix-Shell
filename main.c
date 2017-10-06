#include "command_parser.h"
#include "environment.h"
#include "commands.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <stdio.h>
#include "file_processing.h"
#include "variables.h"
typedef enum {
    false = 0, true = 1
} bool;

static bool keep_running = true;
FILE *batch_file;
char **file_arg;

void start_shell(bool read_from_file);

void shell_loop(bool input_from_file);


int main(int argc, char *argv[]) {

    //signal(SIGINT, interrupt_handler);

    setup_environment();
    char **temp = malloc(100);
    temp[1] = lookup_variable("HOME");
    cd(temp); // let shell starts from home
    //parse_command("ls");
    // any other early configuration should be here
    file_arg = argv;
    free(temp);
    if (argc > 1) {
        start(true);
    } else {
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
        batch_file = get_commands_batch_file();
        shell_loop(read_from_file);
    } else {
        shell_loop(read_from_file);
    }
}

void shell_loop(bool input_from_file) {
    bool from_file = input_from_file;

    while (keep_running) {
        //printf(" PWD: %s\n\n",lookup_variable("PWD"));
        char *temp = getcwd(temp, 100);
        char *command = malloc(1000);
        printf("PWD : %s\n\n", temp);
        if (from_file) {
            //read next instruction from file

            if (getline(&command, 100, batch_file) != -1) {
                printf("COMMAND FROM FILE : %s\n", command);
                parse_command(command);
            }

            // if end of file {from_file = false; continue;}
        } else {
            //read next instruction from console
            printf("Shell>");
            printf("contined to next instruction\n\n");
            gets(command);
        }
        //printf(" command: %s.",command);

        parse_command(command);
        free(command);
        //parse your command here

        //execute your command here

        /*
            you don't need to write all logic here, a better practice is to call functions,
            each one contains a coherent set of logical instructions
        */
    }
}
