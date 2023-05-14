//
// Created by Administrator on 2023-02-08.
//

#include "TeaFileReader.hpp"
#include <asm/Memory.hpp>

TeaFileReader::TeaFileReader(FILE *fileobj, EENDIAN eendian) {
    this->file   = fileobj;
    this->endian = eendian;
}
TeaFileReader::~TeaFileReader() {
    fclose(this->file);
}
u1 TeaFileReader::readU1() {
    return fgetc(this->file);
}
u2 TeaFileReader::readU2() {
    u1 target[2] = {0};
    target[0] = fgetc(this->file);
    target[1] = fgetc(this->file);

    return ((this->endian == ELITTLE_ENDIAN) ? ByteUtils::flip_u2(*((u2 *) target)) // little endian
                                             : *((u2 *)target));// big endian
}
u4 TeaFileReader::readU4() {
    u1 target[4] = {0};
    target[0] = fgetc(this->file);
    target[1] = fgetc(this->file);
    target[2] = fgetc(this->file);
    target[3] = fgetc(this->file);
    return ((this->endian == ELITTLE_ENDIAN) ? ByteUtils::flip_u4(*((u4 *) target)) // little endian
                                             : *((u4 *)target)  // big endian
    );
}
u8 TeaFileReader::readU8() {
    u1 target[8] = {0};
    target[0] = fgetc(this->file);
    target[1] = fgetc(this->file);
    target[2] = fgetc(this->file);
    target[3] = fgetc(this->file);
    target[4] = fgetc(this->file);
    target[5] = fgetc(this->file);
    target[6] = fgetc(this->file);
    target[7] = fgetc(this->file);
    return ((this->endian == ELITTLE_ENDIAN) ? ByteUtils::flip_u8(*((u8 *) target)) // little endian
                                             : *((u8 *)target));// big endian
}
u1 * TeaFileReader::readUn(int n) {
    u1 * res = Memory::alloc_mem(n);
    for(int i = 0;i<n;i++) {
        res[i] = fgetc(this->file);
    }
    return res;
}