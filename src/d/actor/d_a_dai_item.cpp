//
// Generated by dtk
// Translation Unit: d_a_dai_item.cpp
//

#include "d/actor/d_a_dai_item.h"
#include "SSystem/SComponent/c_math.h"
#include "d/d_kankyo_wether.h"
#include "d/d_procname.h"
#include "d/d_s_play.h"
#include "d/res/res_fdai.h"
#include "d/res/res_cloth.h"

#include "f_op/f_op_actor.h"
#include "weak_bss_3569.h" // IWYU pragma: keep
#include "weak_data_2100_2080.h" // IWYU pragma: keep

const char daStandItem_c::m_arcname[] = "Fdai";
const s16 daStandItem_c::m_bmdidx[] = {
    FDAI_BDL_FOBJ00, /* FLOWER_1 */
    FDAI_BDL_FOBJ01, /* FLOWER_2 */
    FDAI_BDL_FOBJ02, /* FLOWER_3 */
    FDAI_BDL_FOBJ03, /* HEROS_FLAG */
    FDAI_BDL_FOBJ04, /* TAIRYO_FLAG */
    FDAI_BDL_FOBJ05, /* SALES_FLAG */
    FDAI_BDL_FOBJ06, /* WIND_FLAG */
    FDAI_BDL_FOBJ07, /* RED_FLAG */
    FDAI_BDL_FOBJ08, /* FOSSIL_HEAD */
    FDAI_BDL_FOBJ09, /* WATER_STATUE */
    FDAI_BDL_FOBJ10, /* POSTMAN_STATUE */
    FDAI_BDL_FOBJ11, /* PRESIDENT_STATUE */
};
const s16 daStandItem_c::m_bckidx[] = {
    FDAI_BCK_FOBJ00,  /* FLOWER_1 */
    FDAI_BCK_FOBJ01,  /* FLOWER_2 */
    FDAI_BCK_FOBJ02,  /* FLOWER_3 */
    -1,               /* HEROS_FLAG */
    -1,               /* TAIRYO_FLAG */
    FDAI_BCK_FOBJ05,  /* SALES_FLAG */
    -1,               /* WIND_FLAG */
    FDAI_BCK_FOBJ07,  /* RED_FLAG */
    FDAI_BCK_FOBJ08,  /* FOSSIL_HEAD */
    FDAI_BCK_FOBJ09,  /* WATER_STATUE */
    FDAI_BCK_FOBJ10,  /* POSTMAN_STATUE */
    FDAI_BCK_FOBJ11,  /* PRESIDENT_STATUE */
};
const u16 daStandItem_c::m_heapsize[] = {
    0x2000, /* FLOWER_1 */
    0x2000, /* FLOWER_2 */
    0x2000, /* FLOWER_3 */
    0x2000, /* HEROS_FLAG */
    0x2000, /* TAIRYO_FLAG */
    0x2000, /* SALES_FLAG */
    0x2000, /* WIND_FLAG */
    0x2000, /* RED_FLAG */
    0x2000, /* FOSSIL_HEAD */
    0x2000, /* WATER_STATUE */
    0x2000, /* POSTMAN_STATUE */
    0x2000, /* PRESIDENT_STATUE */
};
const s16 daStandItem_c::m_anim_min_time[] = {
    50, /* FLOWER_1 */
    50, /* FLOWER_2 */
    50, /* FLOWER_3 */
    50, /* HEROS_FLAG */
    50, /* TAIRYO_FLAG */
    50, /* SALES_FLAG */
    50, /* WIND_FLAG */
    50, /* RED_FLAG */
    30, /* FOSSIL_HEAD */
    20, /* WATER_STATUE */
    50, /* POSTMAN_STATUE */
    50, /* PRESIDENT_STATUE */
};
const s16 daStandItem_c::m_anim_max_time[] = {
    100, /* FLOWER_1 */
    100, /* FLOWER_2 */
    100, /* FLOWER_3 */
    100, /* HEROS_FLAG */
    100, /* TAIRYO_FLAG */
    100, /* SALES_FLAG */
    100, /* WIND_FLAG */
    100, /* RED_FLAG */
    100, /* FOSSIL_HEAD */
    20,  /* WATER_STATUE */
    100, /* POSTMAN_STATUE */
    100, /* PRESIDENT_STATUE */
};
const s16 daStandItem_c::m_stop_min_time[] = {
    50,  /* FLOWER_1 */
    50,  /* FLOWER_2 */
    50,  /* FLOWER_3 */
    50,  /* HEROS_FLAG */
    50,  /* TAIRYO_FLAG */
    50,  /* SALES_FLAG */
    50,  /* WIND_FLAG */
    50,  /* RED_FLAG */
    50,  /* FOSSIL_HEAD */
    600, /* WATER_STATUE */
    50,  /* POSTMAN_STATUE */
    0,   /* PRESIDENT_STATUE */
};
const s16 daStandItem_c::m_stop_max_time[] = {
    100,  /* FLOWER_1 */
    100,  /* FLOWER_2 */
    100,  /* FLOWER_3 */
    100,  /* HEROS_FLAG */
    100,  /* TAIRYO_FLAG */
    100,  /* SALES_FLAG */
    100,  /* WIND_FLAG */
    100,  /* RED_FLAG */
    200,  /* FOSSIL_HEAD */
    1000, /* WATER_STATUE */
    100,  /* POSTMAN_STATUE */
    0,    /* PRESIDENT_STATUE */
};

