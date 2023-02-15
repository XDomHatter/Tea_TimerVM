cmake_minimum_required(VERSION 3.16)
project(tvm)

#cpu headers
include_directories(src/cpu/aarch32)
include_directories(src/cpu/arm    )
include_directories(src/cpu/ppc    )
include_directories(src/cpu/s390   )
include_directories(src/cpu/sparc  )
include_directories(src/cpu/x86    )

include_directories(src/share)

set(CMAKE_CXX_STANDARD 14)

add_executable(tvm_1_0 main.cpp
    src/share/utilities/macros.hpp
    src/cpu/aarch32/MacroAssembler_aarch32.cpp src/cpu/aarch32/MacroAssembler_aarch32.hpp
    src/cpu/arm/MacroAssembler_arm.cpp src/cpu/arm/MacroAssembler_arm.hpp
    src/cpu/ppc/MacroAssembler_ppc.cpp src/cpu/ppc/MacroAssembler_ppc.hpp
    src/cpu/s390/MacroAssembler_s390.cpp src/cpu/s390/MacroAssembler_s390.hpp
    src/cpu/sparc/MacroAssembler_sparc.cpp src/cpu/sparc/MacroAssembler_sparc.hpp
    src/cpu/x86/MacroAssembler_x86.cpp src/cpu/x86/MacroAssembler_x86.hpp
    src/share/structures/Stack.cpp src/share/structures/Stack.hpp
        src/share/asm/BytesUtils.hpp
    src/share/asm/CodeBuffer.cpp src/share/asm/CodeBuffer.hpp
    src/share/asm/AsmCode.cpp src/share/asm/AsmCode.hpp
    src/cpu/x86/AsmCode_x86.cpp src/cpu/x86/AsmCode_x86.hpp
        src/share/asm/Endian.hpp src/share/asm/Endian.cpp
        src/share/asm/BytesUtils.hpp src/share/asm/BytesUtils.cpp
        src/share/oop/TFloat.hpp src/share/oop/TFloat.cpp
        src/share/codefile/TeaFileReader.cpp src/share/codefile/TeaFileReader.hpp
        src/share/run/TimerVM.cpp src/share/run/TimerVM.hpp
        src/share/run/Bootstrap.cpp src/share/run/Bootstrap.hpp
        src/share/utilities/file_macros.hpp
        src/share/codefile/TeaFileParser.cpp src/share/codefile/TeaFileParser.hpp)
