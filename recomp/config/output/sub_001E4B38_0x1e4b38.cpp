#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E4B38
// Address: 0x1e4b38 - 0x1e4e74
void sub_001E4B38_0x1e4b38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E4B38_0x1e4b38");
#endif

    switch (ctx->pc) {
        case 0x1e4c10u: goto label_1e4c10;
        case 0x1e4c64u: goto label_1e4c64;
        case 0x1e4c88u: goto label_1e4c88;
        case 0x1e4d08u: goto label_1e4d08;
        case 0x1e4df8u: goto label_1e4df8;
        case 0x1e4e3cu: goto label_1e4e3c;
        default: break;
    }

    ctx->pc = 0x1e4b38u;

    // 0x1e4b38: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e4b38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e4b3c: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e4b3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e4b40: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e4b40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e4b44: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e4b44u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4b48: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4b48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e4b4c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e4b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4b50: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4b50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e4b54: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e4b54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4b58: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e4b58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e4b5c: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e4b5cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e4b60: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e4b60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e4b64: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4b64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4b68: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e4b68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e4b6c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E4B6Cu;
    {
        const bool branch_taken_0x1e4b6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e4b6c) {
            ctx->pc = 0x1E4B94u;
            goto label_1e4b94;
        }
    }
    ctx->pc = 0x1E4B74u;
    // 0x1e4b74: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4b74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4b78: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4b78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4b7c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4b80: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4b80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4b84: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4b84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4b88: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4b8c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4B8Cu;
    {
        const bool branch_taken_0x1e4b8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4b8c) {
            ctx->pc = 0x1E4BA8u;
            goto label_1e4ba8;
        }
    }
    ctx->pc = 0x1E4B94u;
label_1e4b94:
    // 0x1e4b94: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e4b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e4b98: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4b98u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4b9c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4ba0: 0x100000ae  b           . + 4 + (0xAE << 2)
    ctx->pc = 0x1E4BA0u;
    {
        const bool branch_taken_0x1e4ba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4ba0) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4BA8u;
label_1e4ba8:
    // 0x1e4ba8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4bac: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4bacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4bb0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4bb4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4bb8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4bbc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4bc0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e4bc4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4bc8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e4bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4bcc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4BCCu;
    {
        const bool branch_taken_0x1e4bcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4bcc) {
            ctx->pc = 0x1E4BE8u;
            goto label_1e4be8;
        }
    }
    ctx->pc = 0x1E4BD4u;
    // 0x1e4bd4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4bd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4bd8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4bdc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4be0: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1E4BE0u;
    {
        const bool branch_taken_0x1e4be0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4be0) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4BE8u;
label_1e4be8:
    // 0x1e4be8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4be8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4bec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4becu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4bf0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4bf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4bf4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e4bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4bf8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4bfc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4c00: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e4c00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4c04: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4c04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4c08: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4C08u;
    SET_GPR_U32(ctx, 31, 0x1E4C10u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C10u; }
        if (ctx->pc != 0x1E4C10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C10u; }
        if (ctx->pc != 0x1E4C10u) { return; }
    }
    ctx->pc = 0x1E4C10u;
label_1e4c10:
    // 0x1e4c10: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4c10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4c14: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4c14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4c18: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4C18u;
    {
        const bool branch_taken_0x1e4c18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4c18) {
            ctx->pc = 0x1E4C34u;
            goto label_1e4c34;
        }
    }
    ctx->pc = 0x1E4C20u;
    // 0x1e4c20: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4c20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4c24: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4c24u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4c28: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4c28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4c2c: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x1E4C2Cu;
    {
        const bool branch_taken_0x1e4c2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4c2c) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4C34u;
label_1e4c34:
    // 0x1e4c34: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4c34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4c38: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4c38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4c3c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e4c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4c40: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e4c40u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4c44: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4c44u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4c48: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4c4c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4c50: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e4c50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4c54: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4c54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4c58: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4c58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4c5c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E4C5Cu;
    SET_GPR_U32(ctx, 31, 0x1E4C64u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C64u; }
        if (ctx->pc != 0x1E4C64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C64u; }
        if (ctx->pc != 0x1E4C64u) { return; }
    }
    ctx->pc = 0x1E4C64u;
label_1e4c64:
    // 0x1e4c64: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e4c64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e4c68: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e4c68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4c6c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E4C6Cu;
    {
        const bool branch_taken_0x1e4c6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4c6c) {
            ctx->pc = 0x1E4C9Cu;
            goto label_1e4c9c;
        }
    }
    ctx->pc = 0x1E4C74u;
    // 0x1e4c74: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4c78: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4c78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e4c7c: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e4c7cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4c80: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E4C80u;
    SET_GPR_U32(ctx, 31, 0x1E4C88u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C88u; }
        if (ctx->pc != 0x1E4C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C88u; }
        if (ctx->pc != 0x1E4C88u) { return; }
    }
    ctx->pc = 0x1E4C88u;
label_1e4c88:
    // 0x1e4c88: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4c88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4c8c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4c8cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4c90: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4c90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4c94: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x1E4C94u;
    {
        const bool branch_taken_0x1e4c94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4c94) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4C9Cu;
