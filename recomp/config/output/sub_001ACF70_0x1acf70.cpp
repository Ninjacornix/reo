#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ACF70
// Address: 0x1acf70 - 0x1acf80
void sub_001ACF70_0x1acf70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ACF70_0x1acf70");
#endif

    ctx->pc = 0x1acf70u;

    // 0x1acf70: 0x8069ea0  j           func_1A7A80
    ctx->pc = 0x1ACF70u;
    ctx->pc = 0x1A7A80u;
    if (runtime->hasFunction(0x1A7A80u)) {
        auto targetFn = runtime->lookupFunction(0x1A7A80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A7A80_0x1a7a80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1ACF78u;
    // 0x1acf78: 0x0  nop
    ctx->pc = 0x1acf78u;
    // NOP
    // 0x1acf7c: 0x0  nop
    ctx->pc = 0x1acf7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
