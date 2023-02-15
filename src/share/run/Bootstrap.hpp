//
// Created by Administrator on 2023-02-09.
//

#ifndef $TVM_SRC_SHARE_RUN_BOOTSTRAP_HPP
#define $TVM_SRC_SHARE_RUN_BOOTSTRAP_HPP

#include <utilities/file_macros.hpp>
#include <asm/BytesUtils.hpp>
#include <asm/Endian.hpp>
#include <codefile/TeaFileReader.hpp>

// Bootstrap is for load and check code file
class Bootstrap {
private:
    FILE *       code_file;
    EENDIAN         endian;
    TeaFileReader * reader;
public:
    Bootstrap(char * filename);
    ~Bootstrap(); // to free a pointer field
    u1       check_magic_num();
};


#endif //$TVM_SRC_SHARE_RUN_BOOTSTRAP_HPP
