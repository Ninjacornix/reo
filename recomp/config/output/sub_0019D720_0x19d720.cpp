#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D720
// Address: 0x19d720 - 0x19d730
void sub_0019D720_0x19d720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D720_0x19d720");
#endif

    ctx->pc = 0x19d720u;

    // 0x19d720: 0x80675cc  j           func_19D730
    ctx->pc = 0x19D720u;
    ctx->pc = 0x19D730u;
    if (runtime->hasFunction(0x19D730u)) {
        auto targetFn = runtime->lookupFunction(0x19D730u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0019D730_0x19d730(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x19D728u;
    // 0x19d728: 0x0  nop
    ctx->pc = 0x19d728u;
    // NOP
    // 0x19d72c: 0x0  nop
    ctx->pc = 0x19d72cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
