#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E1D2C
// Address: 0x1e1d2c - 0x1e1ee8
void sub_001E1D2C_0x1e1d2c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E1D2C_0x1e1d2c");
#endif

    switch (ctx->pc) {
        case 0x1e1de0u: goto label_1e1de0;
        case 0x1e1e14u: goto label_1e1e14;
        case 0x1e1e38u: goto label_1e1e38;
        case 0x1e1e5cu: goto label_1e1e5c;
        case 0x1e1e84u: goto label_1e1e84;
        case 0x1e1eb4u: goto label_1e1eb4;
        default: break;
    }

    ctx->pc = 0x1e1d2cu;

    // 0x1e1d2c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e1d2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e1d30: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e1d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e1d34: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e1d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e1d38: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1d38u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1d3c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1d40: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e1d40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e1d44: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e1d44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e1d48: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e1d48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e1d4c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e1d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1d50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1d54: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1D54u;
    {
        const bool branch_taken_0x1e1d54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1d54) {
            ctx->pc = 0x1E1D7Cu;
            goto label_1e1d7c;
        }
    }
    ctx->pc = 0x1E1D5Cu;
    // 0x1e1d5c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1d60: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1d60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1d64: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1d64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1d68: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1d68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1d6c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1d70: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1d70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1d74: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1D74u;
    {
        const bool branch_taken_0x1e1d74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1d74) {
            ctx->pc = 0x1E1D90u;
            goto label_1e1d90;
        }
    }
    ctx->pc = 0x1E1D7Cu;
label_1e1d7c:
    // 0x1e1d7c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e1d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1d80: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1d80u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1d84: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1d84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1d88: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x1E1D88u;
    {
        const bool branch_taken_0x1e1d88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1d88) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1D90u;
label_1e1d90:
    // 0x1e1d90: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1d94: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1d94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1d98: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1d98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1d9c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1da0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1da0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1da4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1da4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1da8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e1da8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e1dac: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e1dacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1db0: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e1db0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e1db4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1DB4u;
    {
        const bool branch_taken_0x1e1db4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1db4) {
            ctx->pc = 0x1E1DD0u;
            goto label_1e1dd0;
        }
    }
    ctx->pc = 0x1E1DBCu;
    // 0x1e1dbc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1dc0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1dc4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1dc8: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1E1DC8u;
    {
        const bool branch_taken_0x1e1dc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1dc8) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1DD0u;
label_1e1dd0:
    // 0x1e1dd0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e1dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1dd4: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1e1dd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e1dd8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E1DD8u;
    SET_GPR_U32(ctx, 31, 0x1E1DE0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1DE0u; }
        if (ctx->pc != 0x1E1DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1DE0u; }
        if (ctx->pc != 0x1E1DE0u) { return; }
    }
    ctx->pc = 0x1E1DE0u;
label_1e1de0:
    // 0x1e1de0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e1de0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e1de4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e1de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e1de8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1DE8u;
    {
        const bool branch_taken_0x1e1de8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1de8) {
            ctx->pc = 0x1E1E04u;
            goto label_1e1e04;
        }
    }
    ctx->pc = 0x1E1DF0u;
    // 0x1e1df0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e1df0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e1df4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1df4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1df8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1df8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1dfc: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1E1DFCu;
    {
        const bool branch_taken_0x1e1dfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1dfc) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1E04u;
label_1e1e04:
    // 0x1e1e04: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e1e04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e1e08: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1e1e08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e1e0c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E1E0Cu;
    SET_GPR_U32(ctx, 31, 0x1E1E14u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E14u; }
        if (ctx->pc != 0x1E1E14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E14u; }
        if (ctx->pc != 0x1E1E14u) { return; }
    }
    ctx->pc = 0x1E1E14u;
label_1e1e14:
    // 0x1e1e14: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e1e14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e1e18: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e1e18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e1e1c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E1E1Cu;
    {
        const bool branch_taken_0x1e1e1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1e1c) {
            ctx->pc = 0x1E1E4Cu;
            goto label_1e1e4c;
        }
    }
    ctx->pc = 0x1E1E24u;
    // 0x1e1e24: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e1e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1e28: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e1e28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e1e2c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e1e2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e1e30: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E1E30u;
    SET_GPR_U32(ctx, 31, 0x1E1E38u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E38u; }
        if (ctx->pc != 0x1E1E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E38u; }
        if (ctx->pc != 0x1E1E38u) { return; }
    }
    ctx->pc = 0x1E1E38u;
label_1e1e38:
    // 0x1e1e38: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e1e38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e1e3c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1e40: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1e40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1e44: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1E1E44u;
    {
        const bool branch_taken_0x1e1e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1e44) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1E4Cu;
label_1e1e4c:
    // 0x1e1e4c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e1e4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e1e50: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e1e50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1e54: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E1E54u;
    SET_GPR_U32(ctx, 31, 0x1E1E5Cu);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E5Cu; }
        if (ctx->pc != 0x1E1E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E5Cu; }
        if (ctx->pc != 0x1E1E5Cu) { return; }
    }
    ctx->pc = 0x1E1E5Cu;
label_1e1e5c:
    // 0x1e1e5c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e1e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1e60: 0x90420614  lbu         $v0, 0x614($v0)
    ctx->pc = 0x1e1e60u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1556)));
    // 0x1e1e64: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e1e64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1e68: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e1e68u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e1e6c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e1e6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e1e70: 0x24070010  addiu       $a3, $zero, 0x10
    ctx->pc = 0x1e1e70u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e1e74: 0x24080003  addiu       $t0, $zero, 0x3
    ctx->pc = 0x1e1e74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1e1e78: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e1e78u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1e7c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E1E7Cu;
    SET_GPR_U32(ctx, 31, 0x1E1E84u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E84u; }
        if (ctx->pc != 0x1E1E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E84u; }
        if (ctx->pc != 0x1E1E84u) { return; }
    }
    ctx->pc = 0x1E1E84u;
label_1e1e84:
    // 0x1e1e84: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1E84u;
    {
        const bool branch_taken_0x1e1e84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1e84) {
            ctx->pc = 0x1E1EA0u;
            goto label_1e1ea0;
        }
    }
    ctx->pc = 0x1E1E8Cu;
    // 0x1e1e8c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1e90: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1e90u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1e94: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1e94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1e98: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E1E98u;
    {
        const bool branch_taken_0x1e1e98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1e98) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1EA0u;
label_1e1ea0:
    // 0x1e1ea0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e1ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1ea4: 0x2405001d  addiu       $a1, $zero, 0x1D
    ctx->pc = 0x1e1ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1e1ea8: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e1ea8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e1eac: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E1EACu;
    SET_GPR_U32(ctx, 31, 0x1E1EB4u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1EB4u; }
        if (ctx->pc != 0x1E1EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1EB4u; }
        if (ctx->pc != 0x1E1EB4u) { return; }
    }
    ctx->pc = 0x1E1EB4u;
label_1e1eb4:
    // 0x1e1eb4: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e1eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1eb8: 0x90640614  lbu         $a0, 0x614($v1)
    ctx->pc = 0x1e1eb8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1556)));
    // 0x1e1ebc: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e1ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e1ec0: 0xa0620614  sb          $v0, 0x614($v1)
    ctx->pc = 0x1e1ec0u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1556), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e1ec4: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e1ec4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e1ec8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e1ec8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e1ecc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e1eccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e1ed0:
    // 0x1e1ed0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e1ed0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1ed4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e1ed4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e1ed8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e1ed8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e1edc: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e1edcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e1ee0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E1EE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E1EE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
