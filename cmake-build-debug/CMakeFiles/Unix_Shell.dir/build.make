# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/youssef/Desktop/OS/Unix-Shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Unix_Shell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Unix_Shell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Unix_Shell.dir/flags.make

CMakeFiles/Unix_Shell.dir/command_parser.c.o: CMakeFiles/Unix_Shell.dir/flags.make
CMakeFiles/Unix_Shell.dir/command_parser.c.o: ../command_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Unix_Shell.dir/command_parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Unix_Shell.dir/command_parser.c.o   -c /home/youssef/Desktop/OS/Unix-Shell/command_parser.c

CMakeFiles/Unix_Shell.dir/command_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Unix_Shell.dir/command_parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/youssef/Desktop/OS/Unix-Shell/command_parser.c > CMakeFiles/Unix_Shell.dir/command_parser.c.i

CMakeFiles/Unix_Shell.dir/command_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Unix_Shell.dir/command_parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/youssef/Desktop/OS/Unix-Shell/command_parser.c -o CMakeFiles/Unix_Shell.dir/command_parser.c.s

CMakeFiles/Unix_Shell.dir/command_parser.c.o.requires:

.PHONY : CMakeFiles/Unix_Shell.dir/command_parser.c.o.requires

CMakeFiles/Unix_Shell.dir/command_parser.c.o.provides: CMakeFiles/Unix_Shell.dir/command_parser.c.o.requires
	$(MAKE) -f CMakeFiles/Unix_Shell.dir/build.make CMakeFiles/Unix_Shell.dir/command_parser.c.o.provides.build
.PHONY : CMakeFiles/Unix_Shell.dir/command_parser.c.o.provides

CMakeFiles/Unix_Shell.dir/command_parser.c.o.provides.build: CMakeFiles/Unix_Shell.dir/command_parser.c.o


CMakeFiles/Unix_Shell.dir/commands.c.o: CMakeFiles/Unix_Shell.dir/flags.make
CMakeFiles/Unix_Shell.dir/commands.c.o: ../commands.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Unix_Shell.dir/commands.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Unix_Shell.dir/commands.c.o   -c /home/youssef/Desktop/OS/Unix-Shell/commands.c

CMakeFiles/Unix_Shell.dir/commands.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Unix_Shell.dir/commands.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/youssef/Desktop/OS/Unix-Shell/commands.c > CMakeFiles/Unix_Shell.dir/commands.c.i

CMakeFiles/Unix_Shell.dir/commands.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Unix_Shell.dir/commands.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/youssef/Desktop/OS/Unix-Shell/commands.c -o CMakeFiles/Unix_Shell.dir/commands.c.s

CMakeFiles/Unix_Shell.dir/commands.c.o.requires:

.PHONY : CMakeFiles/Unix_Shell.dir/commands.c.o.requires

CMakeFiles/Unix_Shell.dir/commands.c.o.provides: CMakeFiles/Unix_Shell.dir/commands.c.o.requires
	$(MAKE) -f CMakeFiles/Unix_Shell.dir/build.make CMakeFiles/Unix_Shell.dir/commands.c.o.provides.build
.PHONY : CMakeFiles/Unix_Shell.dir/commands.c.o.provides

CMakeFiles/Unix_Shell.dir/commands.c.o.provides.build: CMakeFiles/Unix_Shell.dir/commands.c.o


CMakeFiles/Unix_Shell.dir/environment.c.o: CMakeFiles/Unix_Shell.dir/flags.make
CMakeFiles/Unix_Shell.dir/environment.c.o: ../environment.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Unix_Shell.dir/environment.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Unix_Shell.dir/environment.c.o   -c /home/youssef/Desktop/OS/Unix-Shell/environment.c

CMakeFiles/Unix_Shell.dir/environment.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Unix_Shell.dir/environment.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/youssef/Desktop/OS/Unix-Shell/environment.c > CMakeFiles/Unix_Shell.dir/environment.c.i

