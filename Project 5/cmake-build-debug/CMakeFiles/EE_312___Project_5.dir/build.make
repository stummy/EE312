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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/EE_312___Project_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EE_312___Project_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EE_312___Project_5.dir/flags.make

CMakeFiles/EE_312___Project_5.dir/String.c.o: CMakeFiles/EE_312___Project_5.dir/flags.make
CMakeFiles/EE_312___Project_5.dir/String.c.o: ../String.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/EE_312___Project_5.dir/String.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/EE_312___Project_5.dir/String.c.o   -c "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/String.c"

CMakeFiles/EE_312___Project_5.dir/String.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EE_312___Project_5.dir/String.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/String.c" > CMakeFiles/EE_312___Project_5.dir/String.c.i

CMakeFiles/EE_312___Project_5.dir/String.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EE_312___Project_5.dir/String.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/String.c" -o CMakeFiles/EE_312___Project_5.dir/String.c.s

CMakeFiles/EE_312___Project_5.dir/String.c.o.requires:

.PHONY : CMakeFiles/EE_312___Project_5.dir/String.c.o.requires

CMakeFiles/EE_312___Project_5.dir/String.c.o.provides: CMakeFiles/EE_312___Project_5.dir/String.c.o.requires
	$(MAKE) -f CMakeFiles/EE_312___Project_5.dir/build.make CMakeFiles/EE_312___Project_5.dir/String.c.o.provides.build
.PHONY : CMakeFiles/EE_312___Project_5.dir/String.c.o.provides

CMakeFiles/EE_312___Project_5.dir/String.c.o.provides.build: CMakeFiles/EE_312___Project_5.dir/String.c.o


CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o: CMakeFiles/EE_312___Project_5.dir/flags.make
CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o: ../Proj5Test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o   -c "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/Proj5Test.c"

CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/Proj5Test.c" > CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.i

CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/Proj5Test.c" -o CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.s

CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o.requires:

.PHONY : CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o.requires

CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o.provides: CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o.requires
	$(MAKE) -f CMakeFiles/EE_312___Project_5.dir/build.make CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o.provides.build
.PHONY : CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o.provides

CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o.provides.build: CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o


# Object files for target EE_312___Project_5
EE_312___Project_5_OBJECTS = \
"CMakeFiles/EE_312___Project_5.dir/String.c.o" \
"CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o"

# External object files for target EE_312___Project_5
EE_312___Project_5_EXTERNAL_OBJECTS =

EE_312___Project_5: CMakeFiles/EE_312___Project_5.dir/String.c.o
EE_312___Project_5: CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o
EE_312___Project_5: CMakeFiles/EE_312___Project_5.dir/build.make
EE_312___Project_5: CMakeFiles/EE_312___Project_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable EE_312___Project_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EE_312___Project_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EE_312___Project_5.dir/build: EE_312___Project_5

.PHONY : CMakeFiles/EE_312___Project_5.dir/build

CMakeFiles/EE_312___Project_5.dir/requires: CMakeFiles/EE_312___Project_5.dir/String.c.o.requires
CMakeFiles/EE_312___Project_5.dir/requires: CMakeFiles/EE_312___Project_5.dir/Proj5Test.c.o.requires

.PHONY : CMakeFiles/EE_312___Project_5.dir/requires

CMakeFiles/EE_312___Project_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EE_312___Project_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EE_312___Project_5.dir/clean

CMakeFiles/EE_312___Project_5.dir/depend:
	cd "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5" "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5" "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/cmake-build-debug" "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/cmake-build-debug" "/Users/hyalithus/Documents/School/Year 2/Fall 2017/EE 312 - Project 5/cmake-build-debug/CMakeFiles/EE_312___Project_5.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/EE_312___Project_5.dir/depend

