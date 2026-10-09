#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016EC90
// Address: 0x16ec90 - 0x16ef18
void sub_0016EC90_0x16ec90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016EC90_0x16ec90");
#endif

    switch (ctx->pc) {
        case 0x16ecf0u: goto label_16ecf0;
        case 0x16ed08u: goto label_16ed08;
        case 0x16ed10u: goto label_16ed10;
        case 0x16ed18u: goto label_16ed18;
        case 0x16ed2cu: goto label_16ed2c;
        case 0x16ed44u: goto label_16ed44;
        case 0x16ed58u: goto label_16ed58;
        case 0x16ed60u: goto label_16ed60;
        case 0x16ed78u: goto label_16ed78;
        case 0x16edb0u: goto label_16edb0;
        case 0x16edc0u: goto label_16edc0;
        case 0x16edd0u: goto label_16edd0;
        case 0x16edecu: goto label_16edec;
        case 0x16edf8u: goto label_16edf8;
        case 0x16ee08u: goto label_16ee08;
        case 0x16ee8cu: goto label_16ee8c;
        case 0x16eea0u: goto label_16eea0;
        case 0x16eeb4u: goto label_16eeb4;
        case 0x16eec4u: goto label_16eec4;
        case 0x16eee0u: goto label_16eee0;
        default: break;
    }

    ctx->pc = 0x16ec90u;

    // 0x16ec90: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x16ec90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x16ec94: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x16ec94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x16ec98: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x16ec98u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ec9c: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x16ec9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x16eca0: 0x2676098c  addiu       $s6, $s3, 0x98C
    ctx->pc = 0x16eca0u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 19), 2444));
    // 0x16eca4: 0xffb70078  sd          $s7, 0x78($sp)
    ctx->pc = 0x16eca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 23));
    // 0x16eca8: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x16eca8u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ecac: 0xffbe0080  sd          $fp, 0x80($sp)
    ctx->pc = 0x16ecacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 30));
    // 0x16ecb0: 0x2662094c  addiu       $v0, $s3, 0x94C
    ctx->pc = 0x16ecb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2380));
    // 0x16ecb4: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x16ecb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x16ecb8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x16ecb8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ecbc: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x16ecbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x16ecc0: 0x27a70030  addiu       $a3, $sp, 0x30
    ctx->pc = 0x16ecc0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x16ecc4: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x16ecc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x16ecc8: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x16ecc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x16eccc: 0xffb50068  sd          $s5, 0x68($sp)
    ctx->pc = 0x16ecccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 21));
    // 0x16ecd0: 0xffbf0088  sd          $ra, 0x88($sp)
    ctx->pc = 0x16ecd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 31));
    // 0x16ecd4: 0x8e741b30  lw          $s4, 0x1B30($s3)
    ctx->pc = 0x16ecd4u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 6960)));
    // 0x16ecd8: 0xafa20034  sw          $v0, 0x34($sp)
    ctx->pc = 0x16ecd8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
    // 0x16ecdc: 0x269e008c  addiu       $fp, $s4, 0x8C
    ctx->pc = 0x16ecdcu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 20), 140));
    // 0x16ece0: 0x8e820000  lw          $v0, 0x0($s4)
    ctx->pc = 0x16ece0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x16ece4: 0x3c0282d  daddu       $a1, $fp, $zero
    ctx->pc = 0x16ece4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ece8: 0xc05bbc6  jal         func_16EF18
    ctx->pc = 0x16ECE8u;
    SET_GPR_U32(ctx, 31, 0x16ECF0u);
    ctx->pc = 0x16ECECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ECE8u;
            // 0x16ecec: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16EF18u;
    if (runtime->hasFunction(0x16EF18u)) {
        auto targetFn = runtime->lookupFunction(0x16EF18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ECF0u; }
        if (ctx->pc != 0x16ECF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016EF18_0x16ef18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ECF0u; }
        if (ctx->pc != 0x16ECF0u) { return; }
    }
    ctx->pc = 0x16ECF0u;
