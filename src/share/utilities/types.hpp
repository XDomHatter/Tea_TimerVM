//
// Created by XDomHatter on 2023-08-20.
//

#ifndef $TEA_SRC_SHARE_UTILITIES_TYPES_HPP
#define $TEA_SRC_SHARE_UTILITIES_TYPES_HPP

#include <asm/Memory.hpp>

#ifdef STDINT_H_EXIST
#include <stdint.h>
#endif

#ifndef STDINT_H_EXIST
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
#endif
typedef int8_t tsbyte;
typedef int16_t tsshort;
typedef int32_t tsint;
typedef int64_t tslong;

typedef uint8_t tubyte;
typedef uint16_t tushout;
typedef uint32_t tuint;
typedef uint64_t tulong;
typedef enum {
    TType_STR=0,

    TType_N1=1, TType_N2=2, TType_N4=3, TType_N8=4,

    TType_OOP=5,

    TType_ARR=6, // 1 dimension array

    TType_NULL, // NULL value type
} TeaType;

constexpr tuint tea_type_size[] = {
    4, // TType_STR
    1, // TType_N1
    2, // TType_N2
    4, // TType_N4
    8, // TType_N8
    4, // TType_OOP
    0, // TType_ARR, Unknown Size
    0, // TType_NULL, No Size
    0, // TType_Unknown, No Size
};

#define TeaType_DO(t, STR, N1, N2, N4, N8, OOP, ARR, NUL ) \
    switch(t) {                                            \
    case TType_STR: {                                      \
        {STR}                                              \
        break;                                             \
    }                                                      \
    case TType_N1: {                                       \
        {N1}                                               \
        break;                                             \
    }                                                      \
    case TType_N2: {                                       \
        {N2}                                               \
        break;                                             \
    }                                                      \
    case TType_N4: {                                       \
        {N4}                                               \
        break;                                             \
    }                                                      \
    case TType_N8: {                                       \
        {N8}                                               \
        break;                                             \
    }                                                      \
    case TType_OOP: {                                      \
        {OOP}                                              \
        break;                                             \
    }                                                      \
    case TType_ARR: {                                      \
        {ARR}                                              \
        break;                                             \
    }                                                      \
    case TType_NULL: {                                     \
        {NUL}                                              \
        break;                                             \
    }                                                      \
}

#endif //$TEA_SRC_SHARE_UTILITIES_TYPES_HPP
