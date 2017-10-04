#include <stdlib.h>
#include "variables.h"
#include "string.h"
#include "stdio.h"

char **keys_saved;
char **values_saved;
int keys_number;

const char *lookup_variable(const char *key) {
    int j=0;
    while(j<keys_number){
        if (!strcmp(key,keys_saved[j])){

            printf("looked up\n%s\n",values_saved[j]);
            return values_saved[j];
        }
        j++;
    }

   // should indicate if not found
}

void set_variable(const char *key, const char *value) {

    int i = 0;
    while (i < keys_number) {
        if (!strcmp(keys_saved[i], key)) {

            values_saved[i] = (char *)value;
            //printf("value saved\n\n");
            //printf("%s\n",value);
            return;
        }
        i++;
    }
    // new variable
    keys_saved[i] = key;
    values_saved[i] = value;
    keys_number++;


}

void print_all_variables(void) {
    int j = 0;
    while (j < keys_number) {
        printf("%s\n", values_saved[j]);
        j++;
    }
    // you should implement this function
}

void set_up_variables() {
    keys_saved = malloc(1000000);
    values_saved = malloc(100000);
    keys_number = 0;
}