# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/kpit/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kpit/test

# Include any dependencies generated for this target.
include CMakeFiles/cvtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cvtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cvtest.dir/flags.make

CMakeFiles/cvtest.dir/Padding.cpp.o: CMakeFiles/cvtest.dir/flags.make
CMakeFiles/cvtest.dir/Padding.cpp.o: Padding.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kpit/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cvtest.dir/Padding.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cvtest.dir/Padding.cpp.o -c /home/kpit/test/Padding.cpp

CMakeFiles/cvtest.dir/Padding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cvtest.dir/Padding.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kpit/test/Padding.cpp > CMakeFiles/cvtest.dir/Padding.cpp.i

CMakeFiles/cvtest.dir/Padding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cvtest.dir/Padding.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kpit/test/Padding.cpp -o CMakeFiles/cvtest.dir/Padding.cpp.s

# Object files for target cvtest
cvtest_OBJECTS = \
"CMakeFiles/cvtest.dir/Padding.cpp.o"

# External object files for target cvtest
cvtest_EXTERNAL_OBJECTS =

cvtest: CMakeFiles/cvtest.dir/Padding.cpp.o
cvtest: CMakeFiles/cvtest.dir/build.make
cvtest: /usr/local/lib/libopencv_gapi.so.4.9.0
cvtest: /usr/local/lib/libopencv_highgui.so.4.9.0
cvtest: /usr/local/lib/libopencv_ml.so.4.9.0
cvtest: /usr/local/lib/libopencv_objdetect.so.4.9.0
cvtest: /usr/local/lib/libopencv_photo.so.4.9.0
cvtest: /usr/local/lib/libopencv_stitching.so.4.9.0
cvtest: /usr/local/lib/libopencv_video.so.4.9.0
cvtest: /usr/local/lib/libopencv_videoio.so.4.9.0
cvtest: /usr/local/lib/libopencv_imgcodecs.so.4.9.0
cvtest: /usr/local/lib/libopencv_dnn.so.4.9.0
cvtest: /usr/local/lib/libopencv_calib3d.so.4.9.0
cvtest: /usr/local/lib/libopencv_features2d.so.4.9.0
cvtest: /usr/local/lib/libopencv_flann.so.4.9.0
cvtest: /usr/local/lib/libopencv_imgproc.so.4.9.0
cvtest: /usr/local/lib/libopencv_core.so.4.9.0
cvtest: CMakeFiles/cvtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kpit/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cvtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cvtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cvtest.dir/build: cvtest

.PHONY : CMakeFiles/cvtest.dir/build

CMakeFiles/cvtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cvtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cvtest.dir/clean

CMakeFiles/cvtest.dir/depend:
	cd /home/kpit/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kpit/test /home/kpit/test /home/kpit/test /home/kpit/test /home/kpit/test/CMakeFiles/cvtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cvtest.dir/depend

