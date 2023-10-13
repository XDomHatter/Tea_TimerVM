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
    // package files
    char *codefile_name = cmdParser->main_codefile;
    this->code_file = NULL;

    if(codefile_name != NULL) {
        TeaFileParser * main_tfp;
        FILE          * main_fo;
        CodeFileObj   * main_cfo;

        main_fo = fopen(codefile_name, "rb");
        if(main_fo == NULL) {
            // cannot open file
            TConsole::output_f("fatal error: cannot open file \'%s\'", codefile_name);
            QUIT(1);
        }
        // file exists, create Parser object
        main_tfp = new TeaFileParser(
                new TeaFileReader(main_fo)
        );

        main_cfo = new CodeFileObj();
        main_cfo->parser = main_tfp;
        main_cfo->filename = codefile_name;
        this->code_file = main_cfo;
    } else {
        QUIT(0);
    }
}

void TimerVM::parse_files() {
    int length = codefiles_count;
    TFunction *main_func = NULL;

    // check file
    code_file->check_mg();
    // read information
    code_file->read_inf();
    // read constant pool
    code_file->read_cp();
    // read packages map
    code_file->read_pk(libpaths);
    // read global variable
    code_file->read_gv();
    // read global functions info
    code_file->read_gf_info();
    if (code_file->has_main_func()) {
        if (main_func != NULL) {
            // there's already a main function
            TConsole::error("Multiple main functions found. \n");
        }
        code_file->read_global_funcs();
        main_func = code_file->get_gf_fast(METHOD_FUNCTION_Constant::main_func_cst());
    }
    if (main_func == NULL) {
        QUIT(0);
    }
    this->main_function = main_func;
}

int TimerVM::exec_main_func(int argc, char **argv) {
    TeaValue args_in_tea = TeaValue::create_by_oop(
        InstanceArray::package_values<char*>(
            argv, argc, Klass::utf8_klass,
            [](char *v) -> InstanceOOP *{
                return new InstanceString(v);
            }),
        heap
    );
    Interpreter::interpret_func(this->heap, main_function, &args_in_tea);
    return 0;
}