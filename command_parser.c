#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "command_parser.h"
#include "stdio.h"
#include "unistd.h"

/*
 *  Parsing the command will be on several sequential steps
 *  First : dividing the command to slices (arguments)
 *  Second: determine the type of execution: foreground or background
 *  Third: determine the type of commands :
 *      -cd, commands executed by exec, echo,history,comment
 */

enum execution_state {
    foreground, background
} state;
enum command_type {
    cd, ex, echo_type, history, comment
} type;

void check_execution_type(char **args);

void check_command_type(char **args);

void execute(char **args, enum execution_state state1);

int size;

void parse_command(const char *command) {
    char *pch;
    char *temp = (char *) malloc(10000);
    temp = strcpy(temp, command);
    char **arguments = (char **) malloc(100000);
    pch = strtok(temp, " ");
    int i = 0;
    while (pch != NULL) {
        // printf ("%s\n",pch);
        arguments[i] = pch;
        pch = strtok(NULL, " ");
        i++;
    }
    size = i;
    // printing slices
    int j = 0;
    while (arguments[j] != NULL) {
        // printf("%s\n", arguments[j]);
        j++;
    }
    //int x = execv("/bin/ls", arguments);
    //printf("%d\n", x);
    check_execution_type(arguments);
        check_command_type(arguments);

}

void check_execution_type(char **args) {
    int i = size - 1;


    if (!strcmp(args[i], "&")) {
        state = background;

    } else {
        state = foreground;
    }

}

void check_command_type(char **args) {

    if (!strcmp(args[0], "#")) {
        type = comment;
    } else if (!strcmp(args[0], "cd")) {
        type = cd;
    } else if (!strcmp(args[0],"history")) {
        type=history;
    } else if (!strcmp(args[0], "echo")){
        type=echo_type;
    }else{
        type = ex;
    }
    printf("%s\n",args[0]);
    printf("%d\n",type);
}


// don't forget to handle signals (Ctrl +D)
void execute(char **args, enum execution_state state1) {

}

