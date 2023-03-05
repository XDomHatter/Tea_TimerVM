//
// Created by Administrator on 2023-02-26.
//

#include "cint_utils.hpp"


char *cint2cstr(int num) {
    const int MAX_SIZE = 12; // Including sign and null terminator
    char str[MAX_SIZE];
    int i = 0, j;
    bool isNegative = false;
    if (num < 0) {
        num = -num;
        isNegative = true;
    }
    do {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num);
    if (isNegative) str[i++] = '-';
    str[i] = '\0';

    // Reversing the string
    for (j = isNegative ? 1 : 0; j < i / 2; j++) {
        str[j] ^= str[i - j - 1];
        str[i - j - 1] ^= str[j];
        str[j] ^= str[i - j - 1];
    }
    return str;
}
