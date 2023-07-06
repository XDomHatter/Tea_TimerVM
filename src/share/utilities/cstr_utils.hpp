//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_UTILITIES_CSTR_UTILS_HPP
#define $TVM_SRC_SHARE_UTILITIES_CSTR_UTILS_HPP

#include <string.h>
#include <stdarg.h>

#define cstr_EQUAL(str1, str2) \
    (strcmp((str1), (str2)) == 0)

class CSTRUtil{
public:
    /// dst = src;
    /// @param dst
    /// @param src
    /// @return addr of dst
    static char * copy(char * dst, char * src);

    /// return s1 + s2; DOESN'T change s1!
    /// @param s1 address of first str
    /// @param s2 the string to cat after s1
    /// @return new string, the str after catted
    static char * cat(char *s1, char *s2);

    /// get count of bytes (not utf-8 characters) without '\0'
    static int len(char * str);
};

#endif //$TVM_SRC_SHARE_UTILITIES_CSTR_UTILS_HPP
