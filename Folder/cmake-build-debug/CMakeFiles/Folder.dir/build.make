# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Folder.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Folder.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Folder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Folder.dir/flags.make

CMakeFiles/Folder.dir/main.cpp.obj: CMakeFiles/Folder.dir/flags.make
CMakeFiles/Folder.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Folder.dir/main.cpp.obj: CMakeFiles/Folder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Folder.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Folder.dir/main.cpp.obj -MF CMakeFiles\Folder.dir\main.cpp.obj.d -o CMakeFiles\Folder.dir\main.cpp.obj -c C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\main.cpp

CMakeFiles/Folder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Folder.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\main.cpp > CMakeFiles\Folder.dir\main.cpp.i

CMakeFiles/Folder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Folder.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\main.cpp -o CMakeFiles\Folder.dir\main.cpp.s

# Object files for target Folder
Folder_OBJECTS = \
"CMakeFiles/Folder.dir/main.cpp.obj"

# External object files for target Folder
Folder_EXTERNAL_OBJECTS =

Folder.exe: CMakeFiles/Folder.dir/main.cpp.obj
Folder.exe: CMakeFiles/Folder.dir/build.make
Folder.exe: CMakeFiles/Folder.dir/linklibs.rsp
Folder.exe: CMakeFiles/Folder.dir/objects1.rsp
Folder.exe: CMakeFiles/Folder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Folder.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Folder.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Folder.dir/build: Folder.exe
.PHONY : CMakeFiles/Folder.dir/build

CMakeFiles/Folder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Folder.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Folder.dir/clean

CMakeFiles/Folder.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\cmake-build-debug C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\cmake-build-debug C:\Users\user\Desktop\DYZ_TRAITEMENT_IMAGE\Folder\cmake-build-debug\CMakeFiles\Folder.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Folder.dir/depend
