#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016CF58
// Address: 0x16cf58 - 0x16d1b0
void sub_0016CF58_0x16cf58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016CF58_0x16cf58");
#endif

    switch (ctx->pc) {
        case 0x16cfa8u: goto label_16cfa8;
        case 0x16cfb8u: goto label_16cfb8;
        case 0x16cfccu: goto label_16cfcc;
        case 0x16cfe0u: goto label_16cfe0;
        case 0x16d004u: goto label_16d004;
        case 0x16d024u: goto label_16d024;
        case 0x16d038u: goto label_16d038;
        case 0x16d040u: goto label_16d040;
        case 0x16d050u: goto label_16d050;
        case 0x16d068u: goto label_16d068;
        case 0x16d078u: goto label_16d078;
        case 0x16d090u: goto label_16d090;
        case 0x16d0a0u: goto label_16d0a0;
        case 0x16d0d0u: goto label_16d0d0;
        case 0x16d0ecu: goto label_16d0ec;
        case 0x16d124u: goto label_16d124;
        case 0x16d134u: goto label_16d134;
        case 0x16d144u: goto label_16d144;
        case 0x16d160u: goto label_16d160;
        case 0x16d17cu: goto label_16d17c;
        default: break;
    }

    ctx->pc = 0x16cf58u;

    // 0x16cf58: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x16cf58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x16cf5c: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x16cf5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x16cf60: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x16cf60u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cf64: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16cf64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16cf68: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16cf68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cf6c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16cf6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x16cf70: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16cf70u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cf74: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x16cf74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x16cf78: 0x2614094c  addiu       $s4, $s0, 0x94C
    ctx->pc = 0x16cf78u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 2380));
    // 0x16cf7c: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x16cf7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x16cf80: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x16cf80u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cf84: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x16cf84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x16cf88: 0x26021b28  addiu       $v0, $s0, 0x1B28
    ctx->pc = 0x16cf88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 6952));
    // 0x16cf8c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x16cf8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x16cf90: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x16cf90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x16cf94: 0xaea00000  sw          $zero, 0x0($s5)
    ctx->pc = 0x16cf94u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x16cf98: 0x8c520010  lw          $s2, 0x10($v0)
    ctx->pc = 0x16cf98u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x16cf9c: 0x8c530008  lw          $s3, 0x8($v0)
    ctx->pc = 0x16cf9cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x16cfa0: 0xc05c806  jal         func_172018
    ctx->pc = 0x16CFA0u;
    SET_GPR_U32(ctx, 31, 0x16CFA8u);
    ctx->pc = 0x16CFA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFA0u;
            // 0x16cfa4: 0xae800020  sw          $zero, 0x20($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 32), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172018u;
    if (runtime->hasFunction(0x172018u)) {
        auto targetFn = runtime->lookupFunction(0x172018u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CFA8u; }
        if (ctx->pc != 0x16CFA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172018_0x172018(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CFA8u; }
        if (ctx->pc != 0x16CFA8u) { return; }
    }
    ctx->pc = 0x16CFA8u;
label_16cfa8:
    // 0x16cfa8: 0x5440000f  bnel        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x16CFA8u;
    {
        const bool branch_taken_0x16cfa8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16cfa8) {
            ctx->pc = 0x16CFACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFA8u;
            // 0x16cfac: 0x8e620078  lw          $v0, 0x78($s3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 120)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16CFE8u;
            goto label_16cfe8;
        }
    }
    ctx->pc = 0x16CFB0u;
    // 0x16cfb0: 0xc05b58c  jal         func_16D630
    ctx->pc = 0x16CFB0u;
    SET_GPR_U32(ctx, 31, 0x16CFB8u);
    ctx->pc = 0x16CFB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFB0u;
            // 0x16cfb4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D630u;
    if (runtime->hasFunction(0x16D630u)) {
        auto targetFn = runtime->lookupFunction(0x16D630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CFB8u; }
        if (ctx->pc != 0x16CFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D630_0x16d630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CFB8u; }
        if (ctx->pc != 0x16CFB8u) { return; }
    }
    ctx->pc = 0x16CFB8u;
