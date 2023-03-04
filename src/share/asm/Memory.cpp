//
// Created by Administrator on 2023-02-26.
//

#include "Memory.hpp"

ptr Memory::alloc_mem(int size) {
    return (ptr)malloc(size);
}
ptr Memory::realloc_mem(ptr pointer, int size) {
    return (ptr)realloc(pointer, size);
}
void Memory::free_mem(address mem) {
    free(mem);
}


