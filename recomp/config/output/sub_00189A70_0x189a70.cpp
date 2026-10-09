#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189A70
// Address: 0x189a70 - 0x189a88
void sub_00189A70_0x189a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189A70_0x189a70");
#endif

    ctx->pc = 0x189a70u;

    // 0x189a70: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x189a70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x189a74: 0x8ca60000  lw          $a2, 0x0($a1)
    ctx->pc = 0x189a74u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x189a78: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x189a78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x189a7c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x189a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x189a80: 0x3e00008  jr          $ra
    ctx->pc = 0x189A80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189A80u;
            // 0x189a84: 0xac66000c  sw          $a2, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x189A88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
