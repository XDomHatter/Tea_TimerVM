//
// Created by Administrator on 2023-02-09.
//

#include "Bootstrap.hpp"
#include <utilities/macros.hpp>

Bootstrap::Bootstrap(char *filename) {
    // decide endian
    u2 test_data = 0x1234;
    u1 * test_ptr = (u1*)&test_data;
    this->endian = ((*(test_ptr) == 0x12) ? EBIG_ENDIAN : ELITTlE_ENDIAN);

    // create reader
    this->code_file = fopen(filename, "r+");
    this->reader = new TeaFileReader(this->code_file, this->endian);

    // check magic num
    if(!this->check_magic_num()){
          ERR("FILE DOESN'T INTACT");
    }

}
u1 Bootstrap::check_magic_num() {
    u4 MAGIC = this->reader->readU4();
    return (MAGIC == 0xAE584448);
}
