#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D27D0
// Address: 0x1d27d0 - 0x1d29f0
void sub_001D27D0_0x1d27d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D27D0_0x1d27d0");
#endif

    switch (ctx->pc) {
        case 0x1d2804u: goto label_1d2804;
        case 0x1d2824u: goto label_1d2824;
        case 0x1d2844u: goto label_1d2844;
        case 0x1d2868u: goto label_1d2868;
        case 0x1d2870u: goto label_1d2870;
        case 0x1d28b0u: goto label_1d28b0;
        case 0x1d28dcu: goto label_1d28dc;
        case 0x1d28f4u: goto label_1d28f4;
        case 0x1d291cu: goto label_1d291c;
        case 0x1d292cu: goto label_1d292c;
        case 0x1d2940u: goto label_1d2940;
        case 0x1d2968u: goto label_1d2968;
        case 0x1d29a8u: goto label_1d29a8;
        case 0x1d29b4u: goto label_1d29b4;
        default: break;
    }

    ctx->pc = 0x1d27d0u;

    // 0x1d27d0: 0x27bdff10  addiu       $sp, $sp, -0xF0
    ctx->pc = 0x1d27d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967056));
    // 0x1d27d4: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1d27d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1d27d8: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d27d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d27dc: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d27dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d27e0: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1d27e0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d27e4: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d27e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d27e8: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1d27e8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d27ec: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d27ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d27f0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1d27f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d27f4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d27f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d27f8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d27f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d27fc: 0xc068c6c  jal         func_1A31B0
    ctx->pc = 0x1D27FCu;
    SET_GPR_U32(ctx, 31, 0x1D2804u);
    ctx->pc = 0x1D2800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D27FCu;
            // 0x1d2800: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A31B0u;
    if (runtime->hasFunction(0x1A31B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A31B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2804u; }
        if (ctx->pc != 0x1D2804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A31B0_0x1a31b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2804u; }
        if (ctx->pc != 0x1D2804u) { return; }
    }
    ctx->pc = 0x1D2804u;
label_1d2804:
    // 0x1d2804: 0x320300ff  andi        $v1, $s0, 0xFF
    ctx->pc = 0x1d2804u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x1d2808: 0xa6a20812  sh          $v0, 0x812($s5)
    ctx->pc = 0x1d2808u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 2066), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d280c: 0x32080  sll         $a0, $v1, 2
    ctx->pc = 0x1d280cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d2810: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1d2810u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2814: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1d2814u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1d2818: 0x246366e0  addiu       $v1, $v1, 0x66E0
    ctx->pc = 0x1d2818u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 26336));
    // 0x1d281c: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x1D281Cu;
    {
        const bool branch_taken_0x1d281c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D281Cu;
            // 0x1d2820: 0x648821  addu        $s1, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d281c) {
            ctx->pc = 0x1D29B8u;
            goto label_1d29b8;
        }
    }
    ctx->pc = 0x1D2824u;
label_1d2824:
    // 0x1d2824: 0x1310c0  sll         $v0, $s3, 3
    ctx->pc = 0x1d2824u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x1d2828: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1d2828u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d282c: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x1d282cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1d2830: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d2830u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2834: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1d2834u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1d2838: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x1d2838u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1d283c: 0xc068d2c  jal         func_1A34B0
    ctx->pc = 0x1D283Cu;
    SET_GPR_U32(ctx, 31, 0x1D2844u);
    ctx->pc = 0x1D2840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D283Cu;
            // 0x1d2840: 0x280c0  sll         $s0, $v0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A34B0u;
    if (runtime->hasFunction(0x1A34B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A34B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2844u; }
        if (ctx->pc != 0x1D2844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A34B0_0x1a34b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2844u; }
        if (ctx->pc != 0x1D2844u) { return; }
    }
    ctx->pc = 0x1D2844u;
label_1d2844:
    // 0x1d2844: 0x8ea30808  lw          $v1, 0x808($s5)
    ctx->pc = 0x1d2844u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d2848: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1d2848u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d284c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d284cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2850: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1d2850u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1d2854: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1d2854u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1d2858: 0x8ea20808  lw          $v0, 0x808($s5)
    ctx->pc = 0x1d2858u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d285c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d285cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d2860: 0xc068d40  jal         func_1A3500
    ctx->pc = 0x1D2860u;
    SET_GPR_U32(ctx, 31, 0x1D2868u);
    ctx->pc = 0x1D2864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2860u;
            // 0x1d2864: 0x24460008  addiu       $a2, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3500u;
    if (runtime->hasFunction(0x1A3500u)) {
        auto targetFn = runtime->lookupFunction(0x1A3500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2868u; }
        if (ctx->pc != 0x1D2868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3500_0x1a3500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2868u; }
        if (ctx->pc != 0x1D2868u) { return; }
    }
    ctx->pc = 0x1D2868u;
