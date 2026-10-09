#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019EC90
// Address: 0x19ec90 - 0x19ed90
void sub_0019EC90_0x19ec90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019EC90_0x19ec90");
#endif

    switch (ctx->pc) {
        case 0x19ecc0u: goto label_19ecc0;
        case 0x19ecdcu: goto label_19ecdc;
        case 0x19ecf8u: goto label_19ecf8;
        case 0x19ed14u: goto label_19ed14;
        default: break;
    }

    ctx->pc = 0x19ec90u;

    // 0x19ec90: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x19ec90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x19ec94: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19ec94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19ec98: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19ec98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19ec9c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19ec9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19eca0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19eca0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19eca4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19eca4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19eca8: 0x1640000f  bnez        $s2, . + 4 + (0xF << 2)
    ctx->pc = 0x19ECA8u;
    {
        const bool branch_taken_0x19eca8 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x19ECACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19ECA8u;
            // 0x19ecac: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eca8) {
            ctx->pc = 0x19ECE8u;
            goto label_19ece8;
        }
    }
    ctx->pc = 0x19ECB0u;
    // 0x19ecb0: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x19ecb0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x19ecb4: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x19ecb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x19ecb8: 0xc067ac4  jal         func_19EB10
    ctx->pc = 0x19ECB8u;
    SET_GPR_U32(ctx, 31, 0x19ECC0u);
    ctx->pc = 0x19ECBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19ECB8u;
            // 0x19ecbc: 0x2484bee0  addiu       $a0, $a0, -0x4120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EB10u;
    if (runtime->hasFunction(0x19EB10u)) {
        auto targetFn = runtime->lookupFunction(0x19EB10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ECC0u; }
        if (ctx->pc != 0x19ECC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EB10_0x19eb10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ECC0u; }
        if (ctx->pc != 0x19ECC0u) { return; }
    }
    ctx->pc = 0x19ECC0u;
label_19ecc0:
    // 0x19ecc0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19ECC0u;
    {
        const bool branch_taken_0x19ecc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19ECC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19ECC0u;
            // 0x19ecc4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ecc0) {
            ctx->pc = 0x19ECD0u;
            goto label_19ecd0;
        }
    }
    ctx->pc = 0x19ECC8u;
    // 0x19ecc8: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x19ECC8u;
    {
        const bool branch_taken_0x19ecc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19ECCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19ECC8u;
            // 0x19eccc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ecc8) {
            ctx->pc = 0x19ED70u;
            goto label_19ed70;
        }
    }
    ctx->pc = 0x19ECD0u;
label_19ecd0:
    // 0x19ecd0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x19ecd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ecd4: 0xc067b00  jal         func_19EC00
    ctx->pc = 0x19ECD4u;
    SET_GPR_U32(ctx, 31, 0x19ECDCu);
    ctx->pc = 0x19ECD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19ECD4u;
            // 0x19ecd8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EC00u;
    if (runtime->hasFunction(0x19EC00u)) {
        auto targetFn = runtime->lookupFunction(0x19EC00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ECDCu; }
        if (ctx->pc != 0x19ECDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EC00_0x19ec00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ECDCu; }
        if (ctx->pc != 0x19ECDCu) { return; }
    }
    ctx->pc = 0x19ECDCu;
label_19ecdc:
    // 0x19ecdc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ecdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ece0: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x19ECE0u;
    {
        const bool branch_taken_0x19ece0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19ECE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19ECE0u;
            // 0x19ece4: 0x8424f9f8  lh          $a0, -0x608($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294965752)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ece0) {
            ctx->pc = 0x19ED3Cu;
            goto label_19ed3c;
        }
    }
    ctx->pc = 0x19ECE8u;
label_19ece8:
    // 0x19ece8: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x19ece8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x19ecec: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x19ececu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x19ecf0: 0xc067ac4  jal         func_19EB10
    ctx->pc = 0x19ECF0u;
    SET_GPR_U32(ctx, 31, 0x19ECF8u);
    ctx->pc = 0x19ECF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19ECF0u;
            // 0x19ecf4: 0x2484bee0  addiu       $a0, $a0, -0x4120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EB10u;
    if (runtime->hasFunction(0x19EB10u)) {
        auto targetFn = runtime->lookupFunction(0x19EB10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ECF8u; }
        if (ctx->pc != 0x19ECF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EB10_0x19eb10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ECF8u; }
        if (ctx->pc != 0x19ECF8u) { return; }
    }
    ctx->pc = 0x19ECF8u;
