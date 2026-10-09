#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1DE0
// Address: 0x1c1de0 - 0x1c1df8
void sub_001C1DE0_0x1c1de0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1DE0_0x1c1de0");
#endif

    ctx->pc = 0x1c1de0u;

    // 0x1c1de0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1de0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1de4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1de4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1de8: 0x244253f0  addiu       $v0, $v0, 0x53F0
    ctx->pc = 0x1c1de8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21488));
    // 0x1c1dec: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1decu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1df0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1DF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1DF0u;
            // 0x1c1df4: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C1DF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