label_16cfb8:
    // 0x16cfb8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16cfb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16cfbc: 0x54430006  bnel        $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x16CFBCu;
    {
        const bool branch_taken_0x16cfbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x16cfbc) {
            ctx->pc = 0x16CFC0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFBCu;
            // 0x16cfc0: 0xae830020  sw          $v1, 0x20($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 32), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16CFD8u;
            goto label_16cfd8;
        }
    }
    ctx->pc = 0x16CFC4u;
    // 0x16cfc4: 0xc05c158  jal         func_170560
    ctx->pc = 0x16CFC4u;
    SET_GPR_U32(ctx, 31, 0x16CFCCu);
    ctx->pc = 0x16CFC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFC4u;
            // 0x16cfc8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170560u;
    if (runtime->hasFunction(0x170560u)) {
        auto targetFn = runtime->lookupFunction(0x170560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CFCCu; }
        if (ctx->pc != 0x16CFCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170560_0x170560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CFCCu; }
        if (ctx->pc != 0x16CFCCu) { return; }
    }
    ctx->pc = 0x16CFCCu;
label_16cfcc:
    // 0x16cfcc: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x16CFCCu;
    {
        const bool branch_taken_0x16cfcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CFD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFCCu;
            // 0x16cfd0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cfcc) {
            ctx->pc = 0x16D188u;
            goto label_16d188;
        }
    }
    ctx->pc = 0x16CFD4u;
    // 0x16cfd4: 0x0  nop
    ctx->pc = 0x16cfd4u;
    // NOP
label_16cfd8:
    // 0x16cfd8: 0xc05b304  jal         func_16CC10
    ctx->pc = 0x16CFD8u;
    SET_GPR_U32(ctx, 31, 0x16CFE0u);
    ctx->pc = 0x16CFDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFD8u;
            // 0x16cfdc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16CC10u;
    if (runtime->hasFunction(0x16CC10u)) {
        auto targetFn = runtime->lookupFunction(0x16CC10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CFE0u; }
        if (ctx->pc != 0x16CFE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016CC10_0x16cc10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CFE0u; }
        if (ctx->pc != 0x16CFE0u) { return; }
    }
    ctx->pc = 0x16CFE0u;
label_16cfe0:
    // 0x16cfe0: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x16CFE0u;
    {
        const bool branch_taken_0x16cfe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CFE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFE0u;
            // 0x16cfe4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cfe0) {
            ctx->pc = 0x16D18Cu;
            goto label_16d18c;
        }
    }
    ctx->pc = 0x16CFE8u;
label_16cfe8:
    // 0x16cfe8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16cfe8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cfec: 0x322300cc  andi        $v1, $s1, 0xCC
    ctx->pc = 0x16cfecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)204);
    // 0x16cff0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16cff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cff4: 0x384200cc  xori        $v0, $v0, 0xCC
    ctx->pc = 0x16cff4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)204);
    // 0x16cff8: 0x27a60010  addiu       $a2, $sp, 0x10
    ctx->pc = 0x16cff8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x16cffc: 0xc059d7a  jal         func_1675E8
    ctx->pc = 0x16CFFCu;
    SET_GPR_U32(ctx, 31, 0x16D004u);
    ctx->pc = 0x16D000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CFFCu;
            // 0x16d000: 0x62880b  movn        $s1, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1675E8u;
    if (runtime->hasFunction(0x1675E8u)) {
        auto targetFn = runtime->lookupFunction(0x1675E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D004u; }
        if (ctx->pc != 0x16D004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001675E8_0x1675e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D004u; }
        if (ctx->pc != 0x16D004u) { return; }
    }
    ctx->pc = 0x16D004u;
