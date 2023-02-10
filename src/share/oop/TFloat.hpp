//
// Created by Administrator on 2023-02-02.
//

#ifndef $TVM_SRC_SHARE_TYPES_TFLOAT_HPP
#define $TVM_SRC_SHARE_TYPES_TFLOAT_HPP

#include <asm/BytesUtils.hpp>
#include <utilities/macros.hpp>
#include <asm/Endian.hpp>
#include <math.h>

class TFloat {
public:
    EENDIAN     endian;
    u8     byte_value; // !this is bytes in big endian, not number!
    u4     _u_integer; // !this is bytes in big endian, not number!
    u4       _u_fract; // !this is bytes in big endian, not number!
    double    c_value;
    int       integer;
    double      fract;

    TFloat(EENDIAN _endian);
    void              set(u8 byte); // create obj with u8 (in big endian)
    void            set(double cv); // create with c value
    double            get_cvalue(); // get double value in c
    double FAST_FUNC(get_cvalue)(); // get double value in c without setting varible
};


#endif //$TVM_SRC_SHARE_TYPES_TFLOAT_HPP