/* 800E3638-800E36C8       .text convItemNo__FUc */
static u32 convItemNo(u8 itemNo) {
    switch (itemNo) {
    case FLOWER_1: return 0;
    case FLOWER_2: return 1;
    case FLOWER_3: return 2;
    case HEROS_FLAG: return 3;
    case TAIRYO_FLAG: return 4;
    case SALES_FLAG: return 5;
    case WIND_FLAG: return 6;
    case RED_FLAG: return 7;
    case FOSSIL_HEAD: return 8;
    case WATER_STATUE: return 9;
    case POSTMAN_STATUE: return 10;
    case PRESIDENT_STATUE: return 11;
    default: return 0;
    }
}

static dCcD_SrcCyl l_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt  Type    */ 0,
        /* SrcObjAt  Atp     */ 0,
        /* SrcObjAt  SPrm    */ 0,
        /* SrcObjTg  Type    */ AT_TYPE_ALL,
        /* SrcObjTg  SPrm    */ cCcD_TgSPrm_Set_e | cCcD_TgSPrm_IsOther_e,
        /* SrcObjCo  SPrm    */ cCcD_CoSPrm_Set_e | cCcD_CoSPrm_IsOther_e | cCcD_CoSPrm_VsEnemy_e | cCcD_CoSPrm_VsPlayer_e | cCcD_CoSPrm_VsOther_e,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt SPrm    */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg SPrm    */ dCcG_TgSPrm_NoHitMark_e,
        /* SrcGObjCo SPrm    */ 0,
    },
    // cM3dGCylS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 0.0f,
        /* Height */ 0.0f,
    },
};

static cXyz Vobj03_pos0[25];
static cXyz Vobj03_pos1[25];

static cXyz Vobj04_pos0[25];
static cXyz Vobj04_pos1[25];

static cXyz Vobj05_pos0[25];
static cXyz Vobj05_pos1[25];

static cXyz Vobj07_0_pos0[25];
static cXyz Vobj07_0_pos1[25];

static cXyz* Vobj03_pos[] = { Vobj03_pos0, Vobj03_pos1, };
static cXyz* Vobj04_pos[] = { Vobj04_pos0, Vobj04_pos1, };
static cXyz* Vobj05_pos[] = { Vobj05_pos0, Vobj05_pos1, };
static cXyz* Vobj07_0_pos[] = { Vobj07_0_pos0, Vobj07_0_pos1, };

static cXyz** VobjFlagPosTbl[] = {
    Vobj03_pos,
    Vobj04_pos,
    Vobj05_pos,
    Vobj07_0_pos,
};

