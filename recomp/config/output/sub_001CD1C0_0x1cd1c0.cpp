#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001CD1C0
// Address: 0x1cd1c0 - 0x1cd1d0
void sub_001CD1C0_0x1cd1c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1cd1c0u;

    // 0x1cd1c0: 0x3c010023
    ctx->pc = 0x1cd1c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1cd1c4: 0x3e00008
    ctx->pc = 0x1CD1C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD1C8u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 26312), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1CD1CCu;
    // 0x1cd1cc: 0x0
    ctx->pc = 0x1cd1ccu;
    // NOP
}
