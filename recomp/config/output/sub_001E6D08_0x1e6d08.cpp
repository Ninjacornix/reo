#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E6D08
// Address: 0x1e6d08 - 0x1e7294
void sub_001E6D08_0x1e6d08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E6D08_0x1e6d08");
#endif

    switch (ctx->pc) {
        case 0x1e6dc0u: goto label_1e6dc0;
        case 0x1e6df4u: goto label_1e6df4;
        case 0x1e6e18u: goto label_1e6e18;
        case 0x1e6e38u: goto label_1e6e38;
        case 0x1e6e48u: goto label_1e6e48;
        case 0x1e6f5cu: goto label_1e6f5c;
        case 0x1e6f80u: goto label_1e6f80;
        case 0x1e6fbcu: goto label_1e6fbc;
        case 0x1e6fd8u: goto label_1e6fd8;
        case 0x1e7080u: goto label_1e7080;
        case 0x1e70b0u: goto label_1e70b0;
        case 0x1e70f8u: goto label_1e70f8;
        case 0x1e7114u: goto label_1e7114;
        case 0x1e7158u: goto label_1e7158;
        case 0x1e7174u: goto label_1e7174;
        case 0x1e71bcu: goto label_1e71bc;
        case 0x1e71d8u: goto label_1e71d8;
        case 0x1e7210u: goto label_1e7210;
        case 0x1e7240u: goto label_1e7240;
        case 0x1e7278u: goto label_1e7278;
        default: break;
    }

    ctx->pc = 0x1e6d08u;

    // 0x1e6d08: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1e6d08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1e6d0c: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1e6d0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1e6d10: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1e6d10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1e6d14: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6d14u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6d18: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6d18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e6d1c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e6d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6d20: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e6d20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e6d24: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e6d24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e6d28: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e6d28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e6d2c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e6d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6d30: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6d30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6d34: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E6D34u;
    {
        const bool branch_taken_0x1e6d34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e6d34) {
            ctx->pc = 0x1E6D5Cu;
            goto label_1e6d5c;
        }
    }
    ctx->pc = 0x1E6D3Cu;
    // 0x1e6d3c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6d40: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6d40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6d44: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6d44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6d48: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6d48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6d4c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6d50: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6d50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6d54: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6D54u;
    {
        const bool branch_taken_0x1e6d54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6d54) {
            ctx->pc = 0x1E6D70u;
            goto label_1e6d70;
        }
    }
    ctx->pc = 0x1E6D5Cu;
label_1e6d5c:
    // 0x1e6d5c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e6d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e6d60: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6d60u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6d64: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6d68: 0x10000144  b           . + 4 + (0x144 << 2)
    ctx->pc = 0x1E6D68u;
    {
        const bool branch_taken_0x1e6d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6d68) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6D70u;
label_1e6d70:
    // 0x1e6d70: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6d70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6d74: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6d74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6d78: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6d78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6d7c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6d80: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6d84: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6d84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6d88: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e6d88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6d8c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6d90: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e6d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6d94: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6D94u;
    {
        const bool branch_taken_0x1e6d94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6d94) {
            ctx->pc = 0x1E6DB0u;
            goto label_1e6db0;
        }
    }
    ctx->pc = 0x1E6D9Cu;
    // 0x1e6d9c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6da0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6da0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6da4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6da4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6da8: 0x10000134  b           . + 4 + (0x134 << 2)
    ctx->pc = 0x1E6DA8u;
    {
        const bool branch_taken_0x1e6da8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6da8) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6DB0u;
label_1e6db0:
    // 0x1e6db0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e6db0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6db4: 0x240502a8  addiu       $a1, $zero, 0x2A8
    ctx->pc = 0x1e6db4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 680));
    // 0x1e6db8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E6DB8u;
    SET_GPR_U32(ctx, 31, 0x1E6DC0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6DC0u; }
        if (ctx->pc != 0x1E6DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6DC0u; }
        if (ctx->pc != 0x1E6DC0u) { return; }
    }
    ctx->pc = 0x1E6DC0u;
