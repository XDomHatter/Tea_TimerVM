#define DEBUG

//#define wrap_u2_DEBUG
//#define wrap_u4_DEBUG
//#define make_u4_DEBUG
//#define make_u2_DEBUG
//#define TFloat_DEBUG
//#define make_u8_DEBUG
//#define wrap_u8_DEBUG
#define ENDIAN_DEBUG

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
#include "asm/Endian.hpp"
int main(){
    u2 test_data = 0x1234;
    u1 * test_ptr = (u1*)&test_data;
    EENDIAN endian = ((*(test_ptr) == 0x12) ? EBIG_ENDIAN : ELITTlE_ENDIAN);
    puts(((endian == EBIG_ENDIAN) ? "BIG" : "LITTLE"));
}
#endif