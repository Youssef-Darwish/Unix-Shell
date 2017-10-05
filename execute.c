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

void execute(char *path, char **arguments, execution_state state, command_type type) {

    pid_t pid;
    //pid = getpid();
    //printf("Process ID: \n%d\n", pid);


    // cd command is handled separately without fork
    if (type == cd_type) {
        cd(arguments);
        return;
    }


    pid = fork();

    // for cd and echo commands: let the path be the message? xD

    if (pid == 0) {
        //check for type
        printf("Child goes here\n");
        //sleep(10);
        if (type == comment) {
            comment_command(arguments);
        } else if (type == history) {
            history_command();
        } else if (type == echo_type) {
            echo(arguments);
        } else {

            execv(path, arguments);

        }

        exit(0);
    } else {
        //here check for execution_state
        // upon success add in history & log files
        // upon failure add in log file
        printf("Parent\n");
        if (state == foreground) {
            //printf("waiting...");

            waitid(P_PID, pid, NULL, WEXITED);
        }


        return;
    }
}