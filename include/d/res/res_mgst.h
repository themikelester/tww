#ifndef RES_MGST_H
#define RES_MGST_H

#if VERSION == VERSION_PAL
enum MGST_RES_FILE_ID { // IDs and indexes are synced
    /* SCRN */
    MGST_BLO_SHIP_RACE1_0=0x4,
    MGST_BLO_SHIP_RACE1_1=0x5,
    MGST_BLO_SHIP_RACE1_2=0x6,
    MGST_BLO_SHIP_RACE1_3=0x7,
    MGST_BLO_SHIP_RACE1_4=0x8,
    
    /* TIMG */
    MGST_BTI_MS_SHIPFONT_1=0xB,
    MGST_BTI_MS_SHIPFONT_1_2=0xC,
    MGST_BTI_MS_SHIPFONT_2=0xD,
    MGST_BTI_MS_SHIPFONT_2_2=0xE,
    MGST_BTI_MS_SHIPFONT_3=0xF,
    MGST_BTI_MS_SHIPFONT_3_2=0x10,
    MGST_BTI_MS_SHIPFONT_A=0x11,
    MGST_BTI_MS_SHIPFONT_A_BIG=0x12,
    MGST_BTI_MS_SHIPFONT_E=0x13,
    MGST_BTI_MS_SHIPFONT_EX=0x14,
    MGST_BTI_MS_SHIPFONT_EX2=0x15,
    MGST_BTI_MS_SHIPFONT_G_BIG=0x16,
    MGST_BTI_MS_SHIPFONT_I_BIG=0x17,
    MGST_BTI_MS_SHIPFONT_L_BIG=0x18,
    MGST_BTI_MS_SHIPFONT_O=0x19,
    MGST_BTI_MS_SHIPFONT_O_BIG=0x1A,
    MGST_BTI_MS_SHIPFONT_P_BIG=0x1B,
    MGST_BTI_MS_SHIPFONT_R=0x1C,
    MGST_BTI_MS_SHIPFONT_S_BIG=0x1D,
    MGST_BTI_MS_SHIPFONT_T=0x1E,
    MGST_BTI_MS_SHIPFONT_V_BIG=0x1F,
    MGST_BTI_MS_SHIPFONT_Y_BIG=0x20,
    MGST_BTI_MS_SHIPFONT_Z=0x21,
};
#else
enum MGST_RES_FILE_ID { // IDs and indexes are synced
    /* SCRN */
    MGST_BLO_SHIP_RACE1=0x4,
    
    /* TIMG */
    MGST_BTI_MS_SHIPFONT_1=0x7,
    MGST_BTI_MS_SHIPFONT_1_2=0x8,
    MGST_BTI_MS_SHIPFONT_2=0x9,
    MGST_BTI_MS_SHIPFONT_2_2=0xA,
    MGST_BTI_MS_SHIPFONT_3=0xB,
    MGST_BTI_MS_SHIPFONT_3_2=0xC,
    MGST_BTI_MS_SHIPFONT_EX=0xD,
    MGST_BTI_MS_SHIPFONT_G_BIG=0xE,
    MGST_BTI_MS_SHIPFONT_O=0xF,
};
#endif

#endif /* RES_MGST_H */
