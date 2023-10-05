//
// Created by Administrator on 2023-07-26.
//

#include "teaFunction.hpp"
#include <oop/binary_name.hpp>

TFunction::TFunction(
    METHOD_FUNCTION_Constant *info,
    u1 acc_flag,
    u2 lv_slot_count,
    TExceptionHandlerSet *exception_handlers,
    u1 max_stack_size,
    tuint opcode_size,
    u1 *opcodes
) {
    this->info               = info;
    this->acc_flag           = acc_flag;
    this->lv_slot_count      = lv_slot_count;
    this->exception_handlers = exception_handlers;
    this->max_stack_size     = max_stack_size;
    this->opcode_size        = opcode_size;
//  this->opcodes            = opcodes;
    this->opcodes            = Memory::alloc_mem<u1>(opcode_size);
    Memory::copy(opcodes, this->opcodes, opcode_size);
    this->argc = compute_arg_count(info);
}
tuint TFunction::compute_arg_count(METHOD_FUNCTION_Constant *info) {
    char *cst = info->param_types->get_cstr();
    tuint res = BinaryName::count(cst);
    return res;
}
