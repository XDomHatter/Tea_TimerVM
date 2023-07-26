//
// Created by Administrator on 2023-02-09.
//

#include "TimerVM.hpp"
#include <asm/Memory.hpp>
#include <utilities/Tio.hpp>
#include <utilities/macros.hpp>
#include <oop/ConstantPool.hpp>

CMDParser *TimerVM::parse_cmd(int argc, char * argv[]) {
    this->status = VMINIT;
    // parse arguments
    var cmdParser = new CMDParser(argc, argv);

    // copy inf
    this->libpaths  = cmdParser->lib_paths;
    this->recompile = cmdParser->recompile;

    return cmdParser;
}

void TimerVM::open_files(CMDParser *cmdParser) {
    this->codefiles_count = cmdParser->codefile_count;
    // package files
    this->code_files = new std::vector<CodeFileObj *>();
    std::vector<char *> * _list = cmdParser->main_codefile;
    int length = cmdParser->codefile_count;
    TeaFileParser * itParser;
    FILE          * itFile;
    CodeFileObj   * itCFO;
    for(int i = 0; i < length; i++) {
        itFile = fopen(_list->at(i), "rb+");
        if(itFile == NULL) {
            // file doesn't exists
            TConsole::output_f("fatal error: file \'%s\' doesn't exists", _list->at(i));
            QUIT(1);
        }
        // file exists, create Parser object
        itParser = new TeaFileParser(
                new TeaFileReader(itFile)
        );

        itCFO = new CodeFileObj();
        itCFO->parser = itParser;
        itCFO->filename = _list->at(i);
        this->code_files->push_back(itCFO);
    }
}

void TimerVM::parse_files(CMDParser *cmdParser) {
    CodeFileObj *itCFO = nullptr;
    int length  = cmdParser->codefile_count;
    for(int i = 0; i < length; i++) {
        itCFO = this->code_files->at(i);
        
        // check file
        itCFO->check_mg();
        // read information
        itCFO->read_inf();
        // read constant pool
        itCFO->read_cp();
        // read packages map
        itCFO->read_pk(libpaths);
        // read global variable
        itCFO->read_gv();
    }
}