#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D6E8
// Address: 0x16d6e8 - 0x16d8a0
void sub_0016D6E8_0x16d6e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D6E8_0x16d6e8");
#endif

    switch (ctx->pc) {
        case 0x16d744u: goto label_16d744;
        case 0x16d754u: goto label_16d754;
        case 0x16d764u: goto label_16d764;
        case 0x16d778u: goto label_16d778;
        case 0x16d794u: goto label_16d794;
        case 0x16d7a4u: goto label_16d7a4;
        case 0x16d7c0u: goto label_16d7c0;
        case 0x16d7ccu: goto label_16d7cc;
        case 0x16d7ecu: goto label_16d7ec;
        case 0x16d828u: goto label_16d828;
        case 0x16d844u: goto label_16d844;
        case 0x16d850u: goto label_16d850;
        case 0x16d85cu: goto label_16d85c;
        case 0x16d870u: goto label_16d870;
        default: break;
    }

    ctx->pc = 0x16d6e8u;

    // 0x16d6e8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x16d6e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x16d6ec: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16d6ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16d6f0: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x16d6f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d6f4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16d6f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16d6f8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16d6f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16d6fc: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x16d6fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x16d700: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x16d700u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d704: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x16d704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x16d708: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x16d708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x16d70c: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x16d70cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d710: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x16d710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x16d714: 0xe0f02d  daddu       $fp, $a3, $zero
    ctx->pc = 0x16d714u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d718: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16d718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16d71c: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x16d71cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x16d720: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x16d720u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x16d724: 0x8e931b30  lw          $s3, 0x1B30($s4)
    ctx->pc = 0x16d724u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 6960)));
    // 0x16d728: 0x8e760000  lw          $s6, 0x0($s3)
    ctx->pc = 0x16d728u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x16d72c: 0x2662093c  addiu       $v0, $s3, 0x93C
    ctx->pc = 0x16d72cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2364));
    // 0x16d730: 0x8c460008  lw          $a2, 0x8($v0)
    ctx->pc = 0x16d730u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x16d734: 0x2675008c  addiu       $s5, $s3, 0x8C
    ctx->pc = 0x16d734u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 19), 140));
    // 0x16d738: 0x8c45000c  lw          $a1, 0xC($v0)
    ctx->pc = 0x16d738u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x16d73c: 0xc056538  jal         func_1594E0
    ctx->pc = 0x16D73Cu;
    SET_GPR_U32(ctx, 31, 0x16D744u);
    ctx->pc = 0x16D740u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D73Cu;
            // 0x16d740: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1594E0u;
    if (runtime->hasFunction(0x1594E0u)) {
        auto targetFn = runtime->lookupFunction(0x1594E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D744u; }
        if (ctx->pc != 0x16D744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001594E0_0x1594e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D744u; }
        if (ctx->pc != 0x16D744u) { return; }
    }
    ctx->pc = 0x16D744u;
label_16d744:
    // 0x16d744: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d744u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d748: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16d748u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16d74c: 0xc04fffa  jal         func_13FFE8
    ctx->pc = 0x16D74Cu;
    SET_GPR_U32(ctx, 31, 0x16D754u);
    ctx->pc = 0x16D750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D74Cu;
            // 0x16d750: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFE8u;
    if (runtime->hasFunction(0x13FFE8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D754u; }
        if (ctx->pc != 0x16D754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFE8_0x13ffe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D754u; }
        if (ctx->pc != 0x16D754u) { return; }
    }
    ctx->pc = 0x16D754u;
label_16d754:
    // 0x16d754: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x16d754u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d758: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x16d758u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d75c: 0xc056548  jal         func_159520
    ctx->pc = 0x16D75Cu;
    SET_GPR_U32(ctx, 31, 0x16D764u);
    ctx->pc = 0x16D760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D75Cu;
            // 0x16d760: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159520u;
    if (runtime->hasFunction(0x159520u)) {
        auto targetFn = runtime->lookupFunction(0x159520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D764u; }
        if (ctx->pc != 0x16D764u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159520_0x159520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D764u; }
        if (ctx->pc != 0x16D764u) { return; }
    }
    ctx->pc = 0x16D764u;
