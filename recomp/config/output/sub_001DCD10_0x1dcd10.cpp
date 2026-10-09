#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DCD10
// Address: 0x1dcd10 - 0x1dcf34
void sub_001DCD10_0x1dcd10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DCD10_0x1dcd10");
#endif

    switch (ctx->pc) {
        case 0x1dcd50u: goto label_1dcd50;
        case 0x1dcdc8u: goto label_1dcdc8;
        case 0x1dcdfcu: goto label_1dcdfc;
        case 0x1dce24u: goto label_1dce24;
        case 0x1dce50u: goto label_1dce50;
        case 0x1dce78u: goto label_1dce78;
        case 0x1dcea0u: goto label_1dcea0;
        case 0x1dcebcu: goto label_1dcebc;
        case 0x1dcedcu: goto label_1dcedc;
        case 0x1dcf0cu: goto label_1dcf0c;
        default: break;
    }

    ctx->pc = 0x1dcd10u;

    // 0x1dcd10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1dcd10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1dcd14: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1dcd14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1dcd18: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1dcd18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1dcd1c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dcd1cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcd20: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dcd20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dcd24: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dcd24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcd28: 0x24420084  addiu       $v0, $v0, 0x84
    ctx->pc = 0x1dcd28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 132));
    // 0x1dcd2c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1dcd2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1dcd30: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1dcd30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcd34: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dcd34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcd38: 0x94420504  lhu         $v0, 0x504($v0)
    ctx->pc = 0x1dcd38u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 1284)));
    // 0x1dcd3c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dcd3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcd40: 0x8c650500  lw          $a1, 0x500($v1)
    ctx->pc = 0x1dcd40u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1280)));
    // 0x1dcd44: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1dcd44u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcd48: 0xc076bab  jal         func_1DAEAC
    ctx->pc = 0x1DCD48u;
    SET_GPR_U32(ctx, 31, 0x1DCD50u);
    ctx->pc = 0x1DAEACu;
    if (runtime->hasFunction(0x1DAEACu)) {
        auto targetFn = runtime->lookupFunction(0x1DAEACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCD50u; }
        if (ctx->pc != 0x1DCD50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAEAC_0x1daeac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCD50u; }
        if (ctx->pc != 0x1DCD50u) { return; }
    }
    ctx->pc = 0x1DCD50u;
label_1dcd50:
    // 0x1dcd50: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1dcd50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcd54: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1dcd54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dcd58: 0x24420128  addiu       $v0, $v0, 0x128
    ctx->pc = 0x1dcd58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 296));
    // 0x1dcd5c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dcd5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dcd60: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1dcd60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcd64: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1dcd64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcd68: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1dcd68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dcd6c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dcd6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dcd70: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dcd70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dcd74: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1dcd74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcd78: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1dcd78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dcd7c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dcd7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dcd80: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dcd80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dcd84: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dcd84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dcd88: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1dcd88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcd8c: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1dcd8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dcd90: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dcd90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dcd94: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dcd94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dcd98: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1dcd98u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1dcd9c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dcd9cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dcda0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1dcda0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcda4: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1dcda4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dcda8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dcda8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dcdac: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dcdacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dcdb0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dcdb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dcdb4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dcdb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dcdb8: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1dcdb8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1dcdbc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dcdbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcdc0: 0xc076c5b  jal         func_1DB16C
    ctx->pc = 0x1DCDC0u;
    SET_GPR_U32(ctx, 31, 0x1DCDC8u);
    ctx->pc = 0x1DB16Cu;
    if (runtime->hasFunction(0x1DB16Cu)) {
        auto targetFn = runtime->lookupFunction(0x1DB16Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCDC8u; }
        if (ctx->pc != 0x1DCDC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB16C_0x1db16c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCDC8u; }
        if (ctx->pc != 0x1DCDC8u) { return; }
    }
    ctx->pc = 0x1DCDC8u;
label_1dcdc8:
    // 0x1dcdc8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dcdc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1dcdcc: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1dcdccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dcdd0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DCDD0u;
    {
        const bool branch_taken_0x1dcdd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dcdd0) {
            ctx->pc = 0x1DCDE0u;
            goto label_1dcde0;
        }
    }
    ctx->pc = 0x1DCDD8u;
    // 0x1dcdd8: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1DCDD8u;
    {
        const bool branch_taken_0x1dcdd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcdd8) {
            ctx->pc = 0x1DCF1Cu;
            goto label_1dcf1c;
        }
    }
    ctx->pc = 0x1DCDE0u;
