#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "command_parser.h"


void parse_command( const char* command )
{
    char * pch;
    char * temp =(char *) malloc(10000);
          temp =  strcpy(temp,command);
    char ** arguments = (char **) malloc(100000);
    pch = strtok (temp, " ");
    int i =0;
    while (pch != NULL)
    {
       // printf ("%s\n",pch);
        arguments[i] = pch;
        pch = strtok (NULL, " ");
        i++;
    }
    int j=0;
    while(arguments[j]!=NULL){
        printf("%s\n",arguments[j]);
        j++;
    }

}


/*
 * slicing string
 *
	char str[] =" This a       sample    -l -a      string                     ";
	char * pch;

	pch = strtok (str," ");
	while (pch != NULL)
	{
		printf ("%s\n",pch);
		pch = strtok (NULL, " ");
	}

 *
 */