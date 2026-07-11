#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001709F0
// Address: 0x1709f0 - 0x170a58
void sub_001709F0_0x1709f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1709f0u;

    // 0x1709f0: 0x27bdfff0
    ctx->pc = 0x1709f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1709f4: 0xffb00000
    ctx->pc = 0x1709f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1709f8: 0xffbf0008
    ctx->pc = 0x1709f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1709fc: 0xc047598
    ctx->pc = 0x1709FCu;
    SET_GPR_U32(ctx, 31, 0x170A04u);
    ctx->pc = 0x170A00u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170A04u; }
    }
    if (ctx->pc != 0x170A04u) { return; }
    ctx->pc = 0x170A04u;
    // 0x170a04: 0x3c051000
    ctx->pc = 0x170a04u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x170a08: 0x3c070001
    ctx->pc = 0x170a08u;
    SET_GPR_U32(ctx, 7, ((uint32_t)1 << 16));
    // 0x170a0c: 0x34a5f520
    ctx->pc = 0x170a0cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 62752));
    // 0x170a10: 0x3c061000
    ctx->pc = 0x170a10u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x170a14: 0x8ca20000
    ctx->pc = 0x170a14u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0))); // MMIO: 0x10000000
    // 0x170a18: 0x3c041000
    ctx->pc = 0x170a18u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x170a1c: 0x34c6f590
    ctx->pc = 0x170a1cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 62864));
    // 0x170a20: 0x3484b000
    ctx->pc = 0x170a20u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45056));
    // 0x170a24: 0x471025
    ctx->pc = 0x170a24u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x170a28: 0x3c03fffe
    ctx->pc = 0x170a28u;
    SET_GPR_U32(ctx, 3, ((uint32_t)65534 << 16));
    // 0x170a2c: 0xacc20000
    ctx->pc = 0x170a2cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x170a30: 0x3463ffff
    ctx->pc = 0x170a30u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x170a34: 0xac900000
    ctx->pc = 0x170a34u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
    // 0x170a38: 0xdfbf0008
    ctx->pc = 0x170a38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x170a3c: 0x8ca20000
    ctx->pc = 0x170a3cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x170a40: 0xdfb00000
    ctx->pc = 0x170a40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170a44: 0x431024
    ctx->pc = 0x170a44u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x170a48: 0xacc20000
    ctx->pc = 0x170a48u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x170a4c: 0x80475ae
    ctx->pc = 0x170A4Cu;
    ctx->pc = 0x170A50u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x170A54u;
    // 0x170a54: 0x0
    ctx->pc = 0x170a54u;
    // NOP
}
