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
CMAKE_SOURCE_DIR = /home/ubuntu/develop/cpp_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/develop/build

# Include any dependencies generated for this target.
include CMakeFiles/myexe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myexe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myexe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myexe.dir/flags.make

CMakeFiles/myexe.dir/main.cpp.o: CMakeFiles/myexe.dir/flags.make
CMakeFiles/myexe.dir/main.cpp.o: /home/ubuntu/develop/cpp_test/main.cpp
CMakeFiles/myexe.dir/main.cpp.o: CMakeFiles/myexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myexe.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myexe.dir/main.cpp.o -MF CMakeFiles/myexe.dir/main.cpp.o.d -o CMakeFiles/myexe.dir/main.cpp.o -c /home/ubuntu/develop/cpp_test/main.cpp

CMakeFiles/myexe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myexe.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/develop/cpp_test/main.cpp > CMakeFiles/myexe.dir/main.cpp.i

CMakeFiles/myexe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myexe.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/develop/cpp_test/main.cpp -o CMakeFiles/myexe.dir/main.cpp.s

# Object files for target myexe
myexe_OBJECTS = \
"CMakeFiles/myexe.dir/main.cpp.o"

# External object files for target myexe
myexe_EXTERNAL_OBJECTS =

myexe: CMakeFiles/myexe.dir/main.cpp.o
myexe: CMakeFiles/myexe.dir/build.make
myexe: CMakeFiles/myexe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myexe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myexe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myexe.dir/build: myexe
.PHONY : CMakeFiles/myexe.dir/build

CMakeFiles/myexe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myexe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myexe.dir/clean

CMakeFiles/myexe.dir/depend:
	cd /home/ubuntu/develop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/develop/cpp_test /home/ubuntu/develop/cpp_test /home/ubuntu/develop/build /home/ubuntu/develop/build /home/ubuntu/develop/build/CMakeFiles/myexe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myexe.dir/depend

