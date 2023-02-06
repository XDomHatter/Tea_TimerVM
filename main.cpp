//#define wrap_u2_DEBUG
//#define wrap_u4_DEBUG
//#define make_u4_DEBUG
//#define make_u2_DEBUG
#define TFloat_DEBUG

#ifdef wrap_u2_DEBUG
#include "stdio.h"
#include "asm/BytesUtils.hpp"
#include "asm/Endian.hpp"
int main(int argc, char *argv[]) {
    
    puts("developing");
    puts("test");
    u2 inp;
    scanf("%x", &inp);
    inp = wrap_u2(inp);
    printf("%x", inp);

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
    inp = Endian::wrap_u4(inp);
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
    u8 u = 0x0000000110000000;
    TFloat f(ELITTlE_ENDIAN);
    f.set(u);
    printf("%f", f.get_cvalue());
}
#endif