label_1dcde0:
    // 0x1dcde0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dcde0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcde4: 0x24420084  addiu       $v0, $v0, 0x84
    ctx->pc = 0x1dcde4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 132));
    // 0x1dcde8: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1dcde8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dcdec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1dcdecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcdf0: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1dcdf0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dcdf4: 0xc07cd5f  jal         func_1F357C
    ctx->pc = 0x1DCDF4u;
    SET_GPR_U32(ctx, 31, 0x1DCDFCu);
    ctx->pc = 0x1F357Cu;
    if (runtime->hasFunction(0x1F357Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F357Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCDFCu; }
        if (ctx->pc != 0x1DCDFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F357C_0x1f357c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCDFCu; }
        if (ctx->pc != 0x1DCDFCu) { return; }
    }
    ctx->pc = 0x1DCDFCu;
label_1dcdfc:
    // 0x1dcdfc: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dcdfcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dce00: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dce00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dce04: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DCE04u;
    {
        const bool branch_taken_0x1dce04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dce04) {
            ctx->pc = 0x1DCE14u;
            goto label_1dce14;
        }
    }
    ctx->pc = 0x1DCE0Cu;
    // 0x1dce0c: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1DCE0Cu;
    {
        const bool branch_taken_0x1dce0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dce0c) {
            ctx->pc = 0x1DCF1Cu;
            goto label_1dcf1c;
        }
    }
    ctx->pc = 0x1DCE14u;
label_1dce14:
    // 0x1dce14: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1dce14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dce18: 0x2405000e  addiu       $a1, $zero, 0xE
    ctx->pc = 0x1dce18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1dce1c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1DCE1Cu;
    SET_GPR_U32(ctx, 31, 0x1DCE24u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCE24u; }
        if (ctx->pc != 0x1DCE24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCE24u; }
        if (ctx->pc != 0x1DCE24u) { return; }
    }
    ctx->pc = 0x1DCE24u;
label_1dce24:
    // 0x1dce24: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DCE24u;
    {
        const bool branch_taken_0x1dce24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dce24) {
            ctx->pc = 0x1DCE34u;
            goto label_1dce34;
        }
    }
    ctx->pc = 0x1DCE2Cu;
    // 0x1dce2c: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1DCE2Cu;
    {
        const bool branch_taken_0x1dce2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dce2c) {
            ctx->pc = 0x1DCF1Cu;
            goto label_1dcf1c;
        }
    }
    ctx->pc = 0x1DCE34u;
label_1dce34:
    // 0x1dce34: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1dce34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dce38: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dce38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dce3c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dce3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dce40: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1dce40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1dce44: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dce44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dce48: 0xc07c27c  jal         func_1F09F0
    ctx->pc = 0x1DCE48u;
    SET_GPR_U32(ctx, 31, 0x1DCE50u);
    ctx->pc = 0x1F09F0u;
    if (runtime->hasFunction(0x1F09F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F09F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCE50u; }
        if (ctx->pc != 0x1DCE50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F09F0_0x1f09f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCE50u; }
        if (ctx->pc != 0x1DCE50u) { return; }
    }
    ctx->pc = 0x1DCE50u;
label_1dce50:
    // 0x1dce50: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1dce50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dce54: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dce54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dce58: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dce58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dce5c: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1dce5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1dce60: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1dce60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dce64: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dce64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dce68: 0x24054d52  addiu       $a1, $zero, 0x4D52
    ctx->pc = 0x1dce68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 19794));
    // 0x1dce6c: 0x8c660518  lw          $a2, 0x518($v1)
    ctx->pc = 0x1dce6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1304)));
    // 0x1dce70: 0xc07c28f  jal         func_1F0A3C
    ctx->pc = 0x1DCE70u;
    SET_GPR_U32(ctx, 31, 0x1DCE78u);
    ctx->pc = 0x1F0A3Cu;
    if (runtime->hasFunction(0x1F0A3Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F0A3Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCE78u; }
        if (ctx->pc != 0x1DCE78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0A3C_0x1f0a3c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCE78u; }
        if (ctx->pc != 0x1DCE78u) { return; }
    }
    ctx->pc = 0x1DCE78u;
