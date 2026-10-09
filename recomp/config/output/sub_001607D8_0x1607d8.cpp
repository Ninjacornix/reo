#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001607D8
// Address: 0x1607d8 - 0x160b00
void sub_001607D8_0x1607d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001607D8_0x1607d8");
#endif

    switch (ctx->pc) {
        case 0x1607ecu: goto label_1607ec;
        case 0x160800u: goto label_160800;
        case 0x160834u: goto label_160834;
        case 0x160848u: goto label_160848;
        case 0x160858u: goto label_160858;
        case 0x160864u: goto label_160864;
        case 0x16086cu: goto label_16086c;
        case 0x160878u: goto label_160878;
        case 0x160884u: goto label_160884;
        case 0x160890u: goto label_160890;
        case 0x160928u: goto label_160928;
        case 0x1609bcu: goto label_1609bc;
        case 0x1609e8u: goto label_1609e8;
        case 0x160a2cu: goto label_160a2c;
        case 0x160a60u: goto label_160a60;
        case 0x160a74u: goto label_160a74;
        case 0x160a84u: goto label_160a84;
        case 0x160a90u: goto label_160a90;
        case 0x160a9cu: goto label_160a9c;
        case 0x160aa8u: goto label_160aa8;
        default: break;
    }

    ctx->pc = 0x1607d8u;

    // 0x1607d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1607d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1607dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1607dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1607e0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1607e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1607e4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1607E4u;
    SET_GPR_U32(ctx, 31, 0x1607ECu);
    ctx->pc = 0x1607E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1607E4u;
            // 0x1607e8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1607ECu; }
        if (ctx->pc != 0x1607ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1607ECu; }
        if (ctx->pc != 0x1607ECu) { return; }
    }
    ctx->pc = 0x1607ECu;
label_1607ec:
    // 0x1607ec: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1607ECu;
    {
        const bool branch_taken_0x1607ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1607ec) {
            ctx->pc = 0x1607F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1607ECu;
            // 0x1607f0: 0x8e02012c  lw          $v0, 0x12C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x160804u;
            goto label_160804;
        }
    }
    ctx->pc = 0x1607F4u;
    // 0x1607f4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1607f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1607f8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1607F8u;
    SET_GPR_U32(ctx, 31, 0x160800u);
    ctx->pc = 0x1607FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1607F8u;
            // 0x1607fc: 0x2484f7e8  addiu       $a0, $a0, -0x818 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965224));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160800u; }
        if (ctx->pc != 0x160800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160800u; }
        if (ctx->pc != 0x160800u) { return; }
    }
    ctx->pc = 0x160800u;
