#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001CC800
// Address: 0x1cc800 - 0x1cc830
void sub_001CC800_0x1cc800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1cc800u;

    // 0x1cc800: 0x3c011001
    ctx->pc = 0x1cc800u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x1cc804: 0x24030100
    ctx->pc = 0x1cc804u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 256));
    // 0x1cc808: 0xac24b010
    ctx->pc = 0x1cc808u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946832), GPR_U32(ctx, 4)); // MMIO: 0x1000b010
    // 0x1cc80c: 0x52280
    ctx->pc = 0x1cc80cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 5), 10));
    // 0x1cc810: 0x3c011001
    ctx->pc = 0x1cc810u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x1cc814: 0x42102
    ctx->pc = 0x1cc814u;
    SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 4), 4));
    // 0x1cc818: 0xac24b020
    ctx->pc = 0x1cc818u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946848), GPR_U32(ctx, 4)); // MMIO: 0x1000b020
    // 0x1cc81c: 0x3c011001
    ctx->pc = 0x1cc81cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x1cc820: 0x3e00008
    ctx->pc = 0x1CC820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC824u;
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946816), GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1CC828u;
    // 0x1cc828: 0x0
    ctx->pc = 0x1cc828u;
    // NOP
    // 0x1cc82c: 0x0
    ctx->pc = 0x1cc82cu;
    // NOP
}
