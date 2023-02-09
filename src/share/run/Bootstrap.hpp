//
// Created by Administrator on 2023-02-09.
//

#ifndef $TVM_SRC_SHARE_RUN_BOOTSTRAP_HPP
#define $TVM_SRC_SHARE_RUN_BOOTSTRAP_HPP

#include <stdio.h>

// Bootstrap is for load and check code file
class Bootstrap {
private:
    FILE * code_file;
public:
    Bootstrap(char * filename);
};


#endif //$TVM_SRC_SHARE_RUN_BOOTSTRAP_HPP
