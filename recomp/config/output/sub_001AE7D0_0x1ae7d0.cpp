#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE7D0
// Address: 0x1ae7d0 - 0x1ae90c
void sub_001AE7D0_0x1ae7d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE7D0_0x1ae7d0");
#endif

    switch (ctx->pc) {
        case 0x1ae810u: goto label_1ae810;
        case 0x1ae840u: goto label_1ae840;
        case 0x1ae868u: goto label_1ae868;
        case 0x1ae870u: goto label_1ae870;
        case 0x1ae894u: goto label_1ae894;
        case 0x1ae8acu: goto label_1ae8ac;
        case 0x1ae8c4u: goto label_1ae8c4;
        case 0x1ae8e4u: goto label_1ae8e4;
        default: break;
    }

    ctx->pc = 0x1ae7d0u;

    // 0x1ae7d0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1ae7d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1ae7d4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1ae7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1ae7d8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1ae7d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1ae7dc: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ae7dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ae7e0: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1ae7e0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae7e4: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ae7e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ae7e8: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1ae7e8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae7ec: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ae7ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ae7f0: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1ae7f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae7f4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ae7f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ae7f8: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1ae7f8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae7fc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ae7fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ae800: 0x16a00006  bnez        $s5, . + 4 + (0x6 << 2)
    ctx->pc = 0x1AE800u;
    {
        const bool branch_taken_0x1ae800 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE800u;
            // 0x1ae804: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae800) {
            ctx->pc = 0x1AE81Cu;
            goto label_1ae81c;
        }
    }
    ctx->pc = 0x1AE808u;
    // 0x1ae808: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1AE808u;
    SET_GPR_U32(ctx, 31, 0x1AE810u);
    ctx->pc = 0x1AE80Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE808u;
            // 0x1ae80c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE810u; }
        if (ctx->pc != 0x1AE810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE810u; }
        if (ctx->pc != 0x1AE810u) { return; }
    }
    ctx->pc = 0x1AE810u;
label_1ae810:
    // 0x1ae810: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1ae810u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae814: 0x6400033  bltz        $s2, . + 4 + (0x33 << 2)
    ctx->pc = 0x1AE814u;
    {
        const bool branch_taken_0x1ae814 = (GPR_S64(ctx, 18) < 0);
        if (branch_taken_0x1ae814) {
            ctx->pc = 0x1AE8E4u;
            goto label_1ae8e4;
        }
    }
    ctx->pc = 0x1AE81Cu;
label_1ae81c:
    // 0x1ae81c: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae81cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae820: 0x162080  sll         $a0, $s6, 2
    ctx->pc = 0x1ae820u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 22), 2));
    // 0x1ae824: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1ae824u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1ae828: 0x648821  addu        $s1, $v1, $a0
    ctx->pc = 0x1ae828u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae82c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1ae82cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae830: 0x1060002c  beqz        $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x1AE830u;
    {
        const bool branch_taken_0x1ae830 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE830u;
            // 0x1ae834: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae830) {
            ctx->pc = 0x1AE8E4u;
            goto label_1ae8e4;
        }
    }
    ctx->pc = 0x1AE838u;
    // 0x1ae838: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AE838u;
    SET_GPR_U32(ctx, 31, 0x1AE840u);
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE840u; }
        if (ctx->pc != 0x1AE840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE840u; }
        if (ctx->pc != 0x1AE840u) { return; }
    }
    ctx->pc = 0x1AE840u;
label_1ae840:
    // 0x1ae840: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x1AE840u;
    {
        const bool branch_taken_0x1ae840 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE840u;
            // 0x1ae844: 0x161840  sll         $v1, $s6, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae840) {
            ctx->pc = 0x1AE8E4u;
            goto label_1ae8e4;
        }
    }
    ctx->pc = 0x1AE848u;
    // 0x1ae848: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae848u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae84c: 0x761821  addu        $v1, $v1, $s6
    ctx->pc = 0x1ae84cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 22)));
    // 0x1ae850: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1ae850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1ae854: 0x380c0  sll         $s0, $v1, 3
    ctx->pc = 0x1ae854u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae858: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ae858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ae85c: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1ae85cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae860: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1AE860u;
    SET_GPR_U32(ctx, 31, 0x1AE868u);
    ctx->pc = 0x1AE864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE860u;
            // 0x1ae864: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE868u; }
        if (ctx->pc != 0x1AE868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE868u; }
        if (ctx->pc != 0x1AE868u) { return; }
    }
    ctx->pc = 0x1AE868u;
