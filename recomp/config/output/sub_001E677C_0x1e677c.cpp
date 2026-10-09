#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E677C
// Address: 0x1e677c - 0x1e6d08
void sub_001E677C_0x1e677c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E677C_0x1e677c");
#endif

    switch (ctx->pc) {
        case 0x1e6834u: goto label_1e6834;
        case 0x1e6868u: goto label_1e6868;
        case 0x1e688cu: goto label_1e688c;
        case 0x1e68acu: goto label_1e68ac;
        case 0x1e68bcu: goto label_1e68bc;
        case 0x1e69d0u: goto label_1e69d0;
        case 0x1e69f4u: goto label_1e69f4;
        case 0x1e6a30u: goto label_1e6a30;
        case 0x1e6a4cu: goto label_1e6a4c;
        case 0x1e6af4u: goto label_1e6af4;
        case 0x1e6b24u: goto label_1e6b24;
        case 0x1e6b6cu: goto label_1e6b6c;
        case 0x1e6b88u: goto label_1e6b88;
        case 0x1e6bccu: goto label_1e6bcc;
        case 0x1e6be8u: goto label_1e6be8;
        case 0x1e6c30u: goto label_1e6c30;
        case 0x1e6c4cu: goto label_1e6c4c;
        case 0x1e6c84u: goto label_1e6c84;
        case 0x1e6cb4u: goto label_1e6cb4;
        case 0x1e6cecu: goto label_1e6cec;
        default: break;
    }

    ctx->pc = 0x1e677cu;

    // 0x1e677c: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1e677cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1e6780: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1e6780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1e6784: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1e6784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1e6788: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6788u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e678c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e678cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e6790: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e6790u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6794: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e6794u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e6798: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e6798u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e679c: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e679cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e67a0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e67a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e67a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e67a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e67a8: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E67A8u;
    {
        const bool branch_taken_0x1e67a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e67a8) {
            ctx->pc = 0x1E67D0u;
            goto label_1e67d0;
        }
    }
    ctx->pc = 0x1E67B0u;
    // 0x1e67b0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e67b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e67b4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e67b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e67b8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e67b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e67bc: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e67bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e67c0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e67c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e67c4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e67c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e67c8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E67C8u;
    {
        const bool branch_taken_0x1e67c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e67c8) {
            ctx->pc = 0x1E67E4u;
            goto label_1e67e4;
        }
    }
    ctx->pc = 0x1E67D0u;
label_1e67d0:
    // 0x1e67d0: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e67d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e67d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e67d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e67d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e67d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e67dc: 0x10000144  b           . + 4 + (0x144 << 2)
    ctx->pc = 0x1E67DCu;
    {
        const bool branch_taken_0x1e67dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e67dc) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E67E4u;
label_1e67e4:
    // 0x1e67e4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e67e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e67e8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e67e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e67ec: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e67ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e67f0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e67f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e67f4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e67f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e67f8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e67f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e67fc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e67fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6800: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6804: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e6804u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6808: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6808u;
    {
        const bool branch_taken_0x1e6808 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6808) {
            ctx->pc = 0x1E6824u;
            goto label_1e6824;
        }
    }
    ctx->pc = 0x1E6810u;
    // 0x1e6810: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6814: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6814u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6818: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6818u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e681c: 0x10000134  b           . + 4 + (0x134 << 2)
    ctx->pc = 0x1E681Cu;
    {
        const bool branch_taken_0x1e681c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e681c) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E6824u;
label_1e6824:
    // 0x1e6824: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e6824u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6828: 0x240502a8  addiu       $a1, $zero, 0x2A8
    ctx->pc = 0x1e6828u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 680));
    // 0x1e682c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E682Cu;
    SET_GPR_U32(ctx, 31, 0x1E6834u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6834u; }
        if (ctx->pc != 0x1E6834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6834u; }
        if (ctx->pc != 0x1E6834u) { return; }
    }
    ctx->pc = 0x1E6834u;
