#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D700
// Address: 0x15d700 - 0x15d708
void sub_0015D700_0x15d700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D700_0x15d700");
#endif

    ctx->pc = 0x15d700u;

    // 0x15d700: 0x3e00008  jr          $ra
    ctx->pc = 0x15D700u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15D708u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