label_1e6dc0:
    // 0x1e6dc0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e6dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e6dc4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e6dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6dc8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6DC8u;
    {
        const bool branch_taken_0x1e6dc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6dc8) {
            ctx->pc = 0x1E6DE4u;
            goto label_1e6de4;
        }
    }
    ctx->pc = 0x1E6DD0u;
    // 0x1e6dd0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6dd4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6dd4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6dd8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6ddc: 0x10000127  b           . + 4 + (0x127 << 2)
    ctx->pc = 0x1E6DDCu;
    {
        const bool branch_taken_0x1e6ddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ddc) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6DE4u;
label_1e6de4:
    // 0x1e6de4: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e6de4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6de8: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e6de8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e6dec: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E6DECu;
    SET_GPR_U32(ctx, 31, 0x1E6DF4u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6DF4u; }
        if (ctx->pc != 0x1E6DF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6DF4u; }
        if (ctx->pc != 0x1E6DF4u) { return; }
    }
    ctx->pc = 0x1E6DF4u;
label_1e6df4:
    // 0x1e6df4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e6df4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e6df8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e6df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6dfc: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E6DFCu;
    {
        const bool branch_taken_0x1e6dfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6dfc) {
            ctx->pc = 0x1E6E2Cu;
            goto label_1e6e2c;
        }
    }
    ctx->pc = 0x1E6E04u;
    // 0x1e6e04: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6e04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6e08: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e6e08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e6e0c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6e0cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6e10: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E6E10u;
    SET_GPR_U32(ctx, 31, 0x1E6E18u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6E18u; }
        if (ctx->pc != 0x1E6E18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6E18u; }
        if (ctx->pc != 0x1E6E18u) { return; }
    }
    ctx->pc = 0x1E6E18u;
label_1e6e18:
    // 0x1e6e18: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6e1c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6e1cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6e20: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6e20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6e24: 0x10000115  b           . + 4 + (0x115 << 2)
    ctx->pc = 0x1E6E24u;
    {
        const bool branch_taken_0x1e6e24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e24) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6E2Cu;
label_1e6e2c:
    // 0x1e6e2c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e6e2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e6e30: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6E30u;
    SET_GPR_U32(ctx, 31, 0x1E6E38u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6E38u; }
        if (ctx->pc != 0x1E6E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6E38u; }
        if (ctx->pc != 0x1E6E38u) { return; }
    }
    ctx->pc = 0x1E6E38u;
label_1e6e38:
    // 0x1e6e38: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e6e38u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6e3c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e6e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6e40: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1e6e40u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1e6e44: 0xafc00030  sw          $zero, 0x30($fp)
    ctx->pc = 0x1e6e44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 0));
label_1e6e48:
    // 0x1e6e48: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e6e48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6e4c: 0x28420020  slti        $v0, $v0, 0x20
    ctx->pc = 0x1e6e4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1e6e50: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6E50u;
    {
        const bool branch_taken_0x1e6e50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e50) {
            ctx->pc = 0x1E6E60u;
            goto label_1e6e60;
        }
    }
    ctx->pc = 0x1E6E58u;
    // 0x1e6e58: 0x100000e7  b           . + 4 + (0xE7 << 2)
    ctx->pc = 0x1E6E58u;
    {
        const bool branch_taken_0x1e6e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e58) {
            ctx->pc = 0x1E71F8u;
            goto label_1e71f8;
        }
    }
    ctx->pc = 0x1E6E60u;
label_1e6e60:
    // 0x1e6e60: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6e64: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6e64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6e68: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6e68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6e6c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6e70: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6e70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6e74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6e74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6e78: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6e7c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6e80: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6E80u;
    {
        const bool branch_taken_0x1e6e80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e80) {
            ctx->pc = 0x1E6E90u;
            goto label_1e6e90;
        }
    }
    ctx->pc = 0x1E6E88u;
    // 0x1e6e88: 0x100000db  b           . + 4 + (0xDB << 2)
    ctx->pc = 0x1E6E88u;
    {
        const bool branch_taken_0x1e6e88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e88) {
            ctx->pc = 0x1E71F8u;
            goto label_1e71f8;
        }
    }
    ctx->pc = 0x1E6E90u;
