//
// Created by Administrator on 2023-07-05.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#include "CodeFileObj.hpp"
#include <codefile/CodeFileUtils.hpp>
#include <algorithm>

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
        if(f == NULL) {
            TConsole::output_f("cannot find file: %s", i);
            QUIT(1);
        }
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

bool CodeFileObj::has_main_func() const {
    return std::any_of(gf_infos->begin(), gf_infos->end(), [](METHOD_FUNCTION_Constant *i) -> bool {
        return (
            i->pkg_idx == 0                                                         &&
            i->name->       equal(UTF8_Constant(5, (u1 *)"main")) &&
            i->param_types->equal(UTF8_Constant(3, (u1 *)"[U"  )) &&
            i->result_type->equal(UTF8_Constant(2, (u1 *)"4"   ))
        );
    });
}
void CodeFileObj::read_global_funcs() {
    gf_map = parser->read_method_func(gf_infos, cp);
    set_status(STATUS_READGF);
}