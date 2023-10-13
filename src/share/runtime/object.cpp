//
// Created by XDomHatter on 2023-10-02.
//

#include "object.hpp"

Interface::Interface(int abs_func_count, METHOD_FUNCTION_Constant **abstract_funcs) {
    this->abs_func_count = abs_func_count;
    this->abstract_funcs = abstract_funcs;
}

Klass::Klass(
    U8String *name,
    u1 access_flags,
    Klass *parent,
    u2 interface_count,
    Interface **interfaces,
    u2 field_count,
    Klass::FieldInfo **field_infos,
    u2 method_count,
    TFunction **methods
) {
    this->name = name;
    this->access_flags = access_flags;
    this->parent = parent;
    this->interface_count = interface_count;
    this->interfaces = interfaces;
    this->field_count = field_count;
    this->field_infos = field_infos;
    this->method_count = method_count;
    this->methods = methods;
}

Klass *Klass::utf8_klass = new Klass(
    new U8String("U"),
    Klass::AccessFlags::PUBLIC,
    NULL,
    0,
    NULL,
    0,
    NULL,
    0,
    NULL
);

InstanceOOP::InstanceOOP(Klass *cls) {
    this->cls = cls;
}

InstanceArray::InstanceArray(Klass *cls, int dimension, const int *size_in_each_dim, InstanceOOP **values)
    : InstanceOOP(cls) {
    this->dimension = dimension;
//  this->size_in_each_dim = size_in_each_dim :
        this->size_in_each_dim = Memory::alloc_mem<int>(dimension);
        for (int i = 0; i < dimension; i++) {
            this->size_in_each_dim[i] = size_in_each_dim[i];
        }

    this->total_size = size_in_each_dim[0];
    for (int i = 1; i < dimension; i++) {
        total_size *= size_in_each_dim[i];
    }
    this->values = values;
}
InstanceOOP *InstanceArray::get_element_by_index(int index) {
    if(index >= this->total_size) {
        // out of bounds
        TConsole::output_f("tea.base.OutOfBoundsException: index %d out of bounds %d\n",
                           index, this->total_size);
        QUIT(-1);
    }
    return values[index];
}

InstanceString::InstanceString(const InstanceString &other) noexcept:
    InstanceOOP(Klass::utf8_klass) {
    this->str = other.str;
}
InstanceString::InstanceString(char *str):
    InstanceOOP(Klass::utf8_klass) {
    this->str = Memory::alloc_mem<char>(CSTRUtil::len(str));
    CSTRUtil::copy(this->str, str);
}
char *InstanceString::get_cstr() {
    char *res = Memory::alloc_mem<char>(CSTRUtil::len(str));
    CSTRUtil::copy(res, str);
    return res;
}
