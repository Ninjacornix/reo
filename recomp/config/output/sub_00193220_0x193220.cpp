#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193220
// Address: 0x193220 - 0x193228
void sub_00193220_0x193220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193220_0x193220");
#endif

    ctx->pc = 0x193220u;

    // 0x193220: 0x8064c0c  j           func_193030
    ctx->pc = 0x193220u;
    ctx->pc = 0x193030u;
    if (runtime->hasFunction(0x193030u)) {
        auto targetFn = runtime->lookupFunction(0x193030u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00193030_0x193030(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x193228u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
