#include "stdio.h"
#include "Stack.h"

int main(int argc, char *argv[]) {
    
    puts("developing");
    puts("test");
    Stack_u4 stackU4(3);
    stackU4.push(1);
    stackU4.push(2);
    stackU4.pop();
    stackU4.push(4);
    stackU4.push(3);

    u4 _u = stackU4.pop();
    u4 __u = stackU4.pop();
    u4 ___u = stackU4.pop();
    printf("%d%d%d", _u, __u, ___u);

    return 0;
}
