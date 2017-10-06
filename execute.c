//
// Created by Youssef Darwish on 04/10/17.
//

#include <string.h>
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
        open_history_file();
        write_in_history_file(arguments);
        close_history_file();
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

            if (execv(path, arguments) == -1) {
                printf("exit failure\n");
                exit(EXIT_FAILURE);
            }
            //write_in_history_file(arguments);
            //exit(errno);
        }
    } else {
        //here check for execution_state
        // upon success add in history & log files
        // upon failure add in log file
        printf("Parent\n");
        if (state == foreground) {
            //printf("waiting...");
            errno=0;
            waitid(P_PID, pid, &child_status, WEXITED);
            printf("Error : %d\n", errno);
            printf("Exit :%d\n\n", child_status);
            printf("Child finished\n PID  %d\n", pid);
            open_history_file();
            write_in_history_file(arguments);
            close_history_file();
            //open_log_file();
            //printf("opened");
            //write_in_log_file("Child process terminated");

            //write_in_history_file(arguments);
        }

    }
}