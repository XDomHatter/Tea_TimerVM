//
// Created by Administrator on 2023-02-15.
//

#include "TeaFileParser.hpp"

TeaFileParser::TeaFileParser(TeaFileReader * tfr) {
    this->reader = tfr;
    this->is_TCF = false;
    this->status = RSINIT;
}
TeaFileParser::~TeaFileParser() {
    delete this->reader;
}
bool TeaFileParser::check_magic() {
    if(!this->status < RSMAGIC) { // reader hasn't checked magic num
        this->is_TCF = (this->reader->readU4() == 0xAE584448);
        this->status = RSMAGIC;
    }
    return this->is_TCF;
}
void TeaFileParser::read_inf() {
    if(!this->status < RSMAGIC) {
        check_magic();
    }

    u1 inf_ff = this->reader->readU1();
    //  u1 file_inf;   // 0b00000001 means FAST_METHOD mode that vm doesn't check result type
    //                 // 0b00000010 means NO_RES_TYPE mode that Method.result_type doesn't exists
    //                 // 0b00000100 means JIT_ON      mode
    //                 // 0b00001000 means AOT_ON      mode
    //
    this->inf.FAST_METHOD = inf_ff & 1; // 0b00000001
    this->inf.NO_RES_TYPE = inf_ff & 2; // 0b00000010
    this->inf.JIT_ON      = inf_ff & 4; // 0b00000100
    this->inf.AOT_ON      = inf_ff & 8; // 0b00001000

    this->file_size       = this->reader->readU4();

    this->status          = RSINF;
}
