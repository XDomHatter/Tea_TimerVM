//
// Created by Administrator on 2023-03-20.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#ifndef $TEA_SRC_SHARE_CODEFILE_CONSTANT_HPP
#define $TEA_SRC_SHARE_CODEFILE_CONSTANT_HPP

#include <asm/BytesUtils.hpp>
#include <structures/Utf8.hpp>
#include <codefile/TeaFileReader.hpp>
#include <utilities/STATUS.hpp>
#include <utilities/macros.hpp>
#include <utilities/cstr_utils.hpp>
#include <type_traits>
#include <memory>

typedef enum{
    CT_UTF8_CONSTANT            = 0x00,
    CT_METHOD_FUNCTION_CONSTANT = 0x01,
    CT_CLASS_CONSTANT           = 0x02,
    CT_MERGE_UTF8_CONSTANT      = 0x03,
    CT_TYPE_AND_NAME_CONSTANT   = 0x04,
} ConstantType;

class Constant {
public:
    ConstantType   type;
    ConstantStatus status;

    /// base constructor of all the constants
    Constant();
    static int size_in_cp(Constant * c);
    static Constant * convert_constant(u1 * value);

    template<class T> static bool check_type(Constant *c);
};

class UTF8_Constant : public Constant{
public:
    int size;
    U8String * val;

    /// init an empty UTF8 Constant with nothing, usually used in MERGE_UTF8_Constant
    UTF8_Constant();
    /// init UTF8 Constant with source bytes
    /// @param size Size of bytes
    /// @param value Free it by caller! Method only do copying!
    UTF8_Constant(u2 size, u1 * value);
    ~UTF8_Constant();

    /// concat param to end of self
    /// @param v Free it by caller! Method only do copying!
    UTF8_Constant *join(UTF8_Constant * v);
    char *get_cstr() const;
    bool equal(const UTF8_Constant& obj) const;
    /// BKDRHash algorithm
    size_t get_hashcode() const;
};

class METHOD_FUNCTION_Constant : public Constant{
public:
    u2 pkg_idx;
    UTF8_Constant *pkg_cst;
    u2 rslt_idx;
    UTF8_Constant * result_type;
    u2 name_idx;
    UTF8_Constant * name;
    u2 prmt_idx;
    UTF8_Constant * param_types;

    /// init the constant
    METHOD_FUNCTION_Constant(u2 package_index, u2 result_index, u2 name_index, u2 param_types_index);
    ~METHOD_FUNCTION_Constant();

    /// detect if this object is equal to param
    /// @param obj object to detect
    inline bool equal(const METHOD_FUNCTION_Constant& obj) const {
        return (
            result_type->equal(*obj.result_type) &&
            name       ->equal(*obj.name)        &&
            param_types->equal(*obj.param_types) &&
            (pkg_cst == NULL ?
                 obj.pkg_cst == NULL : pkg_cst->equal(*obj.pkg_cst)
            )
        );
    }
    /// get hash code of object
    inline size_t get_hashcode() const {
        char *bin_name = (char *) Memory::alloc_mem<char> (
            this->result_type->size +   // result type
            1 +                         // :
            this->name->size +          // name
            1 +                         // (
            this->param_types->size +   // param_types
            1 +                         // )
            1                           // '\0'
        );
        sprintf(bin_name, "%s:%s(%s)",
                this->result_type->get_cstr(),
                this->name->get_cstr(),
                this->param_types->get_cstr()
        );
        size_t res = CSTRUtil::get_hashcode(bin_name);
        Memory::free_mem(bin_name);
        return res;
    }

