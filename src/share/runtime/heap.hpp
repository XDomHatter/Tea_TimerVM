//
// Created by XDomHatter on 2023-10-01.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_HEAP_HPP
#define $TEA_SRC_SHARE_RUNTIME_HEAP_HPP

#include <map>
#include <asm/BytesUtils.hpp>
#include <runtime/object.hpp>

class TeaHeap {
    u4 null_obj_idx;
    std::map<u4, InstanceOOP *> *_map;
    u4 token;
public:
    TeaHeap();
    u4 add_object(InstanceOOP *object);
    InstanceOOP *get_object(u4 index);
    inline u4 get_null_obj_index() const {
        return null_obj_idx;
    }
};

#endif //$TEA_SRC_SHARE_RUNTIME_HEAP_HPP
