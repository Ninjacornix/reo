#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7C70
// Address: 0x1c7c70 - 0x1c7c90
void sub_001C7C70_0x1c7c70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7C70_0x1c7c70");
#endif

    ctx->pc = 0x1c7c70u;

    // 0x1c7c70: 0x8071f20  j           func_1C7C80
    ctx->pc = 0x1C7C70u;
    ctx->pc = 0x1C7C80u;
    goto label_1c7c80;
    ctx->pc = 0x1C7C78u;
    // 0x1c7c78: 0x0  nop
    ctx->pc = 0x1c7c78u;
    // NOP
    // 0x1c7c7c: 0x0  nop
    ctx->pc = 0x1c7c7cu;
    // NOP
label_1c7c80:
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
    // 0x1c7c88: 0x0  nop
    ctx->pc = 0x1c7c88u;
    // NOP
    // 0x1c7c8c: 0x0  nop
    ctx->pc = 0x1c7c8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