label_16d764:
    // 0x16d764: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d764u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d768: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16d768u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d76c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16d76cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16d770: 0xc04fffa  jal         func_13FFE8
    ctx->pc = 0x16D770u;
    SET_GPR_U32(ctx, 31, 0x16D778u);
    ctx->pc = 0x16D774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D770u;
            // 0x16d774: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFE8u;
    if (runtime->hasFunction(0x13FFE8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D778u; }
        if (ctx->pc != 0x16D778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFE8_0x13ffe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D778u; }
        if (ctx->pc != 0x16D778u) { return; }
    }
    ctx->pc = 0x16D778u;
label_16d778:
    // 0x16d778: 0x528023  subu        $s0, $v0, $s2
    ctx->pc = 0x16d778u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x16d77c: 0x3c07ff00  lui         $a3, 0xFF00
    ctx->pc = 0x16d77cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)65280 << 16));
    // 0x16d780: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16d780u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d784: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x16d784u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d788: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16d788u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d78c: 0xc05b592  jal         func_16D648
    ctx->pc = 0x16D78Cu;
    SET_GPR_U32(ctx, 31, 0x16D794u);
    ctx->pc = 0x16D790u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D78Cu;
            // 0x16d790: 0x34e70f04  ori         $a3, $a3, 0xF04 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)3844);
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D648u;
    if (runtime->hasFunction(0x16D648u)) {
        auto targetFn = runtime->lookupFunction(0x16D648u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D794u; }
        if (ctx->pc != 0x16D794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D648_0x16d648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D794u; }
        if (ctx->pc != 0x16D794u) { return; }
    }
    ctx->pc = 0x16D794u;
label_16d794:
    // 0x16d794: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16d794u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d798: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x16d798u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d79c: 0xc05b572  jal         func_16D5C8
    ctx->pc = 0x16D79Cu;
    SET_GPR_U32(ctx, 31, 0x16D7A4u);
    ctx->pc = 0x16D7A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D79Cu;
            // 0x16d7a0: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D5C8u;
    if (runtime->hasFunction(0x16D5C8u)) {
        auto targetFn = runtime->lookupFunction(0x16D5C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D7A4u; }
        if (ctx->pc != 0x16D7A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D5C8_0x16d5c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D7A4u; }
        if (ctx->pc != 0x16D7A4u) { return; }
    }
    ctx->pc = 0x16D7A4u;
label_16d7a4:
    // 0x16d7a4: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x16d7a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d7a8: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x16d7a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d7ac: 0x2666094c  addiu       $a2, $s3, 0x94C
    ctx->pc = 0x16d7acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 2380));
    // 0x16d7b0: 0x1620002f  bnez        $s1, . + 4 + (0x2F << 2)
    ctx->pc = 0x16D7B0u;
    {
        const bool branch_taken_0x16d7b0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x16D7B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D7B0u;
            // 0x16d7b4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d7b0) {
            ctx->pc = 0x16D870u;
            goto label_16d870;
        }
    }
    ctx->pc = 0x16D7B8u;
    // 0x16d7b8: 0xc05653e  jal         func_1594F8
    ctx->pc = 0x16D7B8u;
    SET_GPR_U32(ctx, 31, 0x16D7C0u);
    ctx->pc = 0x1594F8u;
    if (runtime->hasFunction(0x1594F8u)) {
        auto targetFn = runtime->lookupFunction(0x1594F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D7C0u; }
        if (ctx->pc != 0x16D7C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001594F8_0x1594f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D7C0u; }
        if (ctx->pc != 0x16D7C0u) { return; }
    }
    ctx->pc = 0x16D7C0u;
label_16d7c0:
    // 0x16d7c0: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x16d7c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d7c4: 0xc05647a  jal         func_1591E8
    ctx->pc = 0x16D7C4u;
    SET_GPR_U32(ctx, 31, 0x16D7CCu);
    ctx->pc = 0x16D7C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D7C4u;
            // 0x16d7c8: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1591E8u;
    if (runtime->hasFunction(0x1591E8u)) {
        auto targetFn = runtime->lookupFunction(0x1591E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D7CCu; }
        if (ctx->pc != 0x16D7CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001591E8_0x1591e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D7CCu; }
        if (ctx->pc != 0x16D7CCu) { return; }
    }
    ctx->pc = 0x16D7CCu;
