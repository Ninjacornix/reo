#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001892F0
// Address: 0x1892f0 - 0x18941c
void sub_001892F0_0x1892f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001892F0_0x1892f0");
#endif

    switch (ctx->pc) {
        case 0x18932cu: goto label_18932c;
        case 0x189360u: goto label_189360;
        case 0x1893b8u: goto label_1893b8;
        case 0x1893ccu: goto label_1893cc;
        case 0x1893d4u: goto label_1893d4;
        case 0x1893f4u: goto label_1893f4;
        default: break;
    }

    ctx->pc = 0x1892f0u;

    // 0x1892f0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1892f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1892f4: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x1892f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1892f8: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1892f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1892fc: 0x3c150029  lui         $s5, 0x29
    ctx->pc = 0x1892fcu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)41 << 16));
    // 0x189300: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x189300u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189304: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x189304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x189308: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x189308u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x18930c: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x18930cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189310: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x189310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x189314: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x189314u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189318: 0x8ea44140  lw          $a0, 0x4140($s5)
    ctx->pc = 0x189318u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
    // 0x18931c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x18931cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x189320: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x189320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x189324: 0xc045198  jal         func_114660
    ctx->pc = 0x189324u;
    SET_GPR_U32(ctx, 31, 0x18932Cu);
    ctx->pc = 0x189328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189324u;
            // 0x189328: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18932Cu; }
        if (ctx->pc != 0x18932Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18932Cu; }
        if (ctx->pc != 0x18932Cu) { return; }
    }
    ctx->pc = 0x18932Cu;
label_18932c:
    // 0x18932c: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x18932cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x189330: 0xacf10c00  sw          $s1, 0xC00($a3)
    ctx->pc = 0x189330u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 3072), GPR_U32(ctx, 17));
    // 0x189334: 0x24f20c00  addiu       $s2, $a3, 0xC00
    ctx->pc = 0x189334u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), 3072));
    // 0x189338: 0xae500004  sw          $s0, 0x4($s2)
    ctx->pc = 0x189338u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 16));
    // 0x18933c: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x18933cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x189340: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x189340u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x189344: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x189344u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x189348: 0x1860000f  blez        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x189348u;
    {
        const bool branch_taken_0x189348 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x18934Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189348u;
            // 0x18934c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189348) {
            ctx->pc = 0x189388u;
            goto label_189388;
        }
    }
    ctx->pc = 0x189350u;
    // 0x189350: 0x2646000c  addiu       $a2, $s2, 0xC
    ctx->pc = 0x189350u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
    // 0x189354: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x189354u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x189358: 0x2851021  addu        $v0, $s4, $a1
    ctx->pc = 0x189358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
    // 0x18935c: 0x0  nop
    ctx->pc = 0x18935cu;
    // NOP
label_189360:
    // 0x189360: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x189360u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x189364: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x189364u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x189368: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x189368u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x18936c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x18936cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x189370: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x189370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x189374: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x189374u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x189378: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x189378u;
    {
        const bool branch_taken_0x189378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18937Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189378u;
            // 0x18937c: 0x2851021  addu        $v0, $s4, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189378) {
            ctx->pc = 0x189360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189360;
        }
    }
    ctx->pc = 0x189380u;
    // 0x189380: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x189380u;
    {
        const bool branch_taken_0x189380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189380u;
            // 0x189384: 0x24e70c00  addiu       $a3, $a3, 0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 3072));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189380) {
            ctx->pc = 0x189390u;
            goto label_189390;
        }
    }
    ctx->pc = 0x189388u;
label_189388:
    // 0x189388: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x189388u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x18938c: 0x24e70c00  addiu       $a3, $a3, 0xC00
    ctx->pc = 0x18938cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 3072));
