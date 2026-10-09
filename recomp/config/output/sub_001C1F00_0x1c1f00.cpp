#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1F00
// Address: 0x1c1f00 - 0x1c1f18
void sub_001C1F00_0x1c1f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1F00_0x1c1f00");
#endif

    ctx->pc = 0x1c1f00u;

    // 0x1c1f00: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1f00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1f04: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1f04u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1f08: 0x24425470  addiu       $v0, $v0, 0x5470
    ctx->pc = 0x1c1f08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21616));
    // 0x1c1f0c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1f10: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1F10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1F10u;
            // 0x1c1f14: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C1F18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
