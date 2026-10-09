#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B82B0
// Address: 0x1b82b0 - 0x1b82e0
void sub_001B82B0_0x1b82b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B82B0_0x1b82b0");
#endif

    ctx->pc = 0x1b82b0u;

    // 0x1b82b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B82B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B82B8u;
    // 0x1b82b8: 0x0  nop
    ctx->pc = 0x1b82b8u;
    // NOP
    // 0x1b82bc: 0x0  nop
    ctx->pc = 0x1b82bcu;
    // NOP
    // 0x1b82c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B82C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B82C8u;
    // 0x1b82c8: 0x0  nop
    ctx->pc = 0x1b82c8u;
    // NOP
    // 0x1b82cc: 0x0  nop
    ctx->pc = 0x1b82ccu;
    // NOP
    // 0x1b82d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B82D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B82D8u;
    // 0x1b82d8: 0x0  nop
    ctx->pc = 0x1b82d8u;
    // NOP
    // 0x1b82dc: 0x0  nop
    ctx->pc = 0x1b82dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
