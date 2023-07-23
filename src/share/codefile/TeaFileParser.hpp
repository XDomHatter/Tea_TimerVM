//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
#define $TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP

#include <codefile/TeaFileReader.hpp>
#include <utilities/STATUS.hpp>
#include <utilities/macros.hpp>
#include <oop/ConstantPool.hpp>
#include <list>

class TeaFileParser {
public:
    TeaFileReader * reader;
    ReaderStatus    status;
    u4 file_size;
    bool is_TCF;
//  u1 file_inf;       // 0b00000001 means FAST_METHOD mode that vm doesn't check result type
                       // 0b00000010 means NO_RES_TYPE mode that Method.result_type doesn't exists
                       // 0b00000100 means JIT_ON      mode
                       // 0b00001000 means AOT_ON      mode
    u1 inf;

    explicit TeaFileParser(TeaFileReader * tfr);
    ~TeaFileParser();

    /// check the file's magic
    /// @return the magic is 0xAE584448
    bool check_magic();
    /// read information of codefile
    /// @read file size and inf
    void read_inf();
    /// read constant-about information
    ConstantPool *read_cp() const;
    char ** read_pk_names(int count, ConstantPool *cp) const;

    

    inline bool FAST_METHOD_MODE() const {
        return inf & 1;
    }
    inline bool NO_RES_TYPE_MODE() const {
        return inf & 2;
    }
    inline bool JIT_ON() const {
        return inf & 4;
    }
    inline bool AOT_ON() const {
        return inf & 8;
    }
};


#endif //$TVM_SRC_SHARE_CODEFILE_TEAFILEPARSER_HPP