label_1d2868:
    // 0x1d2868: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1D2868u;
    {
        const bool branch_taken_0x1d2868 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D286Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2868u;
            // 0x1d286c: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2868) {
            ctx->pc = 0x1D28B4u;
            goto label_1d28b4;
        }
    }
    ctx->pc = 0x1D2870u;
label_1d2870:
    // 0x1d2870: 0x2643003a  addiu       $v1, $s2, 0x3A
    ctx->pc = 0x1d2870u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 58));
    // 0x1d2874: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1d2874u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1d2878: 0x306400ff  andi        $a0, $v1, 0xFF
    ctx->pc = 0x1d2878u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1d287c: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1d287cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1d2880: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1d2880u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d2884: 0x3c02004f  lui         $v0, 0x4F
    ctx->pc = 0x1d2884u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)79 << 16));
    // 0x1d2888: 0x2a31821  addu        $v1, $s5, $v1
    ctx->pc = 0x1d2888u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x1d288c: 0x2442dd90  addiu       $v0, $v0, -0x2270
    ctx->pc = 0x1d288cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958480));
    // 0x1d2890: 0x94650008  lhu         $a1, 0x8($v1)
    ctx->pc = 0x1d2890u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1d2894: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x1d2894u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d2898: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1d2898u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1d289c: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1d289cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d28a0: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1d28a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1d28a4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d28a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d28a8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D28A8u;
    SET_GPR_U32(ctx, 31, 0x1D28B0u);
    ctx->pc = 0x1D28ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D28A8u;
            // 0x1d28ac: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D28B0u; }
        if (ctx->pc != 0x1D28B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D28B0u; }
        if (ctx->pc != 0x1D28B0u) { return; }
    }
    ctx->pc = 0x1D28B0u;
label_1d28b0:
    // 0x1d28b0: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1d28b0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1d28b4:
    // 0x1d28b4: 0x8ea20808  lw          $v0, 0x808($s5)
    ctx->pc = 0x1d28b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d28b8: 0x2022021  addu        $a0, $s0, $v0
    ctx->pc = 0x1d28b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1d28bc: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1d28bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d28c0: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x1d28c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d28c4: 0x1440ffea  bnez        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x1D28C4u;
    {
        const bool branch_taken_0x1d28c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D28C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D28C4u;
            // 0x1d28c8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d28c4) {
            ctx->pc = 0x1D2870u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2870;
        }
    }
    ctx->pc = 0x1D28CCu;
    // 0x1d28cc: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1d28ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1d28d0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1d28d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d28d4: 0xc068c24  jal         func_1A3090
    ctx->pc = 0x1D28D4u;
    SET_GPR_U32(ctx, 31, 0x1D28DCu);
    ctx->pc = 0x1D28D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D28D4u;
            // 0x1d28d8: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3090u;
    if (runtime->hasFunction(0x1A3090u)) {
        auto targetFn = runtime->lookupFunction(0x1A3090u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D28DCu; }
        if (ctx->pc != 0x1D28DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3090_0x1a3090(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D28DCu; }
        if (ctx->pc != 0x1D28DCu) { return; }
    }
    ctx->pc = 0x1D28DCu;
label_1d28dc:
    // 0x1d28dc: 0x440000a  bltz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D28DCu;
    {
        const bool branch_taken_0x1d28dc = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1d28dc) {
            ctx->pc = 0x1D2908u;
            goto label_1d2908;
        }
    }
    ctx->pc = 0x1D28E4u;
    // 0x1d28e4: 0x8ea20808  lw          $v0, 0x808($s5)
    ctx->pc = 0x1d28e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d28e8: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1d28e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1d28ec: 0xc074a7c  jal         func_1D29F0
    ctx->pc = 0x1D28ECu;
    SET_GPR_U32(ctx, 31, 0x1D28F4u);
    ctx->pc = 0x1D28F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D28ECu;
            // 0x1d28f0: 0x502821  addu        $a1, $v0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D29F0u;
    if (runtime->hasFunction(0x1D29F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D29F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D28F4u; }
        if (ctx->pc != 0x1D28F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D29F0_0x1d29f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D28F4u; }
        if (ctx->pc != 0x1D28F4u) { return; }
    }
    ctx->pc = 0x1D28F4u;
label_1d28f4:
    // 0x1d28f4: 0x8ea20808  lw          $v0, 0x808($s5)
    ctx->pc = 0x1d28f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d28f8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d28f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d28fc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d28fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d2900: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2900u;
    {
        const bool branch_taken_0x1d2900 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2900u;
            // 0x1d2904: 0xa0430088  sb          $v1, 0x88($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 136), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2900) {
            ctx->pc = 0x1D2914u;
            goto label_1d2914;
        }
    }
    ctx->pc = 0x1D2908u;
