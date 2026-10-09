#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BCD20
// Address: 0x1bcd20 - 0x1bcd28
void sub_001BCD20_0x1bcd20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BCD20_0x1bcd20");
#endif

    ctx->pc = 0x1bcd20u;

    // 0x1bcd20: 0x80748a0  j           func_1D2280
    ctx->pc = 0x1BCD20u;
    ctx->pc = 0x1D2280u;
    if (runtime->hasFunction(0x1D2280u)) {
        auto targetFn = runtime->lookupFunction(0x1D2280u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001D2280_0x1d2280(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BCD28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
