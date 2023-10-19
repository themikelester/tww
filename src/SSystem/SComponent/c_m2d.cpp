//
// Generated by dtk
// Translation Unit: c_m2d.cpp
//

#include "SSystem/SComponent/c_m2d.h"
#include "SSystem/SComponent/c_m3d.h"
#include "SSystem/SComponent/c_m3d_g_cir.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 80249DAC-8024A0E0       .text cM2d_CrossCirLin__FR8cM2dGCirffffPfPf */
void cM2d_CrossCirLin(cM2dGCir& circle, f32 x0, f32 y0, f32 x1, f32 y1, f32* pDstX, f32* pDstY) {
    f32 fVar1 = x0 - circle.GetCx();
    f32 fVar15 = y0 - circle.GetCy();
    f32 dVar13 = x1 * x1 + y1 * y1;
    f32 dVar14 = 2.0f * ((x1 * fVar1) + (y1 * fVar15));
    f32 c = (fVar1 * fVar1 + fVar15 * fVar15) - (circle.GetR() * circle.GetR());
    f32 t;

    JUT_ASSERT_FLOAT(0x47, c < 0.0f);

    if (cM3d_IsZero(dVar13)) {
        if (!cM3d_IsZero(dVar14)) {
            t = -c / dVar14;
        }
    } else {
        f32 dVar10 = ((dVar14 * dVar14) - (4.0f * dVar13) * c);
        if (cM3d_IsZero(dVar10)) {
            t =(-dVar14 / (2.0f * dVar13));
        } else {
            if (dVar10 < 0.0f) {
            } else {
                f32 fVar2 = 1.0f / (2.0f * dVar13);
                f32 fVar15 = sqrtf(dVar10);
                fVar15 = fVar2 * (-dVar14 + fVar15);
                f32 fVar16 = sqrtf(dVar10);
                f32 fVar4 = fVar2 * (-dVar14 - fVar16);
                if (fVar15 > fVar4) {
                    t = fVar15;
                } else {
                    t = fVar4;
                }
            }
        }
    }

    if (cM3d_IsZero(t)) {
        *pDstX = x0;
        *pDstY = y0;
    } else {
        JUT_ASSERT_FLOAT(0x89, t >= 0.0f);
        *pDstX = x0 + (t * x1);
        *pDstY = y0 + (t * y1);
    }
}
