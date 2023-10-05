//
// Created by XDomHatter on 2023-08-30.
//

#include "interpreter.hpp"
#include <runtime/opCode.hpp>
#include <oop/binary_name.hpp>

void Interpreter::interpret_func(TeaHeap *heap, TFunction *func, TeaValue *args) {
    var *ocs   = new OpCodeSet(func->opcode_size, func->opcodes);
    var *stack = new Stack_u4(func->max_stack_size);
    var *lv    = new TeaVariableSet(func->lv_slot_count);
    char *binn = func->info->param_types->get_cstr();
    for (int i = 0, lv_idx = 0; i < func->argc; i++) {
        TeaType bin_type = BinaryName::parse_binary_name(binn);
        TeaType_DO(bin_type,
            { // STR
                u4 str_idx = args[i].get_str_index();
                lv->set_u4(lv_idx, str_idx);
                lv_idx++;
            },
            { // N1
                u1 n1_value = args[i].get_n1_value();
                lv->set_u1(lv_idx, n1_value);
                lv_idx++;
            },
            { // N2
                u2 n2_value = args[i].get_n2_value();
                lv->set_u2(lv_idx, n2_value);
                lv_idx++;
            },
            { // N4
                u4 n4_value = args[i].get_n4_value();
                lv->set_u4(lv_idx, n4_value);
                lv_idx++;
            },
            { // N8
                u8 n8_value = args[i].get_n8_value();
                lv->set_u8(lv_idx, n8_value);
                lv_idx += 2; // u8 takes 2 slots
            },
            { // OOP
                u4 oop_idx = args[i].get_oop_index();
                lv->set_u4(lv_idx, oop_idx);
                lv_idx++;
            },
            { // ARR
                u4 arr_idx = args[i].get_oop_index();
                lv->set_u4(lv_idx, arr_idx);
                lv_idx++;
            },
            { // NULL
                u4 null_obj_idx = heap->get_null_obj_index();
                lv->set_u4(lv_idx, null_obj_idx);
                lv_idx++;
            }
        );
    }
    var *env = new EnvFrame(stack, lv);

    ocs->execute(env);
}
