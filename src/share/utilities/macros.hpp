//
// Created by Administrator on 2022-12-25.
//

#ifndef TVM_1_0_MACROS_HPP
#define TVM_1_0_MACROS_HPP


#define DEBUG
#ifdef DEBUG
#define INCLUDE_SUFFIX_CPU _x86
#define INCLUDE_SUFFIX_OS  _win
#define LITTLE_ENDIAN
#endif



//to change a token to string
#define STR(x) #x
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

#define CPU_HEADER()

//bsd:
#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
#ifndef BSD
#define BSD
#endif // BSD defined in <sys/param.h>
#define BSD_ONLY(code) code
#define NOT_BSD(code)
#else
#define BSD_ONLY(code)
#define NOT_BSD(code) code
#endif

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

#endif //TVM_1_0_MACROS_HPP