label_1e6e90:
    // 0x1e6e90: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6e90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6e94: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6e94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6e98: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6e98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6e9c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6ea0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6ea4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6ea8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6eac: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e6eacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e6eb0: 0x21142  srl         $v0, $v0, 5
    ctx->pc = 0x1e6eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 5));
    // 0x1e6eb4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1e6eb8: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1e6eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1e6ebc: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6ec0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e6ec4: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1e6ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1e6ec8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6ecc: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6eccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6ed0: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1E6ED0u;
    {
        const bool branch_taken_0x1e6ed0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6ed0) {
            ctx->pc = 0x1E6F28u;
            goto label_1e6f28;
        }
    }
    ctx->pc = 0x1E6ED8u;
    // 0x1e6ed8: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6ed8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6edc: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x1e6edcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e6ee0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6EE0u;
    {
        const bool branch_taken_0x1e6ee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ee0) {
            ctx->pc = 0x1E6EFCu;
            goto label_1e6efc;
        }
    }
    ctx->pc = 0x1E6EE8u;
    // 0x1e6ee8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1e6ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6eec: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1E6EECu;
    {
        const bool branch_taken_0x1e6eec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6eec) {
            ctx->pc = 0x1E6F3Cu;
            goto label_1e6f3c;
        }
    }
    ctx->pc = 0x1E6EF4u;
    // 0x1e6ef4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E6EF4u;
    {
        const bool branch_taken_0x1e6ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ef4) {
            ctx->pc = 0x1E6F3Cu;
            goto label_1e6f3c;
        }
    }
    ctx->pc = 0x1E6EFCu;
label_1e6efc:
    // 0x1e6efc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e6efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e6f00: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6f00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6f04: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6F04u;
    {
        const bool branch_taken_0x1e6f04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6f04) {
            ctx->pc = 0x1E6F14u;
            goto label_1e6f14;
        }
    }
    ctx->pc = 0x1E6F0Cu;
    // 0x1e6f0c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1E6F0Cu;
    {
        const bool branch_taken_0x1e6f0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f0c) {
            ctx->pc = 0x1E6F3Cu;
            goto label_1e6f3c;
        }
    }
    ctx->pc = 0x1E6F14u;
label_1e6f14:
    // 0x1e6f14: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e6f18: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e6f18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e6f1c: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6f20: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1E6F20u;
    {
        const bool branch_taken_0x1e6f20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f20) {
            ctx->pc = 0x1E6F48u;
            goto label_1e6f48;
        }
    }
    ctx->pc = 0x1E6F28u;
label_1e6f28:
    // 0x1e6f28: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e6f2c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e6f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e6f30: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6f34: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1E6F34u;
    {
        const bool branch_taken_0x1e6f34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f34) {
            ctx->pc = 0x1E6F48u;
            goto label_1e6f48;
        }
    }
    ctx->pc = 0x1E6F3Cu;
label_1e6f3c:
    // 0x1e6f3c: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e6f40: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6f44: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
label_1e6f48:
    // 0x1e6f48: 0x97c20034  lhu         $v0, 0x34($fp)
    ctx->pc = 0x1e6f48u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e6f4c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e6f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6f50: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6f50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6f54: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E6F54u;
    SET_GPR_U32(ctx, 31, 0x1E6F5Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6F5Cu; }
        if (ctx->pc != 0x1E6F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6F5Cu; }
        if (ctx->pc != 0x1E6F5Cu) { return; }
    }
    ctx->pc = 0x1E6F5Cu;
label_1e6f5c:
    // 0x1e6f5c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6f60: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6f60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6f64: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E6F64u;
    {
        const bool branch_taken_0x1e6f64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f64) {
            ctx->pc = 0x1E6F94u;
            goto label_1e6f94;
        }
    }
    ctx->pc = 0x1E6F6Cu;
    // 0x1e6f6c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6f70: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e6f70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e6f74: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6f74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6f78: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E6F78u;
    SET_GPR_U32(ctx, 31, 0x1E6F80u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6F80u; }
        if (ctx->pc != 0x1E6F80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6F80u; }
        if (ctx->pc != 0x1E6F80u) { return; }
    }
    ctx->pc = 0x1E6F80u;
