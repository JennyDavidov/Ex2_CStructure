# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jenny/CLionProjects/Ex2_CStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jenny/CLionProjects/Ex2_CStructure/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ex2_CStructure.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ex2_CStructure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex2_CStructure.dir/flags.make

CMakeFiles/Ex2_CStructure.dir/main.c.o: CMakeFiles/Ex2_CStructure.dir/flags.make
CMakeFiles/Ex2_CStructure.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jenny/CLionProjects/Ex2_CStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ex2_CStructure.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex2_CStructure.dir/main.c.o   -c /home/jenny/CLionProjects/Ex2_CStructure/main.c

CMakeFiles/Ex2_CStructure.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex2_CStructure.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jenny/CLionProjects/Ex2_CStructure/main.c > CMakeFiles/Ex2_CStructure.dir/main.c.i

CMakeFiles/Ex2_CStructure.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex2_CStructure.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jenny/CLionProjects/Ex2_CStructure/main.c -o CMakeFiles/Ex2_CStructure.dir/main.c.s

CMakeFiles/Ex2_CStructure.dir/kefel.c.o: CMakeFiles/Ex2_CStructure.dir/flags.make
CMakeFiles/Ex2_CStructure.dir/kefel.c.o: ../kefel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jenny/CLionProjects/Ex2_CStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Ex2_CStructure.dir/kefel.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex2_CStructure.dir/kefel.c.o   -c /home/jenny/CLionProjects/Ex2_CStructure/kefel.c

CMakeFiles/Ex2_CStructure.dir/kefel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex2_CStructure.dir/kefel.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jenny/CLionProjects/Ex2_CStructure/kefel.c > CMakeFiles/Ex2_CStructure.dir/kefel.c.i

CMakeFiles/Ex2_CStructure.dir/kefel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex2_CStructure.dir/kefel.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jenny/CLionProjects/Ex2_CStructure/kefel.c -o CMakeFiles/Ex2_CStructure.dir/kefel.c.s

# Object files for target Ex2_CStructure
Ex2_CStructure_OBJECTS = \
"CMakeFiles/Ex2_CStructure.dir/main.c.o" \
"CMakeFiles/Ex2_CStructure.dir/kefel.c.o"

# External object files for target Ex2_CStructure
Ex2_CStructure_EXTERNAL_OBJECTS =

Ex2_CStructure: CMakeFiles/Ex2_CStructure.dir/main.c.o
Ex2_CStructure: CMakeFiles/Ex2_CStructure.dir/kefel.c.o
Ex2_CStructure: CMakeFiles/Ex2_CStructure.dir/build.make
Ex2_CStructure: CMakeFiles/Ex2_CStructure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jenny/CLionProjects/Ex2_CStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Ex2_CStructure"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ex2_CStructure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex2_CStructure.dir/build: Ex2_CStructure

.PHONY : CMakeFiles/Ex2_CStructure.dir/build

CMakeFiles/Ex2_CStructure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ex2_CStructure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ex2_CStructure.dir/clean

CMakeFiles/Ex2_CStructure.dir/depend:
	cd /home/jenny/CLionProjects/Ex2_CStructure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jenny/CLionProjects/Ex2_CStructure /home/jenny/CLionProjects/Ex2_CStructure /home/jenny/CLionProjects/Ex2_CStructure/cmake-build-debug /home/jenny/CLionProjects/Ex2_CStructure/cmake-build-debug /home/jenny/CLionProjects/Ex2_CStructure/cmake-build-debug/CMakeFiles/Ex2_CStructure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex2_CStructure.dir/depend

