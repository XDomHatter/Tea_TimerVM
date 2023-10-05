//
// Created by XDomHatter on 2023-08-07.
//

#include "opCode.hpp"

const u1 OpCodeSet::taken_size[] = {
    1, // NOP
    1, // ICONST_M1
    1, // ICONST_0
};
const OpCodeFunc OpCodeSet::code_func[] = {
    OpCodeFunctions_::NOP,
    OpCodeFunctions_::ICONST_M1,
    OpCodeFunctions_::ICONST_0,
};

namespace OpCodeFunctions_ {
    void NOP(OPCODE_FUNC_PARAM) {
        // No operation, do nothing.
    }
    void ICONST_M1(OPCODE_FUNC_PARAM) {
        env->stack->push1(-1);
    }
    void ICONST_0(OPCODE_FUNC_PARAM) {
        env->stack->push1(0);
    }
}
