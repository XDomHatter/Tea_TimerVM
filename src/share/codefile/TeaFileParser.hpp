//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
#define $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP

#include <codefile/TeaFileReader.hpp>
#include <utilities/STATUS.hpp>

class TeaFileParser {
public:
    TeaFileReader * reader;
    ReaderStatus    status;
    u4 file_size;
    bool is_TCF;
    struct{
        bool FAST_METHOD;
        bool NO_RES_TYPE;
        bool JIT_ON;
        bool AOT_ON;
    } inf;

    TeaFileParser(TeaFileReader * tfr);
    ~TeaFileParser();

    /// check the file's magic
    /// @return the magic is 0xAE584448
    bool check_magic();
    /// read information of codefile
    void read_inf();
    /// read constant-about information
    void read_cp();
    /// read a constant from file
    /// @return bytes of constant(REMEMBER TO FREE IT!)
    u1 * read_constant();
};


#endif //$TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
