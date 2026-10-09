#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112820
// Address: 0x112820 - 0x112b98
void sub_00112820_0x112820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112820_0x112820");
#endif

    switch (ctx->pc) {
        case 0x112874u: goto label_112874;
        case 0x112894u: goto label_112894;
        case 0x1128b0u: goto label_1128b0;
        case 0x112b68u: goto label_112b68;
        default: break;
    }

    ctx->pc = 0x112820u;

    // 0x112820: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x112820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x112824: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x112824u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x112828: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x112828u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x11282c: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x11282cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x112830: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x112830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x112834: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x112834u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x112838: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x112838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x11283c: 0x84400  sll         $t0, $t0, 16
    ctx->pc = 0x11283cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x112840: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x112840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x112844: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x112844u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x112848: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x112848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11284c: 0x5b403  sra         $s6, $a1, 16
    ctx->pc = 0x11284cu;
    SET_GPR_S32(ctx, 22, SRA32(GPR_S32(ctx, 5), 16));
    // 0x112850: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x112850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x112854: 0x79403  sra         $s2, $a3, 16
    ctx->pc = 0x112854u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 7), 16));
    // 0x112858: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x112858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11285c: 0x68403  sra         $s0, $a2, 16
    ctx->pc = 0x11285cu;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 6), 16));
    // 0x112860: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x112860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x112864: 0x8ac03  sra         $s5, $t0, 16
    ctx->pc = 0x112864u;
    SET_GPR_S32(ctx, 21, SRA32(GPR_S32(ctx, 8), 16));
    // 0x112868: 0x9a403  sra         $s4, $t1, 16
    ctx->pc = 0x112868u;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 9), 16));
    // 0x11286c: 0xc0449be  jal         func_1126F8
    ctx->pc = 0x11286Cu;
    SET_GPR_U32(ctx, 31, 0x112874u);
    ctx->pc = 0x112870u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11286Cu;
            // 0x112870: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1126F8u;
    if (runtime->hasFunction(0x1126F8u)) {
        auto targetFn = runtime->lookupFunction(0x1126F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112874u; }
        if (ctx->pc != 0x112874u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112874u; }
        if (ctx->pc != 0x112874u) { return; }
    }
    ctx->pc = 0x112874u;
label_112874:
    // 0x112874: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x112874u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112878: 0x96240002  lhu         $a0, 0x2($s1)
    ctx->pc = 0x112878u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x11287c: 0x2482fffe  addiu       $v0, $a0, -0x2
    ctx->pc = 0x11287cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
    // 0x112880: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x112880u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x112884: 0x5440000e  bnel        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x112884u;
    {
        const bool branch_taken_0x112884 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x112884) {
            ctx->pc = 0x112888u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x112884u;
            // 0x112888: 0xafa0000c  sw          $zero, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1128C0u;
            goto label_1128c0;
        }
    }
    ctx->pc = 0x11288Cu;
    // 0x11288c: 0xc0449dc  jal         func_112770
    ctx->pc = 0x11288Cu;
    SET_GPR_U32(ctx, 31, 0x112894u);
    ctx->pc = 0x112770u;
    if (runtime->hasFunction(0x112770u)) {
        auto targetFn = runtime->lookupFunction(0x112770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112894u; }
        if (ctx->pc != 0x112894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112770_0x112770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112894u; }
        if (ctx->pc != 0x112894u) { return; }
    }
    ctx->pc = 0x112894u;
label_112894:
    // 0x112894: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x112894u;
    {
        const bool branch_taken_0x112894 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x112898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112894u;
            // 0x112898: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112894) {
            ctx->pc = 0x1128B8u;
            goto label_1128b8;
        }
    }
    ctx->pc = 0x11289Cu;
    // 0x11289c: 0x86240002  lh          $a0, 0x2($s1)
    ctx->pc = 0x11289cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1128a0: 0x37a60004  ori         $a2, $sp, 0x4
    ctx->pc = 0x1128a0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)4);
    // 0x1128a4: 0x37a70008  ori         $a3, $sp, 0x8
    ctx->pc = 0x1128a4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)8);
    // 0x1128a8: 0xc044a04  jal         func_112810
    ctx->pc = 0x1128A8u;
    SET_GPR_U32(ctx, 31, 0x1128B0u);
    ctx->pc = 0x1128ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1128A8u;
            // 0x1128ac: 0x37a8000c  ori         $t0, $sp, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)12);
        ctx->in_delay_slot = false;
    ctx->pc = 0x112810u;
    if (runtime->hasFunction(0x112810u)) {
        auto targetFn = runtime->lookupFunction(0x112810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1128B0u; }
        if (ctx->pc != 0x1128B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112810_0x112810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1128B0u; }
        if (ctx->pc != 0x1128B0u) { return; }
    }
    ctx->pc = 0x1128B0u;
