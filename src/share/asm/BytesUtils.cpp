//
// Created by Administrator on 2023-01-17.
//
#include "BytesUtils.hpp"
//#include <stdio.h>

u2 ByteUtils::make_u2(u1 src[2]) {
    return (u2)(
            (((u2)src[0]) << 8) +
            ((u2)src[1])
            );
}
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

// typedef
u8 ByteUtils::make_u8(u1 src[8]) {
    // e.g. src = { 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78, 0x89 }
    return (
            (((u8)(src[0])) << 56) + // 0x12 << ( 7*8 ) = 0x1200000000000000
            (((u8)(src[1])) << 48) + // 0x23 << ( 6*8 ) = 0x0023000000000000
            (((u8)(src[2])) << 40) + // 0x34 << ( 5*8 ) = 0x0000340000000000
            (((u8)(src[3])) << 32) + // 0x45 << ( 4*8 ) = 0x0000004500000000
            (((u8)(src[4])) << 24) + // 0x56 << ( 3*8 ) = 0x0000000056000000
            (((u8)(src[5])) << 16) + // 0x67 << ( 2*8 ) = 0x0000000000670000
            (((u8)(src[6])) << 8 ) + // 0x78 << ( 2*8 ) = 0x0000000000007800
            (((u8)(src[7]))      )   // 0x89 << ( 2*8 ) = 0x0000000000000089
    );
}

u2 ByteUtils::wrap_u2(u2 obj) {
    // obj        = 1001 0011 1110 0111
    // 0x00FF     = 0000 0000 1111 1111
    // obj&0x00FF = 0000 0000 1110 0111

    // obj        = 1001 0011 1110 0111
    // 0xFF00     = 1111 1111 0000 0000
    // obj&0xFF00 = 1001 0011 0000 0000
    return (
            ((obj & 0x00FF) << 8) + ((obj & 0xFF00) >> 8)
    );
}
u4 ByteUtils::wrap_u4(u4 obj) {
    // e.g.
    // obj                   = 10000000 11000000 11100000 11110000
    //
    // o1 = obj & 0xFF000000 = 10000000 00000000 00000000 00000000
    // o2 = obj & 0x00FF0000 = 00000000 11000000 00000000 00000000
    // o3 = obj & 0x0000FF00 = 00000000 00000000 11100000 00000000
    // o4 = obj & 0x000000FF = 00000000 00000000 00000000 11110000

    return (
            ((obj & 0xFF000000) >> 24) + // o1 >> 24 = 00000000 00000000 00000000 10000000
            ((obj & 0x00FF0000) >> 8 ) + // o2 >> 8  = 00000000 00000000 11000000 00000000
            ((obj & 0x0000FF00) << 8 ) + // o3 << 8  = 00000000 11100000 00000000 00000000
            ((obj & 0x000000FF) << 24)   // o4 << 24 = 11110000 00000000 00000000 00000000
    );                                   // result   = 11110000 11100000 11000000 10000000
}
u8 ByteUtils::wrap_u8(u8 obj) {
    // e.g.
    // obj                           = 10000000 11000000 11100000 11110000 11111000 11111100 11111110 11111111
    //
    // o1 = obj & 0xFF00000000000000 = 10000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    // o2 = obj & 0x00FF000000000000 = 00000000 11000000 00000000 00000000 00000000 00000000 00000000 00000000
    // o3 = obj & 0x0000FF0000000000 = 00000000 00000000 11100000 00000000 00000000 00000000 00000000 00000000
    // o4 = obj & 0x000000FF00000000 = 00000000 00000000 00000000 11110000 00000000 00000000 00000000 00000000
    // o5 = obj & 0x00000000FF000000 = 00000000 00000000 00000000 00000000 11111000 00000000 00000000 00000000
    // o6 = obj & 0x0000000000FF0000 = 00000000 00000000 00000000 00000000 00000000 11111100 00000000 00000000
    // o7 = obj & 0x000000000000FF00 = 00000000 00000000 00000000 00000000 00000000 00000000 11111110 00000000
    // o8 = obj & 0x00000000000000FF = 00000000 00000000 00000000 00000000 00000000 00000000 00000000 11111111
    return (
            ((obj & 0xFF00000000000000) >> 56) + // o1 >> ( 7*8 ) = 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001
            ((obj & 0x00FF000000000000) >> 40) + // o2 >> ( 5*8 ) = 00000000 00000000 00000000 00000000 00000000 00000000 11000000 00000000
            ((obj & 0x0000FF0000000000) >> 24) + // o3 >> ( 3*8 ) = 00000000 00000000 00000000 00000000 00000000 11100000 00000000 00000000
            ((obj & 0x000000FF00000000) >> 8 ) + // o4 >> ( 1*8 ) = 00000000 00000000 00000000 00000000 11110000 00000000 00000000 00000000

            ((obj & 0x00000000FF000000) << 8 ) + // o5 << ( 1*8 ) = 00000000 00000000 00000000 11111000 00000000 00000000 00000000 00000000
            ((obj & 0x0000000000FF0000) << 24) + // o6 << ( 3*8 ) = 00000000 00000000 11111100 00000000 00000000 00000000 00000000 00000000
            ((obj & 0x000000000000FF00) << 40) + // o7 << ( 5*8 ) = 00000000 11111110 00000000 00000000 00000000 00000000 00000000 00000000
            ((obj & 0x00000000000000FF) << 56)   // o8 << ( 7*8 ) = 11111111 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    );                                           // result        = 11111111 11111110 11111100 11111000 11110000 11100000 11000000 10000000
}