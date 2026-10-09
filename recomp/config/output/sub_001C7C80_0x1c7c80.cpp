#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7C80
// Address: 0x1c7c80 - 0x1c7c88
void sub_001C7C80_0x1c7c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7C80_0x1c7c80");
#endif

    ctx->pc = 0x1c7c80u;

    // 0x1c7c80: 0x8041eac  j           func_107AB0
    ctx->pc = 0x1C7C80u;
    ctx->pc = 0x1C7C84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7C80u;
            // 0x1c7c84: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C7C88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
