//
// Created by Administrator on 2023-02-15.
//

#include "TeaFileParser.hpp"
#include <oop/ConstantPool.hpp>

TeaFileParser::TeaFileParser(TeaFileReader * tfr) {
    this->reader = tfr;
    tfr->guarantee_more(9); // magic + inf + size -> 4 + 1 + 4
    this->is_TCF = false;
    this->file_size = tfr->get_file_size();
}
TeaFileParser::~TeaFileParser() {
    delete this->reader;
}
bool TeaFileParser::check_magic() {
    if(!this->checked_magic) { // reader hasn't checked magic num
        u4 m = reader->nextU4_fast();
        this->is_TCF = (m == 0xAE584448);
        this->checked_magic = true;
    }
    return this->is_TCF;
}
void TeaFileParser::read_inf() {
    this->inf = this->reader->nextU1_fast();

    this->file_size       = this->reader->nextU4_fast();
    if(file_size < reader->get_file_size()) {
        // file is smaller than after compiling.
        TConsole::error("File isn't intact!\n");
    }
    this->reader->set_size(this->file_size);
}
ConstantPool *TeaFileParser::read_cp() const {
    u2 count = this->reader->nextU2();
    u2 size  = this->reader->nextU2();
    var * cp = new ConstantPool(size, count);
    u1 * cp_bytes = this->reader->nextUn(size);
    u1 * cur = cp_bytes;
    for(int i = 0; i<count; i++) {
        Constant * c = Constant::convert_constant(cur);
        cp->set_constant(i+1, c);
        cur += Constant::size_in_cp(c);
    }
    cp->init_constant();
    
    Memory::free_mem(cp_bytes);
    
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
