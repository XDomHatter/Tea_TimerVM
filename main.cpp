#include "stdio.h"
#include "Stack.h"

#define RSGHOST_DEBUG

#ifdef RSGHOST_DEBUG
#include <iostream>
#include "src/share/types/tstring.hpp"

int main(){

}
#else
int main(int argc, char *argv[]) {
    
    puts("developing");
    puts("test");
    u2 inp;
    scanf("%x", &inp);
    inp = swap_u2(inp);
    printf("%x", inp);

    return 0;
}
#endif