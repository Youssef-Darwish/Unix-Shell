#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "command_parser.h"

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

void execute(char **args);

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
        printf("%s\n", arguments[j]);
        j++;
    }

    check_execution_type(arguments);
    printf("%d\n", state);

}

void check_execution_type(char **args) {
    int i = 0;

    while (i < size - 1) {
        i++;
    }
    // how to use strcmp?
    if (args[i] == "&") {
        state = background;

    } else {
        printf("%s\n", args[i]);
        printf("fore\n");
        state = foreground;
    }

}

void check_command_type(char **args) {


}

void execute(char **args) {

}

