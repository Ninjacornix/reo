#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E4E74
// Address: 0x1e4e74 - 0x1e5008
void sub_001E4E74_0x1e4e74(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E4E74_0x1e4e74");
#endif

    switch (ctx->pc) {
        case 0x1e4f28u: goto label_1e4f28;
        case 0x1e4f60u: goto label_1e4f60;
        case 0x1e4f84u: goto label_1e4f84;
        case 0x1e4facu: goto label_1e4fac;
        case 0x1e4fd0u: goto label_1e4fd0;
        default: break;
    }

    ctx->pc = 0x1e4e74u;

    // 0x1e4e74: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e4e74u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e4e78: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e4e78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e4e7c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e4e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e4e80: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e4e80u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4e84: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4e84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e4e88: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e4e88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4e8c: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e4e90: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e4e90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e4e94: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4e94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4e98: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e4e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e4e9c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E4E9Cu;
    {
        const bool branch_taken_0x1e4e9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e4e9c) {
            ctx->pc = 0x1E4EC4u;
            goto label_1e4ec4;
        }
    }
    ctx->pc = 0x1E4EA4u;
    // 0x1e4ea4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4ea8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4eac: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4eacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4eb0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4eb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4eb8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4ebc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4EBCu;
    {
        const bool branch_taken_0x1e4ebc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4ebc) {
            ctx->pc = 0x1E4ED8u;
            goto label_1e4ed8;
        }
    }
    ctx->pc = 0x1E4EC4u;
label_1e4ec4:
    // 0x1e4ec4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e4ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e4ec8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4ec8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4ecc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4eccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4ed0: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1E4ED0u;
    {
        const bool branch_taken_0x1e4ed0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4ed0) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4ED8u;
label_1e4ed8:
    // 0x1e4ed8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4edc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4edcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4ee0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4ee4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4ee8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4eec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4eecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4ef0: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4ef0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4ef4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4ef8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e4ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4efc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4EFCu;
    {
        const bool branch_taken_0x1e4efc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4efc) {
            ctx->pc = 0x1E4F18u;
            goto label_1e4f18;
        }
    }
    ctx->pc = 0x1E4F04u;
    // 0x1e4f04: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4f04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4f08: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4f08u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4f0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4f10: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x1E4F10u;
    {
        const bool branch_taken_0x1e4f10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f10) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4F18u;
label_1e4f18:
    // 0x1e4f18: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4f18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4f1c: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e4f1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4f20: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4F20u;
    SET_GPR_U32(ctx, 31, 0x1E4F28u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F28u; }
        if (ctx->pc != 0x1E4F28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F28u; }
        if (ctx->pc != 0x1E4F28u) { return; }
    }
    ctx->pc = 0x1E4F28u;
label_1e4f28:
    // 0x1e4f28: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e4f28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e4f2c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e4f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4f30: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4F30u;
    {
        const bool branch_taken_0x1e4f30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f30) {
            ctx->pc = 0x1E4F4Cu;
            goto label_1e4f4c;
        }
    }
    ctx->pc = 0x1E4F38u;
    // 0x1e4f38: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4f3c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4f40: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4f44: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1E4F44u;
    {
        const bool branch_taken_0x1e4f44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f44) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4F4Cu;
label_1e4f4c:
    // 0x1e4f4c: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4f4cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4f50: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e4f50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4f54: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4f54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4f58: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E4F58u;
    SET_GPR_U32(ctx, 31, 0x1E4F60u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F60u; }
        if (ctx->pc != 0x1E4F60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F60u; }
        if (ctx->pc != 0x1E4F60u) { return; }
    }
    ctx->pc = 0x1E4F60u;
label_1e4f60:
    // 0x1e4f60: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e4f60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e4f64: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4f64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4f68: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E4F68u;
    {
        const bool branch_taken_0x1e4f68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f68) {
            ctx->pc = 0x1E4F98u;
            goto label_1e4f98;
        }
    }
    ctx->pc = 0x1E4F70u;
    // 0x1e4f70: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4f74: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4f74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e4f78: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4f78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4f7c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E4F7Cu;
    SET_GPR_U32(ctx, 31, 0x1E4F84u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F84u; }
        if (ctx->pc != 0x1E4F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F84u; }
        if (ctx->pc != 0x1E4F84u) { return; }
    }
    ctx->pc = 0x1E4F84u;
label_1e4f84:
    // 0x1e4f84: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4f84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4f88: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4f88u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4f8c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4f8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4f90: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E4F90u;
    {
        const bool branch_taken_0x1e4f90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f90) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4F98u;
label_1e4f98:
    // 0x1e4f98: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e4f98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4f9c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e4f9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4fa0: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4fa0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4fa4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E4FA4u;
    SET_GPR_U32(ctx, 31, 0x1E4FACu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4FACu; }
        if (ctx->pc != 0x1E4FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4FACu; }
        if (ctx->pc != 0x1E4FACu) { return; }
    }
    ctx->pc = 0x1E4FACu;
label_1e4fac:
    // 0x1e4fac: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4facu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4fb0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4fb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4fb4: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4fb4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4fb8: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1e4fb8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1e4fbc: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e4fbcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4fc0: 0x24080032  addiu       $t0, $zero, 0x32
    ctx->pc = 0x1e4fc0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x1e4fc4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4fc4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4fc8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4FC8u;
    SET_GPR_U32(ctx, 31, 0x1E4FD0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4FD0u; }
        if (ctx->pc != 0x1E4FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4FD0u; }
        if (ctx->pc != 0x1E4FD0u) { return; }
    }
    ctx->pc = 0x1E4FD0u;
label_1e4fd0:
    // 0x1e4fd0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4FD0u;
    {
        const bool branch_taken_0x1e4fd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4fd0) {
            ctx->pc = 0x1E4FECu;
            goto label_1e4fec;
        }
    }
    ctx->pc = 0x1E4FD8u;
    // 0x1e4fd8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4fdc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4fe0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4fe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4fe4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E4FE4u;
    {
        const bool branch_taken_0x1e4fe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4fe4) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4FECu;
label_1e4fec:
    // 0x1e4fec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e4fecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4ff0:
    // 0x1e4ff0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4ff0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4ff4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e4ff4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4ff8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4ff8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e4ffc: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e4ffcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e5000: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5000u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5008u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
