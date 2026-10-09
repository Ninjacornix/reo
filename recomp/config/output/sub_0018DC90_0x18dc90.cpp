#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DC90
// Address: 0x18dc90 - 0x18dca0
void sub_0018DC90_0x18dc90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DC90_0x18dc90");
#endif

    ctx->pc = 0x18dc90u;

    // 0x18dc90: 0x8068360  j           func_1A0D80
    ctx->pc = 0x18DC90u;
    ctx->pc = 0x1A0D80u;
    if (runtime->hasFunction(0x1A0D80u)) {
        auto targetFn = runtime->lookupFunction(0x1A0D80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A0D80_0x1a0d80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x18DC98u;
    // 0x18dc98: 0x0  nop
    ctx->pc = 0x18dc98u;
    // NOP
    // 0x18dc9c: 0x0  nop
    ctx->pc = 0x18dc9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
