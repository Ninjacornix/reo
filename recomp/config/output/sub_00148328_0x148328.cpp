#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148328
// Address: 0x148328 - 0x148448
void sub_00148328_0x148328(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148328_0x148328");
#endif

    switch (ctx->pc) {
        case 0x148380u: goto label_148380;
        case 0x148390u: goto label_148390;
        case 0x1483a4u: goto label_1483a4;
        case 0x1483b4u: goto label_1483b4;
        case 0x1483d0u: goto label_1483d0;
        default: break;
    }

    ctx->pc = 0x148328u;

    // 0x148328: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x148328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x14832c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x14832cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x148330: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x148330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x148334: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x148334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x148338: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x148338u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14833c: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x14833cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x148340: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x148340u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148344: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x148344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x148348: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x148348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14834c: 0x10c20004  beq         $a2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x14834Cu;
    {
        const bool branch_taken_0x14834c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        ctx->pc = 0x148350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14834Cu;
            // 0x148350: 0x8e300040  lw          $s0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14834c) {
            ctx->pc = 0x148360u;
            goto label_148360;
        }
    }
    ctx->pc = 0x148354u;
    // 0x148354: 0xa6102a  slt         $v0, $a1, $a2
    ctx->pc = 0x148354u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x148358: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x148358u;
    {
        const bool branch_taken_0x148358 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14835Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148358u;
            // 0x14835c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148358) {
            ctx->pc = 0x14839Cu;
            goto label_14839c;
        }
    }
    ctx->pc = 0x148360u;
label_148360:
    // 0x148360: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x148360u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x148364: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x148364u;
    {
        const bool branch_taken_0x148364 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x148368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148364u;
            // 0x148368: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148364) {
            ctx->pc = 0x148378u;
            goto label_148378;
        }
    }
    ctx->pc = 0x14836Cu;
    // 0x14836c: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x14836cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x148370: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x148370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148374: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x148374u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
label_148378:
    // 0x148378: 0xc051994  jal         func_146650
    ctx->pc = 0x148378u;
    SET_GPR_U32(ctx, 31, 0x148380u);
    ctx->pc = 0x14837Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148378u;
            // 0x14837c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146650u;
    if (runtime->hasFunction(0x146650u)) {
        auto targetFn = runtime->lookupFunction(0x146650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148380u; }
        if (ctx->pc != 0x148380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146650_0x146650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148380u; }
        if (ctx->pc != 0x148380u) { return; }
    }
    ctx->pc = 0x148380u;
label_148380:
    // 0x148380: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x148380u;
    {
        const bool branch_taken_0x148380 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x148384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148380u;
            // 0x148384: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148380) {
            ctx->pc = 0x148394u;
            goto label_148394;
        }
    }
    ctx->pc = 0x148388u;
    // 0x148388: 0xc05193c  jal         func_1464F0
    ctx->pc = 0x148388u;
    SET_GPR_U32(ctx, 31, 0x148390u);
    ctx->pc = 0x14838Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148388u;
            // 0x14838c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1464F0u;
    if (runtime->hasFunction(0x1464F0u)) {
        auto targetFn = runtime->lookupFunction(0x1464F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148390u; }
        if (ctx->pc != 0x148390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001464F0_0x1464f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148390u; }
        if (ctx->pc != 0x148390u) { return; }
    }
    ctx->pc = 0x148390u;
label_148390:
    // 0x148390: 0x2182b  sltu        $v1, $zero, $v0
    ctx->pc = 0x148390u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_148394:
    // 0x148394: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x148394u;
    {
        const bool branch_taken_0x148394 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x148398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148394u;
            // 0x148398: 0x60902d  daddu       $s2, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148394) {
            ctx->pc = 0x1483B4u;
            goto label_1483b4;
        }
    }
    ctx->pc = 0x14839Cu;
label_14839c:
    // 0x14839c: 0xc051994  jal         func_146650
    ctx->pc = 0x14839Cu;
    SET_GPR_U32(ctx, 31, 0x1483A4u);
    ctx->pc = 0x1483A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14839Cu;
            // 0x1483a0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146650u;
    if (runtime->hasFunction(0x146650u)) {
        auto targetFn = runtime->lookupFunction(0x146650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1483A4u; }
        if (ctx->pc != 0x1483A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146650_0x146650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1483A4u; }
        if (ctx->pc != 0x1483A4u) { return; }
    }
    ctx->pc = 0x1483A4u;
