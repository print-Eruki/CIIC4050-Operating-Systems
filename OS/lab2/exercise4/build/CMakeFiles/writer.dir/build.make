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
CMAKE_SOURCE_DIR = /home/alepgn/Desktop/OS/lab2/exercise4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alepgn/Desktop/OS/lab2/exercise4/build

# Include any dependencies generated for this target.
include CMakeFiles/writer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/writer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/writer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/writer.dir/flags.make

CMakeFiles/writer.dir/src/writer.c.o: CMakeFiles/writer.dir/flags.make
CMakeFiles/writer.dir/src/writer.c.o: ../src/writer.c
CMakeFiles/writer.dir/src/writer.c.o: CMakeFiles/writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alepgn/Desktop/OS/lab2/exercise4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/writer.dir/src/writer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/writer.dir/src/writer.c.o -MF CMakeFiles/writer.dir/src/writer.c.o.d -o CMakeFiles/writer.dir/src/writer.c.o -c /home/alepgn/Desktop/OS/lab2/exercise4/src/writer.c

CMakeFiles/writer.dir/src/writer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/writer.dir/src/writer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alepgn/Desktop/OS/lab2/exercise4/src/writer.c > CMakeFiles/writer.dir/src/writer.c.i

CMakeFiles/writer.dir/src/writer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/writer.dir/src/writer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alepgn/Desktop/OS/lab2/exercise4/src/writer.c -o CMakeFiles/writer.dir/src/writer.c.s

# Object files for target writer
writer_OBJECTS = \
"CMakeFiles/writer.dir/src/writer.c.o"

# External object files for target writer
writer_EXTERNAL_OBJECTS =

writer: CMakeFiles/writer.dir/src/writer.c.o
writer: CMakeFiles/writer.dir/build.make
writer: CMakeFiles/writer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alepgn/Desktop/OS/lab2/exercise4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable writer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/writer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/writer.dir/build: writer
.PHONY : CMakeFiles/writer.dir/build

CMakeFiles/writer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/writer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/writer.dir/clean

CMakeFiles/writer.dir/depend:
	cd /home/alepgn/Desktop/OS/lab2/exercise4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alepgn/Desktop/OS/lab2/exercise4 /home/alepgn/Desktop/OS/lab2/exercise4 /home/alepgn/Desktop/OS/lab2/exercise4/build /home/alepgn/Desktop/OS/lab2/exercise4/build /home/alepgn/Desktop/OS/lab2/exercise4/build/CMakeFiles/writer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/writer.dir/depend

