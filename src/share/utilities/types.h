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
#define u1 char
#define u2 short
#define u4 int
#define boolean bool

//	STRING TYPE
//	IT IS A STRUCT
struct Struct_Str {

    vector<char> chars;
    u4 length;
    //A CHAR -> A PTR
    vector<u4*> ptrs;
};

typedef Struct_Str Str;

//u8 is indefinetely

#endif //TVM_1_0_TYPES_H
