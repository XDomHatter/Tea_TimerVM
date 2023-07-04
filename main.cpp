#include <run/TimerVM.hpp>

int main(int argc, char * argv[]){
    var * vm = new TimerVM();

    CMDParser *cmd_parser = vm->parse_cmd(argc, argv);
    vm->open_files(cmd_parser);
    vm->parse_files(cmd_parser);

    delete vm;
    return 0;
}