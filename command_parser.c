#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "command_parser.h"
#include "stdio.h"
#include "unistd.h"
#include "dirent.h"
#include "variables.h"

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

// modify search_file function : params file & folder
int search_file();

bool is_comment(const char *commmand);

int get_variables(const char *commmand);


char **parse_path(const char *path);

int size;

// use one function for slicing

char **slice_string(const char *string, char *delimiter);

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
    //search_file();

    // don't call execv() in this function : send params to be executed

    //int x = execv("/usr/bin/touch", arguments);
    //printf("%d\n", x);
    //check_execution_type(arguments);
    //check_command_type(arguments);


    char **path_files = parse_path(lookup_variable("PATH"));

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
    } else if (!strcmp(args[0], "history")) {
        type = history;
    } else if (!strcmp(args[0], "echo")) {
        type = echo_type;
    } else {
        type = ex;
    }
    printf("%s\n", args[0]);
    printf("%d\n", type);
}


// don't forget to handle signals (Ctrl +D)
void execute(char **args, enum execution_state state1) {

}

void search_exe_file(const char *path) {

}

int search_file() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("/bin/")) != NULL) {
        /* print all the files and directories within directory */
        int number_of_files = 0;
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
            number_of_files++;
        }
        printf("%d\n", number_of_files);
        closedir(dir);
    } else {
        /* could not open directory */
        perror("");
        return EXIT_FAILURE;
    }

}

char **parse_path(const char *path) {

    char *pch;
    // path cannot be modified so use a temp char * and copy path into temp
    char *temp = (char *) malloc(10000);
    temp = strcpy(temp, path);
    char **path_folders = (char **) malloc(100000);
    pch = strtok(temp, ":");
    int i = 0;
    while (pch != NULL) {
        path_folders[i] = pch;
        pch = strtok(NULL, ":");
        i++;
    }
    int j = 0;
    printf("start of path files: \n\n");
    while (path_folders[j] != NULL) {
        printf("%s\n", path_folders[j]);
        j++;
    }
    printf("End of path files\n\n");
}

