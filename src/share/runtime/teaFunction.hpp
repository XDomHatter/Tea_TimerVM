//
// Created by Administrator on 2023-07-25.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_TEAFUNCTION_HPP
#define $TEA_SRC_SHARE_RUNTIME_TEAFUNCTION_HPP

#include <asm/BytesUtils.hpp>
#include <runtime/teaVariable.hpp>
#include <runtime/teaException.hpp>
#include <runtime/opCode.hpp>
#include <oop/Constant.hpp>
#include <structures/Stack.hpp>

class TFunction {
    METHOD_FUNCTION_Constant *info;
    u1                        acc_flag;
    TeaVariableSet           *local_vars;
    TExceptionHandlerSet     *exception_handlers;
    Stack                    *operand_stack;
    OpCodeSet                *opcode_set;
public:
    TFunction(
        METHOD_FUNCTION_Constant *info,
        u1 acc_flag,
        TeaVariableSet *local_vars,
        TExceptionHandlerSet *exception_handlers,
        u1 max_stack_size,
        int opcode_size,
        u1 *opcodes
    );
};

#endif //$TEA_SRC_SHARE_RUNTIME_TEAFUNCTION_HPP
