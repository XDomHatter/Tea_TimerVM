//
// Created by Administrator on 2023-02-25.
//

#ifndef $TVM_SRC_SHARE_ASM_MEMORY_HPP
#define $TVM_SRC_SHARE_ASM_MEMORY_HPP

#include <asm/BytesUtils.hpp>
#include <stdlib.h>

typedef   u1 *     ptr;
typedef void * address;

class Memory {
public:
    static ptr alloc_mem(int size);
    static ptr realloc_mem(ptr pointer, int size);
    static void free_mem(address mem);
};
#endif //$TVM_SRC_SHARE_ASM_MEMORY_HPP
