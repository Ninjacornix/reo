#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00128348
// Address: 0x128348 - 0x128410
void sub_00128348_0x128348(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x128348u;

    // 0x128348: 0x27bdfff0
    ctx->pc = 0x128348u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12834c: 0x3c020021
    ctx->pc = 0x12834cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x128350: 0xffb00000
    ctx->pc = 0x128350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x128354: 0x2450c8bc
    ctx->pc = 0x128354u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294953148));
    // 0x128358: 0xffbf0008
    ctx->pc = 0x128358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12835c: 0x3c030021
    ctx->pc = 0x12835cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x128360: 0x8e040000
    ctx->pc = 0x128360u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x128364: 0x2463c8b8
    ctx->pc = 0x128364u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294953144));
    // 0x128368: 0x8c620000
    ctx->pc = 0x128368u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12836c: 0x14800022
    ctx->pc = 0x12836Cu;
    {
        const bool branch_taken_0x12836c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x128370u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x12836c) {
            ctx->pc = 0x1283F8u;
            goto label_1283f8;
        }
    }
    ctx->pc = 0x128374u;
    // 0x128374: 0x3c040021
    ctx->pc = 0x128374u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x128378: 0x282d
    ctx->pc = 0x128378u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12837c: 0x2484c8c0
    ctx->pc = 0x12837cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294953152));
    // 0x128380: 0xc041f1a
    ctx->pc = 0x128380u;
    SET_GPR_U32(ctx, 31, 0x128388u);
    ctx->pc = 0x128384u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1088));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128388u; }
    }
    if (ctx->pc != 0x128388u) { return; }
    ctx->pc = 0x128388u;
    // 0x128388: 0x3c040021
    ctx->pc = 0x128388u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x12838c: 0x2484cd00
    ctx->pc = 0x12838cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294954240));
    // 0x128390: 0x282d
    ctx->pc = 0x128390u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128394: 0xc041f1a
    ctx->pc = 0x128394u;
    SET_GPR_U32(ctx, 31, 0x12839Cu);
    ctx->pc = 0x128398u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1024));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12839Cu; }
    }
    if (ctx->pc != 0x12839Cu) { return; }
    ctx->pc = 0x12839Cu;
    // 0x12839c: 0x3c040021
    ctx->pc = 0x12839cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x1283a0: 0x2484d108
    ctx->pc = 0x1283a0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294955272));
    // 0x1283a4: 0x240500ff
    ctx->pc = 0x1283a4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 255));
    // 0x1283a8: 0xc041f1a
    ctx->pc = 0x1283A8u;
    SET_GPR_U32(ctx, 31, 0x1283B0u);
    ctx->pc = 0x1283ACu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1283B0u; }
    }
    if (ctx->pc != 0x1283B0u) { return; }
    ctx->pc = 0x1283B0u;
    // 0x1283b0: 0x3c040021
    ctx->pc = 0x1283b0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x1283b4: 0x2484d208
    ctx->pc = 0x1283b4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294955528));
    // 0x1283b8: 0x282d
    ctx->pc = 0x1283b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1283bc: 0xc041f1a
    ctx->pc = 0x1283BCu;
    SET_GPR_U32(ctx, 31, 0x1283C4u);
    ctx->pc = 0x1283C0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 32));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1283C4u; }
    }
    if (ctx->pc != 0x1283C4u) { return; }
    ctx->pc = 0x1283C4u;
    // 0x1283c4: 0x3c040021
    ctx->pc = 0x1283c4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x1283c8: 0x3c050021
    ctx->pc = 0x1283c8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x1283cc: 0x3c060021
    ctx->pc = 0x1283ccu;
    SET_GPR_U32(ctx, 6, ((uint32_t)33 << 16));
    // 0x1283d0: 0x3c070021
    ctx->pc = 0x1283d0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)33 << 16));
    // 0x1283d4: 0x3c030021
    ctx->pc = 0x1283d4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x1283d8: 0x2402ffff
    ctx->pc = 0x1283d8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1283dc: 0xac80d228
    ctx->pc = 0x1283dcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294955560), GPR_U32(ctx, 0));
    // 0x1283e0: 0xac62d234
    ctx->pc = 0x1283e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294955572), GPR_U32(ctx, 2));
    // 0x1283e4: 0xaca0d100
    ctx->pc = 0x1283e4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294955264), GPR_U32(ctx, 0));
    // 0x1283e8: 0xacc0d22c
    ctx->pc = 0x1283e8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4294955564), GPR_U32(ctx, 0));
    // 0x1283ec: 0xace0d230
    ctx->pc = 0x1283ecu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294955568), GPR_U32(ctx, 0));
    // 0x1283f0: 0x8e040000
    ctx->pc = 0x1283f0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1283f4: 0x24820001
    ctx->pc = 0x1283f4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 1));
label_1283f8:
    // 0x1283f8: 0xdfbf0008
    ctx->pc = 0x1283f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1283fc: 0xae020000
    ctx->pc = 0x1283fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x128400: 0xdfb00000
    ctx->pc = 0x128400u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128404: 0x3e00008
    ctx->pc = 0x128404u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128408u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1283F8u: goto label_1283f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12840Cu;
    // 0x12840c: 0x0
    ctx->pc = 0x12840cu;
    // NOP
}
