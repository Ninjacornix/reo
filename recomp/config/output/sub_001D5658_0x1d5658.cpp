#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5658
// Address: 0x1d5658 - 0x1d5730
void sub_001D5658_0x1d5658(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5658_0x1d5658");
#endif

    switch (ctx->pc) {
        case 0x1d56b4u: goto label_1d56b4;
        case 0x1d56e8u: goto label_1d56e8;
        case 0x1d56fcu: goto label_1d56fc;
        default: break;
    }

    ctx->pc = 0x1d5658u;

    // 0x1d5658: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d5658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d565c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d565cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d5660: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1d5660u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1d5664: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x1d5664u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d5668: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d5668u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d566c: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d566cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d5670: 0x8c446998  lw          $a0, 0x6998($v0)
    ctx->pc = 0x1d5670u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 27032)));
    // 0x1d5674: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1d5674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1d5678: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d5678u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d567c: 0x10820026  beq         $a0, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x1D567Cu;
    {
        const bool branch_taken_0x1d567c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D5680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D567Cu;
            // 0x1d5680: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d567c) {
            ctx->pc = 0x1D5718u;
            goto label_1d5718;
        }
    }
    ctx->pc = 0x1D5684u;
    // 0x1d5684: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d5684u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d5688: 0x8c622840  lw          $v0, 0x2840($v1)
    ctx->pc = 0x1d5688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10304)));
    // 0x1d568c: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1d568cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d5690: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5690u;
    {
        const bool branch_taken_0x1d5690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5690u;
            // 0x1d5694: 0x24722840  addiu       $s2, $v1, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5690) {
            ctx->pc = 0x1D56A0u;
            goto label_1d56a0;
        }
    }
    ctx->pc = 0x1D5698u;
    // 0x1d5698: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1D5698u;
    {
        const bool branch_taken_0x1d5698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D569Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5698u;
            // 0x1d569c: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5698) {
            ctx->pc = 0x1D5718u;
            goto label_1d5718;
        }
    }
    ctx->pc = 0x1D56A0u;
label_1d56a0:
    // 0x1d56a0: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d56a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d56a4: 0x24502940  addiu       $s0, $v0, 0x2940
    ctx->pc = 0x1d56a4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 10560));
    // 0x1d56a8: 0xa0512940  sb          $s1, 0x2940($v0)
    ctx->pc = 0x1d56a8u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 10560), (uint8_t)GPR_U32(ctx, 17));
    // 0x1d56ac: 0xc045198  jal         func_114660
    ctx->pc = 0x1D56ACu;
    SET_GPR_U32(ctx, 31, 0x1D56B4u);
    ctx->pc = 0x1D56B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56ACu;
            // 0x1d56b0: 0xa2050001  sb          $a1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56B4u; }
        if (ctx->pc != 0x1D56B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56B4u; }
        if (ctx->pc != 0x1D56B4u) { return; }
    }
    ctx->pc = 0x1D56B4u;
label_1d56b4:
    // 0x1d56b4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d56b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d56b8: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1d56b8u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1d56bc: 0x3c0b001d  lui         $t3, 0x1D
    ctx->pc = 0x1d56bcu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)29 << 16));
    // 0x1d56c0: 0x248428e0  addiu       $a0, $a0, 0x28E0
    ctx->pc = 0x1d56c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10464));
    // 0x1d56c4: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1d56c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d56c8: 0x25292980  addiu       $t1, $t1, 0x2980
    ctx->pc = 0x1d56c8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 10624));
    // 0x1d56cc: 0x256b59b8  addiu       $t3, $t3, 0x59B8
    ctx->pc = 0x1d56ccu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 22968));
    // 0x1d56d0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1d56d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1d56d4: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1d56d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d56d8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d56d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d56dc: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1d56dcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1d56e0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1D56E0u;
    SET_GPR_U32(ctx, 31, 0x1D56E8u);
    ctx->pc = 0x1D56E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56E0u;
            // 0x1d56e4: 0x240a0010  addiu       $t2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56E8u; }
        if (ctx->pc != 0x1D56E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56E8u; }
        if (ctx->pc != 0x1D56E8u) { return; }
    }
    ctx->pc = 0x1D56E8u;
label_1d56e8:
    // 0x1d56e8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D56E8u;
    {
        const bool branch_taken_0x1d56e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D56ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56E8u;
            // 0x1d56ec: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d56e8) {
            ctx->pc = 0x1D5704u;
            goto label_1d5704;
        }
    }
    ctx->pc = 0x1D56F0u;
    // 0x1d56f0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1d56f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d56f4: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D56F4u;
    SET_GPR_U32(ctx, 31, 0x1D56FCu);
    ctx->pc = 0x1D56F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56F4u;
            // 0x1d56f8: 0x24846ee0  addiu       $a0, $a0, 0x6EE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56FCu; }
        if (ctx->pc != 0x1D56FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56FCu; }
        if (ctx->pc != 0x1D56FCu) { return; }
    }
    ctx->pc = 0x1D56FCu;
label_1d56fc:
    // 0x1d56fc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D56FCu;
    {
        const bool branch_taken_0x1d56fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56FCu;
            // 0x1d5700: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d56fc) {
            ctx->pc = 0x1D5718u;
            goto label_1d5718;
        }
    }
    ctx->pc = 0x1D5704u;
label_1d5704:
    // 0x1d5704: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1d5704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d5708: 0xae510094  sw          $s1, 0x94($s2)
    ctx->pc = 0x1d5708u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 148), GPR_U32(ctx, 17));
    // 0x1d570c: 0xae420090  sw          $v0, 0x90($s2)
    ctx->pc = 0x1d570cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 144), GPR_U32(ctx, 2));
    // 0x1d5710: 0xae400098  sw          $zero, 0x98($s2)
    ctx->pc = 0x1d5710u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 152), GPR_U32(ctx, 0));
    // 0x1d5714: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5714u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5718:
    // 0x1d5718: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d5718u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d571c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1d571cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d5720: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1d5720u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d5724: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1d5724u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d5728: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5728u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D572Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5728u;
            // 0x1d572c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D56A0u: goto label_1d56a0;
            case 0x1D56B4u: goto label_1d56b4;
            case 0x1D56E8u: goto label_1d56e8;
            case 0x1D56FCu: goto label_1d56fc;
            case 0x1D5704u: goto label_1d5704;
            case 0x1D5718u: goto label_1d5718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5730u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
