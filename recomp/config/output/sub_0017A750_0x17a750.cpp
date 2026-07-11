#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017A750
// Address: 0x17a750 - 0x17a7d0
void sub_0017A750_0x17a750(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17a750u;

    // 0x17a750: 0x10800007
    ctx->pc = 0x17A750u;
    {
        const bool branch_taken_0x17a750 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        if (branch_taken_0x17a750) {
            ctx->pc = 0x17A770u;
            goto label_17a770;
        }
    }
    ctx->pc = 0x17A758u;
    // 0x17a758: 0xac800000
    ctx->pc = 0x17a758u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x17a75c: 0x3c030023
    ctx->pc = 0x17a75cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17a760: 0x2463f1f0
    ctx->pc = 0x17a760u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294963696));
    // 0x17a764: 0x8c620000
    ctx->pc = 0x17a764u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17a768: 0x2442ffff
    ctx->pc = 0x17a768u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x17a76c: 0xac620000
    ctx->pc = 0x17a76cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_17a770:
    // 0x17a770: 0x3e00008
    ctx->pc = 0x17A770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A770u: goto label_17a770;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A778u;
    // 0x17a778: 0x27bdfff0
    ctx->pc = 0x17a778u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a77c: 0xc0382d
    ctx->pc = 0x17a77cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a780: 0xffb00000
    ctx->pc = 0x17a780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a784: 0x80802d
    ctx->pc = 0x17a784u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a788: 0xffbf0008
    ctx->pc = 0x17a788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17a78c: 0x26020008
    ctx->pc = 0x17a78cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 8));
    // 0x17a790: 0x8c460008
    ctx->pc = 0x17a790u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x17a794: 0x8c440000
    ctx->pc = 0x17a794u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17a798: 0xc053e42
    ctx->pc = 0x17A798u;
    SET_GPR_U32(ctx, 31, 0x17A7A0u);
    ctx->pc = 0x17A79Cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    ctx->pc = 0x14F908u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F908_0x14f908(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A7A0u; }
    }
    if (ctx->pc != 0x17A7A0u) { return; }
    ctx->pc = 0x17A7A0u;
    // 0x17a7a0: 0xae000004
    ctx->pc = 0x17a7a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x17a7a4: 0xdfbf0008
    ctx->pc = 0x17a7a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a7a8: 0xdfb00000
    ctx->pc = 0x17a7a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a7ac: 0x3e00008
    ctx->pc = 0x17A7ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A7B0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A770u: goto label_17a770;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A7B4u;
    // 0x17a7b4: 0x0
    ctx->pc = 0x17a7b4u;
    // NOP
    // 0x17a7b8: 0x27bdfff0
    ctx->pc = 0x17a7b8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a7bc: 0xc0202d
    ctx->pc = 0x17a7bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a7c0: 0xffbf0000
    ctx->pc = 0x17a7c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17a7c4: 0xdfbf0000
    ctx->pc = 0x17a7c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a7c8: 0x8053ef6
    ctx->pc = 0x17A7C8u;
    ctx->pc = 0x17A7CCu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x14FBD8u;
    entry_14fbd8_0x14fe88(rdram, ctx, runtime); return;
    ctx->pc = 0x17A7D0u;
}
