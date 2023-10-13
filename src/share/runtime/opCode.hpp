//
// Created by Administrator on 2023-07-26.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_OPCODE_HPP
#define $TEA_SRC_SHARE_RUNTIME_OPCODE_HPP

#include <asm/BytesUtils.hpp>
#include <structures/Stack.hpp>
#include <utilities/macros.hpp>
#include <utilities/Tio.hpp>
#include <runtime/teaVariable.hpp>
#include <runtime/heap.hpp>

#define OPCODE_FUNC_PARAM EnvFrame *env, u1 *param

struct EnvFrame{
    Stack *stack;
    TeaVariableSet *local_vars;
    TeaHeap *heap;
    int pc;
    EnvFrame(Stack *stack, TeaVariableSet *local_vars, TeaHeap *heap) :
        stack(stack), local_vars(local_vars), heap(heap), pc(0) {}
};

/// OPCode behaviour
/// @param env Environment
/// @param arg Params in bytecode
typedef void(*OpCodeFunc)(EnvFrame* env, u1* arg);

typedef enum{
    OP_NOP       = 0x00,
    OP_ICONST_M1 = 0x01,
    OP_ICONST_0  = 0x02,
} OpCode;

namespace OpCodeFunctions_ {
    void NOP(OPCODE_FUNC_PARAM);
    void ICONST_M1(OPCODE_FUNC_PARAM);
    void ICONST_0(OPCODE_FUNC_PARAM);
}

class OpCodeSet {
    u4 code_size;
    u1 *codes;
public:
    const static u1 taken_size[];
    const static OpCodeFunc code_func[];

    static inline void check_code(u1 code) {
        if (code > 0x02) {
            TConsole::output_f("tea.lang.ByteCodeError: Invalid code %x", code);
            QUIT(1);
        }
    }

    OpCodeSet(u4 code_size, u1 *codes): code_size(code_size), codes(codes) {}

    void execute(EnvFrame *env_frame) const {
        while (env_frame->pc < code_size) {
            var op = (OpCode) codes[env_frame->pc];
            check_code(op);
            code_func[op](env_frame, (codes + env_frame->pc + 1));
            env_frame->pc += taken_size[op];
        }
    }
};

#endif