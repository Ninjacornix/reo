#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001307E8
// Address: 0x1307e8 - 0x130800
void sub_001307E8_0x1307e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1307e8u;

    // 0x1307e8: 0x3c030022
    ctx->pc = 0x1307e8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x1307ec: 0x2463a8b8
    ctx->pc = 0x1307ecu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294944952));
    // 0x1307f0: 0x8c620000
    ctx->pc = 0x1307f0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1307f4: 0x24420001
    ctx->pc = 0x1307f4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1307f8: 0x3e00008
    ctx->pc = 0x1307F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1307FCu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130800u;
}
