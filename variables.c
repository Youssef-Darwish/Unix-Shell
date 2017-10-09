#include <stdlib.h>
#include "variables.h"
#include "string.h"
#include "stdio.h"

char **keys_saved;
char **values_saved;
int keys_number;

const char *lookup_variable(const char *key) {
    int j = 0;
    while (j < keys_number) {
        if (!strcmp(key, keys_saved[j])) {

            //printf("looked up %s\n%s\n",key,values_saved[j]);
            return values_saved[j];
        }
        j++;
    }
    return "";
}

void set_variable(const char *key, const char *value) {

    int i = 0;
    while (i < keys_number) {
        if (!strcmp(keys_saved[i], key)) {

            values_saved[i] = (char *) value;
            //printf("value saved\n\n");
            //printf("%s\n",value);
            return;
        }
        i++;
    }
    // new variable
    keys_saved[i] = (char *) key;
    values_saved[i] = (char *) value;
    keys_number++;
}

void print_all_variables(void) {
    int j = 0;
    if(keys_number>3)

    while (j < keys_number) {
        printf("%s :%s\n", keys_saved[j], values_saved[j]);
        j++;
    }
    // you should implement this function
}

void set_up_variables() {
    keys_saved = malloc(10000);
    values_saved = malloc(10000);
    keys_number = 0;
}