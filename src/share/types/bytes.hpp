//
// Created by Administrator on 2022-12-26.
//
#ifndef TVM_1_0_BYTES_HPP
#define TVM_1_0_BYTES_HPP

//	BASIC TYPES
#define u1 char
#define u2 short
#define u4 int
//u8 is indefinitely

#define address void *

u2 wrap_u2(u2 data) {
    return (u2)((data << 8) + (data >> 8));
}

#define boolean bool

#endif //TVM_1_0_BYTES_HPP
