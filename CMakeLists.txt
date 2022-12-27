cmake_minimum_required(VERSION 3.16)
project(tvm_1_0)

#cpu headers
include_directories(.\\src\\cpu\\aarch64)
include_directories(.\\src\\cpu\\arm    )
include_directories(.\\src\\cpu\\ppc    )
include_directories(.\\src\\cpu\\s390   )
include_directories(.\\src\\cpu\\sparc  )
include_directories(.\\src\\cpu\\x86    )
include_directories(.\\src\\cpu\\zero   )

include_directories(.\\src\\share\\utilities\\)

set(CMAKE_CXX_STANDARD 14)

add_executable(tvm_1_0 main.cpp src/share/utilities/macros.hpp src/cpu/aarch64/MacroAssembler_aarch64.cpp src/cpu/aarch64/MacroAssembler_aarch64.h src/cpu/arm/MacroAssembler_arm.cpp src/cpu/arm/MacroAssembler_arm.h src/cpu/ppc/MacroAssembler_ppc.cpp src/cpu/ppc/MacroAssembler_ppc.h src/cpu/s390/MacroAssembler_s390.cpp src/cpu/s390/MacroAssembler_s390.h src/cpu/sparc/MacroAssembler_sparc.cpp src/cpu/sparc/MacroAssembler_sparc.h src/cpu/x86/MacroAssembler_x86.cpp src/cpu/x86/MacroAssembler_x86.h src/cpu/zero/MacroAssembler_zero.cpp src/cpu/zero/MacroAssembler_zero.h src/share/structures/Stack.cpp src/share/structures/Stack.h src/share/utilities/types.h)