/* 800E36C8-800E3798       .text _delete__13daStandItem_cFv */
bool daStandItem_c::_delete() {
    if (m694 != NULL) {
        m694->becomeInvalidEmitter();
        m694 = NULL;
    }

    if (m690 != NULL) {
        m690->becomeInvalidEmitter();
        m690 = NULL;
    }

    if (m698 != NULL) {
        m698->quitImmortalEmitter();
        m698->becomeInvalidEmitter();
        m698 = NULL;
    }

    dComIfG_resDelete(&mPhsDai, m_arcname);
    dComIfG_resDelete(&mPhsCloth, "Cloth");
    return true;
}

/* 800E3798-800E37B8       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c* i_ac) {
    return ((daStandItem_c*)i_ac)->CreateHeap();
}

/* 800E37B8-800E3AF8       .text CreateHeap__13daStandItem_cFv */
BOOL daStandItem_c::CreateHeap() {
    J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes(m_arcname, m_bmdidx[mItemType]);
    JUT_ASSERT(0x239, modelData != NULL);

    if (mItemNo == PRESIDENT_STATUE) {
        mpModel = mDoExt_J3DModel__create(modelData, 0x0, 0x11020203);
    } else {
        mpModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000022);
    }
    
    if (mpModel == NULL)
        return FALSE;

    if (m_bckidx[mItemType] != -1) {
        J3DAnmTransform* pbck = (J3DAnmTransform*)dComIfG_getObjectRes(m_arcname, m_bckidx[mItemType]);
        JUT_ASSERT(0x250, pbck != NULL);
        mpBckAnm = new mDoExt_bckAnm();

        static const u32 playmode[] = {
            J3DFrameCtrl::LOOP_REPEAT_e, /* FLOWER_1 */
            J3DFrameCtrl::LOOP_REPEAT_e, /* FLOWER_2 */
            J3DFrameCtrl::LOOP_REPEAT_e, /* FLOWER_3 */
            -1,                          /* HEROS_FLAG */
            -1,                          /* TAIRYO_FLAG */
            J3DFrameCtrl::LOOP_REPEAT_e, /* SALES_FLAG */
            J3DFrameCtrl::LOOP_REPEAT_e, /* WIND_FLAG */
            J3DFrameCtrl::LOOP_REPEAT_e, /* RED_FLAG */
            J3DFrameCtrl::LOOP_REPEAT_e, /* FOSSIL_HEAD */
            J3DFrameCtrl::LOOP_ONCE_e,   /* WATER_STATUE */
            J3DFrameCtrl::LOOP_REPEAT_e, /* POSTMAN_STATUE */
            J3DFrameCtrl::LOOP_REPEAT_e, /* PRESIDENT_STATUE */
        };

        if (mpBckAnm == NULL || !mpBckAnm->init(modelData, pbck, TRUE, playmode[mItemType], 1.0f, 0, -1, false))
            return FALSE;

        mpBckAnm->setPlaySpeed(0.0f);
    }

    if (mItemNo == HEROS_FLAG || mItemNo == TAIRYO_FLAG || mItemNo == SALES_FLAG || mItemNo == RED_FLAG) {
        typedef dCloth_packet_c* (*ClothFunc)(ResTIMG*, ResTIMG*, dKy_tevstr_c*, cXyz**);

        ClothFunc clothFunc[] = {
            (ClothFunc)dClothVobj03_create,
            (ClothFunc)dClothVobj04_create,
            (ClothFunc)dClothVobj05_create,
            (ClothFunc)dClothVobj07_0_create,
        };

        u32 clothTimgRes[] = {
            FDAI_BTI_FTEX03,
            FDAI_BTI_FTEX04,
            FDAI_BTI_FTEX05,
            FDAI_BTI_FTEX07,
        };

        switch (mItemNo) {
            case HEROS_FLAG:
                mClothType = 0;
                break;
            case TAIRYO_FLAG:
                mClothType = 1;
                break;
            case SALES_FLAG:
                mClothType = 2;
                break;
            default:
            case RED_FLAG:
                mClothType = 3;
                break;
        }

        ResTIMG* clothTimg = (ResTIMG*)dComIfG_getObjectRes(m_arcname, clothTimgRes[mClothType]);
        ResTIMG* clothToonTimg = (ResTIMG*)dComIfG_getObjectRes("Cloth", CLOTH_BTI_CLOTHTOON);
        mpCloth = clothFunc[mClothType](clothTimg, clothToonTimg, &tevStr, VobjFlagPosTbl[mClothType]);
        if (mpCloth == NULL)
            return FALSE;
    } else {
        mpCloth = NULL;
    }

    return TRUE;
}

