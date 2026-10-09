#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3870
// Address: 0x1b3870 - 0x1b3880
void sub_001B3870_0x1b3870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3870_0x1b3870");
#endif

    ctx->pc = 0x1b3870u;

    // 0x1b3870: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3870u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B3878u;
    // 0x1b3878: 0x0  nop
    ctx->pc = 0x1b3878u;
    // NOP
    // 0x1b387c: 0x0  nop
    ctx->pc = 0x1b387cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
