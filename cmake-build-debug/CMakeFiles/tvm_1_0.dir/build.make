# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Administrator\Desktop\tvm\tvm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tvm_1_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tvm_1_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tvm_1_0.dir/flags.make

CMakeFiles/tvm_1_0.dir/main.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/main.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tvm_1_0.dir/main.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\main.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\main.cpp

CMakeFiles/tvm_1_0.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/main.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\main.cpp > CMakeFiles\tvm_1_0.dir\main.cpp.i

CMakeFiles/tvm_1_0.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/main.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\main.cpp -o CMakeFiles\tvm_1_0.dir\main.cpp.s

CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.obj: ../src/cpu/aarch64/MacroAssembler_aarch64.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\cpu\aarch64\MacroAssembler_aarch64.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\aarch64\MacroAssembler_aarch64.cpp

CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\aarch64\MacroAssembler_aarch64.cpp > CMakeFiles\tvm_1_0.dir\src\cpu\aarch64\MacroAssembler_aarch64.cpp.i

CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\aarch64\MacroAssembler_aarch64.cpp -o CMakeFiles\tvm_1_0.dir\src\cpu\aarch64\MacroAssembler_aarch64.cpp.s

CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.obj: ../src/cpu/arm/MacroAssembler_arm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\cpu\arm\MacroAssembler_arm.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\arm\MacroAssembler_arm.cpp

CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\arm\MacroAssembler_arm.cpp > CMakeFiles\tvm_1_0.dir\src\cpu\arm\MacroAssembler_arm.cpp.i

CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\arm\MacroAssembler_arm.cpp -o CMakeFiles\tvm_1_0.dir\src\cpu\arm\MacroAssembler_arm.cpp.s

CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.obj: ../src/cpu/ppc/MacroAssembler_ppc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\cpu\ppc\MacroAssembler_ppc.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\ppc\MacroAssembler_ppc.cpp

CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\ppc\MacroAssembler_ppc.cpp > CMakeFiles\tvm_1_0.dir\src\cpu\ppc\MacroAssembler_ppc.cpp.i

CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\ppc\MacroAssembler_ppc.cpp -o CMakeFiles\tvm_1_0.dir\src\cpu\ppc\MacroAssembler_ppc.cpp.s

CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.obj: ../src/cpu/s390/MacroAssembler_s390.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\cpu\s390\MacroAssembler_s390.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\s390\MacroAssembler_s390.cpp

CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\s390\MacroAssembler_s390.cpp > CMakeFiles\tvm_1_0.dir\src\cpu\s390\MacroAssembler_s390.cpp.i

CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\s390\MacroAssembler_s390.cpp -o CMakeFiles\tvm_1_0.dir\src\cpu\s390\MacroAssembler_s390.cpp.s

CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.obj: ../src/cpu/sparc/MacroAssembler_sparc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\cpu\sparc\MacroAssembler_sparc.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\sparc\MacroAssembler_sparc.cpp

CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\sparc\MacroAssembler_sparc.cpp > CMakeFiles\tvm_1_0.dir\src\cpu\sparc\MacroAssembler_sparc.cpp.i

CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\sparc\MacroAssembler_sparc.cpp -o CMakeFiles\tvm_1_0.dir\src\cpu\sparc\MacroAssembler_sparc.cpp.s

CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.obj: ../src/cpu/x86/MacroAssembler_x86.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\cpu\x86\MacroAssembler_x86.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\x86\MacroAssembler_x86.cpp

CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\x86\MacroAssembler_x86.cpp > CMakeFiles\tvm_1_0.dir\src\cpu\x86\MacroAssembler_x86.cpp.i

CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\x86\MacroAssembler_x86.cpp -o CMakeFiles\tvm_1_0.dir\src\cpu\x86\MacroAssembler_x86.cpp.s

CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.obj: ../src/cpu/zero/MacroAssembler_zero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\cpu\zero\MacroAssembler_zero.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\zero\MacroAssembler_zero.cpp

CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\zero\MacroAssembler_zero.cpp > CMakeFiles\tvm_1_0.dir\src\cpu\zero\MacroAssembler_zero.cpp.i

CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\cpu\zero\MacroAssembler_zero.cpp -o CMakeFiles\tvm_1_0.dir\src\cpu\zero\MacroAssembler_zero.cpp.s

CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.obj: ../src/share/structures/Stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\share\structures\Stack.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\share\structures\Stack.cpp

CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\share\structures\Stack.cpp > CMakeFiles\tvm_1_0.dir\src\share\structures\Stack.cpp.i

CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\share\structures\Stack.cpp -o CMakeFiles\tvm_1_0.dir\src\share\structures\Stack.cpp.s

CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.obj: ../src/share/file_reader/TFileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\share\file_reader\TFileReader.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\share\file_reader\TFileReader.cpp

CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\share\file_reader\TFileReader.cpp > CMakeFiles\tvm_1_0.dir\src\share\file_reader\TFileReader.cpp.i

CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\share\file_reader\TFileReader.cpp -o CMakeFiles\tvm_1_0.dir\src\share\file_reader\TFileReader.cpp.s

CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.obj: ../src/os/windows/FileMapper_win.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\os\windows\FileMapper_win.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\os\windows\FileMapper_win.cpp

CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\os\windows\FileMapper_win.cpp > CMakeFiles\tvm_1_0.dir\src\os\windows\FileMapper_win.cpp.i

CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\os\windows\FileMapper_win.cpp -o CMakeFiles\tvm_1_0.dir\src\os\windows\FileMapper_win.cpp.s

CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.obj: CMakeFiles/tvm_1_0.dir/flags.make
CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.obj: CMakeFiles/tvm_1_0.dir/includes_CXX.rsp
CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.obj: ../src/os/linux/FileMapperLinux.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.obj"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tvm_1_0.dir\src\os\linux\FileMapperLinux.cpp.obj -c C:\Users\Administrator\Desktop\tvm\tvm\src\os\linux\FileMapperLinux.cpp

CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.i"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\tvm\tvm\src\os\linux\FileMapperLinux.cpp > CMakeFiles\tvm_1_0.dir\src\os\linux\FileMapperLinux.cpp.i

CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.s"
	"D:\Program Files (x86)\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\tvm\tvm\src\os\linux\FileMapperLinux.cpp -o CMakeFiles\tvm_1_0.dir\src\os\linux\FileMapperLinux.cpp.s

# Object files for target tvm_1_0
tvm_1_0_OBJECTS = \
"CMakeFiles/tvm_1_0.dir/main.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.obj" \
"CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.obj"

# External object files for target tvm_1_0
tvm_1_0_EXTERNAL_OBJECTS =

tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/main.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/cpu/aarch64/MacroAssembler_aarch64.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/cpu/arm/MacroAssembler_arm.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/cpu/ppc/MacroAssembler_ppc.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/cpu/s390/MacroAssembler_s390.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/cpu/sparc/MacroAssembler_sparc.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/cpu/x86/MacroAssembler_x86.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/cpu/zero/MacroAssembler_zero.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/share/structures/Stack.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/share/file_reader/TFileReader.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/os/windows/FileMapper_win.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/src/os/linux/FileMapperLinux.cpp.obj
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/build.make
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/linklibs.rsp
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/objects1.rsp
tvm_1_0.exe: CMakeFiles/tvm_1_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable tvm_1_0.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tvm_1_0.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tvm_1_0.dir/build: tvm_1_0.exe

.PHONY : CMakeFiles/tvm_1_0.dir/build

CMakeFiles/tvm_1_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tvm_1_0.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tvm_1_0.dir/clean

CMakeFiles/tvm_1_0.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\Desktop\tvm\tvm C:\Users\Administrator\Desktop\tvm\tvm C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug C:\Users\Administrator\Desktop\tvm\tvm\cmake-build-debug\CMakeFiles\tvm_1_0.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tvm_1_0.dir/depend

