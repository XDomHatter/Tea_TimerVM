//
// Created by Administrator on 2023-02-25.
//

#ifndef $TVM_SRC_SHARE_ASM_MEMORY_HPP
#define $TVM_SRC_SHARE_ASM_MEMORY_HPP

#include <asm/BytesUtils.hpp>
#include <string.h>
#include <stdlib.h>

typedef   u1 *     pointer;
typedef void * address;

class Memory {
public:
    /// same perform as malloc
    inline static pointer alloc_mem(size_t size) {
        return (pointer) malloc(size);
    }
    template<typename T>
    inline static T* alloc_mem(int count) {
        return (T*) alloc_mem(sizeof(T) * count);
    }
    inline static pointer realloc_mem(pointer ptr, size_t size) {
        return (pointer) realloc(ptr, size);
    }
    static pointer realloc_mem_keep_data(pointer *ptr, size_t size_of_old_ptr, size_t new_size);
    inline static void free_mem(address mem) {
        free(mem);
    }
    inline static void set_mem(pointer ptr, u1 value, size_t size) {
        memset(ptr, value, size);
    }
    /// move source -> dest
    inline static void copy(pointer source, pointer dest, size_t size) {
        memcpy(dest, source, size);
    }
};
#endif //$TVM_SRC_SHARE_ASM_MEMORY_HPP
