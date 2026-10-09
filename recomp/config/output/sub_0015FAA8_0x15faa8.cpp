#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FAA8
// Address: 0x15faa8 - 0x15fab8
void sub_0015FAA8_0x15faa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FAA8_0x15faa8");
#endif

    switch (ctx->pc) {
        case 0x15fab0u: goto label_15fab0;
        default: break;
    }

    ctx->pc = 0x15faa8u;

    // 0x15faa8: 0x3e00008  jr          $ra
    ctx->pc = 0x15FAA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FAB0u: goto label_15fab0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FAB0u;
label_15fab0:
    // 0x15fab0: 0x3e00008  jr          $ra
    ctx->pc = 0x15FAB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FAB0u: goto label_15fab0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FAB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
