#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD7E0
// Address: 0x1ad7e0 - 0x1ada18
void sub_001AD7E0_0x1ad7e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD7E0_0x1ad7e0");
#endif

    switch (ctx->pc) {
        case 0x1ad82cu: goto label_1ad82c;
        case 0x1ad870u: goto label_1ad870;
        case 0x1ad884u: goto label_1ad884;
        case 0x1ad8a4u: goto label_1ad8a4;
        case 0x1ad8acu: goto label_1ad8ac;
        case 0x1ad8c0u: goto label_1ad8c0;
        case 0x1ad8d8u: goto label_1ad8d8;
        case 0x1ad8e8u: goto label_1ad8e8;
        case 0x1ad910u: goto label_1ad910;
        case 0x1ad924u: goto label_1ad924;
        case 0x1ad940u: goto label_1ad940;
        case 0x1ad9acu: goto label_1ad9ac;
        case 0x1ad9d0u: goto label_1ad9d0;
        default: break;
    }

    ctx->pc = 0x1ad7e0u;

    // 0x1ad7e0: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x1ad7e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1ad7e4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad7e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad7e8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ad7e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ad7ec: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ad7ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ad7f0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ad7f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ad7f4: 0x3c11002b  lui         $s1, 0x2B
    ctx->pc = 0x1ad7f4u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)43 << 16));
    // 0x1ad7f8: 0x90233840  lbu         $v1, 0x3840($at)
    ctx->pc = 0x1ad7f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 14400)));
    // 0x1ad7fc: 0x2c610006  sltiu       $at, $v1, 0x6
    ctx->pc = 0x1ad7fcu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x1ad800: 0x10200080  beqz        $at, . + 4 + (0x80 << 2)
    ctx->pc = 0x1AD800u;
    {
        const bool branch_taken_0x1ad800 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD800u;
            // 0x1ad804: 0x26313840  addiu       $s1, $s1, 0x3840 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 14400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad800) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD808u;
    // 0x1ad808: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1ad808u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1ad80c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1ad80cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1ad810: 0x2484fe00  addiu       $a0, $a0, -0x200
    ctx->pc = 0x1ad810u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966784));
    // 0x1ad814: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1ad814u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ad818: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1ad818u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ad81c: 0x600008  jr          $v1
    ctx->pc = 0x1AD81Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD824u: goto label_1ad824;
            case 0x1AD908u: goto label_1ad908;
            case 0x1AD9A4u: goto label_1ad9a4;
            case 0x1AD9C0u: goto label_1ad9c0;
            case 0x1AD9E4u: goto label_1ad9e4;
            case 0x1ADA04u: goto label_1ada04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD824u;
label_1ad824:
    // 0x1ad824: 0xc06b5e4  jal         func_1AD790
    ctx->pc = 0x1AD824u;
    SET_GPR_U32(ctx, 31, 0x1AD82Cu);
    ctx->pc = 0x1AD828u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD824u;
            // 0x1ad828: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD790u;
    if (runtime->hasFunction(0x1AD790u)) {
        auto targetFn = runtime->lookupFunction(0x1AD790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD82Cu; }
        if (ctx->pc != 0x1AD82Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD790_0x1ad790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD82Cu; }
        if (ctx->pc != 0x1AD82Cu) { return; }
    }
    ctx->pc = 0x1AD82Cu;
