# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/hejianzhi/Desktop/AIAvoidProjectilesGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hejianzhi/Desktop/AIAvoidProjectilesGame/build

# Include any dependencies generated for this target.
include CMakeFiles/glfw_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glfw_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glfw_test.dir/flags.make

CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o: CMakeFiles/glfw_test.dir/flags.make
CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o: ../src/glfw_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hejianzhi/Desktop/AIAvoidProjectilesGame/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o -c /home/hejianzhi/Desktop/AIAvoidProjectilesGame/src/glfw_test.cpp

CMakeFiles/glfw_test.dir/src/glfw_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfw_test.dir/src/glfw_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hejianzhi/Desktop/AIAvoidProjectilesGame/src/glfw_test.cpp > CMakeFiles/glfw_test.dir/src/glfw_test.cpp.i

CMakeFiles/glfw_test.dir/src/glfw_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfw_test.dir/src/glfw_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hejianzhi/Desktop/AIAvoidProjectilesGame/src/glfw_test.cpp -o CMakeFiles/glfw_test.dir/src/glfw_test.cpp.s

CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o.requires:
.PHONY : CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o.requires

CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o.provides: CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfw_test.dir/build.make CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o.provides.build
.PHONY : CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o.provides

CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o.provides.build: CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o

CMakeFiles/glfw_test.dir/src/glad.c.o: CMakeFiles/glfw_test.dir/flags.make
CMakeFiles/glfw_test.dir/src/glad.c.o: ../src/glad.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hejianzhi/Desktop/AIAvoidProjectilesGame/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/glfw_test.dir/src/glad.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw_test.dir/src/glad.c.o   -c /home/hejianzhi/Desktop/AIAvoidProjectilesGame/src/glad.c

CMakeFiles/glfw_test.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw_test.dir/src/glad.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/hejianzhi/Desktop/AIAvoidProjectilesGame/src/glad.c > CMakeFiles/glfw_test.dir/src/glad.c.i

CMakeFiles/glfw_test.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw_test.dir/src/glad.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/hejianzhi/Desktop/AIAvoidProjectilesGame/src/glad.c -o CMakeFiles/glfw_test.dir/src/glad.c.s

CMakeFiles/glfw_test.dir/src/glad.c.o.requires:
.PHONY : CMakeFiles/glfw_test.dir/src/glad.c.o.requires

CMakeFiles/glfw_test.dir/src/glad.c.o.provides: CMakeFiles/glfw_test.dir/src/glad.c.o.requires
	$(MAKE) -f CMakeFiles/glfw_test.dir/build.make CMakeFiles/glfw_test.dir/src/glad.c.o.provides.build
.PHONY : CMakeFiles/glfw_test.dir/src/glad.c.o.provides

CMakeFiles/glfw_test.dir/src/glad.c.o.provides.build: CMakeFiles/glfw_test.dir/src/glad.c.o

# Object files for target glfw_test
glfw_test_OBJECTS = \
"CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o" \
"CMakeFiles/glfw_test.dir/src/glad.c.o"

# External object files for target glfw_test
glfw_test_EXTERNAL_OBJECTS =

glfw_test: CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o
glfw_test: CMakeFiles/glfw_test.dir/src/glad.c.o
glfw_test: CMakeFiles/glfw_test.dir/build.make
glfw_test: ThirdParty/glfw/src/libglfw3.a
glfw_test: /usr/lib/i386-linux-gnu/librt.so
glfw_test: /usr/lib/i386-linux-gnu/libm.so
glfw_test: /usr/lib/i386-linux-gnu/libX11.so
glfw_test: /usr/lib/i386-linux-gnu/libXrandr.so
glfw_test: /usr/lib/i386-linux-gnu/libXinerama.so
glfw_test: /usr/lib/i386-linux-gnu/libXcursor.so
glfw_test: CMakeFiles/glfw_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable glfw_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfw_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glfw_test.dir/build: glfw_test
.PHONY : CMakeFiles/glfw_test.dir/build

CMakeFiles/glfw_test.dir/requires: CMakeFiles/glfw_test.dir/src/glfw_test.cpp.o.requires
CMakeFiles/glfw_test.dir/requires: CMakeFiles/glfw_test.dir/src/glad.c.o.requires
.PHONY : CMakeFiles/glfw_test.dir/requires

CMakeFiles/glfw_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glfw_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glfw_test.dir/clean

CMakeFiles/glfw_test.dir/depend:
	cd /home/hejianzhi/Desktop/AIAvoidProjectilesGame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hejianzhi/Desktop/AIAvoidProjectilesGame /home/hejianzhi/Desktop/AIAvoidProjectilesGame /home/hejianzhi/Desktop/AIAvoidProjectilesGame/build /home/hejianzhi/Desktop/AIAvoidProjectilesGame/build /home/hejianzhi/Desktop/AIAvoidProjectilesGame/build/CMakeFiles/glfw_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glfw_test.dir/depend

