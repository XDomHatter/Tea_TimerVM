//
// Created by Administrator on 2023-03-27.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#include "ConstantPool.hpp"
#include <asm/Memory.hpp>
#include <utilities/Tio.hpp>
#include <type_traits>

ConstantPool::ConstantPool(u2 size, u2 count) {
    this->size      = size;
    this->count     = count;
    this->constants = Memory::alloc_mem<Constant *>(count);
}
ConstantPool::~ConstantPool() {
    for(int i = 0;i<this->count;i++){
        delete this->constants[i];
    }
    Memory::free_mem(this->constants);
}

void ConstantPool::init_constant() {
    for (int i = 0; i < this->count; i++) {
        switch (get_constant_fast<Constant>(i+1)->type) {
            case CT_METHOD_FUNCTION_CONSTANT: {
                METHOD_FUNCTION_Constant *mf_c = (METHOD_FUNCTION_Constant *) constants[i];
                // UTF8_Constant inits itself when create it,
                // don't need to verify if the constant is inited.
                // AND don't need to delete.
                mf_c->name        = get_constant_fast<UTF8_Constant>(mf_c->name_idx);
                mf_c->param_types = get_constant_fast<UTF8_Constant>(mf_c->prmt_idx);
                mf_c->result_type = get_constant_fast<UTF8_Constant>(mf_c->rslt_idx);
                // -1 cuz index of constants start with 1, 0 means nothing
                break;
            }
            case CT_CLASS_CONSTANT: {
                TConsole::error("tvm.UnSupportedConstantError: CLASS_Constant is disabled");
                break;
            }
            case CT_MERGE_UTF8_CONSTANT: {
                MERGE_UTF8_Constant *mu_c = (MERGE_UTF8_Constant *) constants[i];
                U8String *r = new U8String(); // every Constant stores an endian
                int soc = 0;
                UTF8_Constant *temp;
                for (int j = 0; j < mu_c->members_count; j++) {
                    // traversal indexes, get constant, concat
                    temp = get_constant_fast<UTF8_Constant>(mu_c->members_idxs[j]);
                    r->join(temp->val);
                    soc += temp->val->_so_chars;
                }
                mu_c->val  = r;
                mu_c->size = soc;
                break;
            }
            case CT_TYPE_AND_NAME_CONSTANT: {
                TYPE_AND_NAME_Constant *tan_c = (TYPE_AND_NAME_Constant *) constants[i];
                tan_c->name_utf8 = get_constant_fast<UTF8_Constant>(tan_c->name_idx);
                tan_c->type_utf8 = get_constant_fast<UTF8_Constant>(tan_c->type_idx);
                break;
            }
            default:
                break;
        }
        constants[i]->status = CTSINITED;
    }
}
void ConstantPool::set_constant(u2 index, Constant *constant) {
    this->constants[index - 1] = constant;
}
template<class T> T * ConstantPool::get_constant(u2 index) {
    Constant *res = this->constants[index - 1];
    if(!Constant::check_type<T>(res)){
        return NULL;
    };
    return (T *) res;
}
