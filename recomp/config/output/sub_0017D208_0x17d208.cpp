#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017D208
// Address: 0x17d208 - 0x17d218
void sub_0017D208_0x17d208(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17d208u;

    // 0x17d208: 0x3c020023
    ctx->pc = 0x17d208u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x17d20c: 0x3e00008
    ctx->pc = 0x17D20Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D210u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963892), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D214u;
    // 0x17d214: 0x0
    ctx->pc = 0x17d214u;
    // NOP
}
