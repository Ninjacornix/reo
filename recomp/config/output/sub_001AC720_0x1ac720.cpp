#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AC720
// Address: 0x1ac720 - 0x1ac730
void sub_001AC720_0x1ac720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AC720_0x1ac720");
#endif

    ctx->pc = 0x1ac720u;

    // 0x1ac720: 0x806b1b4  j           func_1AC6D0
    ctx->pc = 0x1AC720u;
    ctx->pc = 0x1AC6D0u;
    if (runtime->hasFunction(0x1AC6D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AC6D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AC6D0_0x1ac6d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AC728u;
    // 0x1ac728: 0x0  nop
    ctx->pc = 0x1ac728u;
    // NOP
    // 0x1ac72c: 0x0  nop
    ctx->pc = 0x1ac72cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