label_1483a4:
    // 0x1483a4: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x1483a4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1483a8: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1483a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1483ac: 0xc051ff8  jal         func_147FE0
    ctx->pc = 0x1483ACu;
    SET_GPR_U32(ctx, 31, 0x1483B4u);
    ctx->pc = 0x1483B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1483ACu;
            // 0x1483b0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147FE0u;
    if (runtime->hasFunction(0x147FE0u)) {
        auto targetFn = runtime->lookupFunction(0x147FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1483B4u; }
        if (ctx->pc != 0x1483B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1483B4u; }
        if (ctx->pc != 0x1483B4u) { return; }
    }
    ctx->pc = 0x1483B4u;
label_1483b4:
    // 0x1483b4: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x1483b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x1483b8: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1483B8u;
    {
        const bool branch_taken_0x1483b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1483BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1483B8u;
            // 0x1483bc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1483b8) {
            ctx->pc = 0x14842Cu;
            goto label_14842c;
        }
    }
    ctx->pc = 0x1483C0u;
    // 0x1483c0: 0x8e050130  lw          $a1, 0x130($s0)
    ctx->pc = 0x1483c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x1483c4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1483c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1483c8: 0xc051970  jal         func_1465C0
    ctx->pc = 0x1483C8u;
    SET_GPR_U32(ctx, 31, 0x1483D0u);
    ctx->pc = 0x1483CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1483C8u;
            // 0x1483cc: 0x8e060004  lw          $a2, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1465C0u;
    if (runtime->hasFunction(0x1465C0u)) {
        auto targetFn = runtime->lookupFunction(0x1465C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1483D0u; }
        if (ctx->pc != 0x1483D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001465C0_0x1465c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1483D0u; }
        if (ctx->pc != 0x1483D0u) { return; }
    }
    ctx->pc = 0x1483D0u;
label_1483d0:
    // 0x1483d0: 0x8e03018c  lw          $v1, 0x18C($s0)
    ctx->pc = 0x1483d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x1483d4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1483d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1483d8: 0x50620007  beql        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1483D8u;
    {
        const bool branch_taken_0x1483d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1483d8) {
            ctx->pc = 0x1483DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1483D8u;
            // 0x1483dc: 0x8e0300c4  lw          $v1, 0xC4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 196)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1483F8u;
            goto label_1483f8;
        }
    }
    ctx->pc = 0x1483E0u;
    // 0x1483e0: 0x56600005  bnel        $s3, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1483E0u;
    {
        const bool branch_taken_0x1483e0 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x1483e0) {
            ctx->pc = 0x1483E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1483E0u;
            // 0x1483e4: 0x8e0300c4  lw          $v1, 0xC4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 196)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1483F8u;
            goto label_1483f8;
        }
    }
    ctx->pc = 0x1483E8u;
    // 0x1483e8: 0x8e020138  lw          $v0, 0x138($s0)
    ctx->pc = 0x1483e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 312)));
    // 0x1483ec: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1483ecu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1483f0: 0xae020138  sw          $v0, 0x138($s0)
    ctx->pc = 0x1483f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 312), GPR_U32(ctx, 2));
    // 0x1483f4: 0x8e0300c4  lw          $v1, 0xC4($s0)
    ctx->pc = 0x1483f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 196)));
label_1483f8:
    // 0x1483f8: 0x8e020130  lw          $v0, 0x130($s0)
    ctx->pc = 0x1483f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x1483fc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1483fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x148400: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x148400u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x148404: 0x8e030138  lw          $v1, 0x138($s0)
    ctx->pc = 0x148404u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 312)));
    // 0x148408: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x148408u;
    {
        const bool branch_taken_0x148408 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x14840Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148408u;
            // 0x14840c: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148408) {
            ctx->pc = 0x14842Cu;
            goto label_14842c;
        }
    }
    ctx->pc = 0x148410u;
    // 0x148410: 0x8e020130  lw          $v0, 0x130($s0)
    ctx->pc = 0x148410u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x148414: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x148414u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x148418: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x148418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x14841c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x14841cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x148420: 0xae020130  sw          $v0, 0x130($s0)
    ctx->pc = 0x148420u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 304), GPR_U32(ctx, 2));
    // 0x148424: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x148424u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x148428: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x148428u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_14842c:
    // 0x14842c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x14842cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x148430: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x148430u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x148434: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x148434u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x148438: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x148438u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14843c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14843cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x148440: 0x3e00008  jr          $ra
    ctx->pc = 0x148440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148440u;
            // 0x148444: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148360u: goto label_148360;
            case 0x148378u: goto label_148378;
            case 0x148380u: goto label_148380;
            case 0x148390u: goto label_148390;
            case 0x148394u: goto label_148394;
            case 0x14839Cu: goto label_14839c;
            case 0x1483A4u: goto label_1483a4;
            case 0x1483B4u: goto label_1483b4;
            case 0x1483D0u: goto label_1483d0;
            case 0x1483F8u: goto label_1483f8;
            case 0x14842Cu: goto label_14842c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
