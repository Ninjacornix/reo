#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DFF8
// Address: 0x15dff8 - 0x15e020
void sub_0015DFF8_0x15dff8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DFF8_0x15dff8");
#endif

    ctx->pc = 0x15dff8u;

    // 0x15dff8: 0x248400b4  addiu       $a0, $a0, 0xB4
    ctx->pc = 0x15dff8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 180));
    // 0x15dffc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15dffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15e000: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x15e000u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15e004: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15e004u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e008: 0x14a20003  bne         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15E008u;
    {
        const bool branch_taken_0x15e008 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x15E00Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E008u;
            // 0x15e00c: 0x8c830004  lw          $v1, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e008) {
            ctx->pc = 0x15E018u;
            goto label_15e018;
        }
    }
    ctx->pc = 0x15E010u;
    // 0x15e010: 0x651026  xor         $v0, $v1, $a1
    ctx->pc = 0x15e010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 5));
    // 0x15e014: 0x2c460001  sltiu       $a2, $v0, 0x1
    ctx->pc = 0x15e014u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_15e018:
    // 0x15e018: 0x3e00008  jr          $ra
    ctx->pc = 0x15E018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E01Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E018u;
            // 0x15e01c: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E018u: goto label_15e018;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E020u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
