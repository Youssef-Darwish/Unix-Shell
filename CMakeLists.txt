cmake_minimum_required(VERSION 3.8)
project(Unix_Shell)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        command_parser.c
        command_parser.h
        commands.c
        commands.h
        environment.c
        environment.h
        file_processing.c
        file_processing.h
        main.c
        variables.c
        variables.h execute.h execute.c)

add_executable(Unix_Shell ${SOURCE_FILES})