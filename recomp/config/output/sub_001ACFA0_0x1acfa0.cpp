#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ACFA0
// Address: 0x1acfa0 - 0x1acfb0
void sub_001ACFA0_0x1acfa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ACFA0_0x1acfa0");
#endif

    ctx->pc = 0x1acfa0u;

    // 0x1acfa0: 0x806b5f8  j           func_1AD7E0
    ctx->pc = 0x1ACFA0u;
    ctx->pc = 0x1AD7E0u;
    if (runtime->hasFunction(0x1AD7E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AD7E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AD7E0_0x1ad7e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1ACFA8u;
    // 0x1acfa8: 0x0  nop
    ctx->pc = 0x1acfa8u;
    // NOP
    // 0x1acfac: 0x0  nop
    ctx->pc = 0x1acfacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
