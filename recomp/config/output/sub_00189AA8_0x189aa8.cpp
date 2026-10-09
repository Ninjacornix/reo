#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189AA8
// Address: 0x189aa8 - 0x189ae0
void sub_00189AA8_0x189aa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189AA8_0x189aa8");
#endif

    ctx->pc = 0x189aa8u;

label_189aa8:
    // 0x189aa8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x189aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189aac: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x189aacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x189ab0: 0x8c880008  lw          $t0, 0x8($a0)
    ctx->pc = 0x189ab0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x189ab4: 0x8c89000c  lw          $t1, 0xC($a0)
    ctx->pc = 0x189ab4u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x189ab8: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x189ab8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x189abc: 0xaca30004  sw          $v1, 0x4($a1)
    ctx->pc = 0x189abcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x189ac0: 0xaca80008  sw          $t0, 0x8($a1)
    ctx->pc = 0x189ac0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 8));
    // 0x189ac4: 0xaca9000c  sw          $t1, 0xC($a1)
    ctx->pc = 0x189ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 9));
    // 0x189ac8: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189ac8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189acc: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x189accu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x189ad0: 0x14c0fff5  bnez        $a2, . + 4 + (-0xB << 2)
    ctx->pc = 0x189AD0u;
    {
        const bool branch_taken_0x189ad0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189AD0u;
            // 0x189ad4: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189ad0) {
            ctx->pc = 0x189AA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189aa8;
        }
    }
    ctx->pc = 0x189AD8u;
    // 0x189ad8: 0x3e00008  jr          $ra
    ctx->pc = 0x189AD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189AA8u: goto label_189aa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189AE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
