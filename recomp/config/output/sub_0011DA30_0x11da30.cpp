#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DA30
// Address: 0x11da30 - 0x11dae0
void sub_0011DA30_0x11da30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DA30_0x11da30");
#endif

    switch (ctx->pc) {
        case 0x11da48u: goto label_11da48;
        case 0x11da68u: goto label_11da68;
        case 0x11da80u: goto label_11da80;
        case 0x11da88u: goto label_11da88;
        case 0x11da90u: goto label_11da90;
        case 0x11da9cu: goto label_11da9c;
        case 0x11daa0u: goto label_11daa0;
        case 0x11daa8u: goto label_11daa8;
        case 0x11dab8u: goto label_11dab8;
        default: break;
    }

    ctx->pc = 0x11da30u;

    // 0x11da30: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11da30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11da34: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11da34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11da38: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11da38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11da3c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11da3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11da40: 0xc047672  jal         func_11D9C8
    ctx->pc = 0x11DA40u;
    SET_GPR_U32(ctx, 31, 0x11DA48u);
    ctx->pc = 0x11DA44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA40u;
            // 0x11da44: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D9C8u;
    if (runtime->hasFunction(0x11D9C8u)) {
        auto targetFn = runtime->lookupFunction(0x11D9C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA48u; }
        if (ctx->pc != 0x11DA48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D9C8_0x11d9c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA48u; }
        if (ctx->pc != 0x11DA48u) { return; }
    }
    ctx->pc = 0x11DA48u;
label_11da48:
    // 0x11da48: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x11DA48u;
    {
        const bool branch_taken_0x11da48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11DA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA48u;
            // 0x11da4c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11da48) {
            ctx->pc = 0x11DAC4u;
            goto label_11dac4;
        }
    }
    ctx->pc = 0x11DA50u;
    // 0x11da50: 0x24120002  addiu       $s2, $zero, 0x2
    ctx->pc = 0x11da50u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11da54: 0x2450ac20  addiu       $s0, $v0, -0x53E0
    ctx->pc = 0x11da54u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945824));
    // 0x11da58: 0x8c44ac20  lw          $a0, -0x53E0($v0)
    ctx->pc = 0x11da58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294945824)));
    // 0x11da5c: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x11da5cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11da60: 0xc047658  jal         func_11D960
    ctx->pc = 0x11DA60u;
    SET_GPR_U32(ctx, 31, 0x11DA68u);
    ctx->pc = 0x11DA64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA60u;
            // 0x11da64: 0x26110010  addiu       $s1, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D960u;
    if (runtime->hasFunction(0x11D960u)) {
        auto targetFn = runtime->lookupFunction(0x11D960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA68u; }
        if (ctx->pc != 0x11DA68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D960_0x11d960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA68u; }
        if (ctx->pc != 0x11DA68u) { return; }
    }
    ctx->pc = 0x11DA68u;
label_11da68:
    // 0x11da68: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x11da68u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x11da6c: 0x3c048007  lui         $a0, 0x8007
    ctx->pc = 0x11da6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32775 << 16));
    // 0x11da70: 0x240607a8  addiu       $a2, $zero, 0x7A8
    ctx->pc = 0x11da70u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1960));
    // 0x11da74: 0x24a5a478  addiu       $a1, $a1, -0x5B88
    ctx->pc = 0x11da74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294943864));
    // 0x11da78: 0xc04765c  jal         func_11D970
    ctx->pc = 0x11DA78u;
    SET_GPR_U32(ctx, 31, 0x11DA80u);
    ctx->pc = 0x11DA7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA78u;
            // 0x11da7c: 0x34844000  ori         $a0, $a0, 0x4000 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)16384);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D970u;
    if (runtime->hasFunction(0x11D970u)) {
        auto targetFn = runtime->lookupFunction(0x11D970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA80u; }
        if (ctx->pc != 0x11DA80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D970_0x11d970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA80u; }
        if (ctx->pc != 0x11DA80u) { return; }
    }
    ctx->pc = 0x11DA80u;
