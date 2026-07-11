#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00171478
// Address: 0x171478 - 0x1714d0
void sub_00171478_0x171478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x171478u;

    // 0x171478: 0x27bdfff0
    ctx->pc = 0x171478u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17147c: 0xffb00000
    ctx->pc = 0x17147cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171480: 0x80802d
    ctx->pc = 0x171480u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171484: 0xffbf0008
    ctx->pc = 0x171484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x171488: 0xc05c296
    ctx->pc = 0x171488u;
    SET_GPR_U32(ctx, 31, 0x171490u);
    ctx->pc = 0x17148Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x170A58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171490u; }
    }
    if (ctx->pc != 0x171490u) { return; }
    ctx->pc = 0x171490u;
    // 0x171490: 0x3c021000
    ctx->pc = 0x171490u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x171494: 0x3c031000
    ctx->pc = 0x171494u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x171498: 0x3c041000
    ctx->pc = 0x171498u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x17149c: 0x3463b410
    ctx->pc = 0x17149cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46096));
    // 0x1714a0: 0x3442b420
    ctx->pc = 0x1714a0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46112));
    // 0x1714a4: 0x3484b430
    ctx->pc = 0x1714a4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46128));
    // 0x1714a8: 0xac400000
    ctx->pc = 0x1714a8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1714ac: 0xac600000
    ctx->pc = 0x1714acu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1714b0: 0xac800000
    ctx->pc = 0x1714b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1714b4: 0xc04518c
    ctx->pc = 0x1714B4u;
    SET_GPR_U32(ctx, 31, 0x1714BCu);
    ctx->pc = 0x1714B8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 64)));
    ctx->pc = 0x114630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1714BCu; }
    }
    if (ctx->pc != 0x1714BCu) { return; }
    ctx->pc = 0x1714BCu;
    // 0x1714bc: 0x24020001
    ctx->pc = 0x1714bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1714c0: 0xdfb00000
    ctx->pc = 0x1714c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1714c4: 0xdfbf0008
    ctx->pc = 0x1714c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1714c8: 0x3e00008
    ctx->pc = 0x1714C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1714CCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1714D0u;
}
