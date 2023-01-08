//
// Created by Administrator on 2022-12-26.
//
#ifndef TVM_1_0_BYTES_HPP
#define TVM_1_0_BYTES_HPP

//	BASIC TYPES
typedef unsigned char  u1;
typedef unsigned short u2;
typedef unsigned int   u4;

typedef signed char  s1;
typedef signed short s2;
typedef signed int   s4;
//u8,s8 is indefinitely

typedef void * address;

u2 wrap_u2(u2 data) {
    return (u2)((data << 8) + (data >> 8));
}


#endif //TVM_1_0_BYTES_HPP
