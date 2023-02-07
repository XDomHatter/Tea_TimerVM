//
// Created by Administrator on 2022-12-25.
//

#ifndef TVM_1_0_MACROS_HPP
#define TVM_1_0_MACROS_HPP

#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
#define INCLUDE_SUFFIX_CPU _x86
#define INCLUDE_SUFFIX_OS  _win
#define LITTLE_ENDIAN
#endif

#define FAST_FUNC(func_name) func_name##__FAST

//to change a token to string
#define STR(x)  #x
#define XSTR(x) STR(x)

// include from openjdk:
// Apply pre-processor token pasting to the expansions of x and y.
// The token pasting operator (##) prevents its arguments from being
// expanded.  This macro allows expansion of its arguments before the
// concatenation is performed.  Note: One auxilliary level ought to be
// sufficient, but two are used because of bugs in some preprocesors.
#define PASTE_TOKENS(x, y) PASTE_TOKENS_AUX(x, y)
#define PASTE_TOKENS_AUX(x, y) PASTE_TOKENS_AUX2(x, y)
#define PASTE_TOKENS_AUX2(x, y) x ## y

#define CPU_HEADER_STEM(basename) PASTE_TOKENS(basename, INCLUDE_SUFFIX_CPU)
#define OS_HEADER_STEM(basename) PASTE_TOKENS(basename, INCLUDE_SUFFIX_OS)

// Include platform dependent files.
//
// This macro constructs from basename and INCLUDE_SUFFIX_OS /
// INCLUDE_SUFFIX_CPU / INCLUDE_SUFFIX_COMPILER, which are set on
// the command line, the name of platform dependent files to be included.
// Example: INCLUDE_SUFFIX_OS=_linux / INCLUDE_SUFFIX_CPU=_sparc
//   CPU_HEADER_INLINE(macroAssembler) --> macroAssembler_sparc.inline.hpp
//   CPU_HEADER(macroAssembler) --> macroAssembler_sparc.hpp
//
// basename<cpu>.hpp / basename<cpu>.inline.hpp
#define CPU_HEADER_H(basename)         XSTR(CPU_HEADER_STEM(basename).h)
#define CPU_HEADER(basename)           XSTR(CPU_HEADER_STEM(basename).hpp)
#define CPU_HEADER_INLINE(basename)    XSTR(CPU_HEADER_STEM(basename).inline.hpp)

//x86
#if defined(IA32) || defined(AMD64)
#define X86
#define X86_ONLY(code) code
#define NOT_X86(code)
#else
#undef X86
#define X86_ONLY(code)
#define NOT_X86(code) code
#endif

#if defined(BIG_ENDIAN)
#define ENDIAN_CODE(big, little) big
#endif
#ifdef  LITTLE_ENDIAN
#define ENDIAN_CODE(big, little) little
#endif


#define CPU_HEADER_STEM(basename) PASTE_TOKENS(basename, INCLUDE_SUFFIX_CPU)
#define OS_HEADER_STEM(basename) PASTE_TOKENS(basename, INCLUDE_SUFFIX_OS)

#ifdef DEBUG
#define _DEBUG_(code) code
#else
#define _DEBUG_(code)
#endif

#define ERR( text )   \
    puts(XSTR(text)); \
    exit(1);          \

#endif //TVM_1_0_MACROS_HPP
