//
// Created by Administrator on 2023-07-26.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_OPCODE_HPP
#define $TEA_SRC_SHARE_RUNTIME_OPCODE_HPP

#include <asm/BytesUtils.hpp>

class OpCodeSet {
    u4 code_size;
    u1 *codes;
public:
    OpCodeSet(u4 code_size, u1 *codes) : code_size(code_size), codes(codes) {}
};

#endif //$TEA_SRC_SHARE_RUNTIME_OPCODE_HPP
