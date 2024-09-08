//
// Generated by dtk
// Translation Unit: JAISound.cpp
//

#include "JSystem/JAudio/JAISound.h"
#include "JSystem/JAudio/JAIBasic.h"
#include "JSystem/JAudio/JAIGlobalParameter.h"
#include "JSystem/JAudio/JAISeMgr.h"
#include "JSystem/JAudio/JAISequenceMgr.h"
#include "JSystem/JAudio/JAIStreamMgr.h"
#include "JSystem/JKernel/JKRSolidHeap.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 8029859C-802985C4       .text __ct__8JAISoundFv */
JAISound::JAISound() {
    field_0x3c = NULL;
    field_0x5 = 0;
    field_0x6 = 10;
    field_0x24 = NULL;
}

/* 802985C4-802985E8       .text getSeCategoryNumber__8JAISoundFv */
u8 JAISound::getSeCategoryNumber() {
    return JAInter::SeMgr::changeIDToCategory(this->mSoundID);
}

/* 802985E8-802985F4       .text getSwBit__8JAISoundFv */
int JAISound::getSwBit() {
    return ((u32*)field_0x40)[0];
}

/* 802985F4-80298624       .text checkSwBit__8JAISoundFUl */
int JAISound::checkSwBit(u32 param_1) {
    return param_1 & getSwBit();
}

/* 80298624-80298630       .text getInfoPriority__8JAISoundFv */
u8 JAISound::getInfoPriority() {
    return ((u8*)field_0x40)[4];
}

/* 80298630-80298648       .text clearMainSoundPPointer__8JAISoundFv */
void JAISound::clearMainSoundPPointer() {
    if (!field_0x38) {
        return;
    }
    field_0x38[0] = NULL;
}

/* 80298648-80298688       .text start__8JAISoundFUl */
void JAISound::start(u32 param_1) {
    setPrepareFlag(0);
    field_0x14 = param_1;
}

/* 80298688-802986B8       .text stop__8JAISoundFUl */
void JAISound::stop(u32 param_1) {
    JAIBasic::msBasic->stopSoundHandle(this, param_1);
}

/* 802986B8-8029878C       .text setVolume__8JAISoundFfUlUc */
void JAISound::setVolume(f32 param_1, u32 param_2, u8 param_3) {
    switch(mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        setSeqInterVolume(param_3, param_1, param_2);
        break;
    case JAISoundID_Type_Se:
        setSeInterVolume(param_3, param_1, param_2, 0);
        break;
    case JAISoundID_Type_Stream:
        setStreamInterVolume(param_3, param_1, param_2);
        break;
    default:
        JUT_ASSERT_MSG(177, 0, "JAISound::setVolume サウンドカテゴリービットが異常です。\n");
    }
}

static void dummy1() {
    OSReport("JAISound::setDirectVolume サウンドカテゴリービットが異常です。\n");
}

/* 8029878C-80298864       .text setPan__8JAISoundFfUlUc */
void JAISound::setPan(f32 param_1, u32 param_2, u8 param_3) {
    switch(mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        setSeqInterPan(param_3, param_1, param_2);
        break;
    case JAISoundID_Type_Se:
        setSeInterPan(param_3, param_1, param_2, 0);
        break;
    case JAISoundID_Type_Stream:
        setStreamInterPan(param_3, param_1, param_2);
        break;
    default:
        JUT_ASSERT_MSG(217, 0, "JAISound::setPan サウンドカテゴリービットが異常です。\n");
    }
}

static void dummy2() {
    OSReport("JAISound::setDirectPan サウンドカテゴリービットが異常です。\n");
}