label_160800:
    // 0x160800: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x160800u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_160804:
    // 0x160804: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160804u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160808: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x160808u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16080c: 0x3e00008  jr          $ra
    ctx->pc = 0x16080Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16080Cu;
            // 0x160810: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1607ECu: goto label_1607ec;
            case 0x160800u: goto label_160800;
            case 0x160804u: goto label_160804;
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
            case 0x160928u: goto label_160928;
            case 0x16092Cu: goto label_16092c;
            case 0x160978u: goto label_160978;
            case 0x160980u: goto label_160980;
            case 0x160990u: goto label_160990;
            case 0x1609BCu: goto label_1609bc;
            case 0x1609E0u: goto label_1609e0;
            case 0x1609E8u: goto label_1609e8;
            case 0x160A2Cu: goto label_160a2c;
            case 0x160A58u: goto label_160a58;
            case 0x160A60u: goto label_160a60;
            case 0x160A74u: goto label_160a74;
            case 0x160A84u: goto label_160a84;
            case 0x160A90u: goto label_160a90;
            case 0x160A9Cu: goto label_160a9c;
            case 0x160AA8u: goto label_160aa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160814u;
    // 0x160814: 0x0  nop
    ctx->pc = 0x160814u;
    // NOP
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
            case 0x1607ECu: goto label_1607ec;
            case 0x160800u: goto label_160800;
            case 0x160804u: goto label_160804;
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
            case 0x160928u: goto label_160928;
            case 0x16092Cu: goto label_16092c;
            case 0x160978u: goto label_160978;
            case 0x160980u: goto label_160980;
            case 0x160990u: goto label_160990;
            case 0x1609BCu: goto label_1609bc;
            case 0x1609E0u: goto label_1609e0;
            case 0x1609E8u: goto label_1609e8;
            case 0x160A2Cu: goto label_160a2c;
            case 0x160A58u: goto label_160a58;
            case 0x160A60u: goto label_160a60;
            case 0x160A74u: goto label_160a74;
            case 0x160A84u: goto label_160a84;
            case 0x160A90u: goto label_160a90;
            case 0x160A9Cu: goto label_160a9c;
            case 0x160AA8u: goto label_160aa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1608B0u;
    // 0x1608b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1608b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1608b4: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1608b4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1608b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1608b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1608bc: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x1608bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1608c0: 0x8c670134  lw          $a3, 0x134($v1)
    ctx->pc = 0x1608c0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 308)));
    // 0x1608c4: 0x24453fff  addiu       $a1, $v0, 0x3FFF
    ctx->pc = 0x1608c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 16383));
    // 0x1608c8: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x1608c8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1608cc: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x1608ccu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x1608d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1608d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1608d4: 0x21383  sra         $v0, $v0, 14
    ctx->pc = 0x1608d4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 14));
    // 0x1608d8: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x1608d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1608dc: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x1608dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x1608e0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1608e0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1608e4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1608e4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1608e8: 0x460c0002  mul.s       $f0, $f0, $f12
    ctx->pc = 0x1608e8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[12]);
    // 0x1608ec: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1608ecu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1608f0: 0x44050800  mfc1        $a1, $f1
    ctx->pc = 0x1608f0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1608f4: 0xe5102a  slt         $v0, $a3, $a1
    ctx->pc = 0x1608f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1608f8: 0xe2280b  movn        $a1, $a3, $v0
    ctx->pc = 0x1608f8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x1608fc: 0x8057fc6  j           func_15FF18
    ctx->pc = 0x1608FCu;
    ctx->pc = 0x160900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1608FCu;
            // 0x160900: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FF18u;
    if (runtime->hasFunction(0x15FF18u)) {
        auto targetFn = runtime->lookupFunction(0x15FF18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015FF18_0x15ff18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160904u;
    // 0x160904: 0x0  nop
    ctx->pc = 0x160904u;
    // NOP
    // 0x160908: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x160908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16090c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16090cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160910: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x160910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x160914: 0x8c830044  lw          $v1, 0x44($a0)
    ctx->pc = 0x160914u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x160918: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x160918u;
    {
        const bool branch_taken_0x160918 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16091Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160918u;
            // 0x16091c: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160918) {
            ctx->pc = 0x16092Cu;
            goto label_16092c;
        }
    }
    ctx->pc = 0x160920u;
    // 0x160920: 0xc059160  jal         func_164580
    ctx->pc = 0x160920u;
    SET_GPR_U32(ctx, 31, 0x160928u);
    ctx->pc = 0x160924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160920u;
            // 0x160924: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164580u;
    if (runtime->hasFunction(0x164580u)) {
        auto targetFn = runtime->lookupFunction(0x164580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160928u; }
        if (ctx->pc != 0x160928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164580_0x164580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160928u; }
        if (ctx->pc != 0x160928u) { return; }
    }
    ctx->pc = 0x160928u;
label_160928:
    // 0x160928: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x160928u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_16092c:
    // 0x16092c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16092cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160930: 0x3e00008  jr          $ra
    ctx->pc = 0x160930u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160930u;
            // 0x160934: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1607ECu: goto label_1607ec;
            case 0x160800u: goto label_160800;
            case 0x160804u: goto label_160804;
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
            case 0x160928u: goto label_160928;
            case 0x16092Cu: goto label_16092c;
            case 0x160978u: goto label_160978;
            case 0x160980u: goto label_160980;
            case 0x160990u: goto label_160990;
            case 0x1609BCu: goto label_1609bc;
            case 0x1609E0u: goto label_1609e0;
            case 0x1609E8u: goto label_1609e8;
            case 0x160A2Cu: goto label_160a2c;
            case 0x160A58u: goto label_160a58;
            case 0x160A60u: goto label_160a60;
            case 0x160A74u: goto label_160a74;
            case 0x160A84u: goto label_160a84;
            case 0x160A90u: goto label_160a90;
            case 0x160A9Cu: goto label_160a9c;
            case 0x160AA8u: goto label_160aa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160938u;
    // 0x160938: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160938u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16093c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16093cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160940: 0x10800013  beqz        $a0, . + 4 + (0x13 << 2)
    ctx->pc = 0x160940u;
    {
        const bool branch_taken_0x160940 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x160944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160940u;
            // 0x160944: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160940) {
            ctx->pc = 0x160990u;
            goto label_160990;
        }
    }
    ctx->pc = 0x160948u;
    // 0x160948: 0x8c820044  lw          $v0, 0x44($a0)
    ctx->pc = 0x160948u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x16094c: 0x8c83004c  lw          $v1, 0x4C($a0)
    ctx->pc = 0x16094cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x160950: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x160950u;
    {
        const bool branch_taken_0x160950 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160950u;
            // 0x160954: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160950) {
            ctx->pc = 0x160980u;
            goto label_160980;
        }
    }
    ctx->pc = 0x160958u;
    // 0x160958: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x160958u;
    {
        const bool branch_taken_0x160958 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16095Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160958u;
            // 0x16095c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160958) {
            ctx->pc = 0x160990u;
            goto label_160990;
        }
    }
    ctx->pc = 0x160960u;
    // 0x160960: 0x8c620028  lw          $v0, 0x28($v1)
    ctx->pc = 0x160960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x160964: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x160964u;
    {
        const bool branch_taken_0x160964 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x160968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160964u;
            // 0x160968: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160964) {
            ctx->pc = 0x160978u;
            goto label_160978;
        }
    }
    ctx->pc = 0x16096Cu;
    // 0x16096c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16096cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160970: 0x805916a  j           func_1645A8
    ctx->pc = 0x160970u;
    ctx->pc = 0x160974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160970u;
            // 0x160974: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1645A8u;
    if (runtime->hasFunction(0x1645A8u)) {
        auto targetFn = runtime->lookupFunction(0x1645A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001645A8_0x1645a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160978u;
label_160978:
    // 0x160978: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x160978u;
    {
        const bool branch_taken_0x160978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16097Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160978u;
            // 0x16097c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160978) {
            ctx->pc = 0x160990u;
            goto label_160990;
        }
    }
    ctx->pc = 0x160980u;
label_160980:
    // 0x160980: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160980u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160984: 0x805916a  j           func_1645A8
    ctx->pc = 0x160984u;
    ctx->pc = 0x160988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160984u;
            // 0x160988: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1645A8u;
    if (runtime->hasFunction(0x1645A8u)) {
        auto targetFn = runtime->lookupFunction(0x1645A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001645A8_0x1645a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16098Cu;
    // 0x16098c: 0x0  nop
    ctx->pc = 0x16098cu;
    // NOP
label_160990:
    // 0x160990: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160990u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160994: 0x3e00008  jr          $ra
    ctx->pc = 0x160994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160994u;
            // 0x160998: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1607ECu: goto label_1607ec;
            case 0x160800u: goto label_160800;
            case 0x160804u: goto label_160804;
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
            case 0x160928u: goto label_160928;
            case 0x16092Cu: goto label_16092c;
            case 0x160978u: goto label_160978;
            case 0x160980u: goto label_160980;
            case 0x160990u: goto label_160990;
            case 0x1609BCu: goto label_1609bc;
            case 0x1609E0u: goto label_1609e0;
            case 0x1609E8u: goto label_1609e8;
            case 0x160A2Cu: goto label_160a2c;
            case 0x160A58u: goto label_160a58;
            case 0x160A60u: goto label_160a60;
            case 0x160A74u: goto label_160a74;
            case 0x160A84u: goto label_160a84;
            case 0x160A90u: goto label_160a90;
            case 0x160A9Cu: goto label_160a9c;
            case 0x160AA8u: goto label_160aa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16099Cu;
    // 0x16099c: 0x0  nop
    ctx->pc = 0x16099cu;
    // NOP
    // 0x1609a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1609a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1609a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1609a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1609a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1609a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1609ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1609acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1609b0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1609b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1609b4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1609B4u;
    SET_GPR_U32(ctx, 31, 0x1609BCu);
    ctx->pc = 0x1609B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1609B4u;
            // 0x1609b8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1609BCu; }
        if (ctx->pc != 0x1609BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1609BCu; }
        if (ctx->pc != 0x1609BCu) { return; }
    }
    ctx->pc = 0x1609BCu;
label_1609bc:
    // 0x1609bc: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1609BCu;
    {
        const bool branch_taken_0x1609bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1609C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1609BCu;
            // 0x1609c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1609bc) {
            ctx->pc = 0x1609E0u;
            goto label_1609e0;
        }
    }
    ctx->pc = 0x1609C4u;
    // 0x1609c4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1609c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1609c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1609c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1609cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1609ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1609d0: 0x2484f848  addiu       $a0, $a0, -0x7B8
    ctx->pc = 0x1609d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965320));
    // 0x1609d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1609d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1609d8: 0x8058dd4  j           func_163750
    ctx->pc = 0x1609D8u;
    ctx->pc = 0x1609DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1609D8u;
            // 0x1609dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1609E0u;