    inline bool operator<(const METHOD_FUNCTION_Constant& other) const {
        return this->get_hashcode() < other.get_hashcode();
    }
    inline bool operator==(const METHOD_FUNCTION_Constant& other) const {
        return this->equal(other);
    }
    static inline METHOD_FUNCTION_Constant main_func_cst() {
        var main_func_cst = METHOD_FUNCTION_Constant(0, 0, 0, 0);
        main_func_cst.status = CTSINITED; // set status
        main_func_cst.pkg_idx     = 0;
        main_func_cst.pkg_cst     = NULL;
        main_func_cst.result_type = new UTF8_Constant(2, (u1 *) "4"   );
        main_func_cst.name        = new UTF8_Constant(5, (u1 *) "main");
        main_func_cst.param_types = new UTF8_Constant(3, (u1 *) "[U"  );
        return main_func_cst;
    }
};

class CLASS_Constant : public Constant {
public:
    u2 pkg_idx;
    UTF8_Constant *pkg_cst;
    u2 name_idx;
    UTF8_Constant *name_cst;
    
    /// init the constant
    CLASS_Constant(u2 pakg_idx, u2 name_idx);
    inline bool equal(CLASS_Constant *obj) const {
        return
            name_cst->equal(*obj->name_cst) &&
            pkg_cst->equal(*obj->pkg_cst);
    }
};

class MERGE_UTF8_Constant : public UTF8_Constant {
public:
    u2 members_count;
    u2 * members_idxs;
    int size;

    /// init the constant
    MERGE_UTF8_Constant(u2 members_count, u2 * members_idxs);
    ~MERGE_UTF8_Constant();
};

class TYPE_AND_NAME_Constant : public Constant {
public:
    u2 type_idx;
    UTF8_Constant * type_utf8;
    u2 name_idx;
    UTF8_Constant * name_utf8;

    TYPE_AND_NAME_Constant(u2 type_idx, u2 name_idx);

    inline size_t get_hashcode() const {
        char *binn = (char *) Memory::alloc_mem(
            name_utf8->size +    // name
            1 +                  // :
            type_utf8->size +    // type
            1                    // '\0'
        );
        sprintf(binn, "%s:%s", name_utf8->get_cstr(), type_utf8->get_cstr());
        return CSTRUtil::get_hashcode(binn);
    }
    inline bool equal(const TYPE_AND_NAME_Constant &other) const {
        return (
            type_utf8->equal(*other.type_utf8) &&
            name_utf8->equal(*other.name_utf8)
        );
    }
    inline bool operator<(const TYPE_AND_NAME_Constant& other) const {
        return this->get_hashcode() < other.get_hashcode();
    }
    inline bool operator==(const TYPE_AND_NAME_Constant& other) const {
        return this->equal(other);
    }
};



template<class T>
bool Constant::check_type(Constant *c) {
    if(!std::is_base_of<Constant, T>::value) {
        // isn't a constant class
        return false;
    }
    if(std::is_same<typename std::decay<T>::type, Constant>::value) {
        return true;
    } else if(std::is_same<typename std::decay<T>::type, UTF8_Constant>         ::value) {
        // utf-8 constant or merge-utf8 constant
        return c->type == CT_UTF8_CONSTANT || c->type == CT_MERGE_UTF8_CONSTANT;
    }
    else if(std::is_same<typename std::decay<T>::type, METHOD_FUNCTION_Constant>::value) {
        // method_function constant
        return c->type == CT_METHOD_FUNCTION_CONSTANT;
    }
    else if(std::is_same<typename std::decay<T>::type, CLASS_Constant>          ::value) {
        // class constant
        return c->type == CT_CLASS_CONSTANT;
    }
    else if(std::is_same<typename std::decay<T>::type, MERGE_UTF8_Constant>     ::value) {
        // merge utf8 constant
        return c->type == CT_MERGE_UTF8_CONSTANT;
    }
    else if(std::is_same<typename std::decay<T>::type, TYPE_AND_NAME_Constant>  ::value) {
        // type and name constant
        return c->type == CT_TYPE_AND_NAME_CONSTANT;
    }
    else {
        // unknown constant class
        return false;
    }
}
#endif //$TEA_SRC_SHARE_CODEFILE_CONSTANT_HPP
