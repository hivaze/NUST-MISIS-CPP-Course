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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug"

# Include any dependencies generated for this target.
include prj.lab/queuel/CMakeFiles/queuel.dir/depend.make

# Include the progress variables for this target.
include prj.lab/queuel/CMakeFiles/queuel.dir/progress.make

# Include the compile flags for this target's objects.
include prj.lab/queuel/CMakeFiles/queuel.dir/flags.make

prj.lab/queuel/CMakeFiles/queuel.dir/queuel.cpp.o: prj.lab/queuel/CMakeFiles/queuel.dir/flags.make
prj.lab/queuel/CMakeFiles/queuel.dir/queuel.cpp.o: ../prj.lab/queuel/queuel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj.lab/queuel/CMakeFiles/queuel.dir/queuel.cpp.o"
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queuel.dir/queuel.cpp.o -c "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab/queuel/queuel.cpp"

prj.lab/queuel/CMakeFiles/queuel.dir/queuel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queuel.dir/queuel.cpp.i"
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab/queuel/queuel.cpp" > CMakeFiles/queuel.dir/queuel.cpp.i

prj.lab/queuel/CMakeFiles/queuel.dir/queuel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queuel.dir/queuel.cpp.s"
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab/queuel/queuel.cpp" -o CMakeFiles/queuel.dir/queuel.cpp.s

# Object files for target queuel
queuel_OBJECTS = \
"CMakeFiles/queuel.dir/queuel.cpp.o"

# External object files for target queuel
queuel_EXTERNAL_OBJECTS =

prj.lab/queuel/libqueuel.a: prj.lab/queuel/CMakeFiles/queuel.dir/queuel.cpp.o
prj.lab/queuel/libqueuel.a: prj.lab/queuel/CMakeFiles/queuel.dir/build.make
prj.lab/queuel/libqueuel.a: prj.lab/queuel/CMakeFiles/queuel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libqueuel.a"
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel" && $(CMAKE_COMMAND) -P CMakeFiles/queuel.dir/cmake_clean_target.cmake
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queuel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj.lab/queuel/CMakeFiles/queuel.dir/build: prj.lab/queuel/libqueuel.a

.PHONY : prj.lab/queuel/CMakeFiles/queuel.dir/build

prj.lab/queuel/CMakeFiles/queuel.dir/clean:
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel" && $(CMAKE_COMMAND) -P CMakeFiles/queuel.dir/cmake_clean.cmake
.PHONY : prj.lab/queuel/CMakeFiles/queuel.dir/clean

prj.lab/queuel/CMakeFiles/queuel.dir/depend:
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab/queuel" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel/CMakeFiles/queuel.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : prj.lab/queuel/CMakeFiles/queuel.dir/depend
