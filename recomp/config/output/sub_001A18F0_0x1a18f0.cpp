#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A18F0
// Address: 0x1a18f0 - 0x1a18f8
void sub_001A18F0_0x1a18f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A18F0_0x1a18f0");
#endif

    ctx->pc = 0x1a18f0u;

    // 0x1a18f0: 0x80697a0  j           func_1A5E80
    ctx->pc = 0x1A18F0u;
    ctx->pc = 0x1A5E80u;
    if (runtime->hasFunction(0x1A5E80u)) {
        auto targetFn = runtime->lookupFunction(0x1A5E80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A5E80_0x1a5e80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A18F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
