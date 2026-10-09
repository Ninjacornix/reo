#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DF28
// Address: 0x11df28 - 0x11df30
void sub_0011DF28_0x11df28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DF28_0x11df28");
#endif

    ctx->pc = 0x11df28u;

    // 0x11df28: 0x3e00008  jr          $ra
    ctx->pc = 0x11DF28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11DF30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
