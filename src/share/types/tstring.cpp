//
// Created by abbyl on 2022/12/28.
//
#include <iostream>
#include "tstring.hpp"

boolean TStringUtil::_import(TString* str_ptr) {
    this->str_ptr = str_ptr;
    if (str_ptr == nullptr && this->str_ptr == nullptr){
        return false;
    }else{
        length = getLength();
        isImport = true;
        for (int index = 0; index < length; ++index) {
            ptr.insert(std::pair<int,char*>(index,&str_ptr->chars.at(index)));
        }
        return true;
    }
}

u4 TStringUtil::getLength() {
    length = str_ptr->ptrs.size();
    return length;
}

TString TStringUtil::getEmpty() {
    TString str;
    return str;
}

boolean TStringUtil::save(u1 const* text) {
    int text_length = sizeof(text);
    if (text_length == 0){
        return false;
    }
    for (int index = 0; index < text_length; ++index) {
        str_ptr->chars.push_back(text[index]);
    }
}
boolean TStringUtil::edit(u1 const* text) {
    return save(text);
}

TStringUtil::TStringUtil() {
}

TStringUtil::~TStringUtil() {
    _break();
}

boolean TStringUtil::_break() {
    if (isImport){
        std::free(&length);
        std::free(str_ptr);
        std::free(&isImport);
    }else{
        return false;
    }
}
u1 TStringUtil::at(u4 index) {
    return str_ptr->chars.at(index);
}
u1* TStringUtil::get_ptr(u4 index) {
    return ptr.at(index);
}