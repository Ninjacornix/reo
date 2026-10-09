#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3880
// Address: 0x1b3880 - 0x1b3890
void sub_001B3880_0x1b3880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3880_0x1b3880");
#endif

    ctx->pc = 0x1b3880u;

    // 0x1b3880: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3880u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B3888u;
    // 0x1b3888: 0x0  nop
    ctx->pc = 0x1b3888u;
    // NOP
    // 0x1b388c: 0x0  nop
    ctx->pc = 0x1b388cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
