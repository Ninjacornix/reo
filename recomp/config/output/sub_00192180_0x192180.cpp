#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192180
// Address: 0x192180 - 0x192188
void sub_00192180_0x192180(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192180_0x192180");
#endif

    ctx->pc = 0x192180u;

    // 0x192180: 0x80489bc  j           func_1226F0
    ctx->pc = 0x192180u;
    ctx->pc = 0x1226F0u;
    if (runtime->hasFunction(0x1226F0u)) {
        auto targetFn = runtime->lookupFunction(0x1226F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001226F0_0x1226f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x192188u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
