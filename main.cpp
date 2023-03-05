#define DEBUG

//#define wrap_u2_DEBUG
//#define wrap_u4_DEBUG
//#define make_u4_DEBUG
//#define make_u2_DEBUG
//#define TFloat_DEBUG
//#define make_u8_DEBUG
//#define wrap_u8_DEBUG
//#define ENDIAN_DEBUG
//#define TFR_readU2_DEBUG
//#define TFR_readU4_DEBUG
//#define TFR_readU8_DEBUG
//#define CSTR_EQUAL_DEBUG
//#define TIO_DEBUG
//#define CMDParser_DEBUG
//#define CINT2CSTR_DEBUG
//#define BITMAP_DEBUG
//#define CMAKE_DEBUG
#define STRLEN_DEBUG

#ifdef DEBUG

#ifdef wrap_u2_DEBUG
#include "stdio.h"
#include "asm/BytesUtils.hpp"
int main(int argc, char *argv[]) {
    
    puts("developing");
    puts("test");
    u2 inp;
    scanf("%x", &inp);
    inp = ByteUtils::wrap_u2(inp);
    printf("%#x", inp);

    return 0;
}
#endif
#ifdef wrap_u4_DEBUG
#include "stdio.h"
#include "structures/Stack.hpp"
#include "asm/Endian.hpp"
int main(int argc, char *argv[]) {
    
    puts("developing");
    puts("test");
    u4 inp;
    scanf("%x", &inp);
    inp = ByteUtils::wrap_u4(inp);
    printf("%x", inp);

    return 0;
}
#endif
#ifdef make_u4_DEBUG
#include "stdio.h"
#include "structures/Stack.hpp"
#include "asm/BytesUtils.hpp"
#include "asm/Endian.hpp"
#include <iostream>
int main(int argc, char *argv[]) {
    
    puts("developing");
    puts("test");
    u1 src[4] = {};
    for(int i = 0; i<4; i++){
        scanf("%x", &src[i]);
    }
    u4 res = ByteUtils::make_u4(src);
    printf("%x", res);
    if(res == 0x12345678) puts("yes");
    return 0;
}
#endif
#ifdef make_u2_DEBUG
#include "stdio.h"
#include "structures/Stack.hpp"
int main(int argc, char *argv[]) {
    u1 src[2] = {};
    for(int i = 0; i<2; i++){
        scanf("%x", &src[i]);
    }
    u2 res = ByteUtils::make_u2(src);
    printf("%x", res);
    return 0;
}
#endif
#ifdef TFloat_DEBUG
#include "stdio.h"
#include "oop/TFloat.hpp"
int main(int argc, char *argv[]) {
    double d = 12.34;
    TFloat f(ELITTlE_ENDIAN);
    f.set(d);
    printf("%f", f.get_cvalue());

}
#endif
#ifdef make_u8_DEBUG
#include "stdio.h"
#include "structures/Stack.hpp"
int main(int argc, char *argv[]) {

    puts("developing");
    puts("test");
    u1 src[8] = {};
    for(int i = 0; i<8; i++){
        scanf("%x", &src[i]);
    }
    u8 res = ByteUtils::make_u8(src);
    printf("%x%x", (res>>32),res); //%x cannot format byte which width >= u4

    return 0;
}
#endif
#ifdef wrap_u8_DEBUG
#include "stdio.h"
#include "structures/Stack.hpp"
int main(int argc, char *argv[]) {

    puts("developing");
    puts("test");
    u8 inp = 0x1234567890ABCDEF;
    inp = ByteUtils::wrap_u8(inp);
    printf("%x%x", (inp>>32),inp); //%x cannot format byte which width >= u4

    return 0;
}
#endif
#ifdef ENDIAN_DEBUG
#include <stdio.h>
#include <asm/Endian.hpp>
int main(){
    u2 test_data = 0x1234;
    u1 * test_ptr = (u1*)&test_data;
    EENDIAN endian = ((*(test_ptr) == 0x12) ? EBIG_ENDIAN : ELITTlE_ENDIAN);
    puts(((endian == EBIG_ENDIAN) ? "BIG" : "LITTLE"));
}
#endif
#ifdef TFR_readU2_DEBUG
#include <codefile/TeaFileReader.hpp>

int main(){
    FILE * file = fopen("test.tc", "r+");
    TeaFileReader tfr(file, ELITTlE_ENDIAN);
    u2 u = tfr.readU2();
    switch (u) {
        case 0x1234:
            puts("0x1234");
        case 0x3412:
            puts("0x3412");
    };
    if(u == 0x1234) puts("yes");
    return 0;
}
#endif
#ifdef TFR_readU4_DEBUG
#include <codefile/TeaFileReader.hpp>

int main(){
    FILE * file = fopen("test.tc", "r+");
    TeaFileReader tfr(file, ELITTlE_ENDIAN);
    u4 u = tfr.readU4();
    printf("%x",u);
    if(u == 0x12345678) puts("yes");
    return 0;
}
#endif
#ifdef TFR_readU8_DEBUG
#include <codefile/TeaFileReader.hpp>

int main(){
    FILE * file = fopen("test.tc", "r+");
    TeaFileReader tfr(file, ELITTlE_ENDIAN);
    u8 u = tfr.readU8();
    printf("%x%x",u>>32,u&0x00000000FFFFFFFF);
    if(u == 0x1234567889901112) puts("yes");
    return 0;
}
#endif
#ifdef CSTR_EQUAL_DEBUG
#include <stdio.h>
#include <utilities/cstr_utils.hpp>
int main(){
    if (cstr_EQUAL((const char *)"114514", (const char *)"114514")) {
        puts("1");
    } else {
        puts("0");
    }
}
#endif
#ifdef TIO_DEBUG
#include <utilities/Tio.hpp>
int main(){
    char buff[100];
    TConsole::input(buff);
    TConsole::output(buff);
    return 0;
}
#endif

#endif

#ifdef CMDParser_DEBUG
#include <run/TimerVM.hpp>

int main(int argc, char * argv[]){
    CMDParser parser(argc, argv);
    printf(parser.lib_paths[0]);
    return 0;
}
#endif
#ifdef CINT2CSTR_DEBUG
#include <utilities/cint_utils.hpp>
#include <iostream>

int main(){
    int n; std::cin >> n;
    std::cout << cint2cstr(n);
}
#endif
#ifdef BITMAP_DEBUG

#include <utilities/Tio.hpp>
#include <structures/BitMap.hpp>
#include <utilities/cint_utils.hpp>

int main(){
    BitMap map(12);
    map.set(11, 1);
    char res = map.get(11);
    TConsole::output(cint2cstr(res));
}
#endif
#ifdef CMAKE_DEBUG

#include <MacroAssembler_x86.hpp>
int main(){}
#endif

#ifdef STRLEN_DEBUG

#include <stdio.h>
#include <string.h>

int main(){
    char a[] = "1234567";
    printf("%d", strlen(a));
    return 0;
}
#endif


#ifndef DEBUG
#include <run/TimerVM.hpp>

int main(int argc, char * argv[]){
    TimerVM vm(argc, argv);
    return 0;
}
#endif