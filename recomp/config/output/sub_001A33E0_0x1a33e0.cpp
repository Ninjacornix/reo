#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A33E0
// Address: 0x1a33e0 - 0x1a3480
void sub_001A33E0_0x1a33e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A33E0_0x1a33e0");
#endif

    switch (ctx->pc) {
        case 0x1a33f8u: goto label_1a33f8;
        case 0x1a3408u: goto label_1a3408;
        case 0x1a3424u: goto label_1a3424;
        case 0x1a3458u: goto label_1a3458;
        default: break;
    }

    ctx->pc = 0x1a33e0u;

    // 0x1a33e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a33e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a33e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a33e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a33e8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a33e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a33ec: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a33ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a33f0: 0xc068d64  jal         func_1A3590
    ctx->pc = 0x1A33F0u;
    SET_GPR_U32(ctx, 31, 0x1A33F8u);
    ctx->pc = 0x1A33F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A33F0u;
            // 0x1a33f4: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3590u;
    if (runtime->hasFunction(0x1A3590u)) {
        auto targetFn = runtime->lookupFunction(0x1A3590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A33F8u; }
        if (ctx->pc != 0x1A33F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3590_0x1a3590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A33F8u; }
        if (ctx->pc != 0x1A33F8u) { return; }
    }
    ctx->pc = 0x1A33F8u;
label_1a33f8:
    // 0x1a33f8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1a33f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a33fc: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1a33fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1a3400: 0xc068d68  jal         func_1A35A0
    ctx->pc = 0x1A3400u;
    SET_GPR_U32(ctx, 31, 0x1A3408u);
    ctx->pc = 0x1A3404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3400u;
            // 0x1a3404: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35A0u;
    if (runtime->hasFunction(0x1A35A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3408u; }
        if (ctx->pc != 0x1A3408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35A0_0x1a35a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3408u; }
        if (ctx->pc != 0x1A3408u) { return; }
    }
    ctx->pc = 0x1A3408u;
label_1a3408:
    // 0x1a3408: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3408u;
    {
        const bool branch_taken_0x1a3408 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A340Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3408u;
            // 0x1a340c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3408) {
            ctx->pc = 0x1A3418u;
            goto label_1a3418;
        }
    }
    ctx->pc = 0x1A3410u;
    // 0x1a3410: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1A3410u;
    {
        const bool branch_taken_0x1a3410 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3410u;
            // 0x1a3414: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3410) {
            ctx->pc = 0x1A3468u;
            goto label_1a3468;
        }
    }
    ctx->pc = 0x1A3418u;
label_1a3418:
    // 0x1a3418: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1a3418u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1a341c: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A341Cu;
    SET_GPR_U32(ctx, 31, 0x1A3424u);
    ctx->pc = 0x1A3420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A341Cu;
            // 0x1a3420: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3424u; }
        if (ctx->pc != 0x1A3424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3424u; }
        if (ctx->pc != 0x1A3424u) { return; }
    }
    ctx->pc = 0x1A3424u;
label_1a3424:
    // 0x1a3424: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3424u;
    {
        const bool branch_taken_0x1a3424 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3424) {
            ctx->pc = 0x1A3434u;
            goto label_1a3434;
        }
    }
    ctx->pc = 0x1A342Cu;
    // 0x1a342c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1A342Cu;
    {
        const bool branch_taken_0x1a342c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A342Cu;
            // 0x1a3430: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a342c) {
            ctx->pc = 0x1A3468u;
            goto label_1a3468;
        }
    }
    ctx->pc = 0x1A3434u;
label_1a3434:
    // 0x1a3434: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1a3434u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a3438: 0x71082b  sltu        $at, $v1, $s1
    ctx->pc = 0x1a3438u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x1a343c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A343Cu;
    {
        const bool branch_taken_0x1a343c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A343Cu;
            // 0x1a3440: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a343c) {
            ctx->pc = 0x1A344Cu;
            goto label_1a344c;
        }
    }
    ctx->pc = 0x1A3444u;
    // 0x1a3444: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A3444u;
    {
        const bool branch_taken_0x1a3444 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3444u;
            // 0x1a3448: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3444) {
            ctx->pc = 0x1A3468u;
            goto label_1a3468;
        }
    }
    ctx->pc = 0x1A344Cu;
label_1a344c:
    // 0x1a344c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a344cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3450: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3450u;
    SET_GPR_U32(ctx, 31, 0x1A3458u);
    ctx->pc = 0x1A3454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3450u;
            // 0x1a3454: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3458u; }
        if (ctx->pc != 0x1A3458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3458u; }
        if (ctx->pc != 0x1A3458u) { return; }
    }
    ctx->pc = 0x1A3458u;
label_1a3458:
    // 0x1a3458: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3458u;
    {
        const bool branch_taken_0x1a3458 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3458) {
            ctx->pc = 0x1A3468u;
            goto label_1a3468;
        }
    }
    ctx->pc = 0x1A3460u;
    // 0x1a3460: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1A3460u;
    {
        const bool branch_taken_0x1a3460 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3460u;
            // 0x1a3464: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3460) {
            ctx->pc = 0x1A3468u;
            goto label_1a3468;
        }
    }
    ctx->pc = 0x1A3468u;
label_1a3468:
    // 0x1a3468: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a3468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a346c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a346cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a3470: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a3470u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3474: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3474u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3474u;
            // 0x1a3478: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A33F8u: goto label_1a33f8;
            case 0x1A3408u: goto label_1a3408;
            case 0x1A3418u: goto label_1a3418;
            case 0x1A3424u: goto label_1a3424;
            case 0x1A3434u: goto label_1a3434;
            case 0x1A344Cu: goto label_1a344c;
            case 0x1A3458u: goto label_1a3458;
            case 0x1A3468u: goto label_1a3468;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A347Cu;
    // 0x1a347c: 0x0  nop
    ctx->pc = 0x1a347cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
