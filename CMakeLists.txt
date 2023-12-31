cmake_minimum_required(VERSION 3.21)
project(tea)

set(CMAKE_CXX_STANDARD 14)

# save asm file
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")

include(CheckIncludeFiles)

add_compile_options(-Wno-write-strings)

include_directories(src/share)
include_directories(src/os)

CHECK_INCLUDE_FILES(stdint.h STDINT_H_EXIST)
CHECK_INCLUDE_FILES(malloc.h MALLOC_H_EXIST)
if (STDINT_H_EXIST)
    message("TEA: stdint.h found")
    add_definitions(-DSTDINT_H_EXIST)
else ()
    message("TEA: stdint.h not found")
endif ()
if (MALLOC_H_EXIST)
    message("TEA: malloc.h found")
    add_definitions(-DMALLOC_H_EXIST)
else ()
    message("TEA: malloc.h not found")
endif ()

# detect endian
if (CMAKE_CXX_BYTE_ORDER STREQUAL "BIG_ENDIAN")
    add_definitions(-DED_BIGENDIAN)
    message("TEA: System is big endian")
elseif (CMAKE_CXX_BYTE_ORDER STREQUAL "LITTLE_ENDIAN")
    add_definitions(-DED_LITENDIAN)
    message("TEA: System is little endian")
else ()
    message(FATAL_ERROR "Unknown endian")
endif()


# detect cpu
if(CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
    # x86 or amd64 architecture
    message("TEA: on x86 arch CPU")
    include_directories(src/cpu/x86)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "(arm)|(ARM)|(armv7)|(ARMv7)")
    # ARM architecture
    message("TEA: on arm arch CPU")
    include_directories(src/cpu/arm)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "(aarch64)|(AARCH64)")
    # AArch64 architecture
    message("TEA: on aarch64 arch CPU")
    include_directories(src/cpu/aarch64)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc64le)|(PPC64LE)")
    # PowerPC 64 Little Endian (ppc64le) architecture
    message("TEA: on ppc64le arch CPU")
    include_directories(src/cpu/ppc)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc64)|(PPC64)")
    # PowerPC 64 (ppc64) architecture
    message("TEA: on ppc64 arch CPU")
    include_directories(src/cpu/ppc)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc)|(PPC)")
    # PowerPC (ppc) architecture
    message("TEA: on ppc arch CPU")
    include_directories(src/cpu/ppc)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "(s390x)|(S390X)")
    # IBM System z (s390x) architecture
    message("TEA: on s390 arch CPU")
    include_directories(src/cpu/s390)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "(sparc)|(SPARC)")
    # SPARC (sparc) architecture
    message("TEA: on sparc arch CPU")
    include_directories(src/cpu/sparc)
else()
    message(FATAL_ERROR "UNKNOWN CPU")
endif()

# detect cpu bit arch
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions(-DBITARCH=BA64)
    add_definitions(-DBITARCH64)
    message("TEA: Target is 64 bits")
else()
    add_definitions(-DBITARCH=BA32)
    add_definitions(-DBITARCH32)
    message("TEA: Target is 32 bits")
endif()

# detect os
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("TEA: Configuring on/for Linux")
    add_definitions(-DOS_LINUX)
    include_directories(src/os/linux)

elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message("TEA: Configuring on/for MacOS")
    add_definitions(-DOS_MACOS)
    include_directories(src/os/macos)

elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("TEA: Configuring on/for Windows")
    add_definitions(-DOS_WINDOWS)
    include_directories(src/os/windows)

elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message("TEA: Configuring on/for IBM AIX")
    add_definitions(-DOS_AIX)
    include_directories(src/os/aix)
else()
    message(ERROR "UNKNOWN OS")
endif()

add_executable(tea
        main.cpp

        # utilities
        src/share/utilities/macros.hpp
        src/share/utilities/file_macros.hpp
        src/share/utilities/cstr_utils.hpp src/share/utilities/cstr_utils.cpp
        src/share/utilities/Tio.cpp src/share/utilities/Tio.hpp
        src/share/utilities/cint_utils.hpp src/share/utilities/cint_utils.cpp
        src/share/utilities/types.hpp

        # asm
        src/share/asm/Memory.hpp src/share/asm/Memory.cpp
        src/share/asm/Endian.hpp
        src/share/asm/BytesUtils.hpp src/share/asm/BytesUtils.cpp
        src/share/asm/ByteStream.cpp src/share/asm/ByteStream.hpp

        # codefile
        src/share/codefile/TeaFileReader.cpp src/share/codefile/TeaFileReader.hpp
        src/share/codefile/TeaFileParser.cpp src/share/codefile/TeaFileParser.hpp
        src/share/codefile/CodeFileObj.hpp src/share/codefile/CodeFileObj.cpp
        src/share/codefile/CodeFileUtils.cpp src/share/codefile/CodeFileUtils.hpp

        # run
        src/share/run/CmdParser.cpp src/share/run/CmdParser.hpp
        src/share/run/TimerVM.cpp src/share/run/TimerVM.hpp
        src/share/utilities/STATUS.hpp

        # structures
        src/share/structures/Stack.cpp src/share/structures/Stack.hpp
        src/share/structures/Utf8.cpp src/share/structures/Utf8.hpp
        src/share/structures/ArrayList.cpp src/share/structures/ArrayList.hpp
        src/share/structures/BitMap.cpp src/share/structures/BitMap.hpp

        # oop
        src/share/oop/Constant.cpp src/share/oop/Constant.hpp
        src/share/oop/ConstantPool.cpp src/share/oop/ConstantPool.hpp

        # runtime
        src/share/runtime/teaVariable.hpp
        src/share/runtime/teaFunction.hpp src/share/runtime/teaFunction.cpp
        src/share/runtime/opCode.hpp src/share/runtime/opCode.cpp
        src/share/runtime/teaException.hpp
        src/share/runtime/interpreter.cpp src/share/runtime/interpreter.hpp
        src/share/runtime/teaValue.cpp src/share/runtime/teaValue.hpp
        src/share/runtime/heap.cpp src/share/runtime/heap.hpp
        src/share/runtime/object.hpp src/share/runtime/object.cpp)

