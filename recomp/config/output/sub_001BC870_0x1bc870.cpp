#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC870
// Address: 0x1bc870 - 0x1bc880
void sub_001BC870_0x1bc870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC870_0x1bc870");
#endif

    ctx->pc = 0x1bc870u;

    // 0x1bc870: 0x806f23c  j           func_1BC8F0
    ctx->pc = 0x1BC870u;
    ctx->pc = 0x1BC8F0u;
    if (runtime->hasFunction(0x1BC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC8F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001BC8F0_0x1bc8f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BC878u;
    // 0x1bc878: 0x0  nop
    ctx->pc = 0x1bc878u;
    // NOP
    // 0x1bc87c: 0x0  nop
    ctx->pc = 0x1bc87cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
