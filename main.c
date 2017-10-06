#include "command_parser.h"
#include "environment.h"
#include "commands.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <stdio.h>

typedef enum {
    false = 0, true = 1
} bool;

static bool keep_running = true;
void start_shell(bool read_from_file);

void shell_loop(bool input_from_file);

int main(int argc, char *argv[]) {

    //signal(SIGINT, interrupt_handler);

    setup_environment();
    char ** temp = malloc(11221);
    temp[1]="/home/youssef/Downloads";

    cd(temp); // let shell starts from home
    parse_command("pwd");
    //parse_command("cd /home/youssef/Desktop");
    //parse_command("ls");

    //temp[1] = "../Desktop";
    //cd(temp);
    //parse_command("ls");
    //cd("~");
    //parse_command("ls");
    // any other early configuration should be here

    if (argc > 1) {
        start(true);
    } else {
        start(false);
    }

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

    while (keep_running) {
        //printf(" PWD: %s\n\n",lookup_variable("PWD"));
        char * temp = getcwd(temp,100);
        char * command = malloc(1000);
        printf("PWD : %s\n\n",temp);
        if (from_file) {
            //read next instruction from file

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
/*
void intHandler(int) {
    keepRunning = false;
}
 */