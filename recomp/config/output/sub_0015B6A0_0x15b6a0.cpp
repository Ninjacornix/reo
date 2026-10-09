#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B6A0
// Address: 0x15b6a0 - 0x15b6a8
void sub_0015B6A0_0x15b6a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B6A0_0x15b6a0");
#endif

    ctx->pc = 0x15b6a0u;

    // 0x15b6a0: 0x3e00008  jr          $ra
    ctx->pc = 0x15B6A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15B6A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