/* 800E3AF8-800E3E94       .text CreateInit__13daStandItem_cFv */
void daStandItem_c::CreateInit() {
    fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
    fopAcM_setCullSizeBox(this, -100.0f, -0.0f, -100.0f, 100.0f, 300.0f, 100.0f);
    mAcchCir.SetWall(30.0f, 30.0f);
    mAcch.Set(&current.pos, &old.pos, this, 1, &mAcchCir, &speed);
    if (fopAcM_checkCarryNow(this))
        mode_carry_init();
    else
        mode_wait_init();

    mCarry = 0;
    m6A4 = *dKyw_get_wind_vec();
    m6A2 = cM_atan2s(m6A4.x, m6A4.z);
    set_mtx();
    mpModel->setUserArea(NULL);

    JUTNameTab* jointNameTab = mpModel->getModelData()->getJointName();
    const char* jointName;
    u16 i;
    switch (mItemNo) {
    case WIND_FLAG:
        {
            for (i = 0; i < mpModel->getModelData()->getJointNum(); i++) {
                jointName = jointNameTab->getName(i);
                if (strcmp("top", jointName) == 0) {
                    mpModel->getModelData()->getJointNodePointer(i)->setCallBack(daiItemNodeCallBack);
                    break;
                }
            }
            mpModel->setUserArea((u32)this);
            mpModel->calc();
        }
        break;
    case WATER_STATUE:
        {
            for (i = 0; i < mpModel->getModelData()->getJointNum(); i++) {
                jointName = jointNameTab->getName(i);
                if (strcmp("tuboko_head", jointName) == 0 || strcmp("tuboko_base", jointName) == 0)
                    mpModel->getModelData()->getJointNodePointer(i)->setCallBack(daiItemNodeCallBack);
            }
            mpModel->setUserArea((u32)this);
            mpModel->calc();
        }
        break;
    }

    m6BC = dKyw_get_wind_pow();

    s16 animMinTime = m_anim_min_time[mItemType];
    s16 animMaxTime = m_anim_max_time[mItemType];
    s16 stopMinTime = m_stop_min_time[mItemType];
    s16 stopMaxTime = m_stop_max_time[mItemType];
    s16 r29 = (animMinTime + animMaxTime) / 2;
    s16 r28 = (animMaxTime - animMinTime) / 2;
    s16 temp = (stopMaxTime - stopMinTime) / 2;
    mBckPlayTimer = 0;
    f32 temp2 = cM_rndFX(temp);
    s16 temp3 = (stopMinTime + stopMaxTime) / 2;
    mBckStopTimer = temp3 + temp2;
    if (stopMaxTime == 0) {
        mBckPlayTimer = r29 + cM_rndFX(r28);
    }

    m690 = NULL;
    m694 = NULL;
    m698 = NULL;
    g_env_light.settingTevStruct(TEV_TYPE_ACTOR, &current.pos, &tevStr);
}

/* 800E3E94-800E4048       .text _create__13daStandItem_cFv */
s32 daStandItem_c::_create() {
    fopAcM_SetupActor(this, daStandItem_c);

    mItemNo = fopAcM_GetParam(this);
    mItemType = convItemNo(mItemNo);

    s32 rt = dComIfG_resLoad(&mPhsDai, m_arcname);
    if (rt != cPhs_COMPLEATE_e)
        return rt;

    s32 cloth_rt = dComIfG_resLoad(&mPhsCloth, "Cloth");
    if (cloth_rt != cPhs_COMPLEATE_e)
        return cloth_rt;

    if (rt == cPhs_COMPLEATE_e && cloth_rt == cPhs_COMPLEATE_e) {
        if (!fopAcM_entrySolidHeap(this, CheckCreateHeap, m_heapsize[mItemType]))
            return cPhs_ERROR_e;
        CreateInit();
    }
    return rt;
}

