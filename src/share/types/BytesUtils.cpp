//
// Created by Administrator on 2023-01-17.
//
#include "BytesUtils.hpp"
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