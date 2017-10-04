//
// Created by youssef on 04/10/17.
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
    pid = getpid();
    printf("Process ID: \n%d\n", pid);
    pid = fork();

    // for cd and echo commands: let the path be the message? xD

    if (pid == 0) {
        //check for type
        printf("Child goes here\n");
        if (type == cd_type) {
            //cd(arguments);
        } else if (type == comment) {

        } else if (type == history) {

        } else if (type == echo_type) {

        } else {
            execv(path, arguments);
        }

    } else {
        //here check for execution_state
        // upon success add in history & log files
        // upon failure add in log file
        printf("Parent\n");
        waitid(P_PID, pid, NULL, WEXITED);
        printf("child terminated\n\n");
        return;
    }
}