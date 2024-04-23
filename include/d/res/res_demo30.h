#ifndef RES_DEMO30_H
#define RES_DEMO30_H

enum DEMO30_RES_FILE_ID {
    /* STB */
    DEMO30_STB_DANCE_KOKIRI=0x0,
    
    /* BCKS */
    DEMO30_BCK_30_FD_IBARI_L=0x1,
    DEMO30_BCK_30_FD_LOOP_L=0x2,
    DEMO30_BCK_30_FD_TOIKAKE_O=0x3,
    DEMO30_BCK_30_FD_TOIKAKEB2_L=0xD,
    DEMO30_BCK_30_FD_TOIKAKE2_O=0xE,
    DEMO30_BCK_GDEMO27_APPR00=0x14,
    
    /* BTP */
    DEMO30_BTP_30_FD_IBARI_L=0x4,
    DEMO30_BTP_30_FD_LOOP_L=0x5,
    DEMO30_BTP_30_FD_TOIKAKEB2_L=0xF,
    DEMO30_BTP_30_FD_TOIKAKE2_O=0x10,
    
    /* BRK */
    DEMO30_BRK_30_FD_LOOP_L=0x7,
#if VERSION == VERSION_JPN
    DEMO30_BRK_30_FD_TOIKAKE_O=0x8,
    DEMO30_BRK_30_FD_TOIKAKEB_O=0xA,
#endif
    DEMO30_BRK_30_FD_TOIKAKE2_O=0xB,
    DEMO30_BRK_30_FD_TOIKAKEB2_L=0xC,
    DEMO30_BRK_GDEMO27_TFG00=0x15,
#if VERSION != VERSION_JPN
    DEMO30_BRK_30_FD_IBARI_L=0x19,
#endif
    
    /* BDLM */
    DEMO30_BDL_FD_COMP=0x9,
    DEMO30_BDL_GDEMO27_APPR00=0x16,
    DEMO30_BDL_GDEMO27_TFG00=0x17,
    
    /* BTK */
    DEMO30_BTK_GDEMO27_APPR00=0x18,
};

#if VERSION == VERSION_JPN
enum DEMO30_RES_FILE_INDEX {
    /* STB */
    DEMO30_INDEX_STB_DANCE_KOKIRI=0x8,
    
    /* BCKS */
    DEMO30_INDEX_BCK_30_FD_IBARI_L=0xB,
    DEMO30_INDEX_BCK_30_FD_LOOP_L=0xC,
    DEMO30_INDEX_BCK_30_FD_TOIKAKE_O=0xD,
    DEMO30_INDEX_BCK_30_FD_TOIKAKEB2_L=0xE,
    DEMO30_INDEX_BCK_30_FD_TOIKAKE2_O=0xF,
    DEMO30_INDEX_BCK_GDEMO27_APPR00=0x10,
    
    /* BTP */
    DEMO30_INDEX_BTP_30_FD_IBARI_L=0x13,
    DEMO30_INDEX_BTP_30_FD_LOOP_L=0x14,
    DEMO30_INDEX_BTP_30_FD_TOIKAKEB2_L=0x15,
    DEMO30_INDEX_BTP_30_FD_TOIKAKE2_O=0x16,
    
    /* BRK */
    DEMO30_INDEX_BRK_30_FD_LOOP_L=0x19,
    DEMO30_INDEX_BRK_30_FD_TOIKAKE_O=0x1A,
    DEMO30_INDEX_BRK_30_FD_TOIKAKEB_O=0x1B,
    DEMO30_INDEX_BRK_30_FD_TOIKAKE2_O=0x1C,
    DEMO30_INDEX_BRK_30_FD_TOIKAKEB2_L=0x1D,
    DEMO30_INDEX_BRK_GDEMO27_TFG00=0x1E,
    
    /* BDLM */
    DEMO30_INDEX_BDL_FD_COMP=0x21,
    DEMO30_INDEX_BDL_GDEMO27_APPR00=0x22,
    DEMO30_INDEX_BDL_GDEMO27_TFG00=0x23,
    
    /* BTK */
    DEMO30_INDEX_BTK_GDEMO27_APPR00=0x26,
};
#else
enum DEMO30_RES_FILE_INDEX {
    /* STB */
    DEMO30_INDEX_STB_DANCE_KOKIRI=0x8,
    
    /* BCKS */
    DEMO30_INDEX_BCK_30_FD_IBARI_L=0xB,
    DEMO30_INDEX_BCK_30_FD_LOOP_L=0xC,
    DEMO30_INDEX_BCK_30_FD_TOIKAKE_O=0xD,
    DEMO30_INDEX_BCK_30_FD_TOIKAKEB2_L=0xE,
    DEMO30_INDEX_BCK_30_FD_TOIKAKE2_O=0xF,
    DEMO30_INDEX_BCK_GDEMO27_APPR00=0x10,
    
    /* BTP */
    DEMO30_INDEX_BTP_30_FD_IBARI_L=0x13,
    DEMO30_INDEX_BTP_30_FD_LOOP_L=0x14,
    DEMO30_INDEX_BTP_30_FD_TOIKAKEB2_L=0x15,
    DEMO30_INDEX_BTP_30_FD_TOIKAKE2_O=0x16,
    
    /* BRK */
    DEMO30_INDEX_BRK_30_FD_LOOP_L=0x19,
    DEMO30_INDEX_BRK_30_FD_TOIKAKE2_O=0x1A,
    DEMO30_INDEX_BRK_30_FD_TOIKAKEB2_L=0x1B,
    DEMO30_INDEX_BRK_GDEMO27_TFG00=0x1C,
    DEMO30_INDEX_BRK_30_FD_IBARI_L=0x1D,
    
    /* BDLM */
    DEMO30_INDEX_BDL_FD_COMP=0x20,
    DEMO30_INDEX_BDL_GDEMO27_APPR00=0x21,
    DEMO30_INDEX_BDL_GDEMO27_TFG00=0x22,
    
    /* BTK */
    DEMO30_INDEX_BTK_GDEMO27_APPR00=0x25,
};
#endif

#endif /* RES_DEMO30_H */
