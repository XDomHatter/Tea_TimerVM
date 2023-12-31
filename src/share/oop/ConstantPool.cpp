//
// Created by Administrator on 2023-03-27.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#include "ConstantPool.hpp"
#include <asm/Memory.hpp>
#include <utilities/Tio.hpp>
#include <exception>

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
    Constant * temp_c = NULL;
    bool flag = false; // if the constant inited failed
    int failed_init_count = 0; // count of constants which init failed

    /** NETHOD_FUNCTION_Constant, CLASS_Constant, MERGE_UTF8_Constant and TYPE_AND_NAME_Constant needs to be init again.
        They refer other constants. And the referred constants may not be read. And also,
        when the referred constant is MERGE_UTF8_Constant, it maybe hasn't inited.
        A simple example, C0(TYPE_AND_NAME_Constant) refers C1(MERGE_UTF8_Constant),
        initializing it will be failed. So we should verify if there's a failed initializing and init again.
    */

    // verify if index is able to get
    auto verify = [this](int i,u2 idx) -> bool {
        if(idx <  i) return true; // constant are inited
        // if constants is merge-utf8-constant, is hasn't been inited
        var * verify_c = this->get_constant<Constant>(idx);
        if(verify_c->type == CT_MERGE_UTF8_CONSTANT) {
            if(verify_c->status == CTSINITED)
                return true;
        }
        return false;
    };
    // update the environment status(flag, failed_init_count and constant's status)
    auto update_status = [&flag, &failed_init_count](Constant *c) {
        if(!flag) {
            // constant init successfully
            if (c->status == CTSFAILED) failed_init_count--;
            c->status = CTSINITED;
        } else {
            c->status = CTSFAILED;
            failed_init_count ++;
        }
        flag = false;
    };

    do { // init constant
        for (int i = 1; i <= this->count; i++) {
            temp_c = get_constant_fast<Constant>(i);
            if (temp_c->status == CTSINITED) continue; // constant has been inited.
            switch (temp_c->type) {
                case CT_METHOD_FUNCTION_CONSTANT: {
                    var *mf_c = (METHOD_FUNCTION_Constant *) temp_c;
                    // UTF8_Constant inits itself when create it,
                    // don't need to verify if the constant is inited.
                    // AND don't need to delete.

                    // If package index is 0, the method/func is member of current file
                    // And i always >= 0, so don't have to check particular case

                    if (verify(i, mf_c->name_idx) &&
                        verify(i, mf_c->prmt_idx) &&
                        verify(i, mf_c->rslt_idx) &&
                        verify(i, mf_c->pkg_idx)
                        ) {
                        mf_c->name        = get_constant<UTF8_Constant>(mf_c->name_idx);
                        mf_c->param_types = get_constant<UTF8_Constant>(mf_c->prmt_idx);
                        mf_c->result_type = get_constant<UTF8_Constant>(mf_c->rslt_idx);
                        mf_c->pkg_cst     = (
                            (mf_c->pkg_idx == 0) ?
                            NULL : get_constant<UTF8_Constant>(mf_c->pkg_idx)
                        );
                    } else {
                        // constant has not been inited.
                        // set the flag to true to mark it.
                        flag = true;
                    }
                    break;
                }
                case CT_CLASS_CONSTANT: {
                    var cl_c = (CLASS_Constant *)temp_c;
                    if(verify(i, cl_c->name_idx) && verify(i, cl_c->pkg_idx)) {
                        cl_c->name_cst = get_constant<UTF8_Constant>(cl_c->name_idx);
                        cl_c->pkg_cst = (
                            (cl_c->pkg_idx == 0) ?
                            NULL : get_constant<UTF8_Constant>(cl_c->pkg_idx)
                        );
                    } else {
                        flag = true;
                    }
                    break;
                }
                case CT_MERGE_UTF8_CONSTANT: {
                    var *mu_c = (MERGE_UTF8_Constant *) temp_c;
                    var r = new U8String();
                    int soc = 0;
                    UTF8_Constant *temp;
                    for (int j = 0; j < mu_c->members_count; j++) {
                        // traversal indexes, get constant, concat
                        if (verify(i, mu_c->members_idxs[j])) {
                            temp = get_constant_fast<UTF8_Constant>(mu_c->members_idxs[j]);
                            r->join(temp->val);
                            soc += temp->val->_so_chars;
                        } else {
                            // cannot be inited successfully
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) { // init successfully
                        mu_c->val = r;
                        mu_c->size = soc;
                    }
                    delete r;
                    break;
                }
                case CT_TYPE_AND_NAME_CONSTANT: {
                    var *tan_c = (TYPE_AND_NAME_Constant *) temp_c;
                    if (verify(i, tan_c->name_idx) && verify(i, tan_c->type_idx)) {
                        tan_c->name_utf8 = get_constant_fast<UTF8_Constant>(tan_c->name_idx);
                        tan_c->type_utf8 = get_constant_fast<UTF8_Constant>(tan_c->type_idx);
                    } else {
                        // cannot be inited successfully
                        flag = true;
                    }
                    break;
                }
                default:break;
            }
            update_status(temp_c); // update env
        }
    } while(failed_init_count > 0);
}
void ConstantPool::set_constant(u2 index, Constant *constant) {
    this->constants[index - 1] = constant;
}
