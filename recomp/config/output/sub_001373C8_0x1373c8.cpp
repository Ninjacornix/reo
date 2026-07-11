#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001373C8
// Address: 0x1373c8 - 0x137468
void sub_001373C8_0x1373c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1373c8u;

    // 0x1373c8: 0x27bdffe0
    ctx->pc = 0x1373c8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1373cc: 0xffb10008
    ctx->pc = 0x1373ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1373d0: 0x3c110022
    ctx->pc = 0x1373d0u;
    SET_GPR_U32(ctx, 17, ((uint32_t)34 << 16));
    // 0x1373d4: 0xffb00000
    ctx->pc = 0x1373d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1373d8: 0xffbf0010
    ctx->pc = 0x1373d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1373dc: 0xc0505c0
    ctx->pc = 0x1373DCu;
    SET_GPR_U32(ctx, 31, 0x1373E4u);
    ctx->pc = 0x1373E0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141700u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1373E4u; }
    }
    if (ctx->pc != 0x1373E4u) { return; }
    ctx->pc = 0x1373E4u;
    // 0x1373e4: 0x3c040024
    ctx->pc = 0x1373e4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1373e8: 0x2622bb88
    ctx->pc = 0x1373e8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 17), 4294949768));
    // 0x1373ec: 0x2484c468
    ctx->pc = 0x1373ecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294952040));
    // 0x1373f0: 0x200282d
    ctx->pc = 0x1373f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1373f4: 0x12020006
    ctx->pc = 0x1373F4u;
    {
        const bool branch_taken_0x1373f4 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x1373F8u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1373f4) {
            ctx->pc = 0x137410u;
            goto label_137410;
        }
    }
    ctx->pc = 0x1373FCu;
    // 0x1373fc: 0xc045a12
    ctx->pc = 0x1373FCu;
    SET_GPR_U32(ctx, 31, 0x137404u);
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137404u; }
    }
    if (ctx->pc != 0x137404u) { return; }
    ctx->pc = 0x137404u;
    // 0x137404: 0x10000014
    ctx->pc = 0x137404u;
    {
        const bool branch_taken_0x137404 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x137408u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x137404) {
            ctx->pc = 0x137458u;
            goto label_137458;
        }
    }
    ctx->pc = 0x13740Cu;
    // 0x13740c: 0x0
    ctx->pc = 0x13740cu;
    // NOP
label_137410:
    // 0x137410: 0x82040002
    ctx->pc = 0x137410u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x137414: 0x10800007
    ctx->pc = 0x137414u;
    {
        const bool branch_taken_0x137414 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x137418u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x137414) {
            ctx->pc = 0x137434u;
            goto label_137434;
        }
    }
    ctx->pc = 0x13741Cu;
    // 0x13741c: 0x10820005
    ctx->pc = 0x13741Cu;
    {
        const bool branch_taken_0x13741c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x137420u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 9));
        if (branch_taken_0x13741c) {
            ctx->pc = 0x137434u;
            goto label_137434;
        }
    }
    ctx->pc = 0x137424u;
    // 0x137424: 0x10820003
    ctx->pc = 0x137424u;
    {
        const bool branch_taken_0x137424 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x137428u;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        if (branch_taken_0x137424) {
            ctx->pc = 0x137434u;
            goto label_137434;
        }
    }
    ctx->pc = 0x13742Cu;
    // 0x13742c: 0xc045a12
    ctx->pc = 0x13742Cu;
    SET_GPR_U32(ctx, 31, 0x137434u);
    ctx->pc = 0x137430u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294952104));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137434u; }
    }
    if (ctx->pc != 0x137434u) { return; }
    ctx->pc = 0x137434u;
label_137434:
    // 0x137434: 0xc04dcc4
    ctx->pc = 0x137434u;
    SET_GPR_U32(ctx, 31, 0x13743Cu);
    ctx->pc = 0x137310u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00137310_0x137310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13743Cu; }
    }
    if (ctx->pc != 0x13743Cu) { return; }
    ctx->pc = 0x13743Cu;
    // 0x13743c: 0x3c030022
    ctx->pc = 0x13743cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x137440: 0xa220bb88
    ctx->pc = 0x137440u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4294949768), (uint8_t)GPR_U32(ctx, 0));
    // 0x137444: 0x2463bbec
    ctx->pc = 0x137444u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949868));
    // 0x137448: 0x8c620000
    ctx->pc = 0x137448u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13744c: 0x24420001
    ctx->pc = 0x13744cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x137450: 0xac620000
    ctx->pc = 0x137450u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x137454: 0xdfb00000
    ctx->pc = 0x137454u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_137458:
    // 0x137458: 0xdfb10008
    ctx->pc = 0x137458u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13745c: 0xdfbf0010
    ctx->pc = 0x13745cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137460: 0x80505de
    ctx->pc = 0x137460u;
    ctx->pc = 0x137464u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x141778u;
    sub_00141778_0x141778(rdram, ctx, runtime); return;
    ctx->pc = 0x137468u;
}
