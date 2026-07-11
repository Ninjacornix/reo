#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00143F88
// Address: 0x143f88 - 0x143fb0
void sub_00143F88_0x143f88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x143f88u;

    // 0x143f88: 0x3c051000
    ctx->pc = 0x143f88u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x143f8c: 0x3c03ff7f
    ctx->pc = 0x143f8cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)65407 << 16));
    // 0x143f90: 0x34a52010
    ctx->pc = 0x143f90u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 8208));
    // 0x143f94: 0x3463ffff
    ctx->pc = 0x143f94u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x143f98: 0x8ca20000
    ctx->pc = 0x143f98u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0))); // MMIO: 0x10000000
    // 0x143f9c: 0x425c0
    ctx->pc = 0x143f9cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 23));
    // 0x143fa0: 0x431024
    ctx->pc = 0x143fa0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x143fa4: 0x441025
    ctx->pc = 0x143fa4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x143fa8: 0x3e00008
    ctx->pc = 0x143FA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x143FACu;
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x143FB0u;
}
