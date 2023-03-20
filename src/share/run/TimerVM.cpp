//
// Created by Administrator on 2023-02-09.
//

#include "TimerVM.hpp"
#include <asm/Memory.hpp>
#include <asm/BytesUtils.hpp>
#include <utilities/Tio.hpp>
#include <utilities/macros.hpp>

TimerVM::TimerVM(int argc, char * argv[]) {
    this->status = VMINIT;
    // decide endian
    {
        union {
            u2 _2;
            u1 _1;
        } _u;
        _u._2 = 0xCAFE;
        if(_u._1 == 0xCA) this->endian = EBIG_ENDIAN;
        else if(_u._1 == 0xFE) this->endian = ELITTlE_ENDIAN;
        else TConsole::error("Unknown endian(maybe someone change the memory)");
    }
    // parse arguments
    CMDParser * cmdParser = new CMDParser(argc, argv);

    // copy inf
    this->libpaths  = cmdParser->lib_paths;
    this->recompile = cmdParser->recompile;

    // open files
    this->codefiles_count = cmdParser->codefile_count;
    this->pset = new ParserSet();
    // package files
    ArrayList_str * _list = cmdParser->main_codefile;
    int length = _list->length;
    TeaFileParser * itParser;
    FILE          * itFile;
    for(int i = 0; i < length; i++){
        if(_list->has_inited(i)) {
            itFile = fopen(_list->get(i), "rb");
            if(itFile == NULL){
                // file doesn't exists
                TConsole::output_m("fatal error: file \'", _list->get(i), "\' doesn't exists",
                    NULL);
                QUIT(1);
            }
            // file exists, create Parser object
            itParser = new TeaFileParser(
                    new TeaFileReader(itFile, this->endian)
            );
            // check file
            if(!itParser->check_magic()) {
                // it is not a tea codefile
                TConsole::output_m("fatal error: file \'", _list->get(i), "\' isn't a codefile!",
                                   NULL);
            }
            pset->add(itParser);
        }
        else continue;
    }
    delete cmdParser;
}