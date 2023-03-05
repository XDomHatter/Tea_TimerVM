//
// Created by Administrator on 2023-02-18.
//

#ifndef $TVM_SRC_SHARE_UTILITIES_TIO_HPP
#define $TVM_SRC_SHARE_UTILITIES_TIO_HPP

// only support english
class TConsole {
public:
    static void output(const char *str); // print a string(without new line) to stdout
    static void input(char *buf);  // read a line from stdin
    static void error(char *str);

    /// print a error message and quit
    /// @param func the function where the error appear
    /// @param msg error message
    /// @param paramerr the error that the param created
    static void error(const char *func, char *msg, char *paramerr);

    static void print_version();
};


#endif //$TVM_SRC_SHARE_UTILITIES_TIO_HPP
