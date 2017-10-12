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


void execute(char *path, char **arguments, execution_state state,
             command_type type, int numberOfParams) {

    pid_t pid;
    siginfo_t child_status;
    // cd command is handled separately without fork
    if (type == cd_type) {
        cd(arguments, numberOfParams);
        return;
    }
    pid = fork();
    if (pid == 0) {
        if (type == history) {
            history_command();
        } else if (type == echo_type) {
            echo(arguments);
        } else {

            if (execv(path, arguments) == -1) {
                printf("exit failure\n");
                kill(getppid(), SIGCHLD);
                exit(1);
            } else {
                exit(0);
            }
        }
    } else {
        if (state == foreground) {
            waitid(P_PID, pid, &child_status, WEXITED);
            open_log_file();
            char *line = "Child process terminated";
            write_in_log_file(line);
            close_log_file();
        }
    }

}
