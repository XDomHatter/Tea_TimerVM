//
// Created by Administrator on 2023-02-18.
//

#ifndef $TVM_SRC_SHARE_UTILITIES_TIO_HPP
#define $TVM_SRC_SHARE_UTILITIES_TIO_HPP

// only support english
class TConsole {
public:
    /// print str in stdout
    /// @param str c string for output
    static void output(char *str);
    /// print str in stdout, but it can receive more params.
    /// !NOTICE! make the last param be NULL so the method will end, or it will go wrong.
    /// @param n strings count
    /// @param str c string for output
    static void output_m(char *str, ...);
    /// print str in stdout, with format like `printf`
    /// @param str format string
    /// @param ... format params
    static void output_f(char *str, ...);
    /// read a line from stdin
    /// @param buf buffer to store c string
    static void input(char *buf);
    /// print an error message and quit
    /// @param str error message
    static void error(char *str);

    /// print a error message and quit
    /// @param func the function where the error appear
    /// @param msg error message
    /// @param paramerr the error that the param created
    static void error(char *func, char *msg, char *paramerr);

    static void print_version();
};


#endif //$TVM_SRC_SHARE_UTILITIES_TIO_HPP
