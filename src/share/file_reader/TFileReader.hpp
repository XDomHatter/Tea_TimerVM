//
// Created by abbyl on 2022/12/29.
//

#ifndef TVM_1_0_TFILEREADER_H
#define TVM_1_0_TFILEREADER_H

#include <stdio.h>

class TFileReader {
private:
    FILE *tfile;

public:
    TFileReader(FILE *file);
    inline FILE *getFileObj();
};


#endif //TVM_1_0_TFILEREADER_H
