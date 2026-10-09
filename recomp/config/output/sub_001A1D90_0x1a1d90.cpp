#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1D90
// Address: 0x1a1d90 - 0x1a1da0
void sub_001A1D90_0x1a1d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1D90_0x1a1d90");
#endif

    ctx->pc = 0x1a1d90u;

    // 0x1a1d90: 0x80697ac  j           func_1A5EB0
    ctx->pc = 0x1A1D90u;
    ctx->pc = 0x1A5EB0u;
    if (runtime->hasFunction(0x1A5EB0u)) {
        auto targetFn = runtime->lookupFunction(0x1A5EB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A5EB0_0x1a5eb0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A1D98u;
    // 0x1a1d98: 0x0  nop
    ctx->pc = 0x1a1d98u;
    // NOP
    // 0x1a1d9c: 0x0  nop
    ctx->pc = 0x1a1d9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