label_1dce78:
    // 0x1dce78: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1dce78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dce7c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dce7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dce80: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dce80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dce84: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1dce84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1dce88: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1dce88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dce8c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dce8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dce90: 0x24054c43  addiu       $a1, $zero, 0x4C43
    ctx->pc = 0x1dce90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 19523));
    // 0x1dce94: 0x8c660510  lw          $a2, 0x510($v1)
    ctx->pc = 0x1dce94u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1296)));
    // 0x1dce98: 0xc07c28f  jal         func_1F0A3C
    ctx->pc = 0x1DCE98u;
    SET_GPR_U32(ctx, 31, 0x1DCEA0u);
    ctx->pc = 0x1F0A3Cu;
    if (runtime->hasFunction(0x1F0A3Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F0A3Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCEA0u; }
        if (ctx->pc != 0x1DCEA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0A3C_0x1f0a3c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCEA0u; }
        if (ctx->pc != 0x1DCEA0u) { return; }
    }
    ctx->pc = 0x1DCEA0u;
label_1dcea0:
    // 0x1dcea0: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1dcea0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dcea4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dcea4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dcea8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dcea8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dceac: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1dceacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1dceb0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dceb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dceb4: 0xc07c2e8  jal         func_1F0BA0
    ctx->pc = 0x1DCEB4u;
    SET_GPR_U32(ctx, 31, 0x1DCEBCu);
    ctx->pc = 0x1F0BA0u;
    if (runtime->hasFunction(0x1F0BA0u)) {
        auto targetFn = runtime->lookupFunction(0x1F0BA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCEBCu; }
        if (ctx->pc != 0x1DCEBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0BA0_0x1f0ba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCEBCu; }
        if (ctx->pc != 0x1DCEBCu) { return; }
    }
    ctx->pc = 0x1DCEBCu;
label_1dcebc:
    // 0x1dcebc: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1dcebcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1dcec0: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1dcec0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dcec4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dcec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dcec8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dcec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dcecc: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1dceccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1dced0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dced0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dced4: 0xc07c303  jal         func_1F0C0C
    ctx->pc = 0x1DCED4u;
    SET_GPR_U32(ctx, 31, 0x1DCEDCu);
    ctx->pc = 0x1F0C0Cu;
    if (runtime->hasFunction(0x1F0C0Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F0C0Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCEDCu; }
        if (ctx->pc != 0x1DCEDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0C0C_0x1f0c0c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCEDCu; }
        if (ctx->pc != 0x1DCEDCu) { return; }
    }
    ctx->pc = 0x1DCEDCu;
label_1dcedc:
    // 0x1dcedc: 0x97c30008  lhu         $v1, 0x8($fp)
    ctx->pc = 0x1dcedcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dcee0: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1dcee0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dcee4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dcee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dcee8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1dcee8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dceec: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dceecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcef0: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1dcef0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dcef4: 0x24063000  addiu       $a2, $zero, 0x3000
    ctx->pc = 0x1dcef4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12288));
    // 0x1dcef8: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1dcef8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcefc: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1dcefcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dcf00: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1dcf00u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcf04: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1DCF04u;
    SET_GPR_U32(ctx, 31, 0x1DCF0Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCF0Cu; }
        if (ctx->pc != 0x1DCF0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCF0Cu; }
        if (ctx->pc != 0x1DCF0Cu) { return; }
    }
    ctx->pc = 0x1DCF0Cu;
label_1dcf0c:
    // 0x1dcf0c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DCF0Cu;
    {
        const bool branch_taken_0x1dcf0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcf0c) {
            ctx->pc = 0x1DCF1Cu;
            goto label_1dcf1c;
        }
    }
    ctx->pc = 0x1DCF14u;
    // 0x1dcf14: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1DCF14u;
    {
        const bool branch_taken_0x1dcf14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcf14) {
            ctx->pc = 0x1DCF1Cu;
            goto label_1dcf1c;
        }
    }
    ctx->pc = 0x1DCF1Cu;
label_1dcf1c:
    // 0x1dcf1c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dcf1cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcf20: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1dcf20u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1dcf24: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1dcf24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1dcf28: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1dcf28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1dcf2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1DCF2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DCD50u: goto label_1dcd50;
            case 0x1DCDC8u: goto label_1dcdc8;
            case 0x1DCDE0u: goto label_1dcde0;
            case 0x1DCDFCu: goto label_1dcdfc;
            case 0x1DCE14u: goto label_1dce14;
            case 0x1DCE24u: goto label_1dce24;
            case 0x1DCE34u: goto label_1dce34;
            case 0x1DCE50u: goto label_1dce50;
            case 0x1DCE78u: goto label_1dce78;
            case 0x1DCEA0u: goto label_1dcea0;
            case 0x1DCEBCu: goto label_1dcebc;
            case 0x1DCEDCu: goto label_1dcedc;
            case 0x1DCF0Cu: goto label_1dcf0c;
            case 0x1DCF1Cu: goto label_1dcf1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DCF34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
