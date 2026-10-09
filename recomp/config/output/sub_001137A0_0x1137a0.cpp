#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001137A0
// Address: 0x1137a0 - 0x113988
void sub_001137A0_0x1137a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001137A0_0x1137a0");
#endif

    switch (ctx->pc) {
        case 0x113864u: goto label_113864;
        default: break;
    }

    ctx->pc = 0x1137a0u;

    // 0x1137a0: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x1137a0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1137a4: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x1137a4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x1137a8: 0x84400  sll         $t0, $t0, 16
    ctx->pc = 0x1137a8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x1137ac: 0x76c03  sra         $t5, $a3, 16
    ctx->pc = 0x1137acu;
    SET_GPR_S32(ctx, 13, SRA32(GPR_S32(ctx, 7), 16));
    // 0x1137b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1137b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1137b4: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x1137b4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1137b8: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x1137b8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x1137bc: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x1137bcu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x1137c0: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x1137c0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x1137c4: 0x66403  sra         $t4, $a2, 16
    ctx->pc = 0x1137c4u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 6), 16));
    // 0x1137c8: 0x87c03  sra         $t7, $t0, 16
    ctx->pc = 0x1137c8u;
    SET_GPR_S32(ctx, 15, SRA32(GPR_S32(ctx, 8), 16));
    // 0x1137cc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1137ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1137d0: 0x53c03  sra         $a3, $a1, 16
    ctx->pc = 0x1137d0u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 5), 16));
    // 0x1137d4: 0x9c403  sra         $t8, $t1, 16
    ctx->pc = 0x1137d4u;
    SET_GPR_S32(ctx, 24, SRA32(GPR_S32(ctx, 9), 16));
    // 0x1137d8: 0xa5403  sra         $t2, $t2, 16
    ctx->pc = 0x1137d8u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 16));
    // 0x1137dc: 0xb4403  sra         $t0, $t3, 16
    ctx->pc = 0x1137dcu;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 11), 16));
    // 0x1137e0: 0x80702d  daddu       $t6, $a0, $zero
    ctx->pc = 0x1137e0u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1137e4: 0x2da2003b  sltiu       $v0, $t5, 0x3B
    ctx->pc = 0x1137e4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 13) < (uint64_t)(int64_t)(int32_t)59) ? 1 : 0);
    // 0x1137e8: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1137E8u;
    {
        const bool branch_taken_0x1137e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1137ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1137E8u;
            // 0x1137ec: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1137e8) {
            ctx->pc = 0x11384Cu;
            goto label_11384c;
        }
    }
    ctx->pc = 0x1137F0u;
    // 0x1137f0: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1137f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1137f4: 0xd1880  sll         $v1, $t5, 2
    ctx->pc = 0x1137f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 13), 2));
    // 0x1137f8: 0x244287f0  addiu       $v0, $v0, -0x7810
    ctx->pc = 0x1137f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936560));
    // 0x1137fc: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1137fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x113800: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x113800u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113804: 0x800008  jr          $a0
    ctx->pc = 0x113804u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11380Cu: goto label_11380c;
            case 0x113818u: goto label_113818;
            case 0x11382Cu: goto label_11382c;
            case 0x113838u: goto label_113838;
            case 0x113844u: goto label_113844;
            case 0x11384Cu: goto label_11384c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11380Cu;
label_11380c:
    // 0x11380c: 0x1481018  mult        $v0, $t2, $t0
    ctx->pc = 0x11380cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x113810: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x113810u;
    {
        const bool branch_taken_0x113810 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113810u;
            // 0x113814: 0x23083  sra         $a2, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113810) {
            ctx->pc = 0x11384Cu;
            goto label_11384c;
        }
    }
    ctx->pc = 0x113818u;
label_113818:
    // 0x113818: 0x1481818  mult        $v1, $t2, $t0
    ctx->pc = 0x113818u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x11381c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x11381cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x113820: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x113820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x113824: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x113824u;
    {
        const bool branch_taken_0x113824 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113824u;
            // 0x113828: 0x23103  sra         $a2, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113824) {
            ctx->pc = 0x11384Cu;
            goto label_11384c;
        }
    }
    ctx->pc = 0x11382Cu;
