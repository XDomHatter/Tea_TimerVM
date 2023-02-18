//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_RUN_CMDPARSER_HPP
#define $TVM_SRC_SHARE_RUN_CMDPARSER_HPP

enum CMD_TYPE{
    CMDT_HELPMSG, CMDT_UNKNOWN, CMDT_VERSION
};

class CMDParser {
public:
    char * main_codefile;
    char ** lib_names;
    char ** lib_paths;
    CMDParser(int argc, char ** argv);

    static enum CMD_TYPE cast_cmd_type(char * arg);
    static bool               is_a_cmd(char * arg);
    static void             print_help(          );
};


#endif //$TVM_SRC_SHARE_RUN_CMDPARSER_HPP