label_1e4c9c:
    // 0x1e4c9c: 0x27c60018  addiu       $a2, $fp, 0x18
    ctx->pc = 0x1e4c9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e4ca0: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e4ca0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e4ca4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4ca8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4cac: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e4cacu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e4cb0: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e4cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e4cb4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4cb8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4cbc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e4cbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4cc0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e4cc4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4cc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4cc8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4ccc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e4cccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4cd0: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e4cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4cd4: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e4cd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e4cd8: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e4cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4cdc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4cdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4ce0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4ce4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e4ce4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4ce8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e4cec: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e4cecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e4cf0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e4cf4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4cf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4cf8: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e4cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e4cfc: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e4cfcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e4d00: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e4d00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e4d04: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e4d04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
label_1e4d08:
    // 0x1e4d08: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4d08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4d0c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e4d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4d10: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4d10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4d14: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1e4d14u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1e4d18: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E4D18u;
    {
        const bool branch_taken_0x1e4d18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4d18) {
            ctx->pc = 0x1E4D28u;
            goto label_1e4d28;
        }
    }
    ctx->pc = 0x1E4D20u;
    // 0x1e4d20: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1E4D20u;
    {
        const bool branch_taken_0x1e4d20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4d20) {
            ctx->pc = 0x1E4DE4u;
            goto label_1e4de4;
        }
    }
    ctx->pc = 0x1E4D28u;
label_1e4d28:
    // 0x1e4d28: 0x27c70018  addiu       $a3, $fp, 0x18
    ctx->pc = 0x1e4d28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e4d2c: 0x8ce60000  lw          $a2, 0x0($a3)
    ctx->pc = 0x1e4d2cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1e4d30: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e4d30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4d34: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4d34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4d38: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4d38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4d3c: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1e4d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1e4d40: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4d44: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4d44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4d48: 0x304400ff  andi        $a0, $v0, 0xFF
    ctx->pc = 0x1e4d48u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e4d4c: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x1e4d4cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1e4d50: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4d50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4d54: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4d54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4d58: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4d58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4d5c: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e4d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e4d60: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4d60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4d64: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4d64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4d68: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e4d68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4d6c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e4d70: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4d70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4d74: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4d74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4d78: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4d78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4d7c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4d80: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e4d80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e4d84: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4d84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4d88: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e4d88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4d8c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e4d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4d90: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4d90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4d94: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e4d94u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4d98: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4d98u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4d9c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4d9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4da0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4da0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4da4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4da4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4da8: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e4da8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e4dac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4dacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4db0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e4db0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4db4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4db4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e4db8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4db8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4dbc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e4dc0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4dc0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4dc4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1e4dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1e4dc8: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1e4dc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1e4dcc: 0xace60000  sw          $a2, 0x0($a3)
    ctx->pc = 0x1e4dccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 6));
    // 0x1e4dd0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4dd4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e4dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e4dd8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e4dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e4ddc: 0x1000ffca  b           . + 4 + (-0x36 << 2)
    ctx->pc = 0x1E4DDCu;
    {
        const bool branch_taken_0x1e4ddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4ddc) {
            ctx->pc = 0x1E4D08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e4d08;
        }
    }
    ctx->pc = 0x1E4DE4u;
label_1e4de4:
    // 0x1e4de4: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e4de4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4de8: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e4de8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4dec: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4decu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4df0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E4DF0u;
    SET_GPR_U32(ctx, 31, 0x1E4DF8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4DF8u; }
        if (ctx->pc != 0x1E4DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4DF8u; }
        if (ctx->pc != 0x1E4DF8u) { return; }
    }
    ctx->pc = 0x1E4DF8u;
label_1e4df8:
    // 0x1e4df8: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e4df8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4dfc: 0x3442a400  ori         $v0, $v0, 0xA400
    ctx->pc = 0x1e4dfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)41984);
    // 0x1e4e00: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e4e00u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4e04: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4e04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4e08: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4e08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4e0c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e4e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4e10: 0x97c30008  lhu         $v1, 0x8($fp)
    ctx->pc = 0x1e4e10u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4e14: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4e14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4e18: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4e1c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e4e1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4e20: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e4e20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4e24: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e4e24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4e28: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e4e28u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4e2c: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1e4e2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e4e30: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4e30u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4e34: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4E34u;
    SET_GPR_U32(ctx, 31, 0x1E4E3Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4E3Cu; }
        if (ctx->pc != 0x1E4E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4E3Cu; }
        if (ctx->pc != 0x1E4E3Cu) { return; }
    }
    ctx->pc = 0x1E4E3Cu;
label_1e4e3c:
    // 0x1e4e3c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4E3Cu;
    {
        const bool branch_taken_0x1e4e3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4e3c) {
            ctx->pc = 0x1E4E58u;
            goto label_1e4e58;
        }
    }
    ctx->pc = 0x1E4E44u;
    // 0x1e4e44: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4e44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4e48: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4e48u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4e4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4e50: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E4E50u;
    {
        const bool branch_taken_0x1e4e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4e50) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4E58u;
label_1e4e58:
    // 0x1e4e58: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e4e58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4e5c:
    // 0x1e4e5c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4e5cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4e60: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e4e60u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e4e64: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e4e64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e4e68: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e4e68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e4e6c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4E6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4E74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
