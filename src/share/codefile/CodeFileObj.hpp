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
#include <list>

struct CodeFileObj {
private:
    u1 _status;
public:
    static const u1 VERIFY_MAGIC    = 1;
    static const u1 STATUS_READEDCP = 2;
    static const u1 STATUS_READEDPK = 4;
    static const u1 STATUS_READGF   = 8;


    char                       *filename;
    TeaFileParser              *parser;
    ConstantPool               *cp;
    std::vector<CodeFileObj *> *packages;
    TeaVariableSet             *global_var;
    std::list<METHOD_FUNCTION_Constant *> *gf_infos;
    std::map<METHOD_FUNCTION_Constant, TFunction *> *gf_map;

    inline explicit CodeFileObj(char *filename = NULL) {
        this->_status     = 0;
        this->parser      = NULL;
        this->cp          = NULL;
        this->filename    = filename;
        this->packages    = NULL;
        this->global_var  = NULL;
        this->gf_infos    = NULL;
        this->gf_map      = NULL;
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
    /// Read global functions info
    inline void read_gf_info() {
        int count = parser->reader->nextU2();
        // every info is an u2, so guarantee count * 2 bytes
        parser->reader->guarantee_more(count * 2);
        this->gf_infos = parser->read_method_func_info(cp, count);
    }
    /// Determines whether there is a main function in the file
    bool has_main_func() const;
    /// read global function body
    void read_global_funcs();

    inline CodeFileObj *get_pkg(int index) const {
        return this->packages->at(index);
    }
    inline TFunction *get_gf_fast(METHOD_FUNCTION_Constant index) const {
        return this->gf_map->at(index);
    }
};


#endif //$TEA_SRC_SHARE_CODEFILE_CODEFILEOBJ_HPP