label_1128b0:
    // 0x1128b0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1128B0u;
    {
        const bool branch_taken_0x1128b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1128B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1128B0u;
            // 0x1128b4: 0x96240002  lhu         $a0, 0x2($s1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1128b0) {
            ctx->pc = 0x1128CCu;
            goto label_1128cc;
        }
    }
    ctx->pc = 0x1128B8u;
label_1128b8:
    // 0x1128b8: 0x96240002  lhu         $a0, 0x2($s1)
    ctx->pc = 0x1128b8u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1128bc: 0xafa0000c  sw          $zero, 0xC($sp)
    ctx->pc = 0x1128bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
label_1128c0:
    // 0x1128c0: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x1128c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x1128c4: 0xafa00004  sw          $zero, 0x4($sp)
    ctx->pc = 0x1128c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 0));
    // 0x1128c8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1128c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
label_1128cc:
    // 0x1128cc: 0x24030066  addiu       $v1, $zero, 0x66
    ctx->pc = 0x1128ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1128d0: 0x96260000  lhu         $a2, 0x0($s1)
    ctx->pc = 0x1128d0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1128d4: 0xfe630000  sd          $v1, 0x0($s3)
    ctx->pc = 0x1128d4u;
    WRITE64(ADD32(GPR_U32(ctx, 19), 0), GPR_U64(ctx, 3));
    // 0x1128d8: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1128d8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1128dc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1128DCu;
    {
        const bool branch_taken_0x1128dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1128E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1128DCu;
            // 0x1128e0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1128dc) {
            ctx->pc = 0x1128F4u;
            goto label_1128f4;
        }
    }
    ctx->pc = 0x1128E4u;
    // 0x1128e4: 0x86220004  lh          $v0, 0x4($s1)
    ctx->pc = 0x1128e4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1128e8: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1128E8u;
    {
        const bool branch_taken_0x1128e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1128ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1128E8u;
            // 0x1128ec: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1128e8) {
            ctx->pc = 0x1128F4u;
            goto label_1128f4;
        }
    }
    ctx->pc = 0x1128F0u;
    // 0x1128f0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1128f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1128f4:
    // 0x1128f4: 0xfe620008  sd          $v0, 0x8($s3)
    ctx->pc = 0x1128f4u;
    WRITE64(ADD32(GPR_U32(ctx, 19), 8), GPR_U64(ctx, 2));
    // 0x1128f8: 0x2602003f  addiu       $v0, $s0, 0x3F
    ctx->pc = 0x1128f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 63));
    // 0x1128fc: 0x32c3000f  andi        $v1, $s6, 0xF
    ctx->pc = 0x1128fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)15);
    // 0x112900: 0x21183  sra         $v0, $v0, 6
    ctx->pc = 0x112900u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 6));
    // 0x112904: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x112904u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x112908: 0x3042003f  andi        $v0, $v0, 0x3F
    ctx->pc = 0x112908u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    // 0x11290c: 0x31bf8  dsll        $v1, $v1, 15
    ctx->pc = 0x11290cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 15);
    // 0x112910: 0x21278  dsll        $v0, $v0, 9
    ctx->pc = 0x112910u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 9);
    // 0x112914: 0x42c03  sra         $a1, $a0, 16
    ctx->pc = 0x112914u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 4), 16));
    // 0x112918: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x112918u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x11291c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x11291cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x112920: 0x14a4002b  bne         $a1, $a0, . + 4 + (0x2B << 2)
    ctx->pc = 0x112920u;
    {
        const bool branch_taken_0x112920 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 4));
        ctx->pc = 0x112924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112920u;
            // 0x112924: 0xfe630010  sd          $v1, 0x10($s3) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 19), 16), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112920) {
            ctx->pc = 0x1129D0u;
            goto label_1129d0;
        }
    }
    ctx->pc = 0x112928u;
    // 0x112928: 0x61400  sll         $v0, $a2, 16
    ctx->pc = 0x112928u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x11292c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x11292cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112930: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x112930u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x112934: 0x1443001b  bne         $v0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x112934u;
    {
        const bool branch_taken_0x112934 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x112938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112934u;
            // 0x112938: 0x260209ff  addiu       $v0, $s0, 0x9FF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 2559));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112934) {
            ctx->pc = 0x1129A4u;
            goto label_1129a4;
        }
    }
    ctx->pc = 0x11293Cu;
    // 0x11293c: 0x260309ff  addiu       $v1, $s0, 0x9FF
    ctx->pc = 0x11293cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 2559));
    // 0x112940: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x112940u;
    {
        const bool branch_taken_0x112940 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x112940) {
            ctx->pc = 0x112944u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x112940u;
            // 0x112944: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x112948u;
            goto label_112948;
        }
    }
    ctx->pc = 0x112948u;
