//
// Created by Administrator on 2023-02-25.
//

#ifndef $TVM_SRC_SHARE_STRUCTURES_BITMAP_HPP
#define $TVM_SRC_SHARE_STRUCTURES_BITMAP_HPP

#include <asm/BytesUtils.hpp>

class BitMap {
private:
    u1 *bits;
    int size;      // the length of bit that the param of initializer(for user)
    int real_size; // the allocated really size of byte(in memory)
public:
    /// init map by length
    /// @param length         size of map (count of bit but not byte)
    BitMap(int length);

    ~BitMap();

    /// extend map for 's' as size
    /// @param s size of bit to allocate again
    void extend(int s);

    /// get the count of BYTES(NOT BITS)
    /// @return count of BYTES(NOT BITS)
    int getsize();

    /// set size of map for 's' as size
    /// @param s target size
    void setsize(int s);

    /// get the bit(1 or 0) in map
    /// @param idx            index of the target bit
    /// @return 1 or 0
    char get(int idx);

    /// set the bit(1 or 0) in map
    /// @param idx            index of the target bit
    /// @param true_or_false  1(true) or 0(false)
    void set(int idx, bool true_or_false);
};


#endif //$TVM_SRC_SHARE_STRUCTURES_BITMAP_HPP
