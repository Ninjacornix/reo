#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E2C2C
// Address: 0x1e2c2c - 0x1e2eac
void sub_001E2C2C_0x1e2c2c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E2C2C_0x1e2c2c");
#endif

    switch (ctx->pc) {
        case 0x1e2ce8u: goto label_1e2ce8;
        case 0x1e2d1cu: goto label_1e2d1c;
        case 0x1e2d40u: goto label_1e2d40;
        case 0x1e2e10u: goto label_1e2e10;
        case 0x1e2e48u: goto label_1e2e48;
        case 0x1e2e78u: goto label_1e2e78;
        default: break;
    }

    ctx->pc = 0x1e2c2cu;

    // 0x1e2c2c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e2c2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e2c30: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e2c30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e2c34: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e2c34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e2c38: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2c38u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2c3c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2c3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2c40: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2c40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2c44: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2c44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2c48: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e2c48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e2c4c: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e2c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e2c50: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e2c50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e2c54: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2c54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2c58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2c5c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2C5Cu;
    {
        const bool branch_taken_0x1e2c5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2c5c) {
            ctx->pc = 0x1E2C84u;
            goto label_1e2c84;
        }
    }
    ctx->pc = 0x1E2C64u;
    // 0x1e2c64: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2c64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2c68: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2c68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2c6c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2c70: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2c70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2c74: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2c74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2c78: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2c7c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2C7Cu;
    {
        const bool branch_taken_0x1e2c7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2c7c) {
            ctx->pc = 0x1E2C98u;
            goto label_1e2c98;
        }
    }
    ctx->pc = 0x1E2C84u;
label_1e2c84:
    // 0x1e2c84: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2c84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2c88: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2c88u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2c8c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2c90: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x1E2C90u;
    {
        const bool branch_taken_0x1e2c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2c90) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2C98u;
label_1e2c98:
    // 0x1e2c98: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2c98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2c9c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2ca0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2ca4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2ca8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2cac: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2cacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2cb0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2cb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e2cb4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2cb8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e2cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e2cbc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2CBCu;
    {
        const bool branch_taken_0x1e2cbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2cbc) {
            ctx->pc = 0x1E2CD8u;
            goto label_1e2cd8;
        }
    }
    ctx->pc = 0x1E2CC4u;
    // 0x1e2cc4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2cc8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2ccc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2cd0: 0x10000070  b           . + 4 + (0x70 << 2)
    ctx->pc = 0x1E2CD0u;
    {
        const bool branch_taken_0x1e2cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2cd0) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2CD8u;
label_1e2cd8:
    // 0x1e2cd8: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e2cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2cdc: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e2cdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e2ce0: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E2CE0u;
    SET_GPR_U32(ctx, 31, 0x1E2CE8u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2CE8u; }
        if (ctx->pc != 0x1E2CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2CE8u; }
        if (ctx->pc != 0x1E2CE8u) { return; }
    }
    ctx->pc = 0x1E2CE8u;
label_1e2ce8:
    // 0x1e2ce8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e2ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e2cec: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2cecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2cf0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2CF0u;
    {
        const bool branch_taken_0x1e2cf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2cf0) {
            ctx->pc = 0x1E2D0Cu;
            goto label_1e2d0c;
        }
    }
    ctx->pc = 0x1E2CF8u;
    // 0x1e2cf8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2cfc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2d00: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2d00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2d04: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E2D04u;
    {
        const bool branch_taken_0x1e2d04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2d04) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2D0Cu;
label_1e2d0c:
    // 0x1e2d0c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e2d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2d10: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e2d10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e2d14: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2D14u;
    SET_GPR_U32(ctx, 31, 0x1E2D1Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2D1Cu; }
        if (ctx->pc != 0x1E2D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2D1Cu; }
        if (ctx->pc != 0x1E2D1Cu) { return; }
    }
    ctx->pc = 0x1E2D1Cu;
label_1e2d1c:
    // 0x1e2d1c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e2d20: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2d20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2d24: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2D24u;
    {
        const bool branch_taken_0x1e2d24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2d24) {
            ctx->pc = 0x1E2D54u;
            goto label_1e2d54;
        }
    }
    ctx->pc = 0x1E2D2Cu;
    // 0x1e2d2c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2d30: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e2d30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2d34: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e2d34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2d38: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2D38u;
    SET_GPR_U32(ctx, 31, 0x1E2D40u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2D40u; }
        if (ctx->pc != 0x1E2D40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2D40u; }
        if (ctx->pc != 0x1E2D40u) { return; }
    }
    ctx->pc = 0x1E2D40u;
label_1e2d40:
    // 0x1e2d40: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2d44: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2d44u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2d48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2d48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2d4c: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x1E2D4Cu;
    {
        const bool branch_taken_0x1e2d4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2d4c) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2D54u;