label_1609e0:
    // 0x1609e0: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x1609E0u;
    SET_GPR_U32(ctx, 31, 0x1609E8u);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1609E8u; }
        if (ctx->pc != 0x1609E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1609E8u; }
        if (ctx->pc != 0x1609E8u) { return; }
    }
    ctx->pc = 0x1609E8u;
label_1609e8:
    // 0x1609e8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1609e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1609ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1609ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1609f0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1609f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1609f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1609f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1609f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1609f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1609fc: 0x805c8b4  j           func_1722D0
    ctx->pc = 0x1609FCu;
    ctx->pc = 0x160A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1609FCu;
            // 0x160a00: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1722D0u;
    if (runtime->hasFunction(0x1722D0u)) {
        auto targetFn = runtime->lookupFunction(0x1722D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001722D0_0x1722d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160A04u;
    // 0x160a04: 0x0  nop
    ctx->pc = 0x160a04u;
    // NOP
    // 0x160a08: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x160a08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x160a0c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160a0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160a10: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x160a10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160a14: 0xe7b40020  swc1        $f20, 0x20($sp)
    ctx->pc = 0x160a14u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x160a18: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x160a18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x160a1c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x160a1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x160a20: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x160a20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x160a24: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160A24u;
    SET_GPR_U32(ctx, 31, 0x160A2Cu);
    ctx->pc = 0x160A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A24u;
            // 0x160a28: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A2Cu; }
        if (ctx->pc != 0x160A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A2Cu; }
        if (ctx->pc != 0x160A2Cu) { return; }
    }
    ctx->pc = 0x160A2Cu;
label_160a2c:
    // 0x160a2c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x160A2Cu;
    {
        const bool branch_taken_0x160a2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160A2Cu;
            // 0x160a30: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160a2c) {
            ctx->pc = 0x160A58u;
            goto label_160a58;
        }
    }
    ctx->pc = 0x160A34u;
    // 0x160a34: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160a34u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160a38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160a38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160a3c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160a3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160a40: 0x2484f878  addiu       $a0, $a0, -0x788
    ctx->pc = 0x160a40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965368));
    // 0x160a44: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x160a44u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160a48: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x160a48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x160a4c: 0xc7b40020  lwc1        $f20, 0x20($sp)
    ctx->pc = 0x160a4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x160a50: 0x8058dd4  j           func_163750
    ctx->pc = 0x160A50u;
    ctx->pc = 0x160A54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A50u;
            // 0x160a54: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160A58u;
