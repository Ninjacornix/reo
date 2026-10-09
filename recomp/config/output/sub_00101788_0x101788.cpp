#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101788
// Address: 0x101788 - 0x101968
void sub_00101788_0x101788(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101788_0x101788");
#endif

    switch (ctx->pc) {
        case 0x1017d8u: goto label_1017d8;
        case 0x1017ecu: goto label_1017ec;
        case 0x101884u: goto label_101884;
        case 0x101898u: goto label_101898;
        case 0x1018a4u: goto label_1018a4;
        case 0x1018b0u: goto label_1018b0;
        case 0x1018c4u: goto label_1018c4;
        case 0x101908u: goto label_101908;
        case 0x101924u: goto label_101924;
        case 0x101940u: goto label_101940;
        default: break;
    }

    ctx->pc = 0x101788u;

    // 0x101788: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x101788u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x10178c: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x10178cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x101790: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x101790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x101794: 0x3c150020  lui         $s5, 0x20
    ctx->pc = 0x101794u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)32 << 16));
    // 0x101798: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x101798u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x10179c: 0x8ea27938  lw          $v0, 0x7938($s5)
    ctx->pc = 0x10179cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 31032)));
    // 0x1017a0: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1017a0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1017a4: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1017a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1017a8: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1017a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1017ac: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1017acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1017b0: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1017b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1017b4: 0x24727a00  addiu       $s2, $v1, 0x7A00
    ctx->pc = 0x1017b4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 31232));
    // 0x1017b8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1017b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1017bc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1017bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1017c0: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1017c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1017c4: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1017c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1017c8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1017C8u;
    {
        const bool branch_taken_0x1017c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1017CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1017C8u;
            // 0x1017cc: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1017c8) {
            ctx->pc = 0x1017E4u;
            goto label_1017e4;
        }
    }
    ctx->pc = 0x1017D0u;
    // 0x1017d0: 0xc040338  jal         func_100CE0
    ctx->pc = 0x1017D0u;
    SET_GPR_U32(ctx, 31, 0x1017D8u);
    ctx->pc = 0x100CE0u;
    if (runtime->hasFunction(0x100CE0u)) {
        auto targetFn = runtime->lookupFunction(0x100CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1017D8u; }
        if (ctx->pc != 0x1017D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100CE0_0x100ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1017D8u; }
        if (ctx->pc != 0x1017D8u) { return; }
    }
    ctx->pc = 0x1017D8u;
label_1017d8:
    // 0x1017d8: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1017d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1017dc: 0x10430059  beq         $v0, $v1, . + 4 + (0x59 << 2)
    ctx->pc = 0x1017DCu;
    {
        const bool branch_taken_0x1017dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1017E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1017DCu;
            // 0x1017e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1017dc) {
            ctx->pc = 0x101944u;
            goto label_101944;
        }
    }
    ctx->pc = 0x1017E4u;
label_1017e4:
    // 0x1017e4: 0xc0402dc  jal         func_100B70
    ctx->pc = 0x1017E4u;
    SET_GPR_U32(ctx, 31, 0x1017ECu);
    ctx->pc = 0x1017E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1017E4u;
            // 0x1017e8: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100B70u;
    if (runtime->hasFunction(0x100B70u)) {
        auto targetFn = runtime->lookupFunction(0x100B70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1017ECu; }
        if (ctx->pc != 0x1017ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100B70_0x100b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1017ECu; }
        if (ctx->pc != 0x1017ECu) { return; }
    }
    ctx->pc = 0x1017ECu;
