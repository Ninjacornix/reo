#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4870
// Address: 0x1d4870 - 0x1d49d4
void sub_001D4870_0x1d4870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4870_0x1d4870");
#endif

    switch (ctx->pc) {
        case 0x1d48c8u: goto label_1d48c8;
        case 0x1d48e0u: goto label_1d48e0;
        case 0x1d48f0u: goto label_1d48f0;
        case 0x1d4918u: goto label_1d4918;
        case 0x1d492cu: goto label_1d492c;
        case 0x1d493cu: goto label_1d493c;
        case 0x1d4960u: goto label_1d4960;
        case 0x1d496cu: goto label_1d496c;
        case 0x1d497cu: goto label_1d497c;
        case 0x1d4998u: goto label_1d4998;
        case 0x1d49a4u: goto label_1d49a4;
        case 0x1d49b4u: goto label_1d49b4;
        case 0x1d49bcu: goto label_1d49bc;
        default: break;
    }

    ctx->pc = 0x1d4870u;

    // 0x1d4870: 0x27bdfec0  addiu       $sp, $sp, -0x140
    ctx->pc = 0x1d4870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x1d4874: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4874u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4878: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d4878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d487c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d487cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4880: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d4880u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4884: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4884u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4888: 0x3c110032  lui         $s1, 0x32
    ctx->pc = 0x1d4888u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)50 << 16));
    // 0x1d488c: 0x8c32440c  lw          $s2, 0x440C($at)
    ctx->pc = 0x1d488cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d4890: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4890u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4894: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d4894u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d4898: 0x1440002a  bnez        $v0, . + 4 + (0x2A << 2)
    ctx->pc = 0x1D4898u;
    {
        const bool branch_taken_0x1d4898 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D489Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4898u;
            // 0x1d489c: 0x263143c0  addiu       $s1, $s1, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 17344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4898) {
            ctx->pc = 0x1D4944u;
            goto label_1d4944;
        }
    }
    ctx->pc = 0x1D48A0u;
    // 0x1d48a0: 0x9627001a  lhu         $a3, 0x1A($s1)
    ctx->pc = 0x1d48a0u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d48a4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d48a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d48a8: 0x9629001c  lhu         $t1, 0x1C($s1)
    ctx->pc = 0x1d48a8u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d48ac: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d48acu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d48b0: 0x962a001e  lhu         $t2, 0x1E($s1)
    ctx->pc = 0x1d48b0u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x1d48b4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d48b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d48b8: 0x24a56980  addiu       $a1, $a1, 0x6980
    ctx->pc = 0x1d48b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27008));
    // 0x1d48bc: 0x24c669a0  addiu       $a2, $a2, 0x69A0
    ctx->pc = 0x1d48bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 27040));
    // 0x1d48c0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D48C0u;
    SET_GPR_U32(ctx, 31, 0x1D48C8u);
    ctx->pc = 0x1D48C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D48C0u;
            // 0x1d48c4: 0xe0402d  daddu       $t0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D48C8u; }
        if (ctx->pc != 0x1D48C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D48C8u; }
        if (ctx->pc != 0x1D48C8u) { return; }
    }
    ctx->pc = 0x1D48C8u;
label_1d48c8:
    // 0x1d48c8: 0x27b00040  addiu       $s0, $sp, 0x40
    ctx->pc = 0x1d48c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d48cc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1d48ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d48d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d48d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d48d4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d48d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d48d8: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D48D8u;
    SET_GPR_U32(ctx, 31, 0x1D48E0u);
    ctx->pc = 0x1D48DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D48D8u;
            // 0x1d48dc: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D48E0u; }
        if (ctx->pc != 0x1D48E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D48E0u; }
        if (ctx->pc != 0x1D48E0u) { return; }
    }
    ctx->pc = 0x1D48E0u;
label_1d48e0:
    // 0x1d48e0: 0x18400003  blez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D48E0u;
    {
        const bool branch_taken_0x1d48e0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D48E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D48E0u;
            // 0x1d48e4: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d48e0) {
            ctx->pc = 0x1D48F0u;
            goto label_1d48f0;
        }
    }
    ctx->pc = 0x1D48E8u;
    // 0x1d48e8: 0xc1ac7b0  jal         func_6B1EC0
    ctx->pc = 0x1D48E8u;
    SET_GPR_U32(ctx, 31, 0x1D48F0u);
    ctx->pc = 0x1D48ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D48E8u;
            // 0x1d48ec: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B1EC0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B1EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D48F0u; }
        if (ctx->pc != 0x1D48F0u) { return; }
    }
    ctx->pc = 0x1D48F0u;
