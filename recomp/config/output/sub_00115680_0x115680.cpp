#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115680
// Address: 0x115680 - 0x115770
void sub_00115680_0x115680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115680_0x115680");
#endif

    switch (ctx->pc) {
        case 0x1156d0u: goto label_1156d0;
        case 0x1156f0u: goto label_1156f0;
        case 0x115704u: goto label_115704;
        case 0x115718u: goto label_115718;
        case 0x115728u: goto label_115728;
        case 0x115730u: goto label_115730;
        case 0x115758u: goto label_115758;
        default: break;
    }

    ctx->pc = 0x115680u;

    // 0x115680: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x115680u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x115684: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x115684u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x115688: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x115688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11568c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11568cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115690: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x115690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x115694: 0x40026000  mfc0        $v0, Status
    ctx->pc = 0x115694u;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_status);
    // 0x115698: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x115698u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x11569c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x11569cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1156a0: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1156A0u;
    {
        const bool branch_taken_0x1156a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1156a0) {
            ctx->pc = 0x1156A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1156A0u;
            // 0x1156a4: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1156B4u;
            goto label_1156b4;
        }
    }
    ctx->pc = 0x1156A8u;
    // 0x1156a8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1156a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1156ac: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1156ACu;
    {
        const bool branch_taken_0x1156ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1156B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1156ACu;
            // 0x1156b0: 0x34428008  ori         $v0, $v0, 0x8008 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32776);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1156ac) {
            ctx->pc = 0x115734u;
            goto label_115734;
        }
    }
    ctx->pc = 0x1156B4u;
label_1156b4:
    // 0x1156b4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1156b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1156b8: 0x24428940  addiu       $v0, $v0, -0x76C0
    ctx->pc = 0x1156b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936896));
    // 0x1156bc: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x1156bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x1156c0: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x1156c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x1156c4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1156c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1156c8: 0xc045188  jal         func_114620
    ctx->pc = 0x1156C8u;
    SET_GPR_U32(ctx, 31, 0x1156D0u);
    ctx->pc = 0x1156CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1156C8u;
            // 0x1156cc: 0xafa00008  sw          $zero, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1156D0u; }
        if (ctx->pc != 0x1156D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1156D0u; }
        if (ctx->pc != 0x1156D0u) { return; }
    }
    ctx->pc = 0x1156D0u;
label_1156d0:
    // 0x1156d0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1156d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1156d4: 0x6010004  bgez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1156D4u;
    {
        const bool branch_taken_0x1156d4 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1156D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1156D4u;
            // 0x1156d8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1156d4) {
            ctx->pc = 0x1156E8u;
            goto label_1156e8;
        }
    }
    ctx->pc = 0x1156DCu;
    // 0x1156dc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1156dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1156e0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1156E0u;
    {
        const bool branch_taken_0x1156e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1156E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1156E0u;
            // 0x1156e4: 0x34428003  ori         $v0, $v0, 0x8003 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32771);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1156e0) {
            ctx->pc = 0x115734u;
            goto label_115734;
        }
    }
    ctx->pc = 0x1156E8u;
label_1156e8:
    // 0x1156e8: 0xc047c4a  jal         func_11F128
    ctx->pc = 0x1156E8u;
    SET_GPR_U32(ctx, 31, 0x1156F0u);
    ctx->pc = 0x1156ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1156E8u;
            // 0x1156ec: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F128u;
    if (runtime->hasFunction(0x11F128u)) {
        auto targetFn = runtime->lookupFunction(0x11F128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1156F0u; }
        if (ctx->pc != 0x1156F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011F128_0x11f128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1156F0u; }
        if (ctx->pc != 0x1156F0u) { return; }
    }
    ctx->pc = 0x1156F0u;
label_1156f0:
    // 0x1156f0: 0x3c050011  lui         $a1, 0x11
    ctx->pc = 0x1156f0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
    // 0x1156f4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1156f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1156f8: 0x24a55748  addiu       $a1, $a1, 0x5748
    ctx->pc = 0x1156f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22344));
    // 0x1156fc: 0xc047cb6  jal         func_11F2D8
    ctx->pc = 0x1156FCu;
    SET_GPR_U32(ctx, 31, 0x115704u);
    ctx->pc = 0x115700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1156FCu;
            // 0x115700: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F2D8u;
    if (runtime->hasFunction(0x11F2D8u)) {
        auto targetFn = runtime->lookupFunction(0x11F2D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115704u; }
        if (ctx->pc != 0x115704u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011F2D8_0x11f2d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115704u; }
        if (ctx->pc != 0x115704u) { return; }
    }
    ctx->pc = 0x115704u;
