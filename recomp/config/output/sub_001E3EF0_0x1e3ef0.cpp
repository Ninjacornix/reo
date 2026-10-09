#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E3EF0
// Address: 0x1e3ef0 - 0x1e40c8
void sub_001E3EF0_0x1e3ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E3EF0_0x1e3ef0");
#endif

    switch (ctx->pc) {
        case 0x1e3fa4u: goto label_1e3fa4;
        case 0x1e3fd8u: goto label_1e3fd8;
        case 0x1e3ffcu: goto label_1e3ffc;
        case 0x1e407cu: goto label_1e407c;
        case 0x1e40acu: goto label_1e40ac;
        default: break;
    }

    ctx->pc = 0x1e3ef0u;

    // 0x1e3ef0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3ef4: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3ef8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3efc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3efcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3f00: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3f00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3f04: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3f04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3f08: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3f08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e3f0c: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e3f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e3f10: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3f10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3f14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3f18: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3F18u;
    {
        const bool branch_taken_0x1e3f18 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3f18) {
            ctx->pc = 0x1E3F40u;
            goto label_1e3f40;
        }
    }
    ctx->pc = 0x1E3F20u;
    // 0x1e3f20: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3f20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3f24: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3f24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3f28: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3f28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3f2c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3f30: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3f30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3f34: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3f34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3f38: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3F38u;
    {
        const bool branch_taken_0x1e3f38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3f38) {
            ctx->pc = 0x1E3F54u;
            goto label_1e3f54;
        }
    }
    ctx->pc = 0x1E3F40u;
label_1e3f40:
    // 0x1e3f40: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3f44: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3f44u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3f48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3f4c: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E3F4Cu;
    {
        const bool branch_taken_0x1e3f4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3f4c) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E3F54u;
label_1e3f54:
    // 0x1e3f54: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3f54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3f58: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3f58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3f5c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3f60: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3f60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3f64: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3f64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3f68: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3f68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3f6c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e3f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e3f70: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e3f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3f74: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3f74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3f78: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3F78u;
    {
        const bool branch_taken_0x1e3f78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3f78) {
            ctx->pc = 0x1E3F94u;
            goto label_1e3f94;
        }
    }
    ctx->pc = 0x1E3F80u;
    // 0x1e3f80: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3f80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3f84: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3f84u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3f88: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3f8c: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E3F8Cu;
    {
        const bool branch_taken_0x1e3f8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3f8c) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E3F94u;
label_1e3f94:
    // 0x1e3f94: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e3f94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3f98: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3f98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3f9c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3F9Cu;
    SET_GPR_U32(ctx, 31, 0x1E3FA4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FA4u; }
        if (ctx->pc != 0x1E3FA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FA4u; }
        if (ctx->pc != 0x1E3FA4u) { return; }
    }
    ctx->pc = 0x1E3FA4u;
label_1e3fa4:
    // 0x1e3fa4: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3fa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3fa8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3fac: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3FACu;
    {
        const bool branch_taken_0x1e3fac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3fac) {
            ctx->pc = 0x1E3FC8u;
            goto label_1e3fc8;
        }
    }
    ctx->pc = 0x1E3FB4u;
    // 0x1e3fb4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3fb8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3fbc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3fc0: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E3FC0u;
    {
        const bool branch_taken_0x1e3fc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3fc0) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E3FC8u;
label_1e3fc8:
    // 0x1e3fc8: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3fcc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3fccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3fd0: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3FD0u;
    SET_GPR_U32(ctx, 31, 0x1E3FD8u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FD8u; }
        if (ctx->pc != 0x1E3FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FD8u; }
        if (ctx->pc != 0x1E3FD8u) { return; }
    }
    ctx->pc = 0x1E3FD8u;
label_1e3fd8:
    // 0x1e3fd8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3fd8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3fdc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3fe0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E3FE0u;
    {
        const bool branch_taken_0x1e3fe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3fe0) {
            ctx->pc = 0x1E4010u;
            goto label_1e4010;
        }
    }
    ctx->pc = 0x1E3FE8u;
    // 0x1e3fe8: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e3fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3fec: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e3fecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e3ff0: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e3ff0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3ff4: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3FF4u;
    SET_GPR_U32(ctx, 31, 0x1E3FFCu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FFCu; }
        if (ctx->pc != 0x1E3FFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FFCu; }
        if (ctx->pc != 0x1E3FFCu) { return; }
    }
    ctx->pc = 0x1E3FFCu;
label_1e3ffc:
    // 0x1e3ffc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4000: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4000u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4004: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4008: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1E4008u;
    {
        const bool branch_taken_0x1e4008 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4008) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E4010u;
label_1e4010:
    // 0x1e4010: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4010u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4014: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e4014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4018: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e4018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e401c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e401cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e4020: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e4020u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4024: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e4024u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4028: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4028u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e402c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e402cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4030: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e4030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4034: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e4034u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4038: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4038u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e403c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e403cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4040: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4040u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4044: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e4044u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4048: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4048u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e404c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e404cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4050: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4050u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e4054: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e4054u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4058: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e4058u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e405c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e405cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4060: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4060u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4064: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e4064u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e4068: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e4068u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e406c: 0x2408000a  addiu       $t0, $zero, 0xA
    ctx->pc = 0x1e406cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1e4070: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4070u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4074: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4074u;
    SET_GPR_U32(ctx, 31, 0x1E407Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E407Cu; }
        if (ctx->pc != 0x1E407Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E407Cu; }
        if (ctx->pc != 0x1E407Cu) { return; }
    }
    ctx->pc = 0x1E407Cu;
label_1e407c:
    // 0x1e407c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E407Cu;
    {
        const bool branch_taken_0x1e407c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e407c) {
            ctx->pc = 0x1E4098u;
            goto label_1e4098;
        }
    }
    ctx->pc = 0x1E4084u;
    // 0x1e4084: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4088: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4088u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e408c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e408cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4090: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E4090u;
    {
        const bool branch_taken_0x1e4090 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4090) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E4098u;
label_1e4098:
    // 0x1e4098: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e4098u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e409c: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e409cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e40a0: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e40a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e40a4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E40A4u;
    SET_GPR_U32(ctx, 31, 0x1E40ACu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E40ACu; }
        if (ctx->pc != 0x1E40ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E40ACu; }
        if (ctx->pc != 0x1E40ACu) { return; }
    }
    ctx->pc = 0x1E40ACu;
label_1e40ac:
    // 0x1e40ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e40acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e40b0:
    // 0x1e40b0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e40b0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e40b4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e40b4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e40b8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e40b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e40bc: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e40bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e40c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E40C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E40C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