label_16d004:
    // 0x16d004: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x16d004u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d008: 0x1640005f  bnez        $s2, . + 4 + (0x5F << 2)
    ctx->pc = 0x16D008u;
    {
        const bool branch_taken_0x16d008 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x16D00Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D008u;
            // 0x16d00c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d008) {
            ctx->pc = 0x16D188u;
            goto label_16d188;
        }
    }
    ctx->pc = 0x16D010u;
    // 0x16d010: 0x322200c8  andi        $v0, $s1, 0xC8
    ctx->pc = 0x16d010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)200);
    // 0x16d014: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16D014u;
    {
        const bool branch_taken_0x16d014 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D014u;
            // 0x16d018: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d014) {
            ctx->pc = 0x16D024u;
            goto label_16d024;
        }
    }
    ctx->pc = 0x16D01Cu;
    // 0x16d01c: 0xc05c160  jal         func_170580
    ctx->pc = 0x16D01Cu;
    SET_GPR_U32(ctx, 31, 0x16D024u);
    ctx->pc = 0x16D020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D01Cu;
            // 0x16d020: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170580u;
    if (runtime->hasFunction(0x170580u)) {
        auto targetFn = runtime->lookupFunction(0x170580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D024u; }
        if (ctx->pc != 0x16D024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170580_0x170580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D024u; }
        if (ctx->pc != 0x16D024u) { return; }
    }
    ctx->pc = 0x16D024u;
label_16d024:
    // 0x16d024: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x16d024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x16d028: 0x56220016  bnel        $s1, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x16D028u;
    {
        const bool branch_taken_0x16d028 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x16d028) {
            ctx->pc = 0x16D02Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16D028u;
            // 0x16d02c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16D084u;
            goto label_16d084;
        }
    }
    ctx->pc = 0x16D030u;
    // 0x16d030: 0xc05b480  jal         func_16D200
    ctx->pc = 0x16D030u;
    SET_GPR_U32(ctx, 31, 0x16D038u);
    ctx->pc = 0x16D034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D030u;
            // 0x16d034: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D200u;
    if (runtime->hasFunction(0x16D200u)) {
        auto targetFn = runtime->lookupFunction(0x16D200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D038u; }
        if (ctx->pc != 0x16D038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D200_0x16d200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D038u; }
        if (ctx->pc != 0x16D038u) { return; }
    }
    ctx->pc = 0x16D038u;
label_16d038:
    // 0x16d038: 0xc059f74  jal         func_167DD0
    ctx->pc = 0x16D038u;
    SET_GPR_U32(ctx, 31, 0x16D040u);
    ctx->pc = 0x16D03Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D038u;
            // 0x16d03c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167DD0u;
    if (runtime->hasFunction(0x167DD0u)) {
        auto targetFn = runtime->lookupFunction(0x167DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D040u; }
        if (ctx->pc != 0x16D040u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167DD0_0x167dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D040u; }
        if (ctx->pc != 0x16D040u) { return; }
    }
    ctx->pc = 0x16D040u;
label_16d040:
    // 0x16d040: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16D040u;
    {
        const bool branch_taken_0x16d040 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D040u;
            // 0x16d044: 0x8fa50010  lw          $a1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d040) {
            ctx->pc = 0x16D060u;
            goto label_16d060;
        }
    }
    ctx->pc = 0x16D048u;
    // 0x16d048: 0xc05b4ac  jal         func_16D2B0
    ctx->pc = 0x16D048u;
    SET_GPR_U32(ctx, 31, 0x16D050u);
    ctx->pc = 0x16D04Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D048u;
            // 0x16d04c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D2B0u;
    if (runtime->hasFunction(0x16D2B0u)) {
        auto targetFn = runtime->lookupFunction(0x16D2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D050u; }
        if (ctx->pc != 0x16D050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D2B0_0x16d2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D050u; }
        if (ctx->pc != 0x16D050u) { return; }
    }
    ctx->pc = 0x16D050u;
label_16d050:
    // 0x16d050: 0x5440004d  bnel        $v0, $zero, . + 4 + (0x4D << 2)
    ctx->pc = 0x16D050u;
    {
        const bool branch_taken_0x16d050 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16d050) {
            ctx->pc = 0x16D054u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16D050u;
            // 0x16d054: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16D188u;
            goto label_16d188;
        }
    }
    ctx->pc = 0x16D058u;
    // 0x16d058: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x16D058u;
    {
        const bool branch_taken_0x16d058 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D05Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D058u;
            // 0x16d05c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d058) {
            ctx->pc = 0x16D180u;
            goto label_16d180;
        }
    }
    ctx->pc = 0x16D060u;
