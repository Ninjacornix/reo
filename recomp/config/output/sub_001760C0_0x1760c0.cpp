#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001760C0
// Address: 0x1760c0 - 0x176110
void sub_001760C0_0x1760c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1760c0u;

    // 0x1760c0: 0x27bdfff0
    ctx->pc = 0x1760c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1760c4: 0x2402ffff
    ctx->pc = 0x1760c4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1760c8: 0xffb00000
    ctx->pc = 0x1760c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1760cc: 0x80802d
    ctx->pc = 0x1760ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1760d0: 0xffbf0008
    ctx->pc = 0x1760d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1760d4: 0x8e030118
    ctx->pc = 0x1760d4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 280)));
    // 0x1760d8: 0x4600008
    ctx->pc = 0x1760D8u;
    {
        const bool branch_taken_0x1760d8 = (GPR_S32(ctx, 3) < 0);
        ctx->pc = 0x1760DCu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1760d8) {
            ctx->pc = 0x1760FCu;
            goto label_1760fc;
        }
    }
    ctx->pc = 0x1760E0u;
    // 0x1760e0: 0xc056ea0
    ctx->pc = 0x1760E0u;
    SET_GPR_U32(ctx, 31, 0x1760E8u);
    ctx->pc = 0x1760E4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 22500));
    ctx->pc = 0x15BA80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1760E8u; }
    }
    if (ctx->pc != 0x1760E8u) { return; }
    ctx->pc = 0x1760E8u;
    // 0x1760e8: 0x3c050023
    ctx->pc = 0x1760e8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)35 << 16));
    // 0x1760ec: 0x8e040118
    ctx->pc = 0x1760ecu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 280)));
    // 0x1760f0: 0x3c030023
    ctx->pc = 0x1760f0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x1760f4: 0xac62f1cc
    ctx->pc = 0x1760f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963660), GPR_U32(ctx, 2));
    // 0x1760f8: 0xaca4f1c8
    ctx->pc = 0x1760f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294963656), GPR_U32(ctx, 4));
label_1760fc:
    // 0x1760fc: 0xdfb00000
    ctx->pc = 0x1760fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176100: 0xdfbf0008
    ctx->pc = 0x176100u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176104: 0x3e00008
    ctx->pc = 0x176104u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176108u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1760FCu: goto label_1760fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17610Cu;
    // 0x17610c: 0x0
    ctx->pc = 0x17610cu;
    // NOP
}
