#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD2E0
// Address: 0x1bd2e0 - 0x1bd2e8
void sub_001BD2E0_0x1bd2e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD2E0_0x1bd2e0");
#endif

    ctx->pc = 0x1bd2e0u;

    // 0x1bd2e0: 0x8045194  j           func_114650
    ctx->pc = 0x1BD2E0u;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114650_0x114650(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BD2E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
