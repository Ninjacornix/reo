#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00173BF0
// Address: 0x173bf0 - 0x173c00
void sub_00173BF0_0x173bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x173bf0u;

    // 0x173bf0: 0x3c020023
    ctx->pc = 0x173bf0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x173bf4: 0x3e00008
    ctx->pc = 0x173BF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173BF8u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963588), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x173BFCu;
    // 0x173bfc: 0x0
    ctx->pc = 0x173bfcu;
    // NOP
}
