//
// Created by abbyl on 2022/12/29.
//

#ifndef TVM_1_0_TFILEREADER_H
#define TVM_1_0_TFILEREADER_H

#pragma pack(1)

#include <stdio.h>
#include "asm/BytesUtils.hpp"
#include "asm/Endian.hpp"

#define stdFILE_skip(file, size) fgets(NULL, size, file)

class TFileReader {
private:
    FILE        *tfile;
    size_t   buff_size;
    size_t   file_size;
    size_t current_idx;
    address  start_adr;


public:
    TFileReader(const char *fname, size_t buff_size);
    inline FILE *getFileObj();
    void           map_file();
    bool             is_end();
};


#endif //TVM_1_0_TFILEREADER_H
