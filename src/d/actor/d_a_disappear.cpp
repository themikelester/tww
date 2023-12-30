//
// Generated by dtk
// Translation Unit: d_a_disappear.cpp
//

#include "d/actor/d_a_disappear.h"
#include "f_op/f_op_actor.h"
#include "f_op/f_op_actor_mng.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "d/d_s_play.h"
#include "m_Do/m_Do_ext.h"
#include "dolphin/types.h"

/* 800E79C0-800E79C8       .text daDisappear_Draw__FP15disappear_class */
static BOOL daDisappear_Draw(disappear_class*) {
    return TRUE;
}

/* 800E79C8-800E7AC0       .text daDisappear_Execute__FP15disappear_class */
static BOOL daDisappear_Execute(disappear_class* i_this) {
    if (i_this->mTimer != 0) {
        i_this->mTimer--;
        
        if (i_this->mTimer == 0) {
            s8 health = i_this->mHealth;

            if (health != 1 && health != 3) {
                if (health == 2) {
                    fopAcM_createItemForBoss(&i_this->current.pos, 0, i_this->current.roomNo, &i_this->current.angle);
                }
                else if (health >= 0x0A && health <= 0x0D) {
                    if (health < 0x0D) {
                        static u32 ki_item_d[] = {
                            0, 10, 16
                        };

                        fopAcM_createItem(&i_this->current.pos, ki_item_d[health - 0xA], -1, -1, 0, NULL, 4);
                    }
                }
                else {
                    fopAcM_createIball(&i_this->current.pos, i_this->mItemTableIdx, i_this->current.roomNo, &i_this->current.angle, i_this->mSwitchNo);
                }
            }
        }
    }
    else {
        fopAcM_delete(i_this);
    }

    return TRUE;
}

/* 800E7AC0-800E7AC8       .text daDisappear_IsDelete__FP15disappear_class */
static BOOL daDisappear_IsDelete(disappear_class*) {
    return TRUE;
}

/* 800E7AC8-800E7AD0       .text daDisappear_Delete__FP15disappear_class */
static BOOL daDisappear_Delete(disappear_class*) {
    return TRUE;
}

/* 800E7AD0-800E7DBC       .text set_disappear__FP15disappear_classf */
void set_disappear(disappear_class* i_this, float scale) {
    fopAcM_seStart(i_this, JA_SE_CM_MONS_EXPLODE, 0);

    cXyz particleScale(scale, scale, scale);
    i_this->mTimer = 58 + g_regHIO.mChild[8].mShortRegs[0];

    switch (i_this->mHealth) {
        case 0:
        case 2:
        case 10:
        case 0xB:
        case 0xC:
        case 0xD:
            dComIfGp_particle_set(0x14, &i_this->current.pos, NULL, &particleScale);
        case 3:
            dComIfGp_particle_set(0x13, &i_this->current.pos, NULL, &particleScale);
            dComIfGp_particle_setStripes(0x15, &i_this->current.pos, NULL, &particleScale, 0xFF, 0x96);
            dComIfGp_particle_set(0x16, &i_this->current.pos, NULL, &particleScale);
            break;
        case 1:
            dComIfGp_particle_set(0x13, &i_this->current.pos, NULL, &particleScale);
            dComIfGp_particle_set(0x16, &i_this->current.pos, NULL, &particleScale);
            break;
        case 4:
            dComIfGp_particle_set(0x043C, &i_this->current.pos);
            dComIfGp_particle_set(0x043D, &i_this->current.pos);
            dComIfGp_particle_set(0x043E, &i_this->current.pos);
            break;
    }
}

/* 800E7DBC-800E7E60       .text daDisappear_Create__FP10fopAc_ac_c */
static s32 daDisappear_Create(fopAc_ac_c* i_this) {
    disappear_class* dis = static_cast<disappear_class*>(i_this);

    fopAcM_SetupActor(dis, disappear_class);

    u32 params = dis->mBase.mParameters;

    dis->mHealth = dis->mBase.mParameters & 0xFF;
    float scale = ((dis->mBase.mParameters >> 8) & 0xFF) * 0.1f;

    dis->mSwitchNo = (dis->mBase.mParameters >> 0x10) & 0xFF;
    if (dis->mSwitchNo == 0xFF) {
        dis->mSwitchNo = -1;
    }

    set_disappear(dis, scale);
    return cPhs_COMPLEATE_e;
}

actor_method_class l_daDisappear_Method = {
    (process_method_func)daDisappear_Create,
    (process_method_func)daDisappear_Delete,
    (process_method_func)daDisappear_Execute,
    (process_method_func)daDisappear_IsDelete,
    (process_method_func)daDisappear_Draw,
};

actor_process_profile_definition g_profile_DISAPPEAR = {
    fpcLy_CURRENT_e,
    7,
    fpcLy_CURRENT_e,
    PROC_DISAPPEAR,
    &g_fpcLf_Method.mBase,
    sizeof(disappear_class),
    0,
    0,
    &g_fopAc_Method.base,
    0x0188,
    &l_daDisappear_Method,
    fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_0_e,
};
