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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qed/docs/sc/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qed/docs/sc/tests

# Include any dependencies generated for this target.
include CMakeFiles/cvMod.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cvMod.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cvMod.dir/flags.make

CMakeFiles/cvMod.dir/cvMod.cpp.o: CMakeFiles/cvMod.dir/flags.make
CMakeFiles/cvMod.dir/cvMod.cpp.o: cvMod.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qed/docs/sc/tests/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cvMod.dir/cvMod.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cvMod.dir/cvMod.cpp.o -c /home/qed/docs/sc/tests/cvMod.cpp

CMakeFiles/cvMod.dir/cvMod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cvMod.dir/cvMod.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qed/docs/sc/tests/cvMod.cpp > CMakeFiles/cvMod.dir/cvMod.cpp.i

CMakeFiles/cvMod.dir/cvMod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cvMod.dir/cvMod.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qed/docs/sc/tests/cvMod.cpp -o CMakeFiles/cvMod.dir/cvMod.cpp.s

CMakeFiles/cvMod.dir/cvMod.cpp.o.requires:
.PHONY : CMakeFiles/cvMod.dir/cvMod.cpp.o.requires

CMakeFiles/cvMod.dir/cvMod.cpp.o.provides: CMakeFiles/cvMod.dir/cvMod.cpp.o.requires
	$(MAKE) -f CMakeFiles/cvMod.dir/build.make CMakeFiles/cvMod.dir/cvMod.cpp.o.provides.build
.PHONY : CMakeFiles/cvMod.dir/cvMod.cpp.o.provides

CMakeFiles/cvMod.dir/cvMod.cpp.o.provides.build: CMakeFiles/cvMod.dir/cvMod.cpp.o

# Object files for target cvMod
cvMod_OBJECTS = \
"CMakeFiles/cvMod.dir/cvMod.cpp.o"

# External object files for target cvMod
cvMod_EXTERNAL_OBJECTS =

cvMod: CMakeFiles/cvMod.dir/cvMod.cpp.o
cvMod: CMakeFiles/cvMod.dir/build.make
cvMod: /usr/local/lib/libopencv_videostab.so.3.1.0
cvMod: /usr/local/lib/libopencv_videoio.so.3.1.0
cvMod: /usr/local/lib/libopencv_video.so.3.1.0
cvMod: /usr/local/lib/libopencv_superres.so.3.1.0
cvMod: /usr/local/lib/libopencv_stitching.so.3.1.0
cvMod: /usr/local/lib/libopencv_shape.so.3.1.0
cvMod: /usr/local/lib/libopencv_photo.so.3.1.0
cvMod: /usr/local/lib/libopencv_objdetect.so.3.1.0
cvMod: /usr/local/lib/libopencv_ml.so.3.1.0
cvMod: /usr/local/lib/libopencv_imgproc.so.3.1.0
cvMod: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
cvMod: /usr/local/lib/libopencv_highgui.so.3.1.0
cvMod: /usr/local/lib/libopencv_flann.so.3.1.0
cvMod: /usr/local/lib/libopencv_features2d.so.3.1.0
cvMod: /usr/local/lib/libopencv_core.so.3.1.0
cvMod: /usr/local/lib/libopencv_calib3d.so.3.1.0
cvMod: /usr/local/lib/libopencv_features2d.so.3.1.0
cvMod: /usr/local/lib/libopencv_ml.so.3.1.0
cvMod: /usr/local/lib/libopencv_highgui.so.3.1.0
cvMod: /usr/local/lib/libopencv_videoio.so.3.1.0
cvMod: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
cvMod: /usr/local/lib/libopencv_flann.so.3.1.0
cvMod: /usr/local/lib/libopencv_video.so.3.1.0
cvMod: /usr/local/lib/libopencv_imgproc.so.3.1.0
cvMod: /usr/local/lib/libopencv_core.so.3.1.0
cvMod: CMakeFiles/cvMod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cvMod"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cvMod.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cvMod.dir/build: cvMod
.PHONY : CMakeFiles/cvMod.dir/build

CMakeFiles/cvMod.dir/requires: CMakeFiles/cvMod.dir/cvMod.cpp.o.requires
.PHONY : CMakeFiles/cvMod.dir/requires

CMakeFiles/cvMod.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cvMod.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cvMod.dir/clean

CMakeFiles/cvMod.dir/depend:
	cd /home/qed/docs/sc/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qed/docs/sc/tests /home/qed/docs/sc/tests /home/qed/docs/sc/tests /home/qed/docs/sc/tests /home/qed/docs/sc/tests/CMakeFiles/cvMod.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cvMod.dir/depend