label_1d2908:
    // 0x1d2908: 0x8ea20808  lw          $v0, 0x808($s5)
    ctx->pc = 0x1d2908u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d290c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d290cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d2910: 0xa0400088  sb          $zero, 0x88($v0)
    ctx->pc = 0x1d2910u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 136), (uint8_t)GPR_U32(ctx, 0));
label_1d2914:
    // 0x1d2914: 0xc063700  jal         func_18DC00
    ctx->pc = 0x1D2914u;
    SET_GPR_U32(ctx, 31, 0x1D291Cu);
    ctx->pc = 0x1D2918u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2914u;
            // 0x1d2918: 0x27a400e8  addiu       $a0, $sp, 0xE8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 232));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC00u;
    if (runtime->hasFunction(0x18DC00u)) {
        auto targetFn = runtime->lookupFunction(0x18DC00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D291Cu; }
        if (ctx->pc != 0x1D291Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC00_0x18dc00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D291Cu; }
        if (ctx->pc != 0x1D291Cu) { return; }
    }
    ctx->pc = 0x1D291Cu;
label_1d291c:
    // 0x1d291c: 0x27a400c0  addiu       $a0, $sp, 0xC0
    ctx->pc = 0x1d291cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
    // 0x1d2920: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1d2920u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2924: 0xc068f64  jal         func_1A3D90
    ctx->pc = 0x1D2924u;
    SET_GPR_U32(ctx, 31, 0x1D292Cu);
    ctx->pc = 0x1D2928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2924u;
            // 0x1d2928: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3D90u;
    if (runtime->hasFunction(0x1A3D90u)) {
        auto targetFn = runtime->lookupFunction(0x1A3D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D292Cu; }
        if (ctx->pc != 0x1D292Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3D90_0x1a3d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D292Cu; }
        if (ctx->pc != 0x1D292Cu) { return; }
    }
    ctx->pc = 0x1D292Cu;
label_1d292c:
    // 0x1d292c: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1D292Cu;
    {
        const bool branch_taken_0x1d292c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d292c) {
            ctx->pc = 0x1D2970u;
            goto label_1d2970;
        }
    }
    ctx->pc = 0x1D2934u;
    // 0x1d2934: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x1d2934u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d2938: 0xc062720  jal         func_189C80
    ctx->pc = 0x1D2938u;
    SET_GPR_U32(ctx, 31, 0x1D2940u);
    ctx->pc = 0x1D293Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2938u;
            // 0x1d293c: 0x27a400c0  addiu       $a0, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189C80u;
    if (runtime->hasFunction(0x189C80u)) {
        auto targetFn = runtime->lookupFunction(0x189C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2940u; }
        if (ctx->pc != 0x1D2940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189C80_0x189c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2940u; }
        if (ctx->pc != 0x1D2940u) { return; }
    }
    ctx->pc = 0x1D2940u;
label_1d2940:
    // 0x1d2940: 0x8ea30808  lw          $v1, 0x808($s5)
    ctx->pc = 0x1d2940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d2944: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1d2944u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1d2948: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1d2948u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1d294c: 0x8ea20808  lw          $v0, 0x808($s5)
    ctx->pc = 0x1d294cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d2950: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d2950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d2954: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1d2954u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2958: 0x10800009  beqz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D2958u;
    {
        const bool branch_taken_0x1d2958 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d2958) {
            ctx->pc = 0x1D2980u;
            goto label_1d2980;
        }
    }
    ctx->pc = 0x1D2960u;
    // 0x1d2960: 0xc06c3fc  jal         func_1B0FF0
    ctx->pc = 0x1D2960u;
    SET_GPR_U32(ctx, 31, 0x1D2968u);
    ctx->pc = 0x1B0FF0u;
    if (runtime->hasFunction(0x1B0FF0u)) {
        auto targetFn = runtime->lookupFunction(0x1B0FF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2968u; }
        if (ctx->pc != 0x1D2968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0FF0_0x1b0ff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2968u; }
        if (ctx->pc != 0x1D2968u) { return; }
    }
    ctx->pc = 0x1D2968u;
label_1d2968:
    // 0x1d2968: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D2968u;
    {
        const bool branch_taken_0x1d2968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D296Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2968u;
            // 0x1d296c: 0x8ea30818  lw          $v1, 0x818($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2072)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2968) {
            ctx->pc = 0x1D2984u;
            goto label_1d2984;
        }
    }
    ctx->pc = 0x1D2970u;