label_16d7cc:
    // 0x16d7cc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16d7ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d7d0: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16d7d0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16d7d4: 0x2e0302d  daddu       $a2, $s7, $zero
    ctx->pc = 0x16d7d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d7d8: 0x34a50f05  ori         $a1, $a1, 0xF05
    ctx->pc = 0x16d7d8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3845);
    // 0x16d7dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16D7DCu;
    {
        const bool branch_taken_0x16d7dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D7E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D7DCu;
            // 0x16d7e0: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d7dc) {
            ctx->pc = 0x16D7F8u;
            goto label_16d7f8;
        }
    }
    ctx->pc = 0x16D7E4u;
    // 0x16d7e4: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16D7E4u;
    SET_GPR_U32(ctx, 31, 0x16D7ECu);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D7ECu; }
        if (ctx->pc != 0x16D7ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D7ECu; }
        if (ctx->pc != 0x16D7ECu) { return; }
    }
    ctx->pc = 0x16D7ECu;
label_16d7ec:
    // 0x16d7ec: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x16D7ECu;
    {
        const bool branch_taken_0x16d7ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D7F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D7ECu;
            // 0x16d7f0: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d7ec) {
            ctx->pc = 0x16D874u;
            goto label_16d874;
        }
    }
    ctx->pc = 0x16D7F4u;
    // 0x16d7f4: 0x0  nop
    ctx->pc = 0x16d7f4u;
    // NOP
label_16d7f8:
    // 0x16d7f8: 0x8ea30030  lw          $v1, 0x30($s5)
    ctx->pc = 0x16d7f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 48)));
    // 0x16d7fc: 0x8e6200e0  lw          $v0, 0xE0($s3)
    ctx->pc = 0x16d7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 224)));
    // 0x16d800: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D800u;
    {
        const bool branch_taken_0x16d800 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x16D804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D800u;
            // 0x16d804: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d800) {
            ctx->pc = 0x16D818u;
            goto label_16d818;
        }
    }
    ctx->pc = 0x16D808u;
    // 0x16d808: 0xae6300e0  sw          $v1, 0xE0($s3)
    ctx->pc = 0x16d808u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 224), GPR_U32(ctx, 3));
    // 0x16d80c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16D80Cu;
    {
        const bool branch_taken_0x16d80c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D80Cu;
            // 0x16d810: 0xae6200e4  sw          $v0, 0xE4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 228), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d80c) {
            ctx->pc = 0x16D81Cu;
            goto label_16d81c;
        }
    }
    ctx->pc = 0x16D814u;
    // 0x16d814: 0x0  nop
    ctx->pc = 0x16d814u;
    // NOP
label_16d818:
    // 0x16d818: 0xae6000e4  sw          $zero, 0xE4($s3)
    ctx->pc = 0x16d818u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 228), GPR_U32(ctx, 0));
label_16d81c:
    // 0x16d81c: 0x8e6800e4  lw          $t0, 0xE4($s3)
    ctx->pc = 0x16d81cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 228)));
    // 0x16d820: 0xc05b628  jal         func_16D8A0
    ctx->pc = 0x16D820u;
    SET_GPR_U32(ctx, 31, 0x16D828u);
    ctx->pc = 0x16D824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D820u;
            // 0x16d824: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D8A0u;
    if (runtime->hasFunction(0x16D8A0u)) {
        auto targetFn = runtime->lookupFunction(0x16D8A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D828u; }
        if (ctx->pc != 0x16D828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D8A0_0x16d8a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D828u; }
        if (ctx->pc != 0x16D828u) { return; }
    }
    ctx->pc = 0x16D828u;
