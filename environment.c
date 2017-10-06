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
    set_up_variables();
    const char * path =getenv("PATH");

    set_variable("PATH",path);
    const char * home = getenv("HOME");
    set_variable("HOME",home);
    const char * files_directory = getenv("PWD");
    set_variable("PWD",files_directory);
    set_variable("FILES_DIRECTORY",files_directory);

    printf("FILES DIRECTORY : %s\n\n",lookup_variable("FILES_DIRECTORY"));
    // setting the default current directory to home

    //printf("%s\n",path);
  /*  printf("%s\n",path);
    printf("%s\n",files_directory);
    printf("%s\n",home);
    printf("%s\n",current_directory);
    */
}