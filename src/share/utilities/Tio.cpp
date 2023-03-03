//
// Created by Administrator on 2023-02-18.
//

#include "Tio.hpp"
#include <stdio.h>
#include <stdlib.h>

void TConsole::input(char *buf) {
    buf = {0};
    gets((char *)buf);
}
void TConsole::output(const char *str) {
    printf(str);
}
void TConsole::error(char *str) {
    output(str);
    exit(1);
}
void TConsole::print_version() {
    output("Tea_TimerVM v1.0.0 release");
}
void TConsole::error(const char *func, char *msg, char *paramerr) {
    output(func);
    output(": ");
    output(msg);
    output("\n");
    output("param error: ");
    output(paramerr);
    exit(0);
}