label_1e6834:
    // 0x1e6834: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e6834u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e6838: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e6838u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e683c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E683Cu;
    {
        const bool branch_taken_0x1e683c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e683c) {
            ctx->pc = 0x1E6858u;
            goto label_1e6858;
        }
    }
    ctx->pc = 0x1E6844u;
    // 0x1e6844: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6848: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6848u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e684c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e684cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6850: 0x10000127  b           . + 4 + (0x127 << 2)
    ctx->pc = 0x1E6850u;
    {
        const bool branch_taken_0x1e6850 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6850) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E6858u;
label_1e6858:
    // 0x1e6858: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e6858u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e685c: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e685cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e6860: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E6860u;
    SET_GPR_U32(ctx, 31, 0x1E6868u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6868u; }
        if (ctx->pc != 0x1E6868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6868u; }
        if (ctx->pc != 0x1E6868u) { return; }
    }
    ctx->pc = 0x1E6868u;
label_1e6868:
    // 0x1e6868: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e6868u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e686c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e686cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6870: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E6870u;
    {
        const bool branch_taken_0x1e6870 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6870) {
            ctx->pc = 0x1E68A0u;
            goto label_1e68a0;
        }
    }
    ctx->pc = 0x1E6878u;
    // 0x1e6878: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6878u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e687c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e687cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e6880: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6880u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6884: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E6884u;
    SET_GPR_U32(ctx, 31, 0x1E688Cu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E688Cu; }
        if (ctx->pc != 0x1E688Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E688Cu; }
        if (ctx->pc != 0x1E688Cu) { return; }
    }
    ctx->pc = 0x1E688Cu;
label_1e688c:
    // 0x1e688c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e688cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6890: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6890u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6894: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6898: 0x10000115  b           . + 4 + (0x115 << 2)
    ctx->pc = 0x1E6898u;
    {
        const bool branch_taken_0x1e6898 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6898) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E68A0u;
label_1e68a0:
    // 0x1e68a0: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e68a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e68a4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E68A4u;
    SET_GPR_U32(ctx, 31, 0x1E68ACu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E68ACu; }
        if (ctx->pc != 0x1E68ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E68ACu; }
        if (ctx->pc != 0x1E68ACu) { return; }
    }
    ctx->pc = 0x1E68ACu;
label_1e68ac:
    // 0x1e68ac: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e68acu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e68b0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e68b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e68b4: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1e68b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1e68b8: 0xafc00030  sw          $zero, 0x30($fp)
    ctx->pc = 0x1e68b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 0));
label_1e68bc:
    // 0x1e68bc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e68bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e68c0: 0x28420020  slti        $v0, $v0, 0x20
    ctx->pc = 0x1e68c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1e68c4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E68C4u;
    {
        const bool branch_taken_0x1e68c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e68c4) {
            ctx->pc = 0x1E68D4u;
            goto label_1e68d4;
        }
    }
    ctx->pc = 0x1E68CCu;
    // 0x1e68cc: 0x100000e7  b           . + 4 + (0xE7 << 2)
    ctx->pc = 0x1E68CCu;
    {
        const bool branch_taken_0x1e68cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e68cc) {
            ctx->pc = 0x1E6C6Cu;
            goto label_1e6c6c;
        }
    }
    ctx->pc = 0x1E68D4u;
label_1e68d4:
    // 0x1e68d4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e68d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e68d8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e68d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e68dc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e68dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e68e0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e68e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e68e4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e68e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e68e8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e68e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e68ec: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e68ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e68f0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e68f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e68f4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E68F4u;
    {
        const bool branch_taken_0x1e68f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e68f4) {
            ctx->pc = 0x1E6904u;
            goto label_1e6904;
        }
    }
    ctx->pc = 0x1E68FCu;
    // 0x1e68fc: 0x100000db  b           . + 4 + (0xDB << 2)
    ctx->pc = 0x1E68FCu;
    {
        const bool branch_taken_0x1e68fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e68fc) {
            ctx->pc = 0x1E6C6Cu;
            goto label_1e6c6c;
        }
    }
    ctx->pc = 0x1E6904u;