label_160a58:
    // 0x160a58: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x160A58u;
    SET_GPR_U32(ctx, 31, 0x160A60u);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A60u; }
        if (ctx->pc != 0x160A60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A60u; }
        if (ctx->pc != 0x160A60u) { return; }
    }
    ctx->pc = 0x160A60u;
label_160a60:
    // 0x160a60: 0x3c01447a  lui         $at, 0x447A
    ctx->pc = 0x160a60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17530 << 16));
    // 0x160a64: 0x44816000  mtc1        $at, $f12
    ctx->pc = 0x160a64u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x160a68: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x160a68u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160a6c: 0xc04462e  jal         func_1118B8
    ctx->pc = 0x160A6Cu;
    SET_GPR_U32(ctx, 31, 0x160A74u);
    ctx->pc = 0x160A70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A6Cu;
            // 0x160a70: 0x460ca302  mul.s       $f12, $f20, $f12 (Delay Slot)
        ctx->f[12] = FPU_MUL_S(ctx->f[20], ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118B8u;
    if (runtime->hasFunction(0x1118B8u)) {
        auto targetFn = runtime->lookupFunction(0x1118B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A74u; }
        if (ctx->pc != 0x160A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A74u; }
        if (ctx->pc != 0x160A74u) { return; }
    }
    ctx->pc = 0x160A74u;
label_160a74:
    // 0x160a74: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x160a74u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x160a78: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x160a78u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x160a7c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x160A7Cu;
    SET_GPR_U32(ctx, 31, 0x160A84u);
    ctx->pc = 0x160A80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A7Cu;
            // 0x160a80: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A84u; }
        if (ctx->pc != 0x160A84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A84u; }
        if (ctx->pc != 0x160A84u) { return; }
    }
    ctx->pc = 0x160A84u;
label_160a84:
    // 0x160a84: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x160a84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160a88: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x160A88u;
    SET_GPR_U32(ctx, 31, 0x160A90u);
    ctx->pc = 0x160A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A88u;
            // 0x160a8c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A90u; }
        if (ctx->pc != 0x160A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A90u; }
        if (ctx->pc != 0x160A90u) { return; }
    }
    ctx->pc = 0x160A90u;
