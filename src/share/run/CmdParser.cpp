//
// Created by Administrator on 2023-02-15.
//

#include "CmdParser.hpp"
#include <utilities/file_macros.hpp>
#include <utilities/cstr_utils.hpp>
#include <utilities/Tio.hpp>
#include <utilities/macros.hpp>

CMDParser::CMDParser(int argc, char **argv) {
    // init
    this->recompile = false;
    this->main_codefile = NULL;
    this->lib_names     = NULL;
    this->lib_paths     = NULL;

    parse_cmd(argc, argv);
}

/// decide if 'arg' is a cmd
/// @param arg a single arg
/// @return if the arg is a command like '-h' '-v' etc.
bool CMDParser::is_a_cmd(char *arg) {
    return (arg[0] == '-');
}
/// get type of arg ( now is -h -v -d )
/// @param arg a single arg
/// @return type of cmd
enum CMD_TYPE CMDParser::decide_cmd_type(char *arg) {
    if        (cstr_EQUAL(arg, "-h") || cstr_EQUAL(arg, "-H")) {
        // help message
        return CMDT_HELPMSG;
    } else if (cstr_EQUAL(arg, "-v") || cstr_EQUAL(arg, "-V")) {
        return CMDT_VERSION;
    } else if (cstr_EQUAL(arg, "-d") || cstr_EQUAL(arg, "-D")) {
        return CMDT_RECOMPILE;
    } else {
        return CMDT_UNKNOWN;
    }
}
/// parse cmd and do it
/// @param argc count of arg
/// @param argv value of arg
void CMDParser::parse_cmd(int argc, char * argv[]) {
    switch (argc) {
        case 1:
            print_help();
            break;
        case 2:
            do_cmd(argv[1]);
            break;
        default:
            // foreach in arguments array
            for(int i = 0; i < argc; i++){
                do_cmd(argv[i]);
            }
            break;
    }
}
/// print help message
void CMDParser::print_help() {
    TConsole::output("help message");
}
/// do the match operation of single_arg
/// @param single_arg the param to parse
void CMDParser::do_cmd(char * single_arg) {
    if(is_a_cmd(single_arg)){
        switch (decide_cmd_type(single_arg)) {
            case CMDT_HELPMSG:
                print_help();
                exit(0);
                break;
            case CMDT_RECOMPILE:
                this->recompile = true;
                break;
            case CMDT_UNKNOWN:
                TConsole::output("unkown command: ");
                TConsole::output(single_arg);
                exit(1);
                break;
            case CMDT_VERSION:
                TConsole::print_version();
                exit(0);
                break;
        }
    } else {
        // try to find the file
        FILE * file = fopen(single_arg, "r+");
        if( file == NULL ) { // file doesn't exists
            TConsole::output("cannot find file:");
            TConsole::output(single_arg);
            exit(0);
        }
        // file is correct, go on

        this->main_codefile[this->codefile_count] = single_arg;
        this->codefile_count ++;
    }
}

