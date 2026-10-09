#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112770
// Address: 0x112770 - 0x112810
void sub_00112770_0x112770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112770_0x112770");
#endif

    switch (ctx->pc) {
        case 0x112794u: goto label_112794;
        case 0x1127b0u: goto label_1127b0;
        case 0x1127ccu: goto label_1127cc;
        case 0x1127e0u: goto label_1127e0;
        case 0x1127ecu: goto label_1127ec;
        default: break;
    }

    ctx->pc = 0x112770u;

    // 0x112770: 0x27bdfec0  addiu       $sp, $sp, -0x140
    ctx->pc = 0x112770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x112774: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x112774u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x112778: 0xffb20120  sd          $s2, 0x120($sp)
    ctx->pc = 0x112778u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 18));
    // 0x11277c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x11277cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112780: 0xffbf0130  sd          $ra, 0x130($sp)
    ctx->pc = 0x112780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 31));
    // 0x112784: 0x248485b8  addiu       $a0, $a0, -0x7A48
    ctx->pc = 0x112784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294935992));
    // 0x112788: 0xffb10110  sd          $s1, 0x110($sp)
    ctx->pc = 0x112788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 272), GPR_U64(ctx, 17));
    // 0x11278c: 0xc04629c  jal         func_118A70
    ctx->pc = 0x11278Cu;
    SET_GPR_U32(ctx, 31, 0x112794u);
    ctx->pc = 0x112790u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11278Cu;
            // 0x112790: 0xffb00100  sd          $s0, 0x100($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 256), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112794u; }
        if (ctx->pc != 0x112794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112794u; }
        if (ctx->pc != 0x112794u) { return; }
    }
    ctx->pc = 0x112794u;
label_112794:
    // 0x112794: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x112794u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112798: 0x6410003  bgez        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x112798u;
    {
        const bool branch_taken_0x112798 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x11279Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112798u;
            // 0x11279c: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112798) {
            ctx->pc = 0x1127A8u;
            goto label_1127a8;
        }
    }
    ctx->pc = 0x1127A0u;
    // 0x1127a0: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1127A0u;
    {
        const bool branch_taken_0x1127a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1127A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1127A0u;
            // 0x1127a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1127a0) {
            ctx->pc = 0x1127F8u;
            goto label_1127f8;
        }
    }
    ctx->pc = 0x1127A8u;
label_1127a8:
    // 0x1127a8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1127A8u;
    {
        const bool branch_taken_0x1127a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1127ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1127A8u;
            // 0x1127ac: 0x3a0802d  daddu       $s0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1127a8) {
            ctx->pc = 0x1127B4u;
            goto label_1127b4;
        }
    }
    ctx->pc = 0x1127B0u;
label_1127b0:
    // 0x1127b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1127b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1127b4:
    // 0x1127b4: 0x2e220100  sltiu       $v0, $s1, 0x100
    ctx->pc = 0x1127b4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1127b8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1127B8u;
    {
        const bool branch_taken_0x1127b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1127BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1127B8u;
            // 0x1127bc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1127b8) {
            ctx->pc = 0x1127D8u;
            goto label_1127d8;
        }
    }
    ctx->pc = 0x1127C0u;
    // 0x1127c0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1127c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1127c4: 0xc04642c  jal         func_1190B0
    ctx->pc = 0x1127C4u;
    SET_GPR_U32(ctx, 31, 0x1127CCu);
    ctx->pc = 0x1127C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1127C4u;
            // 0x1127c8: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1190B0u;
    if (runtime->hasFunction(0x1190B0u)) {
        auto targetFn = runtime->lookupFunction(0x1190B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1127CCu; }
        if (ctx->pc != 0x1127CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001190B0_0x1190b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1127CCu; }
        if (ctx->pc != 0x1127CCu) { return; }
    }
    ctx->pc = 0x1127CCu;
label_1127cc:
    // 0x1127cc: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1127ccu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1127d0: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1127D0u;
    {
        const bool branch_taken_0x1127d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1127D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1127D0u;
            // 0x1127d4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1127d0) {
            ctx->pc = 0x1127B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1127b0;
        }
    }
    ctx->pc = 0x1127D8u;
label_1127d8:
    // 0x1127d8: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1127D8u;
    SET_GPR_U32(ctx, 31, 0x1127E0u);
    ctx->pc = 0x1127DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1127D8u;
            // 0x1127dc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1127E0u; }
        if (ctx->pc != 0x1127E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1127E0u; }
        if (ctx->pc != 0x1127E0u) { return; }
    }
    ctx->pc = 0x1127E0u;
label_1127e0:
    // 0x1127e0: 0x2624fff7  addiu       $a0, $s1, -0x9
    ctx->pc = 0x1127e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967287));
    // 0x1127e4: 0xc040de0  jal         func_103780
    ctx->pc = 0x1127E4u;
    SET_GPR_U32(ctx, 31, 0x1127ECu);
    ctx->pc = 0x1127E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1127E4u;
            // 0x1127e8: 0x3a42021  addu        $a0, $sp, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1127ECu; }
        if (ctx->pc != 0x1127ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1127ECu; }
        if (ctx->pc != 0x1127ECu) { return; }
    }
    ctx->pc = 0x1127ECu;
label_1127ec:
    // 0x1127ec: 0x3c030131  lui         $v1, 0x131
    ctx->pc = 0x1127ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)305 << 16));
    // 0x1127f0: 0x34635670  ori         $v1, $v1, 0x5670
    ctx->pc = 0x1127f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)22128);
    // 0x1127f4: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1127f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
label_1127f8:
    // 0x1127f8: 0xdfbf0130  ld          $ra, 0x130($sp)
    ctx->pc = 0x1127f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x1127fc: 0xdfb20120  ld          $s2, 0x120($sp)
    ctx->pc = 0x1127fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x112800: 0xdfb10110  ld          $s1, 0x110($sp)
    ctx->pc = 0x112800u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x112804: 0xdfb00100  ld          $s0, 0x100($sp)
    ctx->pc = 0x112804u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x112808: 0x3e00008  jr          $ra
    ctx->pc = 0x112808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11280Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112808u;
            // 0x11280c: 0x27bd0140  addiu       $sp, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112794u: goto label_112794;
            case 0x1127A8u: goto label_1127a8;
            case 0x1127B0u: goto label_1127b0;
            case 0x1127B4u: goto label_1127b4;
            case 0x1127CCu: goto label_1127cc;
            case 0x1127D8u: goto label_1127d8;
            case 0x1127E0u: goto label_1127e0;
            case 0x1127ECu: goto label_1127ec;
            case 0x1127F8u: goto label_1127f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112810u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
