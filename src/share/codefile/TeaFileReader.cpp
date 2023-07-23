//
// Created by Administrator on 2023-02-08.
//

#include "TeaFileReader.hpp"
#include <asm/Memory.hpp>

TeaFileReader::TeaFileReader(FILE *fileobj) {
    this->file = fileobj;
    this->cur   = 0;
}
TeaFileReader::~TeaFileReader() {
    fclose(this->file);
}

u1 TeaFileReader::nextU1_fast() {
    this->cur += 1;
    u1 resp = 0;
    fread(&resp, 1, 1, this->file);
    return resp;
}
u2 TeaFileReader::nextU2_fast() {
    this->cur += 2;
    u1 targetp[2] = {0};
    fread(targetp, 1, 2, this->file);
    u2 target = *(u2 *) targetp;
    
    return EENDIAN_CODE(target, ByteUtils::flip_u2(target));
}
u4 TeaFileReader::nextU4_fast() {
    this->cur += 4;
    u1 targetp[4];
    fread(targetp, 1, 4, this->file);
    u4 target = *(u4 *) targetp;
    return EENDIAN_CODE(target, ByteUtils::flip_u4(target));
}
u8 TeaFileReader::nextU8_fast() {
    this->cur += 8;
    u1 targetp[8];
    fread(targetp, 1, 8, this->file);
    u4 target = *(u8 *) targetp;
    return EENDIAN_CODE(target, ByteUtils::flip_u8(target));
}
u1 * TeaFileReader::nextUn_fast(int n) {
    this->cur += n;
    u1 * res = Memory::alloc_mem(n);
    fread(res, 1, n, this->file);
    return res;
}