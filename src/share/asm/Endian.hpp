//
// Created by Administrator on 2023-01-17.
//

#ifndef $TVM_SRC_SHARE_ASM_ENDIAN_HPP
#define $TVM_SRC_SHARE_ASM_ENDIAN_HPP

#include "types/BytesUtils.hpp"

#define LittleEndian 0
#define BigEndian    1

class Endian {
public:
    static u2 wrap_u2(u2 obj);
    static u4 wrap_u4(u4 obj);
};


#endif //$TVM_SRC_SHARE_ASM_ENDIAN_HPP
