//
// Created by XDomHatter on 2023-10-01.
//

#include "teaValue.hpp"
#include "heap.hpp"
#include <utilities/macros.hpp>
#include <utilities/cstr_utils.hpp>

TeaValue TeaValue::create_by_str(char *value, TeaHeap *heap) {
    TeaValue res{};
    res.t = TType_STR;

    // copy string
    char *n_str = Memory::alloc_mem<char>(CSTRUtil::len(value));
    CSTRUtil::copy(n_str, value);
    var str_obj = new InstanceString(n_str);
    // No need to free n_str, it will be free in destructor of InstanceString
    res.v.str_v = heap->add_object(str_obj);

    return res;
}

TeaValue TeaValue::create_by_u1(u1 value) {
    TeaValue res{};
    res.t = TType_N1;
    res.v.n1_v = value;
    return res;
}
TeaValue TeaValue::create_by_u2(u2 value) {
    TeaValue res{};
    res.t = TType_N2;
    res.v.n2_v = value;
    return res;
}
TeaValue TeaValue::create_by_u4(u4 value) {
    TeaValue res{};
    res.t = TType_N4;
    res.v.n4_v = value;
    return res;
}
TeaValue TeaValue::create_by_u8(u8 value) {
    TeaValue res{};
    res.t = TType_N8;
    res.v.n8_v = value;
    return res;
}
TeaValue TeaValue::create_by_oop(InstanceOOP *oop, TeaHeap *heap) {
    u4 idx = heap->add_object(oop);
    TeaValue res{};
    res.t = TType_OOP;
    res.v.oop_v = idx;
    return res;
}