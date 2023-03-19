//
// Created by Administrator on 2023-02-09.
//

#ifndef $TVM_SRC_SHARE_RUN_TIMERVM_HPP
#define $TVM_SRC_SHARE_RUN_TIMERVM_HPP

#include <codefile/ParserSet.hpp>
#include <run/Bootstrap.hpp>
#include <run/CmdParser.hpp>
#include <run/STATUS.hpp>

class TimerVM {
private:
    EENDIAN endian;

    int codefiles_count;
    ArrayList_str * libpaths;

    ParserSet * pset; // File parsers ( can use this to visit all parsers and readers

    VMStatus status;
    bool recompile;
public:

    TimerVM(int argc, char *argv[]);
};


#endif //$TVM_SRC_SHARE_RUN_TIMERVM_HPP
