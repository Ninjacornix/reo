#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001464F0
// Address: 0x1464f0 - 0x1465c0
void sub_001464F0_0x1464f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001464F0_0x1464f0");
#endif

    switch (ctx->pc) {
        case 0x14652cu: goto label_14652c;
        case 0x14658cu: goto label_14658c;
        case 0x146594u: goto label_146594;
        default: break;
    }

    ctx->pc = 0x1464f0u;

    // 0x1464f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1464f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1464f4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1464f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1464f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1464f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1464fc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1464fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x146500: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x146500u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146504: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x146504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x146508: 0x8e03018c  lw          $v1, 0x18C($s0)
    ctx->pc = 0x146508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x14650c: 0x1462000a  bne         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x14650Cu;
    {
        const bool branch_taken_0x14650c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x146510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14650Cu;
            // 0x146510: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14650c) {
            ctx->pc = 0x146538u;
            goto label_146538;
        }
    }
    ctx->pc = 0x146514u;
    // 0x146514: 0x8e020138  lw          $v0, 0x138($s0)
    ctx->pc = 0x146514u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 312)));
    // 0x146518: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x146518u;
    {
        const bool branch_taken_0x146518 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14651Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146518u;
            // 0x14651c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146518) {
            ctx->pc = 0x146538u;
            goto label_146538;
        }
    }
    ctx->pc = 0x146520u;
    // 0x146520: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x146520u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x146524: 0xc05221c  jal         func_148870
    ctx->pc = 0x146524u;
    SET_GPR_U32(ctx, 31, 0x14652Cu);
    ctx->pc = 0x146528u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146524u;
            // 0x146528: 0x24a5df80  addiu       $a1, $a1, -0x2080 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14652Cu; }
        if (ctx->pc != 0x14652Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14652Cu; }
        if (ctx->pc != 0x14652Cu) { return; }
    }
    ctx->pc = 0x14652Cu;
label_14652c:
    // 0x14652c: 0xae000138  sw          $zero, 0x138($s0)
    ctx->pc = 0x14652cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 312), GPR_U32(ctx, 0));
    // 0x146530: 0x8e03018c  lw          $v1, 0x18C($s0)
    ctx->pc = 0x146530u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x146534: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x146534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_146538:
    // 0x146538: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x146538u;
    {
        const bool branch_taken_0x146538 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x14653Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146538u;
            // 0x14653c: 0x28620003  slti        $v0, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x146538) {
            ctx->pc = 0x146574u;
            goto label_146574;
        }
    }
    ctx->pc = 0x146540u;
    // 0x146540: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x146540u;
    {
        const bool branch_taken_0x146540 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146540u;
            // 0x146544: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146540) {
            ctx->pc = 0x146558u;
            goto label_146558;
        }
    }
    ctx->pc = 0x146548u;
    // 0x146548: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x146548u;
    {
        const bool branch_taken_0x146548 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x14654Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146548u;
            // 0x14654c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146548) {
            ctx->pc = 0x14656Cu;
            goto label_14656c;
        }
    }
    ctx->pc = 0x146550u;
    // 0x146550: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x146550u;
    {
        const bool branch_taken_0x146550 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146550u;
            // 0x146554: 0x8e1101d8  lw          $s1, 0x1D8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 472)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146550) {
            ctx->pc = 0x146580u;
            goto label_146580;
        }
    }
    ctx->pc = 0x146558u;
label_146558:
    // 0x146558: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x146558u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x14655c: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x14655Cu;
    {
        const bool branch_taken_0x14655c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x146560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14655Cu;
            // 0x146560: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14655c) {
            ctx->pc = 0x14657Cu;
            goto label_14657c;
        }
    }
    ctx->pc = 0x146564u;
    // 0x146564: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x146564u;
    {
        const bool branch_taken_0x146564 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146564u;
            // 0x146568: 0x8e1101d8  lw          $s1, 0x1D8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 472)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146564) {
            ctx->pc = 0x14658Cu;
            goto label_14658c;
        }
    }
    ctx->pc = 0x14656Cu;
label_14656c:
    // 0x14656c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x14656Cu;
    {
        const bool branch_taken_0x14656c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14656Cu;
            // 0x146570: 0x8e1101e8  lw          $s1, 0x1E8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14656c) {
            ctx->pc = 0x14658Cu;
            goto label_14658c;
        }
    }
    ctx->pc = 0x146574u;
label_146574:
    // 0x146574: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x146574u;
    {
        const bool branch_taken_0x146574 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146574u;
            // 0x146578: 0x8e1101f8  lw          $s1, 0x1F8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 504)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146574) {
            ctx->pc = 0x14658Cu;
            goto label_14658c;
        }
    }
    ctx->pc = 0x14657Cu;
label_14657c:
    // 0x14657c: 0x8e1101d8  lw          $s1, 0x1D8($s0)
    ctx->pc = 0x14657cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 472)));
label_146580:
    // 0x146580: 0x24a5dfa0  addiu       $a1, $a1, -0x2060
    ctx->pc = 0x146580u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959008));
    // 0x146584: 0xc05221c  jal         func_148870
    ctx->pc = 0x146584u;
    SET_GPR_U32(ctx, 31, 0x14658Cu);
    ctx->pc = 0x146588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146584u;
            // 0x146588: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14658Cu; }
        if (ctx->pc != 0x14658Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14658Cu; }
        if (ctx->pc != 0x14658Cu) { return; }
    }
    ctx->pc = 0x14658Cu;
label_14658c:
    // 0x14658c: 0xc051140  jal         func_144500
    ctx->pc = 0x14658Cu;
    SET_GPR_U32(ctx, 31, 0x146594u);
    ctx->pc = 0x146590u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14658Cu;
            // 0x146590: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144500u;
    if (runtime->hasFunction(0x144500u)) {
        auto targetFn = runtime->lookupFunction(0x144500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146594u; }
        if (ctx->pc != 0x146594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144500_0x144500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146594u; }
        if (ctx->pc != 0x146594u) { return; }
    }
    ctx->pc = 0x146594u;
label_146594:
    // 0x146594: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x146594u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146598: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x146598u;
    {
        const bool branch_taken_0x146598 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x14659Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146598u;
            // 0x14659c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146598) {
            ctx->pc = 0x1465A4u;
            goto label_1465a4;
        }
    }
    ctx->pc = 0x1465A0u;
    // 0x1465a0: 0xae220028  sw          $v0, 0x28($s1)
    ctx->pc = 0x1465a0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 2));
label_1465a4:
    // 0x1465a4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1465a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1465a8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1465a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1465ac: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1465acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1465b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1465b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1465b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1465B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1465B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1465B4u;
            // 0x1465b8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14652Cu: goto label_14652c;
            case 0x146538u: goto label_146538;
            case 0x146558u: goto label_146558;
            case 0x14656Cu: goto label_14656c;
            case 0x146574u: goto label_146574;
            case 0x14657Cu: goto label_14657c;
            case 0x146580u: goto label_146580;
            case 0x14658Cu: goto label_14658c;
            case 0x146594u: goto label_146594;
            case 0x1465A4u: goto label_1465a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1465BCu;
    // 0x1465bc: 0x0  nop
    ctx->pc = 0x1465bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
