//
// Created by XDomHatter on 2023-10-02.
//

#ifndef $TEA_SRC_SHARE_OOP_OBJECT_HPP
#define $TEA_SRC_SHARE_OOP_OBJECT_HPP

#include <asm/Memory.hpp>
#include <oop/Constant.hpp>
#include <runtime/teaFunction.hpp>
#include <functional>

// Interface info
class Interface {
    int abs_func_count;
    METHOD_FUNCTION_Constant **abstract_funcs;
public:
    Interface(int abs_func_count, METHOD_FUNCTION_Constant **abstract_funcs);
};

// Class info
class Klass {
    U8String      *name;
    u1             access_flags;
    Klass         *parent;
    u2             interface_count;
    Interface    **interfaces;
    class FieldInfo {
        Klass *type;
        U8String *name;
    public:
        FieldInfo(Klass *type, U8String *name) : type(type), name(name) {}
    };
    u2             field_count;
    FieldInfo    **field_infos;
    u2             method_count;
    TFunction    **methods;

public:
    class AccessFlags {
    public:
        static constexpr int PUBLIC    = 0b00000001,
            PRIVATE   = 0b00000010,
            PROTECTED = 0b00000100,
            STATIC    = 0b00001000,
            CONST     = 0b00010000,
            NATIVE    = 0b00100000,
            GENERIC   = 0b01000000;
    };

    Klass(U8String      *name,
          u1             access_flags,
          Klass         *parent,
          u2             interface_count,
          Interface    **interfaces,
          u2             field_count,
          FieldInfo    **field_infos,
          u2             method_count,
          TFunction    **methods);

    static Klass *utf8_klass;
};


class InstanceOOP {
    Klass *cls;
public:
    InstanceOOP(Klass *cls);
};
class InstanceArray : public InstanceOOP {
    int dimension;
    int *size_in_each_dim;
    int total_size;
    InstanceOOP *values;
public:
    InstanceArray(Klass *cls, int dimension, const int *size_in_each_dim, InstanceOOP *values);

    template<typename DataType>
    static InstanceArray *package_values(
        DataType *data, int count, Klass *target_cls, std::function<InstanceOOP(DataType)> func
    ) {
        var *v = Memory::alloc_mem<InstanceOOP>(count);
        for(int i = 0; i < count; i++) {
            v[i] = func(data[i]);
        }
        return new InstanceArray(target_cls, 1, &count, v);
    }
};
class InstanceString : public InstanceOOP {
    char *str;
public:
    explicit InstanceString(char *str);
    ~InstanceString() {
//      super_destructor();   // auto call
        Memory::free_mem(str);
    }
};

#endif //$TEA_SRC_SHARE_OOP_OBJECT_HPP
