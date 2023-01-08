//
// Created by Administrator on 2023-01-04.
//

#include "CodeBuffer.hpp"
#include "utilities/macros.hpp"
#include "stdint.h"

void CodeBuffer::emit_code(AsmCode code) {
    this->_current = code.make_code();
    this->_current += code.length;
}