/* 80298864-8029893C       .text setPitch__8JAISoundFfUlUc */
void JAISound::setPitch(f32 param_1, u32 param_2, u8 param_3) {
    switch(mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        setSeqInterPitch(param_3, param_1, param_2);
        break;
    case JAISoundID_Type_Se:
        setSeInterPitch(param_3, param_1, param_2, 0);
        break;
    case JAISoundID_Type_Stream:
        setStreamInterPitch(param_3, param_1, param_2);
        break;
    default:
        JUT_ASSERT_MSG(257, 0, "JAISound::setPitch サウンドカテゴリービットが異常です。\n");
    }
}

static void dummy3() {
    OSReport("JAISound::setDirectPitch サウンドカテゴリービットが異常です。\n");
}

/* 8029893C-80298A04       .text setFxmix__8JAISoundFfUlUc */
void JAISound::setFxmix(f32 param_1, u32 param_2, u8 param_3) {
    switch(mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        setSeqInterFxmix(param_3, param_1, param_2);
        break;
    case JAISoundID_Type_Se:
        setSeInterFxmix(param_3, param_1, param_2, 0);
        break;
    case JAISoundID_Type_Stream:
        break;
    default:
        JUT_ASSERT_MSG(297, 0, "JAISound::setFxmix サウンドカテゴリービットが異常です。\n");
    }
}

static void dummy4() {
    OSReport("JAISound::setDirectFxmix サウンドカテゴリービットが異常です。\n");
}

/* 80298A04-80298ACC       .text setDolby__8JAISoundFfUlUc */
void JAISound::setDolby(f32 param_1, u32 param_2, u8 param_3) {
    switch(mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        setSeqInterDolby(param_3, param_1, param_2);
        break;
    case JAISoundID_Type_Se:
        setSeInterDolby(param_3, param_1, param_2, 0);
        break;
    case JAISoundID_Type_Stream:
        break;
    default:
        JUT_ASSERT_MSG(337, 0, "JAISound::setDolby サウンドカテゴリービットが異常です。\n");
    }
}

static void dummy5() {
    OSReport("JAISound::setDirectDolby サウンドカテゴリービットが異常です。\n");
}

/* 80298ACC-80298B74       .text setTempoProportion__8JAISoundFfUl */
void JAISound::setTempoProportion(f32 param_1, u32 param_2) {
    switch(mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        setSeqTempoProportion(param_1, param_2);
        break;
    case JAISoundID_Type_Se:
        break;
    case JAISoundID_Type_Stream:
        break;
    default:
        JUT_ASSERT_MSG(377, 0, "JAISound::setTempoProportion サウンドカテゴリービットが異常です。\n");
    }
}

/* 80298B74-80298C28       .text setPortData__8JAISoundFUcUs */
void JAISound::setPortData(u8 param_1, u16 param_2) {
    switch(mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        setSeqPortData(param_1, param_2, 0);
        break;
    case JAISoundID_Type_Se:
        setSePortData(param_1, param_2);
        break;
    case JAISoundID_Type_Stream:
        break;
    default:
        JUT_ASSERT_MSG(397, 0, "JAISound::setPortData サウンドカテゴリービットが異常です。\n");
    }
}

/* 80298C28-80298CD8       .text setPrepareFlag__8JAISoundFUc */
void JAISound::setPrepareFlag(u8 param_1) {
    switch(mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        setSeqPrepareFlag(param_1);
        break;
    case JAISoundID_Type_Se:
        break;
    case JAISoundID_Type_Stream:
        setStreamPrepareFlag(param_1);
        break;
    default:
        JUT_ASSERT_MSG(416, 0, "JAISound::setPrepareFlag サウンドカテゴリービットが異常です。\n");
    }
}