label_1017ec:
    // 0x1017ec: 0x1040004d  beqz        $v0, . + 4 + (0x4D << 2)
    ctx->pc = 0x1017ECu;
    {
        const bool branch_taken_0x1017ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1017F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1017ECu;
            // 0x1017f0: 0x3c080021  lui         $t0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1017ec) {
            ctx->pc = 0x101924u;
            goto label_101924;
        }
    }
    ctx->pc = 0x1017F4u;
    // 0x1017f4: 0xae530000  sw          $s3, 0x0($s2)
    ctx->pc = 0x1017f4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 19));
    // 0x1017f8: 0xae510004  sw          $s1, 0x4($s2)
    ctx->pc = 0x1017f8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 17));
    // 0x1017fc: 0x3c130021  lui         $s3, 0x21
    ctx->pc = 0x1017fcu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)33 << 16));
    // 0x101800: 0xae540008  sw          $s4, 0x8($s2)
    ctx->pc = 0x101800u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 20));
    // 0x101804: 0x26648a00  addiu       $a0, $s3, -0x7600
    ctx->pc = 0x101804u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294937088));
    // 0x101808: 0x25058ac0  addiu       $a1, $t0, -0x7540
    ctx->pc = 0x101808u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), 4294937280));
    // 0x10180c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x10180cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101810: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x101810u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x101814: 0xa242000c  sb          $v0, 0xC($s2)
    ctx->pc = 0x101814u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
    // 0x101818: 0x92030001  lbu         $v1, 0x1($s0)
    ctx->pc = 0x101818u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x10181c: 0xa243000d  sb          $v1, 0xD($s2)
    ctx->pc = 0x10181cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x101820: 0x92020002  lbu         $v0, 0x2($s0)
    ctx->pc = 0x101820u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x101824: 0xae440010  sw          $a0, 0x10($s2)
    ctx->pc = 0x101824u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 4));
    // 0x101828: 0xa242000e  sb          $v0, 0xE($s2)
    ctx->pc = 0x101828u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 14), (uint8_t)GPR_U32(ctx, 2));
    // 0x10182c: 0xae450014  sw          $a1, 0x14($s2)
    ctx->pc = 0x10182cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 5));
    // 0x101830: 0x92070002  lbu         $a3, 0x2($s0)
    ctx->pc = 0x101830u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x101834: 0x10e60008  beq         $a3, $a2, . + 4 + (0x8 << 2)
    ctx->pc = 0x101834u;
    {
        const bool branch_taken_0x101834 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 6));
        ctx->pc = 0x101838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101834u;
            // 0x101838: 0x28e20002  slti        $v0, $a3, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101834) {
            ctx->pc = 0x101858u;
            goto label_101858;
        }
    }
    ctx->pc = 0x10183Cu;
    // 0x10183c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10183Cu;
    {
        const bool branch_taken_0x10183c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x101840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10183Cu;
            // 0x101840: 0x112ac0  sll         $a1, $s1, 11 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 17), 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10183c) {
            ctx->pc = 0x101868u;
            goto label_101868;
        }
    }
    ctx->pc = 0x101844u;
    // 0x101844: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x101844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x101848: 0x10e20006  beq         $a3, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x101848u;
    {
        const bool branch_taken_0x101848 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x10184Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101848u;
            // 0x10184c: 0x24020924  addiu       $v0, $zero, 0x924 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2340));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101848) {
            ctx->pc = 0x101864u;
            goto label_101864;
        }
    }
    ctx->pc = 0x101850u;
    // 0x101850: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x101850u;
    {
        const bool branch_taken_0x101850 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x101850) {
            ctx->pc = 0x101868u;
            goto label_101868;
        }
    }
    ctx->pc = 0x101858u;
label_101858:
    // 0x101858: 0x24020918  addiu       $v0, $zero, 0x918
    ctx->pc = 0x101858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2328));
    // 0x10185c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10185Cu;
    {
        const bool branch_taken_0x10185c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10185Cu;
            // 0x101860: 0x2222818  mult        $a1, $s1, $v0 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x10185c) {
            ctx->pc = 0x101868u;
            goto label_101868;
        }
    }
    ctx->pc = 0x101864u;
label_101864:
    // 0x101864: 0x2222818  mult        $a1, $s1, $v0
    ctx->pc = 0x101864u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
