#include <string.h>
#include <stdlib.h>
#include "command_parser.h"
#include "stdio.h"
#include "unistd.h"
#include "dirent.h"
#include "variables.h"
#include "execute.h"
#include "file_processing.h"
/*
 *  Parsing the command will be on several sequential steps
 *  First : dividing the command to slices (arguments)
 *  Second: determine the type of execution: foreground or background
 *  Third: determine the type of commands :
 *      -cd, commands executed by exec, echo,history,comment
 *  followed by extracting variables,searching for executable files
 *  and then sending all params to be executed
 *
 */
//declarations


command_type type;
execution_state state;

void check_execution_type(char **args);

void check_command_type(char **args);

char *search_file(const char *file, char *directory, int flag);

char **slice_string(const char *string, char *delimiter, int *params);

char **extract_variables(char **arguments);

char **exclude_ampersand(char **args);
//end of declarations

int parse_command(const char *command) {
//return 0 on if the command is not exit command
    int commandParams = 0;
    int pathParams = 0;
    int assignmentParams = 0;

    char **variable_assignment = slice_string(command, "=", &assignmentParams);

    if (assignmentParams == 2) {
        set_variable(variable_assignment[0], variable_assignment[1]);
        return 0;
    }

    char **arguments = slice_string(command, " ", &commandParams);
    if (commandParams == 0)
        return 0;
    if (!strcmp(arguments[0], "exit"))
        return 1;
    open_history_file();
    write_in_history_file(arguments);
    close_history_file();
    check_command_type(arguments);
    if (type == comment)
        return 0;
    check_execution_type(arguments);
    if (state == background && type != comment) {
        arguments = exclude_ampersand(arguments);
    }
    arguments = extract_variables(arguments);

    // if command is not executed by :execv, no need to check the path of .exe file
    //send it directly to execute
    if (type != ex) {
        execute("", arguments, state, type, commandParams);
    } else {
        char **path_files = slice_string(getenv("PATH"), ":", &pathParams);

        char *path_flag = arguments[0];

        int absolute_path_flag = 0;
        if (path_flag[0] == '/') {
            absolute_path_flag = 1;
        }
        int index = 0;
        char *exe_file = "";
        while (path_files[index] != NULL) {
            exe_file = search_file(arguments[0], path_files[index], absolute_path_flag);
            // if file is not found, empty string is returned
            if (!strcmp(exe_file, "")) {
                index++;
                continue;
            }
            // file found
            break;
        }
        if (!strcmp(exe_file, "")) {
            printf("Invalid Command!\n\n");
            //free(arguments);
            //free(path_files);
            return 0;
        }
        execute(exe_file, arguments, state, type, commandParams);
    }
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
        type = cd_type;
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
}


char *search_file(const char *file, char *directory, int flag) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(directory)) != NULL) {
        int number_of_files = 0;
        while ((ent = readdir(dir)) != NULL) {
            char *file_name = ent->d_name;
            if (flag) {
                // absolute path and not a file name i.e. /bin/ls
                char *path_found = malloc(100);
                path_found = strcpy(path_found, directory);
                path_found = strcat(path_found, "/");
                path_found = strcat(path_found, file_name);
                if (!strcmp(path_found, file)) {
                    return path_found;
                }
            } else {
                if (!strcmp(file_name, file)) {  //file found
                    char *path_found = malloc(100);
                    strcpy(path_found, directory);
                    strcat(path_found, "/");
                    strcat(path_found, file);
                    return path_found;
                }
            }
            number_of_files++;
        }
        closedir(dir);
    } else {
        /* could not open directory */
        perror("File not found");
    }
    return "";
}

char **slice_string(const char *string, char *delimiter, int *params) {
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
    *params = i;
    sliced_string[i] = NULL;
    return sliced_string;

}

char **exclude_ampersand(char **args) {

    int i = 0;
    char **modified_arguments = malloc(1000);
    while (args[i + 1] != NULL) {
        modified_arguments[i] = args[i];
        i++;
    }
    return modified_arguments;
}

char **extract_variables(char **arguments) {

    int i = 0;
    while (arguments[i] != NULL) {
        char *word = arguments[i];
        if (word[0] == '$') {
            char *replaced_var = lookup_variable(word + 1);

            if (!strcmp(replaced_var, "")) {

                //continue;
            } else {
                arguments[i] = replaced_var;

            }

        }
        i++;
    }
    return arguments;
}