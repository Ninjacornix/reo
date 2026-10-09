#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115320
// Address: 0x115320 - 0x1153f8
void sub_00115320_0x115320(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115320_0x115320");
#endif

    switch (ctx->pc) {
        case 0x115360u: goto label_115360;
        case 0x115368u: goto label_115368;
        case 0x1153c0u: goto label_1153c0;
        case 0x1153d0u: goto label_1153d0;
        case 0x1153e0u: goto label_1153e0;
        case 0x1153f0u: goto label_1153f0;
        default: break;
    }

    ctx->pc = 0x115320u;

    // 0x115320: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x115320u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x115324: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x115324u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115328: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x115328u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11532c: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x11532cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x115330: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x115330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x115334: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x115334u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x115338: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x115338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11533c: 0x3c150024  lui         $s5, 0x24
    ctx->pc = 0x11533cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)36 << 16));
    // 0x115340: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x115340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x115344: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x115344u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x115348: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x115348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11534c: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x11534cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x115350: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x115350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115354: 0x26320008  addiu       $s2, $s1, 0x8
    ctx->pc = 0x115354u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x115358: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x115358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x11535c: 0x26300009  addiu       $s0, $s1, 0x9
    ctx->pc = 0x11535cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 9));
label_115360:
    // 0x115360: 0xc045198  jal         func_114660
    ctx->pc = 0x115360u;
    SET_GPR_U32(ctx, 31, 0x115368u);
    ctx->pc = 0x115364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115360u;
            // 0x115364: 0x8ec4a630  lw          $a0, -0x59D0($s6) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 4294944304)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115368u; }
        if (ctx->pc != 0x115368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115368u; }
        if (ctx->pc != 0x115368u) { return; }
    }
    ctx->pc = 0x115368u;
label_115368:
    // 0x115368: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x115368u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11536c: 0x306301ff  andi        $v1, $v1, 0x1FF
    ctx->pc = 0x11536cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)511);
    // 0x115370: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x115370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x115374: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x115374u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x115378: 0xae240000  sw          $a0, 0x0($s1)
    ctx->pc = 0x115378u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 4));
    // 0x11537c: 0x2431021  addu        $v0, $s2, $v1
    ctx->pc = 0x11537cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x115380: 0x2033021  addu        $a2, $s0, $v1
    ctx->pc = 0x115380u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x115384: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x115384u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x115388: 0x1054000f  beq         $v0, $s4, . + 4 + (0xF << 2)
    ctx->pc = 0x115388u;
    {
        const bool branch_taken_0x115388 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 20));
        ctx->pc = 0x11538Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115388u;
            // 0x11538c: 0x28450002  slti        $a1, $v0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x115388) {
            ctx->pc = 0x1153C8u;
            goto label_1153c8;
        }
    }
    ctx->pc = 0x115390u;
    // 0x115390: 0x10a00005  beqz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x115390u;
    {
        const bool branch_taken_0x115390 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x115394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115390u;
            // 0x115394: 0x26a48918  addiu       $a0, $s5, -0x76E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294936856));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115390) {
            ctx->pc = 0x1153A8u;
            goto label_1153a8;
        }
    }
    ctx->pc = 0x115398u;
    // 0x115398: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x115398u;
    {
        const bool branch_taken_0x115398 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11539Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115398u;
            // 0x11539c: 0xc0182d  daddu       $v1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115398) {
            ctx->pc = 0x1153B8u;
            goto label_1153b8;
        }
    }
    ctx->pc = 0x1153A0u;
    // 0x1153a0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1153A0u;
    {
        const bool branch_taken_0x1153a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1153a0) {
            ctx->pc = 0x1153E8u;
            goto label_1153e8;
        }
    }
    ctx->pc = 0x1153A8u;
