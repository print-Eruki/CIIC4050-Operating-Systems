# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alepgn/Desktop/OS/lab1/Exercise_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alepgn/Desktop/OS/lab1/Exercise_5/build

# Include any dependencies generated for this target.
include CMakeFiles/exercise_5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exercise_5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise_5.dir/flags.make

CMakeFiles/exercise_5.dir/src/main.c.o: CMakeFiles/exercise_5.dir/flags.make
CMakeFiles/exercise_5.dir/src/main.c.o: ../src/main.c
CMakeFiles/exercise_5.dir/src/main.c.o: CMakeFiles/exercise_5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alepgn/Desktop/OS/lab1/Exercise_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exercise_5.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/exercise_5.dir/src/main.c.o -MF CMakeFiles/exercise_5.dir/src/main.c.o.d -o CMakeFiles/exercise_5.dir/src/main.c.o -c /home/alepgn/Desktop/OS/lab1/Exercise_5/src/main.c

CMakeFiles/exercise_5.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exercise_5.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alepgn/Desktop/OS/lab1/Exercise_5/src/main.c > CMakeFiles/exercise_5.dir/src/main.c.i

CMakeFiles/exercise_5.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exercise_5.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alepgn/Desktop/OS/lab1/Exercise_5/src/main.c -o CMakeFiles/exercise_5.dir/src/main.c.s

CMakeFiles/exercise_5.dir/src/functions.c.o: CMakeFiles/exercise_5.dir/flags.make
CMakeFiles/exercise_5.dir/src/functions.c.o: ../src/functions.c
CMakeFiles/exercise_5.dir/src/functions.c.o: CMakeFiles/exercise_5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alepgn/Desktop/OS/lab1/Exercise_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/exercise_5.dir/src/functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/exercise_5.dir/src/functions.c.o -MF CMakeFiles/exercise_5.dir/src/functions.c.o.d -o CMakeFiles/exercise_5.dir/src/functions.c.o -c /home/alepgn/Desktop/OS/lab1/Exercise_5/src/functions.c

CMakeFiles/exercise_5.dir/src/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exercise_5.dir/src/functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alepgn/Desktop/OS/lab1/Exercise_5/src/functions.c > CMakeFiles/exercise_5.dir/src/functions.c.i

CMakeFiles/exercise_5.dir/src/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exercise_5.dir/src/functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alepgn/Desktop/OS/lab1/Exercise_5/src/functions.c -o CMakeFiles/exercise_5.dir/src/functions.c.s

# Object files for target exercise_5
exercise_5_OBJECTS = \
"CMakeFiles/exercise_5.dir/src/main.c.o" \
"CMakeFiles/exercise_5.dir/src/functions.c.o"

# External object files for target exercise_5
exercise_5_EXTERNAL_OBJECTS =

exercise_5: CMakeFiles/exercise_5.dir/src/main.c.o
exercise_5: CMakeFiles/exercise_5.dir/src/functions.c.o
exercise_5: CMakeFiles/exercise_5.dir/build.make
exercise_5: CMakeFiles/exercise_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alepgn/Desktop/OS/lab1/Exercise_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable exercise_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exercise_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise_5.dir/build: exercise_5
.PHONY : CMakeFiles/exercise_5.dir/build

CMakeFiles/exercise_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exercise_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exercise_5.dir/clean

CMakeFiles/exercise_5.dir/depend:
	cd /home/alepgn/Desktop/OS/lab1/Exercise_5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alepgn/Desktop/OS/lab1/Exercise_5 /home/alepgn/Desktop/OS/lab1/Exercise_5 /home/alepgn/Desktop/OS/lab1/Exercise_5/build /home/alepgn/Desktop/OS/lab1/Exercise_5/build /home/alepgn/Desktop/OS/lab1/Exercise_5/build/CMakeFiles/exercise_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exercise_5.dir/depend

