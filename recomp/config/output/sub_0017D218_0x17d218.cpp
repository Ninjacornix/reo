#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017D218
// Address: 0x17d218 - 0x17d248
void sub_0017D218_0x17d218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17d218u;

    // 0x17d218: 0x3c030023
    ctx->pc = 0x17d218u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17d21c: 0x3e00008
    ctx->pc = 0x17D21Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D220u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294963892)));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D224u;
    // 0x17d224: 0x0
    ctx->pc = 0x17d224u;
    // NOP
    // 0x17d228: 0x3c020023
    ctx->pc = 0x17d228u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x17d22c: 0x3e00008
    ctx->pc = 0x17D22Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D230u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963868), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D234u;
    // 0x17d234: 0x0
    ctx->pc = 0x17d234u;
    // NOP
    // 0x17d238: 0x3c030023
    ctx->pc = 0x17d238u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17d23c: 0x3e00008
    ctx->pc = 0x17D23Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D240u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294963868)));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D244u;
    // 0x17d244: 0x0
    ctx->pc = 0x17d244u;
    // NOP
}
