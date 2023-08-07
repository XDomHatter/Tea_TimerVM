//
// Created by Administrator on 2022-12-26.
//

#include "Stack.hpp"
#include <asm/Memory.hpp>

Stack_u4::Stack_u4(int max_stack_size) {
    this->start_address = Memory::alloc_mem<u4>(max_stack_size);
    this->current = this->start_address;
    this->max_stack_size = max_stack_size;
    this->current_size = 0;
    this->full = false;
}
Stack_u4::~Stack_u4() {
    Memory::free_mem(this->start_address);
}
void Stack_u4::push1(u1 value) {
    *current = value;
    this->current++; // next slot
    this->current_size++;
    check_full();
}
void Stack_u4::push2(u2 value) {
    *current = value;
    this->current++; // next slot
    this->current_size++;
    check_full();
}
void Stack_u4::push4(u4 value) {
    *current = value;
    this->current++; // next slot
    this->current_size++;
    check_full();
}
void Stack_u4::push8(u8 value) {
    *((u8 *)current) = value;
    this->current += 8; // next 2 slot
    this->current_size += 2;
    check_full();
}
u1 Stack_u4::pop1() {
    current_size--;
    current--;
    return *current;
}
u2 Stack_u4::pop2() {
    current_size--;
    current--;
    return *current;
}
u4 Stack_u4::pop4() {
    current_size--;
    current--;
    return *current;
}
u8 Stack_u4::pop8() {
    current_size -= 2;
    current -= 8;
    return *((u8 *)current);
}


Stack_u2::Stack_u2(int max_stack_size) {
    this->start_address = (u2 *) malloc(
            ((size_t) max_stack_size) * 2
    );
    this->current = this->start_address;
    this->max_stack_size = max_stack_size;
    this->current_size = 0;
}
Stack_u2::~Stack_u2() {
    free(this->start_address);
}
void Stack_u2::push1(u1 data) {
    *current = data;
    this->current++; // next slot
    this->current_size++;
    check_full();
}
void Stack_u2::push2(u2 data) {
    *current = data;
    this->current++; // next slot
    this->current_size++;
    check_full();
}
void Stack_u2::push4(u4 data) {
    *((u4 *)current) = data;
    this->current += 4; // next slot
    this->current_size += 2;
    check_full();
}
void Stack_u2::push8(u8 data) {
    *((u8 *)current) = data;
    this->current += 8; // next slot
    this->current_size += 4;
    check_full();
}
u1 Stack_u2::pop1() {
    current_size--;
    current--;
    return *current;
}
u2 Stack_u2::pop2() {
    current_size--;
    current--;
    return *current;
}
u4 Stack_u2::pop4() {
    current_size -= 2;
    current -= 4;
    return *((u4 *)current);
}
u8 Stack_u2::pop8() {
    current_size -= 4;
    current -= 8;
    return *((u8 *)current);
}