label_1ad82c:
    // 0x1ad82c: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1ad82cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1ad830: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x1ad830u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ad834: 0x4600073  bltz        $v1, . + 4 + (0x73 << 2)
    ctx->pc = 0x1AD834u;
    {
        const bool branch_taken_0x1ad834 = (GPR_S64(ctx, 3) < 0);
        if (branch_taken_0x1ad834) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD83Cu;
    // 0x1ad83c: 0x711021  addu        $v0, $v1, $s1
    ctx->pc = 0x1ad83cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1ad840: 0x9050000c  lbu         $s0, 0xC($v0)
    ctx->pc = 0x1ad840u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1ad844: 0x2a01000f  slti        $at, $s0, 0xF
    ctx->pc = 0x1ad844u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)15) ? 1 : 0);
    // 0x1ad848: 0x1020000c  beqz        $at, . + 4 + (0xC << 2)
    ctx->pc = 0x1AD848u;
    {
        const bool branch_taken_0x1ad848 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD84Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD848u;
            // 0x1ad84c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad848) {
            ctx->pc = 0x1AD87Cu;
            goto label_1ad87c;
        }
    }
    ctx->pc = 0x1AD850u;
    // 0x1ad850: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x1ad850u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ad854: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1ad854u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1ad858: 0x8c4500a4  lw          $a1, 0xA4($v0)
    ctx->pc = 0x1ad858u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 164)));
    // 0x1ad85c: 0x10a00006  beqz        $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1AD85Cu;
    {
        const bool branch_taken_0x1ad85c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD85Cu;
            // 0x1ad860: 0x31100  sll         $v0, $v1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad85c) {
            ctx->pc = 0x1AD878u;
            goto label_1ad878;
        }
    }
    ctx->pc = 0x1AD864u;
    // 0x1ad864: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x1ad864u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1ad868: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1AD868u;
    SET_GPR_U32(ctx, 31, 0x1AD870u);
    ctx->pc = 0x1AD86Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD868u;
            // 0x1ad86c: 0x24440024  addiu       $a0, $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD870u; }
        if (ctx->pc != 0x1AD870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD870u; }
        if (ctx->pc != 0x1AD870u) { return; }
    }
    ctx->pc = 0x1AD870u;
label_1ad870:
    // 0x1ad870: 0x10400064  beqz        $v0, . + 4 + (0x64 << 2)
    ctx->pc = 0x1AD870u;
    {
        const bool branch_taken_0x1ad870 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ad870) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD878u;
label_1ad878:
    // 0x1ad878: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ad878u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1ad87c:
    // 0x1ad87c: 0xc06b3a8  jal         func_1ACEA0
    ctx->pc = 0x1AD87Cu;
    SET_GPR_U32(ctx, 31, 0x1AD884u);
    ctx->pc = 0x1ACEA0u;
    if (runtime->hasFunction(0x1ACEA0u)) {
        auto targetFn = runtime->lookupFunction(0x1ACEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD884u; }
        if (ctx->pc != 0x1AD884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACEA0_0x1acea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD884u; }
        if (ctx->pc != 0x1AD884u) { return; }
    }
    ctx->pc = 0x1AD884u;
label_1ad884:
    // 0x1ad884: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1ad884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ad888: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1ad888u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1ad88c: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1ad88cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1ad890: 0x24a5fdf8  addiu       $a1, $a1, -0x208
    ctx->pc = 0x1ad890u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966776));
    // 0x1ad894: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1ad894u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ad898: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x1ad898u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1ad89c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AD89Cu;
    SET_GPR_U32(ctx, 31, 0x1AD8A4u);
    ctx->pc = 0x1AD8A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD89Cu;
            // 0x1ad8a0: 0x24460024  addiu       $a2, $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8A4u; }
        if (ctx->pc != 0x1AD8A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8A4u; }
        if (ctx->pc != 0x1AD8A4u) { return; }
    }
    ctx->pc = 0x1AD8A4u;
label_1ad8a4:
    // 0x1ad8a4: 0xc06acc4  jal         func_1AB310
    ctx->pc = 0x1AD8A4u;
    SET_GPR_U32(ctx, 31, 0x1AD8ACu);
    ctx->pc = 0x1AD8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD8A4u;
            // 0x1ad8a8: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB310u;
    if (runtime->hasFunction(0x1AB310u)) {
        auto targetFn = runtime->lookupFunction(0x1AB310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8ACu; }
        if (ctx->pc != 0x1AD8ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB310_0x1ab310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8ACu; }
        if (ctx->pc != 0x1AD8ACu) { return; }
    }
    ctx->pc = 0x1AD8ACu;
