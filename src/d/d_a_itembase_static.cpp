//
// Generated by dtk
// Translation Unit: d_a_itembase_static.cpp
//

#include "d/actor/d_a_itembase.h"
#include "d/d_item_data.h"
#include "SSystem/SComponent/c_lib.h"
#include "dolphin/types.h"

const daItemBase_c_m_data daItemBase_c::m_data = {
    /* mFieldItemGravity      */ -7.0f,
    /* field_0x04             */ 0.62f,
    /* field_0x08             */ 50.0f,
    /* mScaleAnimSpeed        */ 20.0f,
    /* field_0x10             */ 5.0f,
    /* field_0x14             */ 1,
    /* mDuration              */ 8*30,
    /* field_0x18             */ 2*30,
    /* field_0x1A             */ 0x2000,
    /* mNumFramesPerFullSpin  */ 82,
    /* field_0x20             */ -4.0f,
    /* field_0x24             */ 3.5f,
    /* field_0x28             */ 1100,
    /* mHeartMaxRandomZRot    */ 0x0BB8,
    /* field_0x2C             */ 30.0f,
    /* field_0x30             */ 10.0f,
    /* field_0x34             */ 1.5f,
    /* mPickedUpInitialSpeedY */ 23.0f,
    /* mPickedUpGravity       */ -6.0f,
    /* field_0x40             */ 13,
    /* field_0x42             */ 16,
    /* field_0x44             */ 50.0f,
    /* mVelocityScale         */ 7.0f,
};

/* 80068650-80068658       .text getItemNo__12daItemBase_cFv */
u8 daItemBase_c::getItemNo() {
    return m_itemNo;
}

/* 80068658-80068674       .text getHeight__12daItemBase_cFv */
u8 daItemBase_c::getHeight() {
    return dItem_data::getH(m_itemNo);
}

/* 80068674-80068690       .text getR__12daItemBase_cFv */
u8 daItemBase_c::getR() {
    return dItem_data::getR(m_itemNo);
}

/* 80068690-800686A0       .text hide__12daItemBase_cFv */
void daItemBase_c::hide() {
    cLib_offBit(mDrawFlags, (u8)0x01);
}

/* 800686A0-800686B0       .text show__12daItemBase_cFv */
void daItemBase_c::show() {
    cLib_onBit(mDrawFlags, (u8)0x01);
}

/* 800686B0-800686F8       .text changeDraw__12daItemBase_cFv */
void daItemBase_c::changeDraw() {
    if (chkDraw())
        hide();
    else
        show();
}

/* 800686F8-80068710       .text chkDraw__12daItemBase_cFv */
bool daItemBase_c::chkDraw() {
    return cLib_checkBit(mDrawFlags, (u8)0x01);
}

/* 80068710-80068720       .text dead__12daItemBase_cFv */
void daItemBase_c::dead() {
    cLib_onBit(mDrawFlags, (u8)0x02);
}

/* 80068720-80068738       .text chkDead__12daItemBase_cFv */
bool daItemBase_c::chkDead() {
    return cLib_checkBit(mDrawFlags, (u8)0x02);
}

/* 80068738-80068748       .text setLoadError__12daItemBase_cFv */
void daItemBase_c::setLoadError() {
    cLib_onBit(mDrawFlags, (u8)0x04);
}

/* 80068748-800687B4       .text CheckItemCreateHeap__FP10fopAc_ac_c */
BOOL CheckItemCreateHeap(fopAc_ac_c* i_ac) {
    daItemBase_c * i_this = (daItemBase_c *)i_ac;
    u8 itemNo = i_this->getItemNo();
    return i_this->CreateItemHeap(
        dItem_data::getArcname(itemNo),
        dItem_data::getBmdIdx(itemNo),
        dItem_data::getSrtIdx(itemNo),
        dItem_data::getSrtIdx2(itemNo),
        dItem_data::getTevIdx(itemNo),
        dItem_data::getTevIdx2(itemNo),
        dItem_data::getBckIdx(itemNo),
        -1
    );
}

/* 800687B4-80068820       .text CheckFieldItemCreateHeap__FP10fopAc_ac_c */
BOOL CheckFieldItemCreateHeap(fopAc_ac_c* i_ac) {
    daItemBase_c * i_this = (daItemBase_c *)i_ac;
    u8 itemNo = i_this->getItemNo();
    return i_this->CreateItemHeap(
        dItem_data::getFieldArc(itemNo),
        dItem_data::getFieldBmdIdx(itemNo),
        dItem_data::getFieldSrtIdx(itemNo),
        dItem_data::getFieldSrtIdx2(itemNo),
        dItem_data::getFieldTevIdx(itemNo),
        dItem_data::getFieldTevIdx2(itemNo),
        dItem_data::getFieldBckIdx(itemNo),
        -1
    );
}

