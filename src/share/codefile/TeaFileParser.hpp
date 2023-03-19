//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
#define $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP

#include <codefile/TeaFileReader.hpp>

class TeaFileParser {
private:
    TeaFileReader * reader;
    bool checked_TCF;
    bool is_TCF;
public:
    TeaFileParser(TeaFileReader * tfr);

    bool check_magic();
};


#endif //$TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
