#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E5A28
// Address: 0x1e5a28 - 0x1e5bd0
void sub_001E5A28_0x1e5a28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E5A28_0x1e5a28");
#endif

    switch (ctx->pc) {
        case 0x1e5ae4u: goto label_1e5ae4;
        case 0x1e5b1cu: goto label_1e5b1c;
        case 0x1e5b40u: goto label_1e5b40;
        case 0x1e5b68u: goto label_1e5b68;
        case 0x1e5b98u: goto label_1e5b98;
        default: break;
    }

    ctx->pc = 0x1e5a28u;

    // 0x1e5a28: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e5a28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e5a2c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e5a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e5a30: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e5a30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e5a34: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5a34u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5a38: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5a38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5a3c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e5a3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5a40: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5a40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5a44: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e5a44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e5a48: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e5a48u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e5a4c: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e5a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e5a50: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5a50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5a54: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5a54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5a58: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5A58u;
    {
        const bool branch_taken_0x1e5a58 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5a58) {
            ctx->pc = 0x1E5A80u;
            goto label_1e5a80;
        }
    }
    ctx->pc = 0x1E5A60u;
    // 0x1e5a60: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5a60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5a64: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5a64u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5a68: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5a68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5a6c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5a70: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5a70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5a74: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5a78: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5A78u;
    {
        const bool branch_taken_0x1e5a78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5a78) {
            ctx->pc = 0x1E5A94u;
            goto label_1e5a94;
        }
    }
    ctx->pc = 0x1E5A80u;
label_1e5a80:
    // 0x1e5a80: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5a84: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5a84u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5a88: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5a88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5a8c: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1E5A8Cu;
    {
        const bool branch_taken_0x1e5a8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5a8c) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5A94u;
label_1e5a94:
    // 0x1e5a94: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5a94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5a98: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5a98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5a9c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5aa0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5aa4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5aa8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5aac: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e5aacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e5ab0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5ab4: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5ab8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5AB8u;
    {
        const bool branch_taken_0x1e5ab8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5ab8) {
            ctx->pc = 0x1E5AD4u;
            goto label_1e5ad4;
        }
    }
    ctx->pc = 0x1E5AC0u;
    // 0x1e5ac0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5ac4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5ac8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5acc: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1E5ACCu;
    {
        const bool branch_taken_0x1e5acc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5acc) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5AD4u;
label_1e5ad4:
    // 0x1e5ad4: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5ad8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e5ad8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5adc: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E5ADCu;
    SET_GPR_U32(ctx, 31, 0x1E5AE4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5AE4u; }
        if (ctx->pc != 0x1E5AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5AE4u; }
        if (ctx->pc != 0x1E5AE4u) { return; }
    }
    ctx->pc = 0x1E5AE4u;
label_1e5ae4:
    // 0x1e5ae4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e5ae4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e5ae8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5aec: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5AECu;
    {
        const bool branch_taken_0x1e5aec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5aec) {
            ctx->pc = 0x1E5B08u;
            goto label_1e5b08;
        }
    }
    ctx->pc = 0x1E5AF4u;
    // 0x1e5af4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5af8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5af8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5afc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5afcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5b00: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1E5B00u;
    {
        const bool branch_taken_0x1e5b00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5b00) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5B08u;
label_1e5b08:
    // 0x1e5b08: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e5b08u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5b0c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e5b0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5b10: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e5b10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5b14: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E5B14u;
    SET_GPR_U32(ctx, 31, 0x1E5B1Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B1Cu; }
        if (ctx->pc != 0x1E5B1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B1Cu; }
        if (ctx->pc != 0x1E5B1Cu) { return; }
    }
    ctx->pc = 0x1E5B1Cu;
label_1e5b1c:
    // 0x1e5b1c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e5b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5b20: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e5b20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5b24: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E5B24u;
    {
        const bool branch_taken_0x1e5b24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5b24) {
            ctx->pc = 0x1E5B54u;
            goto label_1e5b54;
        }
    }
    ctx->pc = 0x1E5B2Cu;
    // 0x1e5b2c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5b30: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e5b30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e5b34: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e5b34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5b38: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E5B38u;
    SET_GPR_U32(ctx, 31, 0x1E5B40u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B40u; }
        if (ctx->pc != 0x1E5B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B40u; }
        if (ctx->pc != 0x1E5B40u) { return; }
    }
    ctx->pc = 0x1E5B40u;
label_1e5b40:
    // 0x1e5b40: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5b40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5b44: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5b44u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5b48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5b48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5b4c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1E5B4Cu;
    {
        const bool branch_taken_0x1e5b4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5b4c) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5B54u;
label_1e5b54:
    // 0x1e5b54: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e5b54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5b58: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e5b58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5b5c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e5b5cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5b60: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E5B60u;
    SET_GPR_U32(ctx, 31, 0x1E5B68u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B68u; }
        if (ctx->pc != 0x1E5B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B68u; }
        if (ctx->pc != 0x1E5B68u) { return; }
    }
    ctx->pc = 0x1E5B68u;
label_1e5b68:
    // 0x1e5b68: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e5b68u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5b6c: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e5b6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e5b70: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e5b70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5b74: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e5b74u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5b78: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5b78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5b7c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e5b7cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5b80: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1e5b80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5b84: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e5b84u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5b88: 0x24080011  addiu       $t0, $zero, 0x11
    ctx->pc = 0x1e5b88u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1e5b8c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e5b8cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5b90: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5B90u;
    SET_GPR_U32(ctx, 31, 0x1E5B98u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B98u; }
        if (ctx->pc != 0x1E5B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B98u; }
        if (ctx->pc != 0x1E5B98u) { return; }
    }
    ctx->pc = 0x1E5B98u;
label_1e5b98:
    // 0x1e5b98: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5B98u;
    {
        const bool branch_taken_0x1e5b98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5b98) {
            ctx->pc = 0x1E5BB4u;
            goto label_1e5bb4;
        }
    }
    ctx->pc = 0x1E5BA0u;
    // 0x1e5ba0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5ba4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5ba8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5bac: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E5BACu;
    {
        const bool branch_taken_0x1e5bac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5bac) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5BB4u;
label_1e5bb4:
    // 0x1e5bb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5bb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5bb8:
    // 0x1e5bb8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5bb8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5bbc: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e5bbcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e5bc0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e5bc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e5bc4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e5bc4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e5bc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5BC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5BD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
