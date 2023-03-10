cmake_minimum_required(VERSION 3.16)
project(tea)

# save asm file
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")

# cpu headers
include_directories(src/cpu/aarch32)
include_directories(src/cpu/arm    )
include_directories(src/cpu/ppc    )
include_directories(src/cpu/s390   )
include_directories(src/cpu/sparc  )
include_directories(src/cpu/x86    )

include_directories(src/share)

set(CMAKE_CXX_STANDARD 14)

# decide cpu bit arch
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions(-DBITARCH=BA64)
    add_definitions(-DBITARCH64)
    message("Target is 64 bits")
else()
    add_definitions(-DBITARCH=BA32)
    add_definitions(-DBITARCH32)
    message("Target is 32 bits")
endif()

# decide os
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("Configuring on/for Linux")
    add_definitions(-DINCLUDE_SUFFIX_OS=_linux)
    include_directories(src/os/linux)

elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message("Configuring on/for MacOS")
    add_definitions(-DINCLUDE_SUFFIX_OS=_mac)
    include_directories(src/os/macos)

elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Configuring on/for Windows")
    add_definitions(-DINCLUDE_SUFFIX_OS=_win)
    include_directories(src/os/windows)

elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message("Configuring on/for IBM AIX")
    add_definitions(-DINCLUDE_SUFFIX_OS=_aix)
    include_directories(src/os/aix)

else()
    message(ERROR "UNKNOWN OS")
endif()

message("\n")

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
        src/share/asm/Memory.cpp src/share/utilities/cint_utils.cpp
)

