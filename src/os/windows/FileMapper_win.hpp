//
// Created by Administrator on 2022-12-30.
//

#ifndef TVM_1_0_FILEMAPPER_WIN_HPP
#define TVM_1_0_FILEMAPPER_WIN_HPP

#include "types/bytes.hpp"
#include "stdio.h"

class FileMapper {
public:
    static address map_file(FILE* fileObj);
};


#endif //TVM_1_0_FILEMAPPER_WIN_HPP
