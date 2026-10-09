#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF300
// Address: 0x1cf300 - 0x1cf320
void sub_001CF300_0x1cf300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF300_0x1cf300");
#endif

    ctx->pc = 0x1cf300u;

    // 0x1cf300: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CF300u;
    {
        const bool branch_taken_0x1cf300 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF300u;
            // 0x1cf304: 0x3c028000  lui         $v0, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf300) {
            ctx->pc = 0x1CF30Cu;
            goto label_1cf30c;
        }
    }
    ctx->pc = 0x1CF308u;
    // 0x1cf308: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1cf308u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_1cf30c:
    // 0x1cf30c: 0x8073c24  j           func_1CF090
    ctx->pc = 0x1CF30Cu;
    ctx->pc = 0x1CF090u;
    if (runtime->hasFunction(0x1CF090u)) {
        auto targetFn = runtime->lookupFunction(0x1CF090u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CF090_0x1cf090(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1CF314u;
    // 0x1cf314: 0x0  nop
    ctx->pc = 0x1cf314u;
    // NOP
    // 0x1cf318: 0x0  nop
    ctx->pc = 0x1cf318u;
    // NOP
    // 0x1cf31c: 0x0  nop
    ctx->pc = 0x1cf31cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
