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
CMAKE_SOURCE_DIR = /home/u189940/wordCloud

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/u189940/wordCloud/build

# Include any dependencies generated for this target.
include wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/depend.make

# Include the progress variables for this target.
include wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/progress.make

# Include the compile flags for this target's objects.
include wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/flags.make

wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.o: wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/flags.make
wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.o: ../wordcloud/optimized_wordcloud.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u189940/wordCloud/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.o"
	cd /home/u189940/wordCloud/build/wordcloud && /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/bin/icpx  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.o -c /home/u189940/wordCloud/wordcloud/optimized_wordcloud.cpp

wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.i"
	cd /home/u189940/wordCloud/build/wordcloud && /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u189940/wordCloud/wordcloud/optimized_wordcloud.cpp > CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.i

wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.s"
	cd /home/u189940/wordCloud/build/wordcloud && /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u189940/wordCloud/wordcloud/optimized_wordcloud.cpp -o CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.s

# Object files for target optwordcloud.fpga_sim
optwordcloud_fpga_sim_OBJECTS = \
"CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.o"

# External object files for target optwordcloud.fpga_sim
optwordcloud_fpga_sim_EXTERNAL_OBJECTS =

wordcloud/optwordcloud.fpga_sim: wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/optimized_wordcloud.cpp.o
wordcloud/optwordcloud.fpga_sim: wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/build.make
wordcloud/optwordcloud.fpga_sim: wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/u189940/wordCloud/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable optwordcloud.fpga_sim"
	cd /home/u189940/wordCloud/build/wordcloud && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/optwordcloud.fpga_sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/build: wordcloud/optwordcloud.fpga_sim

.PHONY : wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/build

wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/clean:
	cd /home/u189940/wordCloud/build/wordcloud && $(CMAKE_COMMAND) -P CMakeFiles/optwordcloud.fpga_sim.dir/cmake_clean.cmake
.PHONY : wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/clean

wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/depend:
	cd /home/u189940/wordCloud/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/u189940/wordCloud /home/u189940/wordCloud/wordcloud /home/u189940/wordCloud/build /home/u189940/wordCloud/build/wordcloud /home/u189940/wordCloud/build/wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : wordcloud/CMakeFiles/optwordcloud.fpga_sim.dir/depend

