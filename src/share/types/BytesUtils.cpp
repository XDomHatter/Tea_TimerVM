//
// Created by Administrator on 2023-01-17.
//
#include "BytesUtils.hpp"

u4 ByteUtils::make_u4(u1 src[4]) {
    u4 o1,o2,o3,o4;
    o1 = src[0];
    o2 = src[1];
    o3 = src[2];
    o4 = src[3];
    return (
            (o1 << 24) +
            (o2 << 16) +
            (o3 << 8 ) +
            (o4      )
    );
}