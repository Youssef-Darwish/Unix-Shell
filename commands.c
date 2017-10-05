#include "commands.h"
#include "stdio.h"
#include "file_processing.h"
#include "variables.h"
#include "string.h"
#include "unistd.h"
#include "stdlib.h"

char *getVars(char *word);

void cd(const char **path) {

    // check if empty ?

    char *copy = malloc(100);
    copy = strcpy(copy, path[1]);
    char * current_working_firectory = malloc(100);
    if (copy[0] == '/' || copy[0] == '.') {
        chdir(path[1]);
        current_working_firectory = getcwd(current_working_firectory,100);
        set_variable("PWD", current_working_firectory);
    } else if (copy[0] == '~') {
        set_variable("PWD", lookup_variable("HOME"));
        chdir(lookup_variable("HOME"));

    } else if (copy[0] == ' ' || copy[0] == NULL) {
        chdir(lookup_variable("HOME"));
        set_variable("PWD", lookup_variable("HOME"));
    }else { //relative path is given
        chdir(strcat((char *)lookup_variable("PWD"),path));
        current_working_firectory = getcwd(current_working_firectory,100);
        set_variable("PWD", current_working_firectory);
    }

/*
    chdir(path);
    set_variable("PWD", path);
    */
    printf("%s\n\n", lookup_variable("PWD"));
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

    // get history file & write
}
