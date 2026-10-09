#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D588
// Address: 0x13d588 - 0x13d590
void sub_0013D588_0x13d588(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D588_0x13d588");
#endif

    ctx->pc = 0x13d588u;

    // 0x13d588: 0x3e00008  jr          $ra
    ctx->pc = 0x13D588u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13D590u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
