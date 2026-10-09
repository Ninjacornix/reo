#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160818
// Address: 0x160818 - 0x1608b0
void sub_00160818_0x160818(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160818_0x160818");
#endif

    switch (ctx->pc) {
        case 0x160834u: goto label_160834;
        case 0x160848u: goto label_160848;
        case 0x160858u: goto label_160858;
        case 0x160864u: goto label_160864;
        case 0x16086cu: goto label_16086c;
        case 0x160878u: goto label_160878;
        case 0x160884u: goto label_160884;
        case 0x160890u: goto label_160890;
        default: break;
    }

    ctx->pc = 0x160818u;

    // 0x160818: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x160818u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x16081c: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x16081cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x160820: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x160820u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160824: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x160824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x160828: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x160828u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x16082c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16082Cu;
    SET_GPR_U32(ctx, 31, 0x160834u);
    ctx->pc = 0x160830u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16082Cu;
            // 0x160830: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160834u; }
        if (ctx->pc != 0x160834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160834u; }
        if (ctx->pc != 0x160834u) { return; }
    }
    ctx->pc = 0x160834u;
label_160834:
    // 0x160834: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x160834u;
    {
        const bool branch_taken_0x160834 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160834u;
            // 0x160838: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160834) {
            ctx->pc = 0x160850u;
            goto label_160850;
        }
    }
    ctx->pc = 0x16083Cu;
    // 0x16083c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16083cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160840: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160840u;
    SET_GPR_U32(ctx, 31, 0x160848u);
    ctx->pc = 0x160844u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160840u;
            // 0x160844: 0x2484f818  addiu       $a0, $a0, -0x7E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160848u; }
        if (ctx->pc != 0x160848u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160848u; }
        if (ctx->pc != 0x160848u) { return; }
    }
    ctx->pc = 0x160848u;
label_160848:
    // 0x160848: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x160848u;
    {
        const bool branch_taken_0x160848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16084Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160848u;
            // 0x16084c: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160848) {
            ctx->pc = 0x1608A0u;
            goto label_1608a0;
        }
    }
    ctx->pc = 0x160850u;
label_160850:
    // 0x160850: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x160850u;
    SET_GPR_U32(ctx, 31, 0x160858u);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160858u; }
        if (ctx->pc != 0x160858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160858u; }
        if (ctx->pc != 0x160858u) { return; }
    }
    ctx->pc = 0x160858u;
label_160858:
    // 0x160858: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x160858u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16085c: 0xc05d5c4  jal         func_175710
    ctx->pc = 0x16085Cu;
    SET_GPR_U32(ctx, 31, 0x160864u);
    ctx->pc = 0x160860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16085Cu;
            // 0x160860: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175710u;
    if (runtime->hasFunction(0x175710u)) {
        auto targetFn = runtime->lookupFunction(0x175710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160864u; }
        if (ctx->pc != 0x160864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175710_0x175710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160864u; }
        if (ctx->pc != 0x160864u) { return; }
    }
    ctx->pc = 0x160864u;
label_160864:
    // 0x160864: 0xc057eec  jal         func_15FBB0
    ctx->pc = 0x160864u;
    SET_GPR_U32(ctx, 31, 0x16086Cu);
    ctx->pc = 0x160868u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160864u;
            // 0x160868: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FBB0u;
    if (runtime->hasFunction(0x15FBB0u)) {
        auto targetFn = runtime->lookupFunction(0x15FBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16086Cu; }
        if (ctx->pc != 0x16086Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FBB0_0x15fbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16086Cu; }
        if (ctx->pc != 0x16086Cu) { return; }
    }
    ctx->pc = 0x16086Cu;
label_16086c:
    // 0x16086c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16086cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160870: 0xc057f06  jal         func_15FC18
    ctx->pc = 0x160870u;
    SET_GPR_U32(ctx, 31, 0x160878u);
    ctx->pc = 0x160874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160870u;
            // 0x160874: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FC18u;
    if (runtime->hasFunction(0x15FC18u)) {
        auto targetFn = runtime->lookupFunction(0x15FC18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160878u; }
        if (ctx->pc != 0x160878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FC18_0x15fc18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160878u; }
        if (ctx->pc != 0x160878u) { return; }
    }
    ctx->pc = 0x160878u;
label_160878:
    // 0x160878: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x160878u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16087c: 0xc05791e  jal         func_15E478
    ctx->pc = 0x16087Cu;
    SET_GPR_U32(ctx, 31, 0x160884u);
    ctx->pc = 0x160880u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16087Cu;
            // 0x160880: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E478u;
    if (runtime->hasFunction(0x15E478u)) {
        auto targetFn = runtime->lookupFunction(0x15E478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160884u; }
        if (ctx->pc != 0x160884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E478_0x15e478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160884u; }
        if (ctx->pc != 0x160884u) { return; }
    }
    ctx->pc = 0x160884u;
label_160884:
    // 0x160884: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x160884u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160888: 0xc0581c4  jal         func_160710
    ctx->pc = 0x160888u;
    SET_GPR_U32(ctx, 31, 0x160890u);
    ctx->pc = 0x16088Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160888u;
            // 0x16088c: 0xae220008  sw          $v0, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160710u;
    if (runtime->hasFunction(0x160710u)) {
        auto targetFn = runtime->lookupFunction(0x160710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160890u; }
        if (ctx->pc != 0x160890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160710_0x160710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160890u; }
        if (ctx->pc != 0x160890u) { return; }
    }
    ctx->pc = 0x160890u;
label_160890:
    // 0x160890: 0x8fa3001c  lw          $v1, 0x1C($sp)
    ctx->pc = 0x160890u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x160894: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x160894u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x160898: 0xae230010  sw          $v1, 0x10($s1)
    ctx->pc = 0x160898u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
    // 0x16089c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x16089cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1608a0:
    // 0x1608a0: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x1608a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1608a4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1608a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1608a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1608A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1608ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1608A8u;
            // 0x1608ac: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160834u: goto label_160834;
            case 0x160848u: goto label_160848;
            case 0x160850u: goto label_160850;
            case 0x160858u: goto label_160858;
            case 0x160864u: goto label_160864;
            case 0x16086Cu: goto label_16086c;
            case 0x160878u: goto label_160878;
            case 0x160884u: goto label_160884;
            case 0x160890u: goto label_160890;
            case 0x1608A0u: goto label_1608a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1608B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
