#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2CD0
// Address: 0x1b2cd0 - 0x1b2ce0
void sub_001B2CD0_0x1b2cd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2CD0_0x1b2cd0");
#endif

    ctx->pc = 0x1b2cd0u;

    // 0x1b2cd0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2CD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B2CD8u;
    // 0x1b2cd8: 0x0  nop
    ctx->pc = 0x1b2cd8u;
    // NOP
    // 0x1b2cdc: 0x0  nop
    ctx->pc = 0x1b2cdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
