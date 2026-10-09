#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192100
// Address: 0x192100 - 0x192108
void sub_00192100_0x192100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192100_0x192100");
#endif

    ctx->pc = 0x192100u;

    // 0x192100: 0x80489b6  j           func_1226D8
    ctx->pc = 0x192100u;
    ctx->pc = 0x1226D8u;
    if (runtime->hasFunction(0x1226D8u)) {
        auto targetFn = runtime->lookupFunction(0x1226D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001226D8_0x1226d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x192108u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
