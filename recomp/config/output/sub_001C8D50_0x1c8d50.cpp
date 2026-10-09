#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8D50
// Address: 0x1c8d50 - 0x1c8d58
void sub_001C8D50_0x1c8d50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8D50_0x1c8d50");
#endif

    ctx->pc = 0x1c8d50u;

    // 0x1c8d50: 0x807204c  j           func_1C8130
    ctx->pc = 0x1C8D50u;
    ctx->pc = 0x1C8130u;
    if (runtime->hasFunction(0x1C8130u)) {
        auto targetFn = runtime->lookupFunction(0x1C8130u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8130_0x1c8130(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C8D58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
