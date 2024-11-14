#ifndef D_A_DEMO00_H
#define D_A_DEMO00_H

#include "f_op/f_op_actor.h"

class dDemo_actor_c;

class daDemo00_model_c {
public:
    void reset();

public:
    /* Place member variables here */
};

class daDemo00_resID_c {
public:
    void reset();

public:
    /* Place member variables here */
};

class daDemo00_c : public fopAc_ac_c {
    typedef void(daDemo00_c::*actionFunc)(dDemo_actor_c*);

public:
    void action(dDemo_actor_c*) {}
    void setAction(int (daDemo00_c::*)(dDemo_actor_c*)) {}

    void setBaseMtx();
    void setShadowSize();
    void createHeap();
    void actStandby(dDemo_actor_c*);
    void actPerformance(dDemo_actor_c*);
    void actLeaving(dDemo_actor_c*);
    inline BOOL create();
    BOOL draw();
    BOOL execute();

public:
    /* 0x290 */ actionFunc mActionFunc;
    /* 0x29C */ u8 unk29C;
    /* 0x29D */ s8 unk29D;
    /* 0x29E */ u8 unk29E;
    /* 0x29F */ u8 unk29F;
    /* 0x2A0 */ daDemo00_resID_c mResId;
    /* 0x2C8 */ daDemo00_model_c mModel;
    /* 0x314 */ class dBgS_GndChk* mChk;
};

#endif /* D_A_DEMO00_H */
