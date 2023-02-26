//
// Created by Administrator on 2023-02-26.
//

#include "Memory.hpp"

address Memory::alloc_mem(int size) {
    return malloc(size);
}

void Memory::free_mem(address mem) {
    free(mem);
}