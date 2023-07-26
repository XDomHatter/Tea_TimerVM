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
#include <vector>

struct CodeFileObj {
private:
    u1 _status;
public:
    static const u1 VERIFY_MAGIC    = 1;
    static const u1 STATUS_READEDCP = 2;
    static const u1 STATUS_READEDPK = 4;

    char          *filename;
    TeaFileParser *parser;
    ConstantPool  *cp;
    std::vector<CodeFileObj *> *packages;
    TeaVariableSet *global_var;

    inline CodeFileObj(char *filename = NULL) {
        this->_status     = 0;
        this->parser      = NULL;
        this->cp          = NULL;
        this->filename    = filename;
        this->packages    = NULL;
        this->global_var  = NULL;
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

    /// check magic number
    inline void check_mg() {
        if(!parser->check_magic()) {
            // it is not a tea codefile
            TConsole::output_m("fatal error: file \'", filename, "\' isn't a codefile!",
                               NULL);
            QUIT(1);
        }
        set_status(VERIFY_MAGIC);
    }
    /// read information
    inline void read_inf() const {
        parser->read_inf();
    }
    /// read constant pool
    inline void read_cp() {
        this->cp = parser->read_cp();
        this->set_status(STATUS_READEDCP);
    }
    /// read packages
    void read_pk(std::vector<char *> *lib_paths);
    /// read global variables
    inline void read_gv() {
        int count = parser->reader->nextU2();
        this->global_var = new TeaVariableSet(count);
    }

    inline CodeFileObj *get_pkg(int index) const {
        return this->packages->at(index);
    }
};


#endif //$TEA_SRC_SHARE_CODEFILE_CODEFILEOBJ_HPP
