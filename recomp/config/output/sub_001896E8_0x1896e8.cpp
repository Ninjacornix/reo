#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001896E8
// Address: 0x1896e8 - 0x1897d8
void sub_001896E8_0x1896e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001896E8_0x1896e8");
#endif

    switch (ctx->pc) {
        case 0x18974cu: goto label_18974c;
        case 0x189760u: goto label_189760;
        case 0x189790u: goto label_189790;
        default: break;
    }

    ctx->pc = 0x1896e8u;

    // 0x1896e8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1896e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1896ec: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1896ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1896f0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1896f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1896f4: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x1896f4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1896f8: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x1896f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x1896fc: 0xac440c00  sw          $a0, 0xC00($v0)
    ctx->pc = 0x1896fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 4));
    // 0x189700: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x189700u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x189704: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x189704u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x189708: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x189708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x18970c: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x18970cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189710: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x189710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x189714: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x189714u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189718: 0xae050004  sw          $a1, 0x4($s0)
    ctx->pc = 0x189718u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 5));
    // 0x18971c: 0x24840b88  addiu       $a0, $a0, 0xB88
    ctx->pc = 0x18971cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2952));
    // 0x189720: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189720u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x189724: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x189724u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189728: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x189728u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18972c: 0x34a5131a  ori         $a1, $a1, 0x131A
    ctx->pc = 0x18972cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4890);
    // 0x189730: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x189730u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x189734: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x189734u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189738: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x189738u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x18973c: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x18973cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189740: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x189740u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189744: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189744u;
    SET_GPR_U32(ctx, 31, 0x18974Cu);
    ctx->pc = 0x189748u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189744u;
            // 0x189748: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18974Cu; }
        if (ctx->pc != 0x18974Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18974Cu; }
        if (ctx->pc != 0x18974Cu) { return; }
    }
    ctx->pc = 0x18974Cu;
label_18974c:
    // 0x18974c: 0x4430006  bgezl       $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x18974Cu;
    {
        const bool branch_taken_0x18974c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x18974c) {
            ctx->pc = 0x189750u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18974Cu;
            // 0x189750: 0x8e02020c  lw          $v0, 0x20C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 524)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x189768u;
            goto label_189768;
        }
    }
    ctx->pc = 0x189754u;
    // 0x189754: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189754u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189758: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189758u;
    SET_GPR_U32(ctx, 31, 0x189760u);
    ctx->pc = 0x18975Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189758u;
            // 0x18975c: 0x24841ae0  addiu       $a0, $a0, 0x1AE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189760u; }
        if (ctx->pc != 0x189760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189760u; }
        if (ctx->pc != 0x189760u) { return; }
    }
    ctx->pc = 0x189760u;
label_189760:
    // 0x189760: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x189760u;
    {
        const bool branch_taken_0x189760 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189760u;
            // 0x189764: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189760) {
            ctx->pc = 0x1897BCu;
            goto label_1897bc;
        }
    }
    ctx->pc = 0x189768u;
label_189768:
    // 0x189768: 0x4400015  bltz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x189768u;
    {
        const bool branch_taken_0x189768 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x18976Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189768u;
            // 0x18976c: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189768) {
            ctx->pc = 0x1897C0u;
            goto label_1897c0;
        }
    }
    ctx->pc = 0x189770u;
    // 0x189770: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x189770u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x189774: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x189774u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x189778: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x189778u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x18977c: 0x1840000e  blez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x18977Cu;
    {
        const bool branch_taken_0x18977c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x189780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18977Cu;
            // 0x189780: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18977c) {
            ctx->pc = 0x1897B8u;
            goto label_1897b8;
        }
    }
    ctx->pc = 0x189784u;
    // 0x189784: 0x2606000c  addiu       $a2, $s0, 0xC
    ctx->pc = 0x189784u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x189788: 0xc51021  addu        $v0, $a2, $a1
    ctx->pc = 0x189788u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x18978c: 0x0  nop
    ctx->pc = 0x18978cu;
    // NOP
label_189790:
    // 0x189790: 0x2452021  addu        $a0, $s2, $a1
    ctx->pc = 0x189790u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x189794: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x189794u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x189798: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x189798u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x18979c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x18979cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1897a0: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1897a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1897a4: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x1897a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1897a8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1897A8u;
    {
        const bool branch_taken_0x1897a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1897ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1897A8u;
            // 0x1897ac: 0xc51021  addu        $v0, $a2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1897a8) {
            ctx->pc = 0x189790u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189790;
        }
    }
    ctx->pc = 0x1897B0u;
    // 0x1897b0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1897B0u;
    {
        const bool branch_taken_0x1897b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1897B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1897B0u;
            // 0x1897b4: 0x8e02020c  lw          $v0, 0x20C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 524)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1897b0) {
            ctx->pc = 0x1897BCu;
            goto label_1897bc;
        }
    }
    ctx->pc = 0x1897B8u;
label_1897b8:
    // 0x1897b8: 0x8e02020c  lw          $v0, 0x20C($s0)
    ctx->pc = 0x1897b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 524)));
label_1897bc:
    // 0x1897bc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1897bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1897c0:
    // 0x1897c0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1897c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1897c4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1897c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1897c8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1897c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1897cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1897CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1897D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1897CCu;
            // 0x1897d0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18974Cu: goto label_18974c;
            case 0x189760u: goto label_189760;
            case 0x189768u: goto label_189768;
            case 0x189790u: goto label_189790;
            case 0x1897B8u: goto label_1897b8;
            case 0x1897BCu: goto label_1897bc;
            case 0x1897C0u: goto label_1897c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1897D4u;
    // 0x1897d4: 0x0  nop
    ctx->pc = 0x1897d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
