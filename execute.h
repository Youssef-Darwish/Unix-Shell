//
// Created by Youssef Darwish on 04/10/17.
//

#ifndef EXECUTE_H
#define EXECUTE_H


typedef enum{
    foreground,background
}execution_state;

typedef enum {
    cd_type, ex, echo_type, history, comment
}command_type;

void execute(char * path, char ** arguments, execution_state state,command_type type);
#endif //UNIX_SHELL_EXECUTE_H