label_19ecf8:
    // 0x19ecf8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19ECF8u;
    {
        const bool branch_taken_0x19ecf8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19ECFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19ECF8u;
            // 0x19ecfc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ecf8) {
            ctx->pc = 0x19ED08u;
            goto label_19ed08;
        }
    }
    ctx->pc = 0x19ED00u;
    // 0x19ed00: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x19ED00u;
    {
        const bool branch_taken_0x19ed00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19ED04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19ED00u;
            // 0x19ed04: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ed00) {
            ctx->pc = 0x19ED70u;
            goto label_19ed70;
        }
    }
    ctx->pc = 0x19ED08u;
label_19ed08:
    // 0x19ed08: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x19ed08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ed0c: 0xc067b00  jal         func_19EC00
    ctx->pc = 0x19ED0Cu;
    SET_GPR_U32(ctx, 31, 0x19ED14u);
    ctx->pc = 0x19ED10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19ED0Cu;
            // 0x19ed10: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EC00u;
    if (runtime->hasFunction(0x19EC00u)) {
        auto targetFn = runtime->lookupFunction(0x19EC00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ED14u; }
        if (ctx->pc != 0x19ED14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EC00_0x19ec00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ED14u; }
        if (ctx->pc != 0x19ED14u) { return; }
    }
    ctx->pc = 0x19ED14u;
label_19ed14:
    // 0x19ed14: 0x86220012  lh          $v0, 0x12($s1)
    ctx->pc = 0x19ed14u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 18)));
    // 0x19ed18: 0x86440014  lh          $a0, 0x14($s2)
    ctx->pc = 0x19ed18u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x19ed1c: 0x86430016  lh          $v1, 0x16($s2)
    ctx->pc = 0x19ed1cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 22)));
    // 0x19ed20: 0x2445ffff  addiu       $a1, $v0, -0x1
    ctx->pc = 0x19ed20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x19ed24: 0xa01027  not         $v0, $a1
    ctx->pc = 0x19ed24u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 5) | GPR_U64(ctx, 0)));
    // 0x19ed28: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x19ed28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x19ed2c: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x19ed2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x19ed30: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x19ed30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x19ed34: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x19ed34u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x19ed38: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x19ed38u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
label_19ed3c:
    // 0x19ed3c: 0xa6240014  sh          $a0, 0x14($s1)
    ctx->pc = 0x19ed3cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 20), (uint16_t)GPR_U32(ctx, 4));
    // 0x19ed40: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19ed40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19ed44: 0xa2220035  sb          $v0, 0x35($s1)
    ctx->pc = 0x19ed44u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 53), (uint8_t)GPR_U32(ctx, 2));
    // 0x19ed48: 0xae110008  sw          $s1, 0x8($s0)
    ctx->pc = 0x19ed48u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 17));
    // 0x19ed4c: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x19ed4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x19ed50: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x19ed50u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x19ed54: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x19ed54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x19ed58: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x19ed58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x19ed5c: 0xa6040014  sh          $a0, 0x14($s0)
    ctx->pc = 0x19ed5cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 20), (uint16_t)GPR_U32(ctx, 4));
    // 0x19ed60: 0x86230010  lh          $v1, 0x10($s1)
    ctx->pc = 0x19ed60u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x19ed64: 0xa6030016  sh          $v1, 0x16($s0)
    ctx->pc = 0x19ed64u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 22), (uint16_t)GPR_U32(ctx, 3));
    // 0x19ed68: 0x86230012  lh          $v1, 0x12($s1)
    ctx->pc = 0x19ed68u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 18)));
    // 0x19ed6c: 0xa6030018  sh          $v1, 0x18($s0)
    ctx->pc = 0x19ed6cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 24), (uint16_t)GPR_U32(ctx, 3));
label_19ed70:
    // 0x19ed70: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19ed70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19ed74: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19ed74u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19ed78: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19ed78u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19ed7c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19ed7cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19ed80: 0x3e00008  jr          $ra
    ctx->pc = 0x19ED80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19ED84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19ED80u;
            // 0x19ed84: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19ECC0u: goto label_19ecc0;
            case 0x19ECD0u: goto label_19ecd0;
            case 0x19ECDCu: goto label_19ecdc;
            case 0x19ECE8u: goto label_19ece8;
            case 0x19ECF8u: goto label_19ecf8;
            case 0x19ED08u: goto label_19ed08;
            case 0x19ED14u: goto label_19ed14;
            case 0x19ED3Cu: goto label_19ed3c;
            case 0x19ED70u: goto label_19ed70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19ED88u;
    // 0x19ed88: 0x0  nop
    ctx->pc = 0x19ed88u;
    // NOP
    // 0x19ed8c: 0x0  nop
    ctx->pc = 0x19ed8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
