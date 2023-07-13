//
// Created by Administrator on 2023-02-15.
//

#include "TeaFileParser.hpp"
#include <oop/ConstantPool.hpp>

TeaFileParser::TeaFileParser(TeaFileReader * tfr) {
    this->reader = tfr;
    this->is_TCF = false;
    this->status = RSINIT;
    this->file_size = tfr->get_file_size();
    this->e = tfr->endian;
}
TeaFileParser::~TeaFileParser() {
    delete this->reader;
}
bool TeaFileParser::check_magic() {
    if(this->status < RSMAGIC) { // reader hasn't checked magic num
        u4 m = reader->nextU4();
        this->is_TCF = (m == 0xAE584448);
        this->status = RSMAGIC;
    }
    return this->is_TCF;
}
void TeaFileParser::read_inf() {
    if(!this->status < RSMAGIC) {
        check_magic();
    }

    this->inf = this->reader->nextU1();

    this->file_size       = this->reader->nextU4();

    this->status          = RSINF;
}
ConstantPool *TeaFileParser::read_cp() const {
    u2 count = this->reader->nextU2();
    u2 size  = this->reader->nextU2();
    var * cp = new ConstantPool(size, count);
    u1 * cp_bytes = this->reader->nextUn(size);
    u1 * cur = cp_bytes;
    for(int i = 0; i<count; i++) {
        Constant * c = Constant::convert_constant(cur, e);
        cp->set_constant(i+1, c);
        cur += Constant::size_in_cp(c);
    }
    cp->init_constant();

    return cp;
}
char ** TeaFileParser::read_pk_names(int count, ConstantPool *cp) const {
    if(count == 0) {
        return NULL;
    }
    char ** l = Memory::alloc_mem<char *>(count);
    UTF8_Constant * temp_c;
    for(int i = 0; i < count; i++) {
        temp_c = cp->get_constant_fast<UTF8_Constant>(
                reader->nextU2_fast()
        );
        l[i] = temp_c->val->get_cstr();
    }
    return l;
}
