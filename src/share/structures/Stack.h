//
// Created by Administrator on 2022-12-26.
//

#ifndef TVM_1_0_STACK_H
#define TVM_1_0_STACK_H

#include "types.h" //for u1,u2,u4

class Stack_u4 {
private:
    u4 * start_address; // the start address of stack
    u4 * current      ; // current address
    int max_stack_size; // the datas' num !not data's size!'
    int current_size  ;

public:
    bool full         ;
    Stack_u4 (int max_stack_size);
    u4 push  (u4 data)           ;
    u4 pop   (void   )           ;
    ~Stack_u4(       )           ;
};

class Stack_u2 {
private:
    u2 * start_address; // the start address of stack
    u2 * current      ; // current address
    int max_stack_size; // the datas' num !not data's size!'
    int current_size  ;
public:
    bool full         ;
    Stack_u2 (int max_stack_size);
    u2 push  (u2 data)           ;
    u2 pop   (void   )           ;
    ~Stack_u2(       )           ;
};


#endif //TVM_1_0_STACK_H
