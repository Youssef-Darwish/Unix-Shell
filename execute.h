
#include "signal.h"
#ifndef EXECUTE_H
#define EXECUTE_H


typedef enum {
    foreground, background
} execution_state;

typedef enum {
    cd_type, ex, echo_type, history, comment
} command_type;

void execute(char *path, char **arguments, execution_state state, command_type typem,int numberOfParams);

void multi_handler(int sig, siginfo_t *siginfo, void *context);
void assign_signal();

#endif //UNIX_SHELL_EXECUTE_H
