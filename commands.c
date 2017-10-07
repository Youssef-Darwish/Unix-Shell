#include "commands.h"
#include "stdio.h"
#include "file_processing.h"
#include "variables.h"
#include "string.h"
#include "unistd.h"
#include "stdlib.h"



// adding a comment to test Makefile xD

void cd(const char **path, int params) {

    // check if empty ?
    if (params == 1) {
        path[1] = lookup_variable("HOME");
    }
    /*
    if (params>2){
        printf("wrong number of params for cd command!!");
        return;
    }
*/
    char *copy = malloc(100);

    copy = strcpy(copy, path[1]);
    char *current_working_directory = malloc(100);
    //printf("Current working directory before cd command is:\n%s\n\n", lookup_variable("PWD"));
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
        char *current_path = malloc(100);
        current_path = lookup_variable("HOME");
        current_path = strcat(current_path, absPath);

        chdir(current_path);
        current_path = getcwd(current_path, 100);
        set_variable("PWD", current_path);

    } else { //relative path is given

        current_working_directory = getcwd(current_working_directory, 100);
        current_working_directory = strcat(current_working_directory,"/");
        current_working_directory = strcat(current_working_directory,copy);
        chdir(current_working_directory);
        set_variable("PWD", current_working_directory);
    }
    //printf("Current working directory after cd command is:\n%s\n\n", lookup_variable("PWD"));
/*
    chdir(path);
    set_variable("PWD", path);
    */
    //printf("%s\n\n", lookup_variable("PWD"));
    //free(current_working_directory);
    //free(copy);
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
    printf("opened\n\n");
    char c;
    int count = 0;

    if (history_file) {
        char word[280];
        fgets(word, 280, history_file);
        puts(word);
        while ((c = (char) getc(history_file)) != EOF) {
            count++;
            printf("%c", c);
        }
        printf("Counter : %d\n", count);
        fclose(history_file);
    } else {
        printf("not found\n");
    }
}

void comment_command(char **message) {

    open_history_file();
    write_in_history_file(message);
    close_history_file();
}
