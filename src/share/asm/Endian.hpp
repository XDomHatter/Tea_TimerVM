//
// Created by Administrator on 2023-01-17.
//

#ifndef $TVM_SRC_SHARE_ASM_ENDIAN_HPP
#define $TVM_SRC_SHARE_ASM_ENDIAN_HPP

#if defined(ED_LITENDIAN)
#define EENDIAN_CODE(BIG, LIT) LIT
#elif defined(ED_BIGENDIAN)
#define EENDIAN_CODE(BIG, LIT) BIG
#endif



#endif //$TVM_SRC_SHARE_ASM_ENDIAN_HPP
