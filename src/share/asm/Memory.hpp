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
    static pointer alloc_mem(int size);
    static pointer realloc_mem(pointer ptr, int size);
    static void free_mem(address mem);
    static void set_mem(pointer ptr, u1 value, int size);
};
#endif //$TVM_SRC_SHARE_ASM_MEMORY_HPP