label_1e6904:
    // 0x1e6904: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6904u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6908: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6908u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e690c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e690cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6910: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6910u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6914: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6914u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6918: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e691c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e691cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6920: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e6920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e6924: 0x21142  srl         $v0, $v0, 5
    ctx->pc = 0x1e6924u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 5));
    // 0x1e6928: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6928u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1e692c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1e692cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1e6930: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6930u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6934: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6934u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e6938: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1e6938u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1e693c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e693cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6940: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6944: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1E6944u;
    {
        const bool branch_taken_0x1e6944 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6944) {
            ctx->pc = 0x1E699Cu;
            goto label_1e699c;
        }
    }
    ctx->pc = 0x1E694Cu;
    // 0x1e694c: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e694cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6950: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x1e6950u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e6954: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6954u;
    {
        const bool branch_taken_0x1e6954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6954) {
            ctx->pc = 0x1E6970u;
            goto label_1e6970;
        }
    }
    ctx->pc = 0x1E695Cu;
    // 0x1e695c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1e695cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6960: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1E6960u;
    {
        const bool branch_taken_0x1e6960 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6960) {
            ctx->pc = 0x1E69B0u;
            goto label_1e69b0;
        }
    }
    ctx->pc = 0x1E6968u;
    // 0x1e6968: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E6968u;
    {
        const bool branch_taken_0x1e6968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6968) {
            ctx->pc = 0x1E69B0u;
            goto label_1e69b0;
        }
    }
    ctx->pc = 0x1E6970u;
label_1e6970:
    // 0x1e6970: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e6970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e6974: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6974u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6978: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6978u;
    {
        const bool branch_taken_0x1e6978 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6978) {
            ctx->pc = 0x1E6988u;
            goto label_1e6988;
        }
    }
    ctx->pc = 0x1E6980u;
    // 0x1e6980: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1E6980u;
    {
        const bool branch_taken_0x1e6980 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6980) {
            ctx->pc = 0x1E69B0u;
            goto label_1e69b0;
        }
    }
    ctx->pc = 0x1E6988u;
label_1e6988:
    // 0x1e6988: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e6988u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e698c: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e698cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e6990: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6990u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6994: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1E6994u;
    {
        const bool branch_taken_0x1e6994 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6994) {
            ctx->pc = 0x1E69BCu;
            goto label_1e69bc;
        }
    }
    ctx->pc = 0x1E699Cu;
label_1e699c:
    // 0x1e699c: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e699cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e69a0: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e69a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e69a4: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e69a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e69a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1E69A8u;
    {
        const bool branch_taken_0x1e69a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e69a8) {
            ctx->pc = 0x1E69BCu;
            goto label_1e69bc;
        }
    }
    ctx->pc = 0x1E69B0u;
label_1e69b0:
    // 0x1e69b0: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e69b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e69b4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e69b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e69b8: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e69b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
label_1e69bc:
    // 0x1e69bc: 0x97c20034  lhu         $v0, 0x34($fp)
    ctx->pc = 0x1e69bcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e69c0: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e69c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e69c4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e69c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e69c8: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E69C8u;
    SET_GPR_U32(ctx, 31, 0x1E69D0u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E69D0u; }
        if (ctx->pc != 0x1E69D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E69D0u; }
        if (ctx->pc != 0x1E69D0u) { return; }
    }
    ctx->pc = 0x1E69D0u;
label_1e69d0:
    // 0x1e69d0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e69d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e69d4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e69d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e69d8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E69D8u;
    {
        const bool branch_taken_0x1e69d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e69d8) {
            ctx->pc = 0x1E6A08u;
            goto label_1e6a08;
        }
    }
    ctx->pc = 0x1E69E0u;
    // 0x1e69e0: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e69e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e69e4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e69e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e69e8: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e69e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e69ec: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E69ECu;
    SET_GPR_U32(ctx, 31, 0x1E69F4u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E69F4u; }
        if (ctx->pc != 0x1E69F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E69F4u; }
        if (ctx->pc != 0x1E69F4u) { return; }
    }
    ctx->pc = 0x1E69F4u;
label_1e69f4:
    // 0x1e69f4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e69f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e69f8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e69f8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e69fc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e69fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6a00: 0x100000bb  b           . + 4 + (0xBB << 2)
    ctx->pc = 0x1E6A00u;
    {
        const bool branch_taken_0x1e6a00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6a00) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E6A08u;
