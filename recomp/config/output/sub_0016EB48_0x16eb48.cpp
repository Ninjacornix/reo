#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016EB48
// Address: 0x16eb48 - 0x16ec20
void sub_0016EB48_0x16eb48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016EB48_0x16eb48");
#endif

    switch (ctx->pc) {
        case 0x16eb80u: goto label_16eb80;
        case 0x16eb90u: goto label_16eb90;
        case 0x16eba0u: goto label_16eba0;
        case 0x16ebb4u: goto label_16ebb4;
        case 0x16ebd0u: goto label_16ebd0;
        case 0x16ebe0u: goto label_16ebe0;
        case 0x16ebf8u: goto label_16ebf8;
        default: break;
    }

    ctx->pc = 0x16eb48u;

    // 0x16eb48: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16eb48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16eb4c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16eb4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16eb50: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16eb50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eb54: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16eb54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16eb58: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x16eb58u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eb5c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16eb5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16eb60: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16eb60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16eb64: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x16eb64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x16eb68: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16eb68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16eb6c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x16eb6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x16eb70: 0x8e421b30  lw          $v0, 0x1B30($s2)
    ctx->pc = 0x16eb70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 6960)));
    // 0x16eb74: 0x8c510000  lw          $s1, 0x0($v0)
    ctx->pc = 0x16eb74u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16eb78: 0xc05bb08  jal         func_16EC20
    ctx->pc = 0x16EB78u;
    SET_GPR_U32(ctx, 31, 0x16EB80u);
    ctx->pc = 0x16EB7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EB78u;
            // 0x16eb7c: 0x2455008c  addiu       $s5, $v0, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 140));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16EC20u;
    if (runtime->hasFunction(0x16EC20u)) {
        auto targetFn = runtime->lookupFunction(0x16EC20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EB80u; }
        if (ctx->pc != 0x16EB80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016EC20_0x16ec20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EB80u; }
        if (ctx->pc != 0x16EB80u) { return; }
    }
    ctx->pc = 0x16EB80u;
label_16eb80:
    // 0x16eb80: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16eb80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eb84: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16eb84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16eb88: 0xc04fffa  jal         func_13FFE8
    ctx->pc = 0x16EB88u;
    SET_GPR_U32(ctx, 31, 0x16EB90u);
    ctx->pc = 0x16EB8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EB88u;
            // 0x16eb8c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFE8u;
    if (runtime->hasFunction(0x13FFE8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EB90u; }
        if (ctx->pc != 0x16EB90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFE8_0x13ffe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EB90u; }
        if (ctx->pc != 0x16EB90u) { return; }
    }
    ctx->pc = 0x16EB90u;
label_16eb90:
    // 0x16eb90: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16eb90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eb94: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x16eb94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eb98: 0xc05644c  jal         func_159130
    ctx->pc = 0x16EB98u;
    SET_GPR_U32(ctx, 31, 0x16EBA0u);
    ctx->pc = 0x16EB9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EB98u;
            // 0x16eb9c: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159130u;
    if (runtime->hasFunction(0x159130u)) {
        auto targetFn = runtime->lookupFunction(0x159130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBA0u; }
        if (ctx->pc != 0x16EBA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159130_0x159130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBA0u; }
        if (ctx->pc != 0x16EBA0u) { return; }
    }
    ctx->pc = 0x16EBA0u;
label_16eba0:
    // 0x16eba0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16eba0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eba4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16eba4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eba8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16eba8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ebac: 0xc04fffa  jal         func_13FFE8
    ctx->pc = 0x16EBACu;
    SET_GPR_U32(ctx, 31, 0x16EBB4u);
    ctx->pc = 0x16EBB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EBACu;
            // 0x16ebb0: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFE8u;
    if (runtime->hasFunction(0x13FFE8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBB4u; }
        if (ctx->pc != 0x16EBB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFE8_0x13ffe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBB4u; }
        if (ctx->pc != 0x16EBB4u) { return; }
    }
    ctx->pc = 0x16EBB4u;
