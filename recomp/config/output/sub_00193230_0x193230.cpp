#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193230
// Address: 0x193230 - 0x193238
void sub_00193230_0x193230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193230_0x193230");
#endif

    ctx->pc = 0x193230u;

    // 0x193230: 0x8064c3c  j           func_1930F0
    ctx->pc = 0x193230u;
    ctx->pc = 0x1930F0u;
    if (runtime->hasFunction(0x1930F0u)) {
        auto targetFn = runtime->lookupFunction(0x1930F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001930F0_0x1930f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x193238u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
