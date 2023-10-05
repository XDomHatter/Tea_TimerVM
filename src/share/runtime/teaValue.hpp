//
// Created by XDomHatter on 2023-10-01.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_TEAVALUE_HPP
#define $TEA_SRC_SHARE_RUNTIME_TEAVALUE_HPP

#include "heap.hpp"
#include <utilities/types.hpp>
#include <runtime/object.hpp>

class TeaValue {
    TeaType t{};
    union {
        u4 str_v; // heap index of InstanceString object
        u1 n1_v;
        u2 n2_v;
        u4 n4_v;
        u8 n8_v;
        u4 oop_v; // heap index of InstanceOOP object
        u4 arr_v; // heap index of InstanceArray object
    } v{};
public:
    TeaValue()= default;

    /// Create a str value in Tea
    /// @param value C string value
    static TeaValue create_by_str(char *value, TeaHeap *heap);
    /// Create u1 value in Tea
    static TeaValue create_by_u1(u1 value);
    /// Create u2 value in Tea
    static TeaValue create_by_u2(u2 value);
    /// Create u4 value in Tea
    static TeaValue create_by_u4(u4 value);
    /// Create u8 value in Tea
    static TeaValue create_by_u8(u8 value);
    /// Create oop value in Tea
    static TeaValue create_by_oop(InstanceOOP *oop, TeaHeap *heap);


    inline u4 get_str_index() const {
        return v.str_v;
    }
    inline u1 get_n1_value() const {
        return v.n1_v;
    }
    inline u2 get_n2_value() const {
        return v.n2_v;
    }
    inline u4 get_n4_value() const {
        return v.n4_v;
    }
    inline u8 get_n8_value() const {
        return v.n8_v;
    }
    inline u4 get_oop_index() const {
        return v.oop_v;
    }
};

#endif //$TEA_SRC_SHARE_RUNTIME_TEAVALUE_HPP