label_1d2970:
    // 0x1d2970: 0x8ea20808  lw          $v0, 0x808($s5)
    ctx->pc = 0x1d2970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2056)));
    // 0x1d2974: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d2974u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d2978: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d2978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d297c: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1d297cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_1d2980:
    // 0x1d2980: 0x8ea30818  lw          $v1, 0x818($s5)
    ctx->pc = 0x1d2980u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2072)));
label_1d2984:
    // 0x1d2984: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D2984u;
    {
        const bool branch_taken_0x1d2984 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2984u;
            // 0x1d2988: 0x27a400e8  addiu       $a0, $sp, 0xE8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2984) {
            ctx->pc = 0x1D29ACu;
            goto label_1d29ac;
        }
    }
    ctx->pc = 0x1D298Cu;
    // 0x1d298c: 0x131140  sll         $v0, $s3, 5
    ctx->pc = 0x1d298cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 5));
    // 0x1d2990: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1d2990u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2994: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x1d2994u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1d2998: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1d2998u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d299c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1d299cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1d29a0: 0xc068bfc  jal         func_1A2FF0
    ctx->pc = 0x1D29A0u;
    SET_GPR_U32(ctx, 31, 0x1D29A8u);
    ctx->pc = 0x1D29A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D29A0u;
            // 0x1d29a4: 0x622021  addu        $a0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2FF0u;
    if (runtime->hasFunction(0x1A2FF0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2FF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D29A8u; }
        if (ctx->pc != 0x1D29A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2FF0_0x1a2ff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D29A8u; }
        if (ctx->pc != 0x1D29A8u) { return; }
    }
    ctx->pc = 0x1D29A8u;
label_1d29a8:
    // 0x1d29a8: 0x27a400e8  addiu       $a0, $sp, 0xE8
    ctx->pc = 0x1d29a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 232));
label_1d29ac:
    // 0x1d29ac: 0xc063708  jal         func_18DC20
    ctx->pc = 0x1D29ACu;
    SET_GPR_U32(ctx, 31, 0x1D29B4u);
    ctx->pc = 0x18DC20u;
    if (runtime->hasFunction(0x18DC20u)) {
        auto targetFn = runtime->lookupFunction(0x18DC20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D29B4u; }
        if (ctx->pc != 0x1D29B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC20_0x18dc20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D29B4u; }
        if (ctx->pc != 0x1D29B4u) { return; }
    }
    ctx->pc = 0x1D29B4u;
label_1d29b4:
    // 0x1d29b4: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d29b4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1d29b8:
    // 0x1d29b8: 0x96a30812  lhu         $v1, 0x812($s5)
    ctx->pc = 0x1d29b8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 2066)));
    // 0x1d29bc: 0x263182a  slt         $v1, $s3, $v1
    ctx->pc = 0x1d29bcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d29c0: 0x1460ff98  bnez        $v1, . + 4 + (-0x68 << 2)
    ctx->pc = 0x1D29C0u;
    {
        const bool branch_taken_0x1d29c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d29c0) {
            ctx->pc = 0x1D2824u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2824;
        }
    }
    ctx->pc = 0x1D29C8u;
    // 0x1d29c8: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1d29c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d29cc: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d29ccu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d29d0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d29d0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d29d4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d29d4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d29d8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d29d8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d29dc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d29dcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d29e0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d29e0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d29e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D29E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D29E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D29E4u;
            // 0x1d29e8: 0x27bd00f0  addiu       $sp, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2804u: goto label_1d2804;
            case 0x1D2824u: goto label_1d2824;
            case 0x1D2844u: goto label_1d2844;
            case 0x1D2868u: goto label_1d2868;
            case 0x1D2870u: goto label_1d2870;
            case 0x1D28B0u: goto label_1d28b0;
            case 0x1D28B4u: goto label_1d28b4;
            case 0x1D28DCu: goto label_1d28dc;
            case 0x1D28F4u: goto label_1d28f4;
            case 0x1D2908u: goto label_1d2908;
            case 0x1D2914u: goto label_1d2914;
            case 0x1D291Cu: goto label_1d291c;
            case 0x1D292Cu: goto label_1d292c;
            case 0x1D2940u: goto label_1d2940;
            case 0x1D2968u: goto label_1d2968;
            case 0x1D2970u: goto label_1d2970;
            case 0x1D2980u: goto label_1d2980;
            case 0x1D2984u: goto label_1d2984;
            case 0x1D29A8u: goto label_1d29a8;
            case 0x1D29ACu: goto label_1d29ac;
            case 0x1D29B4u: goto label_1d29b4;
            case 0x1D29B8u: goto label_1d29b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D29ECu;
    // 0x1d29ec: 0x0  nop
    ctx->pc = 0x1d29ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
