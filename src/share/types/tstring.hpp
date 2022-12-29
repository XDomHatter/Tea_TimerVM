//
// Created by abbyl on 2022/12/28.
//

#ifndef TVM_1_0_TSTRING_HPP
#define TVM_1_0_TSTRING_HPP

#include <vector>
#include <map>

#include "types.h"

namespace String{
// String for vm to make getting utf-8 constant easier
    struct TString {

        std::vector<u1> chars;
        //A CHAR -> A PTR
        ///
        ///int:index of the ptrs
        ///int:chars of the ptrs
        ///char ---> int
        ///
        std::map<u4,u4*> ptrs;
        //Where is length?
        //it is map's size
    };

//typedef
    typedef TString String;

    class utils{
    private:
        boolean save(u1 const* text);
    protected:
        u4 length;
        String* str_ptr;
    public:
        boolean _import(String* str);
        u4 getLength();
        boolean edit(u1 const* text);
        static String getEmpty();
        utils();
        ~utils();
    };
#endif //TVM_1_0_TSTRING_HPP
}