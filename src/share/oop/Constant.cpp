//
// Created by Administrator on 2023-03-20.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#include "Constant.hpp"
#include <type_traits>
#include <utilities/cstr_utils.hpp>
#include <utilities/Tio.hpp>

//////////////////////////////////////
///////////// Constant ///////////////
//////////////////////////////////////
Constant::Constant(EENDIAN e) : e(e) {

    this->status = CTSNEW;
}
Constant *Constant::convert_constant(u1 *bytes, EDPARAM) {
    Constant * res;
    u1 tag = ByteUtils::u1_of(bytes, 0); // the first byte is type tag
    u1 *value = bytes + 1; // bytes after tag0
    switch (tag) {
        case CT_UTF8_CONSTANT:
            res = new UTF8_Constant(ByteUtils::u2_of(value, 0, e),
                    value + 2, e);
            break;
        case CT_METHOD_FUNCTION_CONSTANT:
            res = new METHOD_FUNCTION_Constant(
                    ByteUtils::u2_of(value, 0, e),
                    ByteUtils::u2_of(value, 2, e),
                    ByteUtils::u2_of(value, 4, e),
                    e
            );
            break;
        case CT_CLASS_CONSTANT:
            res = NULL; // CLASS_Constant is disabled
            break;
        case CT_MERGE_UTF8_CONSTANT: {
            u2 ccount       = ByteUtils::u2_of(value, 0, e);
            u2 *member_idxs = (u2 *) Memory::alloc_mem(ccount * 2);

            for (int i = 0; i < ccount; i++) {
                member_idxs[i] = ByteUtils::u2_of(value, i*2 + 2, e);
                // i*2 cuz every index takes 2 bytes, but the step size is 1
                // it runs like:
                // i = 0, i*2 + 2 = 2
                // i = 1, i*2 + 2 = 4
                // i = 2, i*2 + 2 = 6
                // ...
            }
            res = new MERGE_UTF8_Constant(ccount, member_idxs, e);

            Memory::free_mem(member_idxs);
            // free array cuz it has been copied(not directly use) in constructor

            break;
        }
        case CT_TYPE_AND_NAME_CONSTANT:
            res = new TYPE_AND_NAME_Constant(
                    ByteUtils::u2_of(value, 0, e),
                    ByteUtils::u2_of(value, 2, e),
                    e
            );
            break;
        default:
            // unknown type tag
            return NULL;
    }
    return res;
}
int Constant::size_in_cp(Constant * c) {
    int struct_size = 0;
    switch(c->type){
        case CT_UTF8_CONSTANT:
            struct_size = ((UTF8_Constant *)c)->size + 2;
            break;
        case CT_METHOD_FUNCTION_CONSTANT:
            struct_size = 6;
            break;
        case CT_CLASS_CONSTANT:
            struct_size = 0; // CLASS_Constant is disabled
            break;
        case CT_MERGE_UTF8_CONSTANT:
            struct_size = (2 +
                    ((MERGE_UTF8_Constant *)c)->members_count * 2
            );
            break;
        case CT_TYPE_AND_NAME_CONSTANT:
            struct_size = 4;
            break;
    }
    return struct_size + 1; // cuz of the tag takes 1 byte
}


//////////////////////////////////////
/////////// UTF8_Constant ////////////
//////////////////////////////////////
UTF8_Constant::UTF8_Constant(EDPARAM) : Constant(e) {
    this->type = CT_UTF8_CONSTANT;
    this->size = 0;
    this->val = new U8String();
}
UTF8_Constant::UTF8_Constant(u2 size, u1 *value, EDPARAM) : Constant(e) {
    this->type = CT_UTF8_CONSTANT;
    this->size = size;
    this->val = new U8String((char *)value, size);
}
UTF8_Constant::~UTF8_Constant() {
    delete this->val;
}
char *UTF8_Constant::get_cstr() const{
    return this->val->get_cstr();
}
UTF8_Constant *UTF8_Constant::join(UTF8_Constant *v) {
    this->val->join(v->val);
    this->size += v->size;
    return this;
}
bool UTF8_Constant::equal(const UTF8_Constant& obj) const{
    return cstr_EQUAL((char *) obj.val, (char *) this->val);
}


/////////////////////////////////////////
//////// METHOD_FUNCTION_Constant ///////
/////////////////////////////////////////
METHOD_FUNCTION_Constant::METHOD_FUNCTION_Constant(
            u2 result_index, u2 name_index, u2 param_types_index, EDPARAM
        ) : Constant(e){
    this->type   = CT_METHOD_FUNCTION_CONSTANT;

    this->rslt_idx = result_index;
    this->name_idx = name_index;
    this->prmt_idx = param_types_index;

    // now we don't have handle of constant pool, so the real UTF8_Constant objects will be
    // inited in ConstantPool::InitConstants in the last stage of constants-handle
    // now the constant only have indexes
    this->result_type = NULL;
    this->name        = NULL;
    this->param_types = NULL;
}
METHOD_FUNCTION_Constant::~METHOD_FUNCTION_Constant() {
    delete this->name;
    delete this->result_type;
}
u1 METHOD_FUNCTION_Constant::equal(METHOD_FUNCTION_Constant obj) const{
    if(!this->name->equal(*obj.name)){
        return CTES_NoE;
    } else {
        if (this->name->equal(*obj.name) &&
            this->param_types->equal(*obj.param_types) &&
            this->result_type->equal(*obj.result_type)) {
            return CTES_EQl; // completely equal
        }
        if (this->name->equal(*obj.name) &&
            this->param_types->equal(*obj.param_types)) {
            return CTES_NPE; // only result type isn't equal
        }
        if (this->name->equal(*obj.name) &&
            this->result_type->equal(*obj.result_type)) {
            return CTES_NRE; // param types isn't equal
        }
        if (this->name->equal(*obj.name)) {
            return CTES_NaE; // only name is equal
        }
    }
    return CTES_NoE;
}


/////////////////////////////////////////
/////// MERGE_UTF8_Constant /////////////
/////////////////////////////////////////
MERGE_UTF8_Constant::MERGE_UTF8_Constant(
            u2 members_count, u2 *members_idxs, EDPARAM
        ) : UTF8_Constant(e){
    this->type          = CT_MERGE_UTF8_CONSTANT;
    this->members_count = members_count;
    this->members_idxs  = (u2 *) Memory::alloc_mem(members_count * 2);
    Memory::copy((pointer) members_idxs,
            (pointer) this->members_idxs,
            members_count * 2);


    // constants will be loaded and merged in ConstantPool::init_constant
    this->size          = 0;
    this->val           = NULL;
}
MERGE_UTF8_Constant::~MERGE_UTF8_Constant() {
    Memory::free_mem(this->members_idxs);
}


/////////////////////////////////////////
/////// TYPE_AND_NAME_Constant //////////
/////////////////////////////////////////
TYPE_AND_NAME_Constant::TYPE_AND_NAME_Constant(
            u2 type_idx, u2 name_idx, EENDIAN e
        ) : Constant(e){
    this->type     = CT_TYPE_AND_NAME_CONSTANT;
    this->type_idx = type_idx;
    this->name_idx = name_idx;

    // constants will be loaded and merged in ConstantPool::init_constant
    this->type_utf8 = NULL;
    this->name_utf8 = NULL;
}