label_1d48f0:
    // 0x1d48f0: 0x9627001a  lhu         $a3, 0x1A($s1)
    ctx->pc = 0x1d48f0u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d48f4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d48f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d48f8: 0x9629001c  lhu         $t1, 0x1C($s1)
    ctx->pc = 0x1d48f8u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d48fc: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d48fcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d4900: 0x962a001e  lhu         $t2, 0x1E($s1)
    ctx->pc = 0x1d4900u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x1d4904: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d4904u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d4908: 0x24a569c0  addiu       $a1, $a1, 0x69C0
    ctx->pc = 0x1d4908u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27072));
    // 0x1d490c: 0x24c669e0  addiu       $a2, $a2, 0x69E0
    ctx->pc = 0x1d490cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 27104));
    // 0x1d4910: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4910u;
    SET_GPR_U32(ctx, 31, 0x1D4918u);
    ctx->pc = 0x1D4914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4910u;
            // 0x1d4914: 0xe0402d  daddu       $t0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4918u; }
        if (ctx->pc != 0x1D4918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4918u; }
        if (ctx->pc != 0x1D4918u) { return; }
    }
    ctx->pc = 0x1D4918u;
label_1d4918:
    // 0x1d4918: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d4918u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d491c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1d491cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4920: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d4920u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4924: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4924u;
    SET_GPR_U32(ctx, 31, 0x1D492Cu);
    ctx->pc = 0x1D4928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4924u;
            // 0x1d4928: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D492Cu; }
        if (ctx->pc != 0x1D492Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D492Cu; }
        if (ctx->pc != 0x1D492Cu) { return; }
    }
    ctx->pc = 0x1D492Cu;
label_1d492c:
    // 0x1d492c: 0x18400021  blez        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x1D492Cu;
    {
        const bool branch_taken_0x1d492c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D4930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D492Cu;
            // 0x1d4930: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d492c) {
            ctx->pc = 0x1D49B4u;
            goto label_1d49b4;
        }
    }
    ctx->pc = 0x1D4934u;
    // 0x1d4934: 0xc1ac8f8  jal         func_6B23E0
    ctx->pc = 0x1D4934u;
    SET_GPR_U32(ctx, 31, 0x1D493Cu);
    ctx->pc = 0x1D4938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4934u;
            // 0x1d4938: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B23E0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B23E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D493Cu; }
        if (ctx->pc != 0x1D493Cu) { return; }
    }
    ctx->pc = 0x1D493Cu;
label_1d493c:
    // 0x1d493c: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1D493Cu;
    {
        const bool branch_taken_0x1d493c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d493c) {
            ctx->pc = 0x1D49B4u;
            goto label_1d49b4;
        }
    }
    ctx->pc = 0x1D4944u;
label_1d4944:
    // 0x1d4944: 0x9626001a  lhu         $a2, 0x1A($s1)
    ctx->pc = 0x1d4944u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d4948: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4948u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d494c: 0x9627001c  lhu         $a3, 0x1C($s1)
    ctx->pc = 0x1d494cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d4950: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d4950u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d4954: 0x9628001e  lhu         $t0, 0x1E($s1)
    ctx->pc = 0x1d4954u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x1d4958: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4958u;
    SET_GPR_U32(ctx, 31, 0x1D4960u);
    ctx->pc = 0x1D495Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4958u;
            // 0x1d495c: 0x24a56a00  addiu       $a1, $a1, 0x6A00 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4960u; }
        if (ctx->pc != 0x1D4960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4960u; }
        if (ctx->pc != 0x1D4960u) { return; }
    }
    ctx->pc = 0x1D4960u;
label_1d4960:
    // 0x1d4960: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d4960u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d4964: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D4964u;
    SET_GPR_U32(ctx, 31, 0x1D496Cu);
    ctx->pc = 0x1D4968u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4964u;
            // 0x1d4968: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D496Cu; }
        if (ctx->pc != 0x1D496Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D496Cu; }
        if (ctx->pc != 0x1D496Cu) { return; }
    }
    ctx->pc = 0x1D496Cu;
