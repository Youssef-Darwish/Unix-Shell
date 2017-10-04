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

char *search_file(const char *file, char *directory, int flag);

int get_variables(const char *command);   // needed in echo & comment only ?

char **slice_string(const char *string, char *delimiter);

void parse_command(const char *command) {

    char **arguments = slice_string(command, " ");
    char **path_files = slice_string(getenv("PATH"), ":");
    check_execution_type(arguments);
    check_command_type(arguments);
    char *path_flag = arguments[0];

    int absolute_path_flag = 0;
    if (path_flag[0] == '/') {
        absolute_path_flag = 1;
    }

    // make a function to get exe file?

    int index = 0;
    char *exe_file = "";
    while (path_files[index] != NULL) {
        //printf("%s\n", path_files[index]);
        exe_file = search_file(arguments[0], path_files[index], absolute_path_flag);
        // if file is not found
        if (!strcmp(exe_file, "")) {
            index++;
            continue;
        }
        // file found
        printf("founddddd\n\n");
        printf("%s\n", exe_file);
        break;
    }
    //execv(exe_file,arguments);
}

void check_execution_type(char **args) {
    int i = 0;
    while (args[i + 1] != NULL) {
        i++;
    }
    if (!strcmp(args[i], "&")) {
        state = background;
    } else {
        state = foreground;
    }
}

void check_command_type(char **args) {

    if (!strcmp(args[0], "cd")) {
        type = cd;
    } else if (!strcmp(args[0], "history")) {
        type = history;
    } else if (!strcmp(args[0], "echo")) {
        type = echo_type;
    } else {
        char *first_arg = args[0];
        if (first_arg[0] == '#') {
            type = comment;
        } else {
            type = ex;
        }
    }
    //printf("%s\n", args[0]);
    //printf("%d\n", type);
}


char *search_file(const char *file, char *directory, int flag) {

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(directory)) != NULL) {
        printf("directory opened\n");
        int number_of_files = 0;
        while ((ent = readdir(dir)) != NULL) {
            char *file_name = ent->d_name;
            if (flag) {
                // absolute path and not a file name
                char *path_found = malloc(100);
                path_found = strcpy(path_found, directory);
                path_found = strcat(path_found, "/");
                path_found = strcat(path_found, file_name);
                if (!strcmp(path_found, file)) {
                    return path_found;
                }
            } else {
                if (!strcmp(file_name, file)) {
                    // printf("found\n");
                    char *path_found = malloc(100);
                    path_found = strcpy(path_found, directory);
                    path_found = strcat(path_found, "/");
                    strcat(path_found, file);
                    return path_found;
                }
            }
            number_of_files++;
        }
        printf("Number of files :%d\n", number_of_files);
        closedir(dir);
    } else {
        /* could not open directory */
        perror("");
        printf("errorrrrr\n");
    }
    return "";
}

char **slice_string(const char *string, char *delimiter) {
    char *pch;
    // path cannot be modified so use a temp char * and copy path into temp
    char *temp = (char *) malloc(10000);
    temp = strcpy(temp, string);
    char **sliced_string = (char **) malloc(100000);
    pch = strtok(temp, delimiter);
    int i = 0;
    while (pch != NULL) {
        sliced_string[i] = pch;
        pch = strtok(NULL, delimiter);
        i++;
    }
    int j = 0;
    // printing files in path variable
    printf("printing slices \n\n\n");
    while (sliced_string[j] != NULL) {

        printf("%s\n", sliced_string[j]);
        j++;
    }
    printf("end of printing slices\n\n");
    return sliced_string;

}

