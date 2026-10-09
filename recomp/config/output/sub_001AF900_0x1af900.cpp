#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF900
// Address: 0x1af900 - 0x1af910
void sub_001AF900_0x1af900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF900_0x1af900");
#endif

    ctx->pc = 0x1af900u;

    // 0x1af900: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF900u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1AF908u;
    // 0x1af908: 0x0  nop
    ctx->pc = 0x1af908u;
    // NOP
    // 0x1af90c: 0x0  nop
    ctx->pc = 0x1af90cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