label_11382c:
    // 0x11382c: 0x1481018  mult        $v0, $t2, $t0
    ctx->pc = 0x11382cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x113830: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x113830u;
    {
        const bool branch_taken_0x113830 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113830u;
            // 0x113834: 0x230c3  sra         $a2, $v0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 2), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113830) {
            ctx->pc = 0x11384Cu;
            goto label_11384c;
        }
    }
    ctx->pc = 0x113838u;
label_113838:
    // 0x113838: 0x1481018  mult        $v0, $t2, $t0
    ctx->pc = 0x113838u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x11383c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11383Cu;
    {
        const bool branch_taken_0x11383c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11383Cu;
            // 0x113840: 0x23103  sra         $a2, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11383c) {
            ctx->pc = 0x11384Cu;
            goto label_11384c;
        }
    }
    ctx->pc = 0x113844u;
label_113844:
    // 0x113844: 0x1481018  mult        $v0, $t2, $t0
    ctx->pc = 0x113844u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x113848: 0x23143  sra         $a2, $v0, 5
    ctx->pc = 0x113848u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 2), 5));
label_11384c:
    // 0x11384c: 0x24027fff  addiu       $v0, $zero, 0x7FFF
    ctx->pc = 0x11384cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
    // 0x113850: 0x46102a  slt         $v0, $v0, $a2
    ctx->pc = 0x113850u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x113854: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x113854u;
    {
        const bool branch_taken_0x113854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x113858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113854u;
            // 0x113858: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113854) {
            ctx->pc = 0x11386Cu;
            goto label_11386c;
        }
    }
    ctx->pc = 0x11385Cu;
    // 0x11385c: 0xc045a12  jal         func_116848
    ctx->pc = 0x11385Cu;
    SET_GPR_U32(ctx, 31, 0x113864u);
    ctx->pc = 0x113860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11385Cu;
            // 0x113860: 0x248487c0  addiu       $a0, $a0, -0x7840 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113864u; }
        if (ctx->pc != 0x113864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113864u; }
        if (ctx->pc != 0x113864u) { return; }
    }
    ctx->pc = 0x113864u;
label_113864:
    // 0x113864: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x113864u;
    {
        const bool branch_taken_0x113864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113864u;
            // 0x113868: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113864) {
            ctx->pc = 0x113978u;
            goto label_113978;
        }
    }
    ctx->pc = 0x11386Cu;
