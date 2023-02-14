//
// Created by Administrator on 2023-02-08.
//

#ifndef $TVM_SRC_SHARE_CODEFILE_TEAFILEREADER_HPP
#define $TVM_SRC_SHARE_CODEFILE_TEAFILEREADER_HPP

#include <utilities/file_macros.hpp>
#include <asm/BytesUtils.hpp>
#include <asm/Endian.hpp>

class TeaFileReader {
private:
    FILE * file;
    EENDIAN endian;
public:
    TeaFileReader(FILE * fileobj, EENDIAN eendian);
    u1 readU1();
    u2 readU2();
    u4 readU4();
    u8 readU8();
};


#endif //$TVM_SRC_SHARE_CODEFILE_TEAFILEREADER_HPP
