//
// Created by Administrator on 2023-03-17.
//

#ifndef $TEA_SRC_SHARE_CODEFILE_PARSERSET_HPP
#define $TEA_SRC_SHARE_CODEFILE_PARSERSET_HPP

#include <codefile/TeaFileParser.hpp>
#include <run/STATUS.hpp>

struct ParserSetNODE{
    ParserSetNODE * prev;
    TeaFileParser * value;
    ParserSetNODE * next;
    ParserSetNODE(TeaFileParser * parser);
};

/// List of TeaFileParsers which can auto-extend
class ParserSet {
private:
    ParserSetNODE * head; // head of linklist
    ParserSetNODE * curt; // current value
public:
    ParserSet();
    ~ParserSet();

    /// Add an element at the end of the set
    /// @param parser Value to add
    void add(TeaFileParser * parser);
    /// Delete an element
    /// @param index Index of target element
    void del(int index);
    /// Get the value corresponding to the index
    /// @param index Index of the target element
    /// @return target element
    TeaFileParser * get(int index);
    /// Set the value corresponding to the index
    /// @param index Index of the target element
    /// @param value New value to set
    void            set(int index, TeaFileParser * value);

};


#endif //$TEA_SRC_SHARE_CODEFILE_PARSERSET_HPP
