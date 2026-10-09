#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E678
// Address: 0x16e678 - 0x16e768
void sub_0016E678_0x16e678(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E678_0x16e678");
#endif

    switch (ctx->pc) {
        case 0x16e6acu: goto label_16e6ac;
        case 0x16e6c0u: goto label_16e6c0;
        case 0x16e6e4u: goto label_16e6e4;
        case 0x16e6f8u: goto label_16e6f8;
        case 0x16e70cu: goto label_16e70c;
        case 0x16e71cu: goto label_16e71c;
        case 0x16e730u: goto label_16e730;
        case 0x16e744u: goto label_16e744;
        default: break;
    }

    ctx->pc = 0x16e678u;

    // 0x16e678: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16e678u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16e67c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16e67cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16e680: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16e680u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e684: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16e684u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16e688: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x16e688u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16e68c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16e68cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16e690: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16e690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16e694: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x16e694u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e698: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16e698u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16e69c: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x16e69cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x16e6a0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16e6a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16e6a4: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16E6A4u;
    SET_GPR_U32(ctx, 31, 0x16E6ACu);
    ctx->pc = 0x16E6A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6A4u;
            // 0x16e6a8: 0x8e111b30  lw          $s1, 0x1B30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E6ACu; }
        if (ctx->pc != 0x16E6ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E6ACu; }
        if (ctx->pc != 0x16E6ACu) { return; }
    }
    ctx->pc = 0x16E6ACu;
label_16e6ac:
    // 0x16e6ac: 0x10520026  beq         $v0, $s2, . + 4 + (0x26 << 2)
    ctx->pc = 0x16E6ACu;
    {
        const bool branch_taken_0x16e6ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        ctx->pc = 0x16E6B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6ACu;
            // 0x16e6b0: 0x2633008c  addiu       $s3, $s1, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 140));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e6ac) {
            ctx->pc = 0x16E748u;
            goto label_16e748;
        }
    }
    ctx->pc = 0x16E6B4u;
    // 0x16e6b4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16e6b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e6b8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16E6B8u;
    SET_GPR_U32(ctx, 31, 0x16E6C0u);
    ctx->pc = 0x16E6BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6B8u;
            // 0x16e6bc: 0x24050027  addiu       $a1, $zero, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E6C0u; }
        if (ctx->pc != 0x16E6C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E6C0u; }
        if (ctx->pc != 0x16E6C0u) { return; }
    }
    ctx->pc = 0x16E6C0u;
label_16e6c0:
    // 0x16e6c0: 0x54520003  bnel        $v0, $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x16E6C0u;
    {
        const bool branch_taken_0x16e6c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x16e6c0) {
            ctx->pc = 0x16E6C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6C0u;
            // 0x16e6c4: 0x8e230134  lw          $v1, 0x134($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 308)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E6D0u;
            goto label_16e6d0;
        }
    }
    ctx->pc = 0x16E6C8u;
    // 0x16e6c8: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x16E6C8u;
    {
        const bool branch_taken_0x16e6c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6C8u;
            // 0x16e6cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e6c8) {
            ctx->pc = 0x16E748u;
            goto label_16e748;
        }
    }
    ctx->pc = 0x16E6D0u;
label_16e6d0:
    // 0x16e6d0: 0x1460001d  bnez        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x16E6D0u;
    {
        const bool branch_taken_0x16e6d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6D0u;
            // 0x16e6d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e6d0) {
            ctx->pc = 0x16E748u;
            goto label_16e748;
        }
    }
    ctx->pc = 0x16E6D8u;
    // 0x16e6d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16e6d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e6dc: 0xc05ba24  jal         func_16E890
    ctx->pc = 0x16E6DCu;
    SET_GPR_U32(ctx, 31, 0x16E6E4u);
    ctx->pc = 0x16E6E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6DCu;
            // 0x16e6e0: 0x8e710018  lw          $s1, 0x18($s3) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E890u;
    if (runtime->hasFunction(0x16E890u)) {
        auto targetFn = runtime->lookupFunction(0x16E890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E6E4u; }
        if (ctx->pc != 0x16E6E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E890_0x16e890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E6E4u; }
        if (ctx->pc != 0x16E6E4u) { return; }
    }
    ctx->pc = 0x16E6E4u;
label_16e6e4:
    // 0x16e6e4: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x16E6E4u;
    {
        const bool branch_taken_0x16e6e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E6E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6E4u;
            // 0x16e6e8: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e6e4) {
            ctx->pc = 0x16E734u;
            goto label_16e734;
        }
    }
    ctx->pc = 0x16E6ECu;
    // 0x16e6ec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16e6ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e6f0: 0xc05ba38  jal         func_16E8E0
    ctx->pc = 0x16E6F0u;
    SET_GPR_U32(ctx, 31, 0x16E6F8u);
    ctx->pc = 0x16E6F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6F0u;
            // 0x16e6f4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E8E0u;
    if (runtime->hasFunction(0x16E8E0u)) {
        auto targetFn = runtime->lookupFunction(0x16E8E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E6F8u; }
        if (ctx->pc != 0x16E6F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E8E0_0x16e8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E6F8u; }
        if (ctx->pc != 0x16E6F8u) { return; }
    }
    ctx->pc = 0x16E6F8u;
