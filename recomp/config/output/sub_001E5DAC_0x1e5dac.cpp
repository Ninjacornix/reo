#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E5DAC
// Address: 0x1e5dac - 0x1e5fb8
void sub_001E5DAC_0x1e5dac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E5DAC_0x1e5dac");
#endif

    switch (ctx->pc) {
        case 0x1e5e68u: goto label_1e5e68;
        case 0x1e5e9cu: goto label_1e5e9c;
        case 0x1e5eb4u: goto label_1e5eb4;
        case 0x1e5f6cu: goto label_1e5f6c;
        case 0x1e5f9cu: goto label_1e5f9c;
        default: break;
    }

    ctx->pc = 0x1e5dacu;

    // 0x1e5dac: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e5dacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e5db0: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e5db0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e5db4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e5db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e5db8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5db8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5dbc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5dc0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e5dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e5dc4: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5dc8: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e5dc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e5dcc: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e5dccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e5dd0: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e5dd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e5dd4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5dd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5ddc: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5DDCu;
    {
        const bool branch_taken_0x1e5ddc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5ddc) {
            ctx->pc = 0x1E5E04u;
            goto label_1e5e04;
        }
    }
    ctx->pc = 0x1E5DE4u;
    // 0x1e5de4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5de8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5de8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5dec: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5decu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5df0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5df0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5df4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5df8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5dfc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5DFCu;
    {
        const bool branch_taken_0x1e5dfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5dfc) {
            ctx->pc = 0x1E5E18u;
            goto label_1e5e18;
        }
    }
    ctx->pc = 0x1E5E04u;
label_1e5e04:
    // 0x1e5e04: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5e04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5e08: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5e08u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5e0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5e10: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E5E10u;
    {
        const bool branch_taken_0x1e5e10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e10) {
            ctx->pc = 0x1E5FA0u;
            goto label_1e5fa0;
        }
    }
    ctx->pc = 0x1E5E18u;
label_1e5e18:
    // 0x1e5e18: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5e18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5e1c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5e1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5e20: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5e20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5e24: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5e24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5e28: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5e28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5e2c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5e30: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5e30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e5e34: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5e34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5e38: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5e38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5e3c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5E3Cu;
    {
        const bool branch_taken_0x1e5e3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e3c) {
            ctx->pc = 0x1E5E58u;
            goto label_1e5e58;
        }
    }
    ctx->pc = 0x1E5E44u;
    // 0x1e5e44: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5e44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5e48: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5e48u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5e4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5e50: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1E5E50u;
    {
        const bool branch_taken_0x1e5e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e50) {
            ctx->pc = 0x1E5FA0u;
            goto label_1e5fa0;
        }
    }
    ctx->pc = 0x1E5E58u;
label_1e5e58:
    // 0x1e5e58: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5e58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5e5c: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e5e5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e5e60: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E5E60u;
    SET_GPR_U32(ctx, 31, 0x1E5E68u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5E68u; }
        if (ctx->pc != 0x1E5E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5E68u; }
        if (ctx->pc != 0x1E5E68u) { return; }
    }
    ctx->pc = 0x1E5E68u;
label_1e5e68:
    // 0x1e5e68: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e5e68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e5e6c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5e70: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5E70u;
    {
        const bool branch_taken_0x1e5e70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e70) {
            ctx->pc = 0x1E5E8Cu;
            goto label_1e5e8c;
        }
    }
    ctx->pc = 0x1E5E78u;
    // 0x1e5e78: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5e7c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5e80: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5e84: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1E5E84u;
    {
        const bool branch_taken_0x1e5e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e84) {
            ctx->pc = 0x1E5FA0u;
            goto label_1e5fa0;
        }
    }
    ctx->pc = 0x1E5E8Cu;
