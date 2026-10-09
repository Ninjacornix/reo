#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1DC0
// Address: 0x1c1dc0 - 0x1c1dd8
void sub_001C1DC0_0x1c1dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1DC0_0x1c1dc0");
#endif

    ctx->pc = 0x1c1dc0u;

    // 0x1c1dc0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1dc4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1dc8: 0x24425380  addiu       $v0, $v0, 0x5380
    ctx->pc = 0x1c1dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21376));
    // 0x1c1dcc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1dccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1dd0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1DD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1DD0u;
            // 0x1c1dd4: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C1DD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
