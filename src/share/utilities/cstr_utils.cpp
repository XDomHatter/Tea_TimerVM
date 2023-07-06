//
// Created by Administrator on 2023-03-11.
//

#include "cstr_utils.hpp"
#include <asm/Memory.hpp>

char *CSTRUtil::copy(char *dst, char *src) {
    strcpy(dst, src);
    return dst;
}

char *CSTRUtil::cat(char *s1, char *s2) {
    char *res = NULL;

    if(s2 == NULL || *s2 == '\0')
        copy(res, s1);
    else if(s1 == NULL) {
        res = (char *) Memory::alloc_mem(len(s2));
        copy(res, s2);
    } else {
        int len_1 = len(s1),
            len_2 = len(s2);
        res = (char *) Memory::alloc_mem(len_1 + len_2 + 1); // +1 cuz '\0'
        Memory::copy((pointer) s1, (pointer) res, len_1);
        Memory::copy((pointer) s2, (pointer) (res + len_1), len_2);
        res[len_1 + len_2] = '\0';
    }
    return res;
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

