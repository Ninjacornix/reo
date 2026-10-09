#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D25A0
// Address: 0x1d25a0 - 0x1d25a8
void sub_001D25A0_0x1d25a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D25A0_0x1d25a0");
#endif

    ctx->pc = 0x1d25a0u;

    // 0x1d25a0: 0x80738fc  j           func_1CE3F0
    ctx->pc = 0x1D25A0u;
    ctx->pc = 0x1CE3F0u;
    if (runtime->hasFunction(0x1CE3F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CE3F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CE3F0_0x1ce3f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D25A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
