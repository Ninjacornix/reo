#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E2A24
// Address: 0x1e2a24 - 0x1e2c2c
void sub_001E2A24_0x1e2a24(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E2A24_0x1e2a24");
#endif

    switch (ctx->pc) {
        case 0x1e2adcu: goto label_1e2adc;
        case 0x1e2b10u: goto label_1e2b10;
        case 0x1e2b34u: goto label_1e2b34;
        case 0x1e2b54u: goto label_1e2b54;
        case 0x1e2b90u: goto label_1e2b90;
        case 0x1e2bc0u: goto label_1e2bc0;
        case 0x1e2bf8u: goto label_1e2bf8;
        default: break;
    }

    ctx->pc = 0x1e2a24u;

    // 0x1e2a24: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e2a24u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2a28: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2a28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e2a2c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e2a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e2a30: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2a30u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2a34: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2a34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2a38: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2a38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2a3c: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2a40: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e2a40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e2a44: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e2a44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e2a48: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2a48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2a4c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2a50: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2A50u;
    {
        const bool branch_taken_0x1e2a50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2a50) {
            ctx->pc = 0x1E2A78u;
            goto label_1e2a78;
        }
    }
    ctx->pc = 0x1E2A58u;
    // 0x1e2a58: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2a58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2a5c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2a60: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2a60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2a64: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2a64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2a68: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2a68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2a6c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2a70: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2A70u;
    {
        const bool branch_taken_0x1e2a70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2a70) {
            ctx->pc = 0x1E2A8Cu;
            goto label_1e2a8c;
        }
    }
    ctx->pc = 0x1E2A78u;
label_1e2a78:
    // 0x1e2a78: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2a78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2a7c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2a7cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2a80: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2a84: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E2A84u;
    {
        const bool branch_taken_0x1e2a84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2a84) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2A8Cu;
label_1e2a8c:
    // 0x1e2a8c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2a90: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2a90u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2a94: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2a94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2a98: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2a98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2a9c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2aa0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2aa4: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2aa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e2aa8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2aac: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e2aacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e2ab0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2AB0u;
    {
        const bool branch_taken_0x1e2ab0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2ab0) {
            ctx->pc = 0x1E2ACCu;
            goto label_1e2acc;
        }
    }
    ctx->pc = 0x1E2AB8u;
    // 0x1e2ab8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2ab8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2abc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2abcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2ac0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2ac4: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1E2AC4u;
    {
        const bool branch_taken_0x1e2ac4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2ac4) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2ACCu;
label_1e2acc:
    // 0x1e2acc: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e2accu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2ad0: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x1e2ad0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1e2ad4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E2AD4u;
    SET_GPR_U32(ctx, 31, 0x1E2ADCu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2ADCu; }
        if (ctx->pc != 0x1E2ADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2ADCu; }
        if (ctx->pc != 0x1E2ADCu) { return; }
    }
    ctx->pc = 0x1E2ADCu;
label_1e2adc:
    // 0x1e2adc: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e2adcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e2ae0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2ae4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2AE4u;
    {
        const bool branch_taken_0x1e2ae4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2ae4) {
            ctx->pc = 0x1E2B00u;
            goto label_1e2b00;
        }
    }
    ctx->pc = 0x1E2AECu;
    // 0x1e2aec: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2aecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2af0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2af0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2af4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2af8: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1E2AF8u;
    {
        const bool branch_taken_0x1e2af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2af8) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2B00u;
label_1e2b00:
    // 0x1e2b00: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e2b00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2b04: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x1e2b04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1e2b08: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2B08u;
    SET_GPR_U32(ctx, 31, 0x1E2B10u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B10u; }
        if (ctx->pc != 0x1E2B10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B10u; }
        if (ctx->pc != 0x1E2B10u) { return; }
    }
    ctx->pc = 0x1E2B10u;
label_1e2b10:
    // 0x1e2b10: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e2b14: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b18: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2B18u;
    {
        const bool branch_taken_0x1e2b18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2b18) {
            ctx->pc = 0x1E2B48u;
            goto label_1e2b48;
        }
    }
    ctx->pc = 0x1E2B20u;
    // 0x1e2b20: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2b20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2b24: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e2b24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2b28: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e2b28u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2b2c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2B2Cu;
    SET_GPR_U32(ctx, 31, 0x1E2B34u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B34u; }
        if (ctx->pc != 0x1E2B34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B34u; }
        if (ctx->pc != 0x1E2B34u) { return; }
    }
    ctx->pc = 0x1E2B34u;
