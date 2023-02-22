//
// Created by Administrator on 2023-02-18.
//

#ifndef $TVM_SRC_SHARE_UTILITIES_TIO_HPP
#define $TVM_SRC_SHARE_UTILITIES_TIO_HPP

// only support english
class TConsole {
public:
    static void output(char * str); // print a line(without new line) to stdout
    static void input(char * buf);  // read a line from stdin
    static void error(char * str);
    static void print_version();
};


#endif //$TVM_SRC_SHARE_UTILITIES_TIO_HPP