/* 800E4114-800E443C       .text set_mtx__13daStandItem_cFv */
void daStandItem_c::set_mtx() {
    mpModel->setBaseScale(scale);
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::ZXYrotM(current.angle);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
    if (mpCloth != NULL) {
        cXyz offs[4];
        offs[0] = cXyz(0.0f, REG10_F(15) + 180.0f, 0.0f);
        offs[1] = cXyz(0.0f, REG10_F(15) + 180.0f, 0.0f);
        offs[2] = cXyz(0.0f, REG10_F(15) + 195.0f, 0.0f);
        offs[3] = cXyz(0.0f, REG10_F(15) + 180.0f, 0.0f);

        cXyz wind;
        cXyz pt = current.pos + offs[mClothType];
        wind = dKyw_get_AllWind_vecpow(&pt);
        f32 windStrength = wind.abs();
        f32 currStrength = m6A4.abs();

        if (windStrength - currStrength > 0.25f) {
            m6A4 = wind;
            s16 windAngle = cM_atan2s(m6A4.x, m6A4.z);
            cLib_addCalcAngleS2(&m6A2, windAngle, 4, 0x1000);
        } else {
            cLib_addCalcPos2(&m6A4, wind, 0.1f, 0.1f);
            s16 windAngle = cM_atan2s(m6A4.x, m6A4.z);
            cLib_addCalcAngleS2(&m6A2, windAngle, 16, 0x400);
        }

        mDoMtx_stack_c::transM(offs[mClothType]);
        mDoMtx_stack_c::YrotM(m6A2 - current.angle.y);
        mpCloth->setMtx(mDoMtx_stack_c::get());
    }
}

/* 800E443C-800E44A4       .text _execute__13daStandItem_cFv */
bool daStandItem_c::_execute() {
    mTimer++;
    execAction();
    itemProc();
    set_mtx();
    if (mpCloth != NULL)
        mpCloth->cloth_move();
    return true;
}

typedef bool (daStandItem_c::* ActionFunc)();
static const ActionFunc item_action_tbl[] = {
    &daStandItem_c::actionFobj00,
    &daStandItem_c::actionFobj01,
    &daStandItem_c::actionFobj02,
    &daStandItem_c::actionFobj03,
    &daStandItem_c::actionFobj04,
    &daStandItem_c::actionFobj05,
    &daStandItem_c::actionFobj06,
    &daStandItem_c::actionFobj07,
    &daStandItem_c::actionFobj08,
    &daStandItem_c::actionFobj09,
    &daStandItem_c::actionFobj10,
    &daStandItem_c::actionFobj11,
};

/* 800E44A4-800E4518       .text itemProc__13daStandItem_cFv */
void daStandItem_c::itemProc() {
    if (mMode == 1 && item_action_tbl[mItemType] != NULL)
        (this->*(item_action_tbl[mItemType]))();
}

/* 800E4518-800E453C       .text actionFobj00__13daStandItem_cFv */
bool daStandItem_c::actionFobj00() {
    animTest();
    return true;
}

/* 800E453C-800E4560       .text actionFobj01__13daStandItem_cFv */
bool daStandItem_c::actionFobj01() {
    animTest();
    return true;
}

/* 800E4560-800E4584       .text actionFobj02__13daStandItem_cFv */
bool daStandItem_c::actionFobj02() {
    animTest();
    return true;
}

/* 800E4584-800E458C       .text actionFobj03__13daStandItem_cFv */
bool daStandItem_c::actionFobj03() {
    return true;
}

/* 800E458C-800E4594       .text actionFobj04__13daStandItem_cFv */
bool daStandItem_c::actionFobj04() {
    return true;
}

/* 800E4594-800E45E0       .text actionFobj05__13daStandItem_cFv */
bool daStandItem_c::actionFobj05() {
    f32 windPow = dKyw_get_wind_pow();
    if (mpBckAnm != NULL && windPow > 0.0f)
        mpBckAnm->play();
    return true;
}

