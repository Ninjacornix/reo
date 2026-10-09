#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3310
// Address: 0x1a3310 - 0x1a33b0
void sub_001A3310_0x1a3310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3310_0x1a3310");
#endif

    switch (ctx->pc) {
        case 0x1a3328u: goto label_1a3328;
        case 0x1a3338u: goto label_1a3338;
        case 0x1a3354u: goto label_1a3354;
        case 0x1a3388u: goto label_1a3388;
        default: break;
    }

    ctx->pc = 0x1a3310u;

    // 0x1a3310: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a3310u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a3314: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a3314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a3318: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a3318u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a331c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a331cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3320: 0xc068d64  jal         func_1A3590
    ctx->pc = 0x1A3320u;
    SET_GPR_U32(ctx, 31, 0x1A3328u);
    ctx->pc = 0x1A3324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3320u;
            // 0x1a3324: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3590u;
    if (runtime->hasFunction(0x1A3590u)) {
        auto targetFn = runtime->lookupFunction(0x1A3590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3328u; }
        if (ctx->pc != 0x1A3328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3590_0x1a3590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3328u; }
        if (ctx->pc != 0x1A3328u) { return; }
    }
    ctx->pc = 0x1A3328u;
label_1a3328:
    // 0x1a3328: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1a3328u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a332c: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x1a332cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1a3330: 0xc068d68  jal         func_1A35A0
    ctx->pc = 0x1A3330u;
    SET_GPR_U32(ctx, 31, 0x1A3338u);
    ctx->pc = 0x1A3334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3330u;
            // 0x1a3334: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35A0u;
    if (runtime->hasFunction(0x1A35A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3338u; }
        if (ctx->pc != 0x1A3338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35A0_0x1a35a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3338u; }
        if (ctx->pc != 0x1A3338u) { return; }
    }
    ctx->pc = 0x1A3338u;
label_1a3338:
    // 0x1a3338: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3338u;
    {
        const bool branch_taken_0x1a3338 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A333Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3338u;
            // 0x1a333c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3338) {
            ctx->pc = 0x1A3348u;
            goto label_1a3348;
        }
    }
    ctx->pc = 0x1A3340u;
    // 0x1a3340: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1A3340u;
    {
        const bool branch_taken_0x1a3340 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3340u;
            // 0x1a3344: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3340) {
            ctx->pc = 0x1A3398u;
            goto label_1a3398;
        }
    }
    ctx->pc = 0x1A3348u;
label_1a3348:
    // 0x1a3348: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x1a3348u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1a334c: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A334Cu;
    SET_GPR_U32(ctx, 31, 0x1A3354u);
    ctx->pc = 0x1A3350u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A334Cu;
            // 0x1a3350: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3354u; }
        if (ctx->pc != 0x1A3354u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3354u; }
        if (ctx->pc != 0x1A3354u) { return; }
    }
    ctx->pc = 0x1A3354u;
label_1a3354:
    // 0x1a3354: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3354u;
    {
        const bool branch_taken_0x1a3354 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3354) {
            ctx->pc = 0x1A3364u;
            goto label_1a3364;
        }
    }
    ctx->pc = 0x1A335Cu;
    // 0x1a335c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1A335Cu;
    {
        const bool branch_taken_0x1a335c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A335Cu;
            // 0x1a3360: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a335c) {
            ctx->pc = 0x1A3398u;
            goto label_1a3398;
        }
    }
    ctx->pc = 0x1A3364u;
label_1a3364:
    // 0x1a3364: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1a3364u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a3368: 0x71082b  sltu        $at, $v1, $s1
    ctx->pc = 0x1a3368u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x1a336c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A336Cu;
    {
        const bool branch_taken_0x1a336c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3370u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A336Cu;
            // 0x1a3370: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a336c) {
            ctx->pc = 0x1A337Cu;
            goto label_1a337c;
        }
    }
    ctx->pc = 0x1A3374u;
    // 0x1a3374: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A3374u;
    {
        const bool branch_taken_0x1a3374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3374u;
            // 0x1a3378: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3374) {
            ctx->pc = 0x1A3398u;
            goto label_1a3398;
        }
    }
    ctx->pc = 0x1A337Cu;
label_1a337c:
    // 0x1a337c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a337cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3380: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3380u;
    SET_GPR_U32(ctx, 31, 0x1A3388u);
    ctx->pc = 0x1A3384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3380u;
            // 0x1a3384: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3388u; }
        if (ctx->pc != 0x1A3388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3388u; }
        if (ctx->pc != 0x1A3388u) { return; }
    }
    ctx->pc = 0x1A3388u;
label_1a3388:
    // 0x1a3388: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3388u;
    {
        const bool branch_taken_0x1a3388 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3388) {
            ctx->pc = 0x1A3398u;
            goto label_1a3398;
        }
    }
    ctx->pc = 0x1A3390u;
    // 0x1a3390: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1A3390u;
    {
        const bool branch_taken_0x1a3390 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3390u;
            // 0x1a3394: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3390) {
            ctx->pc = 0x1A3398u;
            goto label_1a3398;
        }
    }
    ctx->pc = 0x1A3398u;
label_1a3398:
    // 0x1a3398: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a3398u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a339c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a339cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a33a0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a33a0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a33a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A33A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A33A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A33A4u;
            // 0x1a33a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3328u: goto label_1a3328;
            case 0x1A3338u: goto label_1a3338;
            case 0x1A3348u: goto label_1a3348;
            case 0x1A3354u: goto label_1a3354;
            case 0x1A3364u: goto label_1a3364;
            case 0x1A337Cu: goto label_1a337c;
            case 0x1A3388u: goto label_1a3388;
            case 0x1A3398u: goto label_1a3398;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A33ACu;
    // 0x1a33ac: 0x0  nop
    ctx->pc = 0x1a33acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
