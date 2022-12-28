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

#endif //TVM_1_0_TSTRING_HPP

    class New{
    private:
        New();
        ~New();
        u4 length;
    public:
        u4 getLength();
        static String getEmpty();
    };
}