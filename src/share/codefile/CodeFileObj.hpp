//
// Created by Administrator on 2023-06-11.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#ifndef $TEA_SRC_SHARE_CODEFILE_CODEFILEOBJ_HPP
#define $TEA_SRC_SHARE_CODEFILE_CODEFILEOBJ_HPP


#include <codefile/TeaFileParser.hpp>
#include <oop/ConstantPool.hpp>

struct CodeFileObj {
public:
    TeaFileParser *parser;
    ConstantPool  *cp;
};


#endif //$TEA_SRC_SHARE_CODEFILE_CODEFILEOBJ_HPP
