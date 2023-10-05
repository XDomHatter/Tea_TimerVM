//
// Created by Administrator on 2023-02-09.
//

#ifndef $TVM_SRC_SHARE_RUN_TIMERVM_HPP
#define $TVM_SRC_SHARE_RUN_TIMERVM_HPP

#include <run/CmdParser.hpp>
#include <utilities/STATUS.hpp>
#include <codefile/CodeFileObj.hpp>
#include <runtime/interpreter.hpp>
#include <vector>

class TimerVM {
private:
    int codefiles_count;
    std::vector<char *> *libpaths;
    std::vector<CodeFileObj *> *code_files;
    TFunction *main_function;
    TeaHeap *heap;

    VMStatus status;
    bool recompile;

public:
    static void initialize();
    CMDParser *parse_cmd(int argc, char *argv[]);
    void open_files(CMDParser *cmdParser);
    void parse_files();
    /// Create vm heap
    inline void create_heap() {
        this->heap = new TeaHeap();
    }
    /// Execute the main function
    int exec_main_func(int argc, char **argv);
    /// Get the loaded code file
    inline CodeFileObj *get_code_file(int index) const {
        return code_files->at(index);
    }
};


#endif //$TVM_SRC_SHARE_RUN_TIMERVM_HPP
