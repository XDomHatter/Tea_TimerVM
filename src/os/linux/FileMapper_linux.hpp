//
// Created by Administrator on 2022-12-30.
//

#ifndef TVM_1_0_FILEMAPPERLINUX_HPP
#define TVM_1_0_FILEMAPPERLINUX_HPP

#include <sys/mman.h>
#include <stdio.h>
#include "types/bytes.hpp"

class FileMapper {
public:
    static address map_file(FILE* fileObj);
};


#endif //TVM_1_0_FILEMAPPERLINUX_HPP
