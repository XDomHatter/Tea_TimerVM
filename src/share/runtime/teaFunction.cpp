//
// Created by Administrator on 2023-07-26.
//

#include "teaFunction.hpp"

TFunction::TFunction(
    u1                        acc_flag,
    TeaVariableSet           *local_vars,
    TExceptionHandlerSet     *exception_handlers,
    u1                        max_stack_size,
    int                       opcode_size,
    u1                       *opcodes
) {
    this->acc_flag           = acc_flag;
    this->local_vars         = local_vars;
    this->exception_handlers = exception_handlers;
    this->operand_stack      = new Stack_u4(max_stack_size);
    this->opcode_set         = new OpCodeSet(opcode_size, opcodes);
}