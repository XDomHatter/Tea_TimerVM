//
// Created by Administrator on 2023-02-25.
//

#ifndef $TVM_SRC_SHARE_STRUCTURES_UTF8_HPP
#define $TVM_SRC_SHARE_STRUCTURES_UTF8_HPP

#include <asm/BytesUtils.hpp>

/// Store character in utf-8
class UTF8Char {
private:
    char *c_str;
public:
    int csize; // count of byte

    /// Create an empty character
    UTF8Char();
    /// Create utf-8 character from a existing utf-8(without '\0')
    /// @param bytes Free it by caller! Method only copy it.
    /// @param size Size of array(bytes)
    explicit UTF8Char(u1 *bytes);
    /// Create utf-8 from ascii char
    explicit UTF8Char(char ascii);
    ~UTF8Char();

    char *get_cstr();

    /// Calculate size for a c string to store utf8 chars
    /// @param cs UTF8 Chars
    /// @param length length of array(cs)
    static int cstr_size_of(UTF8Char *cs, int length);

    /// Change UTF8 chars into c string
    /// @param cs UTF8 Chars
    /// @param length length of array(cs)
    /// @return Char array, remember to free it!
    static char *cstr_of(UTF8Char *cs, int length);

    /// Get count of character of a c string(one utf-8 takes 2 or more bytes)
    /// @param cstr c string. (MUST END WITH '\0')
    static int length_of_utf8String(char * cstr);

    /// Calc size of an utf-8 character
    /// @param c FIRST BYTE of utf-8 char
    /// @return Size of bytes the utf-8 char takes
    static int size_of_utf8Char(u1 c);

    /// Box c string into a UTF8Char array
    /// @param cstr c string(MUST END WITH '\0')
    static UTF8Char * utf8Chars_of(char * cstr);

    /// Move pointer to next character in a utf-8 string
    /// !!! This method doesn't change the pointer !!!
    /// @param cstr utf-8 string
    /// @return pointer after moved(cstr)
    static inline char * next_utf8Char(char *cstr);
};

class U8String {
private:
    int length; // count of utf-8 ( not that of byte )
    char * _chars;

public:
    int _so_chars; // size of _chars


    /// Create an empty string
    U8String();
    /// Init by utf8 characters
    /// @param chars Only copy not refer!
    /// @param length length of chars, not size
    U8String(UTF8Char * chars, int length);
    /// Init by c string constant
    U8String(const char *chars);
    /// Init by c string
    U8String(char *chars, int length);

    /// Concat a string at the end of self
    U8String *join(U8String *str);
    /// Get c string(char *) object
    char * get_cstr();
    /// Get character at index
    char * get_utf8_char_at(int index);
    /// Detect if string is empty
    bool isEmpty();
};


#endif //$TVM_SRC_SHARE_STRUCTURES_UTF8_HPP