label_16d060:
    // 0x16d060: 0xc059f8e  jal         func_167E38
    ctx->pc = 0x16D060u;
    SET_GPR_U32(ctx, 31, 0x16D068u);
    ctx->pc = 0x16D064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D060u;
            // 0x16d064: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167E38u;
    if (runtime->hasFunction(0x167E38u)) {
        auto targetFn = runtime->lookupFunction(0x167E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D068u; }
        if (ctx->pc != 0x16D068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167E38_0x167e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D068u; }
        if (ctx->pc != 0x16D068u) { return; }
    }
    ctx->pc = 0x16D068u;
label_16d068:
    // 0x16d068: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D068u;
    {
        const bool branch_taken_0x16d068 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D06Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D068u;
            // 0x16d06c: 0x8fa50010  lw          $a1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d068) {
            ctx->pc = 0x16D080u;
            goto label_16d080;
        }
    }
    ctx->pc = 0x16D070u;
    // 0x16d070: 0xc05b542  jal         func_16D508
    ctx->pc = 0x16D070u;
    SET_GPR_U32(ctx, 31, 0x16D078u);
    ctx->pc = 0x16D074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D070u;
            // 0x16d074: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D508u;
    if (runtime->hasFunction(0x16D508u)) {
        auto targetFn = runtime->lookupFunction(0x16D508u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D078u; }
        if (ctx->pc != 0x16D078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D508_0x16d508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D078u; }
        if (ctx->pc != 0x16D078u) { return; }
    }
    ctx->pc = 0x16D078u;
label_16d078:
    // 0x16d078: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x16D078u;
    {
        const bool branch_taken_0x16d078 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D07Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D078u;
            // 0x16d07c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d078) {
            ctx->pc = 0x16D180u;
            goto label_16d180;
        }
    }
    ctx->pc = 0x16D080u;
label_16d080:
    // 0x16d080: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d080u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16d084:
    // 0x16d084: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x16d084u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d088: 0xc05b57a  jal         func_16D5E8
    ctx->pc = 0x16D088u;
    SET_GPR_U32(ctx, 31, 0x16D090u);
    ctx->pc = 0x16D08Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D088u;
            // 0x16d08c: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D5E8u;
    if (runtime->hasFunction(0x16D5E8u)) {
        auto targetFn = runtime->lookupFunction(0x16D5E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D090u; }
        if (ctx->pc != 0x16D090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D5E8_0x16d5e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D090u; }
        if (ctx->pc != 0x16D090u) { return; }
    }
    ctx->pc = 0x16D090u;
label_16d090:
    // 0x16d090: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D090u;
    {
        const bool branch_taken_0x16d090 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16d090) {
            ctx->pc = 0x16D094u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16D090u;
            // 0x16d094: 0x2ac20005  slti        $v0, $s6, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16D0A8u;
            goto label_16d0a8;
        }
    }
    ctx->pc = 0x16D098u;
    // 0x16d098: 0xc05c158  jal         func_170560
    ctx->pc = 0x16D098u;
    SET_GPR_U32(ctx, 31, 0x16D0A0u);
    ctx->pc = 0x16D09Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D098u;
            // 0x16d09c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170560u;
    if (runtime->hasFunction(0x170560u)) {
        auto targetFn = runtime->lookupFunction(0x170560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D0A0u; }
        if (ctx->pc != 0x16D0A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170560_0x170560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D0A0u; }
        if (ctx->pc != 0x16D0A0u) { return; }
    }
    ctx->pc = 0x16D0A0u;
label_16d0a0:
    // 0x16d0a0: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x16D0A0u;
    {
        const bool branch_taken_0x16d0a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D0A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D0A0u;
            // 0x16d0a4: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d0a0) {
            ctx->pc = 0x16D188u;
            goto label_16d188;
        }
    }
    ctx->pc = 0x16D0A8u;
