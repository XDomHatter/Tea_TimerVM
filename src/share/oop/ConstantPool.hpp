//
// Created by Administrator on 2023-03-27.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#ifndef $TEA_SRC_SHARE_OOP_CONSTANTPOOL_HPP
#define $TEA_SRC_SHARE_OOP_CONSTANTPOOL_HPP

#include <oop/Constant.hpp>
#include <type_traits>

class ConstantPool {
private:
    int             size;
    int            count;
    Constant ** constants;
public:
    ConstantPool(u2 size, u2 count);
    ~ConstantPool();
    void init_constant();

    void set_constant(u2 index, Constant * constant);

    /// Get a constant in cp and cast it to the target type
    template<class T>
    T * get_constant(u2 index);
    /// Get a constant in cp without checking type
    template<class T>
    inline T * get_constant_fast(u2 index) const {
        return (T *) this->constants[index - 1]; // -1 cuz the index of constant starts from 1
    }
};

template<class T> T * ConstantPool::get_constant(u2 index) {
    if((index - 1) < 0) return NULL;
    if(index > this->count) return NULL;
    Constant *res = get_constant_fast<T>(index);
    if(!Constant::check_type<T>(res)){
        TConsole::error("Constant type is wrong.");
    };
    return (T *) res;
}


#endif //$TEA_SRC_SHARE_OOP_CONSTANTPOOL_HPP
