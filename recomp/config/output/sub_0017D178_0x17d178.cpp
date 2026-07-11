#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017D178
// Address: 0x17d178 - 0x17d1c8
void sub_0017D178_0x17d178(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17d178u;

    // 0x17d178: 0x27bdfff0
    ctx->pc = 0x17d178u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d17c: 0x80102d
    ctx->pc = 0x17d17cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d180: 0xffb00000
    ctx->pc = 0x17d180u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d184: 0x1040000c
    ctx->pc = 0x17D184u;
    {
        const bool branch_taken_0x17d184 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x17D188u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        if (branch_taken_0x17d184) {
            ctx->pc = 0x17D1B8u;
            goto label_17d1b8;
        }
    }
    ctx->pc = 0x17D18Cu;
    // 0x17d18c: 0x8c440024
    ctx->pc = 0x17d18cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x17d190: 0x8c500030
    ctx->pc = 0x17d190u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x17d194: 0xc05f600
    ctx->pc = 0x17D194u;
    SET_GPR_U32(ctx, 31, 0x17D19Cu);
    ctx->pc = 0x17D198u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x17D800u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D800_0x17d800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D19Cu; }
    }
    if (ctx->pc != 0x17D19Cu) { return; }
    ctx->pc = 0x17D19Cu;
    // 0x17d19c: 0xc05e9d4
    ctx->pc = 0x17D19Cu;
    SET_GPR_U32(ctx, 31, 0x17D1A4u);
    ctx->pc = 0x17D1A0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x17A750u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A750_0x17a750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D1A4u; }
    }
    if (ctx->pc != 0x17D1A4u) { return; }
    ctx->pc = 0x17D1A4u;
    // 0x17d1a4: 0x3c030023
    ctx->pc = 0x17d1a4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17d1a8: 0x2463f2a0
    ctx->pc = 0x17d1a8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294963872));
    // 0x17d1ac: 0x8c620000
    ctx->pc = 0x17d1acu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17d1b0: 0x2442ffff
    ctx->pc = 0x17d1b0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x17d1b4: 0xac620000
    ctx->pc = 0x17d1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_17d1b8:
    // 0x17d1b8: 0xdfb00000
    ctx->pc = 0x17d1b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d1bc: 0xdfbf0008
    ctx->pc = 0x17d1bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d1c0: 0x3e00008
    ctx->pc = 0x17D1C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D1C4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D1B8u: goto label_17d1b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D1C8u;
}