label_1d496c:
    // 0x1d496c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D496Cu;
    {
        const bool branch_taken_0x1d496c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D496Cu;
            // 0x1d4970: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d496c) {
            ctx->pc = 0x1D497Cu;
            goto label_1d497c;
        }
    }
    ctx->pc = 0x1D4974u;
    // 0x1d4974: 0xc1ac7b0  jal         func_6B1EC0
    ctx->pc = 0x1D4974u;
    SET_GPR_U32(ctx, 31, 0x1D497Cu);
    ctx->pc = 0x1D4978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4974u;
            // 0x1d4978: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B1EC0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B1EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D497Cu; }
        if (ctx->pc != 0x1D497Cu) { return; }
    }
    ctx->pc = 0x1D497Cu;
label_1d497c:
    // 0x1d497c: 0x9626001a  lhu         $a2, 0x1A($s1)
    ctx->pc = 0x1d497cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d4980: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4980u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4984: 0x9627001c  lhu         $a3, 0x1C($s1)
    ctx->pc = 0x1d4984u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d4988: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d4988u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d498c: 0x9628001e  lhu         $t0, 0x1E($s1)
    ctx->pc = 0x1d498cu;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x1d4990: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4990u;
    SET_GPR_U32(ctx, 31, 0x1D4998u);
    ctx->pc = 0x1D4994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4990u;
            // 0x1d4994: 0x24a56a20  addiu       $a1, $a1, 0x6A20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4998u; }
        if (ctx->pc != 0x1D4998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4998u; }
        if (ctx->pc != 0x1D4998u) { return; }
    }
    ctx->pc = 0x1D4998u;
label_1d4998:
    // 0x1d4998: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d4998u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d499c: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D499Cu;
    SET_GPR_U32(ctx, 31, 0x1D49A4u);
    ctx->pc = 0x1D49A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D499Cu;
            // 0x1d49a0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D49A4u; }
        if (ctx->pc != 0x1D49A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D49A4u; }
        if (ctx->pc != 0x1D49A4u) { return; }
    }
    ctx->pc = 0x1D49A4u;
label_1d49a4:
    // 0x1d49a4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D49A4u;
    {
        const bool branch_taken_0x1d49a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D49A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D49A4u;
            // 0x1d49a8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d49a4) {
            ctx->pc = 0x1D49B4u;
            goto label_1d49b4;
        }
    }
    ctx->pc = 0x1D49ACu;
    // 0x1d49ac: 0xc1ac8f8  jal         func_6B23E0
    ctx->pc = 0x1D49ACu;
    SET_GPR_U32(ctx, 31, 0x1D49B4u);
    ctx->pc = 0x1D49B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D49ACu;
            // 0x1d49b0: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B23E0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B23E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D49B4u; }
        if (ctx->pc != 0x1D49B4u) { return; }
    }
    ctx->pc = 0x1D49B4u;
label_1d49b4:
    // 0x1d49b4: 0xc1ace0c  jal         func_6B3830
    ctx->pc = 0x1D49B4u;
    SET_GPR_U32(ctx, 31, 0x1D49BCu);
    ctx->pc = 0x6B3830u;
    {
        auto targetFn = runtime->lookupFunction(0x6B3830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D49BCu; }
        if (ctx->pc != 0x1D49BCu) { return; }
    }
    ctx->pc = 0x1D49BCu;
label_1d49bc:
    // 0x1d49bc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d49bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d49c0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d49c0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d49c4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d49c4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d49c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d49c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d49cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D49CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D49D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D49CCu;
            // 0x1d49d0: 0x27bd0140  addiu       $sp, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D48C8u: goto label_1d48c8;
            case 0x1D48E0u: goto label_1d48e0;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4918u: goto label_1d4918;
            case 0x1D492Cu: goto label_1d492c;
            case 0x1D493Cu: goto label_1d493c;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D4960u: goto label_1d4960;
            case 0x1D496Cu: goto label_1d496c;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D4998u: goto label_1d4998;
            case 0x1D49A4u: goto label_1d49a4;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D49BCu: goto label_1d49bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D49D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