/* 800E45E0-800E4770       .text actionFobj06__13daStandItem_cFv */
bool daStandItem_c::actionFobj06() {
    cXyz wind = dKyw_get_AllWind_vecpow(&current.pos);
    f32 windStrength = wind.absXZ();
    cXyz zero(0.0f, 0.0f, 0.0f);
    s16 angle = cLib_targetAngleY(&zero, &wind);
    cLib_distanceAngleS(angle, current.angle.y);
    f32 temp = 1.0f;
    m6C4 += fabs(windStrength * temp);
    if (m6C4 > 4.0f) {
        m6C4 = 4.0f;
    }

    m6B2 = m6C4 * 0x600;
    cLib_addCalc(&m6C4, 0.0f, 0.08f, dKyw_get_wind_pow() + 0.3f, dKyw_get_wind_pow() + 0.1f);
    m6B4 += m6B2;
    return true;
}

/* 800E4770-800E47BC       .text actionFobj07__13daStandItem_cFv */
bool daStandItem_c::actionFobj07() {
    f32 windPow = dKyw_get_wind_pow();
    if (mpBckAnm != NULL && windPow > 0.0f)
        mpBckAnm->play();
    return true;
}

/* 800E47BC-800E47E0       .text actionFobj08__13daStandItem_cFv */
bool daStandItem_c::actionFobj08() {
    animTest();
    return true;
}

/* 800E47E0-800E4B94       .text actionFobj09__13daStandItem_cFv */
bool daStandItem_c::actionFobj09() {
    fopAc_ac_c* link = dComIfGp_getLinkPlayer();
    f32 f31 = (link->current.pos - current.pos).absXZ();
    animTestForOneTime();
    if (f31 < 500.0f && !mbBckDidPlay) {
        if (m694) {
            m694->becomeInvalidEmitter();
            m694 = NULL;
        }
        if (m698) {
            m698->quitImmortalEmitter();
            m698->becomeInvalidEmitter();
            m698 = NULL;
        }
        if (m690 == NULL) {
            m690 = dComIfGp_particle_set(0x82B3, &current.pos, &current.angle, NULL, 0xFF, NULL, fopAcM_GetRoomNo(this), &tevStr.mColorK0);
        } else {
            m690->setGlobalRTMatrix(m660);
        }
    } else if (!mbBckDidPlay) {
        if (m690) {
            m690->becomeInvalidEmitter();
            m690 = NULL;
        }
        if (m694) {
            m694->becomeInvalidEmitter();
            m694 = NULL;
        }
        if (m698) {
            m698->quitImmortalEmitter();
            m698->becomeInvalidEmitter();
            m698 = NULL;
        }
    } else if (mbBckDidPlay) {
        if (!m6B1) {
            if (m690) {
                m690->becomeInvalidEmitter();
                m690 = NULL;
            }
            if (m694 == NULL) {
                m694 = dComIfGp_particle_set(0x82B4, &current.pos, &current.angle, NULL, 0xFF, NULL, fopAcM_GetRoomNo(this), &tevStr.mColorK0);
            }
            if (m698 == NULL) {
                m698 = dComIfGp_particle_set(0x82B5, &current.pos, &current.angle);
            }
            if (m698) {
                m698->becomeImmortalEmitter();
            }
        }
        if (m694) {
            m694->setGlobalRTMatrix(m660);
        }
        if (m698) {
            m698->setGlobalRTMatrix(m630);
        }
    }
    m6B1 = mbBckDidPlay;
    return true;
}

/* 800E4B94-800E4BB8       .text actionFobj10__13daStandItem_cFv */
bool daStandItem_c::actionFobj10() {
    animTest();
    return true;
}

/* 800E4BB8-800E4BE4       .text actionFobj11__13daStandItem_cFv */
bool daStandItem_c::actionFobj11() {
    mBckSpeed = 1.0f;
    animTest();
    return true;
}

