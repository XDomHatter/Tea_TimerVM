//
// Created by Administrator on 2022-12-26.
//

#ifndef $TVM_SRC_SHARE_STRUCTURES_STACK_HPP
#define $TVM_SRC_SHARE_STRUCTURES_STACK_HPP

#include <asm/BytesUtils.hpp> //for u1,u2,u4

class Stack {
public:
    virtual void push1(u1 value) = 0;
    virtual void push2(u2 value) = 0;
    virtual void push4(u4 value) = 0;
    virtual void push8(u8 value) = 0;
    virtual u1 pop1() = 0;
    virtual u2 pop2() = 0;
    virtual u4 pop4() = 0;
    virtual u8 pop8() = 0;
};

class Stack_u4 : public Stack{
private:
    u4 * start_address; // the start address of stack
    u4 * current      ; // current address
    int max_stack_size; // the datas' num !not data's size!'
    int current_size  ;
    bool full;

public:
    explicit Stack_u4(int max_stack_size);
    ~Stack_u4();
    inline void check_full() {
        if(this->current_size == this->max_stack_size){
            this->full = true;
        }
    }
    inline bool is_full() const {
        return this->full;
    }
    void push1(u1 value) override;
    void push2(u2 value) override;
    void push4(u4 value) override;
    void push8(u8 value) override;
    u1 pop1() override;
    u2 pop2() override;
    u4 pop4() override;
    u8 pop8() override;
};

class Stack_u2 : public Stack {
private:
    u2 * start_address; // the start address of stack
    u2 * current      ; // current address
    int max_stack_size; // the datas' num !not data's size!'
    int current_size  ;
    bool full;

public:
    Stack_u2(int max_stack_size);
    ~Stack_u2();
    inline void check_full() {
        if(this->current_size == this->max_stack_size){
            this->full = true;
        }
    }
    inline bool is_full() const {
        return this->full;
    }
    void push1(u1 value) override;
    void push2(u2 value) override;
    void push4(u4 value) override;
    void push8(u8 value) override;
    u1 pop1() override;
    u2 pop2() override;
    u4 pop4() override;
    u8 pop8() override;
};


#endif //$TVM_SRC_SHARE_STRUCTURES_STACK_HPP
