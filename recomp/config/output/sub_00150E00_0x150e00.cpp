#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150E00
// Address: 0x150e00 - 0x150e08
void sub_00150E00_0x150e00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150E00_0x150e00");
#endif

    ctx->pc = 0x150e00u;

    // 0x150e00: 0x3e00008  jr          $ra
    ctx->pc = 0x150E00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x150E08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
