# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/dom_carnet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dom_carnet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dom_carnet.dir/flags.make

CMakeFiles/dom_carnet.dir/main.cpp.o: CMakeFiles/dom_carnet.dir/flags.make
CMakeFiles/dom_carnet.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dom_carnet.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dom_carnet.dir/main.cpp.o -c "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/main.cpp"

CMakeFiles/dom_carnet.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dom_carnet.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/main.cpp" > CMakeFiles/dom_carnet.dir/main.cpp.i

CMakeFiles/dom_carnet.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dom_carnet.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/main.cpp" -o CMakeFiles/dom_carnet.dir/main.cpp.s

# Object files for target dom_carnet
dom_carnet_OBJECTS = \
"CMakeFiles/dom_carnet.dir/main.cpp.o"

# External object files for target dom_carnet
dom_carnet_EXTERNAL_OBJECTS =

dom_carnet: CMakeFiles/dom_carnet.dir/main.cpp.o
dom_carnet: CMakeFiles/dom_carnet.dir/build.make
dom_carnet: CMakeFiles/dom_carnet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dom_carnet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dom_carnet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dom_carnet.dir/build: dom_carnet

.PHONY : CMakeFiles/dom_carnet.dir/build

CMakeFiles/dom_carnet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dom_carnet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dom_carnet.dir/clean

CMakeFiles/dom_carnet.dir/depend:
	cd "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet" "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet" "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/cmake-build-debug" "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/cmake-build-debug" "/Volumes/Macintosh MHD/Users/Uni/ED/CLion Projects/dom_carnet/cmake-build-debug/CMakeFiles/dom_carnet.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/dom_carnet.dir/depend

