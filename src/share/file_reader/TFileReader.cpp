//
// Created by abbyl on 2022/12/29.
//

#include "TFileReader.hpp"
#include <malloc.h>
#include <fstream>

TFileReader::TFileReader(const char *filename, size_t buff_size = 16384) {
    this->tfile     = fopen(filename, "r+");
    this->buff_size = buff_size;

    FILE *tmp = fopen(filename, "rb"); //tmp file



    /* It's so waste that we HAVE TO delete it
    // use fseek to seek to end of the file,
    // and ftell to get current offset to show size of the file
    // !!FILE SIZE MUST LESS THAN 2G!!
    FILE *tmp = fopen(filename, "rb");
    fseek(tmp, 0, SEEK_END);
    this->file_size =    ftell(tmp);
    fclose(tmp);
     */
    // Tea File's second structure is an u4(big endian) to denote the size of the file
    fgets(NULL, 4, tmp); //skip 4 bytes (magic number)
    u1 f_size_bytes[4];
    fgets((char *)f_size_bytes, 4, tmp);


    this->current_idx = 0;

    this->start_adr = malloc(buff_size);
    if(this->file_size >= this->buff_size)
        fgets((char *)this->start_adr, buff_size, this->tfile);
    else //file doesn't has enough bytes(buff_size) to read
        fgets((char *)this->start_adr, this->file_size, this->tfile);
}
inline FILE * TFileReader::getFileObj() {
    return this->tfile;
}
void TFileReader::map_file() {
    this->start_adr = fgets((char *)this->start_adr, this->buff_size, this->tfile);
}
inline bool TFileReader::is_end() {
    return this->eof;
}
