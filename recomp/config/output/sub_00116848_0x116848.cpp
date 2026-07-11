#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00116848
// Address: 0x116848 - 0x1168d8
void sub_00116848_0x116848(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x116848u;

    // 0x116848: 0x27bdff50
    ctx->pc = 0x116848u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x11684c: 0x3c020011
    ctx->pc = 0x11684cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)17 << 16));
    // 0x116850: 0xffb00000
    ctx->pc = 0x116850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x116854: 0x24425f30
    ctx->pc = 0x116854u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 24368));
    // 0x116858: 0x3c100021
    ctx->pc = 0x116858u;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    // 0x11685c: 0xffb10010
    ctx->pc = 0x11685cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x116860: 0x8e119d44
    ctx->pc = 0x116860u;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 16), 4294942020)));
    // 0x116864: 0xffa50078
    ctx->pc = 0x116864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 5));
    // 0x116868: 0xae029d44
    ctx->pc = 0x116868u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294942020), GPR_U32(ctx, 2));
    // 0x11686c: 0x27a50078
    ctx->pc = 0x11686cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 120));
    // 0x116870: 0xffbf0020
    ctx->pc = 0x116870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x116874: 0xffa60080
    ctx->pc = 0x116874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 6));
    // 0x116878: 0xffa70088
    ctx->pc = 0x116878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 7));
    // 0x11687c: 0xffa80090
    ctx->pc = 0x11687cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 8));
    // 0x116880: 0xffa90098
    ctx->pc = 0x116880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 9));
    // 0x116884: 0xffaa00a0
    ctx->pc = 0x116884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 10));
    // 0x116888: 0xc045886
    ctx->pc = 0x116888u;
    SET_GPR_U32(ctx, 31, 0x116890u);
    ctx->pc = 0x11688Cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 11));
    ctx->pc = 0x116218u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116218_0x116218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116890u; }
    }
    if (ctx->pc != 0x116890u) { return; }
    ctx->pc = 0x116890u;
    // 0x116890: 0xae119d44
    ctx->pc = 0x116890u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294942020), GPR_U32(ctx, 17));
    // 0x116894: 0xdfbf0020
    ctx->pc = 0x116894u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x116898: 0xdfb10010
    ctx->pc = 0x116898u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11689c: 0xdfb00000
    ctx->pc = 0x11689cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1168a0: 0x3e00008
    ctx->pc = 0x1168A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168A4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1168A8u;
    // 0x1168a8: 0x8c820010
    ctx->pc = 0x1168a8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1168ac: 0x8ca6001c
    ctx->pc = 0x1168acu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x1168b0: 0x8c830014
    ctx->pc = 0x1168b0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1168b4: 0x21080
    ctx->pc = 0x1168b4u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
    // 0x1168b8: 0x461021
    ctx->pc = 0x1168b8u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1168bc: 0x3e00008
    ctx->pc = 0x1168BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168C0u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1168C4u;
    // 0x1168c4: 0x0
    ctx->pc = 0x1168c4u;
    // NOP
    // 0x1168c8: 0x8c820010
    ctx->pc = 0x1168c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1168cc: 0x3e00008
    ctx->pc = 0x1168CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168D0u;
        WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1168D4u;
    // 0x1168d4: 0x0
    ctx->pc = 0x1168d4u;
    // NOP
}
