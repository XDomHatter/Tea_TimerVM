cmake_minimum_required(VERSION 3.16)
project(tvm)

#cpu headers
include_directories(src/cpu/aarch64)
include_directories(src/cpu/arm    )
include_directories(src/cpu/ppc    )
include_directories(src/cpu/s390   )
include_directories(src/cpu/sparc  )
include_directories(src/cpu/x86    )

include_directories(src/share)

set(CMAKE_CXX_STANDARD 14)

add_executable(tvm_1_0 main.cpp
        src/share/utilities/macros.hpp
        src/cpu/aarch64/MacroAssembler_aarch64.cpp src/cpu/aarch64/MacroAssembler_aarch64.h
        src/cpu/arm/MacroAssembler_arm.cpp src/cpu/arm/MacroAssembler_arm.h
        src/cpu/ppc/MacroAssembler_ppc.cpp src/cpu/ppc/MacroAssembler_ppc.h
        src/cpu/s390/MacroAssembler_s390.cpp src/cpu/s390/MacroAssembler_s390.h
        src/cpu/sparc/MacroAssembler_sparc.cpp src/cpu/sparc/MacroAssembler_sparc.h
        src/cpu/x86/MacroAssembler_x86.cpp src/cpu/x86/MacroAssembler_x86.h
        src/share/structures/Stack.cpp src/share/structures/Stack.h
        src/share/types/bytes.hpp
        src/share/file_reader/TFileReader.cpp src/share/file_reader/TFileReader.hpp
        src/os/windows/FileMapper_win.cpp src/os/windows/FileMapper_win.hpp
        src/os/linux/FileMapper_linux.cpp src/os/linux/FileMapper_linux.hpp
        src/share/asm/CodeBuffer.cpp src/share/asm/CodeBuffer.hpp src/share/asm/AsmCode.cpp src/share/asm/AsmCode.hpp)