label_112948:
    // 0x112948: 0x70001a  div         $zero, $v1, $s0
    ctx->pc = 0x112948u;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x11294c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x11294cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x112950: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x112950u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112954: 0x2821021  addu        $v0, $s4, $v0
    ctx->pc = 0x112954u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x112958: 0x86260004  lh          $a2, 0x4($s1)
    ctx->pc = 0x112958u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x11295c: 0x24420032  addiu       $v0, $v0, 0x32
    ctx->pc = 0x11295cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 50));
    // 0x112960: 0x64a5027c  daddiu      $a1, $a1, 0x27C
    ctx->pc = 0x112960u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)636);
    // 0x112964: 0x30420fff  andi        $v0, $v0, 0xFFF
    ctx->pc = 0x112964u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4095);
    // 0x112968: 0x23b38  dsll        $a3, $v0, 12
    ctx->pc = 0x112968u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << 12);
    // 0x11296c: 0x1812  mflo        $v1
    ctx->pc = 0x11296cu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x112970: 0x702018  mult        $a0, $v1, $s0
    ctx->pc = 0x112970u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x112974: 0x72a31018  mult1       $v0, $s5, $v1
    ctx->pc = 0x112974u;
    { int64_t result = (int64_t)GPR_S32(ctx, 21) * (int64_t)GPR_S32(ctx, 3); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x112978: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x112978u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x11297c: 0x355f8  dsll        $t2, $v1, 23
    ctx->pc = 0x11297cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) << 23);
    // 0x112980: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x112980u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x112984: 0x4183c  dsll32      $v1, $a0, 0
    ctx->pc = 0x112984u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x112988: 0x45282d  daddu       $a1, $v0, $a1
    ctx->pc = 0x112988u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 5));
    // 0x11298c: 0x10c00032  beqz        $a2, . + 4 + (0x32 << 2)
    ctx->pc = 0x11298Cu;
    {
        const bool branch_taken_0x11298c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x112990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11298Cu;
            // 0x112990: 0x30a50fff  andi        $a1, $a1, 0xFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4095);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11298c) {
            ctx->pc = 0x112A58u;
            goto label_112a58;
        }
    }
    ctx->pc = 0x112994u;
    // 0x112994: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x112994u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x112998: 0x1431825  or          $v1, $t2, $v1
    ctx->pc = 0x112998u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 10) | GPR_U64(ctx, 3));
    // 0x11299c: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x11299Cu;
    {
        const bool branch_taken_0x11299c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1129A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11299Cu;
            // 0x1129a0: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11299c) {
            ctx->pc = 0x112A60u;
            goto label_112a60;
        }
    }
    ctx->pc = 0x1129A4u;
label_1129a4:
    // 0x1129a4: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1129A4u;
    {
        const bool branch_taken_0x1129a4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1129a4) {
            ctx->pc = 0x1129A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1129A4u;
            // 0x1129a8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1129ACu;
            goto label_1129ac;
        }
    }
    ctx->pc = 0x1129ACu;
label_1129ac:
    // 0x1129ac: 0x50001a  div         $zero, $v0, $s0
    ctx->pc = 0x1129acu;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1129b0: 0x2647ffff  addiu       $a3, $s2, -0x1
    ctx->pc = 0x1129b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x1129b4: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x1129b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1129b8: 0x73b3c  dsll32      $a3, $a3, 12
    ctx->pc = 0x1129b8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << (32 + 12));
    // 0x1129bc: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1129bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1129c0: 0x64a5027c  daddiu      $a1, $a1, 0x27C
    ctx->pc = 0x1129c0u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)636);
    // 0x1129c4: 0x2831821  addu        $v1, $s4, $v1
    ctx->pc = 0x1129c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1129c8: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1129C8u;
    {
        const bool branch_taken_0x1129c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1129CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1129C8u;
            // 0x1129cc: 0x24630019  addiu       $v1, $v1, 0x19 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 25));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1129c8) {
            ctx->pc = 0x112AA0u;
            goto label_112aa0;
        }
    }
    ctx->pc = 0x1129D0u;
