//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
#define $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP

#include <codefile/TeaFileReader.hpp>

class TeaFileParser {
private:

    TeaFileReader * reader;
    u4 file_size;
    bool checked_TCF;
    bool is_TCF;
    struct{
        bool FAST_METHOD;
        bool NO_RES_TYPE;
        bool JIT_ON;
        bool AOT_ON;
    } inf;
public:
    TeaFileParser(TeaFileReader * tfr);
    ~TeaFileParser();

    bool check_magic();
    void read_inf();
};


#endif //$TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