label_16d0a8:
    // 0x16d0a8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D0A8u;
    {
        const bool branch_taken_0x16d0a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D0ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D0A8u;
            // 0x16d0ac: 0x3222004c  andi        $v0, $s1, 0x4C (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)76);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d0a8) {
            ctx->pc = 0x16D0C0u;
            goto label_16d0c0;
        }
    }
    ctx->pc = 0x16D0B0u;
    // 0x16d0b0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16d0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16d0b4: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x16D0B4u;
    {
        const bool branch_taken_0x16d0b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D0B4u;
            // 0x16d0b8: 0xae820020  sw          $v0, 0x20($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d0b4) {
            ctx->pc = 0x16D184u;
            goto label_16d184;
        }
    }
    ctx->pc = 0x16D0BCu;
    // 0x16d0bc: 0x0  nop
    ctx->pc = 0x16d0bcu;
    // NOP
label_16d0c0:
    // 0x16d0c0: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x16D0C0u;
    {
        const bool branch_taken_0x16d0c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D0C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D0C0u;
            // 0x16d0c4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d0c0) {
            ctx->pc = 0x16D110u;
            goto label_16d110;
        }
    }
    ctx->pc = 0x16D0C8u;
    // 0x16d0c8: 0xc05b46c  jal         func_16D1B0
    ctx->pc = 0x16D0C8u;
    SET_GPR_U32(ctx, 31, 0x16D0D0u);
    ctx->pc = 0x16D0CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D0C8u;
            // 0x16d0cc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D1B0u;
    if (runtime->hasFunction(0x16D1B0u)) {
        auto targetFn = runtime->lookupFunction(0x16D1B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D0D0u; }
        if (ctx->pc != 0x16D0D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D1B0_0x16d1b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D0D0u; }
        if (ctx->pc != 0x16D0D0u) { return; }
    }
    ctx->pc = 0x16D0D0u;
label_16d0d0:
    // 0x16d0d0: 0x8e670078  lw          $a3, 0x78($s3)
    ctx->pc = 0x16d0d0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 120)));
    // 0x16d0d4: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x16d0d4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16d0d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d0d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d0dc: 0x2273824  and         $a3, $s1, $a3
    ctx->pc = 0x16d0dcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) & GPR_U64(ctx, 7));
    // 0x16d0e0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16d0e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d0e4: 0xc05b5ba  jal         func_16D6E8
    ctx->pc = 0x16D0E4u;
    SET_GPR_U32(ctx, 31, 0x16D0ECu);
    ctx->pc = 0x16D0E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D0E4u;
            // 0x16d0e8: 0x7382b  sltu        $a3, $zero, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D6E8u;
    if (runtime->hasFunction(0x16D6E8u)) {
        auto targetFn = runtime->lookupFunction(0x16D6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D0ECu; }
        if (ctx->pc != 0x16D0ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D6E8_0x16d6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D0ECu; }
        if (ctx->pc != 0x16D0ECu) { return; }
    }
    ctx->pc = 0x16D0ECu;
label_16d0ec:
    // 0x16d0ec: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x16d0ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d0f0: 0x16400026  bnez        $s2, . + 4 + (0x26 << 2)
    ctx->pc = 0x16D0F0u;
    {
        const bool branch_taken_0x16d0f0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x16D0F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D0F0u;
            // 0x16d0f4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d0f0) {
            ctx->pc = 0x16D18Cu;
            goto label_16d18c;
        }
    }
    ctx->pc = 0x16D0F8u;
    // 0x16d0f8: 0x8e620078  lw          $v0, 0x78($s3)
    ctx->pc = 0x16d0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 120)));
    // 0x16d0fc: 0x2221024  and         $v0, $s1, $v0
    ctx->pc = 0x16d0fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
    // 0x16d100: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x16D100u;
    {
        const bool branch_taken_0x16d100 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D100u;
            // 0x16d104: 0x240200cc  addiu       $v0, $zero, 0xCC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 204));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d100) {
            ctx->pc = 0x16D17Cu;
            goto label_16d17c;
        }
    }
    ctx->pc = 0x16D108u;
    // 0x16d108: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x16D108u;
    {
        const bool branch_taken_0x16d108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D108u;
            // 0x16d10c: 0xae620078  sw          $v0, 0x78($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 120), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d108) {
            ctx->pc = 0x16D17Cu;
            goto label_16d17c;
        }
    }
    ctx->pc = 0x16D110u;
