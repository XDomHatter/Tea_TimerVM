#include <run/TimerVM.hpp>

int main(int argc, char *argv[]) {
    TimerVM::initialize();
    var *vm = new TimerVM();

    CMDParser *cmd_parser = vm->parse_cmd(argc, argv);
    vm->open_files(cmd_parser);
    vm->parse_files();
    vm->create_heap();
    vm->exec_main_func(0, nullptr);

    delete vm;
    return 0;
}