//
// Created by Administrator on 2023-02-18.
//

#include "Tio.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <utilities/macros.hpp> // for QUIT()

void TConsole::input(char *buf) {
    char c = 0;
    int  i = 0;
    while((c = getc(stdin)) != '\n'){
        buf[i] = c;
        i++;
    }
}

void TConsole::output(char *str) {
    if(str == NULL) return;
    char * ptr = str;
    while(*ptr != '\0') {
        putchar(*ptr);
        ptr++;
    }
}

void TConsole::output_m(char *str, ...) {
    output(str);
    va_list ap;
    va_start(ap, str);
    char * sto; // string to output
    for(;;) {
        sto = va_arg(ap, char *);
        if(sto == NULL) break;
        output(sto);
    }
    va_end(ap);

    return;
}

void TConsole::error(char *str) {
    output(str);
    QUIT(1);
}

void TConsole::print_version() {
    output("Tea_TimerVM v1.0.0 release");
}

void TConsole::error(char *func, char *msg, char *paramerr) {
    output(func);
    output(": ");
    output(msg);
    output("\n");
    output("param error: ");
    output(paramerr);
    exit(0);
}
