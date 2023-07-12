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
pointer Memory::realloc_mem_keep_data(pointer *ptr, size_t size_of_old_ptr, size_t new_size) {
    pointer newptr = alloc_mem(new_size);
    copy(*ptr, newptr, size_of_old_ptr);
    free_mem(*ptr);
    *ptr = newptr;
    return newptr;
}
void Memory::free_mem(address mem) {
    free(mem);
}
void Memory::set_mem(pointer ptr, u1 value, size_t size) {
    memset(ptr, value, size);
}
void Memory::copy(pointer source, pointer dest, size_t size) {
    for(int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

