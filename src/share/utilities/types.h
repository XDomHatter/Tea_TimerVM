//
// Created by Administrator on 2022-12-26.
//




#ifndef TVM_1_0_TYPES_H
#define TVM_1_0_TYPES_H

#include <vector>

#define USING_NAMESPACE_STD

#ifdef USING_NAMESPACE_STD
using namespace std;
#endif
//	BASIC TYPES
#define u1 char  //one byte
#define u2 short //two bytes
#define u4 int   //three bytes
/*
 * u2/u4 should care about endian
 * when in little endian, to turn them into big endian,
 * should use 'swap_u2(u2) or swap_u4(u4)
 */
u2 swap_u2(u2 _u2) {
    /* for example:
     * _u2 : 11111111 00000000
     */
    return ((_u2 >> 8) + (_u2 << 8));
}

#define boolean bool

//	STRING TYPE
//	IT IS A STRUCT
struct Sstring {

    vector<char> chars;
    u4 length;
    //A CHAR -> A PTR
    u4 *ptr[];
};

//u8 is indefinetely

#endif //TVM_1_0_TYPES_H
