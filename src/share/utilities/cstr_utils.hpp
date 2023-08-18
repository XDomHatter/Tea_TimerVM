//
// Created by Administrator on 2023-02-15.
//

#ifndef $TEA_SRC_SHARE_UTILITIES_CSTR_UTILS_HPP
#define $TEA_SRC_SHARE_UTILITIES_CSTR_UTILS_HPP

#include <string.h>
#include <stdarg.h>

#define cstr_EQUAL(str1, str2) \
    (strcmp((str1), (str2)) == 0)

class CSTRUtil {
public:
    /// dst = src;
    /// @param dst
    /// @param src
    /// @return addr of dst
    static char *copy(char *dst, char *src);
    
    /// return s1 + s2; DOESN'T change s1!
    /// @param s1 address of first str
    /// @param s2 the string to cat after s1
    /// @return new string, the str after catted
    static char *cat(char *s1, char *s2);
    static char *cat(char *s1, ...);
    
    /// get count of bytes (not utf-8 characters) without '\0'
    static int len(char *str);
    
    /// Return if src's end is obj.
    /// @note The function isn't safe when facing to Timing Attack
    static bool unsafe_end_with(char *src, char *obj, int len_of_src, int len_of_obj);
    /// Return if src's end is obj.(Simpler to call version)
    inline static bool unsafe_end_with(char *src, char *obj) {
        return unsafe_end_with(src, obj, len(src), len(obj));
    }
    static char *replace(char *str, char *find, char *replace);
    /// BKDRHash algorithm
    static size_t get_hashcode(char *str);
};

#endif //$TEA_SRC_SHARE_UTILITIES_CSTR_UTILS_HPP
