#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FAB0
// Address: 0x15fab0 - 0x15fab8
void sub_0015FAB0_0x15fab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FAB0_0x15fab0");
#endif

    ctx->pc = 0x15fab0u;

    // 0x15fab0: 0x3e00008  jr          $ra
    ctx->pc = 0x15FAB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15FAB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
