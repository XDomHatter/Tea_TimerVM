//
// Created by abbyl on 2022/12/29.
//

#ifndef TVM_1_0_TFILEREADER_H
#define TVM_1_0_TFILEREADER_H

#pragma pack(1)

#include <stdio.h>
#include "types/bytes.hpp"

class TFileReader {
private:
    FILE        *tfile;
    size_t   buff_size;
    size_t   file_size;
    size_t current_idx;
    address  start_adr;
    // feof doesn't work cuz there are some 0xFF in the file
    // but dosn't means EOF(end-of-file)
    bool           eof;
    char   endian_type;

public:
    TFileReader(const char *fname, size_t buff_size);
    inline FILE *getFileObj();
    void           map_file();
    bool             is_end();
};


#endif //TVM_1_0_TFILEREADER_H
