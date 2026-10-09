#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6C60
// Address: 0x1c6c60 - 0x1c6c68
void sub_001C6C60_0x1c6c60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6C60_0x1c6c60");
#endif

    ctx->pc = 0x1c6c60u;

    // 0x1c6c60: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6C60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C6C68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
