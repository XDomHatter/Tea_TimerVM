//
// Created by Administrator on 2023-02-08.
//

#ifndef $TVM_SRC_SHARE_CODEFILE_TEAFILEREADER_HPP
#define $TVM_SRC_SHARE_CODEFILE_TEAFILEREADER_HPP

#include <utilities/file_macros.hpp>
#include <asm/BytesUtils.hpp>
#include <asm/ByteStream.hpp>
#include <asm/Endian.hpp>


/// It is not a stream cuz it doesn't load all the file into memory
class TeaFileReader : IByteStream{
private:
    FILE * file;
    u4 fsize;
    u4 cur;

public:
    EENDIAN endian;
    TeaFileReader(FILE *fileobj, EENDIAN eendian);
    ~TeaFileReader();

    inline u4 get_file_size() const {
        return this->fsize;
    }

    inline bool guarantee_more(int n) const {
        return (this->cur + n) <= fsize;
    }

    inline u1 nextU1() override {
        guarantee_more(1);
        return nextU1_fast();
    }
    inline u1 nextU1_fast() override {
        u1 resp = 0;
        fread(&resp, sizeof(__int8), 1, this->file);
        return resp;
    }

    inline u2 nextU2() override{
        guarantee_more(2);
        return nextU2_fast();
    }
    u2 nextU2_fast() override;

    inline u4 nextU4() override {
        guarantee_more(4);
        return nextU4_fast();
    }
    u4 nextU4_fast() override;

    inline u8 nextU8() override {
        guarantee_more(8);
        return nextU8_fast();
    }
    u8 nextU8_fast() override;

    /// read n bytes from file(REMEMBER TO FREE IT!!!!)
    /// @param n count of bytes
    /// @return bytes
    inline u1 * nextUn(int n) override {
        guarantee_more(n);
        return nextUn_fast(n);
    }
    u1 * nextUn_fast(int n) override;
};


#endif //$TVM_SRC_SHARE_CODEFILE_TEAFILEREADER_HPP
