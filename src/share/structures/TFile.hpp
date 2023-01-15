//
// Created by Administrator on 2023-01-15.
//

#ifndef TVM_TFILE_HPP
#define TVM_TFILE_HPP

#include "types/bytes.hpp"

class TFile {
public:
    u4 magic_num; // AE 58 44 48
    /*
     * xxxxxxx0 little endian
     * xxxxxxx1 big endian
     * xxxxxx0x
     */
    u1 file_inf ;
};


#endif //TVM_TFILE_HPP
