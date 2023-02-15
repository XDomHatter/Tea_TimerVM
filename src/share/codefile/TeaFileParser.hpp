//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
#define $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP

#include <codefile/TeaFileReader.hpp>

class TeaFileParser {
private:
    TeaFileReader * reader;
public:
    TeaFileParser(TeaFileReader * tfr);
};


#endif //$TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
