//
// Created by Administrator on 2023-02-09.
//

#include "TimerVM.hpp"
#include <run/CmdParser.hpp>
#include <utilities/Tio.hpp>

TimerVM::TimerVM(int argc, char * argv[]) {
    this->parser = new CMDParser(argc, argv);
}