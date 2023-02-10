//
// Created by Administrator on 2023-01-17.
//

#ifndef $TVM_SRC_SHARE_ASM_ENDIAN_HPP
#define $TVM_SRC_SHARE_ASM_ENDIAN_HPP

#include <asm/BytesUtils.hpp>

typedef enum {
    EBIG_ENDIAN,
    ELITTlE_ENDIAN
} EENDIAN;

#define EENDIAN_CODE( endian, BIG, LIT) \
    if(endian == EBIG_ENDIAN) {BIG}     \
    else {LIT}




#endif //$TVM_SRC_SHARE_ASM_ENDIAN_HPP
