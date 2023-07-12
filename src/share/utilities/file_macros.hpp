//
// Created by Administrator on 2023-02-09.
//

#ifndef $TVM_SRC_SHARE_UTILITIES_FILE_MACROS_HPP
#define $TVM_SRC_SHARE_UTILITIES_FILE_MACROS_HPP

// path separator
// In Windows, it is '\'
// In Unix and Linux, it is '/'
#if defined(OS_WINDOWS)
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

#include <stdio.h>

#define FILE_SKIP(size, file) fgets(NULL, size, file);


#endif //$TVM_SRC_SHARE_UTILITIES_FILE_MACROS_HPP
