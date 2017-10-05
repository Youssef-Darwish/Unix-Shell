//
// Created by Youssef Darwish on 04/10/17.
//

#include "execute.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "wait.h"
#include "commands.h"
#include "variables.h"
#include "errno.h"
#include "file_processing.h"
void execute(char *path, char **arguments, execution_state state, command_type type) {

    pid_t pid;
    siginfo_t child_status;
    // cd command is handled separately without fork
    if (type == cd_type) {
        cd(arguments);
        return;
    }


    pid = fork();

    if (pid == 0) {
        //check for type
        printf("Child goes here\n");
        //sleep(10);
        if (type == comment) {
            comment_command(arguments);
            return;
        } else if (type == history) {
            history_command();
            //write_in_history_file(arguments);
        } else if (type == echo_type) {
            echo(arguments);
            //write_in_history_file(arguments);
        } else {

            execv(path, arguments);
            //write_in_history_file(arguments);
            exit(errno);
        }
    } else {
        //here check for execution_state
        // upon success add in history & log files
        // upon failure add in log file
        printf("Parent\n");
        if (state == foreground) {
            //printf("waiting...");

            waitid(P_PID, pid, &child_status, WEXITED);
            printf("Error : %d\n", errno);
            printf("Exit :%d\n\n", child_status);
            printf("Child finished\n PID  %d\n",pid);
            //write_in_history_file(arguments);
        }
        return;
    }
}