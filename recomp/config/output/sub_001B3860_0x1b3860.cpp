#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3860
// Address: 0x1b3860 - 0x1b3870
void sub_001B3860_0x1b3860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3860_0x1b3860");
#endif

    ctx->pc = 0x1b3860u;

    // 0x1b3860: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3860u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B3868u;
    // 0x1b3868: 0x0  nop
    ctx->pc = 0x1b3868u;
    // NOP
    // 0x1b386c: 0x0  nop
    ctx->pc = 0x1b386cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
