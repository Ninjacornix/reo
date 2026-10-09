#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001921A0
// Address: 0x1921a0 - 0x1921a8
void sub_001921A0_0x1921a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001921A0_0x1921a0");
#endif

    ctx->pc = 0x1921a0u;

    // 0x1921a0: 0x8063d1c  j           func_18F470
    ctx->pc = 0x1921A0u;
    ctx->pc = 0x18F470u;
    if (runtime->hasFunction(0x18F470u)) {
        auto targetFn = runtime->lookupFunction(0x18F470u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0018F470_0x18f470(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1921A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
