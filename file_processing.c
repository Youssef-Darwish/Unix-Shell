#include "file_processing.h"
#include "variables.h"
#include "string.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

/*
	history file section
*/
FILE *history_file;
FILE *log_file;
FILE *batch_file;

char *history_file_path;
char *log_file_path;

void open_history_file() {

    history_file = fopen(history_file_path, "a+");
}

FILE *get_history_file() {
    return history_file;
}

void write_in_history_file(char **message) {

    int i = 0;
    while (message[i] != NULL) {
        fprintf(history_file, "%s ", message[i]);
        i++;
    }
    fprintf(history_file, "\n");
    fflush(history_file);
}

void close_history_file() {
    fclose(history_file);
}


/* 
	log file section
*/
void open_log_file() {
    if (fopen(log_file_path, "a+") == NULL) {
        printf("cannot open file\n");
    } else
        printf("LOG file: %s\n\n", log_file_path);
}

FILE *get_log_file() {
    return log_file;
}

void close_log_file() {
    printf("before closing\n");
    fclose(log_file);
    printf("after closing\n");

}

void write_in_log_file(char *line) {
    printf("line arrived xD\n\n");
    fprintf(log_file,line);

}


/* 
	CommandsBatch file section
*/
void open_commands_batch_file(char *path) {
    printf("Path to file : %s\n", path);
    batch_file = fopen("/home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/testCases.txt", "r");

}

FILE *get_commands_batch_file() {
    return batch_file;
}

void close_commands_batch_file() {
    // you should implement this function
}

void set_file_paths() {

    history_file_path = malloc(1000);
    log_file_path = malloc(1000);
    history_file_path = strcpy(history_file_path, lookup_variable("FILES_DIRECTORY"));

    history_file_path = strcat(history_file_path, "/history.txt");
    log_file_path = (char *) lookup_variable("FILES_DIRECTORY");
    log_file_path = strcat(log_file_path, "/log.txt");

}