label_11386c:
    // 0x11386c: 0x700014a9  por         $v0, $zero, $zero
    ctx->pc = 0x11386cu;
    SET_GPR_VEC(ctx, 2, PS2_POR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x113870: 0x30c37fff  andi        $v1, $a2, 0x7FFF
    ctx->pc = 0x113870u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)32767);
    // 0x113874: 0x7dc20050  sq          $v0, 0x50($t6)
    ctx->pc = 0x113874u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 80), GPR_VEC(ctx, 2));
    // 0x113878: 0x7343c  dsll32      $a2, $a3, 16
    ctx->pc = 0x113878u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) << (32 + 16));
    // 0x11387c: 0x7dc20000  sq          $v0, 0x0($t6)
    ctx->pc = 0x11387cu;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 2));
    // 0x113880: 0x3c07f3ff  lui         $a3, 0xF3FF
    ctx->pc = 0x113880u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)62463 << 16));
    // 0x113884: 0x34e7ffff  ori         $a3, $a3, 0xFFFF
    ctx->pc = 0x113884u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65535);
    // 0x113888: 0x73c38  dsll        $a3, $a3, 16
    ctx->pc = 0x113888u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << 16);
    // 0x11388c: 0x34e7ffff  ori         $a3, $a3, 0xFFFF
    ctx->pc = 0x11388cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65535);
    // 0x113890: 0x73c38  dsll        $a3, $a3, 16
    ctx->pc = 0x113890u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << 16);
    // 0x113894: 0x34e7ffff  ori         $a3, $a3, 0xFFFF
    ctx->pc = 0x113894u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65535);
    // 0x113898: 0xddc40050  ld          $a0, 0x50($t6)
    ctx->pc = 0x113898u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 14), 80)));
    // 0x11389c: 0x24028000  addiu       $v0, $zero, -0x8000
    ctx->pc = 0x11389cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x1138a0: 0xddc50000  ld          $a1, 0x0($t6)
    ctx->pc = 0x1138a0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x1138a4: 0xc643c  dsll32      $t4, $t4, 16
    ctx->pc = 0x1138a4u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) << (32 + 16));
    // 0x1138a8: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x1138a8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1138ac: 0xddcb0008  ld          $t3, 0x8($t6)
    ctx->pc = 0x1138acu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 14), 8)));
    // 0x1138b0: 0xa22824  and         $a1, $a1, $v0
    ctx->pc = 0x1138b0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1138b4: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1138b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1138b8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1138b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1138bc: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x1138bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1138c0: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x1138c0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1138c4: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1138c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1138c8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1138c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1138cc: 0x2113a  dsrl        $v0, $v0, 4
    ctx->pc = 0x1138ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 4);
    // 0x1138d0: 0x2403fff0  addiu       $v1, $zero, -0x10
    ctx->pc = 0x1138d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x1138d4: 0xa22824  and         $a1, $a1, $v0
    ctx->pc = 0x1138d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1138d8: 0x1635824  and         $t3, $t3, $v1
    ctx->pc = 0x1138d8u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 3));
    // 0x1138dc: 0x872024  and         $a0, $a0, $a3
    ctx->pc = 0x1138dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 7));
    // 0x1138e0: 0x6343b  dsra        $a2, $a2, 16
    ctx->pc = 0x1138e0u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> 16);
    // 0x1138e4: 0xa543c  dsll32      $t2, $t2, 16
    ctx->pc = 0x1138e4u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) << (32 + 16));
    // 0x1138e8: 0x8443c  dsll32      $t0, $t0, 16
    ctx->pc = 0x1138e8u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << (32 + 16));
    // 0x1138ec: 0xcc3025  or          $a2, $a2, $t4
    ctx->pc = 0x1138ecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 12));
    // 0x1138f0: 0x8443b  dsra        $t0, $t0, 16
    ctx->pc = 0x1138f0u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> 16);
    // 0x1138f4: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x1138f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1138f8: 0x2137c  dsll32      $v0, $v0, 13
    ctx->pc = 0x1138f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 13));
    // 0x1138fc: 0x2403000e  addiu       $v1, $zero, 0xE
    ctx->pc = 0x1138fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x113900: 0x34078000  ori         $a3, $zero, 0x8000
    ctx->pc = 0x113900u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x113904: 0x73b3c  dsll32      $a3, $a3, 12
    ctx->pc = 0x113904u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << (32 + 12));
    // 0x113908: 0xf4c3c  dsll32      $t1, $t7, 16
    ctx->pc = 0x113908u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 15) << (32 + 16));
    // 0x11390c: 0xa543f  dsra32      $t2, $t2, 16
    ctx->pc = 0x11390cu;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 10) >> (32 + 16));
    // 0x113910: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x113910u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x113914: 0x1485025  or          $t2, $t2, $t0
    ctx->pc = 0x113914u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 8));
    // 0x113918: 0x1635825  or          $t3, $t3, $v1
    ctx->pc = 0x113918u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | GPR_U64(ctx, 3));
    // 0x11391c: 0x872025  or          $a0, $a0, $a3
    ctx->pc = 0x11391cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 7));
    // 0x113920: 0xd6e3c  dsll32      $t5, $t5, 24
    ctx->pc = 0x113920u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) << (32 + 24));
    // 0x113924: 0x94c3b  dsra        $t1, $t1, 16
    ctx->pc = 0x113924u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> 16);
    // 0x113928: 0x18643c  dsll32      $t4, $t8, 16
    ctx->pc = 0x113928u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 24) << (32 + 16));
    // 0x11392c: 0xcd3025  or          $a2, $a2, $t5
    ctx->pc = 0x11392cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 13));
    // 0x113930: 0x12c4825  or          $t1, $t1, $t4
    ctx->pc = 0x113930u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 12));
    // 0x113934: 0x24020050  addiu       $v0, $zero, 0x50
    ctx->pc = 0x113934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x113938: 0x24030051  addiu       $v1, $zero, 0x51
    ctx->pc = 0x113938u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 81));
    // 0x11393c: 0x24070052  addiu       $a3, $zero, 0x52
    ctx->pc = 0x11393cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 82));
    // 0x113940: 0x24080053  addiu       $t0, $zero, 0x53
    ctx->pc = 0x113940u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 83));
    // 0x113944: 0xfdc40050  sd          $a0, 0x50($t6)
    ctx->pc = 0x113944u;
    WRITE64(ADD32(GPR_U32(ctx, 14), 80), GPR_U64(ctx, 4));
    // 0x113948: 0xfdc50000  sd          $a1, 0x0($t6)
    ctx->pc = 0x113948u;
    WRITE64(ADD32(GPR_U32(ctx, 14), 0), GPR_U64(ctx, 5));
    // 0x11394c: 0xfdcb0008  sd          $t3, 0x8($t6)
    ctx->pc = 0x11394cu;
    WRITE64(ADD32(GPR_U32(ctx, 14), 8), GPR_U64(ctx, 11));
    // 0x113950: 0xfdc60010  sd          $a2, 0x10($t6)
    ctx->pc = 0x113950u;
    WRITE64(ADD32(GPR_U32(ctx, 14), 16), GPR_U64(ctx, 6));
    // 0x113954: 0xfdc20018  sd          $v0, 0x18($t6)
    ctx->pc = 0x113954u;
    WRITE64(ADD32(GPR_U32(ctx, 14), 24), GPR_U64(ctx, 2));
    // 0x113958: 0xfdc90020  sd          $t1, 0x20($t6)
    ctx->pc = 0x113958u;
    WRITE64(ADD32(GPR_U32(ctx, 14), 32), GPR_U64(ctx, 9));
    // 0x11395c: 0xfdc30028  sd          $v1, 0x28($t6)
    ctx->pc = 0x11395cu;
    WRITE64(ADD32(GPR_U32(ctx, 14), 40), GPR_U64(ctx, 3));
    // 0x113960: 0xfdca0030  sd          $t2, 0x30($t6)
    ctx->pc = 0x113960u;
    WRITE64(ADD32(GPR_U32(ctx, 14), 48), GPR_U64(ctx, 10));
    // 0x113964: 0xfdc70038  sd          $a3, 0x38($t6)
    ctx->pc = 0x113964u;
    WRITE64(ADD32(GPR_U32(ctx, 14), 56), GPR_U64(ctx, 7));
    // 0x113968: 0xfdc80048  sd          $t0, 0x48($t6)
    ctx->pc = 0x113968u;
    WRITE64(ADD32(GPR_U32(ctx, 14), 72), GPR_U64(ctx, 8));
    // 0x11396c: 0xfdc00040  sd          $zero, 0x40($t6)
    ctx->pc = 0x11396cu;
    WRITE64(ADD32(GPR_U32(ctx, 14), 64), GPR_U64(ctx, 0));
    // 0x113970: 0xf  sync
    ctx->pc = 0x113970u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x113974: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x113974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
label_113978:
    // 0x113978: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x113978u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11397c: 0x3e00008  jr          $ra
    ctx->pc = 0x11397Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11397Cu;
            // 0x113980: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11380Cu: goto label_11380c;
            case 0x113818u: goto label_113818;
            case 0x11382Cu: goto label_11382c;
            case 0x113838u: goto label_113838;
            case 0x113844u: goto label_113844;
            case 0x11384Cu: goto label_11384c;
            case 0x113864u: goto label_113864;
            case 0x11386Cu: goto label_11386c;
            case 0x113978u: goto label_113978;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113984u;
    // 0x113984: 0x0  nop
    ctx->pc = 0x113984u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
