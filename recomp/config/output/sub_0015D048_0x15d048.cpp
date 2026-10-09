#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D048
// Address: 0x15d048 - 0x15d0a0
void sub_0015D048_0x15d048(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D048_0x15d048");
#endif

    switch (ctx->pc) {
        case 0x15d078u: goto label_15d078;
        default: break;
    }

    ctx->pc = 0x15d048u;

    // 0x15d048: 0x8ca30018  lw          $v1, 0x18($a1)
    ctx->pc = 0x15d048u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x15d04c: 0x24820158  addiu       $v0, $a0, 0x158
    ctx->pc = 0x15d04cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 344));
    // 0x15d050: 0x8ca6001c  lw          $a2, 0x1C($a1)
    ctx->pc = 0x15d050u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x15d054: 0x248701e8  addiu       $a3, $a0, 0x1E8
    ctx->pc = 0x15d054u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 488));
    // 0x15d058: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x15d058u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x15d05c: 0x2408001f  addiu       $t0, $zero, 0x1F
    ctx->pc = 0x15d05cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x15d060: 0xac460004  sw          $a2, 0x4($v0)
    ctx->pc = 0x15d060u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 6));
    // 0x15d064: 0x8ca30018  lw          $v1, 0x18($a1)
    ctx->pc = 0x15d064u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x15d068: 0xac40000c  sw          $zero, 0xC($v0)
    ctx->pc = 0x15d068u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 0));
    // 0x15d06c: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x15d06cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x15d070: 0xac800168  sw          $zero, 0x168($a0)
    ctx->pc = 0x15d070u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 360), GPR_U32(ctx, 0));
    // 0x15d074: 0x0  nop
    ctx->pc = 0x15d074u;
    // NOP
label_15d078:
    // 0x15d078: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x15d078u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x15d07c: 0xace00000  sw          $zero, 0x0($a3)
    ctx->pc = 0x15d07cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 0));
    // 0x15d080: 0x0  nop
    ctx->pc = 0x15d080u;
    // NOP
    // 0x15d084: 0x0  nop
    ctx->pc = 0x15d084u;
    // NOP
    // 0x15d088: 0x0  nop
    ctx->pc = 0x15d088u;
    // NOP
    // 0x15d08c: 0x501fffa  bgez        $t0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x15D08Cu;
    {
        const bool branch_taken_0x15d08c = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x15D090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D08Cu;
            // 0x15d090: 0x24e7fffc  addiu       $a3, $a3, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d08c) {
            ctx->pc = 0x15D078u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15d078;
        }
    }
    ctx->pc = 0x15D094u;
    // 0x15d094: 0x3e00008  jr          $ra
    ctx->pc = 0x15D094u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D078u: goto label_15d078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D09Cu;
    // 0x15d09c: 0x0  nop
    ctx->pc = 0x15d09cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
