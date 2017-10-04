
#include <string.h>
#include "environment.h"
#include "commands.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "command_parser.h"
#include "variables.h"
#include "file_processing.h"
#include "commands.h"

typedef enum {
    false = 0, true = 1
} bool;

void start_shell(bool read_from_file);

void shell_loop(bool input_from_file);

int main(int argc, char *argv[]) {


    setup_environment();
    //cd(""); // let shell starts from home
    parse_command("ls ");
    //cd("~");
    //parse_command("ls");
    // any other early configuration should be here
/*
    if (argc > 1) {
        start(true);
    } else {
        start(false);
    }
*/
    return 0;
}

void start(bool read_from_file) {
    if (read_from_file) {
        // file processing functions should be called from here

        shell_loop(true);
    } else {
        shell_loop(false);
    }
}

void shell_loop(bool input_from_file) {
    bool from_file = input_from_file;

    while (true) {
        char * command = malloc(1000);
        if (from_file) {
            //read next instruction from file

            // if end of file {from_file = false; continue;}
        } else {
            //read next instruction from console
            printf("Shell>");
            command = fgets(command,200,stdin);

        }
            parse_command(command);
        //parse your command here

        //execute your command here

        /*
            you don't need to write all logic here, a better practice is to call functions,
            each one contains a coherent set of logical instructions
        */
    }
}
