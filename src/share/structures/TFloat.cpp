//
// Created by Administrator on 2023-02-02.
//

#include "structures/TFloat.hpp"

TFloat::TFloat(EENDIAN _endian) {
    this->endian = _endian;
    _DEBUG_({
        this->byte_value = 0;
        this->c_value = 0;
        this->fract = 0;
        this->integer = 0;
        this->_u_fract = 0;
        this->_u_integer = 0;
    });
}
double TFloat::get_cvalue() {
    this->c_value = (double)this->integer + this->fract;
    return this->c_value;
}
double TFloat::get_cvalue__FAST() {
    return (double)((double)this->integer + ((double)this->fract));
}
void TFloat::set(u8 byte) {
    this->byte_value = byte;
    this->_u_integer = (u4)(byte >> /* 8 * 4 = */  32);
    this->_u_fract   =     (byte & 0x00000000FFFFFFFF);
//    EENDIAN_CODE(this->endian, { // not to wrap
//        this->integer =                                          this->_u_integer;
//        this->fract   = (double )(this->_u_fract)                  * 0.0000000001;
//    }, { // must to wrap cuz _u_xx is in big endian
//        this->integer =                         Endian::wrap_u4(this->_u_integer);
//        this->fract   = (double )(Endian::wrap_u4(this->_u_fract)) * 0.0000000001;
//    });
// i dont know why but seems it doesnt need to wrap :(
    this->integer = this->_u_integer;
    this->fract   = (double )(this->_u_fract) * 0.0000000001;
}
void TFloat::set(double cv) {
//    ERR(\n\n error: TFloat::set(double) is unsupported);
    double __integer = 0;
    this->fract      = modf(cv, &__integer);
    this->integer    =       (int)__integer;
    this->_u_integer =    (u4)this->integer;
    this->_u_fract   = (u4)(this->fract * 10000000000);
    this->byte_value = (
            ((u8)this->_u_integer << 32) +
            this->_u_fract
    );
    this->c_value = cv;
}