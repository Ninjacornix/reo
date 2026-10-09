#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E282C
// Address: 0x1e282c - 0x1e2a24
void sub_001E282C_0x1e282c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E282C_0x1e282c");
#endif

    switch (ctx->pc) {
        case 0x1e28e0u: goto label_1e28e0;
        case 0x1e2914u: goto label_1e2914;
        case 0x1e2938u: goto label_1e2938;
        case 0x1e29c0u: goto label_1e29c0;
        case 0x1e29f0u: goto label_1e29f0;
        default: break;
    }

    ctx->pc = 0x1e282cu;

    // 0x1e282c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e282cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2830: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e2834: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e2834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e2838: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2838u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e283c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e283cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2840: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2840u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2844: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2844u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2848: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e2848u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e284c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e284cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2850: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2854: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2854u;
    {
        const bool branch_taken_0x1e2854 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2854) {
            ctx->pc = 0x1E287Cu;
            goto label_1e287c;
        }
    }
    ctx->pc = 0x1E285Cu;
    // 0x1e285c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e285cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2860: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2860u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2864: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2864u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2868: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2868u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e286c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e286cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2870: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2870u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2874: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2874u;
    {
        const bool branch_taken_0x1e2874 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2874) {
            ctx->pc = 0x1E2890u;
            goto label_1e2890;
        }
    }
    ctx->pc = 0x1E287Cu;
label_1e287c:
    // 0x1e287c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e287cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2880: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2880u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2884: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2888: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1E2888u;
    {
        const bool branch_taken_0x1e2888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2888) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E2890u;
label_1e2890:
    // 0x1e2890: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2894: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2894u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2898: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2898u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e289c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e289cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e28a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e28a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e28a4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e28a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e28a8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e28a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e28ac: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e28acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e28b0: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e28b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e28b4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E28B4u;
    {
        const bool branch_taken_0x1e28b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e28b4) {
            ctx->pc = 0x1E28D0u;
            goto label_1e28d0;
        }
    }
    ctx->pc = 0x1E28BCu;
    // 0x1e28bc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e28bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e28c0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e28c0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e28c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e28c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e28c8: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1E28C8u;
    {
        const bool branch_taken_0x1e28c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e28c8) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E28D0u;
label_1e28d0:
    // 0x1e28d0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e28d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e28d4: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e28d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e28d8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E28D8u;
    SET_GPR_U32(ctx, 31, 0x1E28E0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E28E0u; }
        if (ctx->pc != 0x1E28E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E28E0u; }
        if (ctx->pc != 0x1E28E0u) { return; }
    }
    ctx->pc = 0x1E28E0u;
label_1e28e0:
    // 0x1e28e0: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e28e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e28e4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e28e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e28e8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E28E8u;
    {
        const bool branch_taken_0x1e28e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e28e8) {
            ctx->pc = 0x1E2904u;
            goto label_1e2904;
        }
    }
    ctx->pc = 0x1E28F0u;
    // 0x1e28f0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e28f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e28f4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e28f4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e28f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e28f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e28fc: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E28FCu;
    {
        const bool branch_taken_0x1e28fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e28fc) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E2904u;
label_1e2904:
    // 0x1e2904: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e2904u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2908: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e2908u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e290c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E290Cu;
    SET_GPR_U32(ctx, 31, 0x1E2914u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2914u; }
        if (ctx->pc != 0x1E2914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2914u; }
        if (ctx->pc != 0x1E2914u) { return; }
    }
    ctx->pc = 0x1E2914u;
label_1e2914:
    // 0x1e2914: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e2914u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e2918: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e291c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E291Cu;
    {
        const bool branch_taken_0x1e291c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e291c) {
            ctx->pc = 0x1E294Cu;
            goto label_1e294c;
        }
    }
    ctx->pc = 0x1E2924u;
    // 0x1e2924: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2924u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2928: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e2928u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e292c: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e292cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2930: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2930u;
    SET_GPR_U32(ctx, 31, 0x1E2938u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2938u; }
        if (ctx->pc != 0x1E2938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2938u; }
        if (ctx->pc != 0x1E2938u) { return; }
    }
    ctx->pc = 0x1E2938u;
label_1e2938:
    // 0x1e2938: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e293c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e293cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2940: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2944: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E2944u;
    {
        const bool branch_taken_0x1e2944 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2944) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E294Cu;
label_1e294c:
    // 0x1e294c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e294cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2950: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2954: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2954u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2958: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2958u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e295c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e295cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2960: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2960u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2964: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2964u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2968: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2968u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e296c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e296cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2970: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2970u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2974: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2974u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2978: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e2978u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e297c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e297cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2980: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2980u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2984: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2984u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2988: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2988u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e298c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e298cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2990: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2990u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2994: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e2994u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e2998: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e299c: 0x90420618  lbu         $v0, 0x618($v0)
    ctx->pc = 0x1e299cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1560)));
    // 0x1e29a0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e29a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e29a4: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e29a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e29a8: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e29a8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e29ac: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e29acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e29b0: 0x24080006  addiu       $t0, $zero, 0x6
    ctx->pc = 0x1e29b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1e29b4: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e29b4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e29b8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E29B8u;
    SET_GPR_U32(ctx, 31, 0x1E29C0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E29C0u; }
        if (ctx->pc != 0x1E29C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E29C0u; }
        if (ctx->pc != 0x1E29C0u) { return; }
    }
    ctx->pc = 0x1E29C0u;
label_1e29c0:
    // 0x1e29c0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E29C0u;
    {
        const bool branch_taken_0x1e29c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e29c0) {
            ctx->pc = 0x1E29DCu;
            goto label_1e29dc;
        }
    }
    ctx->pc = 0x1E29C8u;
    // 0x1e29c8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e29c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e29cc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e29ccu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e29d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e29d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e29d4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E29D4u;
    {
        const bool branch_taken_0x1e29d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e29d4) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E29DCu;
label_1e29dc:
    // 0x1e29dc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e29dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e29e0: 0x24050021  addiu       $a1, $zero, 0x21
    ctx->pc = 0x1e29e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x1e29e4: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e29e4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e29e8: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E29E8u;
    SET_GPR_U32(ctx, 31, 0x1E29F0u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E29F0u; }
        if (ctx->pc != 0x1E29F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E29F0u; }
        if (ctx->pc != 0x1E29F0u) { return; }
    }
    ctx->pc = 0x1E29F0u;
label_1e29f0:
    // 0x1e29f0: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e29f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e29f4: 0x90640618  lbu         $a0, 0x618($v1)
    ctx->pc = 0x1e29f4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1560)));
    // 0x1e29f8: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e29f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e29fc: 0xa0620618  sb          $v0, 0x618($v1)
    ctx->pc = 0x1e29fcu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1560), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2a00: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2a00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2a04: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2a04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e2a08: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2a08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e2a0c:
    // 0x1e2a0c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2a0cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2a10: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2a10u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e2a14: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e2a14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e2a18: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e2a18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e2a1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2A1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2A24u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
