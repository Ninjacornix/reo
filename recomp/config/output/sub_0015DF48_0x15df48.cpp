#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DF48
// Address: 0x15df48 - 0x15e020
void sub_0015DF48_0x15df48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DF48_0x15df48");
#endif

    switch (ctx->pc) {
        case 0x15df74u: goto label_15df74;
        case 0x15df90u: goto label_15df90;
        case 0x15dfacu: goto label_15dfac;
        case 0x15dfd0u: goto label_15dfd0;
        case 0x15dfe0u: goto label_15dfe0;
        default: break;
    }

    ctx->pc = 0x15df48u;

    // 0x15df48: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15df48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15df4c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15df4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15df50: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15df50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15df54: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15df54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15df58: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15df58u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15df5c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15df5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15df60: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15df60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15df64: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15df64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15df68: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x15df68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x15df6c: 0xc05e4c2  jal         func_179308
    ctx->pc = 0x15DF6Cu;
    SET_GPR_U32(ctx, 31, 0x15DF74u);
    ctx->pc = 0x15DF70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF6Cu;
            // 0x15df70: 0x263200b4  addiu       $s2, $s1, 0xB4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 180));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179308u;
    if (runtime->hasFunction(0x179308u)) {
        auto targetFn = runtime->lookupFunction(0x179308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF74u; }
        if (ctx->pc != 0x15DF74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179308_0x179308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF74u; }
        if (ctx->pc != 0x15DF74u) { return; }
    }
    ctx->pc = 0x15DF74u;
label_15df74:
    // 0x15df74: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x15DF74u;
    {
        const bool branch_taken_0x15df74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DF78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF74u;
            // 0x15df78: 0x8fa20000  lw          $v0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15df74) {
            ctx->pc = 0x15DFE0u;
            goto label_15dfe0;
        }
    }
    ctx->pc = 0x15DF7Cu;
    // 0x15df7c: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x15DF7Cu;
    {
        const bool branch_taken_0x15df7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DF80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF7Cu;
            // 0x15df80: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15df7c) {
            ctx->pc = 0x15DFE0u;
            goto label_15dfe0;
        }
    }
    ctx->pc = 0x15DF84u;
    // 0x15df84: 0x240500e0  addiu       $a1, $zero, 0xE0
    ctx->pc = 0x15df84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x15df88: 0xc05e4fe  jal         func_1793F8
    ctx->pc = 0x15DF88u;
    SET_GPR_U32(ctx, 31, 0x15DF90u);
    ctx->pc = 0x15DF8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF88u;
            // 0x15df8c: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1793F8u;
    if (runtime->hasFunction(0x1793F8u)) {
        auto targetFn = runtime->lookupFunction(0x1793F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF90u; }
        if (ctx->pc != 0x15DF90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001793F8_0x1793f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF90u; }
        if (ctx->pc != 0x15DF90u) { return; }
    }
    ctx->pc = 0x15DF90u;
label_15df90:
    // 0x15df90: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x15DF90u;
    {
        const bool branch_taken_0x15df90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DF94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF90u;
            // 0x15df94: 0x8fa20004  lw          $v0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15df90) {
            ctx->pc = 0x15DFE0u;
            goto label_15dfe0;
        }
    }
    ctx->pc = 0x15DF98u;
    // 0x15df98: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x15DF98u;
    {
        const bool branch_taken_0x15df98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DF9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF98u;
            // 0x15df9c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15df98) {
            ctx->pc = 0x15DFE0u;
            goto label_15dfe0;
        }
    }
    ctx->pc = 0x15DFA0u;
    // 0x15dfa0: 0x240500e0  addiu       $a1, $zero, 0xE0
    ctx->pc = 0x15dfa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x15dfa4: 0xc05e856  jal         func_17A158
    ctx->pc = 0x15DFA4u;
    SET_GPR_U32(ctx, 31, 0x15DFACu);
    ctx->pc = 0x15DFA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DFA4u;
            // 0x15dfa8: 0x27a60008  addiu       $a2, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A158u;
    if (runtime->hasFunction(0x17A158u)) {
        auto targetFn = runtime->lookupFunction(0x17A158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DFACu; }
        if (ctx->pc != 0x15DFACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A158_0x17a158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DFACu; }
        if (ctx->pc != 0x15DFACu) { return; }
    }
    ctx->pc = 0x15DFACu;
