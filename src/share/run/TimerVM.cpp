//
// Created by Administrator on 2023-02-09.
//

#include "TimerVM.hpp"
#include <asm/Memory.hpp>
#include <utilities/Tio.hpp>
#include <utilities/macros.hpp>
#include <oop/ConstantPool.hpp>

void TimerVM::initialize() {}

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
    int length = codefiles_count;
    TeaFileParser * itParser;
    FILE          * itFile;
    CodeFileObj   * itCFO;
    for(int i = 0; i < length; i++) {
        itFile = fopen(_list->at(i), "rb");
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

void TimerVM::parse_files() {
    CodeFileObj *itCFO = nullptr;
    int length  = codefiles_count;
    TFunction *main_func = NULL;

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
        // read global functions info
        itCFO->read_gf_info();
        if(itCFO->has_main_func()) {
            if(main_func != NULL) {
                // there's already a main function
                TConsole::error("Multiple main functions found. \n");
            }
            itCFO->read_global_funcs();
            main_func = itCFO->get_gf_fast(METHOD_FUNCTION_Constant::main_func_cst());
        }
    }
    if(main_func == NULL) {
        QUIT(0);
    }
    this->main_function = main_func;
}

int TimerVM::exec_main_func(int argc, char **argv) {
    TeaValue args_in_tea = TeaValue::create_by_oop(
        InstanceArray::package_values<char*>(
            argv, argc, Klass::utf8_klass,
            [](char *v){
                return InstanceString(v);
            }),
        heap
    );
    // @TODO pack arguments
    Interpreter::interpret_func(this->heap, main_function, &args_in_tea);
    return 0;
}