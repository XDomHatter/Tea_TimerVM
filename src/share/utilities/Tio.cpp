//
// Created by Administrator on 2023-02-18.
//

#include "Tio.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <asm/Memory.hpp>
#include <utilities/cstr_utils.hpp>
#include <utilities/macros.hpp> // for QUIT()


void TConsole::input(char *buf) {
    char c;
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
}

void TConsole::output_f(char *str, ...) {
    va_list args;
    va_start(args, str);
    int o_ttl = CSTRUtil::len(str) + 1;
    char *o = Memory::alloc_mem<char>(o_ttl);
    o[0] = '\0';
    int o_cur = 0;

    while(*str != '\0') {
        if(*str == '%') {
            printf("%s", o);
            Memory::set_mem((pointer) o, 0, o_ttl);
            o_cur = 0;
            
            switch (*(++str)) {
                case 's': {
                    char *s = va_arg(args, char *);
                    printf("%s", s);
                    break;
                }
                case 'd': {
                    int d = va_arg(args, int);
                    printf("%d", d);
                    break;
                }
                case 'x': {
                    // u1 and u2 will be promoted to u4
                    u4 _u4 = va_arg(args, u4);
                    printf("%x", _u4);
                    break;
                }
                case 'l': {
                    if(*(str + 1) == 'x') {
                        // print u8 hex
                        u8 _u8 = va_arg(args, u8);
                        printf("%llx", _u8);
                        str++;
                        break;
                    }
                }
                default: {
                    error("Unknown format");
                }
            }
        } else {
            sprintf(o+(o_cur++), "%c", *str);
        }
        str ++;
    }
    if(o_cur != 0) {
        printf("%s", o);
    }
    Memory::free_mem(o);
}

void TConsole::error(char *str) {
    output(str);
    QUIT(1);
}

void TConsole::print_version() {
    output("Tea_TimerVM v1.0.0 release\n");
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
