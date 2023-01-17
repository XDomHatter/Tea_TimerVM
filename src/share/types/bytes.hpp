#pragma once

#ifndef $TVM_SRC_SHARE_TYPES_BYTE_HPP
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

//u4 make_u4(u1 src[4]) {
//    u4 o1,o2,o3,o4;
//    o1 = src[0];
//    o2 = src[1];
//    o3 = src[2];
//    o4 = src[3];
//    return (
//            (o1 << 24) +
//            (o2 << 16) +
//            (o3 << 8 ) +
//            (o4      )
//    );
//}

#endif //$TVM_SRC_SHARE_TYPES_BYTE_HPP
