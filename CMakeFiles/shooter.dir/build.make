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
CMAKE_SOURCE_DIR = /home/kulpet345/Shooter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kulpet345/Shooter

# Include any dependencies generated for this target.
include CMakeFiles/shooter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shooter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shooter.dir/flags.make

CMakeFiles/shooter.dir/main.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shooter.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/main.cpp.o -c /home/kulpet345/Shooter/main.cpp

CMakeFiles/shooter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/main.cpp > CMakeFiles/shooter.dir/main.cpp.i

CMakeFiles/shooter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/main.cpp -o CMakeFiles/shooter.dir/main.cpp.s

CMakeFiles/shooter.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/main.cpp.o.requires

CMakeFiles/shooter.dir/main.cpp.o.provides: CMakeFiles/shooter.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/main.cpp.o.provides

CMakeFiles/shooter.dir/main.cpp.o.provides.build: CMakeFiles/shooter.dir/main.cpp.o


CMakeFiles/shooter.dir/shader.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/shader.cpp.o: shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/shooter.dir/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/shader.cpp.o -c /home/kulpet345/Shooter/shader.cpp

CMakeFiles/shooter.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/shader.cpp > CMakeFiles/shooter.dir/shader.cpp.i

CMakeFiles/shooter.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/shader.cpp -o CMakeFiles/shooter.dir/shader.cpp.s

CMakeFiles/shooter.dir/shader.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/shader.cpp.o.requires

CMakeFiles/shooter.dir/shader.cpp.o.provides: CMakeFiles/shooter.dir/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/shader.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/shader.cpp.o.provides

CMakeFiles/shooter.dir/shader.cpp.o.provides.build: CMakeFiles/shooter.dir/shader.cpp.o


CMakeFiles/shooter.dir/enemy.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/enemy.cpp.o: enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/shooter.dir/enemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/enemy.cpp.o -c /home/kulpet345/Shooter/enemy.cpp

CMakeFiles/shooter.dir/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/enemy.cpp > CMakeFiles/shooter.dir/enemy.cpp.i

CMakeFiles/shooter.dir/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/enemy.cpp -o CMakeFiles/shooter.dir/enemy.cpp.s

CMakeFiles/shooter.dir/enemy.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/enemy.cpp.o.requires

CMakeFiles/shooter.dir/enemy.cpp.o.provides: CMakeFiles/shooter.dir/enemy.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/enemy.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/enemy.cpp.o.provides

CMakeFiles/shooter.dir/enemy.cpp.o.provides.build: CMakeFiles/shooter.dir/enemy.cpp.o


CMakeFiles/shooter.dir/gen.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/gen.cpp.o: gen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/shooter.dir/gen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/gen.cpp.o -c /home/kulpet345/Shooter/gen.cpp

CMakeFiles/shooter.dir/gen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/gen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/gen.cpp > CMakeFiles/shooter.dir/gen.cpp.i

CMakeFiles/shooter.dir/gen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/gen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/gen.cpp -o CMakeFiles/shooter.dir/gen.cpp.s

CMakeFiles/shooter.dir/gen.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/gen.cpp.o.requires

CMakeFiles/shooter.dir/gen.cpp.o.provides: CMakeFiles/shooter.dir/gen.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/gen.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/gen.cpp.o.provides

CMakeFiles/shooter.dir/gen.cpp.o.provides.build: CMakeFiles/shooter.dir/gen.cpp.o


CMakeFiles/shooter.dir/camera.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/camera.cpp.o: camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/shooter.dir/camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/camera.cpp.o -c /home/kulpet345/Shooter/camera.cpp

CMakeFiles/shooter.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/camera.cpp > CMakeFiles/shooter.dir/camera.cpp.i

CMakeFiles/shooter.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/camera.cpp -o CMakeFiles/shooter.dir/camera.cpp.s

CMakeFiles/shooter.dir/camera.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/camera.cpp.o.requires

