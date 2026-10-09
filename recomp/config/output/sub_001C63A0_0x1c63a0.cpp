#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C63A0
// Address: 0x1c63a0 - 0x1c63a8
void sub_001C63A0_0x1c63a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C63A0_0x1c63a0");
#endif

    ctx->pc = 0x1c63a0u;

    // 0x1c63a0: 0x80718d8  j           func_1C6360
    ctx->pc = 0x1C63A0u;
    ctx->pc = 0x1C6360u;
    if (runtime->hasFunction(0x1C6360u)) {
        auto targetFn = runtime->lookupFunction(0x1C6360u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C6360_0x1c6360(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C63A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
