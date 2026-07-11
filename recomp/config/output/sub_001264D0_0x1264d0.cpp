#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001264D0
// Address: 0x1264d0 - 0x1264e0
void sub_001264D0_0x1264d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1264d0u;

    // 0x1264d0: 0x3c020021
    ctx->pc = 0x1264d0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x1264d4: 0x3e00008
    ctx->pc = 0x1264D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1264D8u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294952864), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1264DCu;
    // 0x1264dc: 0x0
    ctx->pc = 0x1264dcu;
    // NOP
}
