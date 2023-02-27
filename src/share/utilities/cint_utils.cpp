//
// Created by Administrator on 2023-02-26.
//

#include "cint_utils.hpp"

char * cint2cstr(int num){
    char str[12]; // max value of integer is 2147483647, it has 10 digit,
    // with '-' and '\0', there is 12 chars
    int i = 0; // index of str
    if (num < 0) // if num is a negative number
    {
        num = -num; // make it into a positive number
        str[i++] = '-';
    }
    // transition
    do {
        str[i++] = num % 10 + 48; // take the lowest digit of num,
        // ascii of string 0-9 is 48-57
        // so the match str of the int is
        // int_value + 48;
        // e.g. 0 + 48 = '0'
        num /= 10; // remove the last digit
    } while (num); // go on repeat if num isn't 0

    str[i] = '\0'; // end of str

    // get the index of starting
    int j = 0;
    if (str[0] == '-') { // if there's a negative sign, skip it
        j = 1; // start from 2
        ++i;
    }
    // symmetric exchange
    for (; j < i / 2; j++) {
        // a=a+b;b=a-b;a=a-b; ( a wonderful algorithm )
        str[j] = str[j] + str[i - 1 - j];
        str[i - 1 - j] = str[j] - str[i - 1 - j];
        str[j] = str[j] - str[i - 1 - j];
    }
    return str;
}