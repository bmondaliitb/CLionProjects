# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/buddhadebmondal/CLionProjects/usingSSh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/buddhadebmondal/CLionProjects/usingSSh/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/usingSSh.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/usingSSh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/usingSSh.dir/flags.make

CMakeFiles/usingSSh.dir/main.cpp.o: CMakeFiles/usingSSh.dir/flags.make
CMakeFiles/usingSSh.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/buddhadebmondal/CLionProjects/usingSSh/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/usingSSh.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/usingSSh.dir/main.cpp.o -c /Users/buddhadebmondal/CLionProjects/usingSSh/main.cpp

CMakeFiles/usingSSh.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/usingSSh.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/buddhadebmondal/CLionProjects/usingSSh/main.cpp > CMakeFiles/usingSSh.dir/main.cpp.i

CMakeFiles/usingSSh.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/usingSSh.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/buddhadebmondal/CLionProjects/usingSSh/main.cpp -o CMakeFiles/usingSSh.dir/main.cpp.s

# Object files for target usingSSh
usingSSh_OBJECTS = \
"CMakeFiles/usingSSh.dir/main.cpp.o"

# External object files for target usingSSh
usingSSh_EXTERNAL_OBJECTS =

usingSSh: CMakeFiles/usingSSh.dir/main.cpp.o
usingSSh: CMakeFiles/usingSSh.dir/build.make
usingSSh: CMakeFiles/usingSSh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/buddhadebmondal/CLionProjects/usingSSh/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable usingSSh"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/usingSSh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/usingSSh.dir/build: usingSSh
.PHONY : CMakeFiles/usingSSh.dir/build

CMakeFiles/usingSSh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/usingSSh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/usingSSh.dir/clean

CMakeFiles/usingSSh.dir/depend:
	cd /Users/buddhadebmondal/CLionProjects/usingSSh/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/buddhadebmondal/CLionProjects/usingSSh /Users/buddhadebmondal/CLionProjects/usingSSh /Users/buddhadebmondal/CLionProjects/usingSSh/cmake-build-debug /Users/buddhadebmondal/CLionProjects/usingSSh/cmake-build-debug /Users/buddhadebmondal/CLionProjects/usingSSh/cmake-build-debug/CMakeFiles/usingSSh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/usingSSh.dir/depend