label_1e5e8c:
    // 0x1e5e8c: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5e8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5e90: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e5e90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e5e94: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E5E94u;
    SET_GPR_U32(ctx, 31, 0x1E5E9Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5E9Cu; }
        if (ctx->pc != 0x1E5E9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5E9Cu; }
        if (ctx->pc != 0x1E5E9Cu) { return; }
    }
    ctx->pc = 0x1E5E9Cu;
label_1e5e9c:
    // 0x1e5e9c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e5e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5ea0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e5ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5ea4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e5ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5ea8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e5ea8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e5eac: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E5EACu;
    SET_GPR_U32(ctx, 31, 0x1E5EB4u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5EB4u; }
        if (ctx->pc != 0x1E5EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5EB4u; }
        if (ctx->pc != 0x1E5EB4u) { return; }
    }
    ctx->pc = 0x1E5EB4u;
label_1e5eb4:
    // 0x1e5eb4: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5eb4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5eb8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e5eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5ebc: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e5ebcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e5ec0: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e5ec0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e5ec4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e5ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5ec8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e5ec8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e5ecc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e5eccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e5ed0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e5ed0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5ed4: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e5ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5ed8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e5ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e5edc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e5edcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5ee0: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e5ee0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e5ee4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e5ee4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5ee8: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e5ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5eec: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e5eecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e5ef0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e5ef0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5ef4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5ef8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e5ef8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5efc: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1e5efcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1e5f00: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5f00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5f04: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e5f04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5f08: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e5f08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e5f0c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e5f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e5f10: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e5f10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5f14: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e5f14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e5f18: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e5f18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e5f1c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e5f1cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5f20: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e5f20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5f24: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e5f24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e5f28: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e5f28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5f2c: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e5f2cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e5f30: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e5f30u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5f34: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e5f34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5f38: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e5f38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e5f3c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e5f3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5f40: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5f40u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5f44: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e5f44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5f48: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x1e5f48u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x1e5f4c: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5f50: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e5f50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5f54: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e5f54u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e5f58: 0x24070018  addiu       $a3, $zero, 0x18
    ctx->pc = 0x1e5f58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e5f5c: 0x24080025  addiu       $t0, $zero, 0x25
    ctx->pc = 0x1e5f5cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x1e5f60: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e5f60u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5f64: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5F64u;
    SET_GPR_U32(ctx, 31, 0x1E5F6Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5F6Cu; }
        if (ctx->pc != 0x1E5F6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5F6Cu; }
        if (ctx->pc != 0x1E5F6Cu) { return; }
    }
    ctx->pc = 0x1E5F6Cu;
label_1e5f6c:
    // 0x1e5f6c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5F6Cu;
    {
        const bool branch_taken_0x1e5f6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5f6c) {
            ctx->pc = 0x1E5F88u;
            goto label_1e5f88;
        }
    }
    ctx->pc = 0x1E5F74u;
    // 0x1e5f74: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5f74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5f78: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5f78u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5f7c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5f80: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E5F80u;
    {
        const bool branch_taken_0x1e5f80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5f80) {
            ctx->pc = 0x1E5FA0u;
            goto label_1e5fa0;
        }
    }
    ctx->pc = 0x1E5F88u;
label_1e5f88:
    // 0x1e5f88: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e5f88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5f8c: 0x24050029  addiu       $a1, $zero, 0x29
    ctx->pc = 0x1e5f8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 41));
    // 0x1e5f90: 0x8fc60010  lw          $a2, 0x10($fp)
    ctx->pc = 0x1e5f90u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5f94: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E5F94u;
    SET_GPR_U32(ctx, 31, 0x1E5F9Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5F9Cu; }
        if (ctx->pc != 0x1E5F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5F9Cu; }
        if (ctx->pc != 0x1E5F9Cu) { return; }
    }
    ctx->pc = 0x1E5F9Cu;
label_1e5f9c:
    // 0x1e5f9c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5f9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5fa0:
    // 0x1e5fa0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5fa0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5fa4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e5fa4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e5fa8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e5fa8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e5fac: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e5facu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e5fb0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5FB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5FB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
