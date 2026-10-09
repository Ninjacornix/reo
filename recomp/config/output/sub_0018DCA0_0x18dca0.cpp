#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DCA0
// Address: 0x18dca0 - 0x18dcb0
void sub_0018DCA0_0x18dca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DCA0_0x18dca0");
#endif

    ctx->pc = 0x18dca0u;

    // 0x18dca0: 0x806835c  j           func_1A0D70
    ctx->pc = 0x18DCA0u;
    ctx->pc = 0x1A0D70u;
    if (runtime->hasFunction(0x1A0D70u)) {
        auto targetFn = runtime->lookupFunction(0x1A0D70u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A0D70_0x1a0d70(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x18DCA8u;
    // 0x18dca8: 0x0  nop
    ctx->pc = 0x18dca8u;
    // NOP
    // 0x18dcac: 0x0  nop
    ctx->pc = 0x18dcacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
