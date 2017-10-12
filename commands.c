#include "commands.h"
#include "stdio.h"
#include "file_processing.h"
#include "variables.h"
#include "string.h"
#include "unistd.h"
#include "stdlib.h"




void cd(const char **path, int params) {

    if (params == 1) {
        path[1] = lookup_variable("HOME");
    }
    char *copy = malloc(100);

    copy = strcpy(copy, path[1]);
    char *current_working_directory = malloc(100);
    if (copy[0] == '/' || copy[0] == '.') {
        chdir(path[1]);
        current_working_directory = getcwd(current_working_directory, 100);
        set_variable("PWD", current_working_directory);
    } else if (!strcmp(copy, "~")) {
        set_variable("PWD", lookup_variable("HOME"));
        chdir(lookup_variable("HOME"));
    } else if (strlen(copy) > 2 && copy[0] == '~' && copy[1] == '/') {


        char *absPath = malloc(strlen(copy) + 1);
        absPath = memcpy(absPath, &copy[1], strlen(copy) - 1);
        absPath[strlen(copy) - 1] = '\0';
        char *current_path;
        current_path = lookup_variable("HOME");
        strcat(current_path, "/");
        strcat(current_path, absPath);

        chdir(current_path);
        current_path = getcwd(current_path, 100);
        set_variable("PWD", current_path);

    } else { //relative path is given

        current_working_directory = getcwd(current_working_directory, 100);
        current_working_directory = strcat(current_working_directory, "/");
        current_working_directory = strcat(current_working_directory, copy);
        if (chdir(current_working_directory) == -1) {
            printf("No such file or directory\n");
            return;
        }
        set_variable("PWD", current_working_directory);
    }
}

/*
 * Echo command prints a message on the screen
 * should first search if a variable exists($) and get its value
 *
 */
void echo(const char **message) {

    int i = 1;
    while (message[i] != NULL) {
        char *word = message[i];
        if (word[0] == '$') {
            word = lookup_variable(word + 1);
            //printf("word from echo:%s\n",word);
            if (!strcmp(word, "")) {
                printf("%s ", message[i]);
            } else {
                printf("%s ", word);
            }
        } else {
            printf("%s ", message[i]);
        }
        i++;
    }
    printf("\n");
}

void history_command() {

    open_history_file();
    FILE *history_file = get_history_file();
    char c;
    int count = 0;

    if (history_file) {
//        char word[280];
//        fgets(word, 280, history_file);
//        puts(word);
        while ((c = (char) getc(history_file)) != EOF) {
            count++;
            printf("%c", c);
        }
        fclose(history_file);
    } else {
        printf("not found\n");
    }
}

void comment_command(char **message) {

//    open_history_file();
//    write_in_history_file(message);
//    close_history_file();
}
