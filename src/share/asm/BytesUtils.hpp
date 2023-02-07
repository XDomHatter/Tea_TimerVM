#pragma once

#ifndef $TVM_SRC_SHARE_TYPES_BYTEUTILS_HPP
#define $TVM_SRC_SHARE_TYPES_BYTE_HPP

//	BASIC TYPES
typedef unsigned char      u1;
typedef unsigned short     u2;
typedef unsigned int       u4;
typedef unsigned long long u8;

typedef signed char      s1;
typedef signed short     s2;
typedef signed int       s4;
typedef signed long long s8;

typedef   u1 *     ptr;
typedef void * address;



class ByteUtils{
public:
    static u2 make_u2(u1 src[2]);
    static u4 make_u4(u1 src[4]);
    static u8 make_u8(u1 src[8]);
    static u2 wrap_u2(u2 obj);
    static u4 wrap_u4(u4 obj);
    static u8 wrap_u8(u8 obj);
};


#endif //$TVM_SRC_SHARE_TYPES_BYTEUTILS_HPP
