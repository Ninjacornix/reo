#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F45C0
// Address: 0x1f45c0 - 0x1f45d0
void sub_001F45C0_0x1f45c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F45C0_0x1f45c0");
#endif

    ctx->pc = 0x1f45c0u;

    // 0x1f45c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F45C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F45C8u;
    // 0x1f45c8: 0x0  nop
    ctx->pc = 0x1f45c8u;
    // NOP
    // 0x1f45cc: 0x0  nop
    ctx->pc = 0x1f45ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
