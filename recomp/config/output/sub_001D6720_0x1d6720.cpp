#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001D6720
// Address: 0x1d6720 - 0x1d6760
void sub_001D6720_0x1d6720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1d6720u;

    // 0x1d6720: 0x3c010034
    ctx->pc = 0x1d6720u;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1d6724: 0x8c2245e8
    ctx->pc = 0x1d6724u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 17896)));
    // 0x1d6728: 0x38420003
    ctx->pc = 0x1d6728u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 3));
    // 0x1d672c: 0x3e00008
    ctx->pc = 0x1D672Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6730u;
        SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 1));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D6734u;
    // 0x1d6734: 0x0
    ctx->pc = 0x1d6734u;
    // NOP
    // 0x1d6738: 0x0
    ctx->pc = 0x1d6738u;
    // NOP
    // 0x1d673c: 0x0
    ctx->pc = 0x1d673cu;
    // NOP
    // 0x1d6740: 0x4102b
    ctx->pc = 0x1d6740u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x1d6744: 0x3c010034
    ctx->pc = 0x1d6744u;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1d6748: 0x38420001
    ctx->pc = 0x1d6748u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 1));
    // 0x1d674c: 0x3e00008
    ctx->pc = 0x1D674Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6750u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 17904), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D6754u;
    // 0x1d6754: 0x0
    ctx->pc = 0x1d6754u;
    // NOP
    // 0x1d6758: 0x0
    ctx->pc = 0x1d6758u;
    // NOP
    // 0x1d675c: 0x0
    ctx->pc = 0x1d675cu;
    // NOP
}