label_1e2d54:
    // 0x1e2d54: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e2d54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2d58: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2d58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2d5c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2d5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2d60: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2d60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2d64: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2d64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2d68: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2d68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2d6c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2d70: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2d70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2d74: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2d74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2d78: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2d78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2d7c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2d7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2d80: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e2d80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e2d84: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2d84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2d88: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2d88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2d8c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2d90: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2d90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2d94: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e2d94u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2d98: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2d98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2d9c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e2d9cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e2da0: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e2da0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2da4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e2da4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2da8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2da8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2dac: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2dacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2db0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e2db0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2db4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2db4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2db8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2db8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2dbc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2dbcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2dc0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e2dc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2dc4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2dc8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2dc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2dcc: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e2dccu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e2dd0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2dd0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2dd4: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e2dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2dd8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2ddc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2ddcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2de0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e2de0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2de4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2de4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2de8: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1e2de8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1e2dec: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e2decu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2df0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2DF0u;
    {
        const bool branch_taken_0x1e2df0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2df0) {
            ctx->pc = 0x1E2E18u;
            goto label_1e2e18;
        }
    }
    ctx->pc = 0x1E2DF8u;
    // 0x1e2df8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2dfc: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e2dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e2e00: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e2e00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2e04: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e2e04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2e08: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E2E08u;
    SET_GPR_U32(ctx, 31, 0x1E2E10u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E10u; }
        if (ctx->pc != 0x1E2E10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E10u; }
        if (ctx->pc != 0x1E2E10u) { return; }
    }
    ctx->pc = 0x1E2E10u;
label_1e2e10:
    // 0x1e2e10: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1E2E10u;
    {
        const bool branch_taken_0x1e2e10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2e10) {
            ctx->pc = 0x1E2E20u;
            goto label_1e2e20;
        }
    }
    ctx->pc = 0x1E2E18u;
label_1e2e18:
    // 0x1e2e18: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2e18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2e1c: 0xa0400008  sb          $zero, 0x8($v0)
    ctx->pc = 0x1e2e1cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 8), (uint8_t)GPR_U32(ctx, 0));
label_1e2e20:
    // 0x1e2e20: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2e20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2e24: 0x90420619  lbu         $v0, 0x619($v0)
    ctx->pc = 0x1e2e24u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1561)));
    // 0x1e2e28: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e2e28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2e2c: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e2e2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2e30: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e2e30u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e2e34: 0x24070018  addiu       $a3, $zero, 0x18
    ctx->pc = 0x1e2e34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e2e38: 0x24080006  addiu       $t0, $zero, 0x6
    ctx->pc = 0x1e2e38u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1e2e3c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e2e3cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2e40: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E2E40u;
    SET_GPR_U32(ctx, 31, 0x1E2E48u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E48u; }
        if (ctx->pc != 0x1E2E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E48u; }
        if (ctx->pc != 0x1E2E48u) { return; }
    }
    ctx->pc = 0x1E2E48u;
label_1e2e48:
    // 0x1e2e48: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2E48u;
    {
        const bool branch_taken_0x1e2e48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2e48) {
            ctx->pc = 0x1E2E64u;
            goto label_1e2e64;
        }
    }
    ctx->pc = 0x1E2E50u;
    // 0x1e2e50: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2e50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2e54: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2e54u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2e58: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2e58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2e5c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E2E5Cu;
    {
        const bool branch_taken_0x1e2e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2e5c) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2E64u;
label_1e2e64:
    // 0x1e2e64: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e2e64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2e68: 0x24050022  addiu       $a1, $zero, 0x22
    ctx->pc = 0x1e2e68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1e2e6c: 0x8fc60010  lw          $a2, 0x10($fp)
    ctx->pc = 0x1e2e6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2e70: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E2E70u;
    SET_GPR_U32(ctx, 31, 0x1E2E78u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E78u; }
        if (ctx->pc != 0x1E2E78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E78u; }
        if (ctx->pc != 0x1E2E78u) { return; }
    }
    ctx->pc = 0x1E2E78u;
label_1e2e78:
    // 0x1e2e78: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e2e78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2e7c: 0x90640619  lbu         $a0, 0x619($v1)
    ctx->pc = 0x1e2e7cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1561)));
    // 0x1e2e80: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2e84: 0xa0620619  sb          $v0, 0x619($v1)
    ctx->pc = 0x1e2e84u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1561), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2e88: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2e88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2e8c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e2e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e2e90: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e2e90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
label_1e2e94:
    // 0x1e2e94: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2e94u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2e98: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e2e98u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e2e9c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e2e9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e2ea0: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e2ea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e2ea4: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2EA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2EACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
