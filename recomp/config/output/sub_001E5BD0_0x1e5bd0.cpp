#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E5BD0
// Address: 0x1e5bd0 - 0x1e5dac
void sub_001E5BD0_0x1e5bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E5BD0_0x1e5bd0");
#endif

    switch (ctx->pc) {
        case 0x1e5c90u: goto label_1e5c90;
        case 0x1e5cc8u: goto label_1e5cc8;
        case 0x1e5cecu: goto label_1e5cec;
        case 0x1e5d14u: goto label_1e5d14;
        case 0x1e5d48u: goto label_1e5d48;
        case 0x1e5d78u: goto label_1e5d78;
        default: break;
    }

    ctx->pc = 0x1e5bd0u;

    // 0x1e5bd0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e5bd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e5bd4: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e5bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e5bd8: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e5bd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e5bdc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5bdcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5be0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5be0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5be4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e5be4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5be8: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5be8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5bec: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e5becu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e5bf0: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e5bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e5bf4: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e5bf4u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e5bf8: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e5bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e5bfc: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5c00: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5c04: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5C04u;
    {
        const bool branch_taken_0x1e5c04 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5c04) {
            ctx->pc = 0x1E5C2Cu;
            goto label_1e5c2c;
        }
    }
    ctx->pc = 0x1E5C0Cu;
    // 0x1e5c0c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5c10: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5c10u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5c14: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5c14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5c18: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5c18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5c1c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5c20: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5c20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5c24: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5C24u;
    {
        const bool branch_taken_0x1e5c24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c24) {
            ctx->pc = 0x1E5C40u;
            goto label_1e5c40;
        }
    }
    ctx->pc = 0x1E5C2Cu;
label_1e5c2c:
    // 0x1e5c2c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5c30: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5c30u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5c34: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5c38: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1E5C38u;
    {
        const bool branch_taken_0x1e5c38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c38) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5C40u;
label_1e5c40:
    // 0x1e5c40: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5c40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5c44: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5c44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5c48: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5c48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5c4c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5c50: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5c50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5c54: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5c54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5c58: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5c58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e5c5c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5c60: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5c60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5c64: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5C64u;
    {
        const bool branch_taken_0x1e5c64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c64) {
            ctx->pc = 0x1E5C80u;
            goto label_1e5c80;
        }
    }
    ctx->pc = 0x1E5C6Cu;
    // 0x1e5c6c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5c70: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5c70u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5c74: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5c74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5c78: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1E5C78u;
    {
        const bool branch_taken_0x1e5c78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c78) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5C80u;
label_1e5c80:
    // 0x1e5c80: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5c80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5c84: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e5c84u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5c88: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E5C88u;
    SET_GPR_U32(ctx, 31, 0x1E5C90u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5C90u; }
        if (ctx->pc != 0x1E5C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5C90u; }
        if (ctx->pc != 0x1E5C90u) { return; }
    }
    ctx->pc = 0x1E5C90u;
label_1e5c90:
    // 0x1e5c90: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e5c90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5c94: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e5c94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5c98: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5C98u;
    {
        const bool branch_taken_0x1e5c98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c98) {
            ctx->pc = 0x1E5CB4u;
            goto label_1e5cb4;
        }
    }
    ctx->pc = 0x1E5CA0u;
    // 0x1e5ca0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5ca4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5ca8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5cac: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1E5CACu;
    {
        const bool branch_taken_0x1e5cac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5cac) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5CB4u;
label_1e5cb4:
    // 0x1e5cb4: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e5cb4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5cb8: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e5cb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5cbc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e5cbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5cc0: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E5CC0u;
    SET_GPR_U32(ctx, 31, 0x1E5CC8u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5CC8u; }
        if (ctx->pc != 0x1E5CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5CC8u; }
        if (ctx->pc != 0x1E5CC8u) { return; }
    }
    ctx->pc = 0x1E5CC8u;
