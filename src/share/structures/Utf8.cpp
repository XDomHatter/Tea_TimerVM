//
// Created by Administrator on 2023-02-25.
//
#include "Utf8.hpp"
#include <asm/Memory.hpp>
#include <utilities/cstr_utils.hpp>


///////////////////////////
//////// UTF8Char /////////
///////////////////////////
UTF8Char::UTF8Char() {
    this->c_str = "";
    this->csize = 0;
}
UTF8Char::UTF8Char(u1 *bytes) {
    int size = size_of_utf8Char(*bytes);
    if(bytes[size - 1] == '\0') {
        // that's a str not character
        // just to copy characters ahead of '\0'
        this->c_str = (char *) Memory::alloc_mem(size - 1);
        Memory::copy(bytes, (pointer) this->c_str, size - 1);
        this->csize = size - 1;
    } else {
        // A character without '\0'
        this->c_str = (char *) Memory::alloc_mem(size);
        Memory::copy(bytes, (pointer) this->c_str, size);
        this->csize = size;
    }
}
UTF8Char::UTF8Char(char ascii) {
    this->csize = 1;
    this->c_str = (char *) Memory::alloc_mem(1);
    Memory::set_mem((pointer) this->c_str, ascii, 1);
}
UTF8Char::~UTF8Char() {
    Memory::free_mem(this->c_str);
}
char *UTF8Char::get_cstr() {
    return this->c_str;
}

int UTF8Char::cstr_size_of(UTF8Char *cs, int length) {
    int size = 0;
    for(int i = 0; i<length; i++){
        size += cs[i].csize;
    }
    return size + 1; // +1 for '\0'
}
char *UTF8Char::cstr_of(UTF8Char *cs, int length) {
    char *res = (char *) Memory::alloc_mem(cstr_size_of(cs, length));

    // do the same as strcpy ( like strcpy(cs, res) )
    UTF8Char * tmp_char;
    int current_idx = 0;
    for(int i = 0; i < length; i++) {
        tmp_char = &cs[i];
        Memory::copy((pointer) tmp_char->c_str,
                     (pointer) (res+current_idx),
                     tmp_char->csize);
        current_idx += tmp_char->csize;
        // e.g.
        // i=0, cs->csize = 2
        // looks like:
        //      mov (c string of tmp char) -> (top addr of res)
        //      current_idx += 2 (now is 2)
        // i=1, cs->csize = 3
        //      mov (c string of tmp char) -> (3rd (current_idx + 1) addr of res)
        //      current_idx += 3 (now is 5)
        // etc.
    }

    return res;
}
int UTF8Char::length_of_utf8String(char *cstr) {
    int res = 0;
    char c = *cstr;
    for(int i = 0; c != '\0';) {
        i += size_of_utf8Char(c);
        res ++;
        c = cstr[i];
    }
    return res;
}
int UTF8Char::size_of_utf8Char(u1 c) {
    if (c <= 0x7F) {                      // ASCII takes 1 bytes
        return  1;
    } else if (c >= 0xC0 && c <= 0xDF) {  // UTF-8 takes 2 bytes
        return  2;
    } else if (c >= 0xE0 && c <= 0xEF) {  // UTF-8 takes 3 bytes
        return  3;
    } else if (c >= 0xF0 && c <= 0xF7) {  // UTF-8 takes 4 bytes
        return  4;
    } else if (c >= 0xF8 && c <= 0xFB) {  // UTF-8 takes 5 bytes
        return  5;
    } else if (c >= 0xFC && c <= 0xFD) {  // UTF-8 takes 6 bytes
        return  6;
    } else if (c > 0x7F && c < 0xC0 ) {   // then is isn't first byte of utf-8
        return -1;
    } else {
        return -2;
    }
}
UTF8Char *UTF8Char::utf8Chars_of(char *cstr) {
    int count = UTF8Char::length_of_utf8String(cstr);
    UTF8Char *res = Memory::alloc_mem<UTF8Char>(count);
    int idx_of_res = 0;
    char * current_addr = cstr;
    do {
        res[idx_of_res] = UTF8Char((u1 *) current_addr);
        idx_of_res ++;
        current_addr = next_utf8Char(current_addr);
    } while(idx_of_res < count);

    return res;
}
char *UTF8Char::next_utf8Char(char *cstr) {
    return cstr + size_of_utf8Char(*cstr);
}


/////////////////////////
/////// U8String ////////
/////////////////////////
U8String::U8String() {
    this->length = 0;
    this->_so_chars = 0;
    this->_chars = NULL;
}
U8String::U8String(const char* chars) {
    this->_chars = (char *) malloc(
            CSTRUtil::len((char *) (chars))
            );
//  this->_chars = chars;
    CSTRUtil::copy(this->_chars, (char *) chars);
    this->_so_chars = CSTRUtil::len((char *) chars);
    this->length = UTF8Char::length_of_utf8String((char *) chars);
}
U8String::U8String(char *chars, int length) {
    if (chars[length - 1] == '\0') { // str end with '\0'
        this->_chars = (char *) Memory::alloc_mem(length);
        //  this->_chars = chars;
        CSTRUtil::copy(this->_chars, chars);
        this->_so_chars = length;
        this->length = UTF8Char::length_of_utf8String(chars);
    } else {                         // string is without '\0'
        this->_chars = (char *) Memory::alloc_mem(length + 1);
        Memory::copy((pointer) chars, (pointer) this->_chars, length);
        this->_chars[length] = 0;
        this->_so_chars = length + 1; // +1 cuz '\0'
        this->length = UTF8Char::length_of_utf8String(this->_chars);
    }

}
U8String::U8String(UTF8Char *chars, int length) {
    this->_so_chars = UTF8Char::cstr_size_of(chars, length);
    this->_chars = UTF8Char::cstr_of(chars, length);
    this->length = length;
}
bool U8String::isEmpty() {
    return this->_chars == NULL  ||
           cstr_EQUAL(this->_chars, "") || // this->_chars == ""
           this->length    == 0  ||
           this->_so_chars == 0;
}
U8String *U8String::join(U8String *str) {
    this->length += str->length;
    this->_so_chars += (str->_so_chars - 1); // -1 cuz _so_chars contains the '\0'

    char *new_chars = CSTRUtil::cat(this->_chars, str->_chars);
    if(_chars != NULL) {
        Memory::free_mem(_chars);
    }
    this->_chars = new_chars;

    return this;
}
char * U8String::get_utf8_char_at(int index) {
    char *cur = this->_chars;
    for(int i = 0; i < index; i++) {
        cur += UTF8Char::size_of_utf8Char(*cur);
    }
    int cs = UTF8Char::size_of_utf8Char(*cur);
    char *res = (char *) Memory::alloc_mem(cs);
    Memory::copy((pointer) cur, (pointer) res, cs);
    *(res+cs) = '\0'; // add '\0' to the end
    return res;
}
char *U8String::get_cstr() {
    char *res = Memory::alloc_mem<char>(this->_so_chars);
    CSTRUtil::copy(res, _chars);
    return res;
}
