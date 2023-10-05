//
// Created by Administrator on 2023-07-25.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_TEAFUNCTION_HPP
#define $TEA_SRC_SHARE_RUNTIME_TEAFUNCTION_HPP

#include <asm/BytesUtils.hpp>
#include <runtime/teaException.hpp>
#include <oop/Constant.hpp>
#include <utilities/types.hpp>

class TFunction {
    METHOD_FUNCTION_Constant *info;
    u1                        acc_flag;
    u2                        lv_slot_count;
    TExceptionHandlerSet     *exception_handlers;
    u1                        max_stack_size;
    tuint                     opcode_size;
    u1                       *opcodes;
    tuint                     argc;

    friend class Interpreter;
public:
    TFunction(
        METHOD_FUNCTION_Constant *info,
        u1 acc_flag,
        u2 lv_slot_count,
        TExceptionHandlerSet *exception_handlers,
        u1 max_stack_size,
        tuint opcode_size,
        u1 *opcodes
    );

    static tuint compute_arg_count(METHOD_FUNCTION_Constant *info);
};

#endif //$TEA_SRC_SHARE_RUNTIME_TEAFUNCTION_HPP