/* 800E4BE4-800E4E44       .text animTest__13daStandItem_cFv */
void daStandItem_c::animTest() {
    s16 animMinTime = m_anim_min_time[mItemType];
    s16 animMaxTime = m_anim_max_time[mItemType];
    s16 stopMinTime = m_stop_min_time[mItemType];
    s16 stopMaxTime = m_stop_max_time[mItemType];
    mbBckDidPlay = false;
    
    if (mBckPlayTimer > 0) {
        mBckPlayTimer--;
        if (mpBckAnm) {
            mpBckAnm->play();
            mbBckDidPlay = true;
        }
        if (stopMaxTime == 0) {
            mBckPlayTimer = 16;
            mpBckAnm->setPlaySpeed(1.0f);
        }
        if (mBckPlayTimer < 15 && stopMaxTime != 0) {
            cLib_addCalc(&mBckSpeed, 0.0f, 0.1f, 0.1f, 0.05f);
            mpBckAnm->setPlaySpeed(mBckSpeed);
        }
        if (mBckSpeed == 0.0f || mBckPlayTimer == 0) {
            mpBckAnm->setPlaySpeed(0.0f);
            s16 temp = (stopMaxTime - stopMinTime) / 2;
            s16 temp2 = (stopMinTime + stopMaxTime) / 2;
            mBckStopTimer = temp2 + cM_rndFX(temp);
        }
    } else if (mBckStopTimer > 0) {
        mBckStopTimer--;
        if (animMaxTime == 0) {
            mBckStopTimer = 1;
        }
        if (mBckStopTimer == 0) {
            s16 temp = (animMaxTime - animMinTime) / 2;
            s16 temp2 = (animMinTime + animMaxTime) / 2;
            mBckPlayTimer = temp2 + cM_rndFX(temp);
            mBckSpeed = 1.0f;
            if (mpBckAnm) {
                mpBckAnm->setPlaySpeed(mBckSpeed);
            }
        }
    }
}

/* 800E4E44-800E509C       .text animTestForOneTime__13daStandItem_cFv */
void daStandItem_c::animTestForOneTime() {
    s16 animMinTime = m_anim_min_time[mItemType];
    s16 animMaxTime = m_anim_max_time[mItemType];
    s16 stopMinTime = m_stop_min_time[mItemType];
    s16 stopMaxTime = m_stop_max_time[mItemType];
    mbBckDidPlay = false;
    BOOL isStop = mpBckAnm->play();
    
    if (mBckStopTimer > 0) {
        mBckStopTimer--;
        if (mBckStopTimer == 0) {
            mpBckAnm->setPlaySpeed(1.0f);
            mpBckAnm->setFrame(0.0f);
            s16 temp = (animMaxTime - animMinTime) / 2;
            s16 temp2 = (animMinTime + animMaxTime) / 2;
            mBckPlayTimer = temp2 + cM_rndFX(temp);
        }
    } else if (mBckPlayTimer > 0) {
        mBckPlayTimer--;
        if (mBckPlayTimer > 0 && isStop) {
            mpBckAnm->setPlaySpeed(1.0f);
            mpBckAnm->setFrame(0.0f);
        } else if (mBckPlayTimer == 0 && isStop) {
            s16 temp = (stopMaxTime - stopMinTime) / 2;
            s16 temp2 = (stopMinTime + stopMaxTime) / 2;
            mBckStopTimer = temp2 + cM_rndFX(temp);
        } else if (mBckPlayTimer == 0) {
            mBckPlayTimer = 1;
        }
    }
    
    if (stopMaxTime == 0 && isStop) {
        mpBckAnm->setPlaySpeed(1.0f);
        mpBckAnm->setFrame(0.0f);
    }
    if (!isStop) {
        mbBckDidPlay = true;
    }
}

/* 800E509C-800E5190       .text execAction__13daStandItem_cFv */
void daStandItem_c::execAction() {
    typedef void (daStandItem_c::*ModeFunc)();
    static const ModeFunc mode_proc[] = {
        &daStandItem_c::mode_carry,
        &daStandItem_c::mode_wait,
        &daStandItem_c::mode_drop,
    };

    bool carry = fopAcM_checkCarryNow(this);
    if (carry && !mCarry)
        mode_carry_init();
    if (mCarry && !carry)
        mode_wait_init();

    (this->*(mode_proc[mMode]))();
    mCarry = carry;
}