/* 80298CD8-80298E30       .text setDistanceVolumeCommon__8JAISoundFfUc */
f32 JAISound::setDistanceVolumeCommon(f32 param_1, u8 param_2) {
    f32 var1;
    if (field_0x8 != 4) {
        var1 = mPositionInfo[field_0x8].field_0x18;
    } else {
        var1 = mPositionInfo[0].field_0x18;
        for (u8 i = 1; i < JAIGlobalParameter::audioCameraMax; i++) {
            if (mPositionInfo[i].field_0x18 < var1) {
                var1 = mPositionInfo[i].field_0x18;
            }
        }
    }
    if (var1 < JAIGlobalParameter::maxVolumeDistance) {
        return 1.0f;
    }
    var1 -= JAIGlobalParameter::maxVolumeDistance;
    f32 var2 = param_1 - JAIGlobalParameter::maxVolumeDistance;
    if (param_2 > 3) {
        var2 /= 1 << (param_2 & 3) + 1;
    } else if (param_2 != 0) {
        var2 *= 1 << (param_2 & 3);
    }
    if (var1 < var2) {
        if (param_2 > 3) {
            return 1.0f - var1 / var2;
        } else {
            return JAIGlobalParameter::minDistanceVolume + (1.0f - JAIGlobalParameter::minDistanceVolume) * (1.0f - var1 / var2);
        }
    } else {
        if (param_2 > 3) {
            return 0.0f;
        } else {
            return JAIGlobalParameter::minDistanceVolume;
        }
    }
}

/* 80298E30-80298F8C       .text setDistancePanCommon__8JAISoundFv */
f32 JAISound::setDistancePanCommon() {
    /* Nonmatching */
}

/* 80298F8C-80299178       .text setPositionDopplarCommon__8JAISoundFUl */
f32 JAISound::setPositionDopplarCommon(u32) {
    /* Nonmatching */
}

/* 80299178-8029925C       .text setSeqInterVolume__8JAISoundFUcfUl */
void JAISound::setSeqInterVolume(u8 line_, f32 param_2, u32 param_3) {
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    int r31 = getSeqParameter()->mVolumes[line_].set(param_2, param_3);
    if (r31 == 1) {
        getSeqParameter()->field_0x126c |= 1 << line_;
    }
    if (getSeqParameter()->field_0x135c && r31 != 2) {
        getSeqParameter()->field_0x135c->field_0x8 |= 0x40000;
    }
}

static void dummy6() {
    OSReport("JAISound::checkReady サウンドカテゴリービットが異常です。\n");
}

/* 8029925C-802993AC       .text setSeqInterPan__8JAISoundFUcfUl */
void JAISound::setSeqInterPan(u8 line_, f32 param_2, u32 param_3) {
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    JUT_ASSERT_MSG(660, line_<JAIGlobalParameter::seqParameterLines, "JAISound::setSeqInterPan 設定できるライン数を超えています。\n");
    int r31 = getSeqParameter()->seqPan[line_].set(param_2, param_3);
    if (r31 == 1) {
        getSeqParameter()->field_0x1270 |= 1 << line_;
    }
    if (getSeqParameter()->field_0x135c && r31 != 2) {
        getSeqParameter()->field_0x135c->field_0x8 |= 0x80000;
    }
}

/* 802993AC-802994FC       .text setSeqInterPitch__8JAISoundFUcfUl */
void JAISound::setSeqInterPitch(u8 line_, f32 param_2, u32 param_3) {
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    JUT_ASSERT_MSG(678, line_<JAIGlobalParameter::seqParameterLines, "JAISound::setSeqInterPan 設定できるライン数を超えています。\n");
    int r31 = getSeqParameter()->seqPitch[line_].set(param_2, param_3);
    if (r31 == 1) {
        getSeqParameter()->field_0x1274 |= 1 << line_;
    }
    if (getSeqParameter()->field_0x135c && r31 != 2) {
        getSeqParameter()->field_0x135c->field_0x8 |= 0x100000;
    }
}

