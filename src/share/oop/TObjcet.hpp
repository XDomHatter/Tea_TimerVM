//
// Created by Administrator on 2023-02-04.
//

#ifndef $TVM_SRC_SHARE_TYPES_TOBJCET_HPP
#define $TVM_SRC_SHARE_TYPES_TOBJCET_HPP

#include "asm/Endian.hpp"
#include "asm/BytesUtils.hpp"

class TObjcet {
private:
    EENDIAN endian;
public:
    TObjcet(EENDIAN _endian);
};


#endif //$TVM_SRC_SHARE_TYPES_TOBJCET_HPP
