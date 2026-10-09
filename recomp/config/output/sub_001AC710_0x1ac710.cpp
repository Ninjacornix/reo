#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AC710
// Address: 0x1ac710 - 0x1ac720
void sub_001AC710_0x1ac710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AC710_0x1ac710");
#endif

    ctx->pc = 0x1ac710u;

    // 0x1ac710: 0x8069f78  j           func_1A7DE0
    ctx->pc = 0x1AC710u;
    ctx->pc = 0x1A7DE0u;
    if (runtime->hasFunction(0x1A7DE0u)) {
        auto targetFn = runtime->lookupFunction(0x1A7DE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A7DE0_0x1a7de0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AC718u;
    // 0x1ac718: 0x0  nop
    ctx->pc = 0x1ac718u;
    // NOP
    // 0x1ac71c: 0x0  nop
    ctx->pc = 0x1ac71cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