/* 802994FC-8029964C       .text setSeqInterFxmix__8JAISoundFUcfUl */
void JAISound::setSeqInterFxmix(u8 line_, f32 param_2, u32 param_3) {
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    JUT_ASSERT_MSG(696, line_<JAIGlobalParameter::seqParameterLines, "JAISound::setSeqInterPan 設定できるライン数を超えています。\n");
    int r31 = getSeqParameter()->seqFxmix[line_].set(param_2, param_3);
    if (r31 == 1) {
        getSeqParameter()->field_0x1278 |= 1 << line_;
    }
    if (getSeqParameter()->field_0x135c && r31 != 2) {
        getSeqParameter()->field_0x135c->field_0x8 |= 0x200000;
    }
}

/* 8029964C-802997E4       .text setSeqInterDolby__8JAISoundFUcfUl */
void JAISound::setSeqInterDolby(u8 line_, f32 param_2, u32 param_3) {
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    JUT_ASSERT_MSG(714, line_<JAIGlobalParameter::seqParameterLines, "JAISound::setSeqInterPan 設定できるライン数を超えています。\n");
    if (JAIBasic::getInterface()->field_0xd != 2) {
        if (getSeqParameter()->seqDolby[line_].mCurrentValue != 0.0f) {
            param_2 = 0.0f;
        } else {
            return;
        }
    }
    int r31 = getSeqParameter()->seqDolby[line_].set(param_2, param_3);
    if (r31 == 1) {
        getSeqParameter()->field_0x127c |= 1 << line_;
    }
    if (getSeqParameter()->field_0x135c && r31 != 2) {
        getSeqParameter()->field_0x135c->field_0x8 |= 0x400000;
    }
}

/* 802997E4-80299884       .text setSeqTempoProportion__8JAISoundFfUl */
void JAISound::setSeqTempoProportion(f32 param_1, u32 param_2) {
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    getSeqParameter()->mTempo.set(param_1, param_2);
    if (getSeqParameter()->field_0x135c) {
        getSeqParameter()->field_0x135c->field_0x8 |= 4;
    }
}

/* 80299884-802999F4       .text setSeqPortData__8JAISoundFUcUsUl */
void JAISound::setSeqPortData(u8 line_, u16 param_2, u32 param_3) {
    /* Nonmatching */
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    if (getSeqParameter()->field_0x10[line_].mCurrentValue == 0.0f && field_0x5 >= 3) {
        u16 local_38;
        JASystem::TTrack* track = getSeqParameter()->getRootTrackPointer();
        track->readPortApp(line_ << 16, &local_38);
        getSeqParameter()->field_0x10[line_].mCurrentValue = local_38;
    }
    int r29 = getSeqParameter()->field_0x10[line_].set(param_2, param_3);
    if (r29 == 1) {
        getSeqParameter()->field_0x1268 |= 1 << line_;
    }
    if (getSeqParameter()->field_0x135c && r29 != 2) {
        getSeqParameter()->field_0x135c->field_0x8 |= 0x10;
    }
}

/* 802999F4-80299B14       .text setTrackVolume__8JAISoundFUcfUl */
void JAISound::setTrackVolume(u8 line_, f32 param_2, u32 param_3) {
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    if (field_0x5 >= 4 && (getSeqParameter()->field_0x135c->field_0x4 & 1 << line_) == 0) {
        return;
    }
    if (param_3 == 0) {
        param_3++;
    }
    int r30 = getSeqParameter()->mTrackVolumes[line_].set(param_2, param_3);
    if (r30 == 1) {
        getSeqParameter()->field_0x1280 |= 1 << line_;
    }
    if (getSeqParameter()->field_0x135c && r30 != 2) {
        getSeqParameter()->field_0x135c->field_0x8 |= 0x40;
    }
}

/* 80299B14-80299BAC       .text setTrackInterruptSwitch__8JAISoundFUcUc */
void JAISound::setTrackInterruptSwitch(u8 param_1, u8 param_2) {
    if ((mSoundID & JAISoundID_TypeMask) != JAISoundID_Type_Sequence) {
        return;
    }
    if (!getSeqParameter()) {
        return;
    }
    getSeqParameter()->field_0x131c[param_1] = param_2;
    if (getSeqParameter()->field_0x135c) {
        getSeqParameter()->field_0x135c->field_0x8 |= 0x800000;
    }
}

