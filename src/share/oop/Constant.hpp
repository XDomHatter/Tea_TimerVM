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

// 00000001(1) means complete equal
#define CTES_EQl 1
// 00000010(2) means only ::name is equal that obj is method/function 's override
#define CTES_NaE 2
// 00000100(4) means only result type isn't equal
#define CTES_NPE 4
// 00001000(8) means only param types are not equal
#define CTES_NRE 8
// 00010000(16) means complete not equal
#define CTES_NoE 16

#define CstTypePARAM ConstantType cst_type


typedef enum{
    CT_UTF8_CONSTANT            = 0x00,
    CT_METHOD_FUNCTION_CONSTANT = 0x01,
    CT_CLASS_CONSTANT           = 0x02,
    CT_MERGE_UTF8_CONSTANT      = 0x03,
    CT_TYPE_AND_NAME_CONSTANT   = 0x04,
} ConstantType;

class Constant {
public:
    EENDIAN e;
    ConstantType   type;
    ConstantStatus status;

    /// base constructor of all the constants
    Constant(EDPARAM);
    static int size_in_cp(Constant * c);
    static Constant * convert_constant(u1 * value, EDPARAM);

    template<class T> static bool check_type(Constant *c);
};

class UTF8_Constant : public Constant{
public:
    int size;
    U8String * val;

    /// init an empty UTF8 Constant with nothing, usually used in MERGE_UTF8_Constant
    UTF8_Constant(EDPARAM);
    /// init UTF8 Constant with source bytes
    /// @param size Size of bytes
    /// @param value Free it by caller! Method only do copying!
    UTF8_Constant(u2 size, u1 * value, EDPARAM);
    ~UTF8_Constant();

    /// concat param to end of self
    /// @param v Free it by caller! Method only do copying!
    UTF8_Constant *join(UTF8_Constant * v);
    char *get_cstr() const;
    bool equal(const UTF8_Constant& obj) const;
};

class METHOD_FUNCTION_Constant : public Constant{
public:
    u2 rslt_idx;
    UTF8_Constant * result_type;
    u2 name_idx;
    UTF8_Constant * name;
    u2 prmt_idx;
    UTF8_Constant * param_types;

    /// init the constant
    METHOD_FUNCTION_Constant(u2 result_index, u2 name_index, u2 param_types_index, EDPARAM);
    ~METHOD_FUNCTION_Constant();

    /// detect if this object is equal to param
    /// @param obj object to detect
    /// @return CTES_EQl/CTES_NaE/CTES_NPE/CTES_NoE
    u1 equal(METHOD_FUNCTION_Constant obj) const;
};

class MERGE_UTF8_Constant : public UTF8_Constant {
public:
    u2 members_count;
    u2 * members_idxs;
    int size;

    /// init the constant
    MERGE_UTF8_Constant(u2 members_count, u2 * members_idxs, EDPARAM);
    ~MERGE_UTF8_Constant();
};

class TYPE_AND_NAME_Constant : public Constant {
public:
    u2 type_idx;
    UTF8_Constant * type_utf8;
    u2 name_idx;
    UTF8_Constant * name_utf8;

    TYPE_AND_NAME_Constant(u2 type_idx, u2 name_idx, EDPARAM);
};

#endif //$TEA_SRC_SHARE_CODEFILE_CONSTANT_HPP