CMakeFiles/Unix_Shell.dir/environment.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Unix_Shell.dir/environment.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/youssef/Desktop/OS/Unix-Shell/environment.c -o CMakeFiles/Unix_Shell.dir/environment.c.s

CMakeFiles/Unix_Shell.dir/environment.c.o.requires:

.PHONY : CMakeFiles/Unix_Shell.dir/environment.c.o.requires

CMakeFiles/Unix_Shell.dir/environment.c.o.provides: CMakeFiles/Unix_Shell.dir/environment.c.o.requires
	$(MAKE) -f CMakeFiles/Unix_Shell.dir/build.make CMakeFiles/Unix_Shell.dir/environment.c.o.provides.build
.PHONY : CMakeFiles/Unix_Shell.dir/environment.c.o.provides

CMakeFiles/Unix_Shell.dir/environment.c.o.provides.build: CMakeFiles/Unix_Shell.dir/environment.c.o


CMakeFiles/Unix_Shell.dir/file_processing.c.o: CMakeFiles/Unix_Shell.dir/flags.make
CMakeFiles/Unix_Shell.dir/file_processing.c.o: ../file_processing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Unix_Shell.dir/file_processing.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Unix_Shell.dir/file_processing.c.o   -c /home/youssef/Desktop/OS/Unix-Shell/file_processing.c

CMakeFiles/Unix_Shell.dir/file_processing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Unix_Shell.dir/file_processing.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/youssef/Desktop/OS/Unix-Shell/file_processing.c > CMakeFiles/Unix_Shell.dir/file_processing.c.i

CMakeFiles/Unix_Shell.dir/file_processing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Unix_Shell.dir/file_processing.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/youssef/Desktop/OS/Unix-Shell/file_processing.c -o CMakeFiles/Unix_Shell.dir/file_processing.c.s

CMakeFiles/Unix_Shell.dir/file_processing.c.o.requires:

.PHONY : CMakeFiles/Unix_Shell.dir/file_processing.c.o.requires

CMakeFiles/Unix_Shell.dir/file_processing.c.o.provides: CMakeFiles/Unix_Shell.dir/file_processing.c.o.requires
	$(MAKE) -f CMakeFiles/Unix_Shell.dir/build.make CMakeFiles/Unix_Shell.dir/file_processing.c.o.provides.build
.PHONY : CMakeFiles/Unix_Shell.dir/file_processing.c.o.provides

CMakeFiles/Unix_Shell.dir/file_processing.c.o.provides.build: CMakeFiles/Unix_Shell.dir/file_processing.c.o


CMakeFiles/Unix_Shell.dir/main.c.o: CMakeFiles/Unix_Shell.dir/flags.make
CMakeFiles/Unix_Shell.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Unix_Shell.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Unix_Shell.dir/main.c.o   -c /home/youssef/Desktop/OS/Unix-Shell/main.c

CMakeFiles/Unix_Shell.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Unix_Shell.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/youssef/Desktop/OS/Unix-Shell/main.c > CMakeFiles/Unix_Shell.dir/main.c.i

CMakeFiles/Unix_Shell.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Unix_Shell.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/youssef/Desktop/OS/Unix-Shell/main.c -o CMakeFiles/Unix_Shell.dir/main.c.s

CMakeFiles/Unix_Shell.dir/main.c.o.requires:

.PHONY : CMakeFiles/Unix_Shell.dir/main.c.o.requires

CMakeFiles/Unix_Shell.dir/main.c.o.provides: CMakeFiles/Unix_Shell.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Unix_Shell.dir/build.make CMakeFiles/Unix_Shell.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Unix_Shell.dir/main.c.o.provides

CMakeFiles/Unix_Shell.dir/main.c.o.provides.build: CMakeFiles/Unix_Shell.dir/main.c.o


CMakeFiles/Unix_Shell.dir/variables.c.o: CMakeFiles/Unix_Shell.dir/flags.make
CMakeFiles/Unix_Shell.dir/variables.c.o: ../variables.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Unix_Shell.dir/variables.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Unix_Shell.dir/variables.c.o   -c /home/youssef/Desktop/OS/Unix-Shell/variables.c

