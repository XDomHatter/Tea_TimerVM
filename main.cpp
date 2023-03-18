#include <run/TimerVM.hpp>

int main(int argc, char * argv[]){
    TimerVM * vm = new TimerVM(argc, argv);

    delete vm;
    return 0;
}