label_16d828:
    // 0x16d828: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16d828u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d82c: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x16d82cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d830: 0x13c0000f  beqz        $fp, . + 4 + (0xF << 2)
    ctx->pc = 0x16D830u;
    {
        const bool branch_taken_0x16d830 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D830u;
            // 0x16d834: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d830) {
            ctx->pc = 0x16D870u;
            goto label_16d870;
        }
    }
    ctx->pc = 0x16D838u;
    // 0x16d838: 0x8e6700e4  lw          $a3, 0xE4($s3)
    ctx->pc = 0x16d838u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 228)));
    // 0x16d83c: 0xc05b6c8  jal         func_16DB20
    ctx->pc = 0x16D83Cu;
    SET_GPR_U32(ctx, 31, 0x16D844u);
    ctx->pc = 0x16D840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D83Cu;
            // 0x16d840: 0x8fa60000  lw          $a2, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16DB20u;
    if (runtime->hasFunction(0x16DB20u)) {
        auto targetFn = runtime->lookupFunction(0x16DB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D844u; }
        if (ctx->pc != 0x16D844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016DB20_0x16db20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D844u; }
        if (ctx->pc != 0x16D844u) { return; }
    }
    ctx->pc = 0x16D844u;
label_16d844:
    // 0x16d844: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16d844u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d848: 0xc05b80e  jal         func_16E038
    ctx->pc = 0x16D848u;
    SET_GPR_U32(ctx, 31, 0x16D850u);
    ctx->pc = 0x16D84Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D848u;
            // 0x16d84c: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E038u;
    if (runtime->hasFunction(0x16E038u)) {
        auto targetFn = runtime->lookupFunction(0x16E038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D850u; }
        if (ctx->pc != 0x16D850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E038_0x16e038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D850u; }
        if (ctx->pc != 0x16D850u) { return; }
    }
    ctx->pc = 0x16D850u;
label_16d850:
    // 0x16d850: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16d850u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d854: 0xc05b838  jal         func_16E0E0
    ctx->pc = 0x16D854u;
    SET_GPR_U32(ctx, 31, 0x16D85Cu);
    ctx->pc = 0x16D858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D854u;
            // 0x16d858: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E0E0u;
    if (runtime->hasFunction(0x16E0E0u)) {
        auto targetFn = runtime->lookupFunction(0x16E0E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D85Cu; }
        if (ctx->pc != 0x16D85Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E0E0_0x16e0e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D85Cu; }
        if (ctx->pc != 0x16D85Cu) { return; }
    }
    ctx->pc = 0x16D85Cu;
label_16d85c:
    // 0x16d85c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16d85cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d860: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x16d860u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d864: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x16d864u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d868: 0xc05b88c  jal         func_16E230
    ctx->pc = 0x16D868u;
    SET_GPR_U32(ctx, 31, 0x16D870u);
    ctx->pc = 0x16D86Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D868u;
            // 0x16d86c: 0x2e0382d  daddu       $a3, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E230u;
    if (runtime->hasFunction(0x16E230u)) {
        auto targetFn = runtime->lookupFunction(0x16E230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D870u; }
        if (ctx->pc != 0x16D870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E230_0x16e230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D870u; }
        if (ctx->pc != 0x16D870u) { return; }
    }
    ctx->pc = 0x16D870u;
label_16d870:
    // 0x16d870: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16d870u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16d874:
    // 0x16d874: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16d874u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16d878: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16d878u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16d87c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16d87cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16d880: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16d880u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16d884: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x16d884u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16d888: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x16d888u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16d88c: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x16d88cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16d890: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x16d890u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x16d894: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x16d894u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x16d898: 0x3e00008  jr          $ra
    ctx->pc = 0x16D898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D89Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D898u;
            // 0x16d89c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D744u: goto label_16d744;
            case 0x16D754u: goto label_16d754;
            case 0x16D764u: goto label_16d764;
            case 0x16D778u: goto label_16d778;
            case 0x16D794u: goto label_16d794;
            case 0x16D7A4u: goto label_16d7a4;
            case 0x16D7C0u: goto label_16d7c0;
            case 0x16D7CCu: goto label_16d7cc;
            case 0x16D7ECu: goto label_16d7ec;
            case 0x16D7F8u: goto label_16d7f8;
            case 0x16D818u: goto label_16d818;
            case 0x16D81Cu: goto label_16d81c;
            case 0x16D828u: goto label_16d828;
            case 0x16D844u: goto label_16d844;
            case 0x16D850u: goto label_16d850;
            case 0x16D85Cu: goto label_16d85c;
            case 0x16D870u: goto label_16d870;
            case 0x16D874u: goto label_16d874;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D8A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
