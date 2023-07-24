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
    CTSFAILED = 0x00,
    CTSNEW    = 0x01,
    CTSINITED = 0x02
} ConstantStatus;

#endif //$TEA_SRC_SHARE_RUN_STATUS_HPP
