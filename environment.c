#include "environment.h"
#include "variables.h"
#include "stdio.h"
#include "stdlib.h"

/*
 * This function imports the needed variables as path,home,pwd and stores them
 * in the lookup table
 */
void setup_environment( void )
{
    printf("test");
    const char * path =getenv("PATH");
    printf("%s\n",path);
    set_variable("PATH",path);
    const char * home = getenv("HOME");
    printf("%s\n",home);
    set_variable("HOME",home);
    const char * current_directory = getenv("PWD");
    printf("%s/n",current_directory);
    set_variable("PWD",current_directory);
}