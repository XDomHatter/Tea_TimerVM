//
// Created by Administrator on 2023-02-15.
//

#include "CmdParser.hpp"
#include <utilities/cstr_utils.hpp>
#include <utilities/Tio.hpp>

CMDParser::CMDParser(int argc, char **argv) {
    switch (argc) {
        case 1:
            // print help messeges
            break;
        case 2:
            if(is_a_cmd(argv[1])){
                switch (cast_cmd_type(argv[1])) {
                    case HELPMSG:
                        TIO::output("help message");
                }

            }
    }
}

bool CMDParser::is_a_cmd(char *arg) {
    return (arg[0] == '-');
}
enum CMD_TYPE CMDParser::cast_cmd_type(char *arg) {
    if(cstr_EQUAL(arg, "-h")){
        // help message
        return HELPMSG;
    }
}
