#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C72E0
// Address: 0x1c72e0 - 0x1c72f0
void sub_001C72E0_0x1c72e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C72E0_0x1c72e0");
#endif

    ctx->pc = 0x1c72e0u;

    // 0x1c72e0: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c72e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c72e4: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1c72e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c72e8: 0x8071f60  j           func_1C7D80
    ctx->pc = 0x1C72E8u;
    ctx->pc = 0x1C72ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C72E8u;
            // 0x1c72ec: 0x24842f90  addiu       $a0, $a0, 0x2F90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D80u;
    if (runtime->hasFunction(0x1C7D80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C7D80_0x1c7d80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C72F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
