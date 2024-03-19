//
// Generated by dtk
// Translation Unit: d_a_player_npc.cpp
//

#include "d/actor/d_a_player_npc.h"
#include "d/d_com_inf_game.h"
#include "m_Do/m_Do_lib.h"
#include "SSystem/SComponent/c_counter.h"
#include "d/d_procname.h"

/* 8015A37C-8015A448       .text check_initialRoom__10daPy_npc_cFv */
int daPy_npc_c::check_initialRoom() {
    if (home.roomNo < 0) {
        mAcch.CrrPos(*dComIfG_Bgsp());
        if (mAcch.GetGroundH() == -1000000000.0f || dComIfG_Bgsp()->GetGroundCode(mAcch.m_gnd) == 4) {
            return 0;
        } else {
            int roomNo = dComIfG_Bgsp()->GetRoomId(mAcch.m_gnd);
            if (roomNo < 0 || !dComIfGp_roomControl_checkStatusFlag(roomNo, 0x10)) {
                return 0;
            } else {
                fopAcM_SetHomeRoomNo(this, roomNo);
                fopAcM_SetRoomNo(this, roomNo);
                return -1;
            }
        }
    }
    return 1;
}

/* 8015A448-8015A524       .text check_moveStop__10daPy_npc_cFv */
BOOL daPy_npc_c::check_moveStop() {
    int roomNo = current.roomNo;
    BOOL hasBgW = dComIfGp_roomControl_checkStatusFlag(roomNo, 0x10);
    if ((roomNo < 0 || !hasBgW)) {
        if (!hasBgW || m4E8 >= 30) {
            current = home;
            shape_angle = home.angle;
            speedF = 0.0f;
            m4E8 = 0;
        }
        if (dComIfGp_getPlayer(0)->eventInfo.mCommand != dEvtCmd_INDOOR_e) {
            offNpcCallCommand();
        }
        return TRUE;
    }
    return FALSE;
}

/* 8015A524-8015A590       .text setRestart__10daPy_npc_cFSc */
void daPy_npc_c::setRestart(s8 option) {
    if (option == dComIfGs_getRestartOption()) {
        bool playerInDoor = dComIfGp_getPlayer(0)->eventInfo.checkCommandDoor();
        s8 roomNo = current.roomNo;
        s8 optionRoomNo = dComIfGs_getRestartOptionRoomNo();
        if (!playerInDoor && roomNo != optionRoomNo) {
            unconditionalSetRestart(option);
        }
    }
}

/* 8015A590-8015A624       .text unconditionalSetRestart__10daPy_npc_cFSc */
void daPy_npc_c::unconditionalSetRestart(s8 option) {
    dComIfGs_setRestartOption(option);
    dComIfGs_setPlayerPriest(option, dComIfGs_getRestartOptionPos(), dComIfGs_getRestartOptionAngleY(), dComIfGs_getRestartOptionRoomNo());
    home.pos = dComIfGs_getRestartOptionPos();
    home.angle.y = dComIfGs_getRestartOptionAngleY();
    home.roomNo = dComIfGs_getRestartOptionRoomNo();
}

/* 8015A624-8015A6A4       .text setOffsetHomePos__10daPy_npc_cFv */
void daPy_npc_c::setOffsetHomePos() {
    static cXyz l_offsetPos(100.0f, 0.0f, 0.0f);
    cLib_offsetPos(&home.pos, &home.pos, home.angle.y, &l_offsetPos);
}

/* 8015A6A4-8015AA0C       .text setPointRestart__10daPy_npc_cFsSc */
void daPy_npc_c::setPointRestart(s16 i_point, s8 option) {
    JUT_ASSERT(157, dComIfGp_getStagePlayer() != 0);
    stage_scls_info_dummy_class* sclsinfo = dComIfGp_getStageSclsInfo();
    JUT_ASSERT(159, sclsinfo != 0);
    
    JUT_ASSERT(161, 0 <= i_point && i_point < sclsinfo->num);
    stage_scls_info_class* scls_data = sclsinfo->m_entries;
    JUT_ASSERT(163, scls_data != 0);
    
    stage_actor_data_class* player_data = dComIfGp_getStagePlayer()->m_entries;
    int scls_start_code = scls_data[i_point].mStart;
    int i;
    for (i = 0; i < dComIfGp_getStagePlayerNum(); i++) {
        u8 plyr_start_code = player_data->mAngle.z & 0xFF;
        if (plyr_start_code == scls_start_code) {
            break;
        }
        player_data++;
    }
    JUT_ASSERT(174, i != dComIfGp_getStagePlayerNum());
    
    home.pos = player_data->mSpawnPos;
    home.angle.y = player_data->mAngle.y;
    home.roomNo = -1;
    setOffsetHomePos();
    current = home;
    old = home;
    shape_angle = home.angle;
    
    dComIfGs_setRestartOption(&home.pos, home.angle.y, -1, option);
    dComIfGs_setPlayerPriest(option, dComIfGs_getRestartOptionPos(), dComIfGs_getRestartOptionAngleY(), dComIfGs_getRestartOptionRoomNo());
    fopAcM_setStageLayer(this);
}

/* 8015AA0C-8015AB28       .text checkRestart__10daPy_npc_cFSc */
BOOL daPy_npc_c::checkRestart(s8 option) {
    if (option == dComIfGs_getRestartOption()) {
        s16 option_point = dComIfGs_getRestartOptionPoint();
        if (option_point < 0) {
            home.pos = dComIfGs_getRestartOptionPos();
            home.angle.y = dComIfGs_getRestartOptionAngleY();
            home.roomNo = dComIfGs_getRestartOptionRoomNo();
            current = home;
            old = home;
            shape_angle = home.angle;
        } else {
            setPointRestart(option_point, 1);
        }
        return TRUE;
    }
    return FALSE;
}

