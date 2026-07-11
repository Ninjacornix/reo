#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00163420
// Address: 0x163420 - 0x163440
void sub_00163420_0x163420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x163420u;

    // 0x163420: 0x3c030023
    ctx->pc = 0x163420u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x163424: 0x3e00008
    ctx->pc = 0x163424u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163428u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294963024)));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16342Cu;
    // 0x16342c: 0x0
    ctx->pc = 0x16342cu;
    // NOP
    // 0x163430: 0x3c020023
    ctx->pc = 0x163430u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x163434: 0x3e00008
    ctx->pc = 0x163434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163438u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963024), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16343Cu;
    // 0x16343c: 0x0
    ctx->pc = 0x16343cu;
    // NOP
}