label_189390:
    // 0x189390: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189390u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x189394: 0x25040b88  addiu       $a0, $t0, 0xB88
    ctx->pc = 0x189394u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), 2952));
    // 0x189398: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x189398u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x18939c: 0x34a51319  ori         $a1, $a1, 0x1319
    ctx->pc = 0x18939cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4889);
    // 0x1893a0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1893a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1893a4: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x1893a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1893a8: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x1893a8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1893ac: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x1893acu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1893b0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1893B0u;
    SET_GPR_U32(ctx, 31, 0x1893B8u);
    ctx->pc = 0x1893B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1893B0u;
            // 0x1893b4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893B8u; }
        if (ctx->pc != 0x1893B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893B8u; }
        if (ctx->pc != 0x1893B8u) { return; }
    }
    ctx->pc = 0x1893B8u;
label_1893b8:
    // 0x1893b8: 0x4430008  bgezl       $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1893B8u;
    {
        const bool branch_taken_0x1893b8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1893b8) {
            ctx->pc = 0x1893BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1893B8u;
            // 0x1893bc: 0x8e42020c  lw          $v0, 0x20C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 524)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1893DCu;
            goto label_1893dc;
        }
    }
    ctx->pc = 0x1893C0u;
    // 0x1893c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1893c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1893c4: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x1893C4u;
    SET_GPR_U32(ctx, 31, 0x1893CCu);
    ctx->pc = 0x1893C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1893C4u;
            // 0x1893c8: 0x24841a08  addiu       $a0, $a0, 0x1A08 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6664));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893CCu; }
        if (ctx->pc != 0x1893CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893CCu; }
        if (ctx->pc != 0x1893CCu) { return; }
    }
    ctx->pc = 0x1893CCu;
label_1893cc:
    // 0x1893cc: 0xc045190  jal         func_114640
    ctx->pc = 0x1893CCu;
    SET_GPR_U32(ctx, 31, 0x1893D4u);
    ctx->pc = 0x1893D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1893CCu;
            // 0x1893d0: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893D4u; }
        if (ctx->pc != 0x1893D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893D4u; }
        if (ctx->pc != 0x1893D4u) { return; }
    }
    ctx->pc = 0x1893D4u;
label_1893d4:
    // 0x1893d4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1893D4u;
    {
        const bool branch_taken_0x1893d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1893D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1893D4u;
            // 0x1893d8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1893d4) {
            ctx->pc = 0x1893F8u;
            goto label_1893f8;
        }
    }
    ctx->pc = 0x1893DCu;
label_1893dc:
    // 0x1893dc: 0x4400003  bltz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1893DCu;
    {
        const bool branch_taken_0x1893dc = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1893dc) {
            ctx->pc = 0x1893ECu;
            goto label_1893ec;
        }
    }
    ctx->pc = 0x1893E4u;
    // 0x1893e4: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x1893e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1893e8: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x1893e8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
label_1893ec:
    // 0x1893ec: 0xc045190  jal         func_114640
    ctx->pc = 0x1893ECu;
    SET_GPR_U32(ctx, 31, 0x1893F4u);
    ctx->pc = 0x1893F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1893ECu;
            // 0x1893f0: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893F4u; }
        if (ctx->pc != 0x1893F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893F4u; }
        if (ctx->pc != 0x1893F4u) { return; }
    }
    ctx->pc = 0x1893F4u;
label_1893f4:
    // 0x1893f4: 0x8e42020c  lw          $v0, 0x20C($s2)
    ctx->pc = 0x1893f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 524)));
label_1893f8:
    // 0x1893f8: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1893f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1893fc: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x1893fcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x189400: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x189400u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x189404: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x189404u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x189408: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x189408u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18940c: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x18940cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x189410: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x189410u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189414: 0x3e00008  jr          $ra
    ctx->pc = 0x189414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189414u;
            // 0x189418: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18932Cu: goto label_18932c;
            case 0x189360u: goto label_189360;
            case 0x189388u: goto label_189388;
            case 0x189390u: goto label_189390;
            case 0x1893B8u: goto label_1893b8;
            case 0x1893CCu: goto label_1893cc;
            case 0x1893D4u: goto label_1893d4;
            case 0x1893DCu: goto label_1893dc;
            case 0x1893ECu: goto label_1893ec;
            case 0x1893F4u: goto label_1893f4;
            case 0x1893F8u: goto label_1893f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18941Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
