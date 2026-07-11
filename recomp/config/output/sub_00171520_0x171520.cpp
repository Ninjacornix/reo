#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00171520
// Address: 0x171520 - 0x171530
void sub_00171520_0x171520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x171520u;

    // 0x171520: 0x3c020023
    ctx->pc = 0x171520u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x171524: 0x3e00008
    ctx->pc = 0x171524u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171528u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963648), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17152Cu;
    // 0x17152c: 0x0
    ctx->pc = 0x17152cu;
    // NOP
}