label_1ae868:
    // 0x1ae868: 0xc06b9b4  jal         func_1AE6D0
    ctx->pc = 0x1AE868u;
    SET_GPR_U32(ctx, 31, 0x1AE870u);
    ctx->pc = 0x1AE86Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE868u;
            // 0x1ae86c: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE6D0u;
    if (runtime->hasFunction(0x1AE6D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE6D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE870u; }
        if (ctx->pc != 0x1AE870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE6D0_0x1ae6d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE870u; }
        if (ctx->pc != 0x1AE870u) { return; }
    }
    ctx->pc = 0x1AE870u;
label_1ae870:
    // 0x1ae870: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ae870u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ae874: 0x16a2000f  bne         $s5, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1AE874u;
    {
        const bool branch_taken_0x1ae874 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 2));
        if (branch_taken_0x1ae874) {
            ctx->pc = 0x1AE8B4u;
            goto label_1ae8b4;
        }
    }
    ctx->pc = 0x1AE87Cu;
    // 0x1ae87c: 0x6610007  bgez        $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AE87Cu;
    {
        const bool branch_taken_0x1ae87c = (GPR_S64(ctx, 19) >= 0);
        if (branch_taken_0x1ae87c) {
            ctx->pc = 0x1AE89Cu;
            goto label_1ae89c;
        }
    }
    ctx->pc = 0x1AE884u;
    // 0x1ae884: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1ae884u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae888: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1ae888u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae88c: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1AE88Cu;
    SET_GPR_U32(ctx, 31, 0x1AE894u);
    ctx->pc = 0x1AE890u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE88Cu;
            // 0x1ae890: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE894u; }
        if (ctx->pc != 0x1AE894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE894u; }
        if (ctx->pc != 0x1AE894u) { return; }
    }
    ctx->pc = 0x1AE894u;
label_1ae894:
    // 0x1ae894: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1AE894u;
    {
        const bool branch_taken_0x1ae894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae894) {
            ctx->pc = 0x1AE8C4u;
            goto label_1ae8c4;
        }
    }
    ctx->pc = 0x1AE89Cu;
label_1ae89c:
    // 0x1ae89c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1ae89cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae8a0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1ae8a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae8a4: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1AE8A4u;
    SET_GPR_U32(ctx, 31, 0x1AE8ACu);
    ctx->pc = 0x1AE8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE8A4u;
            // 0x1ae8a8: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8ACu; }
        if (ctx->pc != 0x1AE8ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8ACu; }
        if (ctx->pc != 0x1AE8ACu) { return; }
    }
    ctx->pc = 0x1AE8ACu;
label_1ae8ac:
    // 0x1ae8ac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1AE8ACu;
    {
        const bool branch_taken_0x1ae8ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae8ac) {
            ctx->pc = 0x1AE8C4u;
            goto label_1ae8c4;
        }
    }
    ctx->pc = 0x1AE8B4u;
label_1ae8b4:
    // 0x1ae8b4: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1ae8b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae8b8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1ae8b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae8bc: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1AE8BCu;
    SET_GPR_U32(ctx, 31, 0x1AE8C4u);
    ctx->pc = 0x1AE8C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE8BCu;
            // 0x1ae8c0: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8C4u; }
        if (ctx->pc != 0x1AE8C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8C4u; }
        if (ctx->pc != 0x1AE8C4u) { return; }
    }
    ctx->pc = 0x1AE8C4u;
label_1ae8c4:
    // 0x1ae8c4: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae8c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae8c8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ae8c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ae8cc: 0x24428d73  addiu       $v0, $v0, -0x728D
    ctx->pc = 0x1ae8ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937971));
    // 0x1ae8d0: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ae8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ae8d4: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1ae8d4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ae8d8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1ae8d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae8dc: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1AE8DCu;
    SET_GPR_U32(ctx, 31, 0x1AE8E4u);
    ctx->pc = 0x1AE8E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE8DCu;
            // 0x1ae8e0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8E4u; }
        if (ctx->pc != 0x1AE8E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8E4u; }
        if (ctx->pc != 0x1AE8E4u) { return; }
    }
    ctx->pc = 0x1AE8E4u;
label_1ae8e4:
    // 0x1ae8e4: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1ae8e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1ae8e8: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1ae8e8u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ae8ec: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ae8ecu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ae8f0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ae8f0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ae8f4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ae8f4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ae8f8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ae8f8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ae8fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ae8fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae900: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae900u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae904: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE904u;
            // 0x1ae908: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE90Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
