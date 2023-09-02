//
// Created by Administrator on 2022-12-25.
//

#ifndef MACROS
#define MACROS

#include <stdlib.h>
#include <stdio.h>

typedef void * UtilType;

#define var auto

#define FAST_FUNC(func_name) func_name##_fast

//to change a token to string
#define STR(x)  #x
#define XSTR(x) STR(x)

#ifdef DEBUG
#define DEBUGCODE(code) code
#else
#define DEBUGCODE(code)
#endif

#define ERR(text)   \
    puts(XSTR(text)); \
    exit(1);          \

#define QUIT(code) exit((code));


#if defined(OS_WINDOWS)
    #define WINDOWS_ONLY(code) code
    #define NOT_WINDOWS(code)
#else
    #define WINDOWS_ONLY(code)
    #define NOT_WINDOWS(code) code
#endif

#if defined(OS_LINUX) || defined(OS_AIX)
    #define UNIX_ONLY(code) code
    #define NOT_UNIX(code)
#else
    #define UNIX_ONLY(code)
    #define NOT_UNIX(code) code
#endif

#if defined(OS_MACOS)
    #define MAC_ONLY(code)
    #define NOT_MAC(code)
#else
    #define MAC_ONLY(code)
    #define NOT_MAC(code) code
#endif


#if defined(BITARCH64)
    #define BITARCH64_ONLY(code) code
    #define BITARCH32_ONLY(code)
#else
    #define BITARCH64_ONLY(code)
    #define BITARCH32_ONLY(code) code
#endif

#endif //MACROS
