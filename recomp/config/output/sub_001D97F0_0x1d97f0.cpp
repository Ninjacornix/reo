#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D97F0
// Address: 0x1d97f0 - 0x1d98a0
void sub_001D97F0_0x1d97f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D97F0_0x1d97f0");
#endif

    switch (ctx->pc) {
        case 0x1d9820u: goto label_1d9820;
        case 0x1d9830u: goto label_1d9830;
        case 0x1d9868u: goto label_1d9868;
        case 0x1d988cu: goto label_1d988c;
        default: break;
    }

    ctx->pc = 0x1d97f0u;

    // 0x1d97f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d97f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d97f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d97f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d97f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d97f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d97fc: 0x10a20006  beq         $a1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D97FCu;
    {
        const bool branch_taken_0x1d97fc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D97FCu;
            // 0x1d9800: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d97fc) {
            ctx->pc = 0x1D9818u;
            goto label_1d9818;
        }
    }
    ctx->pc = 0x1D9804u;
    // 0x1d9804: 0x24030016  addiu       $v1, $zero, 0x16
    ctx->pc = 0x1d9804u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1d9808: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9808u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d980c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d980cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9810: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1D9810u;
    {
        const bool branch_taken_0x1d9810 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9810u;
            // 0x1d9814: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9810) {
            ctx->pc = 0x1D9890u;
            goto label_1d9890;
        }
    }
    ctx->pc = 0x1D9818u;
label_1d9818:
    // 0x1d9818: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9818u;
    SET_GPR_U32(ctx, 31, 0x1D9820u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9820u; }
        if (ctx->pc != 0x1D9820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9820u; }
        if (ctx->pc != 0x1D9820u) { return; }
    }
    ctx->pc = 0x1D9820u;
label_1d9820:
    // 0x1d9820: 0x3c040035  lui         $a0, 0x35
    ctx->pc = 0x1d9820u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)53 << 16));
    // 0x1d9824: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d9824u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9828: 0x24848c90  addiu       $a0, $a0, -0x7370
    ctx->pc = 0x1d9828u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937744));
    // 0x1d982c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d982cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1d9830:
    // 0x1d9830: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1d9830u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d9834: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9834u;
    {
        const bool branch_taken_0x1d9834 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d9834) {
            ctx->pc = 0x1D9850u;
            goto label_1d9850;
        }
    }
    ctx->pc = 0x1D983Cu;
    // 0x1d983c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d983cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d9840: 0x2a020003  slti        $v0, $s0, 0x3
    ctx->pc = 0x1d9840u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d9844: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D9844u;
    {
        const bool branch_taken_0x1d9844 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9844u;
            // 0x1d9848: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9844) {
            ctx->pc = 0x1D9830u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9830;
        }
    }
    ctx->pc = 0x1D984Cu;
    // 0x1d984c: 0x0  nop
    ctx->pc = 0x1d984cu;
    // NOP
label_1d9850:
    // 0x1d9850: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1d9850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d9854: 0x16020006  bne         $s0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9854u;
    {
        const bool branch_taken_0x1d9854 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D9858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9854u;
            // 0x1d9858: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9854) {
            ctx->pc = 0x1D9870u;
            goto label_1d9870;
        }
    }
    ctx->pc = 0x1D985Cu;
    // 0x1d985c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d985cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9860: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9860u;
    SET_GPR_U32(ctx, 31, 0x1D9868u);
    ctx->pc = 0x1D9864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9860u;
            // 0x1d9864: 0xac228c88  sw          $v0, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9868u; }
        if (ctx->pc != 0x1D9868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9868u; }
        if (ctx->pc != 0x1D9868u) { return; }
    }
    ctx->pc = 0x1D9868u;
label_1d9868:
    // 0x1d9868: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D9868u;
    {
        const bool branch_taken_0x1d9868 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D986Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9868u;
            // 0x1d986c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9868) {
            ctx->pc = 0x1D9890u;
            goto label_1d9890;
        }
    }
    ctx->pc = 0x1D9870u;
label_1d9870:
    // 0x1d9870: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9870u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9874: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1d9874u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d9878: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9878u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d987c: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x1d987cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1d9880: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d9880u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d9884: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9884u;
    SET_GPR_U32(ctx, 31, 0x1D988Cu);
    ctx->pc = 0x1D9888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9884u;
            // 0x1d9888: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D988Cu; }
        if (ctx->pc != 0x1D988Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D988Cu; }
        if (ctx->pc != 0x1D988Cu) { return; }
    }
    ctx->pc = 0x1D988Cu;
label_1d988c:
    // 0x1d988c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d988cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1d9890:
    // 0x1d9890: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d9890u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9894: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9894u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9898: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D989Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9898u;
            // 0x1d989c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D98A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
