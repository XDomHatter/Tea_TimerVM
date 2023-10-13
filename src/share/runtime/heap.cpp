//
// Created by XDomHatter on 2023-10-01.
//

#include "heap.hpp"
#include <stdexcept>

TeaHeap::TeaHeap() {
    _map = new std::map<u4, InstanceOOP *>();
    token = 0;
    null_obj_idx = token;
    _map->operator[](null_obj_idx) = NULL;

    token++;
}
u4 TeaHeap::add_object(InstanceOOP *object) {
    this->_map->operator[](token++) = object;
    return token-1;
}
InstanceOOP *TeaHeap::get_object(u4 index) {
    InstanceOOP *res;
    try {
        res = _map->at(index);
    } catch (const std::out_of_range &e) {
        TConsole::output_f("Cannot get object at index: %d", index);
        QUIT(-1);
    }
    return res;
}
