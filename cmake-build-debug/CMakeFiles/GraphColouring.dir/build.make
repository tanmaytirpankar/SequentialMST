# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GraphColouring.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GraphColouring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GraphColouring.dir/flags.make

CMakeFiles/GraphColouring.dir/main.cpp.o: CMakeFiles/GraphColouring.dir/flags.make
CMakeFiles/GraphColouring.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GraphColouring.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GraphColouring.dir/main.cpp.o -c /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/main.cpp

CMakeFiles/GraphColouring.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraphColouring.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/main.cpp > CMakeFiles/GraphColouring.dir/main.cpp.i

CMakeFiles/GraphColouring.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraphColouring.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/main.cpp -o CMakeFiles/GraphColouring.dir/main.cpp.s

CMakeFiles/GraphColouring.dir/graph.cpp.o: CMakeFiles/GraphColouring.dir/flags.make
CMakeFiles/GraphColouring.dir/graph.cpp.o: graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GraphColouring.dir/graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GraphColouring.dir/graph.cpp.o -c /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/graph.cpp

CMakeFiles/GraphColouring.dir/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraphColouring.dir/graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/graph.cpp > CMakeFiles/GraphColouring.dir/graph.cpp.i

CMakeFiles/GraphColouring.dir/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraphColouring.dir/graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/graph.cpp -o CMakeFiles/GraphColouring.dir/graph.cpp.s

CMakeFiles/GraphColouring.dir/edge.cpp.o: CMakeFiles/GraphColouring.dir/flags.make
CMakeFiles/GraphColouring.dir/edge.cpp.o: edge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GraphColouring.dir/edge.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GraphColouring.dir/edge.cpp.o -c /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/edge.cpp

CMakeFiles/GraphColouring.dir/edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraphColouring.dir/edge.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/edge.cpp > CMakeFiles/GraphColouring.dir/edge.cpp.i

CMakeFiles/GraphColouring.dir/edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraphColouring.dir/edge.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/edge.cpp -o CMakeFiles/GraphColouring.dir/edge.cpp.s

CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.o: CMakeFiles/GraphColouring.dir/flags.make
CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.o: MinSpanTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.o -c /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/MinSpanTree.cpp

CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/MinSpanTree.cpp > CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.i

CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/MinSpanTree.cpp -o CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.s

# Object files for target GraphColouring
GraphColouring_OBJECTS = \
"CMakeFiles/GraphColouring.dir/main.cpp.o" \
"CMakeFiles/GraphColouring.dir/graph.cpp.o" \
"CMakeFiles/GraphColouring.dir/edge.cpp.o" \
"CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.o"

# External object files for target GraphColouring
GraphColouring_EXTERNAL_OBJECTS =

GraphColouring: CMakeFiles/GraphColouring.dir/main.cpp.o
GraphColouring: CMakeFiles/GraphColouring.dir/graph.cpp.o
GraphColouring: CMakeFiles/GraphColouring.dir/edge.cpp.o
GraphColouring: CMakeFiles/GraphColouring.dir/MinSpanTree.cpp.o
GraphColouring: CMakeFiles/GraphColouring.dir/build.make
GraphColouring: CMakeFiles/GraphColouring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable GraphColouring"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GraphColouring.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GraphColouring.dir/build: GraphColouring

.PHONY : CMakeFiles/GraphColouring.dir/build

CMakeFiles/GraphColouring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GraphColouring.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GraphColouring.dir/clean

CMakeFiles/GraphColouring.dir/depend:
	cd /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug /Users/tanmaytirpankar/Documents/CLionProjects/GraphColouring/cmake-build-debug/CMakeFiles/GraphColouring.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GraphColouring.dir/depend

