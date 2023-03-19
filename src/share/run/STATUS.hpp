//
// Created by Administrator on 2023-03-17.
//

#ifndef $TEA_SRC_SHARE_RUN_STATUS_HPP
#define $TEA_SRC_SHARE_RUN_STATUS_HPP

typedef enum {
    INIT         = 0x00,
    READING_FILE = 0x01,
    READY        = 0x02,
    RUNNING      = 0x03,
    WAITING      = 0x04,

} VMStatus;

#endif //$TEA_SRC_SHARE_RUN_STATUS_HPP
