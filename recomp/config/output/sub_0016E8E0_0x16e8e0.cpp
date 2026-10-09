#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E8E0
// Address: 0x16e8e0 - 0x16e930
void sub_0016E8E0_0x16e8e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E8E0_0x16e8e0");
#endif

    ctx->pc = 0x16e8e0u;

    // 0x16e8e0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x16e8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16e8e4: 0x10a2000e  beq         $a1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x16E8E4u;
    {
        const bool branch_taken_0x16e8e4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x16E8E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E8E4u;
            // 0x16e8e8: 0x248409a0  addiu       $a0, $a0, 0x9A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2464));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e8e4) {
            ctx->pc = 0x16E920u;
            goto label_16e920;
        }
    }
    ctx->pc = 0x16E8ECu;
    // 0x16e8ec: 0x2ca20003  sltiu       $v0, $a1, 0x3
    ctx->pc = 0x16e8ecu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x16e8f0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16E8F0u;
    {
        const bool branch_taken_0x16e8f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E8F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E8F0u;
            // 0x16e8f4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e8f0) {
            ctx->pc = 0x16E910u;
            goto label_16e910;
        }
    }
    ctx->pc = 0x16E8F8u;
    // 0x16e8f8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16e8f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16e8fc: 0x50a20009  beql        $a1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16E8FCu;
    {
        const bool branch_taken_0x16e8fc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x16e8fc) {
            ctx->pc = 0x16E900u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E8FCu;
            // 0x16e900: 0x8c820008  lw          $v0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E924u;
            goto label_16e924;
        }
    }
    ctx->pc = 0x16E904u;
    // 0x16e904: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x16E904u;
    {
        const bool branch_taken_0x16e904 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x16e904) {
            ctx->pc = 0x16E928u;
            goto label_16e928;
        }
    }
    ctx->pc = 0x16E90Cu;
    // 0x16e90c: 0x0  nop
    ctx->pc = 0x16e90cu;
    // NOP
label_16e910:
    // 0x16e910: 0x50a20004  beql        $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16E910u;
    {
        const bool branch_taken_0x16e910 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x16e910) {
            ctx->pc = 0x16E914u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E910u;
            // 0x16e914: 0x8c820010  lw          $v0, 0x10($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E924u;
            goto label_16e924;
        }
    }
    ctx->pc = 0x16E918u;
    // 0x16e918: 0x3e00008  jr          $ra
    ctx->pc = 0x16E918u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E918u;
            // 0x16e91c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E910u: goto label_16e910;
            case 0x16E920u: goto label_16e920;
            case 0x16E924u: goto label_16e924;
            case 0x16E928u: goto label_16e928;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E920u;
label_16e920:
    // 0x16e920: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x16e920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
label_16e924:
    // 0x16e924: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x16e924u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_16e928:
    // 0x16e928: 0x3e00008  jr          $ra
    ctx->pc = 0x16E928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E910u: goto label_16e910;
            case 0x16E920u: goto label_16e920;
            case 0x16E924u: goto label_16e924;
            case 0x16E928u: goto label_16e928;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
