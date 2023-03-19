//
// Created by Administrator on 2023-02-15.
//

#include "TeaFileParser.hpp"

TeaFileParser::TeaFileParser(TeaFileReader * tfr) {
    this->reader = tfr;
    this->is_TCF = false;
    this->checked_TCF = false;
}
bool TeaFileParser::check_magic() {
    if(!this->checked_TCF) {
        this->is_TCF = (this->reader->readU4() == 0xAE584448);
        this->checked_TCF = true;
    }
    return this->is_TCF;
}

