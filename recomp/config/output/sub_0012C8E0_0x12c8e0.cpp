#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C8E0
// Address: 0x12c8e0 - 0x12c8e8
void sub_0012C8E0_0x12c8e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C8E0_0x12c8e0");
#endif

    ctx->pc = 0x12c8e0u;

    // 0x12c8e0: 0x3e00008  jr          $ra
    ctx->pc = 0x12C8E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12C8E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
