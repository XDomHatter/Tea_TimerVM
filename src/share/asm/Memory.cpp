//
// Created by Administrator on 2023-02-26.
//

#include "Memory.hpp"
#include <string.h>

pointer Memory::alloc_mem(size_t size) {
    return (pointer)malloc(size);
}
pointer Memory::realloc_mem(pointer ptr, size_t size) {
    return (pointer)realloc(ptr, size);
}
void Memory::free_mem(address mem) {
    free(mem);
}
void Memory::set_mem(pointer ptr, u1 value, size_t size) {
    memset(ptr, value, size);
}
void Memory::copy(pointer source, pointer dest, size_t size) {
    memcpy(dest, source, size);
}