label_16d110:
    // 0x16d110: 0x32220002  andi        $v0, $s1, 0x2
    ctx->pc = 0x16d110u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)2);
    // 0x16d114: 0x50400014  beql        $v0, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x16D114u;
    {
        const bool branch_taken_0x16d114 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16d114) {
            ctx->pc = 0x16D118u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16D114u;
            // 0x16d118: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16D168u;
            goto label_16d168;
        }
    }
    ctx->pc = 0x16D11Cu;
    // 0x16d11c: 0xc05b99a  jal         func_16E668
    ctx->pc = 0x16D11Cu;
    SET_GPR_U32(ctx, 31, 0x16D124u);
    ctx->pc = 0x16D120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D11Cu;
            // 0x16d120: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E668u;
    if (runtime->hasFunction(0x16E668u)) {
        auto targetFn = runtime->lookupFunction(0x16E668u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D124u; }
        if (ctx->pc != 0x16D124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E668_0x16e668(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D124u; }
        if (ctx->pc != 0x16D124u) { return; }
    }
    ctx->pc = 0x16D124u;
label_16d124:
    // 0x16d124: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x16D124u;
    {
        const bool branch_taken_0x16d124 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D124u;
            // 0x16d128: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d124) {
            ctx->pc = 0x16D188u;
            goto label_16d188;
        }
    }
    ctx->pc = 0x16D12Cu;
    // 0x16d12c: 0xc05b99e  jal         func_16E678
    ctx->pc = 0x16D12Cu;
    SET_GPR_U32(ctx, 31, 0x16D134u);
    ctx->pc = 0x16D130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D12Cu;
            // 0x16d130: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E678u;
    if (runtime->hasFunction(0x16E678u)) {
        auto targetFn = runtime->lookupFunction(0x16E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D134u; }
        if (ctx->pc != 0x16D134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E678_0x16e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D134u; }
        if (ctx->pc != 0x16D134u) { return; }
    }
    ctx->pc = 0x16D134u;
label_16d134:
    // 0x16d134: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16D134u;
    {
        const bool branch_taken_0x16d134 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D134u;
            // 0x16d138: 0x8fa50010  lw          $a1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d134) {
            ctx->pc = 0x16D158u;
            goto label_16d158;
        }
    }
    ctx->pc = 0x16D13Cu;
    // 0x16d13c: 0xc05bad2  jal         func_16EB48
    ctx->pc = 0x16D13Cu;
    SET_GPR_U32(ctx, 31, 0x16D144u);
    ctx->pc = 0x16D140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D13Cu;
            // 0x16d140: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16EB48u;
    if (runtime->hasFunction(0x16EB48u)) {
        auto targetFn = runtime->lookupFunction(0x16EB48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D144u; }
        if (ctx->pc != 0x16D144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016EB48_0x16eb48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D144u; }
        if (ctx->pc != 0x16D144u) { return; }
    }
    ctx->pc = 0x16D144u;
label_16d144:
    // 0x16d144: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x16d144u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d148: 0x5640000f  bnel        $s2, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x16D148u;
    {
        const bool branch_taken_0x16d148 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x16d148) {
            ctx->pc = 0x16D14Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16D148u;
            // 0x16d14c: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16D188u;
            goto label_16d188;
        }
    }
    ctx->pc = 0x16D150u;
    // 0x16d150: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x16D150u;
    {
        const bool branch_taken_0x16d150 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D150u;
            // 0x16d154: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d150) {
            ctx->pc = 0x16D180u;
            goto label_16d180;
        }
    }
    ctx->pc = 0x16D158u;
label_16d158:
    // 0x16d158: 0xc05bb24  jal         func_16EC90
    ctx->pc = 0x16D158u;
    SET_GPR_U32(ctx, 31, 0x16D160u);
    ctx->pc = 0x16D15Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D158u;
            // 0x16d15c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16EC90u;
    if (runtime->hasFunction(0x16EC90u)) {
        auto targetFn = runtime->lookupFunction(0x16EC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D160u; }
        if (ctx->pc != 0x16D160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016EC90_0x16ec90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D160u; }
        if (ctx->pc != 0x16D160u) { return; }
    }
    ctx->pc = 0x16D160u;
