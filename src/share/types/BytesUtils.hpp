#pragma once

#ifndef $TVM_SRC_SHARE_TYPES_BYTEUTILS_HPP
#define $TVM_SRC_SHARE_TYPES_BYTE_HPP

//	BASIC TYPES
typedef unsigned char  u1;
typedef unsigned short u2;
typedef unsigned int   u4;

typedef signed char  s1;
typedef signed short s2;
typedef signed int   s4;
//u8,s8 is indefinitely

typedef   u1 *     ptr;
typedef void * address;

class ByteUtils{
public:
    static u4 make_u4(u1 src[4]);
};


#endif //$TVM_SRC_SHARE_TYPES_BYTEUTILS_HPP
