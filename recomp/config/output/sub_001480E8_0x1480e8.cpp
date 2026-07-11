#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001480E8
// Address: 0x1480e8 - 0x148170
void sub_001480E8_0x1480e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1480e8u;

    // 0x1480e8: 0x27bdfff0
    ctx->pc = 0x1480e8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1480ec: 0x80402d
    ctx->pc = 0x1480ecu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1480f0: 0xffbf0000
    ctx->pc = 0x1480f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1480f4: 0x50e00001
    ctx->pc = 0x1480F4u;
    {
        const bool branch_taken_0x1480f4 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 0));
        if (branch_taken_0x1480f4) {
            ctx->pc = 0x1480F8u;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x1480FCu;
            goto label_1480fc;
        }
    }
    ctx->pc = 0x1480FCu;
label_1480fc:
    // 0x1480fc: 0x8ca20008
    ctx->pc = 0x1480fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x148100: 0x8ca40004
    ctx->pc = 0x148100u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x148104: 0x471021
    ctx->pc = 0x148104u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x148108: 0x8ca30000
    ctx->pc = 0x148108u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x14810c: 0x2442ffff
    ctx->pc = 0x14810cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x148110: 0x47001b
    ctx->pc = 0x148110u;
    { uint32_t divisor = GPR_U32(ctx, 7); if (divisor != 0) { ctx->lo = GPR_U32(ctx, 2) / divisor; ctx->hi = GPR_U32(ctx, 7) % divisor; } else { ctx->lo = 0xFFFFFFFF; ctx->hi = GPR_U32(ctx,2); } }
    // 0x148114: 0x641821
    ctx->pc = 0x148114u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x148118: 0x1012
    ctx->pc = 0x148118u;
    SET_GPR_U32(ctx, 2, ctx->lo);
    // 0x14811c: 0x471018
    ctx->pc = 0x14811cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x148120: 0x462021
    ctx->pc = 0x148120u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x148124: 0x64182b
    ctx->pc = 0x148124u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x148128: 0x54600003
    ctx->pc = 0x148128u;
    {
        const bool branch_taken_0x148128 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x148128) {
            ctx->pc = 0x14812Cu;
            SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
            ctx->pc = 0x148138u;
            goto label_148138;
        }
    }
    ctx->pc = 0x148130u;
    // 0x148130: 0x10000005
    ctx->pc = 0x148130u;
    {
        const bool branch_taken_0x148130 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x148134u;
        WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 4));
        if (branch_taken_0x148130) {
            ctx->pc = 0x148148u;
            goto label_148148;
        }
    }
    ctx->pc = 0x148138u;
label_148138:
    // 0x148138: 0x100202d
    ctx->pc = 0x148138u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14813c: 0xc05221c
    ctx->pc = 0x14813Cu;
    SET_GPR_U32(ctx, 31, 0x148144u);
    ctx->pc = 0x148140u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294959160));
    ctx->pc = 0x148870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148144u; }
    }
    if (ctx->pc != 0x148144u) { return; }
    ctx->pc = 0x148144u;
    // 0x148144: 0x102d
    ctx->pc = 0x148144u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_148148:
    // 0x148148: 0xdfbf0000
    ctx->pc = 0x148148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14814c: 0x3e00008
    ctx->pc = 0x14814Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148150u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1480FCu: goto label_1480fc;
            case 0x148138u: goto label_148138;
            case 0x148148u: goto label_148148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148154u;
    // 0x148154: 0x0
    ctx->pc = 0x148154u;
    // NOP
    // 0x148158: 0x8c820000
    ctx->pc = 0x148158u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14815c: 0x8c830004
    ctx->pc = 0x14815cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x148160: 0x8c850008
    ctx->pc = 0x148160u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x148164: 0x431021
    ctx->pc = 0x148164u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x148168: 0x3e00008
    ctx->pc = 0x148168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14816Cu;
        SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1480FCu: goto label_1480fc;
            case 0x148138u: goto label_148138;
            case 0x148148u: goto label_148148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148170u;
}
