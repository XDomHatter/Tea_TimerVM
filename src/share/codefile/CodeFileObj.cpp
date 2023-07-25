//
// Created by Administrator on 2023-07-05.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#include "CodeFileObj.hpp"
#include <codefile/CodeFileUtils.hpp>

void CodeFileObj::read_pk(std::vector<char *> *lib_paths) {
    int count = parser->reader->nextU2_fast();
    var l = parser->read_pk_names(count, this->cp);
    if (l == NULL) return;
    var r = new std::vector<CodeFileObj *>();
    CodeFileObj *itCFO = NULL;
    char *i = NULL;
    for(int j = 0; j < count; j++) {
        i = l[j];
        itCFO = new CodeFileObj();
        FILE *f =CodeFileUtils::find_file(i, lib_paths);

        if(f == NULL) TConsole::error(CSTRUtil::cat("cannot find file: ", i));
        itCFO->parser = new TeaFileParser(
                new TeaFileReader(f)
        );

        itCFO->check_mg();
        itCFO->read_inf();
        itCFO->read_cp();
        itCFO->read_pk(lib_paths);
        r->push_back(itCFO);
    }
    this->packages = r;
    set_status(STATUS_READEDPK);
}

void CodeFileObj::read_gv() {

}