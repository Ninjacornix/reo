#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4F90
// Address: 0x1d4f90 - 0x1d50b8
void sub_001D4F90_0x1d4f90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4F90_0x1d4f90");
#endif

    switch (ctx->pc) {
        case 0x1d4fe4u: goto label_1d4fe4;
        case 0x1d4ff4u: goto label_1d4ff4;
        case 0x1d5014u: goto label_1d5014;
        case 0x1d502cu: goto label_1d502c;
        case 0x1d5038u: goto label_1d5038;
        case 0x1d5090u: goto label_1d5090;
        default: break;
    }

    ctx->pc = 0x1d4f90u;

    // 0x1d4f90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d4f90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d4f94: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4f98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d4f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d4f9c: 0x80222650  lb          $v0, 0x2650($at)
    ctx->pc = 0x1d4f9cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 9808)));
    // 0x1d4fa0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4FA0u;
    {
        const bool branch_taken_0x1d4fa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FA0u;
            // 0x1d4fa4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4fa0) {
            ctx->pc = 0x1D4FB0u;
            goto label_1d4fb0;
        }
    }
    ctx->pc = 0x1D4FA8u;
    // 0x1d4fa8: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1D4FA8u;
    {
        const bool branch_taken_0x1d4fa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FA8u;
            // 0x1d4fac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4fa8) {
            ctx->pc = 0x1D50ACu;
            goto label_1d50ac;
        }
    }
    ctx->pc = 0x1D4FB0u;
label_1d4fb0:
    // 0x1d4fb0: 0x84222640  lh          $v0, 0x2640($at)
    ctx->pc = 0x1d4fb0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 9792)));
    // 0x1d4fb4: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1D4FB4u;
    {
        const bool branch_taken_0x1d4fb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FB4u;
            // 0x1d4fb8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4fb4) {
            ctx->pc = 0x1D4FECu;
            goto label_1d4fec;
        }
    }
    ctx->pc = 0x1D4FBCu;
    // 0x1d4fbc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4fbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4fc0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d4fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d4fc4: 0x80232648  lb          $v1, 0x2648($at)
    ctx->pc = 0x1d4fc4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 9800)));
    // 0x1d4fc8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d4fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d4fcc: 0x24426960  addiu       $v0, $v0, 0x6960
    ctx->pc = 0x1d4fccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26976));
    // 0x1d4fd0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d4fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d4fd4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d4fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4fd8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1d4fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d4fdc: 0x40f809  jalr        $v0
    ctx->pc = 0x1D4FDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1D4FE4u);
        ctx->pc = 0x1D4FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FDCu;
            // 0x1d4fe0: 0x24842648  addiu       $a0, $a0, 0x2648 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9800));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1D4FE4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D50ACu: goto label_1d50ac;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1D4FE4u; }
            if (ctx->pc != 0x1D4FE4u) { return; }
        }
        }
    }
    ctx->pc = 0x1D4FE4u;
label_1d4fe4:
    // 0x1d4fe4: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1D4FE4u;
    {
        const bool branch_taken_0x1d4fe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FE4u;
            // 0x1d4fe8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4fe4) {
            ctx->pc = 0x1D50ACu;
            goto label_1d50ac;
        }
    }
    ctx->pc = 0x1D4FECu;
label_1d4fec:
    // 0x1d4fec: 0xc075430  jal         func_1D50C0
    ctx->pc = 0x1D4FECu;
    SET_GPR_U32(ctx, 31, 0x1D4FF4u);
    ctx->pc = 0x1D50C0u;
    if (runtime->hasFunction(0x1D50C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D50C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4FF4u; }
        if (ctx->pc != 0x1D4FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D50C0_0x1d50c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4FF4u; }
        if (ctx->pc != 0x1D4FF4u) { return; }
    }
    ctx->pc = 0x1D4FF4u;
label_1d4ff4:
    // 0x1d4ff4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d4ff4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d4ff8: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4FF8u;
    {
        const bool branch_taken_0x1d4ff8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D4FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FF8u;
            // 0x1d4ffc: 0x3c050034  lui         $a1, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4ff8) {
            ctx->pc = 0x1D5008u;
            goto label_1d5008;
        }
    }
    ctx->pc = 0x1D5000u;
    // 0x1d5000: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1D5000u;
    {
        const bool branch_taken_0x1d5000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5000u;
            // 0x1d5004: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5000) {
            ctx->pc = 0x1D50ACu;
            goto label_1d50ac;
        }
    }
    ctx->pc = 0x1D5008u;
label_1d5008:
    // 0x1d5008: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d5008u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d500c: 0xc075526  jal         func_1D5498
    ctx->pc = 0x1D500Cu;
    SET_GPR_U32(ctx, 31, 0x1D5014u);
    ctx->pc = 0x1D5010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D500Cu;
            // 0x1d5010: 0x24a52690  addiu       $a1, $a1, 0x2690 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9872));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5498u;
    if (runtime->hasFunction(0x1D5498u)) {
        auto targetFn = runtime->lookupFunction(0x1D5498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5014u; }
        if (ctx->pc != 0x1D5014u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5498_0x1d5498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5014u; }
        if (ctx->pc != 0x1D5014u) { return; }
    }
    ctx->pc = 0x1D5014u;
