//
// Created by Administrator on 2023-02-08.
//

#include "TeaFileReader.hpp"
#include <asm/Memory.hpp>

TeaFileReader::TeaFileReader(FILE *fileobj, EENDIAN eendian) {
    this->file   = fileobj;
    this->endian = eendian;
    // get size of file
    fseek(file, 0, SEEK_END);
    this->fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    this->cur   = 0;
}
TeaFileReader::~TeaFileReader() {
    fclose(this->file);
}

u2 TeaFileReader::nextU2_fast() {
    u1 targetp[2] = {0};
    fread(targetp, 1, 2, this->file);
    u2 target = *(u2 *) targetp;

    return ((this->endian == ELITTLE_ENDIAN) ? ByteUtils::flip_u2(target)   // little endian
                                             :                    target);  // big endian
}
u4 TeaFileReader::nextU4_fast() {
    u1 targetp[4];
    fread(targetp, 1, 4, this->file);
    u4 target = *(u4 *) targetp;
    return ((this->endian == ELITTLE_ENDIAN) ? ByteUtils::flip_u4(target) // little endian
                                             :                    target  // big endian
    );
}
u8 TeaFileReader::nextU8_fast() {
    u1 targetp[8];
    fread(targetp, 1, 8, this->file);
    u4 target = *(u8 *) targetp;
    return ((this->endian == ELITTLE_ENDIAN) ? ByteUtils::flip_u8(target) // little endian
                                             :                    target  // big endian
    );
}
u1 * TeaFileReader::nextUn_fast(int n) {
    u1 * res = Memory::alloc_mem(n);
    fread(res, 1, n, this->file);
    return res;
}