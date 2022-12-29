

//#define RSGHOST_DEBUG
#define swap_u2_DEBUG

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

#ifdef swap_u2_DEBUG
#include "stdio.h"
#include "Stack.h"
#include "bytes.hpp"
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