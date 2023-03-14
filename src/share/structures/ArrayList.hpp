//
// Created by Administrator on 2023-02-25.
//

#ifndef $TVM_SRC_SHARE_STRUCTURES_ARRAYLIST_HPP
#define $TVM_SRC_SHARE_STRUCTURES_ARRAYLIST_HPP

#include <structures/BitMap.hpp>

class ArrayList_str {
private:
    char **list;
    BitMap *if_inited;
public:
    int length;
    ArrayList_str();
    ArrayList_str(int length);
    ~ArrayList_str();

    /// get the str corresponding to the index
    /// @param index Index of string
    /// @return str of index
    char *get(int index);

    /// set the str corresponding to the index
    /// @param index Index of string
    /// @param value Value to set
    void set(int index, char *value);

};


#endif //$TVM_SRC_SHARE_STRUCTURES_ARRAYLIST_HPP
