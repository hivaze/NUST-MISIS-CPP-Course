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
include prj.lab/dynarray/CMakeFiles/dynarray.dir/depend.make

# Include the progress variables for this target.
include prj.lab/dynarray/CMakeFiles/dynarray.dir/progress.make

# Include the compile flags for this target's objects.
include prj.lab/dynarray/CMakeFiles/dynarray.dir/flags.make

prj.lab/dynarray/CMakeFiles/dynarray.dir/dynarray.cpp.o: prj.lab/dynarray/CMakeFiles/dynarray.dir/flags.make
prj.lab/dynarray/CMakeFiles/dynarray.dir/dynarray.cpp.o: ../prj.lab/dynarray/dynarray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj.lab/dynarray/CMakeFiles/dynarray.dir/dynarray.cpp.o"
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dynarray.dir/dynarray.cpp.o -c "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab/dynarray/dynarray.cpp"

prj.lab/dynarray/CMakeFiles/dynarray.dir/dynarray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dynarray.dir/dynarray.cpp.i"
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab/dynarray/dynarray.cpp" > CMakeFiles/dynarray.dir/dynarray.cpp.i

prj.lab/dynarray/CMakeFiles/dynarray.dir/dynarray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dynarray.dir/dynarray.cpp.s"
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab/dynarray/dynarray.cpp" -o CMakeFiles/dynarray.dir/dynarray.cpp.s

# Object files for target dynarray
dynarray_OBJECTS = \
"CMakeFiles/dynarray.dir/dynarray.cpp.o"

# External object files for target dynarray
dynarray_EXTERNAL_OBJECTS =

prj.lab/dynarray/libdynarray.a: prj.lab/dynarray/CMakeFiles/dynarray.dir/dynarray.cpp.o
prj.lab/dynarray/libdynarray.a: prj.lab/dynarray/CMakeFiles/dynarray.dir/build.make
prj.lab/dynarray/libdynarray.a: prj.lab/dynarray/CMakeFiles/dynarray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdynarray.a"
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray" && $(CMAKE_COMMAND) -P CMakeFiles/dynarray.dir/cmake_clean_target.cmake
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dynarray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj.lab/dynarray/CMakeFiles/dynarray.dir/build: prj.lab/dynarray/libdynarray.a

.PHONY : prj.lab/dynarray/CMakeFiles/dynarray.dir/build

prj.lab/dynarray/CMakeFiles/dynarray.dir/clean:
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray" && $(CMAKE_COMMAND) -P CMakeFiles/dynarray.dir/cmake_clean.cmake
.PHONY : prj.lab/dynarray/CMakeFiles/dynarray.dir/clean

prj.lab/dynarray/CMakeFiles/dynarray.dir/depend:
	cd "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab/dynarray" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray" "/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray/CMakeFiles/dynarray.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : prj.lab/dynarray/CMakeFiles/dynarray.dir/depend