/* 8015AB28-8015ABD8       .text initialRestartOption__10daPy_npc_cFSci */
BOOL daPy_npc_c::initialRestartOption(s8 option, int save) {
    fopAc_ac_c* partner = dComIfGp_getCb1Player();
    if (!partner) {
        dComIfGp_setCb1Player(this);
        if (save && option != dComIfGs_getRestartOption()) {
            s16 rotY;
            s8 roomNo = current.roomNo;
            rotY = home.angle.y;
            dComIfGs_setRestartOption(&home.pos, rotY, roomNo, option);
        }
        return TRUE;
    }
    return FALSE;
}

/* 8015ABD8-8015AC74       .text checkNowPosMove__10daPy_npc_cFPCc */
BOOL daPy_npc_c::checkNowPosMove(const char* pName) {
    if (!dComIfGp_event_runCheck()) {
        return TRUE;
    }
    if (eventInfo.checkCommandTalk()) {
        return TRUE;
    }
    if (isEventAccept() && !isReturnLink()) {
        return TRUE;
    }
    
    int evtStaffId = dComIfGp_evmng_getMyStaffId(pName);
    if (evtStaffId != -1) {
        return TRUE;
    }
    
    return fopAcM_CheckStatus(this, fopAcStts_UNK800_e);
}

/* 8015AC74-8015AD20       .text drawDamageFog__10daPy_npc_cFv */
void daPy_npc_c::drawDamageFog() {
    if (mDamageFogTimer == 0) {
        return;
    }
    
    cXyz camPos;
    mDoLib_pos2camera(&current.pos, &camPos);
    f32 adjust = fabsf(cM_ssin(g_Counter.mTimer * 0x800));
    tevStr.mFogColor.r = 255;
    tevStr.mFogColor.g = 60;
    tevStr.mFogColor.b = 60;
    
    tevStr.mFogStartZ = (-camPos.z - 200.0f) + 200.0f * adjust;
    tevStr.mFogEndZ = tevStr.mFogStartZ + 300.0f;
}

/* 8015AD20-8015AEF8       .text chkMoveBlock__10daPy_npc_cFP4cXyz */
int daPy_npc_c::chkMoveBlock(cXyz* outBlockVel) {
    cXyz blockRelPos;
    fopAc_ac_c* block = daPy_npc_SearchAreaByName(this, PROC_Obj_Movebox, 300.0f, &blockRelPos);
    if (block) {
        cXyz blockVel = block->current.pos - block->old.pos;
        if (blockVel.abs() > 0.001f) {
            if (outBlockVel) {
                *outBlockVel = blockVel;
            }
            
            blockRelPos.normalizeZP();
            blockVel.normalizeZP();
            f32 dot = blockRelPos.getDotProduct(blockVel);
            
            blockVel.y = 0.0f;
            blockRelPos.y = 0.0f;
            cXyz cross = blockRelPos.outprod(blockVel);
            
            if (dot < -0.707099974155426f) {
                if (cross.y < 0.0f) {
                    return -1;
                } else {
                    return 1;
                }
            }
            
            if (block->current.pos.y > current.pos.y + 100.0f) {
                if (cross.y < 0.0f) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

struct judge_parm_c {
    /* 0x00 */ s16 mProcName;
    /* 0x04 */ cXyz mAreaCenter;
    /* 0x10 */ cXyz mActorRelPos;
    /* 0x1C */ f32 mAreaRadius;
    /* 0x20 */ f32 mMinDist;
    /* 0x24 */ fopAc_ac_c* mpActor;
};

/* 8015AEF8-8015B00C       .text daPy_npc_JudgeForPNameAndDistance__FPvPv */
void* daPy_npc_JudgeForPNameAndDistance(void* i_actor, void* i_prm) {
    fopAc_ac_c* actor = (fopAc_ac_c*)i_actor;
    judge_parm_c* prm = (judge_parm_c*)i_prm;
    
    if (fopAcM_GetName(actor) == prm->mProcName) {
        cXyz actorOffset = actor->current.pos - prm->mAreaCenter;
        f32 dist = actorOffset.abs();
        if (dist < prm->mAreaRadius && dist < prm->mMinDist) {
            prm->mMinDist = dist;
            prm->mpActor = actor;
            prm->mActorRelPos = actorOffset;
        }
    }
    
    return NULL;
}

/* 8015B00C-8015B0A4       .text daPy_npc_SearchAreaByName__FP10fopAc_ac_csfP4cXyz */
fopAc_ac_c* daPy_npc_SearchAreaByName(fopAc_ac_c* i_this, s16 procName, f32 areaRadius, cXyz* outActorRelPos) {
    judge_parm_c prm;
    prm.mProcName = procName;
    prm.mAreaCenter = i_this->current.pos;
    prm.mAreaRadius = areaRadius;
    prm.mMinDist = areaRadius;
    prm.mpActor = NULL;
    prm.mActorRelPos.x = 0.0f;
    prm.mActorRelPos.y = 0.0f;
    prm.mActorRelPos.z = 0.0f;
    fopAcIt_Judge(daPy_npc_JudgeForPNameAndDistance, &prm);
    if (outActorRelPos) {
        *outActorRelPos = prm.mActorRelPos;
    }
    return prm.mpActor;
}
