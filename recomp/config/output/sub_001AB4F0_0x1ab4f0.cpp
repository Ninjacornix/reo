#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB4F0
// Address: 0x1ab4f0 - 0x1ab500
void sub_001AB4F0_0x1ab4f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB4F0_0x1ab4f0");
#endif

    ctx->pc = 0x1ab4f0u;

    // 0x1ab4f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB4F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1AB4F8u;
    // 0x1ab4f8: 0x0  nop
    ctx->pc = 0x1ab4f8u;
    // NOP
    // 0x1ab4fc: 0x0  nop
    ctx->pc = 0x1ab4fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
