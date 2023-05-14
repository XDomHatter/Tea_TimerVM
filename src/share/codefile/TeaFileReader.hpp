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

public:
    EENDIAN endian;
    TeaFileReader(FILE * fileobj, EENDIAN eendian);
    ~TeaFileReader();
    u1 readU1();
    u2 readU2();
    u4 readU4();
    u8 readU8();
    /// read n bytes from file(REMEMBER TO FREE IT!!!!)
    /// @param n count of bytes
    /// @return bytes
    u1 * readUn(int n);
};


#endif //$TVM_SRC_SHARE_CODEFILE_TEAFILEREADER_HPP
