//
// Created by Administrator on 2023-02-26.
//

#include "cint_utils.hpp"
#include <stdio.h>
#include <asm/Memory.hpp>


char *cint2cstr(int num) {
    const int MAX_SIZE = 12; // Including sign and null terminator
    char *str = Memory::alloc_mem<char>(11);
    
    sprintf(str, "%d", num);
    return str;
}