/* 80299BAC-80299CD4       .text setTrackPortData__8JAISoundFUcUcUs */
void JAISound::setTrackPortData(u8, u8, u16) {
    /* Nonmatching */
}

/* 80299CD4-80299DE8       .text setSeInterRandomPara__8JAISoundFPfUlff */
void JAISound::setSeInterRandomPara(f32*, u32, f32, f32) {
    /* Nonmatching */
}

/* 80299DE8-80299E88       .text setSeInterVolume__8JAISoundFUcfUlUc */
void JAISound::setSeInterVolume(u8, f32, u32, u8) {
    /* Nonmatching */
}

/* 80299E88-80299F28       .text setSeInterPan__8JAISoundFUcfUlUc */
void JAISound::setSeInterPan(u8, f32, u32, u8) {
    /* Nonmatching */
}

/* 80299F28-80299FE0       .text setSeInterPitch__8JAISoundFUcfUlf */
void JAISound::setSeInterPitch(u8, f32, u32, f32) {
    /* Nonmatching */
}

/* 80299FE0-8029A080       .text setSeInterFxmix__8JAISoundFUcfUlUc */
void JAISound::setSeInterFxmix(u8, f32, u32, u8) {
    /* Nonmatching */
}

/* 8029A080-8029A120       .text setSeInterDolby__8JAISoundFUcfUlUc */
void JAISound::setSeInterDolby(u8, f32, u32, u8) {
    /* Nonmatching */
}

/* 8029A120-8029A1C4       .text setSePortData__8JAISoundFUcUs */
void JAISound::setSePortData(u8, u16) {
    /* Nonmatching */
}

/* 8029A1C4-8029A2E4       .text setSeDistanceParameters__8JAISoundFv */
void JAISound::setSeDistanceParameters() {
    /* Nonmatching */
}

/* 8029A2E4-8029A364       .text setSeDistanceVolume__8JAISoundFUc */
void JAISound::setSeDistanceVolume(u8) {
    /* Nonmatching */
}

/* 8029A364-8029A3BC       .text setSeDistancePan__8JAISoundFUc */
void JAISound::setSeDistancePan(u8) {
    /* Nonmatching */
}

/* 8029A3BC-8029A544       .text setSeDistancePitch__8JAISoundFUc */
void JAISound::setSeDistancePitch(u8) {
    /* Nonmatching */
}

/* 8029A544-8029A5CC       .text setSePositionDopplar__8JAISoundFv */
void JAISound::setSePositionDopplar() {
    /* Nonmatching */
}

/* 8029A5CC-8029A6B0       .text setSeDistanceFxmix__8JAISoundFUc */
void JAISound::setSeDistanceFxmix(u8) {
    /* Nonmatching */
}

/* 8029A6B0-8029A6B4       .text setSeDistanceFir__8JAISoundFUc */
void JAISound::setSeDistanceFir(u8) {}

/* 8029A6B4-8029A788       .text setSeDistanceDolby__8JAISoundFUc */
void JAISound::setSeDistanceDolby(u8) {
    /* Nonmatching */
}

/* 8029A788-8029A86C       .text setStreamInterVolume__8JAISoundFUcfUl */
void JAISound::setStreamInterVolume(u8, f32, u32) {
    /* Nonmatching */
}

/* 8029A86C-8029A950       .text setStreamInterPitch__8JAISoundFUcfUl */
void JAISound::setStreamInterPitch(u8, f32, u32) {
    /* Nonmatching */
}

/* 8029A950-8029AA34       .text setStreamInterPan__8JAISoundFUcfUl */
void JAISound::setStreamInterPan(u8, f32, u32) {
    /* Nonmatching */
}