label_16ecf0:
    // 0x16ecf0: 0x1440007c  bnez        $v0, . + 4 + (0x7C << 2)
    ctx->pc = 0x16ECF0u;
    {
        const bool branch_taken_0x16ecf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16ECF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16ECF0u;
            // 0x16ecf4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ecf0) {
            ctx->pc = 0x16EEE4u;
            goto label_16eee4;
        }
    }
    ctx->pc = 0x16ECF8u;
    // 0x16ecf8: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x16ecf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ecfc: 0x26850948  addiu       $a1, $s4, 0x948
    ctx->pc = 0x16ecfcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 2376));
    // 0x16ed00: 0xc05bd96  jal         func_16F658
    ctx->pc = 0x16ED00u;
    SET_GPR_U32(ctx, 31, 0x16ED08u);
    ctx->pc = 0x16ED04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ED00u;
            // 0x16ed04: 0x8c440028  lw          $a0, 0x28($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16F658u;
    if (runtime->hasFunction(0x16F658u)) {
        auto targetFn = runtime->lookupFunction(0x16F658u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED08u; }
        if (ctx->pc != 0x16ED08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016F658_0x16f658(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED08u; }
        if (ctx->pc != 0x16ED08u) { return; }
    }
    ctx->pc = 0x16ED08u;
label_16ed08:
    // 0x16ed08: 0xc05bc8c  jal         func_16F230
    ctx->pc = 0x16ED08u;
    SET_GPR_U32(ctx, 31, 0x16ED10u);
    ctx->pc = 0x16ED0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ED08u;
            // 0x16ed0c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16F230u;
    if (runtime->hasFunction(0x16F230u)) {
        auto targetFn = runtime->lookupFunction(0x16F230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED10u; }
        if (ctx->pc != 0x16ED10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016F230_0x16f230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED10u; }
        if (ctx->pc != 0x16ED10u) { return; }
    }
    ctx->pc = 0x16ED10u;
label_16ed10:
    // 0x16ed10: 0xc05fa1c  jal         func_17E870
    ctx->pc = 0x16ED10u;
    SET_GPR_U32(ctx, 31, 0x16ED18u);
    ctx->pc = 0x17E870u;
    if (runtime->hasFunction(0x17E870u)) {
        auto targetFn = runtime->lookupFunction(0x17E870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED18u; }
        if (ctx->pc != 0x16ED18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E870_0x17e870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED18u; }
        if (ctx->pc != 0x16ED18u) { return; }
    }
    ctx->pc = 0x16ED18u;
label_16ed18:
    // 0x16ed18: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x16ed18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed1c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16ed1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed20: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16ed20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ed24: 0xc04fffa  jal         func_13FFE8
    ctx->pc = 0x16ED24u;
    SET_GPR_U32(ctx, 31, 0x16ED2Cu);
    ctx->pc = 0x16ED28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ED24u;
            // 0x16ed28: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFE8u;
    if (runtime->hasFunction(0x13FFE8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED2Cu; }
        if (ctx->pc != 0x16ED2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFE8_0x13ffe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED2Cu; }
        if (ctx->pc != 0x16ED2Cu) { return; }
    }
    ctx->pc = 0x16ED2Cu;
label_16ed2c:
    // 0x16ed2c: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x16ed2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed30: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x16ed30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16ed34: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x16ed34u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed38: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x16ed38u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed3c: 0xc05c744  jal         func_171D10
    ctx->pc = 0x16ED3Cu;
    SET_GPR_U32(ctx, 31, 0x16ED44u);
    ctx->pc = 0x16ED40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ED3Cu;
            // 0x16ed40: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171D10u;
    if (runtime->hasFunction(0x171D10u)) {
        auto targetFn = runtime->lookupFunction(0x171D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED44u; }
        if (ctx->pc != 0x16ED44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171D10_0x171d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED44u; }
        if (ctx->pc != 0x16ED44u) { return; }
    }
    ctx->pc = 0x16ED44u;
label_16ed44:
    // 0x16ed44: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x16ed44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed48: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16ed48u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ed4c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16ed4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed50: 0xc04fffa  jal         func_13FFE8
    ctx->pc = 0x16ED50u;
    SET_GPR_U32(ctx, 31, 0x16ED58u);
    ctx->pc = 0x16ED54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ED50u;
            // 0x16ed54: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFE8u;
    if (runtime->hasFunction(0x13FFE8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED58u; }
        if (ctx->pc != 0x16ED58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFE8_0x13ffe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED58u; }
        if (ctx->pc != 0x16ED58u) { return; }
    }
    ctx->pc = 0x16ED58u;
label_16ed58:
    // 0x16ed58: 0xc05fa1c  jal         func_17E870
    ctx->pc = 0x16ED58u;
    SET_GPR_U32(ctx, 31, 0x16ED60u);
    ctx->pc = 0x16ED5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ED58u;
            // 0x16ed5c: 0x50a823  subu        $s5, $v0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E870u;
    if (runtime->hasFunction(0x17E870u)) {
        auto targetFn = runtime->lookupFunction(0x17E870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED60u; }
        if (ctx->pc != 0x16ED60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E870_0x17e870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED60u; }
        if (ctx->pc != 0x16ED60u) { return; }
    }
    ctx->pc = 0x16ED60u;
label_16ed60:
    // 0x16ed60: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x16ed60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x16ed64: 0x52282f  dsubu       $a1, $v0, $s2
    ctx->pc = 0x16ed64u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) - GPR_U64(ctx, 18));
    // 0x16ed68: 0x42140  sll         $a0, $a0, 5
    ctx->pc = 0x16ed68u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x16ed6c: 0x2642021  addu        $a0, $s3, $a0
    ctx->pc = 0x16ed6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
    // 0x16ed70: 0xc05dd1c  jal         func_177470
    ctx->pc = 0x16ED70u;
    SET_GPR_U32(ctx, 31, 0x16ED78u);
    ctx->pc = 0x16ED74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ED70u;
            // 0x16ed74: 0x24842ac0  addiu       $a0, $a0, 0x2AC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177470u;
    if (runtime->hasFunction(0x177470u)) {
        auto targetFn = runtime->lookupFunction(0x177470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED78u; }
        if (ctx->pc != 0x16ED78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177470_0x177470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ED78u; }
        if (ctx->pc != 0x16ED78u) { return; }
    }
    ctx->pc = 0x16ED78u;
