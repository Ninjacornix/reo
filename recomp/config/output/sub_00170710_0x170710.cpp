#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170710
// Address: 0x170710 - 0x170738
void sub_00170710_0x170710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170710_0x170710");
#endif

    ctx->pc = 0x170710u;

    // 0x170710: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x170710u;
    {
        const bool branch_taken_0x170710 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x170714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170710u;
            // 0x170714: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170710) {
            ctx->pc = 0x170730u;
            goto label_170730;
        }
    }
    ctx->pc = 0x170718u;
    // 0x170718: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x170718u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17071c: 0x54620004  bnel        $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17071Cu;
    {
        const bool branch_taken_0x17071c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x17071c) {
            ctx->pc = 0x170720u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17071Cu;
            // 0x170720: 0xac800000  sw          $zero, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x170730u;
            goto label_170730;
        }
    }
    ctx->pc = 0x170724u;
    // 0x170724: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x170724u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x170728: 0x3e00008  jr          $ra
    ctx->pc = 0x170728u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17072Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170728u;
            // 0x17072c: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170730u: goto label_170730;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170730u;
label_170730:
    // 0x170730: 0x3e00008  jr          $ra
    ctx->pc = 0x170730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170730u: goto label_170730;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170738u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
