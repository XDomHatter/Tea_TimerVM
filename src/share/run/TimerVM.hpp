//
// Created by Administrator on 2023-02-09.
//

#ifndef $TVM_SRC_SHARE_RUN_TIMERVM_HPP
#define $TVM_SRC_SHARE_RUN_TIMERVM_HPP

#include <run/CmdParser.hpp>
#include <utilities/STATUS.hpp>
#include <codefile/CodeFileObj.hpp>
#include <vector>

class TimerVM {
private:
    EENDIAN endian;

    int codefiles_count;
    std::vector<char *> *libpaths;

    std::vector<CodeFileObj *> *code_files;

    VMStatus status;
    bool recompile;

public:
    CMDParser *parse_cmd(int argc, char *argv[]);
    void open_files (CMDParser *cmdParser);
    void parse_files(CMDParser *cmdParser);
    inline CodeFileObj *get_code_file(int index) const {
        return code_files->at(index);
    }
};


#endif //$TVM_SRC_SHARE_RUN_TIMERVM_HPP
