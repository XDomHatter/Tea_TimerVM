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
    ArrayList_str * libpaths;

    std::vector<CodeFileObj *> *code_files;

    VMStatus status;
    bool recompile;

public:
    TimerVM(int argc, char *argv[]);
};


#endif //$TVM_SRC_SHARE_RUN_TIMERVM_HPP