label_1e6f80:
    // 0x1e6f80: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6f80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6f84: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6f84u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6f88: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6f8c: 0x100000bb  b           . + 4 + (0xBB << 2)
    ctx->pc = 0x1E6F8Cu;
    {
        const bool branch_taken_0x1e6f8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f8c) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6F94u;
label_1e6f94:
    // 0x1e6f94: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6f94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6f98: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6f98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6f9c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6fa0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6fa4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6fa4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6fa8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6fac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6facu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6fb0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e6fb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6fb4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6FB4u;
    SET_GPR_U32(ctx, 31, 0x1E6FBCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6FBCu; }
        if (ctx->pc != 0x1E6FBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6FBCu; }
        if (ctx->pc != 0x1E6FBCu) { return; }
    }
    ctx->pc = 0x1E6FBCu;
label_1e6fbc:
    // 0x1e6fbc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e6fbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e6fc0: 0x27c20024  addiu       $v0, $fp, 0x24
    ctx->pc = 0x1e6fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 36));
    // 0x1e6fc4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6fc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6fc8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6fc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6fcc: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6fccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6fd0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6FD0u;
    SET_GPR_U32(ctx, 31, 0x1E6FD8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6FD8u; }
        if (ctx->pc != 0x1E6FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6FD8u; }
        if (ctx->pc != 0x1E6FD8u) { return; }
    }
    ctx->pc = 0x1E6FD8u;
label_1e6fd8:
    // 0x1e6fd8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6fdc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6fe0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6fe4: 0x27c50020  addiu       $a1, $fp, 0x20
    ctx->pc = 0x1e6fe4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1e6fe8: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x1e6fe8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1e6fec: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6fecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6ff0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6ff0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6ff4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6ff8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6ffc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6ffcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e7000: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7004: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7008: 0x90420004  lbu         $v0, 0x4($v0)
    ctx->pc = 0x1e7008u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e700c: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1e700cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e7010: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1e7010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e7014: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x1e7014u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x1e7018: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e7018u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e701c: 0xafc2003c  sw          $v0, 0x3C($fp)
    ctx->pc = 0x1e701cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 2));
    // 0x1e7020: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e7020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e7024: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e7024u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e7028: 0x10620026  beq         $v1, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x1E7028u;
    {
        const bool branch_taken_0x1e7028 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e7028) {
            ctx->pc = 0x1E70C4u;
            goto label_1e70c4;
        }
    }
    ctx->pc = 0x1E7030u;
    // 0x1e7030: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e7030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e7034: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x1e7034u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e7038: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E7038u;
    {
        const bool branch_taken_0x1e7038 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7038) {
            ctx->pc = 0x1E7054u;
            goto label_1e7054;
        }
    }
    ctx->pc = 0x1E7040u;
    // 0x1e7040: 0x8fc2003c  lw          $v0, 0x3C($fp)
    ctx->pc = 0x1e7040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e7044: 0x10400050  beqz        $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x1E7044u;
    {
        const bool branch_taken_0x1e7044 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7044) {
            ctx->pc = 0x1E7188u;
            goto label_1e7188;
        }
    }
    ctx->pc = 0x1E704Cu;
    // 0x1e704c: 0x1000004e  b           . + 4 + (0x4E << 2)
    ctx->pc = 0x1E704Cu;
    {
        const bool branch_taken_0x1e704c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e704c) {
            ctx->pc = 0x1E7188u;
            goto label_1e7188;
        }
    }
    ctx->pc = 0x1E7054u;
label_1e7054:
    // 0x1e7054: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e7054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e7058: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e7058u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e705c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E705Cu;
    {
        const bool branch_taken_0x1e705c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e705c) {
            ctx->pc = 0x1E706Cu;
            goto label_1e706c;
        }
    }
    ctx->pc = 0x1E7064u;
    // 0x1e7064: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E7064u;
    {
        const bool branch_taken_0x1e7064 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7064) {
            ctx->pc = 0x1E7188u;
            goto label_1e7188;
        }
    }
    ctx->pc = 0x1E706Cu;
