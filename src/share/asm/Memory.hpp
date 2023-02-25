//
// Created by Administrator on 2023-02-25.
//

#ifndef $TVM_SRC_SHARE_ASM_MEMORY_HPP
#define $TVM_SRC_SHARE_ASM_MEMORY_HPP

#include <asm/BytesUtils.hpp>
#include <stdlib.h>

typedef   u1 *     ptr;
typedef void * address;

address alloc_mem(int size){
    return malloc(size);
}
void    free_mem(address mem){
    free(mem);
}

#endif //$TVM_SRC_SHARE_ASM_MEMORY_HPP
