# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liesamarouche/Downloads/my_som

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liesamarouche/Downloads/my_som/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_som.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_som.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_som.dir/flags.make

CMakeFiles/my_som.dir/main.c.o: CMakeFiles/my_som.dir/flags.make
CMakeFiles/my_som.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liesamarouche/Downloads/my_som/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_som.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_som.dir/main.c.o   -c /Users/liesamarouche/Downloads/my_som/main.c

CMakeFiles/my_som.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_som.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/liesamarouche/Downloads/my_som/main.c > CMakeFiles/my_som.dir/main.c.i

CMakeFiles/my_som.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_som.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/liesamarouche/Downloads/my_som/main.c -o CMakeFiles/my_som.dir/main.c.s

CMakeFiles/my_som.dir/data.c.o: CMakeFiles/my_som.dir/flags.make
CMakeFiles/my_som.dir/data.c.o: ../data.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liesamarouche/Downloads/my_som/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/my_som.dir/data.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_som.dir/data.c.o   -c /Users/liesamarouche/Downloads/my_som/data.c

CMakeFiles/my_som.dir/data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_som.dir/data.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/liesamarouche/Downloads/my_som/data.c > CMakeFiles/my_som.dir/data.c.i

CMakeFiles/my_som.dir/data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_som.dir/data.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/liesamarouche/Downloads/my_som/data.c -o CMakeFiles/my_som.dir/data.c.s

CMakeFiles/my_som.dir/list.c.o: CMakeFiles/my_som.dir/flags.make
CMakeFiles/my_som.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liesamarouche/Downloads/my_som/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/my_som.dir/list.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_som.dir/list.c.o   -c /Users/liesamarouche/Downloads/my_som/list.c

CMakeFiles/my_som.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_som.dir/list.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/liesamarouche/Downloads/my_som/list.c > CMakeFiles/my_som.dir/list.c.i

CMakeFiles/my_som.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_som.dir/list.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/liesamarouche/Downloads/my_som/list.c -o CMakeFiles/my_som.dir/list.c.s

# Object files for target my_som
my_som_OBJECTS = \
"CMakeFiles/my_som.dir/main.c.o" \
"CMakeFiles/my_som.dir/data.c.o" \
"CMakeFiles/my_som.dir/list.c.o"

# External object files for target my_som
my_som_EXTERNAL_OBJECTS =

my_som: CMakeFiles/my_som.dir/main.c.o
my_som: CMakeFiles/my_som.dir/data.c.o
my_som: CMakeFiles/my_som.dir/list.c.o
my_som: CMakeFiles/my_som.dir/build.make
my_som: CMakeFiles/my_som.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liesamarouche/Downloads/my_som/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable my_som"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_som.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_som.dir/build: my_som

.PHONY : CMakeFiles/my_som.dir/build

CMakeFiles/my_som.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_som.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_som.dir/clean

CMakeFiles/my_som.dir/depend:
	cd /Users/liesamarouche/Downloads/my_som/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liesamarouche/Downloads/my_som /Users/liesamarouche/Downloads/my_som /Users/liesamarouche/Downloads/my_som/cmake-build-debug /Users/liesamarouche/Downloads/my_som/cmake-build-debug /Users/liesamarouche/Downloads/my_som/cmake-build-debug/CMakeFiles/my_som.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_som.dir/depend

