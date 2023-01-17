

//#define RSGHOST_DEBUG
//#define wrap_u2_DEBUG
//#define wrap_u4_DEBUG
#define make_u4_DEBUG

#ifdef RSGHOST_DEBUG
#include <iostream>
#include "src/share/types/tstring.hpp"

int main(){
    using namespace std;
    String::String a = String::utils::getEmpty();
    String::utils a_util;
    a_util._import(&a);
    a_util.getLength();
    a_util.edit("");

}
#endif

#ifdef wrap_u2_DEBUG
#include "stdio.h"
#include "types/bytes.hpp"
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
#include "types/BytesUtils.hpp"
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