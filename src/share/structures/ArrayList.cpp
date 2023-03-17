//
// Created by Administrator on 2023-02-25.
//

#include "ArrayList.hpp"
#include <asm/Memory.hpp>
#include <utilities/cstr_utils.hpp>
#include <utilities/Tio.hpp>
#include <utilities/cint_utils.hpp>

ArrayList_str::ArrayList_str() {
    this->list = (char **) Memory::alloc_mem((sizeof(char *)) * 16);
    this->length = 16;
    this->if_inited = new BitMap(16);
}

ArrayList_str::ArrayList_str(int length) {
    this->list = (char **) Memory::alloc_mem((sizeof(char *)) * length);
    this->length = length;
    this->if_inited = new BitMap(length);
}

ArrayList_str::~ArrayList_str() {
    for(int i = 0; i < this->length; i++){
        if(this->if_inited->get(i)){
            Memory::free_mem(*(this->list + (sizeof(char *) * i)));
        }
    }
    Memory::free_mem(this->list);
    delete this->if_inited;
}

char *ArrayList_str::get(int index) {
    if (index >= this->length) {
        return NULL;
    }
    if (this->if_inited->get(index) == 0) {
        return NULL;
    }
    return this->list[index];
}

void ArrayList_str::set(int index, char *value) {
    if (index > this->length) { // array need extend
        /* extend list of strings*/
        // usually we use this method to set value not only once
        // so, for usability and also for machine can read that quickly,
        // we do byte alignment:
        // e.g. index = 13
        // index % 4  = 3
        // index + index % 4 = 13 + 3 = 16
        int needed_size = index + (index % 4);
        // add 8 byte if needed_size doesn't change( index is a multiples of 4 )
        needed_size += ((index == needed_size) ? 8 : 0);

        int old_length = this->length;
        this->list = (char **) Memory::realloc_mem((pointer) this->list,
                needed_size * sizeof(char *));
        this->length = needed_size;

        /* extend bitmap */
        this->if_inited->extend(needed_size - old_length);
    }

    if(this->if_inited->get(index) == 0){
        // the string hasn't inited
        // init c string(char *) by size of 'value'
        // '+1' cuz 'strlen' doesn't contain '\0'
        this->list[index] = (char *) Memory::alloc_mem(strlen(value) * sizeof(char) + 1);
        this->if_inited->set(index, 1);
    } else {
        // it has inited so do reallocation
        Memory::realloc_mem((pointer) this->list[index], strlen(value) * sizeof(char) + 1);
    }

    // this.list[index] = value;
    CSTRUtil::copy(this->list[index], value);
}

bool ArrayList_str::has_inited(int index) {
    return this->if_inited->get(index);
}


template<class T> ArrayList<T>::ArrayList() {
    this->length = 16;
    this->values  = Memory::alloc_mem(sizeof(T) * 16);
}

template<class T> ArrayList<T>::ArrayList(int length) {
    this->length = 16;
    this->values  = Memory::alloc_mem(sizeof(T) * length);
}

template<class T> ArrayList<T>::~ArrayList() {
    Memory::free_mem(this->values);
}

template<class T> T ArrayList<T>::get(int index) {
    if (index >= this->length) {
        return NULL;
    }
    return this->values[index];
}

template<class T> void ArrayList<T>::set(int index, T value) {
    if (index > this->length) { // array need extend
        /* extend list of values*/
        // usually we use this method to set value not only once
        // so, for usability and also for machine can read that quickly,
        // we do byte alignment:
        // e.g. index = 13
        // index % 4  = 3
        // index + index % 4 = 13 + 3 = 16
        int needed_size = index + (index % 4);
        // add 8 byte if needed_size doesn't change( index is a multiples of 4 )
        needed_size += ((index == needed_size) ? 8 : 0);
        this->values = (T *) Memory::realloc_mem((pointer) this->values,
                needed_size * sizeof(T));
        this->length = needed_size;
    }
    // copy value
//    this->values[index] = value;
    memcpy(this->values[index], value, sizeof(T));
}