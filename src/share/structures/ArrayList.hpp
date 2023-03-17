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

    /// decide if the value corresponding to index is inited
    /// @param index index
    /// @return if it is inited
    bool has_inited(int index);
};

template<class T>
class ArrayList{
private:
    int length;
    T * values;
public:
    ArrayList();
    ArrayList(int length);
    ~ArrayList();

    /// get the value corresponding to the index
    /// @param index Index of value
    /// @return Str of index
    T get(int index);

    /// set the value corresponding to the index
    /// @param index Index of value
    /// @param value Value to set
    void set(int index, T value);
};

#endif //$TVM_SRC_SHARE_STRUCTURES_ARRAYLIST_HPP
