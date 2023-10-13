//
// Created by Administrator on 2023-02-15.
//

#include "CmdParser.hpp"
#include <utilities/cstr_utils.hpp>
#include <utilities/Tio.hpp>
#include <utilities/macros.hpp>

CMDParser::CMDParser(int argc, char **argv) {
    // init
    this->recompile = false;
    this->main_codefile = NULL;
    this->lib_paths = new std::vector<char *>();
    this->libpath_count = 0;
    this->usr_args = new std::vector<char *>();
    this->argc = argc;
    this->argv = argv;

    parse_cmd();
}

bool CMDParser::is_a_cmd(char *arg) {
    return (arg[0] == '-');
}

enum CMD_TYPE CMDParser::decide_cmd_type(char *arg) {
    if (cstr_EQUAL(arg, "-h") || cstr_EQUAL(arg, "-H")) {
        return CMDT_HELPMSG;
    } else if (cstr_EQUAL(arg, "-v") || cstr_EQUAL(arg, "-V")) {
        return CMDT_VERSION;
    } else if (cstr_EQUAL(arg, "-d") || cstr_EQUAL(arg, "-D")) {
        return CMDT_RECOMPILE;
    } else if (cstr_EQUAL(arg, "-lp") || cstr_EQUAL(arg, "-LP")) {
        return CMDT_LIBPATH;
    } else {
        return CMDT_UNKNOWN;
    }
}

void CMDParser::parse_cmd() {
    switch (argc) {
        case 1:
            print_help();
            break;
        case 2:
            do_cmd(NULL);
            break;
        default:
            // foreach in arguments array
            int i = 1;
            for (; i < argc; i++) {
                do_cmd(&i);
            }
            break;
    }
}


void CMDParser::print_help() {
    char * msg =
        "Usage: tea [options] [source files] [args] \n"
        "Options:\n"
        "    -v           print version\n"
        "    -lp <path>   include a lib path\n"
        "    -h           print help message\n"
        ;
    TConsole::output(msg);
    QUIT(0);
}


void CMDParser::do_cmd(int *i) {
    char *single_arg; // the arg to parse
    single_arg = this->argv[
        ((i == NULL) ? 1 : (*i))
        // if i is NULL, use the first arg
        // or use the value of i
    ];
    if (is_a_cmd(single_arg)) {
        switch (decide_cmd_type(single_arg)) {
            case CMDT_HELPMSG:
                print_help();
                QUIT(0);
                break;
            case CMDT_RECOMPILE:
                this->recompile = true;
                break;
            case CMDT_VERSION:
                TConsole::print_version();
                QUIT(0);
                break;
            case CMDT_LIBPATH:
                // user call like: -lp "C:\\xxx\\"
                if (i == NULL) {
                    // not enough args
                    TConsole::error("Unenough args.");
                }
                (*i)++; // next arg ( after -lp )
                this->lib_paths->push_back(argv[*i]);
                this->libpath_count++;
                break;
            case CMDT_UNKNOWN:
                TConsole::output_f("unknown command: %s", single_arg);
                QUIT(1);
                break;
        }
    } else {
        this->main_codefile = single_arg;
        if (i == NULL) {
            return;
        }
        for((*i)++;*i < argc; (*i)++) {
            this->usr_args->push_back(argv[*i]);
        }
    }
}

