#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00135068
// Address: 0x135068 - 0x135078
void sub_00135068_0x135068(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x135068u;

    // 0x135068: 0x3c030022
    ctx->pc = 0x135068u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13506c: 0x24020001
    ctx->pc = 0x13506cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x135070: 0x3e00008
    ctx->pc = 0x135070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135074u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294948784), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x135078u;
}