label_1e706c:
    // 0x1e706c: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e706cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7070: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e7070u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7074: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e7074u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e7078: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1E7078u;
    SET_GPR_U32(ctx, 31, 0x1E7080u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7080u; }
        if (ctx->pc != 0x1E7080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7080u; }
        if (ctx->pc != 0x1E7080u) { return; }
    }
    ctx->pc = 0x1E7080u;
label_1e7080:
    // 0x1e7080: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e7080u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e7084: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e7084u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7088: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e7088u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e708c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e708cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e7090: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e7090u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e7094: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7098: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7098u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e709c: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e709cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e70a0: 0x8c450008  lw          $a1, 0x8($v0)
    ctx->pc = 0x1e70a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e70a4: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e70a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e70a8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E70A8u;
    SET_GPR_U32(ctx, 31, 0x1E70B0u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E70B0u; }
        if (ctx->pc != 0x1E70B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E70B0u; }
        if (ctx->pc != 0x1E70B0u) { return; }
    }
    ctx->pc = 0x1E70B0u;
label_1e70b0:
    // 0x1e70b0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e70b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e70b4: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e70b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e70b8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e70b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e70bc: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x1E70BCu;
    {
        const bool branch_taken_0x1e70bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e70bc) {
            ctx->pc = 0x1E71E4u;
            goto label_1e71e4;
        }
    }
    ctx->pc = 0x1E70C4u;
label_1e70c4:
    // 0x1e70c4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e70c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e70c8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e70c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e70cc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e70ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e70d0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e70d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e70d4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e70d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e70d8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e70d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e70dc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e70dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e70e0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e70e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e70e4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e70e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e70e8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e70e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e70ec: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e70ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e70f0: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E70F0u;
    SET_GPR_U32(ctx, 31, 0x1E70F8u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E70F8u; }
        if (ctx->pc != 0x1E70F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E70F8u; }
        if (ctx->pc != 0x1E70F8u) { return; }
    }
    ctx->pc = 0x1E70F8u;
label_1e70f8:
    // 0x1e70f8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e70f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e70fc: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e70fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e7100: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e7100u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7104: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e7104u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7108: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e7108u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e710c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E710Cu;
    SET_GPR_U32(ctx, 31, 0x1E7114u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7114u; }
        if (ctx->pc != 0x1E7114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7114u; }
        if (ctx->pc != 0x1E7114u) { return; }
    }
    ctx->pc = 0x1E7114u;
label_1e7114:
    // 0x1e7114: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e7114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7118: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e7118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e711c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e711cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e7120: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e7120u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e7124: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e7124u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7128: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e7128u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e712c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e712cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e7130: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e7130u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e7134: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7134u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7138: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e713c: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e713cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e7140: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e7140u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e7144: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e7144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e7148: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e7148u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e714c: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e714cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e7150: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E7150u;
    SET_GPR_U32(ctx, 31, 0x1E7158u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7158u; }
        if (ctx->pc != 0x1E7158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7158u; }
        if (ctx->pc != 0x1E7158u) { return; }
    }
    ctx->pc = 0x1E7158u;
label_1e7158:
    // 0x1e7158: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e7158u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e715c: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e715cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e7160: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e7160u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7164: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e7164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7168: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e7168u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e716c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E716Cu;
    SET_GPR_U32(ctx, 31, 0x1E7174u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7174u; }
        if (ctx->pc != 0x1E7174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7174u; }
        if (ctx->pc != 0x1E7174u) { return; }
    }
    ctx->pc = 0x1E7174u;
label_1e7174:
    // 0x1e7174: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e7174u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7178: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e7178u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e717c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e717cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e7180: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1E7180u;
    {
        const bool branch_taken_0x1e7180 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7180) {
            ctx->pc = 0x1E71E4u;
            goto label_1e71e4;
        }
    }
    ctx->pc = 0x1E7188u;