label_16ed78:
    // 0x16ed78: 0x8ec2000c  lw          $v0, 0xC($s6)
    ctx->pc = 0x16ed78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x16ed7c: 0x8fa60028  lw          $a2, 0x28($sp)
    ctx->pc = 0x16ed7cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16ed80: 0x3c07ff00  lui         $a3, 0xFF00
    ctx->pc = 0x16ed80u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)65280 << 16));
    // 0x16ed84: 0x8fa8002c  lw          $t0, 0x2C($sp)
    ctx->pc = 0x16ed84u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x16ed88: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16ed88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed8c: 0x8ec30010  lw          $v1, 0x10($s6)
    ctx->pc = 0x16ed8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 16)));
    // 0x16ed90: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x16ed90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x16ed94: 0xaec2000c  sw          $v0, 0xC($s6)
    ctx->pc = 0x16ed94u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 12), GPR_U32(ctx, 2));
    // 0x16ed98: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x16ed98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ed9c: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x16ed9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x16eda0: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x16eda0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eda4: 0xaec30010  sw          $v1, 0x10($s6)
    ctx->pc = 0x16eda4u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 16), GPR_U32(ctx, 3));
    // 0x16eda8: 0xc05b592  jal         func_16D648
    ctx->pc = 0x16EDA8u;
    SET_GPR_U32(ctx, 31, 0x16EDB0u);
    ctx->pc = 0x16EDACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EDA8u;
            // 0x16edac: 0x34e70f06  ori         $a3, $a3, 0xF06 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)3846);
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D648u;
    if (runtime->hasFunction(0x16D648u)) {
        auto targetFn = runtime->lookupFunction(0x16D648u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDB0u; }
        if (ctx->pc != 0x16EDB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D648_0x16d648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDB0u; }
        if (ctx->pc != 0x16EDB0u) { return; }
    }
    ctx->pc = 0x16EDB0u;
