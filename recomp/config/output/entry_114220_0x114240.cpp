#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_114220
// Address: 0x114220 - 0x114240
void entry_114220_0x114240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x114220u;

    // 0x114220: 0x24030002
    ctx->pc = 0x114220u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x114224: 0xc
    ctx->pc = 0x114224u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114228: 0x3e00008
    ctx->pc = 0x114228u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114230u;
    // 0x114230: 0x24030003
    ctx->pc = 0x114230u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
    // 0x114234: 0xc
    ctx->pc = 0x114234u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114238: 0x3e00008
    ctx->pc = 0x114238u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114240u;
}
