//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_RUN_CMDPARSER_HPP
#define $TVM_SRC_SHARE_RUN_CMDPARSER_HPP

enum CMD_TYPE{
    CMDT_HELPMSG, CMDT_UNKNOWN, CMDT_VERSION,
    CMDT_RECOMPILE
};

class CMDParser {
public:
    int codefile_count;
    char ** main_codefile;
    char ** lib_names;
    char ** lib_paths;

    bool recompile;
    CMDParser(int argc, char ** argv);

    static enum CMD_TYPE decide_cmd_type(char * arg);
    static bool          is_a_cmd       (char * arg);
    static void          print_help     (          );
           void          parse_cmd      (int argc, char * argv[]);
           void          do_cmd         (char *single_arg);
};


#endif //$TVM_SRC_SHARE_RUN_CMDPARSER_HPP
