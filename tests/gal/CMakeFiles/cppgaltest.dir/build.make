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
CMAKE_SOURCE_DIR = /home/qed/docs/sc/tests/gal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qed/docs/sc/tests/gal

# Include any dependencies generated for this target.
include CMakeFiles/cppgaltest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cppgaltest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppgaltest.dir/flags.make

CMakeFiles/cppgaltest.dir/cppgaltest.o: CMakeFiles/cppgaltest.dir/flags.make
CMakeFiles/cppgaltest.dir/cppgaltest.o: cppgaltest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qed/docs/sc/tests/gal/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cppgaltest.dir/cppgaltest.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cppgaltest.dir/cppgaltest.o -c /home/qed/docs/sc/tests/gal/cppgaltest.cpp

CMakeFiles/cppgaltest.dir/cppgaltest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppgaltest.dir/cppgaltest.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qed/docs/sc/tests/gal/cppgaltest.cpp > CMakeFiles/cppgaltest.dir/cppgaltest.i

CMakeFiles/cppgaltest.dir/cppgaltest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppgaltest.dir/cppgaltest.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qed/docs/sc/tests/gal/cppgaltest.cpp -o CMakeFiles/cppgaltest.dir/cppgaltest.s

CMakeFiles/cppgaltest.dir/cppgaltest.o.requires:
.PHONY : CMakeFiles/cppgaltest.dir/cppgaltest.o.requires

CMakeFiles/cppgaltest.dir/cppgaltest.o.provides: CMakeFiles/cppgaltest.dir/cppgaltest.o.requires
	$(MAKE) -f CMakeFiles/cppgaltest.dir/build.make CMakeFiles/cppgaltest.dir/cppgaltest.o.provides.build
.PHONY : CMakeFiles/cppgaltest.dir/cppgaltest.o.provides

CMakeFiles/cppgaltest.dir/cppgaltest.o.provides.build: CMakeFiles/cppgaltest.dir/cppgaltest.o

CMakeFiles/cppgaltest.dir/gp.o: CMakeFiles/cppgaltest.dir/flags.make
CMakeFiles/cppgaltest.dir/gp.o: gp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qed/docs/sc/tests/gal/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cppgaltest.dir/gp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cppgaltest.dir/gp.o -c /home/qed/docs/sc/tests/gal/gp.cpp

CMakeFiles/cppgaltest.dir/gp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppgaltest.dir/gp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qed/docs/sc/tests/gal/gp.cpp > CMakeFiles/cppgaltest.dir/gp.i

CMakeFiles/cppgaltest.dir/gp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppgaltest.dir/gp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qed/docs/sc/tests/gal/gp.cpp -o CMakeFiles/cppgaltest.dir/gp.s

CMakeFiles/cppgaltest.dir/gp.o.requires:
.PHONY : CMakeFiles/cppgaltest.dir/gp.o.requires

CMakeFiles/cppgaltest.dir/gp.o.provides: CMakeFiles/cppgaltest.dir/gp.o.requires
	$(MAKE) -f CMakeFiles/cppgaltest.dir/build.make CMakeFiles/cppgaltest.dir/gp.o.provides.build
.PHONY : CMakeFiles/cppgaltest.dir/gp.o.provides

CMakeFiles/cppgaltest.dir/gp.o.provides.build: CMakeFiles/cppgaltest.dir/gp.o

# Object files for target cppgaltest
cppgaltest_OBJECTS = \
"CMakeFiles/cppgaltest.dir/cppgaltest.o" \
"CMakeFiles/cppgaltest.dir/gp.o"

# External object files for target cppgaltest
cppgaltest_EXTERNAL_OBJECTS =

cppgaltest: CMakeFiles/cppgaltest.dir/cppgaltest.o
cppgaltest: CMakeFiles/cppgaltest.dir/gp.o
cppgaltest: CMakeFiles/cppgaltest.dir/build.make
cppgaltest: /usr/lib64/libopencv_calib3d.so
cppgaltest: /usr/lib64/libopencv_contrib.so
cppgaltest: /usr/lib64/libopencv_core.so
cppgaltest: /usr/lib64/libopencv_features2d.so
cppgaltest: /usr/lib64/libopencv_flann.so
cppgaltest: /usr/lib64/libopencv_highgui.so
cppgaltest: /usr/lib64/libopencv_imgproc.so
cppgaltest: /usr/lib64/libopencv_legacy.so
cppgaltest: /usr/lib64/libopencv_ml.so
cppgaltest: /usr/lib64/libopencv_objdetect.so
cppgaltest: /usr/lib64/libopencv_photo.so
cppgaltest: /usr/lib64/libopencv_stitching.so
cppgaltest: /usr/lib64/libopencv_superres.so
cppgaltest: /usr/lib64/libopencv_ts.so
cppgaltest: /usr/lib64/libopencv_video.so
cppgaltest: /usr/lib64/libopencv_videostab.so
cppgaltest: CMakeFiles/cppgaltest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cppgaltest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppgaltest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppgaltest.dir/build: cppgaltest
.PHONY : CMakeFiles/cppgaltest.dir/build

CMakeFiles/cppgaltest.dir/requires: CMakeFiles/cppgaltest.dir/cppgaltest.o.requires
CMakeFiles/cppgaltest.dir/requires: CMakeFiles/cppgaltest.dir/gp.o.requires
.PHONY : CMakeFiles/cppgaltest.dir/requires

CMakeFiles/cppgaltest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppgaltest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppgaltest.dir/clean

CMakeFiles/cppgaltest.dir/depend:
	cd /home/qed/docs/sc/tests/gal && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qed/docs/sc/tests/gal /home/qed/docs/sc/tests/gal /home/qed/docs/sc/tests/gal /home/qed/docs/sc/tests/gal /home/qed/docs/sc/tests/gal/CMakeFiles/cppgaltest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppgaltest.dir/depend
