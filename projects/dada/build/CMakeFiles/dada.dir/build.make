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
CMAKE_SOURCE_DIR = /home/hui/projects/dada

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hui/projects/dada/build

# Include any dependencies generated for this target.
include CMakeFiles/dada.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dada.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dada.dir/flags.make

CMakeFiles/dada.dir/main.cpp.o: CMakeFiles/dada.dir/flags.make
CMakeFiles/dada.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hui/projects/dada/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dada.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dada.dir/main.cpp.o -c /home/hui/projects/dada/main.cpp

CMakeFiles/dada.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dada.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hui/projects/dada/main.cpp > CMakeFiles/dada.dir/main.cpp.i

CMakeFiles/dada.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dada.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hui/projects/dada/main.cpp -o CMakeFiles/dada.dir/main.cpp.s

CMakeFiles/dada.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/dada.dir/main.cpp.o.requires

CMakeFiles/dada.dir/main.cpp.o.provides: CMakeFiles/dada.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/dada.dir/build.make CMakeFiles/dada.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/dada.dir/main.cpp.o.provides

CMakeFiles/dada.dir/main.cpp.o.provides.build: CMakeFiles/dada.dir/main.cpp.o


# Object files for target dada
dada_OBJECTS = \
"CMakeFiles/dada.dir/main.cpp.o"

# External object files for target dada
dada_EXTERNAL_OBJECTS =

dada: CMakeFiles/dada.dir/main.cpp.o
dada: CMakeFiles/dada.dir/build.make
dada: CMakeFiles/dada.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hui/projects/dada/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dada"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dada.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dada.dir/build: dada

.PHONY : CMakeFiles/dada.dir/build

CMakeFiles/dada.dir/requires: CMakeFiles/dada.dir/main.cpp.o.requires

.PHONY : CMakeFiles/dada.dir/requires

CMakeFiles/dada.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dada.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dada.dir/clean

CMakeFiles/dada.dir/depend:
	cd /home/hui/projects/dada/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hui/projects/dada /home/hui/projects/dada /home/hui/projects/dada/build /home/hui/projects/dada/build /home/hui/projects/dada/build/CMakeFiles/dada.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dada.dir/depend