/* 800E5190-800E51D8       .text mode_carry_init__13daStandItem_cFv */
void daStandItem_c::mode_carry_init() {
    fopAcM_SetSpeedF(this, 0.0f);
    speed = cXyz::Zero;
    attention_info.flags &= ~fopAc_Attn_ACTION_CARRY_e;
    mCyl.OffCoSetBit();
    mMode = 0;
}

/* 800E51D8-800E5204       .text mode_carry__13daStandItem_cFv */
void daStandItem_c::mode_carry() {
    if (!fopAcM_checkCarryNow(this))
        mode_drop_init();
}

/* 800E5204-800E5230       .text mode_wait_init__13daStandItem_cFv */
void daStandItem_c::mode_wait_init() {
    fopAcM_SetSpeedF(this, 0.0f);
    fopAcM_SetSpeed(this, 0.0f, 0.0f, 0.0f);
    mCyl.OnCoSetBit();
    mMode = 1;
}

/* 800E5230-800E5234       .text mode_wait__13daStandItem_cFv */
void daStandItem_c::mode_wait() {
}

/* 800E5234-800E5240       .text mode_drop_init__13daStandItem_cFv */
void daStandItem_c::mode_drop_init() {
    mMode = 2;
}

/* 800E5240-800E52D0       .text mode_drop__13daStandItem_cFv */
void daStandItem_c::mode_drop() {
    fopAcM_posMoveF(this, NULL);
    mAcch.CrrPos(*dComIfG_Bgsp());
    if (mAcch.ChkGroundHit()) {
        fopAcM_seStart(this, JA_SE_LK_W_DAIZA_ATTACH, 0);
        mode_wait_init();
    }
}

/* 800E52D0-800E53B8       .text _draw__13daStandItem_cFv */
bool daStandItem_c::_draw() {
    g_env_light.settingTevStruct(TEV_TYPE_ACTOR, &current.pos, &tevStr);
    g_env_light.setLightTevColorType(mpModel, &tevStr);
    if (mItemNo == WIND_FLAG)
        mpModel->getModelData()->getJointNodePointer(0)->setMtxCalc(NULL);
    else if (mpBckAnm != NULL)
        mpBckAnm->entry(mpModel->getModelData());

    if (mItemNo == PRESIDENT_STATUE)
        dDlst_texSpecmapST(&eyePos, &tevStr, mpModel->getModelData(), 1.0f);

    mDoExt_modelUpdateDL(mpModel);
    if (mpCloth != NULL)
        mpCloth->cloth_draw();

    return true;
}

/* 800E53B8-800E53D8       .text daStandItem_Create__FPv */
static s32 daStandItem_Create(void* i_this) {
    return ((daStandItem_c*)i_this)->_create();
}

/* 800E53D8-800E53FC       .text daStandItem_Delete__FPv */
static BOOL daStandItem_Delete(void* i_this) {
    return ((daStandItem_c*)i_this)->_delete();
}

/* 800E53FC-800E5420       .text daStandItem_Draw__FPv */
static BOOL daStandItem_Draw(void* i_this) {
    return ((daStandItem_c*)i_this)->_draw();
}

/* 800E5420-800E5444       .text daStandItem_Execute__FPv */
static BOOL daStandItem_Execute(void* i_this) {
    return ((daStandItem_c*)i_this)->_execute();
}

/* 800E5444-800E544C       .text daStandItem_IsDelete__FPv */
static BOOL daStandItem_IsDelete(void* i_this) {
    return TRUE;
}

static actor_method_class daStandItemMethodTable = {
    (process_method_func)daStandItem_Create,
    (process_method_func)daStandItem_Delete,
    (process_method_func)daStandItem_Execute,
    (process_method_func)daStandItem_IsDelete,
    (process_method_func)daStandItem_Draw,
};

actor_process_profile_definition g_profile_STANDITEM = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0008,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_STANDITEM,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daStandItem_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0101,
    /* Actor SubMtd */ &daStandItemMethodTable,
    /* Status       */ fopAcStts_NOCULLEXEC_e | fopAcStts_CULL_e | fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
