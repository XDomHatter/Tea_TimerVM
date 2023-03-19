//
// Created by Administrator on 2023-03-17.
//

#include "ParserSet.hpp"
#include <asm/Memory.hpp>


/////////////////////////////////////////////////////////
//////////////////// ParserSetNode //////////////////////
/////////////////////////////////////////////////////////
ParserSetNODE::ParserSetNODE(TeaFileParser * parser) {
    this->prev  = NULL;
    this->value = parser;
    this->next  = NULL;
}


/////////////////////////////////////////////////////////
////////////////////// ParserSet ////////////////////////
/////////////////////////////////////////////////////////
ParserSet::ParserSet() {
    this->head = new ParserSetNODE(NULL);
    this->curt = this->head;
}

ParserSet::~ParserSet() {
    ParserSetNODE * node = this->head;
    while(node != NULL){
        delete node->value;
        node = node->next;
        delete node->prev;
    }
}

void ParserSet::add(TeaFileParser *parser) {
    if(this->curt == this->head){
        this->curt->value = parser;
        return;
    }
    // curt = 0xA0000000
    this->curt->next = (ParserSetNODE *) Memory::alloc_mem(sizeof(ParserSetNODE *));
    // curt->next = 0xA0010000  (it's un continuous)
    this->curt->next->prev  = this->curt;
    this->curt->next->value = parser;
    this->curt->next->next  = NULL;
    // curt:{
    //   head = ?;
    //   value = ?;
    //   next = curt:{
    //     head = curt;
    //     value= parser;
    //     next = NULL;
    //   }
    // }
    this->curt = this->curt->next;
    return;
}

TeaFileParser *ParserSet::get(int index) {
    ParserSetNODE * res = this->head;
    for(int i = 1; i<=index; i++) {
        res = res->next;
    }
    return res->value;
}

void ParserSet::del(int index) {
    ParserSetNODE * target_node = this->head;
    for(int i = 1; i<=index; i++) {
        target_node = target_node->next;
    }

    // before: node1 -> node2 -> node3 -> node4
    //                   ^^^
    //                 target
    target_node->prev->next = target_node->next;
    // after:        ___________
    //              /           \
    //         node1    node2    node3 -> node4
    //  node2 is invisible
    delete target_node;
}

void ParserSet::set(int index, TeaFileParser * value) {
    ParserSetNODE * target_node = this->head;
    for(int i = 1; i<=index; i++) {
        target_node = target_node->next;
    }
    target_node->value = value;
}