/* 8029AA34-8029AA84       .text setStreamPrepareFlag__8JAISoundFUc */
void JAISound::setStreamPrepareFlag(u8) {
    /* Nonmatching */
}

/* 8029AA84-8029ACF0       .text setPauseMode__8JAISoundFUcUc */
void JAISound::setPauseMode(u8 param_1, u8 param_2) {
    /* Nonmatching */
    switch (mSoundID & JAISoundID_TypeMask) {
    case JAISoundID_Type_Sequence:
        if (!getSeqParameter()) {
            return;
        }
        if (param_1 == 3) {
            param_1 = 4;
        }
        if (param_1 != 0) {
            switch (param_1) {
            case 1:
                setSeqInterVolume(11, param_2 / 127.0f, 1);
                break;
            case 2:
                JASystem::TTrack* track = getSeqParameter()->getRootTrackPointer();
                track->pauseTrackAll();
                break;
            }
        } else {
            getSeqParameter();
            switch (getSeqParameter()->field_0x1261) {
            case 1:
                setSeqInterVolume(11, 1.0f, 1);
                break;
            case 2:
                JASystem::TTrack* track = getSeqParameter()->getRootTrackPointer();
                track->unPauseTrackAll();
                break;
            }
        }
        getSeqParameter()->field_0x1261 = param_1;
        break;
    case JAISoundID_Type_Stream:
        if (!getStreamParameter()) {
            return;
        }
        if (param_1 != 0) {
            switch (param_1) {
            case 1:
                setStreamInterVolume(11, param_2 / 127.0f, 1);
                break;
            case 2:
                JAInter::StreamLib::setPauseFlag(2);
                break;
            }
        } else {
            switch (getStreamParameter()->field_0x0) {
            case 1:
                setStreamInterVolume(11, 1.0f, 1);
                break;
            case 2:
                JAInter::StreamLib::clearPauseFlag(2);
                break;
            }
        }
        getStreamParameter()->field_0x0 = param_1;
        break;
    default:
        JUT_ASSERT_MSG(1443, 0, "JAISound::setPauseMode サウンドカテゴリービットが異常です。\n");
        break;
    }
}

/* 8029ACF0-8029AD54       .text setSeqPrepareFlag__8JAISoundFUc */
void JAISound::setSeqPrepareFlag(u8) {
    /* Nonmatching */
}

/* 8029AD54-8029ADA8       .text getSeqInterVolume__8JAISoundFUc */
f32 JAISound::getSeqInterVolume(u8) {
    /* Nonmatching */
}

/* 8029ADA8-8029AE34       .text getStreamInterVolume__8JAISoundFUc */
f32 JAISound::getStreamInterVolume(u8) {
    /* Nonmatching */
}

/* 8029AE34-8029AE3C       .text getSeqParameter__8JAISoundFv */
JAInter::SeqParameter* JAISound::getSeqParameter() {
    return (JAInter::SeqParameter*)field_0x3c;
}

/* 8029AE3C-8029AE44       .text getSeParameter__8JAISoundFv */
JAInter::SeParameter* JAISound::getSeParameter() {
    return (JAInter::SeParameter*)field_0x3c;
}

/* 8029AE44-8029AE4C       .text getStreamParameter__8JAISoundFv */
JAInter::StreamParameter* JAISound::getStreamParameter() {
    return (JAInter::StreamParameter*)field_0x3c;
}

/* 8029AE4C-8029AE88       .text getTrackPortRoute__8JAISoundFUcUc */
int JAISound::getTrackPortRoute(u8, u8) {
    /* Nonmatching */
}

/* 8029AE88-8029AEF8       .text checkSoundHandle__8JAISoundFUlPv */
u32 JAISound::checkSoundHandle(u32, void*) {
    /* Nonmatching */
}

