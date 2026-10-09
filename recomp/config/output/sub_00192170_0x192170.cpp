#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192170
// Address: 0x192170 - 0x1921b0
void sub_00192170_0x192170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192170_0x192170");
#endif

    ctx->pc = 0x192170u;

    // 0x192170: 0x8048850  j           func_122140
    ctx->pc = 0x192170u;
    ctx->pc = 0x122140u;
    if (runtime->hasFunction(0x122140u)) {
        auto targetFn = runtime->lookupFunction(0x122140u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122140_0x122140(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x192178u;
    // 0x192178: 0x0  nop
    ctx->pc = 0x192178u;
    // NOP
    // 0x19217c: 0x0  nop
    ctx->pc = 0x19217cu;
    // NOP
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
    // 0x192188: 0x0  nop
    ctx->pc = 0x192188u;
    // NOP
    // 0x19218c: 0x0  nop
    ctx->pc = 0x19218cu;
    // NOP
    // 0x192190: 0x8063cd0  j           func_18F340
    ctx->pc = 0x192190u;
    ctx->pc = 0x18F340u;
    if (runtime->hasFunction(0x18F340u)) {
        auto targetFn = runtime->lookupFunction(0x18F340u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0018F340_0x18f340(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x192198u;
    // 0x192198: 0x0  nop
    ctx->pc = 0x192198u;
    // NOP
    // 0x19219c: 0x0  nop
    ctx->pc = 0x19219cu;
    // NOP
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
    // 0x1921a8: 0x0  nop
    ctx->pc = 0x1921a8u;
    // NOP
    // 0x1921ac: 0x0  nop
    ctx->pc = 0x1921acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
