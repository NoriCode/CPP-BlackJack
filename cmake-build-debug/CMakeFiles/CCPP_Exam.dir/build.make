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
CMAKE_COMMAND = /home/philip_nori/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/philip_nori/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/philip_nori/CCPP_Exam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/philip_nori/CCPP_Exam/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CCPP_Exam.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CCPP_Exam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CCPP_Exam.dir/flags.make

CMakeFiles/CCPP_Exam.dir/main.cpp.o: CMakeFiles/CCPP_Exam.dir/flags.make
CMakeFiles/CCPP_Exam.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CCPP_Exam.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CCPP_Exam.dir/main.cpp.o -c /home/philip_nori/CCPP_Exam/main.cpp

CMakeFiles/CCPP_Exam.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCPP_Exam.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philip_nori/CCPP_Exam/main.cpp > CMakeFiles/CCPP_Exam.dir/main.cpp.i

CMakeFiles/CCPP_Exam.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCPP_Exam.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philip_nori/CCPP_Exam/main.cpp -o CMakeFiles/CCPP_Exam.dir/main.cpp.s

CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.o: CMakeFiles/CCPP_Exam.dir/flags.make
CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.o: ../bjRuleController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.o -c /home/philip_nori/CCPP_Exam/bjRuleController.cpp

CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philip_nori/CCPP_Exam/bjRuleController.cpp > CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.i

CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philip_nori/CCPP_Exam/bjRuleController.cpp -o CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.s

CMakeFiles/CCPP_Exam.dir/bjCards.cpp.o: CMakeFiles/CCPP_Exam.dir/flags.make
CMakeFiles/CCPP_Exam.dir/bjCards.cpp.o: ../bjCards.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CCPP_Exam.dir/bjCards.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CCPP_Exam.dir/bjCards.cpp.o -c /home/philip_nori/CCPP_Exam/bjCards.cpp

CMakeFiles/CCPP_Exam.dir/bjCards.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCPP_Exam.dir/bjCards.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philip_nori/CCPP_Exam/bjCards.cpp > CMakeFiles/CCPP_Exam.dir/bjCards.cpp.i

CMakeFiles/CCPP_Exam.dir/bjCards.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCPP_Exam.dir/bjCards.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philip_nori/CCPP_Exam/bjCards.cpp -o CMakeFiles/CCPP_Exam.dir/bjCards.cpp.s

CMakeFiles/CCPP_Exam.dir/bjHand.cpp.o: CMakeFiles/CCPP_Exam.dir/flags.make
CMakeFiles/CCPP_Exam.dir/bjHand.cpp.o: ../bjHand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CCPP_Exam.dir/bjHand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CCPP_Exam.dir/bjHand.cpp.o -c /home/philip_nori/CCPP_Exam/bjHand.cpp

CMakeFiles/CCPP_Exam.dir/bjHand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCPP_Exam.dir/bjHand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philip_nori/CCPP_Exam/bjHand.cpp > CMakeFiles/CCPP_Exam.dir/bjHand.cpp.i

CMakeFiles/CCPP_Exam.dir/bjHand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCPP_Exam.dir/bjHand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philip_nori/CCPP_Exam/bjHand.cpp -o CMakeFiles/CCPP_Exam.dir/bjHand.cpp.s

CMakeFiles/CCPP_Exam.dir/blackJack.cpp.o: CMakeFiles/CCPP_Exam.dir/flags.make
CMakeFiles/CCPP_Exam.dir/blackJack.cpp.o: ../blackJack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CCPP_Exam.dir/blackJack.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CCPP_Exam.dir/blackJack.cpp.o -c /home/philip_nori/CCPP_Exam/blackJack.cpp

CMakeFiles/CCPP_Exam.dir/blackJack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCPP_Exam.dir/blackJack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philip_nori/CCPP_Exam/blackJack.cpp > CMakeFiles/CCPP_Exam.dir/blackJack.cpp.i

CMakeFiles/CCPP_Exam.dir/blackJack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCPP_Exam.dir/blackJack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philip_nori/CCPP_Exam/blackJack.cpp -o CMakeFiles/CCPP_Exam.dir/blackJack.cpp.s

CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.o: CMakeFiles/CCPP_Exam.dir/flags.make
CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.o: ../tempDeck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.o -c /home/philip_nori/CCPP_Exam/tempDeck.cpp

CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philip_nori/CCPP_Exam/tempDeck.cpp > CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.i

CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philip_nori/CCPP_Exam/tempDeck.cpp -o CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.s

CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.o: CMakeFiles/CCPP_Exam.dir/flags.make
CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.o: ../tempPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.o -c /home/philip_nori/CCPP_Exam/tempPlayer.cpp

CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philip_nori/CCPP_Exam/tempPlayer.cpp > CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.i

CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philip_nori/CCPP_Exam/tempPlayer.cpp -o CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.s

# Object files for target CCPP_Exam
CCPP_Exam_OBJECTS = \
"CMakeFiles/CCPP_Exam.dir/main.cpp.o" \
"CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.o" \
"CMakeFiles/CCPP_Exam.dir/bjCards.cpp.o" \
"CMakeFiles/CCPP_Exam.dir/bjHand.cpp.o" \
"CMakeFiles/CCPP_Exam.dir/blackJack.cpp.o" \
"CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.o" \
"CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.o"

# External object files for target CCPP_Exam
CCPP_Exam_EXTERNAL_OBJECTS =

../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/main.cpp.o
../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/bjRuleController.cpp.o
../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/bjCards.cpp.o
../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/bjHand.cpp.o
../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/blackJack.cpp.o
../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/tempDeck.cpp.o
../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/tempPlayer.cpp.o
../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/build.make
../CCPP_Exam: CMakeFiles/CCPP_Exam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../CCPP_Exam"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CCPP_Exam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CCPP_Exam.dir/build: ../CCPP_Exam

.PHONY : CMakeFiles/CCPP_Exam.dir/build

CMakeFiles/CCPP_Exam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CCPP_Exam.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CCPP_Exam.dir/clean

CMakeFiles/CCPP_Exam.dir/depend:
	cd /home/philip_nori/CCPP_Exam/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/philip_nori/CCPP_Exam /home/philip_nori/CCPP_Exam /home/philip_nori/CCPP_Exam/cmake-build-debug /home/philip_nori/CCPP_Exam/cmake-build-debug /home/philip_nori/CCPP_Exam/cmake-build-debug/CMakeFiles/CCPP_Exam.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CCPP_Exam.dir/depend