/* 8029AEF8-8029AFCC       .text initParameter__8JAISoundFPP8JAISoundPQ27JAInter5ActorUlUlUcPv */
void JAISound::initParameter(JAISound**, JAInter::Actor*, u32, u32, u8, void*) {
    /* Nonmatching */
}

/* 8029AFCC-8029B07C       .text set__Q27JAInter11MoveParaSetFfUl */
int JAInter::MoveParaSet::set(f32, u32) {
    /* Nonmatching */
}

/* 8029B07C-8029B0C4       .text move__Q27JAInter11MoveParaSetFv */
bool JAInter::MoveParaSet::move() {
    /* Nonmatching */
}

static void dummy7() {
    OSReport("JAISound::getVolume サウンドカテゴリービットが異常です。\n");
    OSReport("JAISound::getPitch サウンドカテゴリービットが異常です。\n");
    OSReport("JAISound::getFxmix サウンドカテゴリービットが異常です。\n");
    OSReport("JAISound::getDolby サウンドカテゴリービットが異常です。\n");
    OSReport("JAISound::getTempoProportion サウンドカテゴリービットが異常です。\n");
    OSReport("JAISound::getPortData サウンドカテゴリービットが異常です。\n");
    OSReport("JAISound::getTrackParameterU7 未定義のサウンドパラメータです。\n");
    OSReport("JAISound::getTrackParameterF32 未定義のサウンドパラメータです。\n");
    OSReport("JAISound::getSeParametermeterF32 未定義のサウンドパラメータです。\n");
}

/* 8029B0C4-8029B4AC       .text init__Q27JAInter9LinkSoundFP8JAISoundUl */
void JAInter::LinkSound::init(JAISound* param_1, u32 param_2) {
    JAIGlobalParameter::getParamAudioCameraMax();
    Buffer = param_1;
    field_0x0 = Buffer;
    field_0x4 = NULL;
    Buffer[0x00].field_0x30 = NULL;
    Buffer[0x00].field_0x34 = Buffer + 1;
    Buffer[0x00].field_0x5 = 0;
    Buffer[0x00].mPositionInfo = new (JAIBasic::getCurrentJAIHeap(), 0x20) JAISound::PositionInfo_t[JAIGlobalParameter::getParamAudioCameraMax()];
    JUT_ASSERT_MSG(2084, Buffer[0x00].mPositionInfo, "LinkSound::initLinkSound Cannot Alloc Heap!!\n");
    int i;
    for (i = 1; i < param_2 - 1; i++) {
        Buffer[i].field_0x30 = Buffer + (i - 1);
        Buffer[i].field_0x34 = Buffer + (i + 1);
        Buffer[i].field_0x5 = 0;
        Buffer[i].mPositionInfo = new (JAIBasic::getCurrentJAIHeap(), 0x20) JAISound::PositionInfo_t[JAIGlobalParameter::getParamAudioCameraMax()];
        JUT_ASSERT_MSG(2092, Buffer[i].mPositionInfo, "LinkSound::initLinkSound Cannot Alloc Heap!!\n");
    }
    Buffer[i].field_0x30 = Buffer + (i - 1);
    Buffer[i].field_0x34 = NULL;
    Buffer[i].field_0x5 = 0;
    Buffer[i].mPositionInfo = new (JAIBasic::getCurrentJAIHeap(), 0x20) JAISound::PositionInfo_t[JAIGlobalParameter::getParamAudioCameraMax()];
    JUT_ASSERT_MSG(2099, Buffer[i].mPositionInfo, "LinkSound::initLinkSound Cannot Alloc Heap!!\n");
}

/* 8029B4AC-8029B500       .text getSound__Q27JAInter9LinkSoundFv */
JAISound* JAInter::LinkSound::getSound() {
    /* Nonmatching */
}

/* 8029B500-8029B570       .text releaseSound__Q27JAInter9LinkSoundFP8JAISound */
void JAInter::LinkSound::releaseSound(JAISound*) {
    /* Nonmatching */
}
