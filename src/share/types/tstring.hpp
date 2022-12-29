//
// Created by abbyl on 2022/12/28.
//

#ifndef TVM_1_0_TSTRING_HPP
#define TVM_1_0_TSTRING_HPP

#include <vector>
#include <map>

#include "bytes.hpp"

// String for vm to make getting utf-8 constant easier
struct TString {

    std::vector<u1> chars;
    //A CHAR -> A PTR
    ///
    ///int:index of the ptrs
    ///int:chars of the ptrs
    ///char ---> int
    ///
    std::map<u4, u4 *> ptrs;
    //Where is length?
        //it is map's size
}

class TStringUtil {
private:
    boolean save(u1 const *text);

    boolean _break();

protected:
    boolean isImport = false;
    u4 length;
    TString *str_ptr;
    std::map<int, char *> ptr;
public:
    boolean _import(TString *str);

    u4 getLength();

    boolean edit(u1 const *text);

    u1 at(u4 index);

    u1 *get_ptr(u4 index);

    static TString getEmpty();

    TStringUtil();

    ~TStringUtil();
};
#endif //TVM_1_0_TSTRING_HPP