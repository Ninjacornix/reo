#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00145228
// Address: 0x145228 - 0x145258
void sub_00145228_0x145228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x145228u;

    // 0x145228: 0x3c021000
    ctx->pc = 0x145228u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x14522c: 0x53702
    ctx->pc = 0x14522cu;
    SET_GPR_U32(ctx, 6, SRL32(GPR_U32(ctx, 5), 28));
    // 0x145230: 0x34422000
    ctx->pc = 0x145230u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x145234: 0x3c030023
    ctx->pc = 0x145234u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x145238: 0xac450000
    ctx->pc = 0x145238u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x14523c: 0x2463a6f8
    ctx->pc = 0x14523cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294944504));
    // 0x145240: 0x63080
    ctx->pc = 0x145240u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 6), 2));
    // 0x145244: 0xc33021
    ctx->pc = 0x145244u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x145248: 0x8cc20000
    ctx->pc = 0x145248u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14524c: 0x3e00008
    ctx->pc = 0x14524Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145250u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 2096), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x145254u;
    // 0x145254: 0x0
    ctx->pc = 0x145254u;
    // NOP
}
