//
// Created by abbyl on 2022/12/29.
//

#ifndef TVM_1_0_TFILEREADER_H
#define TVM_1_0_TFILEREADER_H

#include <stdio.h>
#include "types/bytes.hpp"

class TFileReader {
private:
    FILE *tfile;

public:
    TFileReader(FILE *file);
    inline FILE *getFileObj();
    address map_file(){

    }
};


#endif //TVM_1_0_TFILEREADER_H