label_1e2b34:
    // 0x1e2b34: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2b34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2b38: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2b38u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2b3c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2b40: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1E2B40u;
    {
        const bool branch_taken_0x1e2b40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2b40) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2B48u;
label_1e2b48:
    // 0x1e2b48: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e2b48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2b4c: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E2B4Cu;
    SET_GPR_U32(ctx, 31, 0x1E2B54u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B54u; }
        if (ctx->pc != 0x1E2B54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B54u; }
        if (ctx->pc != 0x1E2B54u) { return; }
    }
    ctx->pc = 0x1E2B54u;
label_1e2b54:
    // 0x1e2b54: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e2b54u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2b58: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b5c: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1e2b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1e2b60: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b64: 0xa0400004  sb          $zero, 0x4($v0)
    ctx->pc = 0x1e2b64u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 4), (uint8_t)GPR_U32(ctx, 0));
    // 0x1e2b68: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e2b68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2b6c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E2B6Cu;
    {
        const bool branch_taken_0x1e2b6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2b6c) {
            ctx->pc = 0x1E2B98u;
            goto label_1e2b98;
        }
    }
    ctx->pc = 0x1E2B74u;
    // 0x1e2b74: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b78: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e2b78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e2b7c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e2b7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2b80: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e2b80u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2b84: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e2b84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e2b88: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E2B88u;
    SET_GPR_U32(ctx, 31, 0x1E2B90u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B90u; }
        if (ctx->pc != 0x1E2B90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B90u; }
        if (ctx->pc != 0x1E2B90u) { return; }
    }
    ctx->pc = 0x1E2B90u;
label_1e2b90:
    // 0x1e2b90: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b94: 0xa0400013  sb          $zero, 0x13($v0)
    ctx->pc = 0x1e2b94u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 19), (uint8_t)GPR_U32(ctx, 0));
label_1e2b98:
    // 0x1e2b98: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2b98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2b9c: 0x90420618  lbu         $v0, 0x618($v0)
    ctx->pc = 0x1e2b9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1560)));
    // 0x1e2ba0: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e2ba0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2ba4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e2ba4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2ba8: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e2ba8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e2bac: 0x24070014  addiu       $a3, $zero, 0x14
    ctx->pc = 0x1e2bacu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1e2bb0: 0x24080006  addiu       $t0, $zero, 0x6
    ctx->pc = 0x1e2bb0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1e2bb4: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e2bb4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2bb8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E2BB8u;
    SET_GPR_U32(ctx, 31, 0x1E2BC0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2BC0u; }
        if (ctx->pc != 0x1E2BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2BC0u; }
        if (ctx->pc != 0x1E2BC0u) { return; }
    }
    ctx->pc = 0x1E2BC0u;
label_1e2bc0:
    // 0x1e2bc0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e2bc4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2bc8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2BC8u;
    {
        const bool branch_taken_0x1e2bc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2bc8) {
            ctx->pc = 0x1E2BE4u;
            goto label_1e2be4;
        }
    }
    ctx->pc = 0x1E2BD0u;
    // 0x1e2bd0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2bd4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2bd4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2bd8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2bdc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E2BDCu;
    {
        const bool branch_taken_0x1e2bdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2bdc) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2BE4u;
label_1e2be4:
    // 0x1e2be4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e2be4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2be8: 0x24050021  addiu       $a1, $zero, 0x21
    ctx->pc = 0x1e2be8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x1e2bec: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e2becu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2bf0: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E2BF0u;
    SET_GPR_U32(ctx, 31, 0x1E2BF8u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2BF8u; }
        if (ctx->pc != 0x1E2BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2BF8u; }
        if (ctx->pc != 0x1E2BF8u) { return; }
    }
    ctx->pc = 0x1E2BF8u;
label_1e2bf8:
    // 0x1e2bf8: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e2bf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2bfc: 0x90640618  lbu         $a0, 0x618($v1)
    ctx->pc = 0x1e2bfcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1560)));
    // 0x1e2c00: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2c04: 0xa0620618  sb          $v0, 0x618($v1)
    ctx->pc = 0x1e2c04u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1560), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2c08: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2c08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2c0c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e2c10: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
label_1e2c14:
    // 0x1e2c14: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2c14u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2c18: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2c18u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e2c1c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e2c1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e2c20: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e2c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e2c24: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2C24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2C2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
