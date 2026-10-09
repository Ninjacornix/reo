#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8830
// Address: 0x1c8830 - 0x1c8840
void sub_001C8830_0x1c8830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8830_0x1c8830");
#endif

    ctx->pc = 0x1c8830u;

    // 0x1c8830: 0x8042bf0  j           func_10AFC0
    ctx->pc = 0x1C8830u;
    ctx->pc = 0x1C8834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8830u;
            // 0x1c8834: 0x2484007c  addiu       $a0, $a0, 0x7C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 124));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C8838u;
    // 0x1c8838: 0x0  nop
    ctx->pc = 0x1c8838u;
    // NOP
    // 0x1c883c: 0x0  nop
    ctx->pc = 0x1c883cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