label_16d160:
    // 0x16d160: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x16D160u;
    {
        const bool branch_taken_0x16d160 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D160u;
            // 0x16d164: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d160) {
            ctx->pc = 0x16D184u;
            goto label_16d184;
        }
    }
    ctx->pc = 0x16D168u;
label_16d168:
    // 0x16d168: 0x12220006  beq         $s1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16D168u;
    {
        const bool branch_taken_0x16d168 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x16D16Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D168u;
            // 0x16d16c: 0x8fa50010  lw          $a1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d168) {
            ctx->pc = 0x16D184u;
            goto label_16d184;
        }
    }
    ctx->pc = 0x16D170u;
    // 0x16d170: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d170u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d174: 0xc05bda8  jal         func_16F6A0
    ctx->pc = 0x16D174u;
    SET_GPR_U32(ctx, 31, 0x16D17Cu);
    ctx->pc = 0x16D178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D174u;
            // 0x16d178: 0x240600cc  addiu       $a2, $zero, 0xCC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 204));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16F6A0u;
    if (runtime->hasFunction(0x16F6A0u)) {
        auto targetFn = runtime->lookupFunction(0x16F6A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D17Cu; }
        if (ctx->pc != 0x16D17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016F6A0_0x16f6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D17Cu; }
        if (ctx->pc != 0x16D17Cu) { return; }
    }
    ctx->pc = 0x16D17Cu;
label_16d17c:
    // 0x16d17c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16d17cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_16d180:
    // 0x16d180: 0xaea20000  sw          $v0, 0x0($s5)
    ctx->pc = 0x16d180u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
label_16d184:
    // 0x16d184: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x16d184u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_16d188:
    // 0x16d188: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16d188u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_16d18c:
    // 0x16d18c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x16d18cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16d190: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x16d190u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16d194: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x16d194u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16d198: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x16d198u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16d19c: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x16d19cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16d1a0: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x16d1a0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x16d1a4: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x16d1a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x16d1a8: 0x3e00008  jr          $ra
    ctx->pc = 0x16D1A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D1ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D1A8u;
            // 0x16d1ac: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16CFA8u: goto label_16cfa8;
            case 0x16CFB8u: goto label_16cfb8;
            case 0x16CFCCu: goto label_16cfcc;
            case 0x16CFD8u: goto label_16cfd8;
            case 0x16CFE0u: goto label_16cfe0;
            case 0x16CFE8u: goto label_16cfe8;
            case 0x16D004u: goto label_16d004;
            case 0x16D024u: goto label_16d024;
            case 0x16D038u: goto label_16d038;
            case 0x16D040u: goto label_16d040;
            case 0x16D050u: goto label_16d050;
            case 0x16D060u: goto label_16d060;
            case 0x16D068u: goto label_16d068;
            case 0x16D078u: goto label_16d078;
            case 0x16D080u: goto label_16d080;
            case 0x16D084u: goto label_16d084;
            case 0x16D090u: goto label_16d090;
            case 0x16D0A0u: goto label_16d0a0;
            case 0x16D0A8u: goto label_16d0a8;
            case 0x16D0C0u: goto label_16d0c0;
            case 0x16D0D0u: goto label_16d0d0;
            case 0x16D0ECu: goto label_16d0ec;
            case 0x16D110u: goto label_16d110;
            case 0x16D124u: goto label_16d124;
            case 0x16D134u: goto label_16d134;
            case 0x16D144u: goto label_16d144;
            case 0x16D158u: goto label_16d158;
            case 0x16D160u: goto label_16d160;
            case 0x16D168u: goto label_16d168;
            case 0x16D17Cu: goto label_16d17c;
            case 0x16D180u: goto label_16d180;
            case 0x16D184u: goto label_16d184;
            case 0x16D188u: goto label_16d188;
            case 0x16D18Cu: goto label_16d18c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D1B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
