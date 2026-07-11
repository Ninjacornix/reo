#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013ADF0
// Address: 0x13adf0 - 0x13ae10
void sub_0013ADF0_0x13adf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13adf0u;

    // 0x13adf0: 0x3c020022
    ctx->pc = 0x13adf0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13adf4: 0x3c030022
    ctx->pc = 0x13adf4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13adf8: 0x2442d8e0
    ctx->pc = 0x13adf8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294957280));
    // 0x13adfc: 0xac67d8e4
    ctx->pc = 0x13adfcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294957284), GPR_U32(ctx, 7));
    // 0x13ae00: 0xa0460002
    ctx->pc = 0x13ae00u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x13ae04: 0xa0440000
    ctx->pc = 0x13ae04u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x13ae08: 0x3e00008
    ctx->pc = 0x13AE08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AE0Cu;
        WRITE8(ADD32(GPR_U32(ctx, 2), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13AE10u;
}