CMakeFiles/shooter.dir/camera.cpp.o.provides: CMakeFiles/shooter.dir/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/camera.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/camera.cpp.o.provides

CMakeFiles/shooter.dir/camera.cpp.o.provides.build: CMakeFiles/shooter.dir/camera.cpp.o


CMakeFiles/shooter.dir/text2D.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/text2D.cpp.o: text2D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/shooter.dir/text2D.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/text2D.cpp.o -c /home/kulpet345/Shooter/text2D.cpp

CMakeFiles/shooter.dir/text2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/text2D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/text2D.cpp > CMakeFiles/shooter.dir/text2D.cpp.i

CMakeFiles/shooter.dir/text2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/text2D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/text2D.cpp -o CMakeFiles/shooter.dir/text2D.cpp.s

CMakeFiles/shooter.dir/text2D.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/text2D.cpp.o.requires

CMakeFiles/shooter.dir/text2D.cpp.o.provides: CMakeFiles/shooter.dir/text2D.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/text2D.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/text2D.cpp.o.provides

CMakeFiles/shooter.dir/text2D.cpp.o.provides.build: CMakeFiles/shooter.dir/text2D.cpp.o


CMakeFiles/shooter.dir/texture.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/texture.cpp.o: texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/shooter.dir/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/texture.cpp.o -c /home/kulpet345/Shooter/texture.cpp

CMakeFiles/shooter.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/texture.cpp > CMakeFiles/shooter.dir/texture.cpp.i

CMakeFiles/shooter.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/texture.cpp -o CMakeFiles/shooter.dir/texture.cpp.s

CMakeFiles/shooter.dir/texture.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/texture.cpp.o.requires

CMakeFiles/shooter.dir/texture.cpp.o.provides: CMakeFiles/shooter.dir/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/texture.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/texture.cpp.o.provides

CMakeFiles/shooter.dir/texture.cpp.o.provides.build: CMakeFiles/shooter.dir/texture.cpp.o


CMakeFiles/shooter.dir/objloader.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/objloader.cpp.o: objloader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/shooter.dir/objloader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/objloader.cpp.o -c /home/kulpet345/Shooter/objloader.cpp

CMakeFiles/shooter.dir/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/objloader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/objloader.cpp > CMakeFiles/shooter.dir/objloader.cpp.i

CMakeFiles/shooter.dir/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/objloader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/objloader.cpp -o CMakeFiles/shooter.dir/objloader.cpp.s

CMakeFiles/shooter.dir/objloader.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/objloader.cpp.o.requires

CMakeFiles/shooter.dir/objloader.cpp.o.provides: CMakeFiles/shooter.dir/objloader.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/objloader.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/objloader.cpp.o.provides

CMakeFiles/shooter.dir/objloader.cpp.o.provides.build: CMakeFiles/shooter.dir/objloader.cpp.o


CMakeFiles/shooter.dir/bullet_geom.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/bullet_geom.cpp.o: bullet_geom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/shooter.dir/bullet_geom.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/bullet_geom.cpp.o -c /home/kulpet345/Shooter/bullet_geom.cpp

CMakeFiles/shooter.dir/bullet_geom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/bullet_geom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/bullet_geom.cpp > CMakeFiles/shooter.dir/bullet_geom.cpp.i

CMakeFiles/shooter.dir/bullet_geom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/bullet_geom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/bullet_geom.cpp -o CMakeFiles/shooter.dir/bullet_geom.cpp.s

CMakeFiles/shooter.dir/bullet_geom.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/bullet_geom.cpp.o.requires

CMakeFiles/shooter.dir/bullet_geom.cpp.o.provides: CMakeFiles/shooter.dir/bullet_geom.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/bullet_geom.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/bullet_geom.cpp.o.provides

CMakeFiles/shooter.dir/bullet_geom.cpp.o.provides.build: CMakeFiles/shooter.dir/bullet_geom.cpp.o


