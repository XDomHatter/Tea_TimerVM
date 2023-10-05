//
// Created by XDomHatter on 2023-08-30.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_INTERPRETER_HPP
#define $TEA_SRC_SHARE_RUNTIME_INTERPRETER_HPP

#include <runtime/teaFunction.hpp>
#include <runtime/heap.hpp>
#include <runtime/teaValue.hpp>

class Interpreter {
public:
    static void interpret_func(TeaHeap *heap, TFunction *func, TeaValue *args);
};

#endif //$TEA_SRC_SHARE_RUNTIME_INTERPRETER_HPP
