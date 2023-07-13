//
// Created by Administrator on 2023-07-06.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#ifndef $TEA_SRC_SHARE_CODEFILE_CODEFILEUTILS_HPP
#define $TEA_SRC_SHARE_CODEFILE_CODEFILEUTILS_HPP

#include <vector>
#include <stdio.h>

class CodeFileUtils {
public:
    static FILE *find_file(char *filename, std::vector<char *> *lib_paths);
};


#endif //$TEA_SRC_SHARE_CODEFILE_CODEFILEUTILS_HPP
