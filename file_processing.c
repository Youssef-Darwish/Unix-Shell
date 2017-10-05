#include "file_processing.h"
#include "variables.h"
#include "string.h"

/*
	history file section
*/
FILE *history_file;

void open_history_file() {
    char *path = (char *) lookup_variable("PWD");
    printf("%s\n",path);

    path = "history.txt";
    printf("%s\n",path);
    history_file = fopen(path, "r+");
}

FILE *get_history_file() {
    return history_file;
}

void close_history_file() {
    // you should implement this function
}


/* 
	log file section
*/
void open_log_file() {
    // you should implement this function
}

FILE *get_log_file() {
    // you should implement this function
}

void close_log_file() {
    // you should implement this function
}


/* 
	CommandsBatch file section
*/
void open_commands_batch_file() {
    // you should implement this function
}

FILE *get_commands_batch_file() {
    // you should implement this function
}

void close_commands_batch_file() {
    // you should implement this function
}