CMakeFiles/shooter.dir/bullet.cpp.o: CMakeFiles/shooter.dir/flags.make
CMakeFiles/shooter.dir/bullet.cpp.o: bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/shooter.dir/bullet.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shooter.dir/bullet.cpp.o -c /home/kulpet345/Shooter/bullet.cpp

CMakeFiles/shooter.dir/bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooter.dir/bullet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kulpet345/Shooter/bullet.cpp > CMakeFiles/shooter.dir/bullet.cpp.i

CMakeFiles/shooter.dir/bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooter.dir/bullet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kulpet345/Shooter/bullet.cpp -o CMakeFiles/shooter.dir/bullet.cpp.s

CMakeFiles/shooter.dir/bullet.cpp.o.requires:

.PHONY : CMakeFiles/shooter.dir/bullet.cpp.o.requires

CMakeFiles/shooter.dir/bullet.cpp.o.provides: CMakeFiles/shooter.dir/bullet.cpp.o.requires
	$(MAKE) -f CMakeFiles/shooter.dir/build.make CMakeFiles/shooter.dir/bullet.cpp.o.provides.build
.PHONY : CMakeFiles/shooter.dir/bullet.cpp.o.provides

CMakeFiles/shooter.dir/bullet.cpp.o.provides.build: CMakeFiles/shooter.dir/bullet.cpp.o


# Object files for target shooter
shooter_OBJECTS = \
"CMakeFiles/shooter.dir/main.cpp.o" \
"CMakeFiles/shooter.dir/shader.cpp.o" \
"CMakeFiles/shooter.dir/enemy.cpp.o" \
"CMakeFiles/shooter.dir/gen.cpp.o" \
"CMakeFiles/shooter.dir/camera.cpp.o" \
"CMakeFiles/shooter.dir/text2D.cpp.o" \
"CMakeFiles/shooter.dir/texture.cpp.o" \
"CMakeFiles/shooter.dir/objloader.cpp.o" \
"CMakeFiles/shooter.dir/bullet_geom.cpp.o" \
"CMakeFiles/shooter.dir/bullet.cpp.o"

# External object files for target shooter
shooter_EXTERNAL_OBJECTS =

shooter: CMakeFiles/shooter.dir/main.cpp.o
shooter: CMakeFiles/shooter.dir/shader.cpp.o
shooter: CMakeFiles/shooter.dir/enemy.cpp.o
shooter: CMakeFiles/shooter.dir/gen.cpp.o
shooter: CMakeFiles/shooter.dir/camera.cpp.o
shooter: CMakeFiles/shooter.dir/text2D.cpp.o
shooter: CMakeFiles/shooter.dir/texture.cpp.o
shooter: CMakeFiles/shooter.dir/objloader.cpp.o
shooter: CMakeFiles/shooter.dir/bullet_geom.cpp.o
shooter: CMakeFiles/shooter.dir/bullet.cpp.o
shooter: CMakeFiles/shooter.dir/build.make
shooter: /usr/lib/x86_64-linux-gnu/libGL.so
shooter: /usr/lib/x86_64-linux-gnu/libGLU.so
shooter: CMakeFiles/shooter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kulpet345/Shooter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable shooter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shooter.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy shooter ../shooter

# Rule to build all files generated by this target.
CMakeFiles/shooter.dir/build: shooter

.PHONY : CMakeFiles/shooter.dir/build

CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/main.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/shader.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/enemy.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/gen.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/camera.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/text2D.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/texture.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/objloader.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/bullet_geom.cpp.o.requires
CMakeFiles/shooter.dir/requires: CMakeFiles/shooter.dir/bullet.cpp.o.requires

.PHONY : CMakeFiles/shooter.dir/requires

CMakeFiles/shooter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shooter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shooter.dir/clean

CMakeFiles/shooter.dir/depend:
	cd /home/kulpet345/Shooter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kulpet345/Shooter /home/kulpet345/Shooter /home/kulpet345/Shooter /home/kulpet345/Shooter /home/kulpet345/Shooter/CMakeFiles/shooter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shooter.dir/depend

