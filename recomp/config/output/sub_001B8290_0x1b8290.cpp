#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8290
// Address: 0x1b8290 - 0x1b82a0
void sub_001B8290_0x1b8290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8290_0x1b8290");
#endif

    ctx->pc = 0x1b8290u;

    // 0x1b8290: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B8298u;
    // 0x1b8298: 0x0  nop
    ctx->pc = 0x1b8298u;
    // NOP
    // 0x1b829c: 0x0  nop
    ctx->pc = 0x1b829cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