label_16edb0:
    // 0x16edb0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x16edb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16edb4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16edb4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16edb8: 0xc05b572  jal         func_16D5C8
    ctx->pc = 0x16EDB8u;
    SET_GPR_U32(ctx, 31, 0x16EDC0u);
    ctx->pc = 0x16EDBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EDB8u;
            // 0x16edbc: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D5C8u;
    if (runtime->hasFunction(0x16D5C8u)) {
        auto targetFn = runtime->lookupFunction(0x16D5C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDC0u; }
        if (ctx->pc != 0x16EDC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D5C8_0x16d5c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDC0u; }
        if (ctx->pc != 0x16EDC0u) { return; }
    }
    ctx->pc = 0x16EDC0u;
label_16edc0:
    // 0x16edc0: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16EDC0u;
    {
        const bool branch_taken_0x16edc0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x16edc0) {
            ctx->pc = 0x16EDD8u;
            goto label_16edd8;
        }
    }
    ctx->pc = 0x16EDC8u;
    // 0x16edc8: 0xc05c1b4  jal         func_1706D0
    ctx->pc = 0x16EDC8u;
    SET_GPR_U32(ctx, 31, 0x16EDD0u);
    ctx->pc = 0x16EDCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EDC8u;
            // 0x16edcc: 0x8fa40030  lw          $a0, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1706D0u;
    if (runtime->hasFunction(0x1706D0u)) {
        auto targetFn = runtime->lookupFunction(0x1706D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDD0u; }
        if (ctx->pc != 0x16EDD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001706D0_0x1706d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDD0u; }
        if (ctx->pc != 0x16EDD0u) { return; }
    }
    ctx->pc = 0x16EDD0u;
label_16edd0:
    // 0x16edd0: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x16EDD0u;
    {
        const bool branch_taken_0x16edd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EDD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EDD0u;
            // 0x16edd4: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16edd0) {
            ctx->pc = 0x16EEE4u;
            goto label_16eee4;
        }
    }
    ctx->pc = 0x16EDD8u;
label_16edd8:
    // 0x16edd8: 0x5aa0003d  blezl       $s5, . + 4 + (0x3D << 2)
    ctx->pc = 0x16EDD8u;
    {
        const bool branch_taken_0x16edd8 = (GPR_S64(ctx, 21) <= 0);
        if (branch_taken_0x16edd8) {
            ctx->pc = 0x16EDDCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16EDD8u;
            // 0x16eddc: 0x8e820134  lw          $v0, 0x134($s4) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 308)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16EED0u;
            goto label_16eed0;
        }
    }
    ctx->pc = 0x16EDE0u;
    // 0x16ede0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16ede0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ede4: 0xc05c160  jal         func_170580
    ctx->pc = 0x16EDE4u;
    SET_GPR_U32(ctx, 31, 0x16EDECu);
    ctx->pc = 0x16EDE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EDE4u;
            // 0x16ede8: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170580u;
    if (runtime->hasFunction(0x170580u)) {
        auto targetFn = runtime->lookupFunction(0x170580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDECu; }
        if (ctx->pc != 0x16EDECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170580_0x170580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDECu; }
        if (ctx->pc != 0x16EDECu) { return; }
    }
    ctx->pc = 0x16EDECu;
label_16edec:
    // 0x16edec: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x16edecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16edf0: 0xc05bcce  jal         func_16F338
    ctx->pc = 0x16EDF0u;
    SET_GPR_U32(ctx, 31, 0x16EDF8u);
    ctx->pc = 0x16EDF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EDF0u;
            // 0x16edf4: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16F338u;
    if (runtime->hasFunction(0x16F338u)) {
        auto targetFn = runtime->lookupFunction(0x16F338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDF8u; }
        if (ctx->pc != 0x16EDF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016F338_0x16f338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EDF8u; }
        if (ctx->pc != 0x16EDF8u) { return; }
    }
    ctx->pc = 0x16EDF8u;
