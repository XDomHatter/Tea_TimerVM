//
// Created by Administrator on 2023-06-11.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#include "ByteStream.hpp"

ByteStream::ByteStream(u1 *bytes, int size, EDPARAM) {
    this->e = e;
    this->head = Memory::alloc_mem(size);
    Memory::copy(bytes, (pointer) this->head, size);
    this->current = head;
    this->end = this->head + size;
}

u1 ByteStream::nextU1() {
    guarantee_more(1);
    return nextU1_fast();
}
u2 ByteStream::nextU2() {
    guarantee_more(2);
    return nextU2_fast();
}
u4 ByteStream::nextU4() {
    guarantee_more(4);
    return nextU4_fast();
}
u8 ByteStream::nextU8() {
    guarantee_more(8);
    return nextU8_fast();
}
u1 *ByteStream::nextUn(int n) {
    guarantee_more(n);
    return nextUn_fast(n);
}

