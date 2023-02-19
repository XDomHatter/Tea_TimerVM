//
// Created by Administrator on 2023-02-18.
//

#include "Tio.hpp"
#include <stdio.h>
#include <stdlib.h>

void TIO::input(char *buf) {
    buf = {0};
    gets((char *)buf);
}
void TIO::output(char *str) {
    printf(str);
}
void TIO::error(char *str) {
    output(str);
    exit(1);
}
