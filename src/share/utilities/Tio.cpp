//
// Created by Administrator on 2023-02-18.
//

#include "Tio.hpp"
#include <stdio.h>

void TIO::input(void *buf) {
    gets((char *)buf);
}
void TIO::output(char *str) {
    printf(str);
}