label_160a90:
    // 0x160a90: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x160a90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160a94: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x160A94u;
    SET_GPR_U32(ctx, 31, 0x160A9Cu);
    ctx->pc = 0x160A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A94u;
            // 0x160a98: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A9Cu; }
        if (ctx->pc != 0x160A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A9Cu; }
        if (ctx->pc != 0x160A9Cu) { return; }
    }
    ctx->pc = 0x160A9Cu;
label_160a9c:
    // 0x160a9c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x160a9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160aa0: 0xc0448a6  jal         func_112298
    ctx->pc = 0x160AA0u;
    SET_GPR_U32(ctx, 31, 0x160AA8u);
    ctx->pc = 0x160AA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160AA0u;
            // 0x160aa4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160AA8u; }
        if (ctx->pc != 0x160AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160AA8u; }
        if (ctx->pc != 0x160AA8u) { return; }
    }
    ctx->pc = 0x160AA8u;
label_160aa8:
    // 0x160aa8: 0x2605ffff  addiu       $a1, $s0, -0x1
    ctx->pc = 0x160aa8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x160aac: 0x2102a  slt         $v0, $zero, $v0
    ctx->pc = 0x160aacu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x160ab0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x160ab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ab4: 0x202280a  movz        $a1, $s0, $v0
    ctx->pc = 0x160ab4u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 16));
    // 0x160ab8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160ab8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160abc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160abcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160ac0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x160ac0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160ac4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x160ac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x160ac8: 0xc7b40020  lwc1        $f20, 0x20($sp)
    ctx->pc = 0x160ac8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x160acc: 0x805c8b4  j           func_1722D0
    ctx->pc = 0x160ACCu;
    ctx->pc = 0x160AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160ACCu;
            // 0x160ad0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1722D0u;
    if (runtime->hasFunction(0x1722D0u)) {
        auto targetFn = runtime->lookupFunction(0x1722D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001722D0_0x1722d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160AD4u;
    // 0x160ad4: 0x0  nop
    ctx->pc = 0x160ad4u;
    // NOP
    // 0x160ad8: 0x3e00008  jr          $ra
    ctx->pc = 0x160AD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1607ECu: goto label_1607ec;
            case 0x160800u: goto label_160800;
            case 0x160804u: goto label_160804;
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
            case 0x160928u: goto label_160928;
            case 0x16092Cu: goto label_16092c;
            case 0x160978u: goto label_160978;
            case 0x160980u: goto label_160980;
            case 0x160990u: goto label_160990;
            case 0x1609BCu: goto label_1609bc;
            case 0x1609E0u: goto label_1609e0;
            case 0x1609E8u: goto label_1609e8;
            case 0x160A2Cu: goto label_160a2c;
            case 0x160A58u: goto label_160a58;
            case 0x160A60u: goto label_160a60;
            case 0x160A74u: goto label_160a74;
            case 0x160A84u: goto label_160a84;
            case 0x160A90u: goto label_160a90;
            case 0x160A9Cu: goto label_160a9c;
            case 0x160AA8u: goto label_160aa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160AE0u;
    // 0x160ae0: 0x3e00008  jr          $ra
    ctx->pc = 0x160AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1607ECu: goto label_1607ec;
            case 0x160800u: goto label_160800;
            case 0x160804u: goto label_160804;
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
            case 0x160928u: goto label_160928;
            case 0x16092Cu: goto label_16092c;
            case 0x160978u: goto label_160978;
            case 0x160980u: goto label_160980;
            case 0x160990u: goto label_160990;
            case 0x1609BCu: goto label_1609bc;
            case 0x1609E0u: goto label_1609e0;
            case 0x1609E8u: goto label_1609e8;
            case 0x160A2Cu: goto label_160a2c;
            case 0x160A58u: goto label_160a58;
            case 0x160A60u: goto label_160a60;
            case 0x160A74u: goto label_160a74;
            case 0x160A84u: goto label_160a84;
            case 0x160A90u: goto label_160a90;
            case 0x160A9Cu: goto label_160a9c;
            case 0x160AA8u: goto label_160aa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160AE8u;
    // 0x160ae8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160ae8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160aec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160aecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160af0: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x160af0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x160af4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160af4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160af8: 0x805a7fc  j           func_169FF0
    ctx->pc = 0x160AF8u;
    ctx->pc = 0x160AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160AF8u;
            // 0x160afc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169FF0u;
    if (runtime->hasFunction(0x169FF0u)) {
        auto targetFn = runtime->lookupFunction(0x169FF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169FF0_0x169ff0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160B00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
