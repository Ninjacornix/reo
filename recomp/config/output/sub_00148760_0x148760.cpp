#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00148760
// Address: 0x148760 - 0x148828
void sub_00148760_0x148760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x148760u;

    // 0x148760: 0x27bdfff0
    ctx->pc = 0x148760u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x148764: 0x24020001
    ctx->pc = 0x148764u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x148768: 0xffbf0000
    ctx->pc = 0x148768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14876c: 0xac820830
    ctx->pc = 0x14876cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 2096), GPR_U32(ctx, 2));
    // 0x148770: 0xc047598
    ctx->pc = 0x148770u;
    SET_GPR_U32(ctx, 31, 0x148778u);
    ctx->pc = 0x148774u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 456), GPR_U32(ctx, 0));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148778u; }
    }
    if (ctx->pc != 0x148778u) { return; }
    ctx->pc = 0x148778u;
    // 0x148778: 0x3c061000
    ctx->pc = 0x148778u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x14877c: 0x3c071000
    ctx->pc = 0x14877cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x148780: 0x34c6f520
    ctx->pc = 0x148780u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 62752));
    // 0x148784: 0x3c080001
    ctx->pc = 0x148784u;
    SET_GPR_U32(ctx, 8, ((uint32_t)1 << 16));
    // 0x148788: 0x8cc30000
    ctx->pc = 0x148788u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 0))); // MMIO: 0x10000000
    // 0x14878c: 0x34e7f590
    ctx->pc = 0x14878cu;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 62864));
    // 0x148790: 0x3c041000
    ctx->pc = 0x148790u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x148794: 0x3c051000
    ctx->pc = 0x148794u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x148798: 0x681825
    ctx->pc = 0x148798u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x14879c: 0x3484b000
    ctx->pc = 0x14879cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45056));
    // 0x1487a0: 0xace30000
    ctx->pc = 0x1487a0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x1487a4: 0x34a5b400
    ctx->pc = 0x1487a4u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 46080));
    // 0x1487a8: 0xac800000
    ctx->pc = 0x1487a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1487ac: 0x3c031000
    ctx->pc = 0x1487acu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1487b0: 0xaca00000
    ctx->pc = 0x1487b0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x1487b4: 0x3463d400
    ctx->pc = 0x1487b4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 54272));
    // 0x1487b8: 0xac600000
    ctx->pc = 0x1487b8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x1487bc: 0x3c04fffe
    ctx->pc = 0x1487bcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)65534 << 16));
    // 0x1487c0: 0x3484ffff
    ctx->pc = 0x1487c0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 65535));
    // 0x1487c4: 0x8cc30000
    ctx->pc = 0x1487c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1487c8: 0x641824
    ctx->pc = 0x1487c8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1487cc: 0xace30000
    ctx->pc = 0x1487ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x1487d0: 0x10400004
    ctx->pc = 0x1487D0u;
    {
        const bool branch_taken_0x1487d0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1487D4u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x1487d0) {
            ctx->pc = 0x1487E4u;
            goto label_1487e4;
        }
    }
    ctx->pc = 0x1487D8u;
    // 0x1487d8: 0xc0475ae
    ctx->pc = 0x1487D8u;
    SET_GPR_U32(ctx, 31, 0x1487E0u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1487E0u; }
    }
    if (ctx->pc != 0x1487E0u) { return; }
    ctx->pc = 0x1487E0u;
    // 0x1487e0: 0x3c021000
    ctx->pc = 0x1487e0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_1487e4:
    // 0x1487e4: 0x3c041000
    ctx->pc = 0x1487e4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1487e8: 0x3442b020
    ctx->pc = 0x1487e8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45088));
    // 0x1487ec: 0x3484b420
    ctx->pc = 0x1487ecu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46112));
    // 0x1487f0: 0xac400000
    ctx->pc = 0x1487f0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x1487f4: 0x3c031000
    ctx->pc = 0x1487f4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1487f8: 0xac800000
    ctx->pc = 0x1487f8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x1487fc: 0x3463d420
    ctx->pc = 0x1487fcu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 54304));
    // 0x148800: 0xac600000
    ctx->pc = 0x148800u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x148804: 0x3c021000
    ctx->pc = 0x148804u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x148808: 0x34422010
    ctx->pc = 0x148808u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x14880c: 0x3c034000
    ctx->pc = 0x14880cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
    // 0x148810: 0xdfbf0000
    ctx->pc = 0x148810u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x148814: 0x202d
    ctx->pc = 0x148814u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148818: 0xac430000
    ctx->pc = 0x148818u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x14881c: 0x282d
    ctx->pc = 0x14881cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148820: 0x8044fb4
    ctx->pc = 0x148820u;
    ctx->pc = 0x148824u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x113ED0u;
    sub_00113ED0_0x113ed0(rdram, ctx, runtime); return;
    ctx->pc = 0x148828u;
}
