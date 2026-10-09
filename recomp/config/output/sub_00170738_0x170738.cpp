#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170738
// Address: 0x170738 - 0x170760
void sub_00170738_0x170738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170738_0x170738");
#endif

    ctx->pc = 0x170738u;

    // 0x170738: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x170738u;
    {
        const bool branch_taken_0x170738 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x17073Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170738u;
            // 0x17073c: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170738) {
            ctx->pc = 0x170758u;
            goto label_170758;
        }
    }
    ctx->pc = 0x170740u;
    // 0x170740: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x170740u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x170744: 0x54620004  bnel        $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x170744u;
    {
        const bool branch_taken_0x170744 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x170744) {
            ctx->pc = 0x170748u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x170744u;
            // 0x170748: 0xac800000  sw          $zero, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x170758u;
            goto label_170758;
        }
    }
    ctx->pc = 0x17074Cu;
    // 0x17074c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x17074cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x170750: 0x3e00008  jr          $ra
    ctx->pc = 0x170750u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170750u;
            // 0x170754: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170758u: goto label_170758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170758u;
label_170758:
    // 0x170758: 0x3e00008  jr          $ra
    ctx->pc = 0x170758u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170758u: goto label_170758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170760u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