CMakeFiles/Unix_Shell.dir/variables.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Unix_Shell.dir/variables.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/youssef/Desktop/OS/Unix-Shell/variables.c > CMakeFiles/Unix_Shell.dir/variables.c.i

CMakeFiles/Unix_Shell.dir/variables.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Unix_Shell.dir/variables.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/youssef/Desktop/OS/Unix-Shell/variables.c -o CMakeFiles/Unix_Shell.dir/variables.c.s

CMakeFiles/Unix_Shell.dir/variables.c.o.requires:

.PHONY : CMakeFiles/Unix_Shell.dir/variables.c.o.requires

CMakeFiles/Unix_Shell.dir/variables.c.o.provides: CMakeFiles/Unix_Shell.dir/variables.c.o.requires
	$(MAKE) -f CMakeFiles/Unix_Shell.dir/build.make CMakeFiles/Unix_Shell.dir/variables.c.o.provides.build
.PHONY : CMakeFiles/Unix_Shell.dir/variables.c.o.provides

CMakeFiles/Unix_Shell.dir/variables.c.o.provides.build: CMakeFiles/Unix_Shell.dir/variables.c.o


# Object files for target Unix_Shell
Unix_Shell_OBJECTS = \
"CMakeFiles/Unix_Shell.dir/command_parser.c.o" \
"CMakeFiles/Unix_Shell.dir/commands.c.o" \
"CMakeFiles/Unix_Shell.dir/environment.c.o" \
"CMakeFiles/Unix_Shell.dir/file_processing.c.o" \
"CMakeFiles/Unix_Shell.dir/main.c.o" \
"CMakeFiles/Unix_Shell.dir/variables.c.o"

# External object files for target Unix_Shell
Unix_Shell_EXTERNAL_OBJECTS =

Unix_Shell: CMakeFiles/Unix_Shell.dir/command_parser.c.o
Unix_Shell: CMakeFiles/Unix_Shell.dir/commands.c.o
Unix_Shell: CMakeFiles/Unix_Shell.dir/environment.c.o
Unix_Shell: CMakeFiles/Unix_Shell.dir/file_processing.c.o
Unix_Shell: CMakeFiles/Unix_Shell.dir/main.c.o
Unix_Shell: CMakeFiles/Unix_Shell.dir/variables.c.o
Unix_Shell: CMakeFiles/Unix_Shell.dir/build.make
Unix_Shell: CMakeFiles/Unix_Shell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Unix_Shell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Unix_Shell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Unix_Shell.dir/build: Unix_Shell

.PHONY : CMakeFiles/Unix_Shell.dir/build

CMakeFiles/Unix_Shell.dir/requires: CMakeFiles/Unix_Shell.dir/command_parser.c.o.requires
CMakeFiles/Unix_Shell.dir/requires: CMakeFiles/Unix_Shell.dir/commands.c.o.requires
CMakeFiles/Unix_Shell.dir/requires: CMakeFiles/Unix_Shell.dir/environment.c.o.requires
CMakeFiles/Unix_Shell.dir/requires: CMakeFiles/Unix_Shell.dir/file_processing.c.o.requires
CMakeFiles/Unix_Shell.dir/requires: CMakeFiles/Unix_Shell.dir/main.c.o.requires
CMakeFiles/Unix_Shell.dir/requires: CMakeFiles/Unix_Shell.dir/variables.c.o.requires

.PHONY : CMakeFiles/Unix_Shell.dir/requires

CMakeFiles/Unix_Shell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Unix_Shell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Unix_Shell.dir/clean

CMakeFiles/Unix_Shell.dir/depend:
	cd /home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/youssef/Desktop/OS/Unix-Shell /home/youssef/Desktop/OS/Unix-Shell /home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug /home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug /home/youssef/Desktop/OS/Unix-Shell/cmake-build-debug/CMakeFiles/Unix_Shell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Unix_Shell.dir/depend