label_1e6a08:
    // 0x1e6a08: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6a08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6a0c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6a0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6a10: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6a10u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6a14: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6a14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6a18: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6a18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6a1c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6a20: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6a20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6a24: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e6a24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6a28: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6A28u;
    SET_GPR_U32(ctx, 31, 0x1E6A30u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6A30u; }
        if (ctx->pc != 0x1E6A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6A30u; }
        if (ctx->pc != 0x1E6A30u) { return; }
    }
    ctx->pc = 0x1E6A30u;
label_1e6a30:
    // 0x1e6a30: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e6a30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e6a34: 0x27c20024  addiu       $v0, $fp, 0x24
    ctx->pc = 0x1e6a34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 36));
    // 0x1e6a38: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6a38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6a3c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6a3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6a40: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6a40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6a44: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6A44u;
    SET_GPR_U32(ctx, 31, 0x1E6A4Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6A4Cu; }
        if (ctx->pc != 0x1E6A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6A4Cu; }
        if (ctx->pc != 0x1E6A4Cu) { return; }
    }
    ctx->pc = 0x1E6A4Cu;
label_1e6a4c:
    // 0x1e6a4c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6a50: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6a50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6a54: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6a54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6a58: 0x27c50020  addiu       $a1, $fp, 0x20
    ctx->pc = 0x1e6a58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1e6a5c: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x1e6a5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1e6a60: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6a60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6a64: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6a64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6a68: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6a68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6a6c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6a70: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6a70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6a74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6a78: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6a78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6a7c: 0x90420004  lbu         $v0, 0x4($v0)
    ctx->pc = 0x1e6a7cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e6a80: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1e6a80u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e6a84: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1e6a84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e6a88: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x1e6a88u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x1e6a8c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e6a90: 0xafc2003c  sw          $v0, 0x3C($fp)
    ctx->pc = 0x1e6a90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 2));
    // 0x1e6a94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6a98: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e6a98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e6a9c: 0x10620026  beq         $v1, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x1E6A9Cu;
    {
        const bool branch_taken_0x1e6a9c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6a9c) {
            ctx->pc = 0x1E6B38u;
            goto label_1e6b38;
        }
    }
    ctx->pc = 0x1E6AA4u;
    // 0x1e6aa4: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e6aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e6aa8: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x1e6aa8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e6aac: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6AACu;
    {
        const bool branch_taken_0x1e6aac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6aac) {
            ctx->pc = 0x1E6AC8u;
            goto label_1e6ac8;
        }
    }
    ctx->pc = 0x1E6AB4u;
    // 0x1e6ab4: 0x8fc2003c  lw          $v0, 0x3C($fp)
    ctx->pc = 0x1e6ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e6ab8: 0x10400050  beqz        $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x1E6AB8u;
    {
        const bool branch_taken_0x1e6ab8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ab8) {
            ctx->pc = 0x1E6BFCu;
            goto label_1e6bfc;
        }
    }
    ctx->pc = 0x1E6AC0u;
    // 0x1e6ac0: 0x1000004e  b           . + 4 + (0x4E << 2)
    ctx->pc = 0x1E6AC0u;
    {
        const bool branch_taken_0x1e6ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ac0) {
            ctx->pc = 0x1E6BFCu;
            goto label_1e6bfc;
        }
    }
    ctx->pc = 0x1E6AC8u;
label_1e6ac8:
    // 0x1e6ac8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e6ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e6acc: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e6accu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e6ad0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6AD0u;
    {
        const bool branch_taken_0x1e6ad0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6ad0) {
            ctx->pc = 0x1E6AE0u;
            goto label_1e6ae0;
        }
    }
    ctx->pc = 0x1E6AD8u;
    // 0x1e6ad8: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E6AD8u;
    {
        const bool branch_taken_0x1e6ad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ad8) {
            ctx->pc = 0x1E6BFCu;
            goto label_1e6bfc;
        }
    }
    ctx->pc = 0x1E6AE0u;
