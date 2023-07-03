//
// Created by Administrator on 2023-02-25.
//

#ifndef $TVM_SRC_SHARE_ASM_MEMORY_HPP
#define $TVM_SRC_SHARE_ASM_MEMORY_HPP

#include <asm/BytesUtils.hpp>
#include <stdlib.h>

typedef   u1 *     pointer;
typedef void * address;

class Memory {
public:
    /// same perform as malloc
    static pointer alloc_mem(size_t size);
    template<typename T>
    inline static T* alloc_mem(int count) {
        return (T*) alloc_mem(sizeof(T) * count);
    }
    static pointer realloc_mem(pointer ptr, size_t size);
    static void free_mem(address mem);
    static void set_mem(pointer ptr, u1 value, size_t size);
    /// move source -> dest
    static void copy(pointer source, pointer dest, size_t size);
};
#endif //$TVM_SRC_SHARE_ASM_MEMORY_HPP
