#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00114AA0
// Address: 0x114aa0 - 0x114ab0
void sub_00114AA0_0x114aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x114aa0u;

    // 0x114aa0: 0x3c020021
    ctx->pc = 0x114aa0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x114aa4: 0x3e00008
    ctx->pc = 0x114AA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114AA8u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294942000), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114AACu;
    // 0x114aac: 0x0
    ctx->pc = 0x114aacu;
    // NOP
}