label_101868:
    // 0x101868: 0x8ea27938  lw          $v0, 0x7938($s5)
    ctx->pc = 0x101868u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 31032)));
    // 0x10186c: 0x25108ac0  addiu       $s0, $t0, -0x7540
    ctx->pc = 0x10186cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 8), 4294937280));
    // 0x101870: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x101870u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x101874: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101874u;
    {
        const bool branch_taken_0x101874 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x101878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101874u;
            // 0x101878: 0xad008ac0  sw          $zero, -0x7540($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 4294937280), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101874) {
            ctx->pc = 0x101884u;
            goto label_101884;
        }
    }
    ctx->pc = 0x10187Cu;
    // 0x10187c: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x10187Cu;
    SET_GPR_U32(ctx, 31, 0x101884u);
    ctx->pc = 0x101880u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10187Cu;
            // 0x101880: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101884u; }
        if (ctx->pc != 0x101884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101884u; }
        if (ctx->pc != 0x101884u) { return; }
    }
    ctx->pc = 0x101884u;
label_101884:
    // 0x101884: 0x26738a00  addiu       $s3, $s3, -0x7600
    ctx->pc = 0x101884u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294937088));
    // 0x101888: 0x24050090  addiu       $a1, $zero, 0x90
    ctx->pc = 0x101888u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
    // 0x10188c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10188cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101890: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x101890u;
    SET_GPR_U32(ctx, 31, 0x101898u);
    ctx->pc = 0x101894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101890u;
            // 0x101894: 0x3c140020  lui         $s4, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101898u; }
        if (ctx->pc != 0x101898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101898u; }
        if (ctx->pc != 0x101898u) { return; }
    }
    ctx->pc = 0x101898u;
label_101898:
    // 0x101898: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x101898u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10189c: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x10189Cu;
    SET_GPR_U32(ctx, 31, 0x1018A4u);
    ctx->pc = 0x1018A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10189Cu;
            // 0x1018a0: 0x24050018  addiu       $a1, $zero, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018A4u; }
        if (ctx->pc != 0x1018A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018A4u; }
        if (ctx->pc != 0x1018A4u) { return; }
    }
    ctx->pc = 0x1018A4u;
label_1018a4:
    // 0x1018a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1018a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1018a8: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x1018A8u;
    SET_GPR_U32(ctx, 31, 0x1018B0u);
    ctx->pc = 0x1018ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1018A8u;
            // 0x1018ac: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018B0u; }
        if (ctx->pc != 0x1018B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018B0u; }
        if (ctx->pc != 0x1018B0u) { return; }
    }
    ctx->pc = 0x1018B0u;
label_1018b0:
    // 0x1018b0: 0x8e827910  lw          $v0, 0x7910($s4)
    ctx->pc = 0x1018b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x1018b4: 0x18400003  blez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1018B4u;
    {
        const bool branch_taken_0x1018b4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1018B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1018B4u;
            // 0x1018b8: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1018b4) {
            ctx->pc = 0x1018C4u;
            goto label_1018c4;
        }
    }
    ctx->pc = 0x1018BCu;
    // 0x1018bc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1018BCu;
    SET_GPR_U32(ctx, 31, 0x1018C4u);
    ctx->pc = 0x1018C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1018BCu;
            // 0x1018c0: 0x24847650  addiu       $a0, $a0, 0x7650 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018C4u; }
        if (ctx->pc != 0x1018C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018C4u; }
        if (ctx->pc != 0x1018C4u) { return; }
    }
    ctx->pc = 0x1018C4u;
label_1018c4:
    // 0x1018c4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1018c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1018c8: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x1018c8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x1018cc: 0xae027958  sw          $v0, 0x7958($s0)
    ctx->pc = 0x1018ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 2));
    // 0x1018d0: 0x3c110020  lui         $s1, 0x20
    ctx->pc = 0x1018d0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
    // 0x1018d4: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1018d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1018d8: 0x3c0b0010  lui         $t3, 0x10
    ctx->pc = 0x1018d8u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)16 << 16));
    // 0x1018dc: 0xae227934  sw          $v0, 0x7934($s1)
    ctx->pc = 0x1018dcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 2));
    // 0x1018e0: 0x24848ad0  addiu       $a0, $a0, -0x7530
    ctx->pc = 0x1018e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937296));
    // 0x1018e4: 0xafb30000  sw          $s3, 0x0($sp)
    ctx->pc = 0x1018e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 19));
    // 0x1018e8: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1018e8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1018ec: 0x256b04d8  addiu       $t3, $t3, 0x4D8
    ctx->pc = 0x1018ecu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1240));
    // 0x1018f0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1018f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1018f4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1018f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1018f8: 0x24080018  addiu       $t0, $zero, 0x18
    ctx->pc = 0x1018f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1018fc: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1018fcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101900: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x101900u;
    SET_GPR_U32(ctx, 31, 0x101908u);
    ctx->pc = 0x101904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101900u;
            // 0x101904: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101908u; }
        if (ctx->pc != 0x101908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101908u; }
        if (ctx->pc != 0x101908u) { return; }
    }
    ctx->pc = 0x101908u;
