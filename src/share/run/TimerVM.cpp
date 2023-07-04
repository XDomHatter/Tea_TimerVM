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
    // decide endian
    DETECT_ENDIAN( this->endian );
    // parse arguments
    CMDParser * cmdParser = new CMDParser(argc, argv);

    // copy inf
    this->libpaths  = cmdParser->lib_paths;
    this->recompile = cmdParser->recompile;



}

void TimerVM::open_files(CMDParser *cmdParser) {
    this->codefiles_count = cmdParser->codefile_count;
    // package files
    this->code_files = new std::vector<CodeFileObj *>();
    ArrayList_str * _list = cmdParser->main_codefile;
    int length = cmdParser->codefile_count;
    TeaFileParser * itParser;
    FILE          * itFile;
    CodeFileObj   * itCFO;
    for(int i = 0; i < length; i++) {
        if(_list->has_inited(i)) {
            itFile = fopen(_list->get(i), "rb+");
            if(itFile == NULL) {
                // file doesn't exists
                TConsole::output_m("fatal error: file \'", _list->get(i), "\' doesn't exists",
                                   NULL);
                QUIT(1);
            }
            // file exists, create Parser object
            itParser = new TeaFileParser(
                    new TeaFileReader(itFile, this->endian),
                    this->endian
            );
            // check file
            if(!itParser->check_magic()) {
                // it is not a tea codefile
                TConsole::output_m("fatal error: file \'", _list->get(i), "\' isn't a codefile!",
                                   NULL);
                QUIT(1);
            }

            itCFO = new CodeFileObj();
            itCFO->parser = itParser;
            this->code_files->push_back(itCFO);
        }
        else continue;
    }
}

void TimerVM::parse_files(CMDParser *cmdParser) {
    CodeFileObj *itCFO = nullptr;
    int length  = cmdParser->codefile_count;
    for(int i = 0; i < length; i++) {
        itCFO = this->code_files->at(i);

        itCFO->parser->read_inf();

        // read package
        /// @todo code for reading included packages
        itCFO->parser->reader->nextU2_fast();
        // read constant pool
        itCFO->cp = itCFO->parser->read_cp();

    }
}