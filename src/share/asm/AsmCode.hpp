//
// Created by Administrator on 2023-01-04.
//

#ifndef TVM_ASMCODE_HPP
#define TVM_ASMCODE_HPP

#include "types/BytesUtils.hpp"
#include "utilities/macros.hpp"

class AsmCode {
private:
    u1 instruction;
    u1       *args;
public:
    int length;
    virtual u1 * make_code();

};


#endif //TVM_ASMCODE_HPP
