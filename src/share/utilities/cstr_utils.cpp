//
// Created by Administrator on 2023-03-11.
//

#include "cstr_utils.hpp"
#include <asm/Memory.hpp>

#define DEF *str1
char *CSTRUtil::copy(char *dst, char *src) {
    if((dst != NULL) || (src != NULL))
        strcpy(dst, src);
    
    return dst;
}

char *CSTRUtil::cat(char *s1, char *s2) {
    char *res = NULL;

    if (s2 == NULL || *s2 == '\0') {
        res = Memory::alloc_mem<char>(len(s1) + 1);
        copy(res, s1);
    }
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
char *CSTRUtil::cat(char *s1, ...) {
    if(s1 == NULL)
        return NULL;
    int res_last_size = 10;
    int res_totl_size = 10;
    int cur = 0;
    char *res = Memory::alloc_mem<char>(10);
    va_list vl; va_start(vl, s1);
    char *t = s1;
    while(t != NULL) {
        int length_of_t = len(t);
        if(length_of_t >= res_last_size) {
            int res_new_size = (res_totl_size + length_of_t + 10);
            Memory::realloc_mem_keep_data((pointer *) &res, res_totl_size, res_new_size);
            res_totl_size = res_new_size;
        }
        Memory::copy((pointer) t, (pointer) (res + cur), length_of_t);
        res_last_size -= length_of_t;
        cur += length_of_t;

        t = va_arg(vl, char *);
    }
    va_end(vl);
    res[cur] = '\0';
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

bool CSTRUtil::unsafe_end_with(char *src, char *obj, int len_of_src, int len_of_obj) {
    if(len_of_obj > len_of_src) {
        return false;
    }
    if(len_of_src == len_of_obj) {
        return cstr_EQUAL(src, obj);
    }
    if(len_of_src <= 0 || len_of_obj <= 0) {
        return false;
    }
    int idx_of_src = len_of_src - 1;
    int idx_of_obj = len_of_obj - 1;
    // e.g.
    // src = [ 's' 't' 'r' 'i' 'n' 'g' '\0' ] idx_of_src = 5
    // obj =             [ 'i' 'n' 'g' '\0' ] idx_of_obj = 2
    while(idx_of_obj >= 0) {
        if(src[idx_of_src--] != obj[idx_of_obj--]) {
            return false;
        }
    }
    return true;
}
char *CSTRUtil::replace(char *str, char *find, char *replace) {
    int find_len = len(find);
    int replace_len = len(replace);

    char *occurrence = strstr(str, find);
    int occurrences = 0;
    while (occurrence != NULL) {
        occurrences++;
        occurrence = strstr(occurrence + 1, find);
    }
    int original_len = len(str);
    int newLen = original_len + occurrences * (replace_len - find_len) + 1;

    char *result = (char *) malloc(newLen);

    char *src = str;
    char *dest = result;

    while (*src) {
        if (strstr(src, find) == src) {
            strcpy(dest, replace);
            dest += replace_len;
            src += find_len;
        } else {
            *dest++ = *src++;
        }
    }
    *dest = '\0';
    return result;
}
size_t CSTRUtil::get_hashcode(char *str) {
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    char *sstr = str;

    while (*sstr) {
        hash = hash * seed + (*sstr++);
    }

    return (hash & 0x7FFFFFFF);
}