label_16e6f8:
    // 0x16e6f8: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x16E6F8u;
    {
        const bool branch_taken_0x16e6f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E6FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E6F8u;
            // 0x16e6fc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e6f8) {
            ctx->pc = 0x16E738u;
            goto label_16e738;
        }
    }
    ctx->pc = 0x16E700u;
    // 0x16e700: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x16e700u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e704: 0xc05ba4c  jal         func_16E930
    ctx->pc = 0x16E704u;
    SET_GPR_U32(ctx, 31, 0x16E70Cu);
    ctx->pc = 0x16E708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E704u;
            // 0x16e708: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E930u;
    if (runtime->hasFunction(0x16E930u)) {
        auto targetFn = runtime->lookupFunction(0x16E930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E70Cu; }
        if (ctx->pc != 0x16E70Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E930_0x16e930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E70Cu; }
        if (ctx->pc != 0x16E70Cu) { return; }
    }
    ctx->pc = 0x16E70Cu;
label_16e70c:
    // 0x16e70c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16E70Cu;
    {
        const bool branch_taken_0x16e70c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E70Cu;
            // 0x16e710: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e70c) {
            ctx->pc = 0x16E738u;
            goto label_16e738;
        }
    }
    ctx->pc = 0x16E714u;
    // 0x16e714: 0xc05b9da  jal         func_16E768
    ctx->pc = 0x16E714u;
    SET_GPR_U32(ctx, 31, 0x16E71Cu);
    ctx->pc = 0x16E718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E714u;
            // 0x16e718: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E768u;
    if (runtime->hasFunction(0x16E768u)) {
        auto targetFn = runtime->lookupFunction(0x16E768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E71Cu; }
        if (ctx->pc != 0x16E71Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E768_0x16e768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E71Cu; }
        if (ctx->pc != 0x16E71Cu) { return; }
    }
    ctx->pc = 0x16E71Cu;
label_16e71c:
    // 0x16e71c: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x16E71Cu;
    {
        const bool branch_taken_0x16e71c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16e71c) {
            ctx->pc = 0x16E720u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E71Cu;
            // 0x16e720: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E738u;
            goto label_16e738;
        }
    }
    ctx->pc = 0x16E724u;
    // 0x16e724: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16e724u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e728: 0xc05ba6e  jal         func_16E9B8
    ctx->pc = 0x16E728u;
    SET_GPR_U32(ctx, 31, 0x16E730u);
    ctx->pc = 0x16E72Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E728u;
            // 0x16e72c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E9B8u;
    if (runtime->hasFunction(0x16E9B8u)) {
        auto targetFn = runtime->lookupFunction(0x16E9B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E730u; }
        if (ctx->pc != 0x16E730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E9B8_0x16e9b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E730u; }
        if (ctx->pc != 0x16E730u) { return; }
    }
    ctx->pc = 0x16E730u;
label_16e730:
    // 0x16e730: 0x2902b  sltu        $s2, $zero, $v0
    ctx->pc = 0x16e730u;
    SET_GPR_U64(ctx, 18, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_16e734:
    // 0x16e734: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16e734u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16e738:
    // 0x16e738: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x16e738u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e73c: 0xc05b9f2  jal         func_16E7C8
    ctx->pc = 0x16E73Cu;
    SET_GPR_U32(ctx, 31, 0x16E744u);
    ctx->pc = 0x16E740u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E73Cu;
            // 0x16e740: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E7C8u;
    if (runtime->hasFunction(0x16E7C8u)) {
        auto targetFn = runtime->lookupFunction(0x16E7C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E744u; }
        if (ctx->pc != 0x16E744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E7C8_0x16e7c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E744u; }
        if (ctx->pc != 0x16E744u) { return; }
    }
    ctx->pc = 0x16E744u;
label_16e744:
    // 0x16e744: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x16e744u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_16e748:
    // 0x16e748: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16e748u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16e74c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16e74cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16e750: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16e750u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16e754: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16e754u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16e758: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16e758u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16e75c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16e75cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16e760: 0x3e00008  jr          $ra
    ctx->pc = 0x16E760u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E760u;
            // 0x16e764: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E6ACu: goto label_16e6ac;
            case 0x16E6C0u: goto label_16e6c0;
            case 0x16E6D0u: goto label_16e6d0;
            case 0x16E6E4u: goto label_16e6e4;
            case 0x16E6F8u: goto label_16e6f8;
            case 0x16E70Cu: goto label_16e70c;
            case 0x16E71Cu: goto label_16e71c;
            case 0x16E730u: goto label_16e730;
            case 0x16E734u: goto label_16e734;
            case 0x16E738u: goto label_16e738;
            case 0x16E744u: goto label_16e744;
            case 0x16E748u: goto label_16e748;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E768u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