label_1e5cc8:
    // 0x1e5cc8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e5cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e5ccc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5cccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5cd0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E5CD0u;
    {
        const bool branch_taken_0x1e5cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5cd0) {
            ctx->pc = 0x1E5D00u;
            goto label_1e5d00;
        }
    }
    ctx->pc = 0x1E5CD8u;
    // 0x1e5cd8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5cdc: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e5cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e5ce0: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5ce0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5ce4: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E5CE4u;
    SET_GPR_U32(ctx, 31, 0x1E5CECu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5CECu; }
        if (ctx->pc != 0x1E5CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5CECu; }
        if (ctx->pc != 0x1E5CECu) { return; }
    }
    ctx->pc = 0x1E5CECu;
label_1e5cec:
    // 0x1e5cec: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5cecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5cf0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5cf4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5cf8: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1E5CF8u;
    {
        const bool branch_taken_0x1e5cf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5cf8) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5D00u;
label_1e5d00:
    // 0x1e5d00: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5d00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5d04: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e5d04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5d08: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e5d08u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5d0c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E5D0Cu;
    SET_GPR_U32(ctx, 31, 0x1E5D14u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D14u; }
        if (ctx->pc != 0x1E5D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D14u; }
        if (ctx->pc != 0x1E5D14u) { return; }
    }
    ctx->pc = 0x1E5D14u;
label_1e5d14:
    // 0x1e5d14: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e5d14u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5d18: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e5d18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e5d1c: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1e5d1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5d20: 0x97c7000c  lhu         $a3, 0xC($fp)
    ctx->pc = 0x1e5d20u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5d24: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5d24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5d28: 0x90420621  lbu         $v0, 0x621($v0)
    ctx->pc = 0x1e5d28u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1569)));
    // 0x1e5d2c: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5d30: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5d30u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5d34: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1e5d34u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5d38: 0x24080014  addiu       $t0, $zero, 0x14
    ctx->pc = 0x1e5d38u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1e5d3c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e5d3cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5d40: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5D40u;
    SET_GPR_U32(ctx, 31, 0x1E5D48u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D48u; }
        if (ctx->pc != 0x1E5D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D48u; }
        if (ctx->pc != 0x1E5D48u) { return; }
    }
    ctx->pc = 0x1E5D48u;
label_1e5d48:
    // 0x1e5d48: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5D48u;
    {
        const bool branch_taken_0x1e5d48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5d48) {
            ctx->pc = 0x1E5D64u;
            goto label_1e5d64;
        }
    }
    ctx->pc = 0x1E5D50u;
    // 0x1e5d50: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5d54: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5d54u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5d58: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5d58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5d5c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E5D5Cu;
    {
        const bool branch_taken_0x1e5d5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5d5c) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5D64u;
label_1e5d64:
    // 0x1e5d64: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e5d64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5d68: 0x24050028  addiu       $a1, $zero, 0x28
    ctx->pc = 0x1e5d68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e5d6c: 0x8fc60010  lw          $a2, 0x10($fp)
    ctx->pc = 0x1e5d6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5d70: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E5D70u;
    SET_GPR_U32(ctx, 31, 0x1E5D78u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D78u; }
        if (ctx->pc != 0x1E5D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D78u; }
        if (ctx->pc != 0x1E5D78u) { return; }
    }
    ctx->pc = 0x1E5D78u;
label_1e5d78:
    // 0x1e5d78: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e5d78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5d7c: 0x90640621  lbu         $a0, 0x621($v1)
    ctx->pc = 0x1e5d7cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1569)));
    // 0x1e5d80: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e5d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e5d84: 0xa0620621  sb          $v0, 0x621($v1)
    ctx->pc = 0x1e5d84u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1569), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e5d88: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e5d88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e5d8c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e5d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e5d90: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e5d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
label_1e5d94:
    // 0x1e5d94: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5d94u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5d98: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e5d98u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e5d9c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e5d9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e5da0: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e5da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e5da4: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5DA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5DACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
