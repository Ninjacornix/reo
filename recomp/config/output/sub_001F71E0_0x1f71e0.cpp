#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F71E0
// Address: 0x1f71e0 - 0x1f71f0
void sub_001F71E0_0x1f71e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F71E0_0x1f71e0");
#endif

    ctx->pc = 0x1f71e0u;

    // 0x1f71e0: 0x806ecac  j           func_1BB2B0
    ctx->pc = 0x1F71E0u;
    ctx->pc = 0x1BB2B0u;
    if (runtime->hasFunction(0x1BB2B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB2B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001BB2B0_0x1bb2b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1F71E8u;
    // 0x1f71e8: 0x0  nop
    ctx->pc = 0x1f71e8u;
    // NOP
    // 0x1f71ec: 0x0  nop
    ctx->pc = 0x1f71ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
