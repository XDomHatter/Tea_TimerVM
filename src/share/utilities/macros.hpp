//
// Created by Administrator on 2022-12-25.
//

#ifndef TVM_1_0_MACROS_HPP
#define TVM_1_0_MACROS_HPP

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


#endif //TVM_1_0_MACROS_HPP
