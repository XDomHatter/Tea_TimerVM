//
// Created by Administrator on 2023-03-17.
//

#ifndef $TEA_SRC_SHARE_RUN_STATUS_HPP
#define $TEA_SRC_SHARE_RUN_STATUS_HPP

typedef enum {
    VMINIT         = 0x00,
    VMREADING_FILE = 0x01,
    VMREADY        = 0x02,
    VMRUNNING      = 0x03,
    VMWAITING      = 0x04,

} VMStatus;

typedef enum {
    RINIT   = 0x00,
    RMAGIC = 0x01, // reader has already checked the magic num
    RINF   = 0x02, //                                information in the codefile
    RCP    = 0x03, //                                information about constants
    RGF    = 0x04, //                                global functions
} ReaderStatus;

#endif //$TEA_SRC_SHARE_RUN_STATUS_HPP
