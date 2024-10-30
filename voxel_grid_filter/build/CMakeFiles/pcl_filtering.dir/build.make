# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ethereal/pcl/voxel_grid_filter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ethereal/pcl/voxel_grid_filter/build

# Include any dependencies generated for this target.
include CMakeFiles/pcl_filtering.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pcl_filtering.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pcl_filtering.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pcl_filtering.dir/flags.make

CMakeFiles/pcl_filtering.dir/main.cpp.o: CMakeFiles/pcl_filtering.dir/flags.make
CMakeFiles/pcl_filtering.dir/main.cpp.o: /home/ethereal/pcl/voxel_grid_filter/main.cpp
CMakeFiles/pcl_filtering.dir/main.cpp.o: CMakeFiles/pcl_filtering.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ethereal/pcl/voxel_grid_filter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pcl_filtering.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcl_filtering.dir/main.cpp.o -MF CMakeFiles/pcl_filtering.dir/main.cpp.o.d -o CMakeFiles/pcl_filtering.dir/main.cpp.o -c /home/ethereal/pcl/voxel_grid_filter/main.cpp

CMakeFiles/pcl_filtering.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pcl_filtering.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ethereal/pcl/voxel_grid_filter/main.cpp > CMakeFiles/pcl_filtering.dir/main.cpp.i

CMakeFiles/pcl_filtering.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pcl_filtering.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ethereal/pcl/voxel_grid_filter/main.cpp -o CMakeFiles/pcl_filtering.dir/main.cpp.s

# Object files for target pcl_filtering
pcl_filtering_OBJECTS = \
"CMakeFiles/pcl_filtering.dir/main.cpp.o"

# External object files for target pcl_filtering
pcl_filtering_EXTERNAL_OBJECTS =

pcl_filtering: CMakeFiles/pcl_filtering.dir/main.cpp.o
pcl_filtering: CMakeFiles/pcl_filtering.dir/build.make
pcl_filtering: /usr/local/lib/libpcl_ml.so
pcl_filtering: /usr/local/lib/libpcl_stereo.so
pcl_filtering: /usr/local/lib/libpcl_io.so
pcl_filtering: /usr/local/lib/libpcl_octree.so
pcl_filtering: /usr/local/lib/libpcl_common.so
pcl_filtering: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.83.0
pcl_filtering: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.83.0
pcl_filtering: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.83.0
pcl_filtering: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.83.0
pcl_filtering: /usr/lib/x86_64-linux-gnu/libboost_serialization.so.1.83.0
pcl_filtering: /usr/lib/x86_64-linux-gnu/libpcap.so
pcl_filtering: /usr/lib/x86_64-linux-gnu/libpng.so
pcl_filtering: /usr/lib/x86_64-linux-gnu/libz.so
pcl_filtering: /usr/lib/gcc/x86_64-linux-gnu/13/libgomp.so
pcl_filtering: /usr/lib/x86_64-linux-gnu/libpthread.a
pcl_filtering: CMakeFiles/pcl_filtering.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ethereal/pcl/voxel_grid_filter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pcl_filtering"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcl_filtering.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pcl_filtering.dir/build: pcl_filtering
.PHONY : CMakeFiles/pcl_filtering.dir/build

CMakeFiles/pcl_filtering.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pcl_filtering.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pcl_filtering.dir/clean

CMakeFiles/pcl_filtering.dir/depend:
	cd /home/ethereal/pcl/voxel_grid_filter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ethereal/pcl/voxel_grid_filter /home/ethereal/pcl/voxel_grid_filter /home/ethereal/pcl/voxel_grid_filter/build /home/ethereal/pcl/voxel_grid_filter/build /home/ethereal/pcl/voxel_grid_filter/build/CMakeFiles/pcl_filtering.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pcl_filtering.dir/depend
