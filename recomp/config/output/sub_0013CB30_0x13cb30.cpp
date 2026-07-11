#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013CB30
// Address: 0x13cb30 - 0x13cb50
void sub_0013CB30_0x13cb30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13cb30u;

    // 0x13cb30: 0x3c020022
    ctx->pc = 0x13cb30u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13cb34: 0x3e00008
    ctx->pc = 0x13CB34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CB38u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294958756), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13CB3Cu;
    // 0x13cb3c: 0x0
    ctx->pc = 0x13cb3cu;
    // NOP
    // 0x13cb40: 0x3c030022
    ctx->pc = 0x13cb40u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13cb44: 0x3e00008
    ctx->pc = 0x13CB44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CB48u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294958756)));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13CB4Cu;
    // 0x13cb4c: 0x0
    ctx->pc = 0x13cb4cu;
    // NOP
}
