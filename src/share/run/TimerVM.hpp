//
// Created by Administrator on 2023-02-09.
//

#ifndef $TVM_SRC_SHARE_RUN_TIMERVM_HPP
#define $TVM_SRC_SHARE_RUN_TIMERVM_HPP

#include <run/Bootstrap.hpp>
#include <codefile/TeaFileReader.hpp>
#include <codefile/TeaFileParser.hpp>
#include <run/CmdParser.hpp>

class TimerVM {
private:
    CMDParser * parser;
public:

    TimerVM(int argc, char * argv[]);
};


#endif //$TVM_SRC_SHARE_RUN_TIMERVM_HPP
