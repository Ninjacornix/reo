#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B760
// Address: 0x15b760 - 0x15b7b0
void sub_0015B760_0x15b760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B760_0x15b760");
#endif

    switch (ctx->pc) {
        case 0x15b780u: goto label_15b780;
        default: break;
    }

    ctx->pc = 0x15b760u;

    // 0x15b760: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x15b760u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x15b764: 0x24424c70  addiu       $v0, $v0, 0x4C70
    ctx->pc = 0x15b764u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19568));
    // 0x15b768: 0x8c460054  lw          $a2, 0x54($v0)
    ctx->pc = 0x15b768u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 84)));
    // 0x15b76c: 0x18c0000d  blez        $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x15B76Cu;
    {
        const bool branch_taken_0x15b76c = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x15B770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B76Cu;
            // 0x15b770: 0x8c430058  lw          $v1, 0x58($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 88)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b76c) {
            ctx->pc = 0x15B7A4u;
            goto label_15b7a4;
        }
    }
    ctx->pc = 0x15B774u;
    // 0x15b774: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x15b774u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x15b778: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x15b778u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15b77c: 0x24440190  addiu       $a0, $v0, 0x190
    ctx->pc = 0x15b77cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 400));
label_15b780:
    // 0x15b780: 0x8c620188  lw          $v0, 0x188($v1)
    ctx->pc = 0x15b780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 392)));
    // 0x15b784: 0x14470003  bne         $v0, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x15B784u;
    {
        const bool branch_taken_0x15b784 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        ctx->pc = 0x15B788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B784u;
            // 0x15b788: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b784) {
            ctx->pc = 0x15B794u;
            goto label_15b794;
        }
    }
    ctx->pc = 0x15B78Cu;
    // 0x15b78c: 0x641021  addu        $v0, $v1, $a0
    ctx->pc = 0x15b78cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x15b790: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x15b790u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
label_15b794:
    // 0x15b794: 0x0  nop
    ctx->pc = 0x15b794u;
    // NOP
    // 0x15b798: 0x0  nop
    ctx->pc = 0x15b798u;
    // NOP
    // 0x15b79c: 0x14c0fff8  bnez        $a2, . + 4 + (-0x8 << 2)
    ctx->pc = 0x15B79Cu;
    {
        const bool branch_taken_0x15b79c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x15B7A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B79Cu;
            // 0x15b7a0: 0x246303e0  addiu       $v1, $v1, 0x3E0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 992));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b79c) {
            ctx->pc = 0x15B780u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15b780;
        }
    }
    ctx->pc = 0x15B7A4u;
label_15b7a4:
    // 0x15b7a4: 0x3e00008  jr          $ra
    ctx->pc = 0x15B7A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B780u: goto label_15b780;
            case 0x15B794u: goto label_15b794;
            case 0x15B7A4u: goto label_15b7a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B7ACu;
    // 0x15b7ac: 0x0  nop
    ctx->pc = 0x15b7acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