label_16edf8:
    // 0x16edf8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x16edf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16edfc: 0x8fa50030  lw          $a1, 0x30($sp)
    ctx->pc = 0x16edfcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ee00: 0xc05bd0e  jal         func_16F438
    ctx->pc = 0x16EE00u;
    SET_GPR_U32(ctx, 31, 0x16EE08u);
    ctx->pc = 0x16EE04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EE00u;
            // 0x16ee04: 0x2e0302d  daddu       $a2, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16F438u;
    if (runtime->hasFunction(0x16F438u)) {
        auto targetFn = runtime->lookupFunction(0x16F438u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EE08u; }
        if (ctx->pc != 0x16EE08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016F438_0x16f438(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EE08u; }
        if (ctx->pc != 0x16EE08u) { return; }
    }
    ctx->pc = 0x16EE08u;
label_16ee08:
    // 0x16ee08: 0x8e840088  lw          $a0, 0x88($s4)
    ctx->pc = 0x16ee08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 136)));
    // 0x16ee0c: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x16ee0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ee10: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x16ee10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16ee14: 0x8fc50038  lw          $a1, 0x38($fp)
    ctx->pc = 0x16ee14u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x16ee18: 0xac44001c  sw          $a0, 0x1C($v0)
    ctx->pc = 0x16ee18u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x16ee1c: 0x8fa20028  lw          $v0, 0x28($sp)
    ctx->pc = 0x16ee1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16ee20: 0x8fa30030  lw          $v1, 0x30($sp)
    ctx->pc = 0x16ee20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ee24: 0xac620014  sw          $v0, 0x14($v1)
    ctx->pc = 0x16ee24u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 2));
    // 0x16ee28: 0x8fa40030  lw          $a0, 0x30($sp)
    ctx->pc = 0x16ee28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ee2c: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x16ee2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x16ee30: 0x10a60007  beq         $a1, $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x16EE30u;
    {
        const bool branch_taken_0x16ee30 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x16EE34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EE30u;
            // 0x16ee34: 0xac820018  sw          $v0, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ee30) {
            ctx->pc = 0x16EE50u;
            goto label_16ee50;
        }
    }
    ctx->pc = 0x16EE38u;
    // 0x16ee38: 0x8e820134  lw          $v0, 0x134($s4)
    ctx->pc = 0x16ee38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 308)));
    // 0x16ee3c: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x16EE3Cu;
    {
        const bool branch_taken_0x16ee3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16ee3c) {
            ctx->pc = 0x16EE40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16EE3Cu;
            // 0x16ee40: 0xae800134  sw          $zero, 0x134($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 308), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16EE54u;
            goto label_16ee54;
        }
    }
    ctx->pc = 0x16EE44u;
    // 0x16ee44: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x16ee44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ee48: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x16EE48u;
    {
        const bool branch_taken_0x16ee48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EE4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EE48u;
            // 0x16ee4c: 0xae820134  sw          $v0, 0x134($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 308), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ee48) {
            ctx->pc = 0x16EE54u;
            goto label_16ee54;
        }
    }
    ctx->pc = 0x16EE50u;
label_16ee50:
    // 0x16ee50: 0xae800134  sw          $zero, 0x134($s4)
    ctx->pc = 0x16ee50u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 308), GPR_U32(ctx, 0));
