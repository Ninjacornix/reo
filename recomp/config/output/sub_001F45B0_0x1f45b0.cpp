#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F45B0
// Address: 0x1f45b0 - 0x1f45c0
void sub_001F45B0_0x1f45b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F45B0_0x1f45b0");
#endif

    ctx->pc = 0x1f45b0u;

    // 0x1f45b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F45B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F45B8u;
    // 0x1f45b8: 0x0  nop
    ctx->pc = 0x1f45b8u;
    // NOP
    // 0x1f45bc: 0x0  nop
    ctx->pc = 0x1f45bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
