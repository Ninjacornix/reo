#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AEB60
// Address: 0x1aeb60 - 0x1aebdc
void sub_001AEB60_0x1aeb60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AEB60_0x1aeb60");
#endif

    switch (ctx->pc) {
        case 0x1aeb84u: goto label_1aeb84;
        case 0x1aeb8cu: goto label_1aeb8c;
        case 0x1aeba8u: goto label_1aeba8;
        case 0x1aebb4u: goto label_1aebb4;
        case 0x1aebd0u: goto label_1aebd0;
        default: break;
    }

    ctx->pc = 0x1aeb60u;

    // 0x1aeb60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1aeb60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1aeb64: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1aeb64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1aeb68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1aeb68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1aeb6c: 0x8c238dc8  lw          $v1, -0x7238($at)
    ctx->pc = 0x1aeb6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938056)));
    // 0x1aeb70: 0x10600017  beqz        $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1AEB70u;
    {
        const bool branch_taken_0x1aeb70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AEB74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB70u;
            // 0x1aeb74: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aeb70) {
            ctx->pc = 0x1AEBD0u;
            goto label_1aebd0;
        }
    }
    ctx->pc = 0x1AEB78u;
    // 0x1aeb78: 0x8c258d78  lw          $a1, -0x7288($at)
    ctx->pc = 0x1aeb78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294937976)));
    // 0x1aeb7c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1AEB7Cu;
    SET_GPR_U32(ctx, 31, 0x1AEB84u);
    ctx->pc = 0x1AEB80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB7Cu;
            // 0x1aeb80: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB84u; }
        if (ctx->pc != 0x1AEB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB84u; }
        if (ctx->pc != 0x1AEB84u) { return; }
    }
    ctx->pc = 0x1AEB84u;
label_1aeb84:
    // 0x1aeb84: 0xc06b9b4  jal         func_1AE6D0
    ctx->pc = 0x1AEB84u;
    SET_GPR_U32(ctx, 31, 0x1AEB8Cu);
    ctx->pc = 0x1AEB88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB84u;
            // 0x1aeb88: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE6D0u;
    if (runtime->hasFunction(0x1AE6D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE6D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB8Cu; }
        if (ctx->pc != 0x1AEB8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE6D0_0x1ae6d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB8Cu; }
        if (ctx->pc != 0x1AEB8Cu) { return; }
    }
    ctx->pc = 0x1AEB8Cu;
label_1aeb8c:
    // 0x1aeb8c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1aeb8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1aeb90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1aeb90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aeb94: 0x8c248dc8  lw          $a0, -0x7238($at)
    ctx->pc = 0x1aeb94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938056)));
    // 0x1aeb98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1aeb98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aeb9c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1aeb9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1aeba0: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1AEBA0u;
    SET_GPR_U32(ctx, 31, 0x1AEBA8u);
    ctx->pc = 0x1AEBA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBA0u;
            // 0x1aeba4: 0xa0228d73  sb          $v0, -0x728D($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294937971), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBA8u; }
        if (ctx->pc != 0x1AEBA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBA8u; }
        if (ctx->pc != 0x1AEBA8u) { return; }
    }
    ctx->pc = 0x1AEBA8u;
label_1aeba8:
    // 0x1aeba8: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1aeba8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1aebac: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1AEBACu;
    SET_GPR_U32(ctx, 31, 0x1AEBB4u);
    ctx->pc = 0x1AEBB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBACu;
            // 0x1aebb0: 0x2484fe18  addiu       $a0, $a0, -0x1E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966808));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBB4u; }
        if (ctx->pc != 0x1AEBB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBB4u; }
        if (ctx->pc != 0x1AEBB4u) { return; }
    }
    ctx->pc = 0x1AEBB4u;
label_1aebb4:
    // 0x1aebb4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1aebb4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aebb8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1aebb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1aebbc: 0x10c30004  beq         $a2, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AEBBCu;
    {
        const bool branch_taken_0x1aebbc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AEBC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBBCu;
            // 0x1aebc0: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aebbc) {
            ctx->pc = 0x1AEBD0u;
            goto label_1aebd0;
        }
    }
    ctx->pc = 0x1AEBC4u;
    // 0x1aebc4: 0x8c248dc8  lw          $a0, -0x7238($at)
    ctx->pc = 0x1aebc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938056)));
    // 0x1aebc8: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1AEBC8u;
    SET_GPR_U32(ctx, 31, 0x1AEBD0u);
    ctx->pc = 0x1AEBCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBC8u;
            // 0x1aebcc: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBD0u; }
        if (ctx->pc != 0x1AEBD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBD0u; }
        if (ctx->pc != 0x1AEBD0u) { return; }
    }
    ctx->pc = 0x1AEBD0u;
label_1aebd0:
    // 0x1aebd0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1aebd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aebd4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEBD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEBD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBD4u;
            // 0x1aebd8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEBDCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