label_16ee54:
    // 0x16ee54: 0x8e820134  lw          $v0, 0x134($s4)
    ctx->pc = 0x16ee54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 308)));
    // 0x16ee58: 0x14400022  bnez        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x16EE58u;
    {
        const bool branch_taken_0x16ee58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16EE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EE58u;
            // 0x16ee5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ee58) {
            ctx->pc = 0x16EEE4u;
            goto label_16eee4;
        }
    }
    ctx->pc = 0x16EE60u;
    // 0x16ee60: 0x8e630038  lw          $v1, 0x38($s3)
    ctx->pc = 0x16ee60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
    // 0x16ee64: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x16ee64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16ee68: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x16EE68u;
    {
        const bool branch_taken_0x16ee68 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x16ee68) {
            ctx->pc = 0x16EE98u;
            goto label_16ee98;
        }
    }
    ctx->pc = 0x16EE70u;
    // 0x16ee70: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x16ee70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x16ee74: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x16ee74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x16ee78: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x16ee78u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x16ee7c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16EE7Cu;
    {
        const bool branch_taken_0x16ee7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16ee7c) {
            ctx->pc = 0x16EE98u;
            goto label_16ee98;
        }
    }
    ctx->pc = 0x16EE84u;
    // 0x16ee84: 0xc05c1be  jal         func_1706F8
    ctx->pc = 0x16EE84u;
    SET_GPR_U32(ctx, 31, 0x16EE8Cu);
    ctx->pc = 0x16EE88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EE84u;
            // 0x16ee88: 0x8fa40030  lw          $a0, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1706F8u;
    if (runtime->hasFunction(0x1706F8u)) {
        auto targetFn = runtime->lookupFunction(0x1706F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EE8Cu; }
        if (ctx->pc != 0x16EE8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001706F8_0x1706f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EE8Cu; }
        if (ctx->pc != 0x16EE8Cu) { return; }
    }
    ctx->pc = 0x16EE8Cu;
label_16ee8c:
    // 0x16ee8c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16EE8Cu;
    {
        const bool branch_taken_0x16ee8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EE90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EE8Cu;
            // 0x16ee90: 0x8fa20034  lw          $v0, 0x34($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ee8c) {
            ctx->pc = 0x16EEA4u;
            goto label_16eea4;
        }
    }
    ctx->pc = 0x16EE94u;
    // 0x16ee94: 0x0  nop
    ctx->pc = 0x16ee94u;
    // NOP
label_16ee98:
    // 0x16ee98: 0xc05c1b8  jal         func_1706E0
    ctx->pc = 0x16EE98u;
    SET_GPR_U32(ctx, 31, 0x16EEA0u);
    ctx->pc = 0x16EE9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EE98u;
            // 0x16ee9c: 0x8fa40030  lw          $a0, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1706E0u;
    if (runtime->hasFunction(0x1706E0u)) {
        auto targetFn = runtime->lookupFunction(0x1706E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EEA0u; }
        if (ctx->pc != 0x16EEA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001706E0_0x1706e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EEA0u; }
        if (ctx->pc != 0x16EEA0u) { return; }
    }
    ctx->pc = 0x16EEA0u;
label_16eea0:
    // 0x16eea0: 0x8fa20034  lw          $v0, 0x34($sp)
    ctx->pc = 0x16eea0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_16eea4:
    // 0x16eea4: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x16eea4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16eea8: 0x2446000c  addiu       $a2, $v0, 0xC
    ctx->pc = 0x16eea8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x16eeac: 0xc056d84  jal         func_15B610
    ctx->pc = 0x16EEACu;
    SET_GPR_U32(ctx, 31, 0x16EEB4u);
    ctx->pc = 0x16EEB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EEACu;
            // 0x16eeb0: 0x24450008  addiu       $a1, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B610u;
    if (runtime->hasFunction(0x15B610u)) {
        auto targetFn = runtime->lookupFunction(0x15B610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EEB4u; }
        if (ctx->pc != 0x16EEB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B610_0x15b610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EEB4u; }
        if (ctx->pc != 0x16EEB4u) { return; }
    }
    ctx->pc = 0x16EEB4u;
label_16eeb4:
    // 0x16eeb4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x16eeb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eeb8: 0x8fc60018  lw          $a2, 0x18($fp)
    ctx->pc = 0x16eeb8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x16eebc: 0xc05ce30  jal         func_1738C0
    ctx->pc = 0x16EEBCu;
    SET_GPR_U32(ctx, 31, 0x16EEC4u);
    ctx->pc = 0x16EEC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EEBCu;
            // 0x16eec0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1738C0u;
    if (runtime->hasFunction(0x1738C0u)) {
        auto targetFn = runtime->lookupFunction(0x1738C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EEC4u; }
        if (ctx->pc != 0x16EEC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001738C0_0x1738c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EEC4u; }
        if (ctx->pc != 0x16EEC4u) { return; }
    }
    ctx->pc = 0x16EEC4u;
