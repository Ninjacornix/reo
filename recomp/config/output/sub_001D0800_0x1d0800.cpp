#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D0800
// Address: 0x1d0800 - 0x1d0914
void sub_001D0800_0x1d0800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D0800_0x1d0800");
#endif

    switch (ctx->pc) {
        case 0x1d0840u: goto label_1d0840;
        case 0x1d0858u: goto label_1d0858;
        case 0x1d0860u: goto label_1d0860;
        case 0x1d089cu: goto label_1d089c;
        case 0x1d08e4u: goto label_1d08e4;
        case 0x1d08f8u: goto label_1d08f8;
        default: break;
    }

    ctx->pc = 0x1d0800u;

    // 0x1d0800: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d0800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d0804: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d0804u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0808: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d0808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d080c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d080cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d0810: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d0810u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d0814: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1d0814u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0818: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0818u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d081c: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1d081cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0820: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0820u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0824: 0x30d000ff  andi        $s0, $a2, 0xFF
    ctx->pc = 0x1d0824u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1d0828: 0x16020007  bne         $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D0828u;
    {
        const bool branch_taken_0x1d0828 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D082Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0828u;
            // 0x1d082c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0828) {
            ctx->pc = 0x1D0848u;
            goto label_1d0848;
        }
    }
    ctx->pc = 0x1D0830u;
    // 0x1d0830: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0830u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0834: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d0834u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d0838: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0838u;
    SET_GPR_U32(ctx, 31, 0x1D0840u);
    ctx->pc = 0x1D083Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0838u;
            // 0x1d083c: 0x24441600  addiu       $a0, $v0, 0x1600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 5632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0840u; }
        if (ctx->pc != 0x1D0840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0840u; }
        if (ctx->pc != 0x1D0840u) { return; }
    }
    ctx->pc = 0x1D0840u;
label_1d0840:
    // 0x1d0840: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D0840u;
    {
        const bool branch_taken_0x1d0840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0840) {
            ctx->pc = 0x1D0858u;
            goto label_1d0858;
        }
    }
    ctx->pc = 0x1D0848u;
label_1d0848:
    // 0x1d0848: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0848u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d084c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d084cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d0850: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0850u;
    SET_GPR_U32(ctx, 31, 0x1D0858u);
    ctx->pc = 0x1D0854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0850u;
            // 0x1d0854: 0x24441400  addiu       $a0, $v0, 0x1400 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 5120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0858u; }
        if (ctx->pc != 0x1D0858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0858u; }
        if (ctx->pc != 0x1D0858u) { return; }
    }
    ctx->pc = 0x1D0858u;
label_1d0858:
    // 0x1d0858: 0xc0740e8  jal         func_1D03A0
    ctx->pc = 0x1D0858u;
    SET_GPR_U32(ctx, 31, 0x1D0860u);
    ctx->pc = 0x1D03A0u;
    if (runtime->hasFunction(0x1D03A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D03A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0860u; }
        if (ctx->pc != 0x1D0860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D03A0_0x1d03a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0860u; }
        if (ctx->pc != 0x1D0860u) { return; }
    }
    ctx->pc = 0x1D0860u;
label_1d0860:
    // 0x1d0860: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d0860u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0864: 0x16020002  bne         $s0, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D0864u;
    {
        const bool branch_taken_0x1d0864 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D0868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0864u;
            // 0x1d0868: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0864) {
            ctx->pc = 0x1D0870u;
            goto label_1d0870;
        }
    }
    ctx->pc = 0x1D086Cu;
    // 0x1d086c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1d086cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1d0870:
    // 0x1d0870: 0x326200ff  andi        $v0, $s3, 0xFF
    ctx->pc = 0x1d0870u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d0874: 0x322400ff  andi        $a0, $s1, 0xFF
    ctx->pc = 0x1d0874u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0878: 0x24031468  addiu       $v1, $zero, 0x1468
    ctx->pc = 0x1d0878u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5224));
    // 0x1d087c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1d087cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1d0880: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1d0880u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d0884: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x1d0884u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1d0888: 0x3c020042  lui         $v0, 0x42
    ctx->pc = 0x1d0888u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)66 << 16));
    // 0x1d088c: 0x24421ef0  addiu       $v0, $v0, 0x1EF0
    ctx->pc = 0x1d088cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7920));
    // 0x1d0890: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x1d0890u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d0894: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D0894u;
    SET_GPR_U32(ctx, 31, 0x1D089Cu);
    ctx->pc = 0x1D0898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0894u;
            // 0x1d0898: 0x438821  addu        $s1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D089Cu; }
        if (ctx->pc != 0x1D089Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D089Cu; }
        if (ctx->pc != 0x1D089Cu) { return; }
    }
    ctx->pc = 0x1D089Cu;
