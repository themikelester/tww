#ifndef RES_KAISEN_3_H
#define RES_KAISEN_3_H

#include "global.h"

#if VERSION == VERSION_PAL
enum KAISEN_3_RES_FILE_ID { // IDs and indexes are synced
    /* BDL */
    KAISEN_3_BDL_AK2SH=0x4,
    KAISEN_3_BDL_AK3SH=0x5,
    KAISEN_3_BDL_AK4SH=0x6,
    KAISEN_3_BDL_AKATR=0x7,
    KAISEN_3_BDL_AKBOD=0x8,
    KAISEN_3_BDL_AKCSR=0x9,
    KAISEN_3_BDL_AKHZR=0xA,
    KAISEN_3_BDL_AKKSL=0xB,
    
    /* TEX */
    KAISEN_3_BTI_GAME_BEST_RECORD=0xE,
    KAISEN_3_BTI_GAME_BOMB_01=0xF,
    KAISEN_3_BTI_GAME_BOMB_02=0x10,
    KAISEN_3_BTI_GAME_PAPER=0x11,
    KAISEN_3_BTI_KAISEN_IKA_01=0x12,
    KAISEN_3_BTI_KAISEN_IKA_02=0x13,
};
#endif

#endif /* RES_KAISEN_3_H */