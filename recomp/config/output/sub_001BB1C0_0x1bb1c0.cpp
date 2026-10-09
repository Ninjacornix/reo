#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB1C0
// Address: 0x1bb1c0 - 0x1bb1d0
void sub_001BB1C0_0x1bb1c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB1C0_0x1bb1c0");
#endif

    ctx->pc = 0x1bb1c0u;

    // 0x1bb1c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB1C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BB1C8u;
    // 0x1bb1c8: 0x0  nop
    ctx->pc = 0x1bb1c8u;
    // NOP
    // 0x1bb1cc: 0x0  nop
    ctx->pc = 0x1bb1ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
