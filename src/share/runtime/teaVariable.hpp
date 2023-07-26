//
// Created by Administrator on 2023-07-24.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_TEAVARIABLE_HPP
#define $TEA_SRC_SHARE_RUNTIME_TEAVARIABLE_HPP

#include <asm/BytesUtils.hpp>
#include <asm/Memory.hpp>

typedef u4 TSlot;

class TeaVariableSet {
    u2 slot_count;
    TSlot *slots;

public:
    inline explicit TeaVariableSet(u2 count_slot) {
        this->slot_count = count_slot;
        this->slots      = Memory::alloc_mem<TSlot>(count_slot);
    }

    inline void set_u1(u2 index, u1 value) {
        this->slots[index] = value;
    }
    inline void set_u2(u2 index, u2 value) {
        this->slots[index] = value;
    }
    inline void set_u4(u2 index, u4 value) {
        *((u4 *) (this->slots + index * 2)) = value;
    }
    inline void set_u8(u2 index, u8 value) {
        *((u8 *) (this->slots + index * 2)) = value;
    }

    inline u1 get_u1(u2 index) {
        return slots[index];
    }
    inline u2 get_u2(u2 index) {
        return slots[index];
    }
    inline u4 get_u4(u2 index) {
        return *((u4 *) (this->slots + index * 2));
    }
    inline u8 get_u8(u2 index) {
        return *((u8 *) (this->slots + index * 2));
    }
};

#endif //$TEA_SRC_SHARE_RUNTIME_TEAVARIABLE_HPP