label_115704:
    // 0x115704: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x115704u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115708: 0x6210005  bgez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x115708u;
    {
        const bool branch_taken_0x115708 = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x115708) {
            ctx->pc = 0x115720u;
            goto label_115720;
        }
    }
    ctx->pc = 0x115710u;
    // 0x115710: 0xc04518c  jal         func_114630
    ctx->pc = 0x115710u;
    SET_GPR_U32(ctx, 31, 0x115718u);
    ctx->pc = 0x115714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115710u;
            // 0x115714: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115718u; }
        if (ctx->pc != 0x115718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115718u; }
        if (ctx->pc != 0x115718u) { return; }
    }
    ctx->pc = 0x115718u;
label_115718:
    // 0x115718: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x115718u;
    {
        const bool branch_taken_0x115718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11571Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115718u;
            // 0x11571c: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115718) {
            ctx->pc = 0x115734u;
            goto label_115734;
        }
    }
    ctx->pc = 0x115720u;
label_115720:
    // 0x115720: 0xc045198  jal         func_114660
    ctx->pc = 0x115720u;
    SET_GPR_U32(ctx, 31, 0x115728u);
    ctx->pc = 0x115724u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115720u;
            // 0x115724: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115728u; }
        if (ctx->pc != 0x115728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115728u; }
        if (ctx->pc != 0x115728u) { return; }
    }
    ctx->pc = 0x115728u;
label_115728:
    // 0x115728: 0xc04518c  jal         func_114630
    ctx->pc = 0x115728u;
    SET_GPR_U32(ctx, 31, 0x115730u);
    ctx->pc = 0x11572Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115728u;
            // 0x11572c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115730u; }
        if (ctx->pc != 0x115730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115730u; }
        if (ctx->pc != 0x115730u) { return; }
    }
    ctx->pc = 0x115730u;
label_115730:
    // 0x115730: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x115730u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_115734:
    // 0x115734: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x115734u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x115738: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x115738u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11573c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x11573cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115740: 0x3e00008  jr          $ra
    ctx->pc = 0x115740u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115740u;
            // 0x115744: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1156B4u: goto label_1156b4;
            case 0x1156D0u: goto label_1156d0;
            case 0x1156E8u: goto label_1156e8;
            case 0x1156F0u: goto label_1156f0;
            case 0x115704u: goto label_115704;
            case 0x115718u: goto label_115718;
            case 0x115720u: goto label_115720;
            case 0x115728u: goto label_115728;
            case 0x115730u: goto label_115730;
            case 0x115734u: goto label_115734;
            case 0x115758u: goto label_115758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115748u;
    // 0x115748: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x115748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11574c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11574cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x115750: 0xc045194  jal         func_114650
    ctx->pc = 0x115750u;
    SET_GPR_U32(ctx, 31, 0x115758u);
    ctx->pc = 0x115754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115750u;
            // 0x115754: 0xe0202d  daddu       $a0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115758u; }
        if (ctx->pc != 0x115758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115758u; }
        if (ctx->pc != 0x115758u) { return; }
    }
    ctx->pc = 0x115758u;
label_115758:
    // 0x115758: 0xf  sync
    ctx->pc = 0x115758u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11575c: 0x42000038  ei
    ctx->pc = 0x11575cu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x115760: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x115760u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115764: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x115764u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115768: 0x3e00008  jr          $ra
    ctx->pc = 0x115768u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11576Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115768u;
            // 0x11576c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1156B4u: goto label_1156b4;
            case 0x1156D0u: goto label_1156d0;
            case 0x1156E8u: goto label_1156e8;
            case 0x1156F0u: goto label_1156f0;
            case 0x115704u: goto label_115704;
            case 0x115718u: goto label_115718;
            case 0x115720u: goto label_115720;
            case 0x115728u: goto label_115728;
            case 0x115730u: goto label_115730;
            case 0x115734u: goto label_115734;
            case 0x115758u: goto label_115758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115770u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
