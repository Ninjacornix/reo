#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012EF90
// Address: 0x12ef90 - 0x12f090
void sub_0012EF90_0x12ef90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012EF90_0x12ef90");
#endif

    switch (ctx->pc) {
        case 0x12effcu: goto label_12effc;
        case 0x12f024u: goto label_12f024;
        case 0x12f03cu: goto label_12f03c;
        case 0x12f050u: goto label_12f050;
        case 0x12f064u: goto label_12f064;
        default: break;
    }

    ctx->pc = 0x12ef90u;

    // 0x12ef90: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12ef90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12ef94: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12ef94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12ef98: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12ef98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x12ef9c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x12ef9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x12efa0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x12efa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x12efa4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x12efa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x12efa8: 0x8c82006c  lw          $v0, 0x6C($a0)
    ctx->pc = 0x12efa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 108)));
    // 0x12efac: 0x8c92000c  lw          $s2, 0xC($a0)
    ctx->pc = 0x12efacu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12efb0: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12EFB0u;
    {
        const bool branch_taken_0x12efb0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x12EFB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EFB0u;
            // 0x12efb4: 0x8c85002c  lw          $a1, 0x2C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12efb0) {
            ctx->pc = 0x12EFC0u;
            goto label_12efc0;
        }
    }
    ctx->pc = 0x12EFB8u;
    // 0x12efb8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x12EFB8u;
    {
        const bool branch_taken_0x12efb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EFB8u;
            // 0x12efbc: 0x8c910050  lw          $s1, 0x50($a0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12efb8) {
            ctx->pc = 0x12EFE4u;
            goto label_12efe4;
        }
    }
    ctx->pc = 0x12EFC0u;
label_12efc0:
    // 0x12efc0: 0x8c820050  lw          $v0, 0x50($a0)
    ctx->pc = 0x12efc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 80)));
    // 0x12efc4: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x12efc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12efc8: 0x244307ff  addiu       $v1, $v0, 0x7FF
    ctx->pc = 0x12efc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x12efcc: 0x24420ffe  addiu       $v0, $v0, 0xFFE
    ctx->pc = 0x12efccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4094));
    // 0x12efd0: 0x28640000  slti        $a0, $v1, 0x0
    ctx->pc = 0x12efd0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x12efd4: 0x44180b  movn        $v1, $v0, $a0
    ctx->pc = 0x12efd4u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 2));
    // 0x12efd8: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x12efd8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x12efdc: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x12efdcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x12efe0: 0x658823  subu        $s1, $v1, $a1
    ctx->pc = 0x12efe0u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_12efe4:
    // 0x12efe4: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x12efe4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12efe8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x12efe8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12efec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12efecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12eff0: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x12eff0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x12eff4: 0x40f809  jalr        $v0
    ctx->pc = 0x12EFF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12EFFCu);
        ctx->pc = 0x12EFF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EFF4u;
            // 0x12eff8: 0x2630fffc  addiu       $s0, $s1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967292));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12EFFCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12EFC0u: goto label_12efc0;
            case 0x12EFE4u: goto label_12efe4;
            case 0x12EFFCu: goto label_12effc;
            case 0x12F024u: goto label_12f024;
            case 0x12F03Cu: goto label_12f03c;
            case 0x12F050u: goto label_12f050;
            case 0x12F064u: goto label_12f064;
            case 0x12F06Cu: goto label_12f06c;
            case 0x12F070u: goto label_12f070;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12EFFCu; }
            if (ctx->pc != 0x12EFFCu) { return; }
        }
        }
    }
    ctx->pc = 0x12EFFCu;
label_12effc:
    // 0x12effc: 0x51182a  slt         $v1, $v0, $s1
    ctx->pc = 0x12effcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x12f000: 0x1460001b  bnez        $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x12F000u;
    {
        const bool branch_taken_0x12f000 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12F004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F000u;
            // 0x12f004: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f000) {
            ctx->pc = 0x12F070u;
            goto label_12f070;
        }
    }
    ctx->pc = 0x12F008u;
    // 0x12f008: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12f008u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f00c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f00cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f010: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f010u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f014: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x12f014u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f018: 0x34028001  ori         $v0, $zero, 0x8001
    ctx->pc = 0x12f018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x12f01c: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F01Cu;
    SET_GPR_U32(ctx, 31, 0x12F024u);
    ctx->pc = 0x12F020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F01Cu;
            // 0x12f020: 0xa7a20000  sh          $v0, 0x0($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F024u; }
        if (ctx->pc != 0x12F024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F024u; }
        if (ctx->pc != 0x12F024u) { return; }
    }
    ctx->pc = 0x12F024u;
label_12f024:
    // 0x12f024: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12f024u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f028: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f028u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f02c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f02cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f030: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x12f030u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f034: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F034u;
    SET_GPR_U32(ctx, 31, 0x12F03Cu);
    ctx->pc = 0x12F038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F034u;
            // 0x12f038: 0xa7b00000  sh          $s0, 0x0($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 0), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F03Cu; }
        if (ctx->pc != 0x12F03Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F03Cu; }
        if (ctx->pc != 0x12F03Cu) { return; }
    }
    ctx->pc = 0x12F03Cu;
label_12f03c:
    // 0x12f03c: 0x1a00000b  blez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x12F03Cu;
    {
        const bool branch_taken_0x12f03c = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x12F040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F03Cu;
            // 0x12f040: 0xa3a00002  sb          $zero, 0x2($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f03c) {
            ctx->pc = 0x12F06Cu;
            goto label_12f06c;
        }
    }
    ctx->pc = 0x12F044u;
    // 0x12f044: 0x27b30002  addiu       $s3, $sp, 0x2
    ctx->pc = 0x12f044u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 2));
    // 0x12f048: 0x2630fffc  addiu       $s0, $s1, -0x4
    ctx->pc = 0x12f048u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967292));
    // 0x12f04c: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x12f04cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
label_12f050:
    // 0x12f050: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x12f050u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f054: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f054u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f058: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f058u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f05c: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F05Cu;
    SET_GPR_U32(ctx, 31, 0x12F064u);
    ctx->pc = 0x12F060u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F05Cu;
            // 0x12f060: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F064u; }
        if (ctx->pc != 0x12F064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F064u; }
        if (ctx->pc != 0x12F064u) { return; }
    }
    ctx->pc = 0x12F064u;
label_12f064:
    // 0x12f064: 0x1600fffa  bnez        $s0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x12F064u;
    {
        const bool branch_taken_0x12f064 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x12F068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F064u;
            // 0x12f068: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f064) {
            ctx->pc = 0x12F050u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12f050;
        }
    }
    ctx->pc = 0x12F06Cu;
label_12f06c:
    // 0x12f06c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x12f06cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12f070:
    // 0x12f070: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12f070u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12f074: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12f074u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12f078: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x12f078u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12f07c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x12f07cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12f080: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x12f080u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12f084: 0x3e00008  jr          $ra
    ctx->pc = 0x12F084u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12F088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F084u;
            // 0x12f088: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12EFC0u: goto label_12efc0;
            case 0x12EFE4u: goto label_12efe4;
            case 0x12EFFCu: goto label_12effc;
            case 0x12F024u: goto label_12f024;
            case 0x12F03Cu: goto label_12f03c;
            case 0x12F050u: goto label_12f050;
            case 0x12F064u: goto label_12f064;
            case 0x12F06Cu: goto label_12f06c;
            case 0x12F070u: goto label_12f070;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12F08Cu;
    // 0x12f08c: 0x0  nop
    ctx->pc = 0x12f08cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
