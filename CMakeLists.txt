cmake_minimum_required(VERSION 3.16)
project(tea)

#cpu headers
include_directories(src/cpu/aarch32)
include_directories(src/cpu/arm    )
include_directories(src/cpu/ppc    )
include_directories(src/cpu/s390   )
include_directories(src/cpu/sparc  )
include_directories(src/cpu/x86    )
#os headers
include_directories(src/os/windows)
include_directories(src/os/linux)

include_directories(src/share)

set(CMAKE_CXX_STANDARD 14)

# decide cpu bit arch
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions(-DBITARCH=BA64)
    add_definitions(-DBITARCH64)
    message(STATUS "Target is 64 bits")
else()
    add_definitions(-DBITARCH=BA32)
    add_definitions(-DBITARCH32)
    message(STATUS "Target is 32 bits")
endif()

# decide os
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
    add_definitions(-DINCLUDE_SUFFIX_OS=_linux)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for macOS")
    add_definitions(-DINCLUDE_SUFFIX_OS=_mac)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")
    add_definitions(-DINCLUDE_SUFFIX_OS=_win)
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for IBM AIX")
    add_definitions(-DINCLUDE_SUFFIX_OS=_aix)
else()
    message(STATUS "UNKNOWN OS")
endif()

add_executable(tea
        main.cpp
        src/share/utilities/macros.hpp
        src/share/structures/Stack.cpp src/share/structures/Stack.hpp
        src/share/asm/BytesUtils.hpp
        src/share/asm/CodeBuffer.cpp src/share/asm/CodeBuffer.hpp
        src/share/asm/AsmCode.cpp src/share/asm/AsmCode.hpp
        src/share/asm/Endian.hpp src/share/asm/Endian.cpp
        src/share/asm/BytesUtils.hpp src/share/asm/BytesUtils.cpp
        src/share/oop/TFloat.hpp src/share/oop/TFloat.cpp
        src/share/codefile/TeaFileReader.cpp src/share/codefile/TeaFileReader.hpp
        src/share/run/TimerVM.cpp src/share/run/TimerVM.hpp
        src/share/run/Bootstrap.cpp src/share/run/Bootstrap.hpp
        src/share/utilities/file_macros.hpp
        src/share/codefile/TeaFileParser.cpp src/share/codefile/TeaFileParser.hpp
        src/share/run/CmdParser.cpp src/share/run/CmdParser.hpp
        src/share/utilities/cstr_utils.hpp
        src/share/utilities/Tio.cpp src/share/utilities/Tio.hpp
        src/share/structures/Utf8.cpp src/share/structures/Utf8.hpp
        src/share/structures/ArrayList.cpp src/share/structures/ArrayList.hpp
        src/share/structures/BitMap.cpp src/share/structures/BitMap.hpp
        src/share/asm/Memory.hpp src/share/utilities/cint_utils.hpp
        src/share/asm/Memory.cpp src/share/utilities/cint_utils.cpp)