label_1129d0:
    // 0x1129d0: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1129d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1129d4: 0x14a20043  bne         $a1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1129D4u;
    {
        const bool branch_taken_0x1129d4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x1129D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1129D4u;
            // 0x1129d8: 0x24020050  addiu       $v0, $zero, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1129d4) {
            ctx->pc = 0x112AE4u;
            goto label_112ae4;
        }
    }
    ctx->pc = 0x1129DCu;
    // 0x1129dc: 0x61400  sll         $v0, $a2, 16
    ctx->pc = 0x1129dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x1129e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1129e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1129e4: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1129e4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1129e8: 0x14430023  bne         $v0, $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1129E8u;
    {
        const bool branch_taken_0x1129e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1129ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1129E8u;
            // 0x1129ec: 0x260209ff  addiu       $v0, $s0, 0x9FF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 2559));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1129e8) {
            ctx->pc = 0x112A78u;
            goto label_112a78;
        }
    }
    ctx->pc = 0x1129F0u;
    // 0x1129f0: 0x260309ff  addiu       $v1, $s0, 0x9FF
    ctx->pc = 0x1129f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 2559));
    // 0x1129f4: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1129F4u;
    {
        const bool branch_taken_0x1129f4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1129f4) {
            ctx->pc = 0x1129F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1129F4u;
            // 0x1129f8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1129FCu;
            goto label_1129fc;
        }
    }
    ctx->pc = 0x1129FCu;
label_1129fc:
    // 0x1129fc: 0x70001a  div         $zero, $v1, $s0
    ctx->pc = 0x1129fcu;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x112a00: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x112a00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x112a04: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x112a04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112a08: 0x2821021  addu        $v0, $s4, $v0
    ctx->pc = 0x112a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x112a0c: 0x86260004  lh          $a2, 0x4($s1)
    ctx->pc = 0x112a0cu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x112a10: 0x24420048  addiu       $v0, $v0, 0x48
    ctx->pc = 0x112a10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 72));
    // 0x112a14: 0x64a50290  daddiu      $a1, $a1, 0x290
    ctx->pc = 0x112a14u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)656);
    // 0x112a18: 0x30420fff  andi        $v0, $v0, 0xFFF
    ctx->pc = 0x112a18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4095);
    // 0x112a1c: 0x23b38  dsll        $a3, $v0, 12
    ctx->pc = 0x112a1cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << 12);
    // 0x112a20: 0x1812  mflo        $v1
    ctx->pc = 0x112a20u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x112a24: 0x702018  mult        $a0, $v1, $s0
    ctx->pc = 0x112a24u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x112a28: 0x72a31018  mult1       $v0, $s5, $v1
    ctx->pc = 0x112a28u;
    { int64_t result = (int64_t)GPR_S32(ctx, 21) * (int64_t)GPR_S32(ctx, 3); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x112a2c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x112a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x112a30: 0x355f8  dsll        $t2, $v1, 23
    ctx->pc = 0x112a30u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) << 23);
    // 0x112a34: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x112a34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x112a38: 0x4183c  dsll32      $v1, $a0, 0
    ctx->pc = 0x112a38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x112a3c: 0x45282d  daddu       $a1, $v0, $a1
    ctx->pc = 0x112a3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 5));
    // 0x112a40: 0x10c00005  beqz        $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x112A40u;
    {
        const bool branch_taken_0x112a40 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x112A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112A40u;
            // 0x112a44: 0x30a50fff  andi        $a1, $a1, 0xFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4095);
        ctx->in_delay_slot = false;
        if (branch_taken_0x112a40) {
            ctx->pc = 0x112A58u;
            goto label_112a58;
        }
    }
    ctx->pc = 0x112A48u;
    // 0x112a48: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x112a48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x112a4c: 0x1431825  or          $v1, $t2, $v1
    ctx->pc = 0x112a4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 10) | GPR_U64(ctx, 3));
    // 0x112a50: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x112A50u;
    {
        const bool branch_taken_0x112a50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112A50u;
            // 0x112a54: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112a50) {
            ctx->pc = 0x112A60u;
            goto label_112a60;
        }
    }
    ctx->pc = 0x112A58u;