label_16eec4:
    // 0x16eec4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x16EEC4u;
    {
        const bool branch_taken_0x16eec4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EEC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EEC4u;
            // 0x16eec8: 0xae800084  sw          $zero, 0x84($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 132), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16eec4) {
            ctx->pc = 0x16EEE0u;
            goto label_16eee0;
        }
    }
    ctx->pc = 0x16EECCu;
    // 0x16eecc: 0x0  nop
    ctx->pc = 0x16eeccu;
    // NOP
label_16eed0:
    // 0x16eed0: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x16EED0u;
    {
        const bool branch_taken_0x16eed0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16eed0) {
            ctx->pc = 0x16EED4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16EED0u;
            // 0x16eed4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16EEE4u;
            goto label_16eee4;
        }
    }
    ctx->pc = 0x16EED8u;
    // 0x16eed8: 0xc05c1b4  jal         func_1706D0
    ctx->pc = 0x16EED8u;
    SET_GPR_U32(ctx, 31, 0x16EEE0u);
    ctx->pc = 0x16EEDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EED8u;
            // 0x16eedc: 0x8fa40030  lw          $a0, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1706D0u;
    if (runtime->hasFunction(0x1706D0u)) {
        auto targetFn = runtime->lookupFunction(0x1706D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EEE0u; }
        if (ctx->pc != 0x16EEE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001706D0_0x1706d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EEE0u; }
        if (ctx->pc != 0x16EEE0u) { return; }
    }
    ctx->pc = 0x16EEE0u;
label_16eee0:
    // 0x16eee0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16eee0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16eee4:
    // 0x16eee4: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x16eee4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16eee8: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x16eee8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16eeec: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x16eeecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x16eef0: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x16eef0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x16eef4: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x16eef4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x16eef8: 0xdfb50068  ld          $s5, 0x68($sp)
    ctx->pc = 0x16eef8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x16eefc: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x16eefcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x16ef00: 0xdfb70078  ld          $s7, 0x78($sp)
    ctx->pc = 0x16ef00u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x16ef04: 0xdfbe0080  ld          $fp, 0x80($sp)
    ctx->pc = 0x16ef04u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x16ef08: 0xdfbf0088  ld          $ra, 0x88($sp)
    ctx->pc = 0x16ef08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x16ef0c: 0x3e00008  jr          $ra
    ctx->pc = 0x16EF0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16EF10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EF0Cu;
            // 0x16ef10: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16ECF0u: goto label_16ecf0;
            case 0x16ED08u: goto label_16ed08;
            case 0x16ED10u: goto label_16ed10;
            case 0x16ED18u: goto label_16ed18;
            case 0x16ED2Cu: goto label_16ed2c;
            case 0x16ED44u: goto label_16ed44;
            case 0x16ED58u: goto label_16ed58;
            case 0x16ED60u: goto label_16ed60;
            case 0x16ED78u: goto label_16ed78;
            case 0x16EDB0u: goto label_16edb0;
            case 0x16EDC0u: goto label_16edc0;
            case 0x16EDD0u: goto label_16edd0;
            case 0x16EDD8u: goto label_16edd8;
            case 0x16EDECu: goto label_16edec;
            case 0x16EDF8u: goto label_16edf8;
            case 0x16EE08u: goto label_16ee08;
            case 0x16EE50u: goto label_16ee50;
            case 0x16EE54u: goto label_16ee54;
            case 0x16EE8Cu: goto label_16ee8c;
            case 0x16EE98u: goto label_16ee98;
            case 0x16EEA0u: goto label_16eea0;
            case 0x16EEA4u: goto label_16eea4;
            case 0x16EEB4u: goto label_16eeb4;
            case 0x16EEC4u: goto label_16eec4;
            case 0x16EED0u: goto label_16eed0;
            case 0x16EEE0u: goto label_16eee0;
            case 0x16EEE4u: goto label_16eee4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16EF14u;
    // 0x16ef14: 0x0  nop
    ctx->pc = 0x16ef14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
