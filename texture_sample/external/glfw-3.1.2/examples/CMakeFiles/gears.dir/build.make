# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kulpet345/comp_gr/ogl-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube

# Include any dependencies generated for this target.
include external/glfw-3.1.2/examples/CMakeFiles/gears.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/examples/CMakeFiles/gears.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/examples/CMakeFiles/gears.dir/flags.make

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o: external/glfw-3.1.2/examples/CMakeFiles/gears.dir/flags.make
external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o: ../external/glfw-3.1.2/examples/gears.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o"
	cd /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/external/glfw-3.1.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gears.dir/gears.c.o   -c /home/kulpet345/comp_gr/ogl-master/external/glfw-3.1.2/examples/gears.c

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/gears.c.i"
	cd /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/external/glfw-3.1.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kulpet345/comp_gr/ogl-master/external/glfw-3.1.2/examples/gears.c > CMakeFiles/gears.dir/gears.c.i

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/gears.c.s"
	cd /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/external/glfw-3.1.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kulpet345/comp_gr/ogl-master/external/glfw-3.1.2/examples/gears.c -o CMakeFiles/gears.dir/gears.c.s

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o.requires:

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o.requires

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o.provides: external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o.requires
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/gears.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o.provides.build
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o.provides

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o.provides.build: external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o


# Object files for target gears
gears_OBJECTS = \
"CMakeFiles/gears.dir/gears.c.o"

# External object files for target gears
gears_EXTERNAL_OBJECTS =

external/glfw-3.1.2/examples/gears: external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o
external/glfw-3.1.2/examples/gears: external/glfw-3.1.2/examples/CMakeFiles/gears.dir/build.make
external/glfw-3.1.2/examples/gears: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/examples/gears: /usr/lib/x86_64-linux-gnu/librt.so
external/glfw-3.1.2/examples/gears: /usr/lib/x86_64-linux-gnu/libm.so
external/glfw-3.1.2/examples/gears: /usr/lib/x86_64-linux-gnu/libX11.so
external/glfw-3.1.2/examples/gears: /usr/lib/x86_64-linux-gnu/libXrandr.so
external/glfw-3.1.2/examples/gears: /usr/lib/x86_64-linux-gnu/libXinerama.so
external/glfw-3.1.2/examples/gears: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
external/glfw-3.1.2/examples/gears: /usr/lib/x86_64-linux-gnu/libXcursor.so
external/glfw-3.1.2/examples/gears: /usr/lib/x86_64-linux-gnu/libGL.so
external/glfw-3.1.2/examples/gears: external/glfw-3.1.2/examples/CMakeFiles/gears.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable gears"
	cd /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/external/glfw-3.1.2/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gears.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/examples/CMakeFiles/gears.dir/build: external/glfw-3.1.2/examples/gears

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/gears.dir/build

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/requires: external/glfw-3.1.2/examples/CMakeFiles/gears.dir/gears.c.o.requires

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/gears.dir/requires

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/clean:
	cd /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/external/glfw-3.1.2/examples && $(CMAKE_COMMAND) -P CMakeFiles/gears.dir/cmake_clean.cmake
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/gears.dir/clean

external/glfw-3.1.2/examples/CMakeFiles/gears.dir/depend:
	cd /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kulpet345/comp_gr/ogl-master /home/kulpet345/comp_gr/ogl-master/external/glfw-3.1.2/examples /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/external/glfw-3.1.2/examples /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/external/glfw-3.1.2/examples/CMakeFiles/gears.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/gears.dir/depend