label_1d089c:
    // 0x1d089c: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1d089cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1d08a0: 0x26220820  addiu       $v0, $s1, 0x820
    ctx->pc = 0x1d08a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 2080));
    // 0x1d08a4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d08a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d08a8: 0x26220a20  addiu       $v0, $s1, 0xA20
    ctx->pc = 0x1d08a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 2592));
    // 0x1d08ac: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1d08acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1d08b0: 0x26220c20  addiu       $v0, $s1, 0xC20
    ctx->pc = 0x1d08b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 3104));
    // 0x1d08b4: 0xae220818  sw          $v0, 0x818($s1)
    ctx->pc = 0x1d08b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 2));
    // 0x1d08b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d08b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d08bc: 0x12020002  beq         $s0, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D08BCu;
    {
        const bool branch_taken_0x1d08bc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D08C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D08BCu;
            // 0x1d08c0: 0x326500ff  andi        $a1, $s3, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d08bc) {
            ctx->pc = 0x1D08C8u;
            goto label_1d08c8;
        }
    }
    ctx->pc = 0x1D08C4u;
    // 0x1d08c4: 0x641200ff  daddiu      $s2, $zero, 0xFF
    ctx->pc = 0x1d08c4u;
    SET_GPR_S64(ctx, 18, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)255);
label_1d08c8:
    // 0x1d08c8: 0x124e3c  dsll32      $t1, $s2, 24
    ctx->pc = 0x1d08c8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 18) << (32 + 24));
    // 0x1d08cc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d08ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d08d0: 0x94e3f  dsra32      $t1, $t1, 24
    ctx->pc = 0x1d08d0u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 24));
    // 0x1d08d4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1d08d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d08d8: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x1d08d8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d08dc: 0xc073cc0  jal         func_1CF300
    ctx->pc = 0x1D08DCu;
    SET_GPR_U32(ctx, 31, 0x1D08E4u);
    ctx->pc = 0x1D08E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D08DCu;
            // 0x1d08e0: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF300u;
    if (runtime->hasFunction(0x1CF300u)) {
        auto targetFn = runtime->lookupFunction(0x1CF300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D08E4u; }
        if (ctx->pc != 0x1D08E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF300_0x1cf300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D08E4u; }
        if (ctx->pc != 0x1D08E4u) { return; }
    }
    ctx->pc = 0x1D08E4u;
label_1d08e4:
    // 0x1d08e4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d08e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d08e8: 0x16030003  bne         $s0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D08E8u;
    {
        const bool branch_taken_0x1d08e8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D08ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D08E8u;
            // 0x1d08ec: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d08e8) {
            ctx->pc = 0x1D08F8u;
            goto label_1d08f8;
        }
    }
    ctx->pc = 0x1D08F0u;
    // 0x1d08f0: 0xc0741b8  jal         func_1D06E0
    ctx->pc = 0x1D08F0u;
    SET_GPR_U32(ctx, 31, 0x1D08F8u);
    ctx->pc = 0x1D08F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D08F0u;
            // 0x1d08f4: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D06E0u;
    if (runtime->hasFunction(0x1D06E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D06E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D08F8u; }
        if (ctx->pc != 0x1D08F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D06E0_0x1d06e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D08F8u; }
        if (ctx->pc != 0x1D08F8u) { return; }
    }
    ctx->pc = 0x1D08F8u;
label_1d08f8:
    // 0x1d08f8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d08f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d08fc: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d08fcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d0900: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d0900u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d0904: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0904u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0908: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0908u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d090c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D090Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D090Cu;
            // 0x1d0910: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0914u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
