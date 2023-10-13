//
// Created by Administrator on 2023-02-15.
//

#ifndef $TVM_SRC_SHARE_RUN_CMDPARSER_HPP
#define $TVM_SRC_SHARE_RUN_CMDPARSER_HPP

#include <vector>

enum CMD_TYPE {
    CMDT_HELPMSG, // print help message
    CMDT_VERSION, // print version message
    CMDT_RECOMPILE, // recompile but not run
    CMDT_LIBPATH, // add a library path for program
    CMDT_UNKNOWN, // unknown command
};

class CMDParser {
public:
    char *main_codefile;
    int libpath_count;
    std::vector<char *> *lib_paths;

    std::vector<char *> *usr_args;

    int argc;
    char **argv;

    bool recompile;
    CMDParser(int argc, char **argv);

    /// get type of arg ( now is -h -v -d )
    /// @param arg a single arg
    /// @return type of cmd
    static enum CMD_TYPE decide_cmd_type(char *arg);
    /// decide if 'arg' is a cmd
    /// @param arg a single arg
    /// @return if the arg is a command like '-h' '-v' etc.
    static bool is_a_cmd(char *arg);
    /// print help message
    static void print_help();

    /// parse cmd and do it
    /// @param argc count of arg
    /// @param argv value of arg
    void parse_cmd();

    /// do the specific operation for an single arg
    /// @param single_arg the param to parse
    /// @param i          the current index of 'argv' ( usually in foreach )
    void do_cmd(int *i);
};


#endif //$TVM_SRC_SHARE_RUN_CMDPARSER_HPP
