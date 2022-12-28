//
// Created by Administrator on 2022-12-26.
//

#include "Stack.h"
#include "malloc.h"

Stack_u4::Stack_u4(int max_stack_size) {
    this->start_address = (u4 *) malloc(
            ((size_t) max_stack_size) * 4
    );
    this->current = this->start_address;
    this->max_stack_size = max_stack_size;
    this->current_size = 0;
}
Stack_u4::~Stack_u4() {
    free(this->start_address);
}
u4 Stack_u4::push(u4 data) {
    *(this->current) = data;
    this->current ++       ; //next u4
    this->current_size ++  ;
    if(this->current_size == this->max_stack_size){
        this->full = true;
    }
    return data;
}
u4 Stack_u4::pop() {
    this->current_size--;
    return *(--this->current);
}