label_112a58:
    // 0x112a58: 0x2642ffff  addiu       $v0, $s2, -0x1
    ctx->pc = 0x112a58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x112a5c: 0x1431825  or          $v1, $t2, $v1
    ctx->pc = 0x112a5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 10) | GPR_U64(ctx, 3));
label_112a60:
    // 0x112a60: 0x2133c  dsll32      $v0, $v0, 12
    ctx->pc = 0x112a60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 12));
    // 0x112a64: 0xa21025  or          $v0, $a1, $v0
    ctx->pc = 0x112a64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x112a68: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x112a68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x112a6c: 0x671025  or          $v0, $v1, $a3
    ctx->pc = 0x112a6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x112a70: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x112A70u;
    {
        const bool branch_taken_0x112a70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112A70u;
            // 0x112a74: 0xfe620018  sd          $v0, 0x18($s3) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 19), 24), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112a70) {
            ctx->pc = 0x112B68u;
            goto label_112b68;
        }
    }
    ctx->pc = 0x112A78u;
label_112a78:
    // 0x112a78: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x112A78u;
    {
        const bool branch_taken_0x112a78 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x112a78) {
            ctx->pc = 0x112A7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x112A78u;
            // 0x112a7c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x112A80u;
            goto label_112a80;
        }
    }
    ctx->pc = 0x112A80u;
label_112a80:
    // 0x112a80: 0x50001a  div         $zero, $v0, $s0
    ctx->pc = 0x112a80u;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x112a84: 0x2647ffff  addiu       $a3, $s2, -0x1
    ctx->pc = 0x112a84u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x112a88: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x112a88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112a8c: 0x73b3c  dsll32      $a3, $a3, 12
    ctx->pc = 0x112a8cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << (32 + 12));
    // 0x112a90: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x112a90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x112a94: 0x64a50290  daddiu      $a1, $a1, 0x290
    ctx->pc = 0x112a94u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)656);
    // 0x112a98: 0x2831821  addu        $v1, $s4, $v1
    ctx->pc = 0x112a98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x112a9c: 0x24630024  addiu       $v1, $v1, 0x24
    ctx->pc = 0x112a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 36));
label_112aa0:
    // 0x112aa0: 0x30630fff  andi        $v1, $v1, 0xFFF
    ctx->pc = 0x112aa0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4095);
    // 0x112aa4: 0x31b38  dsll        $v1, $v1, 12
    ctx->pc = 0x112aa4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 12);
    // 0x112aa8: 0x1012  mflo        $v0
    ctx->pc = 0x112aa8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x112aac: 0x2a23018  mult        $a2, $s5, $v0
    ctx->pc = 0x112aacu;
    { int64_t result = (int64_t)GPR_S32(ctx, 21) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x112ab0: 0x70502018  mult1       $a0, $v0, $s0
    ctx->pc = 0x112ab0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 16); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x112ab4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x112ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x112ab8: 0xc5282d  daddu       $a1, $a2, $a1
    ctx->pc = 0x112ab8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 5));
    // 0x112abc: 0x215f8  dsll        $v0, $v0, 23
    ctx->pc = 0x112abcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 23);
    // 0x112ac0: 0x30a50fff  andi        $a1, $a1, 0xFFF
    ctx->pc = 0x112ac0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4095);
    // 0x112ac4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x112ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x112ac8: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x112ac8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x112acc: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x112accu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x112ad0: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x112ad0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x112ad4: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x112ad4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x112ad8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x112ad8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x112adc: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x112ADCu;
    {
        const bool branch_taken_0x112adc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112ADCu;
            // 0x112ae0: 0xfe620018  sd          $v0, 0x18($s3) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 19), 24), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112adc) {
            ctx->pc = 0x112B68u;
            goto label_112b68;
        }
    }
    ctx->pc = 0x112AE4u;
