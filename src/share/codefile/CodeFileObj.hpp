//
// Created by Administrator on 2023-06-11.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#ifndef $TEA_SRC_SHARE_CODEFILE_CODEFILEOBJ_HPP
#define $TEA_SRC_SHARE_CODEFILE_CODEFILEOBJ_HPP

#include <codefile/TeaFileParser.hpp>
#include <oop/ConstantPool.hpp>
#include <utilities/Tio.hpp>
#include <utilities/cstr_utils.hpp>

struct CodeFileObj {
private:
    u1 _status;
public:
    static const u1 STATUS_READEDCP = 1;
    static const u1 STATUS_READEDPK = 2;

    TeaFileParser *parser;
    ConstantPool  *cp;

    inline CodeFileObj() {
        this->_status = 0;
        this->parser = NULL;
        this->cp     = NULL;
    }

    inline void set_status(u1 status) {
        if(status_have(status)) {
            TConsole::output_f("Already setted status: %d", status);
            QUIT(1);
        }
        this->_status += status;
    }
    inline bool status_have(u1 status) const {
        return _status & status;
    }
};


#endif //$TEA_SRC_SHARE_CODEFILE_CODEFILEOBJ_HPP
