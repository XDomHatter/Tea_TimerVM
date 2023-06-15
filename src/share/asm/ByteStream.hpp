//
// Created by Administrator on 2023-06-11.
// Copyright (c) 2023 TimerFX Studio. All rights reserved.
//

#ifndef $TEA_SRC_SHARE_ASM_BYTESTREAM_HPP
#define $TEA_SRC_SHARE_ASM_BYTESTREAM_HPP

#include <asm/Memory.hpp>
#include <utilities/macros.hpp>

/// nextU2 4 8 do the flip operation if the endian is little
class IByteStream {
protected:
    EDPARAM;
public:
    /// return next u1 in stream
    virtual u1 nextU1() = 0;
    /// return next u1 in stream without check
    virtual u1 nextU1_fast() = 0;
    /// return next u2 in stream
    virtual u2 nextU2() = 0;
    /// return next u2 in stream without check
    virtual u2 nextU2_fast() = 0;
    /// return next u4 in stream
    virtual u4 nextU4() = 0;
    /// return next u4 in stream without check
    virtual u4 nextU4_fast() = 0;
    /// return next u8 in stream
    virtual u8 nextU8() = 0;
    /// return next u8 in stream without check
    virtual u8 nextU8_fast() = 0;
    /// return next n bytes in stream
    virtual u1 *nextUn(int n) = 0;
    /// return next n bytes in stream without check
    virtual u1 *nextUn_fast(int n) = 0;
};

class ByteStream : IByteStream {
private:
    u1 * head;
    u1 * current;
    u1 * end;

public:
    /// Create stream with bytes
    /// @param bytes target bytes
    /// @param size  size of bytes
    /// @TIP The array only do copy, free it self!
    ByteStream(u1 *bytes, int size, EDPARAM);

    inline bool guarantee_more(int n) {
        return (current+n) < end;
    }

    u1 nextU1() override;
    inline u1 nextU1_fast() override {
        return *(current++);
    }

    u2 nextU2() override;
    inline u2 nextU2_fast() override {
        u2 res = *((u2 *)current);
        EENDIAN_CODE(e, {}, {
            res = ByteUtils::flip_u2(res);
        });
        current += 2;
        return res;
    }

    u4 nextU4() override;
    inline u4 nextU4_fast() override {
        u4 res = *((u4 *)current);
        EENDIAN_CODE(e, {}, {
            res = ByteUtils::flip_u4(res);
        });
        current += 4;
        return res;
    }

    u8 nextU8() override;
    inline u8 nextU8_fast() override {
        u8 res = *((u8 *)current);
        EENDIAN_CODE(e, {}, {
            res = ByteUtils::flip_u8(res);
        });
        current += 8;
        return res;
    }

    u1 * nextUn(int n) override;
    inline u1 *nextUn_fast(int n) override {
        u1 *res = current;
        current += n;
        return res;
    }
};


#endif //$TEA_SRC_SHARE_ASM_BYTESTREAM_HPP