label_15dfac:
    // 0x15dfac: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x15DFACu;
    {
        const bool branch_taken_0x15dfac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DFB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DFACu;
            // 0x15dfb0: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dfac) {
            ctx->pc = 0x15DFE0u;
            goto label_15dfe0;
        }
    }
    ctx->pc = 0x15DFB4u;
    // 0x15dfb4: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x15dfb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15dfb8: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15DFB8u;
    {
        const bool branch_taken_0x15dfb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x15DFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DFB8u;
            // 0x15dfbc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dfb8) {
            ctx->pc = 0x15DFD8u;
            goto label_15dfd8;
        }
    }
    ctx->pc = 0x15DFC0u;
    // 0x15dfc0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15dfc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15dfc4: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x15dfc4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x15dfc8: 0xc05855e  jal         func_161578
    ctx->pc = 0x15DFC8u;
    SET_GPR_U32(ctx, 31, 0x15DFD0u);
    ctx->pc = 0x15DFCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DFC8u;
            // 0x15dfcc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161578u;
    if (runtime->hasFunction(0x161578u)) {
        auto targetFn = runtime->lookupFunction(0x161578u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DFD0u; }
        if (ctx->pc != 0x15DFD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00161578_0x161578(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DFD0u; }
        if (ctx->pc != 0x15DFD0u) { return; }
    }
    ctx->pc = 0x15DFD0u;
label_15dfd0:
    // 0x15dfd0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15DFD0u;
    {
        const bool branch_taken_0x15dfd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DFD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DFD0u;
            // 0x15dfd4: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dfd0) {
            ctx->pc = 0x15DFE4u;
            goto label_15dfe4;
        }
    }
    ctx->pc = 0x15DFD8u;
label_15dfd8:
    // 0x15dfd8: 0xc05855e  jal         func_161578
    ctx->pc = 0x15DFD8u;
    SET_GPR_U32(ctx, 31, 0x15DFE0u);
    ctx->pc = 0x15DFDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DFD8u;
            // 0x15dfdc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161578u;
    if (runtime->hasFunction(0x161578u)) {
        auto targetFn = runtime->lookupFunction(0x161578u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DFE0u; }
        if (ctx->pc != 0x15DFE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00161578_0x161578(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DFE0u; }
        if (ctx->pc != 0x15DFE0u) { return; }
    }
    ctx->pc = 0x15DFE0u;
label_15dfe0:
    // 0x15dfe0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15dfe0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_15dfe4:
    // 0x15dfe4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15dfe4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15dfe8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15dfe8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15dfec: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x15dfecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15dff0: 0x3e00008  jr          $ra
    ctx->pc = 0x15DFF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DFF0u;
            // 0x15dff4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DF74u: goto label_15df74;
            case 0x15DF90u: goto label_15df90;
            case 0x15DFACu: goto label_15dfac;
            case 0x15DFD0u: goto label_15dfd0;
            case 0x15DFD8u: goto label_15dfd8;
            case 0x15DFE0u: goto label_15dfe0;
            case 0x15DFE4u: goto label_15dfe4;
            case 0x15E018u: goto label_15e018;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15DFF8u;
    // 0x15dff8: 0x248400b4  addiu       $a0, $a0, 0xB4
    ctx->pc = 0x15dff8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 180));
    // 0x15dffc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15dffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15e000: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x15e000u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15e004: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15e004u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e008: 0x14a20003  bne         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15E008u;
    {
        const bool branch_taken_0x15e008 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x15E00Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E008u;
            // 0x15e00c: 0x8c830004  lw          $v1, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e008) {
            ctx->pc = 0x15E018u;
            goto label_15e018;
        }
    }
    ctx->pc = 0x15E010u;
    // 0x15e010: 0x651026  xor         $v0, $v1, $a1
    ctx->pc = 0x15e010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 5));
    // 0x15e014: 0x2c460001  sltiu       $a2, $v0, 0x1
    ctx->pc = 0x15e014u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_15e018:
    // 0x15e018: 0x3e00008  jr          $ra
    ctx->pc = 0x15E018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E01Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E018u;
            // 0x15e01c: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DF74u: goto label_15df74;
            case 0x15DF90u: goto label_15df90;
            case 0x15DFACu: goto label_15dfac;
            case 0x15DFD0u: goto label_15dfd0;
            case 0x15DFD8u: goto label_15dfd8;
            case 0x15DFE0u: goto label_15dfe0;
            case 0x15DFE4u: goto label_15dfe4;
            case 0x15E018u: goto label_15e018;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E020u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
