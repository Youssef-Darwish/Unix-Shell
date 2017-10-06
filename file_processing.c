#include "file_processing.h"
#include "variables.h"
#include "string.h"

/*
	history file section
*/
FILE *history_file;
FILE *log_file;
FILE * batch_file;
void open_history_file() {
    char *path = (char *) lookup_variable("FILES_DIRECTORY");
    printf("History File path :    %s\n",path);

    // hard coding path for now only  instead use pwd
    path = "/home/youssef/Desktop/OS/Unix-Shell/history.txt";
    printf("%s\n",path);
    history_file = fopen(path, "a+");
}

FILE *get_history_file() {
    return history_file;
}
void write_in_history_file(char ** message){

    int i=0;
    while(message[i]!=NULL){
        fprintf(history_file,"%s ",message[i]);
        i++;
    }

}

void close_history_file() {
    fclose(history_file);
}


/* 
	log file section
*/
void open_log_file() {
    char *path = (char *) lookup_variable("PWD");
    printf("%s\n",path);
    // hard coding path for now only
    path = "/home/youssef/Desktop/log.txt";
    printf(" LOG FILE PATH\n%s\n",path);
    log_file = fopen(path, "a+");

}

FILE *get_log_file() {
    return log_file;
}

void close_log_file() {
    // you should implement this function
}
void write_in_log_file(char * line){
    int i=0;
    while(line[i]!=NULL){
        fprintf(log_file,"%s ",line[i]);
        i++;
    }
}


/* 
	CommandsBatch file section
*/
void open_commands_batch_file(char * path) {
    printf("Paht to file : %s\n",path);
    batch_file = fopen(path,"r");

    // you should implement this function
}

FILE *get_commands_batch_file() {
    return batch_file;
}

void close_commands_batch_file() {
    // you should implement this function
}