label_1e6ae0:
    // 0x1e6ae0: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6ae0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6ae4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e6ae4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6ae8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e6ae8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e6aec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1E6AECu;
    SET_GPR_U32(ctx, 31, 0x1E6AF4u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6AF4u; }
        if (ctx->pc != 0x1E6AF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6AF4u; }
        if (ctx->pc != 0x1E6AF4u) { return; }
    }
    ctx->pc = 0x1E6AF4u;
label_1e6af4:
    // 0x1e6af4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6af4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6af8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6af8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6afc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6afcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6b00: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6b00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6b04: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6b04u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6b08: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6b08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6b0c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6b10: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6b10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6b14: 0x8c450008  lw          $a1, 0x8($v0)
    ctx->pc = 0x1e6b14u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e6b18: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e6b18u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e6b1c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E6B1Cu;
    SET_GPR_U32(ctx, 31, 0x1E6B24u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B24u; }
        if (ctx->pc != 0x1E6B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B24u; }
        if (ctx->pc != 0x1E6B24u) { return; }
    }
    ctx->pc = 0x1E6B24u;
label_1e6b24:
    // 0x1e6b24: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6b24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6b28: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e6b28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e6b2c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6b2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6b30: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x1E6B30u;
    {
        const bool branch_taken_0x1e6b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6b30) {
            ctx->pc = 0x1E6C58u;
            goto label_1e6c58;
        }
    }
    ctx->pc = 0x1E6B38u;
label_1e6b38:
    // 0x1e6b38: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6b38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6b3c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6b3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6b40: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6b40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6b44: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6b44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6b48: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6b48u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6b4c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6b50: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6b54: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e6b54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e6b58: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6b58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6b5c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6b60: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e6b60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e6b64: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6B64u;
    SET_GPR_U32(ctx, 31, 0x1E6B6Cu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B6Cu; }
        if (ctx->pc != 0x1E6B6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B6Cu; }
        if (ctx->pc != 0x1E6B6Cu) { return; }
    }
    ctx->pc = 0x1E6B6Cu;
label_1e6b6c:
    // 0x1e6b6c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6b6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6b70: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e6b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e6b74: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6b74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6b78: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6b78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6b7c: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6b7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6b80: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6B80u;
    SET_GPR_U32(ctx, 31, 0x1E6B88u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B88u; }
        if (ctx->pc != 0x1E6B88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B88u; }
        if (ctx->pc != 0x1E6B88u) { return; }
    }
    ctx->pc = 0x1E6B88u;
label_1e6b88:
    // 0x1e6b88: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6b8c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6b90: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6b90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6b94: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6b94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6b98: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6b98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6b9c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6ba0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6ba4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6ba8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6bac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6bacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6bb0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e6bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e6bb4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6bb8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6bbc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6bbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6bc0: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e6bc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e6bc4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6BC4u;
    SET_GPR_U32(ctx, 31, 0x1E6BCCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6BCCu; }
        if (ctx->pc != 0x1E6BCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6BCCu; }
        if (ctx->pc != 0x1E6BCCu) { return; }
    }
    ctx->pc = 0x1E6BCCu;
label_1e6bcc:
    // 0x1e6bcc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6bccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6bd0: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e6bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e6bd4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6bd8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6bd8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6bdc: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6bdcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6be0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6BE0u;
    SET_GPR_U32(ctx, 31, 0x1E6BE8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6BE8u; }
        if (ctx->pc != 0x1E6BE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6BE8u; }
        if (ctx->pc != 0x1E6BE8u) { return; }
    }
    ctx->pc = 0x1E6BE8u;
label_1e6be8:
    // 0x1e6be8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6be8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6bec: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6becu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6bf0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6bf4: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1E6BF4u;
    {
        const bool branch_taken_0x1e6bf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6bf4) {
            ctx->pc = 0x1E6C58u;
            goto label_1e6c58;
        }
    }
    ctx->pc = 0x1E6BFCu;
