#include <stdlib.h>
#include "variables.h"
#include "string.h"
#include "stdio.h"

char **keys;
char **values;
int keys_number;

const char *lookup_variable(const char *key) {
    int j=0;
    while(j<keys_number){
        if (strcmp(key[j],keys[j])){
            return values[j];
        }
        j++;
    }

   // should indicate if not found
}

void set_variable(const char *key, const char *value) {

    int i = 0;
    while (i < keys_number) {
        if (strcmp(keys[i], key)) {
            values[i] = value;
            return;
        }
        i++;
    }
    // new variable
    keys[i] = key;
    values[i] = value;
    keys_number++;

    // you should implement this function
}

void print_all_variables(void) {
    int j = 0;
    while (j < keys_number) {
        printf("%s\n", values[j]);
        j++;
    }
    // you should implement this function
}

void set_up_variables() {
    keys = malloc(1000000);
    values = malloc(100000);
    keys_number = 0;
}