label_11da80:
    // 0x11da80: 0xc045228  jal         func_1148A0
    ctx->pc = 0x11DA80u;
    SET_GPR_U32(ctx, 31, 0x11DA88u);
    ctx->pc = 0x11DA84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA80u;
            // 0x11da84: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA88u; }
        if (ctx->pc != 0x11DA88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA88u; }
        if (ctx->pc != 0x11DA88u) { return; }
    }
    ctx->pc = 0x11DA88u;
label_11da88:
    // 0x11da88: 0xc045228  jal         func_1148A0
    ctx->pc = 0x11DA88u;
    SET_GPR_U32(ctx, 31, 0x11DA90u);
    ctx->pc = 0x11DA8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA88u;
            // 0x11da8c: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA90u; }
        if (ctx->pc != 0x11DA90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA90u; }
        if (ctx->pc != 0x11DA90u) { return; }
    }
    ctx->pc = 0x11DA90u;
label_11da90:
    // 0x11da90: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x11da90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11da94: 0xc047658  jal         func_11D960
    ctx->pc = 0x11DA94u;
    SET_GPR_U32(ctx, 31, 0x11DA9Cu);
    ctx->pc = 0x11DA98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA94u;
            // 0x11da98: 0x8e05000c  lw          $a1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D960u;
    if (runtime->hasFunction(0x11D960u)) {
        auto targetFn = runtime->lookupFunction(0x11D960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA9Cu; }
        if (ctx->pc != 0x11DA9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D960_0x11d960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA9Cu; }
        if (ctx->pc != 0x11DA9Cu) { return; }
    }
    ctx->pc = 0x11DA9Cu;
label_11da9c:
    // 0x11da9c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x11da9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_11daa0:
    // 0x11daa0: 0xc04766e  jal         func_11D9B8
    ctx->pc = 0x11DAA0u;
    SET_GPR_U32(ctx, 31, 0x11DAA8u);
    ctx->pc = 0x11DAA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DAA0u;
            // 0x11daa4: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D9B8u;
    if (runtime->hasFunction(0x11D9B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D9B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DAA8u; }
        if (ctx->pc != 0x11DAA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D9B8_0x11d9b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DAA8u; }
        if (ctx->pc != 0x11DAA8u) { return; }
    }
    ctx->pc = 0x11DAA8u;
label_11daa8:
    // 0x11daa8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x11daa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11daac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11daacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dab0: 0xc047658  jal         func_11D960
    ctx->pc = 0x11DAB0u;
    SET_GPR_U32(ctx, 31, 0x11DAB8u);
    ctx->pc = 0x11DAB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DAB0u;
            // 0x11dab4: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D960u;
    if (runtime->hasFunction(0x11D960u)) {
        auto targetFn = runtime->lookupFunction(0x11D960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DAB8u; }
        if (ctx->pc != 0x11DAB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D960_0x11d960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DAB8u; }
        if (ctx->pc != 0x11DAB8u) { return; }
    }
    ctx->pc = 0x11DAB8u;
label_11dab8:
    // 0x11dab8: 0x2e420003  sltiu       $v0, $s2, 0x3
    ctx->pc = 0x11dab8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x11dabc: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11DABCu;
    {
        const bool branch_taken_0x11dabc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11dabc) {
            ctx->pc = 0x11DAC0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11DABCu;
            // 0x11dac0: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11DAA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11daa0;
        }
    }
    ctx->pc = 0x11DAC4u;
label_11dac4:
    // 0x11dac4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11dac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11dac8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11dac8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11dacc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11daccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11dad0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11dad0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dad4: 0x3e00008  jr          $ra
    ctx->pc = 0x11DAD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DAD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DAD4u;
            // 0x11dad8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DA48u: goto label_11da48;
            case 0x11DA68u: goto label_11da68;
            case 0x11DA80u: goto label_11da80;
            case 0x11DA88u: goto label_11da88;
            case 0x11DA90u: goto label_11da90;
            case 0x11DA9Cu: goto label_11da9c;
            case 0x11DAA0u: goto label_11daa0;
            case 0x11DAA8u: goto label_11daa8;
            case 0x11DAB8u: goto label_11dab8;
            case 0x11DAC4u: goto label_11dac4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DADCu;
    // 0x11dadc: 0x0  nop
    ctx->pc = 0x11dadcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
