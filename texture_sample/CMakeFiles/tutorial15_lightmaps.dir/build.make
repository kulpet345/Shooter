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
include CMakeFiles/tutorial15_lightmaps.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tutorial15_lightmaps.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tutorial15_lightmaps.dir/flags.make

CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o: CMakeFiles/tutorial15_lightmaps.dir/flags.make
CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o: ../tutorial15_lightmaps/tutorial15.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o -c /home/kulpet345/comp_gr/ogl-master/tutorial15_lightmaps/tutorial15.cpp

CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/comp_gr/ogl-master/tutorial15_lightmaps/tutorial15.cpp > CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.i

CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/comp_gr/ogl-master/tutorial15_lightmaps/tutorial15.cpp -o CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.s

CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o.requires:

.PHONY : CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o.requires

CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o.provides: CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial15_lightmaps.dir/build.make CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o.provides

CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o.provides.build: CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o


CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o: CMakeFiles/tutorial15_lightmaps.dir/flags.make
CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o: ../common/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o -c /home/kulpet345/comp_gr/ogl-master/common/shader.cpp

CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/comp_gr/ogl-master/common/shader.cpp > CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.i

CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/comp_gr/ogl-master/common/shader.cpp -o CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.s

CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o.requires:

.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o.requires

CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o.provides: CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial15_lightmaps.dir/build.make CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o.provides

CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o.provides.build: CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o


CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o: CMakeFiles/tutorial15_lightmaps.dir/flags.make
CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o: ../common/controls.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o -c /home/kulpet345/comp_gr/ogl-master/common/controls.cpp

CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/comp_gr/ogl-master/common/controls.cpp > CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.i

CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/comp_gr/ogl-master/common/controls.cpp -o CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.s

CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o.requires:

.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o.requires

CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o.provides: CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial15_lightmaps.dir/build.make CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o.provides

CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o.provides.build: CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o


CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o: CMakeFiles/tutorial15_lightmaps.dir/flags.make
CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o: ../common/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o -c /home/kulpet345/comp_gr/ogl-master/common/texture.cpp

CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/comp_gr/ogl-master/common/texture.cpp > CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.i

CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/comp_gr/ogl-master/common/texture.cpp -o CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.s

CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o.requires:

.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o.requires

CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o.provides: CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial15_lightmaps.dir/build.make CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o.provides

CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o.provides.build: CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o


CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o: CMakeFiles/tutorial15_lightmaps.dir/flags.make
CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o: ../common/objloader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o -c /home/kulpet345/comp_gr/ogl-master/common/objloader.cpp

CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/comp_gr/ogl-master/common/objloader.cpp > CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.i

CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/comp_gr/ogl-master/common/objloader.cpp -o CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.s

CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o.requires:

.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o.requires

CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o.provides: CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial15_lightmaps.dir/build.make CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o.provides

CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o.provides.build: CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o


CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o: CMakeFiles/tutorial15_lightmaps.dir/flags.make
CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o: ../common/vboindexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o -c /home/kulpet345/comp_gr/ogl-master/common/vboindexer.cpp

CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/comp_gr/ogl-master/common/vboindexer.cpp > CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.i

CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/comp_gr/ogl-master/common/vboindexer.cpp -o CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.s

CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o.requires:

.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o.requires

CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o.provides: CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial15_lightmaps.dir/build.make CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o.provides

CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o.provides.build: CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o


# Object files for target tutorial15_lightmaps
tutorial15_lightmaps_OBJECTS = \
"CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o" \
"CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o" \
"CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o" \
"CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o" \
"CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o" \
"CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o"

# External object files for target tutorial15_lightmaps
tutorial15_lightmaps_EXTERNAL_OBJECTS =

tutorial15_lightmaps: CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o
tutorial15_lightmaps: CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o
tutorial15_lightmaps: CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o
tutorial15_lightmaps: CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o
tutorial15_lightmaps: CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o
tutorial15_lightmaps: CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o
tutorial15_lightmaps: CMakeFiles/tutorial15_lightmaps.dir/build.make
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libGL.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libGLU.so
tutorial15_lightmaps: external/glfw-3.1.2/src/libglfw3.a
tutorial15_lightmaps: external/libGLEW_1130.a
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/librt.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libm.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libX11.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libXrandr.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libXinerama.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libXcursor.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/librt.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libm.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libX11.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libXrandr.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libXinerama.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libXcursor.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libGL.so
tutorial15_lightmaps: /usr/lib/x86_64-linux-gnu/libGLU.so
tutorial15_lightmaps: CMakeFiles/tutorial15_lightmaps.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable tutorial15_lightmaps"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial15_lightmaps.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/./tutorial15_lightmaps /home/kulpet345/comp_gr/ogl-master/tutorial15_lightmaps/

# Rule to build all files generated by this target.
CMakeFiles/tutorial15_lightmaps.dir/build: tutorial15_lightmaps

.PHONY : CMakeFiles/tutorial15_lightmaps.dir/build

CMakeFiles/tutorial15_lightmaps.dir/requires: CMakeFiles/tutorial15_lightmaps.dir/tutorial15_lightmaps/tutorial15.cpp.o.requires
CMakeFiles/tutorial15_lightmaps.dir/requires: CMakeFiles/tutorial15_lightmaps.dir/common/shader.cpp.o.requires
CMakeFiles/tutorial15_lightmaps.dir/requires: CMakeFiles/tutorial15_lightmaps.dir/common/controls.cpp.o.requires
CMakeFiles/tutorial15_lightmaps.dir/requires: CMakeFiles/tutorial15_lightmaps.dir/common/texture.cpp.o.requires
CMakeFiles/tutorial15_lightmaps.dir/requires: CMakeFiles/tutorial15_lightmaps.dir/common/objloader.cpp.o.requires
CMakeFiles/tutorial15_lightmaps.dir/requires: CMakeFiles/tutorial15_lightmaps.dir/common/vboindexer.cpp.o.requires

.PHONY : CMakeFiles/tutorial15_lightmaps.dir/requires

CMakeFiles/tutorial15_lightmaps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tutorial15_lightmaps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tutorial15_lightmaps.dir/clean

CMakeFiles/tutorial15_lightmaps.dir/depend:
	cd /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kulpet345/comp_gr/ogl-master /home/kulpet345/comp_gr/ogl-master /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/CMakeFiles/tutorial15_lightmaps.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tutorial15_lightmaps.dir/depend

