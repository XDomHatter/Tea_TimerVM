//
// Created by Administrator on 2023-07-06.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#include "CodeFileUtils.hpp"
#include <asm/Memory.hpp>
#include <utilities/cstr_utils.hpp>
#include <utilities/file_macros.hpp>
#include <utilities/macros.hpp>

FILE *CodeFileUtils::find_file(char *filename, std::vector<char *> *lib_paths) {
    WINDOWS_ONLY(
        char *filename_fmt = CSTRUtil::replace(filename, "/", PATH_SEPARATOR);
    );
    char *full_path = NULL;
    char *may_full_path = NULL;
    FILE *f = NULL;
    for (char *i : *lib_paths) {
        full_path = CSTRUtil::cat(i, PATH_SEPARATOR, filename_fmt, NULL);
        f = fopen(full_path, "rb+");
        if (f != NULL) {
            Memory::free_mem(full_path);
            return f;
        } else {
            may_full_path = CSTRUtil::cat(full_path, ".tc");
            f = fopen(may_full_path, "rb+");
            if (f != NULL) {
                Memory::free_mem(full_path);
                Memory::free_mem(may_full_path);
                return f;
            }
        }
        Memory::free_mem(full_path);
        Memory::free_mem(may_full_path);
        Memory::free_mem(filename_fmt);
    }
    return NULL;
}
