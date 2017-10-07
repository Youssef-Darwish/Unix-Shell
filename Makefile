
Shell: main.o file_processing.o environment.o variables.o command_parser.o execute.o commands.o
	gcc  main.o file_processing.o environment.o variables.o command_parser.o execute.o commands.o -o Shell

main.o: main.c command_parser.h commands.h environment.h variables.h
	gcc -c main.c 

file_processing.o: file_processing.c file_processing.h variables.h
	gcc -c file_processing.c

environment.o: environment.c environment.h variables.h file_processing.h
	gcc -c environment.c

variables.o: variables.c variables.h
	gcc -c variables.c

command_parser.o: command_parser.c command_parser.h execute.h
	gcc -c command_parser.c

execute.o: execute.c execute.h file_processing.h variables.h commands.h 
	gcc -c execute.c

commands.o: commands.c commands.h file_processing.h variables.h
	gcc -c commands.c 

clean:
	rm *.o Shell