label_1ad8ac:
    // 0x1ad8ac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1ad8acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad8b0: 0x4a00054  bltz        $a1, . + 4 + (0x54 << 2)
    ctx->pc = 0x1AD8B0u;
    {
        const bool branch_taken_0x1ad8b0 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x1AD8B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD8B0u;
            // 0x1ad8b4: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad8b0) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD8B8u;
    // 0x1ad8b8: 0xc04a490  jal         func_129240
    ctx->pc = 0x1AD8B8u;
    SET_GPR_U32(ctx, 31, 0x1AD8C0u);
    ctx->pc = 0x129240u;
    if (runtime->hasFunction(0x129240u)) {
        auto targetFn = runtime->lookupFunction(0x129240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8C0u; }
        if (ctx->pc != 0x1AD8C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129240_0x129240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8C0u; }
        if (ctx->pc != 0x1AD8C0u) { return; }
    }
    ctx->pc = 0x1AD8C0u;
label_1ad8c0:
    // 0x1ad8c0: 0xae220104  sw          $v0, 0x104($s1)
    ctx->pc = 0x1ad8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 260), GPR_U32(ctx, 2));
    // 0x1ad8c4: 0x8e240104  lw          $a0, 0x104($s1)
    ctx->pc = 0x1ad8c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 260)));
    // 0x1ad8c8: 0x1080004e  beqz        $a0, . + 4 + (0x4E << 2)
    ctx->pc = 0x1AD8C8u;
    {
        const bool branch_taken_0x1ad8c8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ad8c8) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD8D0u;
    // 0x1ad8d0: 0xc04a702  jal         func_129C08
    ctx->pc = 0x1AD8D0u;
    SET_GPR_U32(ctx, 31, 0x1AD8D8u);
    ctx->pc = 0x129C08u;
    if (runtime->hasFunction(0x129C08u)) {
        auto targetFn = runtime->lookupFunction(0x129C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8D8u; }
        if (ctx->pc != 0x1AD8D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129C08_0x129c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8D8u; }
        if (ctx->pc != 0x1AD8D8u) { return; }
    }
    ctx->pc = 0x1AD8D8u;
label_1ad8d8:
    // 0x1ad8d8: 0x8e240104  lw          $a0, 0x104($s1)
    ctx->pc = 0x1ad8d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 260)));
    // 0x1ad8dc: 0x8e260008  lw          $a2, 0x8($s1)
    ctx->pc = 0x1ad8dcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1ad8e0: 0xc04a5e8  jal         func_1297A0
    ctx->pc = 0x1AD8E0u;
    SET_GPR_U32(ctx, 31, 0x1AD8E8u);
    ctx->pc = 0x1AD8E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD8E0u;
            // 0x1ad8e4: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297A0u;
    if (runtime->hasFunction(0x1297A0u)) {
        auto targetFn = runtime->lookupFunction(0x1297A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8E8u; }
        if (ctx->pc != 0x1AD8E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD8E8u; }
        if (ctx->pc != 0x1AD8E8u) { return; }
    }
    ctx->pc = 0x1AD8E8u;
label_1ad8e8:
    // 0x1ad8e8: 0x92250000  lbu         $a1, 0x0($s1)
    ctx->pc = 0x1ad8e8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ad8ec: 0x2111821  addu        $v1, $s0, $s1
    ctx->pc = 0x1ad8ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1ad8f0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1ad8f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ad8f4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1ad8f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1ad8f8: 0xa2250000  sb          $a1, 0x0($s1)
    ctx->pc = 0x1ad8f8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1ad8fc: 0xa06400e4  sb          $a0, 0xE4($v1)
    ctx->pc = 0x1ad8fcu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 228), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ad900: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1AD900u;
    {
        const bool branch_taken_0x1ad900 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD900u;
            // 0x1ad904: 0xa06400f4  sb          $a0, 0xF4($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 244), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad900) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD908u;
label_1ad908:
    // 0x1ad908: 0xc04a752  jal         func_129D48
    ctx->pc = 0x1AD908u;
    SET_GPR_U32(ctx, 31, 0x1AD910u);
    ctx->pc = 0x1AD90Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD908u;
            // 0x1ad90c: 0x8e240104  lw          $a0, 0x104($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 260)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129D48u;
    if (runtime->hasFunction(0x129D48u)) {
        auto targetFn = runtime->lookupFunction(0x129D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD910u; }
        if (ctx->pc != 0x1AD910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD910u; }
        if (ctx->pc != 0x1AD910u) { return; }
    }
    ctx->pc = 0x1AD910u;
label_1ad910:
    // 0x1ad910: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1ad910u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ad914: 0x1443003b  bne         $v0, $v1, . + 4 + (0x3B << 2)
    ctx->pc = 0x1AD914u;
    {
        const bool branch_taken_0x1ad914 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1ad914) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD91Cu;
    // 0x1ad91c: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1AD91Cu;
    SET_GPR_U32(ctx, 31, 0x1AD924u);
    ctx->pc = 0x1AD920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD91Cu;
            // 0x1ad920: 0x8e240104  lw          $a0, 0x104($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 260)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD924u; }
        if (ctx->pc != 0x1AD924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD924u; }
        if (ctx->pc != 0x1AD924u) { return; }
    }
    ctx->pc = 0x1AD924u;