label_1153a8:
    // 0x1153a8: 0x1053000b  beq         $v0, $s3, . + 4 + (0xB << 2)
    ctx->pc = 0x1153A8u;
    {
        const bool branch_taken_0x1153a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 19));
        ctx->pc = 0x1153ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1153A8u;
            // 0x1153ac: 0x2031821  addu        $v1, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1153a8) {
            ctx->pc = 0x1153D8u;
            goto label_1153d8;
        }
    }
    ctx->pc = 0x1153B0u;
    // 0x1153b0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1153B0u;
    {
        const bool branch_taken_0x1153b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1153b0) {
            ctx->pc = 0x1153E8u;
            goto label_1153e8;
        }
    }
    ctx->pc = 0x1153B8u;
label_1153b8:
    // 0x1153b8: 0xc045154  jal         func_114550
    ctx->pc = 0x1153B8u;
    SET_GPR_U32(ctx, 31, 0x1153C0u);
    ctx->pc = 0x1153BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1153B8u;
            // 0x1153bc: 0x90640000  lbu         $a0, 0x0($v1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114550u;
    if (runtime->hasFunction(0x114550u)) {
        auto targetFn = runtime->lookupFunction(0x114550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1153C0u; }
        if (ctx->pc != 0x1153C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114550_0x114550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1153C0u; }
        if (ctx->pc != 0x1153C0u) { return; }
    }
    ctx->pc = 0x1153C0u;
label_1153c0:
    // 0x1153c0: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x1153C0u;
    {
        const bool branch_taken_0x1153c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1153c0) {
            ctx->pc = 0x115360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115360;
        }
    }
    ctx->pc = 0x1153C8u;
label_1153c8:
    // 0x1153c8: 0xc045134  jal         func_1144D0
    ctx->pc = 0x1153C8u;
    SET_GPR_U32(ctx, 31, 0x1153D0u);
    ctx->pc = 0x1153CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1153C8u;
            // 0x1153cc: 0x90c40000  lbu         $a0, 0x0($a2) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144D0u;
    if (runtime->hasFunction(0x1144D0u)) {
        auto targetFn = runtime->lookupFunction(0x1144D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1153D0u; }
        if (ctx->pc != 0x1153D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144D0_0x1144d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1153D0u; }
        if (ctx->pc != 0x1153D0u) { return; }
    }
    ctx->pc = 0x1153D0u;
label_1153d0:
    // 0x1153d0: 0x1000ffe3  b           . + 4 + (-0x1D << 2)
    ctx->pc = 0x1153D0u;
    {
        const bool branch_taken_0x1153d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1153d0) {
            ctx->pc = 0x115360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115360;
        }
    }
    ctx->pc = 0x1153D8u;
label_1153d8:
    // 0x1153d8: 0xc045164  jal         func_114590
    ctx->pc = 0x1153D8u;
    SET_GPR_U32(ctx, 31, 0x1153E0u);
    ctx->pc = 0x1153DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1153D8u;
            // 0x1153dc: 0x90640000  lbu         $a0, 0x0($v1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114590u;
    if (runtime->hasFunction(0x114590u)) {
        auto targetFn = runtime->lookupFunction(0x114590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1153E0u; }
        if (ctx->pc != 0x1153E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114590_0x114590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1153E0u; }
        if (ctx->pc != 0x1153E0u) { return; }
    }
    ctx->pc = 0x1153E0u;
label_1153e0:
    // 0x1153e0: 0x1000ffdf  b           . + 4 + (-0x21 << 2)
    ctx->pc = 0x1153E0u;
    {
        const bool branch_taken_0x1153e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1153e0) {
            ctx->pc = 0x115360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115360;
        }
    }
    ctx->pc = 0x1153E8u;
label_1153e8:
    // 0x1153e8: 0xc045a04  jal         func_116810
    ctx->pc = 0x1153E8u;
    SET_GPR_U32(ctx, 31, 0x1153F0u);
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1153F0u; }
        if (ctx->pc != 0x1153F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1153F0u; }
        if (ctx->pc != 0x1153F0u) { return; }
    }
    ctx->pc = 0x1153F0u;
label_1153f0:
    // 0x1153f0: 0x1000ffdb  b           . + 4 + (-0x25 << 2)
    ctx->pc = 0x1153F0u;
    {
        const bool branch_taken_0x1153f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1153f0) {
            ctx->pc = 0x115360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115360;
        }
    }
    ctx->pc = 0x1153F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
