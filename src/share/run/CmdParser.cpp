//
// Created by Administrator on 2023-02-15.
//

#include "CmdParser.hpp"
#include <utilities/file_macros.hpp>
#include <utilities/cstr_utils.hpp>
#include <utilities/Tio.hpp>
#include <utilities/macros.hpp>

CMDParser::CMDParser(int argc, char **argv) {
    switch (argc) {
        case 1:
            // print help messeges
            goto PRT_HPMSG;
            break;
        case 2:
            if(is_a_cmd(argv[1])){
                switch (cast_cmd_type(argv[1])) {
                    case CMDT_HELPMSG:
                    PRT_HPMSG:
                        print_help();
                        break;
                    case CMDT_UNKNOWN:
                        TIO::output("unknown command :");
                        TIO::output(argv[1]);
                        break;
                    case CMDT_VERSION:
                        TIO::output("Tea_TimerVM v1.0.0");
                }
            } else {
                // try to find the file
                FILE * file = fopen(argv[1], "r+");
                if( file == NULL ) { // file doesn't exists
                    TIO::output("cannot find file:");
                    TIO::output(argv[1]);
                    exit(0);
                }

            }
    }
}

bool CMDParser::is_a_cmd(char *arg) {
    return (arg[0] == '-');
}
enum CMD_TYPE CMDParser::cast_cmd_type(char *arg) {
    if(cstr_EQUAL(arg, "-h") || cstr_EQUAL(arg, "-H")){
        // help message
        return CMDT_HELPMSG;
    } else if(cstr_EQUAL(arg, "-v") || cstr_EQUAL(arg, "-V")){
        return CMDT_VERSION;
    } else {
        return CMDT_UNKNOWN;
    }
}

void CMDParser::print_help() {
    TIO::output("help message");
}