label_1ad924:
    // 0x1ad924: 0xae200104  sw          $zero, 0x104($s1)
    ctx->pc = 0x1ad924u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 260), GPR_U32(ctx, 0));
    // 0x1ad928: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1ad928u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ad92c: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x1ad92cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1ad930: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1ad930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1ad934: 0x9050000c  lbu         $s0, 0xC($v0)
    ctx->pc = 0x1ad934u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1ad938: 0xc06b3ec  jal         func_1ACFB0
    ctx->pc = 0x1AD938u;
    SET_GPR_U32(ctx, 31, 0x1AD940u);
    ctx->pc = 0x1AD93Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD938u;
            // 0x1ad93c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACFB0u;
    if (runtime->hasFunction(0x1ACFB0u)) {
        auto targetFn = runtime->lookupFunction(0x1ACFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD940u; }
        if (ctx->pc != 0x1AD940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACFB0_0x1acfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD940u; }
        if (ctx->pc != 0x1AD940u) { return; }
    }
    ctx->pc = 0x1AD940u;
label_1ad940:
    // 0x1ad940: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x1ad940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ad944: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1ad944u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ad948: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1ad948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1ad94c: 0xa4620014  sh          $v0, 0x14($v1)
    ctx->pc = 0x1ad94cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ad950: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1ad950u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ad954: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1ad954u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ad958: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1ad958u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1ad95c: 0x84630014  lh          $v1, 0x14($v1)
    ctx->pc = 0x1ad95cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x1ad960: 0x4610006  bgez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1AD960u;
    {
        const bool branch_taken_0x1ad960 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1AD964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD960u;
            // 0x1ad964: 0x2a010010  slti        $at, $s0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad960) {
            ctx->pc = 0x1AD97Cu;
            goto label_1ad97c;
        }
    }
    ctx->pc = 0x1AD968u;
    // 0x1ad968: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1ad968u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ad96c: 0x2111821  addu        $v1, $s0, $s1
    ctx->pc = 0x1ad96cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1ad970: 0xa2240000  sb          $a0, 0x0($s1)
    ctx->pc = 0x1ad970u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ad974: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1AD974u;
    {
        const bool branch_taken_0x1ad974 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD974u;
            // 0x1ad978: 0xa06000e4  sb          $zero, 0xE4($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 228), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad974) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD97Cu;
label_1ad97c:
    // 0x1ad97c: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1AD97Cu;
    {
        const bool branch_taken_0x1ad97c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD97Cu;
            // 0x1ad980: 0x41900  sll         $v1, $a0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad97c) {
            ctx->pc = 0x1AD998u;
            goto label_1ad998;
        }
    }
    ctx->pc = 0x1AD984u;
    // 0x1ad984: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x1ad984u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ad988: 0x2231821  addu        $v1, $s1, $v1
    ctx->pc = 0x1ad988u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x1ad98c: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1ad98cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1ad990: 0x24630024  addiu       $v1, $v1, 0x24
    ctx->pc = 0x1ad990u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 36));
    // 0x1ad994: 0xac4300a4  sw          $v1, 0xA4($v0)
    ctx->pc = 0x1ad994u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 164), GPR_U32(ctx, 3));
label_1ad998:
    // 0x1ad998: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1ad998u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ad99c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ad99cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ad9a0: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1ad9a0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