label_1e7188:
    // 0x1e7188: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e7188u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e718c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e718cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7190: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e7190u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e7194: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e7194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e7198: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e7198u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e719c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e719cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e71a0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e71a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e71a4: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e71a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e71a8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e71a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e71ac: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e71acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e71b0: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e71b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e71b4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E71B4u;
    SET_GPR_U32(ctx, 31, 0x1E71BCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E71BCu; }
        if (ctx->pc != 0x1E71BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E71BCu; }
        if (ctx->pc != 0x1E71BCu) { return; }
    }
    ctx->pc = 0x1E71BCu;
label_1e71bc:
    // 0x1e71bc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e71bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e71c0: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e71c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e71c4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e71c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e71c8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e71c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e71cc: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e71ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e71d0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E71D0u;
    SET_GPR_U32(ctx, 31, 0x1E71D8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E71D8u; }
        if (ctx->pc != 0x1E71D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E71D8u; }
        if (ctx->pc != 0x1E71D8u) { return; }
    }
    ctx->pc = 0x1E71D8u;
label_1e71d8:
    // 0x1e71d8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e71d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e71dc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e71dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e71e0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e71e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
label_1e71e4:
    // 0x1e71e4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e71e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e71e8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e71e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e71ec: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1e71ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1e71f0: 0x1000ff15  b           . + 4 + (-0xEB << 2)
    ctx->pc = 0x1E71F0u;
    {
        const bool branch_taken_0x1e71f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e71f0) {
            ctx->pc = 0x1E6E48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e6e48;
        }
    }
    ctx->pc = 0x1E71F8u;
label_1e71f8:
    // 0x1e71f8: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e71f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e71fc: 0x93c20030  lbu         $v0, 0x30($fp)
    ctx->pc = 0x1e71fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e7200: 0xa0620004  sb          $v0, 0x4($v1)
    ctx->pc = 0x1e7200u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e7204: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e7204u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e7208: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1E7208u;
    SET_GPR_U32(ctx, 31, 0x1E7210u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7210u; }
        if (ctx->pc != 0x1E7210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7210u; }
        if (ctx->pc != 0x1E7210u) { return; }
    }
    ctx->pc = 0x1E7210u;
label_1e7210:
    // 0x1e7210: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e7210u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7214: 0x3402fff0  ori         $v0, $zero, 0xFFF0
    ctx->pc = 0x1e7214u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65520);
    // 0x1e7218: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7218u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e721c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e721cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e7220: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e7220u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7224: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e7224u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e7228: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e7228u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e722c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e722cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7230: 0x24080049  addiu       $t0, $zero, 0x49
    ctx->pc = 0x1e7230u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 73));
    // 0x1e7234: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e7234u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7238: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E7238u;
    SET_GPR_U32(ctx, 31, 0x1E7240u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7240u; }
        if (ctx->pc != 0x1E7240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7240u; }
        if (ctx->pc != 0x1E7240u) { return; }
    }
    ctx->pc = 0x1E7240u;
label_1e7240:
    // 0x1e7240: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e7240u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e7244: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e7244u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e7248: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E7248u;
    {
        const bool branch_taken_0x1e7248 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7248) {
            ctx->pc = 0x1E7264u;
            goto label_1e7264;
        }
    }
    ctx->pc = 0x1E7250u;
    // 0x1e7250: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e7250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e7254: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e7254u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e7258: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e7258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e725c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E725Cu;
    {
        const bool branch_taken_0x1e725c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e725c) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E7264u;
label_1e7264:
    // 0x1e7264: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e7264u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7268: 0x24050032  addiu       $a1, $zero, 0x32
    ctx->pc = 0x1e7268u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x1e726c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e726cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7270: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E7270u;
    SET_GPR_U32(ctx, 31, 0x1E7278u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7278u; }
        if (ctx->pc != 0x1E7278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7278u; }
        if (ctx->pc != 0x1E7278u) { return; }
    }
    ctx->pc = 0x1E7278u;
label_1e7278:
    // 0x1e7278: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e7278u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e727c:
    // 0x1e727c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e727cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7280: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1e7280u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1e7284: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1e7284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1e7288: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1e7288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1e728c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E728Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E7294u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
