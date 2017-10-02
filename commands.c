#include "commands.h"
#include "stdio.h"
#include "file_processing.h"
#include "variables.h"
#include "string.h"
void cd( const char* path )
{

    // you should implement this function
}  

/*  Echo command prints a message on the screen
 *  Should first search if a variable exists($) and get its value
 *
 */
void echo( const char* message )
{

}
void history_command(){

    FILE * history_file;
    char *path = (char *) lookup_variable("PWD");
    printf("%s\n",path);

    path = strcat(path,"/history.txt");
    //printf("%s\n",path);
    history_file = fopen(path,"w");


    

}