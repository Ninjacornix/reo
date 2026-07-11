#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001328A8
// Address: 0x1328a8 - 0x1328b8
void sub_001328A8_0x1328a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1328a8u;

    // 0x1328a8: 0x3c020022
    ctx->pc = 0x1328a8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x1328ac: 0x3e00008
    ctx->pc = 0x1328ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1328B0u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294948696), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1328B4u;
    // 0x1328b4: 0x0
    ctx->pc = 0x1328b4u;
    // NOP
}
