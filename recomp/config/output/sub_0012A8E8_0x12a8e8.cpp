#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A8E8
// Address: 0x12a8e8 - 0x12a8f0
void sub_0012A8E8_0x12a8e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A8E8_0x12a8e8");
#endif

    ctx->pc = 0x12a8e8u;

    // 0x12a8e8: 0x3e00008  jr          $ra
    ctx->pc = 0x12A8E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12A8F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