label_16ebb4:
    // 0x16ebb4: 0x548823  subu        $s1, $v0, $s4
    ctx->pc = 0x16ebb4u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x16ebb8: 0x3c07ff00  lui         $a3, 0xFF00
    ctx->pc = 0x16ebb8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)65280 << 16));
    // 0x16ebbc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16ebbcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ebc0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x16ebc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ebc4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x16ebc4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ebc8: 0xc05b592  jal         func_16D648
    ctx->pc = 0x16EBC8u;
    SET_GPR_U32(ctx, 31, 0x16EBD0u);
    ctx->pc = 0x16EBCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EBC8u;
            // 0x16ebcc: 0x34e70f07  ori         $a3, $a3, 0xF07 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)3847);
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D648u;
    if (runtime->hasFunction(0x16D648u)) {
        auto targetFn = runtime->lookupFunction(0x16D648u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBD0u; }
        if (ctx->pc != 0x16EBD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D648_0x16d648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBD0u; }
        if (ctx->pc != 0x16EBD0u) { return; }
    }
    ctx->pc = 0x16EBD0u;
label_16ebd0:
    // 0x16ebd0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16ebd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ebd4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16ebd4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ebd8: 0xc05b572  jal         func_16D5C8
    ctx->pc = 0x16EBD8u;
    SET_GPR_U32(ctx, 31, 0x16EBE0u);
    ctx->pc = 0x16EBDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EBD8u;
            // 0x16ebdc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D5C8u;
    if (runtime->hasFunction(0x16D5C8u)) {
        auto targetFn = runtime->lookupFunction(0x16D5C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBE0u; }
        if (ctx->pc != 0x16EBE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D5C8_0x16d5c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBE0u; }
        if (ctx->pc != 0x16EBE0u) { return; }
    }
    ctx->pc = 0x16EBE0u;
label_16ebe0:
    // 0x16ebe0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x16ebe0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ebe4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16ebe4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ebe8: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16EBE8u;
    {
        const bool branch_taken_0x16ebe8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x16EBECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EBE8u;
            // 0x16ebec: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ebe8) {
            ctx->pc = 0x16EBFCu;
            goto label_16ebfc;
        }
    }
    ctx->pc = 0x16EBF0u;
    // 0x16ebf0: 0xc05ce4a  jal         func_173928
    ctx->pc = 0x16EBF0u;
    SET_GPR_U32(ctx, 31, 0x16EBF8u);
    ctx->pc = 0x16EBF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EBF0u;
            // 0x16ebf4: 0x8ea60018  lw          $a2, 0x18($s5) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173928u;
    if (runtime->hasFunction(0x173928u)) {
        auto targetFn = runtime->lookupFunction(0x173928u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBF8u; }
        if (ctx->pc != 0x16EBF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173928_0x173928(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EBF8u; }
        if (ctx->pc != 0x16EBF8u) { return; }
    }
    ctx->pc = 0x16EBF8u;
label_16ebf8:
    // 0x16ebf8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16ebf8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16ebfc:
    // 0x16ebfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16ebfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16ec00: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16ec00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16ec04: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16ec04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16ec08: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16ec08u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16ec0c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16ec0cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16ec10: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16ec10u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16ec14: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16ec14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ec18: 0x3e00008  jr          $ra
    ctx->pc = 0x16EC18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16EC1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EC18u;
            // 0x16ec1c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16EB80u: goto label_16eb80;
            case 0x16EB90u: goto label_16eb90;
            case 0x16EBA0u: goto label_16eba0;
            case 0x16EBB4u: goto label_16ebb4;
            case 0x16EBD0u: goto label_16ebd0;
            case 0x16EBE0u: goto label_16ebe0;
            case 0x16EBF8u: goto label_16ebf8;
            case 0x16EBFCu: goto label_16ebfc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16EC20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
