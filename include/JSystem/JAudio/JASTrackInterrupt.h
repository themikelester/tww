#ifndef JASTRACKINTERRUPT_H
#define JASTRACKINTERRUPT_H

#include "dolphin/types.h"

namespace JASystem {
    class TIntrMgr {
    public:
        void disable() { field_0x0 = 0; }
        void enable() { field_0x0 = 1; }
        void setTimer(u32 param_1, u32 param_2) {
            field_0x3 = param_1;
            field_0x4 = param_2;
            field_0x8 = param_2;
        }

        void init();
        void request(u32);
        void setIntr(u32, void*);
        void resetInter(u32);
        void* checkIntr();
        void timerProcess();

        /* 0x00 */ u8 field_0x0;
        /* 0x01 */ u8 field_0x1;
        /* 0x02 */ u8 field_0x2;
        /* 0x03 */ u8 field_0x3;
        /* 0x04 */ u32 field_0x4;
        /* 0x08 */ u32 field_0x8;
        /* 0x0C */ void* field_0xc[8];
    };
}

#endif /* JASTRACKINTERRUPT_H */
