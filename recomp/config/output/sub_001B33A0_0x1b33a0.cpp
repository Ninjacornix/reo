#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B33A0
// Address: 0x1b33a0 - 0x1b33a8
void sub_001B33A0_0x1b33a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B33A0_0x1b33a0");
#endif

    ctx->pc = 0x1b33a0u;

    // 0x1b33a0: 0x806315c  j           func_18C570
    ctx->pc = 0x1B33A0u;
    ctx->pc = 0x18C570u;
    if (runtime->hasFunction(0x18C570u)) {
        auto targetFn = runtime->lookupFunction(0x18C570u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0018C570_0x18c570(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B33A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