label_112ae4:
    // 0x112ae4: 0x14a2001e  bne         $a1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x112AE4u;
    {
        const bool branch_taken_0x112ae4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x112AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112AE4u;
            // 0x112ae8: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112ae4) {
            ctx->pc = 0x112B60u;
            goto label_112b60;
        }
    }
    ctx->pc = 0x112AECu;
    // 0x112aec: 0x240202d0  addiu       $v0, $zero, 0x2D0
    ctx->pc = 0x112aecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 720));
    // 0x112af0: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x112af0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112af4: 0x501023  subu        $v0, $v0, $s0
    ctx->pc = 0x112af4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x112af8: 0x153040  sll         $a2, $s5, 1
    ctx->pc = 0x112af8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 21), 1));
    // 0x112afc: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x112afcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x112b00: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x112b00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x112b04: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x112b04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x112b08: 0x64c700e8  daddiu      $a3, $a2, 0xE8
    ctx->pc = 0x112b08u;
    SET_GPR_S64(ctx, 7, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)232);
    // 0x112b0c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x112b0cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x112b10: 0x103040  sll         $a2, $s0, 1
    ctx->pc = 0x112b10u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x112b14: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x112b14u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x112b18: 0x2842021  addu        $a0, $s4, $a0
    ctx->pc = 0x112b18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 4)));
    // 0x112b1c: 0x45282d  daddu       $a1, $v0, $a1
    ctx->pc = 0x112b1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 5));
    // 0x112b20: 0x2643ffff  addiu       $v1, $s2, -0x1
    ctx->pc = 0x112b20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x112b24: 0xa7282d  daddu       $a1, $a1, $a3
    ctx->pc = 0x112b24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 7));
    // 0x112b28: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x112b28u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x112b2c: 0x31b3c  dsll32      $v1, $v1, 12
    ctx->pc = 0x112b2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 12));
    // 0x112b30: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x112b30u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x112b34: 0x30a50fff  andi        $a1, $a1, 0xFFF
    ctx->pc = 0x112b34u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4095);
    // 0x112b38: 0x24840023  addiu       $a0, $a0, 0x23
    ctx->pc = 0x112b38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 35));
    // 0x112b3c: 0x3c020080  lui         $v0, 0x80
    ctx->pc = 0x112b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)128 << 16));
    // 0x112b40: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x112b40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x112b44: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x112b44u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x112b48: 0x30840fff  andi        $a0, $a0, 0xFFF
    ctx->pc = 0x112b48u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4095);
    // 0x112b4c: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x112b4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x112b50: 0x42338  dsll        $a0, $a0, 12
    ctx->pc = 0x112b50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 12);
    // 0x112b54: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x112b54u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x112b58: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x112B58u;
    {
        const bool branch_taken_0x112b58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112B58u;
            // 0x112b5c: 0xfe630018  sd          $v1, 0x18($s3) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 19), 24), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112b58) {
            ctx->pc = 0x112B68u;
            goto label_112b68;
        }
    }
    ctx->pc = 0x112B60u;
label_112b60:
    // 0x112b60: 0xc045a12  jal         func_116848
    ctx->pc = 0x112B60u;
    SET_GPR_U32(ctx, 31, 0x112B68u);
    ctx->pc = 0x112B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112B60u;
            // 0x112b64: 0x248485c8  addiu       $a0, $a0, -0x7A38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936008));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112B68u; }
        if (ctx->pc != 0x112B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112B68u; }
        if (ctx->pc != 0x112B68u) { return; }
    }
    ctx->pc = 0x112B68u;
label_112b68:
    // 0x112b68: 0xfe600020  sd          $zero, 0x20($s3)
    ctx->pc = 0x112b68u;
    WRITE64(ADD32(GPR_U32(ctx, 19), 32), GPR_U64(ctx, 0));
    // 0x112b6c: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x112b6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x112b70: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x112b70u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x112b74: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x112b74u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x112b78: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x112b78u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x112b7c: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x112b7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x112b80: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x112b80u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x112b84: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x112b84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x112b88: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x112b88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112b8c: 0x3e00008  jr          $ra
    ctx->pc = 0x112B8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112B8Cu;
            // 0x112b90: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112874u: goto label_112874;
            case 0x112894u: goto label_112894;
            case 0x1128B0u: goto label_1128b0;
            case 0x1128B8u: goto label_1128b8;
            case 0x1128C0u: goto label_1128c0;
            case 0x1128CCu: goto label_1128cc;
            case 0x1128F4u: goto label_1128f4;
            case 0x112948u: goto label_112948;
            case 0x1129A4u: goto label_1129a4;
            case 0x1129ACu: goto label_1129ac;
            case 0x1129D0u: goto label_1129d0;
            case 0x1129FCu: goto label_1129fc;
            case 0x112A58u: goto label_112a58;
            case 0x112A60u: goto label_112a60;
            case 0x112A78u: goto label_112a78;
            case 0x112A80u: goto label_112a80;
            case 0x112AA0u: goto label_112aa0;
            case 0x112AE4u: goto label_112ae4;
            case 0x112B60u: goto label_112b60;
            case 0x112B68u: goto label_112b68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112B94u;
    // 0x112b94: 0x0  nop
    ctx->pc = 0x112b94u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
