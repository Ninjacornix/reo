#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF790
// Address: 0x1af790 - 0x1af7a0
void sub_001AF790_0x1af790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF790_0x1af790");
#endif

    ctx->pc = 0x1af790u;

    // 0x1af790: 0x8066318  j           func_198C60
    ctx->pc = 0x1AF790u;
    ctx->pc = 0x198C60u;
    if (runtime->hasFunction(0x198C60u)) {
        auto targetFn = runtime->lookupFunction(0x198C60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00198C60_0x198c60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AF798u;
    // 0x1af798: 0x0  nop
    ctx->pc = 0x1af798u;
    // NOP
    // 0x1af79c: 0x0  nop
    ctx->pc = 0x1af79cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
