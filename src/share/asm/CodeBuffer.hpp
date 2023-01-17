//
// Created by Administrator on 2023-01-04.
//

#ifndef TVM_CODEBUFFER_HPP
#define TVM_CODEBUFFER_HPP

#include "types/BytesUtils.hpp"
#include "AsmCode.hpp"

class CodeBuffer {
private:
    address   _start;
    address _current;
public:
    void emit_code(AsmCode code);
    address    run(            );


};


#endif //TVM_CODEBUFFER_HPP