label_101908:
    // 0x101908: 0x4430008  bgezl       $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x101908u;
    {
        const bool branch_taken_0x101908 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x101908) {
            ctx->pc = 0x10190Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x101908u;
            // 0x10190c: 0x8e827910  lw          $v0, 0x7910($s4) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30992)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10192Cu;
            goto label_10192c;
        }
    }
    ctx->pc = 0x101910u;
    // 0x101910: 0xae007958  sw          $zero, 0x7958($s0)
    ctx->pc = 0x101910u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101914: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101914u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101918: 0xae207934  sw          $zero, 0x7934($s1)
    ctx->pc = 0x101918u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 0));
    // 0x10191c: 0xc045190  jal         func_114640
    ctx->pc = 0x10191Cu;
    SET_GPR_U32(ctx, 31, 0x101924u);
    ctx->pc = 0x101920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10191Cu;
            // 0x101920: 0x8c447928  lw          $a0, 0x7928($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31016)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101924u; }
        if (ctx->pc != 0x101924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101924u; }
        if (ctx->pc != 0x101924u) { return; }
    }
    ctx->pc = 0x101924u;
label_101924:
    // 0x101924: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x101924u;
    {
        const bool branch_taken_0x101924 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101924u;
            // 0x101928: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101924) {
            ctx->pc = 0x101944u;
            goto label_101944;
        }
    }
    ctx->pc = 0x10192Cu;
label_10192c:
    // 0x10192c: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10192Cu;
    {
        const bool branch_taken_0x10192c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x101930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10192Cu;
            // 0x101930: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10192c) {
            ctx->pc = 0x101944u;
            goto label_101944;
        }
    }
    ctx->pc = 0x101934u;
    // 0x101934: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x101934u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x101938: 0xc045a12  jal         func_116848
    ctx->pc = 0x101938u;
    SET_GPR_U32(ctx, 31, 0x101940u);
    ctx->pc = 0x10193Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101938u;
            // 0x10193c: 0x24847668  addiu       $a0, $a0, 0x7668 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101940u; }
        if (ctx->pc != 0x101940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101940u; }
        if (ctx->pc != 0x101940u) { return; }
    }
    ctx->pc = 0x101940u;
label_101940:
    // 0x101940: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x101940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_101944:
    // 0x101944: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x101944u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x101948: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x101948u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10194c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x10194cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x101950: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x101950u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x101954: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x101954u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101958: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x101958u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10195c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x10195cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101960: 0x3e00008  jr          $ra
    ctx->pc = 0x101960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101960u;
            // 0x101964: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1017D8u: goto label_1017d8;
            case 0x1017E4u: goto label_1017e4;
            case 0x1017ECu: goto label_1017ec;
            case 0x101858u: goto label_101858;
            case 0x101864u: goto label_101864;
            case 0x101868u: goto label_101868;
            case 0x101884u: goto label_101884;
            case 0x101898u: goto label_101898;
            case 0x1018A4u: goto label_1018a4;
            case 0x1018B0u: goto label_1018b0;
            case 0x1018C4u: goto label_1018c4;
            case 0x101908u: goto label_101908;
            case 0x101924u: goto label_101924;
            case 0x10192Cu: goto label_10192c;
            case 0x101940u: goto label_101940;
            case 0x101944u: goto label_101944;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101968u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