label_1e6bfc:
    // 0x1e6bfc: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6c00: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6c00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6c04: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6c04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6c08: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6c08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6c0c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6c10: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6c14: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6c14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6c18: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e6c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e6c1c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6c20: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6c20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6c24: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e6c24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e6c28: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6C28u;
    SET_GPR_U32(ctx, 31, 0x1E6C30u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C30u; }
        if (ctx->pc != 0x1E6C30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C30u; }
        if (ctx->pc != 0x1E6C30u) { return; }
    }
    ctx->pc = 0x1E6C30u;
label_1e6c30:
    // 0x1e6c30: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6c30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6c34: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e6c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e6c38: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6c38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6c3c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6c3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6c40: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6c40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6c44: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6C44u;
    SET_GPR_U32(ctx, 31, 0x1E6C4Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C4Cu; }
        if (ctx->pc != 0x1E6C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C4Cu; }
        if (ctx->pc != 0x1E6C4Cu) { return; }
    }
    ctx->pc = 0x1E6C4Cu;
label_1e6c4c:
    // 0x1e6c4c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6c50: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6c50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6c54: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6c54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
label_1e6c58:
    // 0x1e6c58: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e6c58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6c5c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e6c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e6c60: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1e6c60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1e6c64: 0x1000ff15  b           . + 4 + (-0xEB << 2)
    ctx->pc = 0x1E6C64u;
    {
        const bool branch_taken_0x1e6c64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6c64) {
            ctx->pc = 0x1E68BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e68bc;
        }
    }
    ctx->pc = 0x1E6C6Cu;
label_1e6c6c:
    // 0x1e6c6c: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e6c6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6c70: 0x93c20030  lbu         $v0, 0x30($fp)
    ctx->pc = 0x1e6c70u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6c74: 0xa0620004  sb          $v0, 0x4($v1)
    ctx->pc = 0x1e6c74u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e6c78: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e6c78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6c7c: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1E6C7Cu;
    SET_GPR_U32(ctx, 31, 0x1E6C84u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C84u; }
        if (ctx->pc != 0x1E6C84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C84u; }
        if (ctx->pc != 0x1E6C84u) { return; }
    }
    ctx->pc = 0x1E6C84u;
label_1e6c84:
    // 0x1e6c84: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e6c84u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6c88: 0x3402fff0  ori         $v0, $zero, 0xFFF0
    ctx->pc = 0x1e6c88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65520);
    // 0x1e6c8c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6c90: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e6c90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e6c94: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e6c94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6c98: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6c98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6c9c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e6c9cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e6ca0: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e6ca0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6ca4: 0x24080048  addiu       $t0, $zero, 0x48
    ctx->pc = 0x1e6ca4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x1e6ca8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e6ca8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6cac: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E6CACu;
    SET_GPR_U32(ctx, 31, 0x1E6CB4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6CB4u; }
        if (ctx->pc != 0x1E6CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6CB4u; }
        if (ctx->pc != 0x1E6CB4u) { return; }
    }
    ctx->pc = 0x1E6CB4u;
label_1e6cb4:
    // 0x1e6cb4: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e6cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e6cb8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e6cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6cbc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6CBCu;
    {
        const bool branch_taken_0x1e6cbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6cbc) {
            ctx->pc = 0x1E6CD8u;
            goto label_1e6cd8;
        }
    }
    ctx->pc = 0x1E6CC4u;
    // 0x1e6cc4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6cc8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6ccc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6cd0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E6CD0u;
    {
        const bool branch_taken_0x1e6cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6cd0) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E6CD8u;
label_1e6cd8:
    // 0x1e6cd8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e6cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6cdc: 0x24050031  addiu       $a1, $zero, 0x31
    ctx->pc = 0x1e6cdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x1e6ce0: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e6ce0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6ce4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E6CE4u;
    SET_GPR_U32(ctx, 31, 0x1E6CECu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6CECu; }
        if (ctx->pc != 0x1E6CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6CECu; }
        if (ctx->pc != 0x1E6CECu) { return; }
    }
    ctx->pc = 0x1E6CECu;
label_1e6cec:
    // 0x1e6cec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e6cecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6cf0:
    // 0x1e6cf0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6cf0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6cf4: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1e6cf4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1e6cf8: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1e6cf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1e6cfc: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1e6cfcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1e6d00: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6D00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E6D08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
