//
// Created by abbyl on 2022/12/28.
//

#ifndef TVM_1_0_TSTRING_HPP
#define TVM_1_0_TSTRING_HPP

#include "vector"
#include "types.h"

// String for vm to make getting utf-8 constant easier
struct TString {

    std::vector<char> chars;
    u4 length;
    //A CHAR -> A PTR
    std::vector<u4*> ptrs;
};

#endif //TVM_1_0_TSTRING_HPP