label_1ad9a4:
    // 0x1ad9a4: 0xc069fd4  jal         func_1A7F50
    ctx->pc = 0x1AD9A4u;
    SET_GPR_U32(ctx, 31, 0x1AD9ACu);
    ctx->pc = 0x1AD9A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD9A4u;
            // 0x1ad9a8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7F50u;
    if (runtime->hasFunction(0x1A7F50u)) {
        auto targetFn = runtime->lookupFunction(0x1A7F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD9ACu; }
        if (ctx->pc != 0x1AD9ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7F50_0x1a7f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD9ACu; }
        if (ctx->pc != 0x1AD9ACu) { return; }
    }
    ctx->pc = 0x1AD9ACu;
label_1ad9ac:
    // 0x1ad9ac: 0x1c400015  bgtz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1AD9ACu;
    {
        const bool branch_taken_0x1ad9ac = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1ad9ac) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD9B4u;
    // 0x1ad9b4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1ad9b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ad9b8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ad9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ad9bc: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1ad9bcu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
label_1ad9c0:
    // 0x1ad9c0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ad9c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ad9c4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1ad9c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ad9c8: 0xc06a030  jal         func_1A80C0
    ctx->pc = 0x1AD9C8u;
    SET_GPR_U32(ctx, 31, 0x1AD9D0u);
    ctx->pc = 0x1AD9CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD9C8u;
            // 0x1ad9cc: 0x3444000c  ori         $a0, $v0, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A80C0u;
    if (runtime->hasFunction(0x1A80C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A80C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD9D0u; }
        if (ctx->pc != 0x1AD9D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A80C0_0x1a80c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD9D0u; }
        if (ctx->pc != 0x1AD9D0u) { return; }
    }
    ctx->pc = 0x1AD9D0u;
label_1ad9d0:
    // 0x1ad9d0: 0x1c40000c  bgtz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1AD9D0u;
    {
        const bool branch_taken_0x1ad9d0 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1ad9d0) {
            ctx->pc = 0x1ADA04u;
            goto label_1ada04;
        }
    }
    ctx->pc = 0x1AD9D8u;
    // 0x1ad9d8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1ad9d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ad9dc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ad9dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ad9e0: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1ad9e0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
label_1ad9e4:
    // 0x1ad9e4: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1ad9e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ad9e8: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1ad9e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ad9ec: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ad9ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ad9f0: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1ad9f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1ad9f4: 0x9084000c  lbu         $a0, 0xC($a0)
    ctx->pc = 0x1ad9f4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1ad9f8: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1ad9f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1ad9fc: 0xa08500e4  sb          $a1, 0xE4($a0)
    ctx->pc = 0x1ad9fcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 228), (uint8_t)GPR_U32(ctx, 5));
    // 0x1ada00: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1ada00u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
label_1ada04:
    // 0x1ada04: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ada04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ada08: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ada08u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ada0c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ada0cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ada10: 0x3e00008  jr          $ra
    ctx->pc = 0x1ADA10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ADA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADA10u;
            // 0x1ada14: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD824u: goto label_1ad824;
            case 0x1AD82Cu: goto label_1ad82c;
            case 0x1AD870u: goto label_1ad870;
            case 0x1AD878u: goto label_1ad878;
            case 0x1AD87Cu: goto label_1ad87c;
            case 0x1AD884u: goto label_1ad884;
            case 0x1AD8A4u: goto label_1ad8a4;
            case 0x1AD8ACu: goto label_1ad8ac;
            case 0x1AD8C0u: goto label_1ad8c0;
            case 0x1AD8D8u: goto label_1ad8d8;
            case 0x1AD8E8u: goto label_1ad8e8;
            case 0x1AD908u: goto label_1ad908;
            case 0x1AD910u: goto label_1ad910;
            case 0x1AD924u: goto label_1ad924;
            case 0x1AD940u: goto label_1ad940;
            case 0x1AD97Cu: goto label_1ad97c;
            case 0x1AD998u: goto label_1ad998;
            case 0x1AD9A4u: goto label_1ad9a4;
            case 0x1AD9ACu: goto label_1ad9ac;
            case 0x1AD9C0u: goto label_1ad9c0;
            case 0x1AD9D0u: goto label_1ad9d0;
            case 0x1AD9E4u: goto label_1ad9e4;
            case 0x1ADA04u: goto label_1ada04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ADA18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
