//
// Created by Administrator on 2023-01-17.
//

#ifndef $TVM_SRC_SHARE_ASM_ENDIAN_HPP
#define $TVM_SRC_SHARE_ASM_ENDIAN_HPP

typedef enum {
    EBIG_ENDIAN = 0x00,
    ELITTLE_ENDIAN = 0xFF
} EENDIAN;

#define DETECT_ENDIAN( o ) {                     \
    union {                                      \
        unsigned short _2;                       \
        unsigned char  _1;                       \
    } _u;                                        \
    _u._2 = 0xCAFE;                              \
    if(_u._1 == 0xCA)      o = EBIG_ENDIAN;      \
    else if(_u._1 == 0xFE) o = ELITTLE_ENDIAN;   \
}

#define EENDIAN_CODE( endian, BIG, LIT) \
    if(endian == EBIG_ENDIAN) {BIG}     \
    else {LIT}




#endif //$TVM_SRC_SHARE_ASM_ENDIAN_HPP
