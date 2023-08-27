#pragma once

#ifndef $TVM_SRC_SHARE_TYPES_BYTEUTILS_HPP
#define $TVM_SRC_SHARE_TYPES_BYTE_HPP

#include <asm/Endian.hpp>

//	BASIC TYPES
typedef unsigned char      u1;
typedef unsigned short     u2;
typedef unsigned int       u4;
typedef unsigned long long u8;

typedef signed char      s1;
typedef signed short     s2;
typedef signed int       s4;
typedef signed long long s8;

typedef   u1 * pointer;
typedef void * address;

class ByteUtils{
public:
    static u2 make_u2(u1 src[2]);
    static u4 make_u4(u1 src[4]);
    static u8 make_u8(u1 src[8]);

    static u2 flip_u2(u2 obj);
    static u4 flip_u4(u4 obj);
    static u8 flip_u8(u8 obj);

    /// get the u1 of the index in src
    /// @param src source bytes array
    /// @param idx index
    static u1 u1_of(u1 * src, int idx);
    /// get the u2 of the index in src(IT HAS WRAPPED)
    /// @param src source bytes array
    /// @param idx index
    static u2 u2_of(u1 *src, int idx);
    /// get the u4 of the index in src(IT HAS WRAPPED)
    /// @param src source bytes array
    /// @param idx index
    static u4 u4_of(u1 * src, int idx);
    /// get the u8 of the index in src(IT HAS WRAPPED)
    /// @param src source bytes array
    /// @param idx index
    static u8 u8_of(u1 * src, int idx);

    static u2 cast_u2(u1 * arr);
    static u4 cast_u4(u1 * arr);
    static u8 cast_u8(u1 * arr);

    static inline void put_u1(address ptr, int idx, u1 value) {
        ((u1 *)ptr)[idx] = value;
    }
    static void put_u2(address ptr, int idx, u2 value) {
        ((u2 *)ptr)[idx] = value;
    }
    static void put_u4(address ptr, int idx, u4 value) {
        ((u4 *)ptr)[idx] = value;
    }
    static void put_u8(address ptr, int idx, u8 value) {
        ((u8 *)ptr)[idx] = value;
    }
};


#endif //$TVM_SRC_SHARE_TYPES_BYTEUTILS_HPP
