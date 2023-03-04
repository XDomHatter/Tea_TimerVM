//
// Created by Administrator on 2023-02-25.
//

#include "BitMap.hpp"
#include <stdlib.h>
#include <asm/Memory.hpp>
#include <utilities/Tio.hpp>
#include <utilities/cint_utils.hpp>

BitMap::BitMap(int length) {
    // length => multiples of 8 => divide by 8
    // 9      => 16             => 2
    // 8      => 8              => 1
    // 17     => 24             => 3

    int byte_num = (length / 8) + ((length % 8 == 0) ? 0 : 1);
    this->bits = (u1 *)Memory::alloc_mem(byte_num);

    this->size = length;
    this->real_size = byte_num;
}
BitMap::~BitMap() {
    Memory::free_mem(this->bits);
}

void BitMap::set(int idx, bool true_or_false) {
    if(idx >= size){
        TConsole::error("BitMap::set(int)", "index out of range", "idx");
        return;
    }
    // no error:
    u1 * area; // specific area of object bit

    // e.g. idx = 18  bits = 0x00A0
    // memory seeing:
    // -------------------------------------index--------------------------------------
    // | 0  1  2  3  4  5  6  7     8  9  10 11 12 13 14 15    16 17 18 19 20 21 22 23|
    // -----------------------------------bit value-----------------------------------|
    // | 1  0  1  0  1  0  1  0     1  1  1  1  1  1  1  1     0  1  x  0  1  0  1  1 |
    // ------------------------------------address------------------------------------|
    // | 0x00A0                     0x00A1                     0x00A2                 |
    // --------------------------------------------------------------------------------
    // idx / 8 = 2
    // bits + 2 = 0x00A2    =>  01x01011
    area = (this->bits + (idx/8));

    if(true_or_false){ // true => 1
        if((*area) >> ( 8 - ((idx+1)%8)) & 0x01){
            // idx + 1 = 19
            // 19 % 8  = 3
            // 8  - 3  = 5
            // 01x01011 >> 5 = 0000001x
            // 0000001x & 00000001 ( 0x01 ) = x

            // the expression is true, x don't need to set
            return;
        } else {
            // x is 0
            *(area) += (0x01 << ( 8 - ((idx+1)%8)));
            // idx + 1 = 19
            // 19 % 8  = 3
            // 8  - 3  = 5
            // 00000001(0x01) << 5 = 00100000
            // 01001011 + 00100000 = 01101011  it's been set
            return;
        }
    } else {
        if((*area) >> ( 8 - ((idx+1)%8)) & 0x01){
            // idx + 1 = 19
            // 19 % 8  = 3
            // 8  - 3  = 5
            // 01x01011 >> 5 = 0000001x
            // 0000001x & 00000001 ( 0x01 ) = x

            // expression is true, so x is 1

            // idx + 1 = 19
            // 19  % 8  = 3
            // 8   - 3  = 5
            // 00000001(0x01) << 5 = 00100000
            // 00111010 - 00100000 = 00011010  it's been set
            *(area) -= (0x01 << ( 8 - ((idx+1)%8)));
            return;
        } else {
            // x is 0
            return; // no need to set
        }
    }

}
char BitMap::get(int idx) {
    if(idx >= this->size){
        TConsole::error("BitMap::get(int)", "index out of range", "idx");
    }

    u1 area; // specific area of object bit
    // e.g. idx = 18  bits = 0x00A0
    // memory seeing:
    // -------------------------------------index--------------------------------------
    // | 0  1  2  3  4  5  6  7     8  9  10 11 12 13 14 15    16 17 18 19 20 21 22 23|
    // -----------------------------------bit value-----------------------------------|
    // | 1  0  1  0  1  0  1  0     1  1  1  1  1  1  1  1     0  1  x  0  1  0  1  1 |
    // ------------------------------------address------------------------------------|
    // | 0x00A0                     0x00A1                     0x00A2                 |
    // --------------------------------------------------------------------------------
    // idx / 8 = 2
    // bits + 2 = 0x00A2    =>  01101011
    area = *(this->bits + (idx/8));

    return (area >> ( 8 - ((idx+1)%8)) & 0x01);
    // idx + 1 = 19
    // 19 % 8  = 3
    // 8  - 3  = 5
    // 01x01011 >> 5 = 0000001x
    // 0000001x & 00000001(0x01) = x
}

void BitMap::extend(int s) {
    setsize(this->size+s);
    // fields are set in 'setsize', direct return is alright
    return;
}
void BitMap::setsize(int s) {
    if((this->real_size == (s / 8)) && ((s % 8) == 0)){
        // user wanna extend but now real length is enough
        //
        // (this->real_size == (s / 8)):
        // 's' is count of bit and 'this->real_size' is count of byte,
        // so we need to divided it by 8
        //
        // (s % 8) == 0):
        // but 19/8 = 2, so we need to make sure 's' is multiple of 8

        this->size = real_size; // already allocated but user don't know
        return;
    }

    if(s < (this->real_size * 8)){
        // user wanna extend but now real length is enough
        // 's' is count of bit and 'this->real_size' is count of byte,
        // so we need to multi it by 8
        this->size += s;
        return;
    }

    // real size is not enough

    //
    if(s < 8){
        // s < 8, so align to a byte
        this->bits = (u1 *)Memory::realloc_mem(this->bits, (this->real_size + 1));
        this->real_size += 1;
        this->size += s;
        return;
    } else if(s%8 == 0){
        // s is multiples of 8
        this->bits = (u1 *)Memory::realloc_mem(this->bits, (this->real_size + (s/8)));
        this->size += s;
        this->real_size += (s / 8);
        return;
    } else {
        // s isn't multiples of 8
        // e.g. s = 19
        // 19 / 8 = 2
        // so we need a more byte for the last 3 bit
        this->bits = (u1 *)Memory::realloc_mem(this->bits, (this->real_size + (s/8 + 1)));
        this->size += s;
        this->real_size += (s/8 + 1);
    }
}