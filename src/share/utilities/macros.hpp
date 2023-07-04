//
// Created by Administrator on 2022-12-25.
//

#ifndef MACROS
#define MACROS

#include <stdlib.h>
#include <stdio.h>

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

#define EDPARAM EENDIAN e

#endif //MACROS