label_1d5014:
    // 0x1d5014: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d5014u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d5018: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d5018u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d501c: 0x248427b0  addiu       $a0, $a0, 0x27B0
    ctx->pc = 0x1d501cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10160));
    // 0x1d5020: 0x24a52690  addiu       $a1, $a1, 0x2690
    ctx->pc = 0x1d5020u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9872));
    // 0x1d5024: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D5024u;
    SET_GPR_U32(ctx, 31, 0x1D502Cu);
    ctx->pc = 0x1D5028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5024u;
            // 0x1d5028: 0x24060088  addiu       $a2, $zero, 0x88 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D502Cu; }
        if (ctx->pc != 0x1D502Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D502Cu; }
        if (ctx->pc != 0x1D502Cu) { return; }
    }
    ctx->pc = 0x1D502Cu;
label_1d502c:
    // 0x1d502c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d502cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5030: 0xc075646  jal         func_1D5918
    ctx->pc = 0x1D5030u;
    SET_GPR_U32(ctx, 31, 0x1D5038u);
    ctx->pc = 0x1D5034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5030u;
            // 0x1d5034: 0x27a5001c  addiu       $a1, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5918u;
    if (runtime->hasFunction(0x1D5918u)) {
        auto targetFn = runtime->lookupFunction(0x1D5918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5038u; }
        if (ctx->pc != 0x1D5038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5038u; }
        if (ctx->pc != 0x1D5038u) { return; }
    }
    ctx->pc = 0x1D5038u;
label_1d5038:
    // 0x1d5038: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5038u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d503c: 0x8c222698  lw          $v0, 0x2698($at)
    ctx->pc = 0x1d503cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9880)));
    // 0x1d5040: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5040u;
    {
        const bool branch_taken_0x1d5040 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5040u;
            // 0x1d5044: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5040) {
            ctx->pc = 0x1D5050u;
            goto label_1d5050;
        }
    }
    ctx->pc = 0x1D5048u;
    // 0x1d5048: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D5048u;
    {
        const bool branch_taken_0x1d5048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D504Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5048u;
            // 0x1d504c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5048) {
            ctx->pc = 0x1D50ACu;
            goto label_1d50ac;
        }
    }
    ctx->pc = 0x1D5050u;
label_1d5050:
    // 0x1d5050: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d5050u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d5054: 0x8c232694  lw          $v1, 0x2694($at)
    ctx->pc = 0x1d5054u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9876)));
    // 0x1d5058: 0x24422660  addiu       $v0, $v0, 0x2660
    ctx->pc = 0x1d5058u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9824));
    // 0x1d505c: 0x24060006  addiu       $a2, $zero, 0x6
    ctx->pc = 0x1d505cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d5060: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5060u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d5064: 0xac222670  sw          $v0, 0x2670($at)
    ctx->pc = 0x1d5064u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9840), GPR_U32(ctx, 2));
    // 0x1d5068: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5068u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d506c: 0x8c222690  lw          $v0, 0x2690($at)
    ctx->pc = 0x1d506cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9872)));
    // 0x1d5070: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5070u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d5074: 0xa0232668  sb          $v1, 0x2668($at)
    ctx->pc = 0x1d5074u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 9832), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d5078: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5078u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d507c: 0xa0222669  sb          $v0, 0x2669($at)
    ctx->pc = 0x1d507cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 9833), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d5080: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d5080u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d5084: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d5084u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d5088: 0x24a52690  addiu       $a1, $a1, 0x2690
    ctx->pc = 0x1d5088u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9872));
    // 0x1d508c: 0x24422668  addiu       $v0, $v0, 0x2668
    ctx->pc = 0x1d508cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9832));
label_1d5090:
    // 0x1d5090: 0x62040  sll         $a0, $a2, 1
    ctx->pc = 0x1d5090u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1d5094: 0x461821  addu        $v1, $v0, $a2
    ctx->pc = 0x1d5094u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1d5098: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1d5098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1d509c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1d509cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1d50a0: 0x9484000c  lhu         $a0, 0xC($a0)
    ctx->pc = 0x1d50a0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1d50a4: 0x4c1fffa  bgez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D50A4u;
    {
        const bool branch_taken_0x1d50a4 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1D50A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50A4u;
            // 0x1d50a8: 0xa0640002  sb          $a0, 0x2($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d50a4) {
            ctx->pc = 0x1D5090u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5090;
        }
    }
    ctx->pc = 0x1D50ACu;
label_1d50ac:
    // 0x1d50ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d50acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d50b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D50B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D50B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50B0u;
            // 0x1d50b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D50ACu: goto label_1d50ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D50B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
