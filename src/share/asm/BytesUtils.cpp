//
// Created by Administrator on 2023-01-17.
//
#include "asm/BytesUtils.hpp"
//#include <stdio.h>

u4 ByteUtils::make_u4(u1 src[4]) {
    u4 o1,o2,o3,o4;
    // for example, src = { 0x12, 0x34, 0x56, 0x78 }
    o1 = src[0]; // 0x00000012
//    printf("%x",o1);
    o2 = src[1]; // 0x00000034
//    printf("%x",o2);
    o3 = src[2]; // 0x00000056
//    printf("%x",o3);
    o4 = src[3]; // 0x00000078
//    printf("%x",o4);
    return (
            (o1 << 24) + // 0x00000012 << 24 = 0x12000000
            (o2 << 16) + // 0x00000034 << 16 = 0x00340000
            (o3 << 8 ) + // 0x00000056 << 8  = 0x00005600
            (o4      )   //                    0x00000078
    );
}

u2 ByteUtils::make_u2(u1 src[2]) {
    return (u2)(
            (((u2)src[0]) << 8) +
            ((u2)src[1])
            );
}

u2 ByteUtils::wrap_u2(u2 obj) {
    u2 o1, o2;
    //obj = 1001 0011 1110 0111
    //0xff= 0000 0000 1111 1111
    o1 = obj & 0x00FF; // get last byte of obj
    //obj    = 1001 0011 1110 0111
    //0xFF00 = 1111 1111 0000 0000
    o2 = obj & 0xFF00; // get first byte of obj
    return (o1 << 8) + (o2 >> 8);
}

u4 ByteUtils::wrap_u4(u4 obj) {
    u4 o1, o2, o3, o4;
    // e.g.
    // obj              = 10000000 11000000 11100000 11110000
    //
    // obj & 0xFF000000 = 10000000 00000000 00000000 00000000
    // obj & 0x00FF0000 = 00000000 11000000 00000000 00000000
    // obj & 0x0000FF00 = 00000000 00000000 11100000 00000000
    // obj & 0x000000FF = 00000000 00000000 00000000 11110000

    o1 = obj & 0xFF000000; // 1st byte
    o2 = obj & 0x00FF0000; // 2ed byte
    o3 = obj & 0x0000FF00; // 3rd byte
    o4 = obj & 0x000000FF; // 4th byte
    return (
            (o1 >> 24) + // o1 >> 24 = 00000000 00000000 00000000 10000000
            (o2 >> 8 ) + // o2 >> 8  = 00000000 00000000 11000000 00000000
            (o3 << 8 ) + // o3 << 8  = 00000000 11100000 00000000 00000000
            (o4 << 24)   // o4 << 24 = 11110000 00000000 00000000 00000000
    );           // result   = 11110000 11100000 11000000 10000000
}