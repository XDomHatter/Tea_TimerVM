//
// Created by Administrator on 2023-03-11.
//

#include "cstr_utils.hpp"
#include <asm/Memory.hpp>

char *CSTRUtil::copy(char *dst, char *src) {
    strcpy(dst, src);
    return dst;
}

char *CSTRUtil::cat(char **s1, char *s2) {
    if(s2 == NULL) {
        return *s1;
    }
    if(*s1 == NULL) {
        *s1 = (char *) Memory::alloc_mem(len(s2));
        copy(*s1, s2);
        return *s1;
    }


    int len1 = len(*s1),
        len2 = len(s2);
    char *res = (char *) Memory::alloc_mem(len1 + len2 + 1); // +1 cuz '\0'
    Memory::copy((pointer) *s1, (pointer) res           , len1);
    Memory::copy((pointer) s2, (pointer) (res+len1), len2);
    res[len1 + len2] = '\0';
    Memory::free_mem(*s1);
    *s1 = res;
    return *s1;
}

int CSTRUtil::len(char *str) {
    int res = 0;
    char c  = *str;
    for(int i = 1; c != '\0'; i++) {
        // meet '\0' and break, so the res doesn't contain '\0'
        res ++;
        c = *(str+i);
    }
    return res;
}

