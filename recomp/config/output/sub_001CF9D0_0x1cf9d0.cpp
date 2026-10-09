#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF9D0
// Address: 0x1cf9d0 - 0x1cfaa0
void sub_001CF9D0_0x1cf9d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF9D0_0x1cf9d0");
#endif

    switch (ctx->pc) {
        case 0x1cf9fcu: goto label_1cf9fc;
        case 0x1cfa0cu: goto label_1cfa0c;
        case 0x1cfa34u: goto label_1cfa34;
        case 0x1cfa4cu: goto label_1cfa4c;
        case 0x1cfa6cu: goto label_1cfa6c;
        default: break;
    }

    ctx->pc = 0x1cf9d0u;

    // 0x1cf9d0: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x1cf9d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x1cf9d4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1cf9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1cf9d8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cf9d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cf9dc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cf9dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cf9e0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1cf9e0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf9e4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cf9e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cf9e8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1cf9e8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf9ec: 0x30d100ff  andi        $s1, $a2, 0xFF
    ctx->pc = 0x1cf9ecu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1cf9f0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cf9f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cf9f4: 0xc073e24  jal         func_1CF890
    ctx->pc = 0x1CF9F4u;
    SET_GPR_U32(ctx, 31, 0x1CF9FCu);
    ctx->pc = 0x1CF9F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF9F4u;
            // 0x1cf9f8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF890u;
    if (runtime->hasFunction(0x1CF890u)) {
        auto targetFn = runtime->lookupFunction(0x1CF890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF9FCu; }
        if (ctx->pc != 0x1CF9FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF890_0x1cf890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF9FCu; }
        if (ctx->pc != 0x1CF9FCu) { return; }
    }
    ctx->pc = 0x1CF9FCu;
label_1cf9fc:
    // 0x1cf9fc: 0x14400020  bnez        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1CF9FCu;
    {
        const bool branch_taken_0x1cf9fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf9fc) {
            ctx->pc = 0x1CFA80u;
            goto label_1cfa80;
        }
    }
    ctx->pc = 0x1CFA04u;
    // 0x1cfa04: 0xc073e10  jal         func_1CF840
    ctx->pc = 0x1CFA04u;
    SET_GPR_U32(ctx, 31, 0x1CFA0Cu);
    ctx->pc = 0x1CF840u;
    if (runtime->hasFunction(0x1CF840u)) {
        auto targetFn = runtime->lookupFunction(0x1CF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFA0Cu; }
        if (ctx->pc != 0x1CFA0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF840_0x1cf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFA0Cu; }
        if (ctx->pc != 0x1CFA0Cu) { return; }
    }
    ctx->pc = 0x1CFA0Cu;
label_1cfa0c:
    // 0x1cfa0c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1cfa0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cfa10: 0x1200001b  beqz        $s0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1CFA10u;
    {
        const bool branch_taken_0x1cfa10 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFA10u;
            // 0x1cfa14: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfa10) {
            ctx->pc = 0x1CFA80u;
            goto label_1cfa80;
        }
    }
    ctx->pc = 0x1CFA18u;
    // 0x1cfa18: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1cfa18u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1cfa1c: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1cfa1cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cfa20: 0x3267ffff  andi        $a3, $s3, 0xFFFF
    ctx->pc = 0x1cfa20u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x1cfa24: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1cfa24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1cfa28: 0x24a56180  addiu       $a1, $a1, 0x6180
    ctx->pc = 0x1cfa28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24960));
    // 0x1cfa2c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CFA2Cu;
    SET_GPR_U32(ctx, 31, 0x1CFA34u);
    ctx->pc = 0x1CFA30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFA2Cu;
            // 0x1cfa30: 0x24c661a0  addiu       $a2, $a2, 0x61A0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 24992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFA34u; }
        if (ctx->pc != 0x1CFA34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFA34u; }
        if (ctx->pc != 0x1CFA34u) { return; }
    }
    ctx->pc = 0x1CFA34u;
label_1cfa34:
    // 0x1cfa34: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cfa34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cfa38: 0x27a40053  addiu       $a0, $sp, 0x53
    ctx->pc = 0x1cfa38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 83));
    // 0x1cfa3c: 0x8c250ae0  lw          $a1, 0xAE0($at)
    ctx->pc = 0x1cfa3cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2784)));
    // 0x1cfa40: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1cfa40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cfa44: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1CFA44u;
    SET_GPR_U32(ctx, 31, 0x1CFA4Cu);
    ctx->pc = 0x1CFA48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFA44u;
            // 0x1cfa48: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFA4Cu; }
        if (ctx->pc != 0x1CFA4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFA4Cu; }
        if (ctx->pc != 0x1CFA4Cu) { return; }
    }
    ctx->pc = 0x1CFA4Cu;
label_1cfa4c:
    // 0x1cfa4c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1cfa4cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cfa50: 0x18c0000b  blez        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x1CFA50u;
    {
        const bool branch_taken_0x1cfa50 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x1CFA54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFA50u;
            // 0x1cfa54: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfa50) {
            ctx->pc = 0x1CFA80u;
            goto label_1cfa80;
        }
    }
    ctx->pc = 0x1CFA58u;
    // 0x1cfa58: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x1cfa58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cfa5c: 0x8c240ae0  lw          $a0, 0xAE0($at)
    ctx->pc = 0x1cfa5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2784)));
    // 0x1cfa60: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1cfa60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1cfa64: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1CFA64u;
    SET_GPR_U32(ctx, 31, 0x1CFA6Cu);
    ctx->pc = 0x1CFA68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFA64u;
            // 0x1cfa68: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFA6Cu; }
        if (ctx->pc != 0x1CFA6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CFA6Cu; }
        if (ctx->pc != 0x1CFA6Cu) { return; }
    }
    ctx->pc = 0x1CFA6Cu;
label_1cfa6c:
    // 0x1cfa6c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1cfa6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cfa70: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1cfa70u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cfa74: 0xa6120002  sh          $s2, 0x2($s0)
    ctx->pc = 0x1cfa74u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 18));
    // 0x1cfa78: 0xa6130008  sh          $s3, 0x8($s0)
    ctx->pc = 0x1cfa78u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 19));
    // 0x1cfa7c: 0xa611000c  sh          $s1, 0xC($s0)
    ctx->pc = 0x1cfa7cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 17));
label_1cfa80:
    // 0x1cfa80: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1cfa80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cfa84: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cfa84u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cfa88: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cfa88u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cfa8c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cfa8cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cfa90: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cfa90u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cfa94: 0x3e00008  jr          $ra
    ctx->pc = 0x1CFA94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CFA98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFA94u;
            // 0x1cfa98: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF9FCu: goto label_1cf9fc;
            case 0x1CFA0Cu: goto label_1cfa0c;
            case 0x1CFA34u: goto label_1cfa34;
            case 0x1CFA4Cu: goto label_1cfa4c;
            case 0x1CFA6Cu: goto label_1cfa6c;
            case 0x1CFA80u: goto label_1cfa80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CFA9Cu;
    // 0x1cfa9c: 0x0  nop
    ctx->pc = 0x1cfa9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
