#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F0718
// Address: 0x1f0718 - 0x1f09f0
void sub_001F0718_0x1f0718(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F0718_0x1f0718");
#endif

    switch (ctx->pc) {
        case 0x1f074cu: goto label_1f074c;
        case 0x1f0760u: goto label_1f0760;
        case 0x1f0778u: goto label_1f0778;
        case 0x1f0790u: goto label_1f0790;
        case 0x1f07a8u: goto label_1f07a8;
        case 0x1f07c0u: goto label_1f07c0;
        case 0x1f07e0u: goto label_1f07e0;
        case 0x1f081cu: goto label_1f081c;
        case 0x1f082cu: goto label_1f082c;
        case 0x1f084cu: goto label_1f084c;
        case 0x1f0858u: goto label_1f0858;
        case 0x1f0868u: goto label_1f0868;
        case 0x1f08bcu: goto label_1f08bc;
        case 0x1f0918u: goto label_1f0918;
        case 0x1f0924u: goto label_1f0924;
        case 0x1f0950u: goto label_1f0950;
        case 0x1f0984u: goto label_1f0984;
        default: break;
    }

    ctx->pc = 0x1f0718u;

    // 0x1f0718: 0x27bdfe20  addiu       $sp, $sp, -0x1E0
    ctx->pc = 0x1f0718u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966816));
    // 0x1f071c: 0xffbe01d0  sd          $fp, 0x1D0($sp)
    ctx->pc = 0x1f071cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 464), GPR_U64(ctx, 30));
    // 0x1f0720: 0xffbf01d8  sd          $ra, 0x1D8($sp)
    ctx->pc = 0x1f0720u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 472), GPR_U64(ctx, 31));
    // 0x1f0724: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0724u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0728: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0728u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f072c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f072cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f0730: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f0730u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f0734: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1f0734u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1f0738: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1f0738u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1f073c: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1f073cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1f0740: 0x24041048  addiu       $a0, $zero, 0x1048
    ctx->pc = 0x1f0740u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4168));
    // 0x1f0744: 0xc041bb8  jal         func_106EE0
    ctx->pc = 0x1F0744u;
    SET_GPR_U32(ctx, 31, 0x1F074Cu);
    ctx->pc = 0x106EE0u;
    if (runtime->hasFunction(0x106EE0u)) {
        auto targetFn = runtime->lookupFunction(0x106EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F074Cu; }
        if (ctx->pc != 0x1F074Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106EE0_0x106ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F074Cu; }
        if (ctx->pc != 0x1F074Cu) { return; }
    }
    ctx->pc = 0x1F074Cu;
label_1f074c:
    // 0x1f074c: 0xafc201bc  sw          $v0, 0x1BC($fp)
    ctx->pc = 0x1f074cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 444), GPR_U32(ctx, 2));
    // 0x1f0750: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1f0750u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1f0754: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0754u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0758: 0xc07ada1  jal         func_1EB684
    ctx->pc = 0x1F0758u;
    SET_GPR_U32(ctx, 31, 0x1F0760u);
    ctx->pc = 0x1EB684u;
    if (runtime->hasFunction(0x1EB684u)) {
        auto targetFn = runtime->lookupFunction(0x1EB684u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0760u; }
        if (ctx->pc != 0x1F0760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB684_0x1eb684(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0760u; }
        if (ctx->pc != 0x1F0760u) { return; }
    }
    ctx->pc = 0x1F0760u;
label_1f0760:
    // 0x1f0760: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1f0760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1f0764: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0764u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0768: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1f0768u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f076c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1f076cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0770: 0xc07c16d  jal         func_1F05B4
    ctx->pc = 0x1F0770u;
    SET_GPR_U32(ctx, 31, 0x1F0778u);
    ctx->pc = 0x1F05B4u;
    if (runtime->hasFunction(0x1F05B4u)) {
        auto targetFn = runtime->lookupFunction(0x1F05B4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0778u; }
        if (ctx->pc != 0x1F0778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F05B4_0x1f05b4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0778u; }
        if (ctx->pc != 0x1F0778u) { return; }
    }
    ctx->pc = 0x1F0778u;
label_1f0778:
    // 0x1f0778: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1f0778u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1f077c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f077cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0780: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1f0780u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f0784: 0x8fc60014  lw          $a2, 0x14($fp)
    ctx->pc = 0x1f0784u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0788: 0xc07c16d  jal         func_1F05B4
    ctx->pc = 0x1F0788u;
    SET_GPR_U32(ctx, 31, 0x1F0790u);
    ctx->pc = 0x1F05B4u;
    if (runtime->hasFunction(0x1F05B4u)) {
        auto targetFn = runtime->lookupFunction(0x1F05B4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0790u; }
        if (ctx->pc != 0x1F0790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F05B4_0x1f05b4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0790u; }
        if (ctx->pc != 0x1F0790u) { return; }
    }
    ctx->pc = 0x1F0790u;
label_1f0790:
    // 0x1f0790: 0x27c20190  addiu       $v0, $fp, 0x190
    ctx->pc = 0x1f0790u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 400));
    // 0x1f0794: 0x27c30020  addiu       $v1, $fp, 0x20
    ctx->pc = 0x1f0794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1f0798: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0798u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f079c: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1f079cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f07a0: 0xc07c18d  jal         func_1F0634
    ctx->pc = 0x1F07A0u;
    SET_GPR_U32(ctx, 31, 0x1F07A8u);
    ctx->pc = 0x1F0634u;
    if (runtime->hasFunction(0x1F0634u)) {
        auto targetFn = runtime->lookupFunction(0x1F0634u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F07A8u; }
        if (ctx->pc != 0x1F07A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0634_0x1f0634(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F07A8u; }
        if (ctx->pc != 0x1F07A8u) { return; }
    }
    ctx->pc = 0x1F07A8u;
label_1f07a8:
    // 0x1f07a8: 0x27c20190  addiu       $v0, $fp, 0x190
    ctx->pc = 0x1f07a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 400));
    // 0x1f07ac: 0x8fc401bc  lw          $a0, 0x1BC($fp)
    ctx->pc = 0x1f07acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 444)));
    // 0x1f07b0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f07b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f07b4: 0x24060014  addiu       $a2, $zero, 0x14
    ctx->pc = 0x1f07b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1f07b8: 0xc07ac19  jal         func_1EB064
    ctx->pc = 0x1F07B8u;
    SET_GPR_U32(ctx, 31, 0x1F07C0u);
    ctx->pc = 0x1EB064u;
    if (runtime->hasFunction(0x1EB064u)) {
        auto targetFn = runtime->lookupFunction(0x1EB064u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F07C0u; }
        if (ctx->pc != 0x1F07C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB064_0x1eb064(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F07C0u; }
        if (ctx->pc != 0x1F07C0u) { return; }
    }
    ctx->pc = 0x1F07C0u;
label_1f07c0:
    // 0x1f07c0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f07c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f07c4: 0x24420007  addiu       $v0, $v0, 0x7
    ctx->pc = 0x1f07c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7));
    // 0x1f07c8: 0x210c2  srl         $v0, $v0, 3
    ctx->pc = 0x1f07c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 3));
    // 0x1f07cc: 0xafc201b4  sw          $v0, 0x1B4($fp)
    ctx->pc = 0x1f07ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 436), GPR_U32(ctx, 2));
    // 0x1f07d0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f07d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f07d4: 0xafc201b0  sw          $v0, 0x1B0($fp)
    ctx->pc = 0x1f07d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 432), GPR_U32(ctx, 2));
    // 0x1f07d8: 0x8fc201b4  lw          $v0, 0x1B4($fp)
    ctx->pc = 0x1f07d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 436)));
    // 0x1f07dc: 0xafc201b8  sw          $v0, 0x1B8($fp)
    ctx->pc = 0x1f07dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 440), GPR_U32(ctx, 2));
label_1f07e0:
    // 0x1f07e0: 0x8fc201b8  lw          $v0, 0x1B8($fp)
    ctx->pc = 0x1f07e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 440)));
    // 0x1f07e4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F07E4u;
    {
        const bool branch_taken_0x1f07e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f07e4) {
            ctx->pc = 0x1F07F4u;
            goto label_1f07f4;
        }
    }
    ctx->pc = 0x1F07ECu;
    // 0x1f07ec: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1F07ECu;
    {
        const bool branch_taken_0x1f07ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f07ec) {
            ctx->pc = 0x1F08B0u;
            goto label_1f08b0;
        }
    }
    ctx->pc = 0x1F07F4u;
label_1f07f4:
    // 0x1f07f4: 0x8fc201b0  lw          $v0, 0x1B0($fp)
    ctx->pc = 0x1f07f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 432)));
    // 0x1f07f8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f07f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f07fc: 0xafc201c0  sw          $v0, 0x1C0($fp)
    ctx->pc = 0x1f07fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 448), GPR_U32(ctx, 2));
    // 0x1f0800: 0x8fc201b0  lw          $v0, 0x1B0($fp)
    ctx->pc = 0x1f0800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 432)));
    // 0x1f0804: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0804u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0808: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f0808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f080c: 0xafc201c4  sw          $v0, 0x1C4($fp)
    ctx->pc = 0x1f080cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 452), GPR_U32(ctx, 2));
    // 0x1f0810: 0x8fc401c0  lw          $a0, 0x1C0($fp)
    ctx->pc = 0x1f0810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 448)));
    // 0x1f0814: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1F0814u;
    SET_GPR_U32(ctx, 31, 0x1F081Cu);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F081Cu; }
        if (ctx->pc != 0x1F081Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F081Cu; }
        if (ctx->pc != 0x1F081Cu) { return; }
    }
    ctx->pc = 0x1F081Cu;
label_1f081c:
    // 0x1f081c: 0xafc201c0  sw          $v0, 0x1C0($fp)
    ctx->pc = 0x1f081cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 448), GPR_U32(ctx, 2));
    // 0x1f0820: 0x8fc401c4  lw          $a0, 0x1C4($fp)
    ctx->pc = 0x1f0820u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 452)));
    // 0x1f0824: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1F0824u;
    SET_GPR_U32(ctx, 31, 0x1F082Cu);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F082Cu; }
        if (ctx->pc != 0x1F082Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F082Cu; }
        if (ctx->pc != 0x1F082Cu) { return; }
    }
    ctx->pc = 0x1F082Cu;
label_1f082c:
    // 0x1f082c: 0xafc201c4  sw          $v0, 0x1C4($fp)
    ctx->pc = 0x1f082cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 452), GPR_U32(ctx, 2));
    // 0x1f0830: 0x27c201c0  addiu       $v0, $fp, 0x1C0
    ctx->pc = 0x1f0830u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 448));
    // 0x1f0834: 0x27c301c4  addiu       $v1, $fp, 0x1C4
    ctx->pc = 0x1f0834u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 452));
    // 0x1f0838: 0x8fc401bc  lw          $a0, 0x1BC($fp)
    ctx->pc = 0x1f0838u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 444)));
    // 0x1f083c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f083cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0840: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1f0840u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0844: 0xc07abcd  jal         func_1EAF34
    ctx->pc = 0x1F0844u;
    SET_GPR_U32(ctx, 31, 0x1F084Cu);
    ctx->pc = 0x1EAF34u;
    if (runtime->hasFunction(0x1EAF34u)) {
        auto targetFn = runtime->lookupFunction(0x1EAF34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F084Cu; }
        if (ctx->pc != 0x1F084Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAF34_0x1eaf34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F084Cu; }
        if (ctx->pc != 0x1F084Cu) { return; }
    }
    ctx->pc = 0x1F084Cu;
label_1f084c:
    // 0x1f084c: 0x8fc401c0  lw          $a0, 0x1C0($fp)
    ctx->pc = 0x1f084cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 448)));
    // 0x1f0850: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1F0850u;
    SET_GPR_U32(ctx, 31, 0x1F0858u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0858u; }
        if (ctx->pc != 0x1F0858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0858u; }
        if (ctx->pc != 0x1F0858u) { return; }
    }
    ctx->pc = 0x1F0858u;
label_1f0858:
    // 0x1f0858: 0xafc201c0  sw          $v0, 0x1C0($fp)
    ctx->pc = 0x1f0858u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 448), GPR_U32(ctx, 2));
    // 0x1f085c: 0x8fc401c4  lw          $a0, 0x1C4($fp)
    ctx->pc = 0x1f085cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 452)));
    // 0x1f0860: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1F0860u;
    SET_GPR_U32(ctx, 31, 0x1F0868u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0868u; }
        if (ctx->pc != 0x1F0868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0868u; }
        if (ctx->pc != 0x1F0868u) { return; }
    }
    ctx->pc = 0x1F0868u;
label_1f0868:
    // 0x1f0868: 0xafc201c4  sw          $v0, 0x1C4($fp)
    ctx->pc = 0x1f0868u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 452), GPR_U32(ctx, 2));
    // 0x1f086c: 0x27c401b0  addiu       $a0, $fp, 0x1B0
    ctx->pc = 0x1f086cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 432));
    // 0x1f0870: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0870u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0874: 0x8fc301c0  lw          $v1, 0x1C0($fp)
    ctx->pc = 0x1f0874u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 448)));
    // 0x1f0878: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1f0878u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1f087c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f087cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0880: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x1f0880u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x1f0884: 0x27c401b0  addiu       $a0, $fp, 0x1B0
    ctx->pc = 0x1f0884u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 432));
    // 0x1f0888: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f088c: 0x8fc301c4  lw          $v1, 0x1C4($fp)
    ctx->pc = 0x1f088cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 452)));
    // 0x1f0890: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1f0890u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1f0894: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0898: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x1f0898u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x1f089c: 0x8fc201b8  lw          $v0, 0x1B8($fp)
    ctx->pc = 0x1f089cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 440)));
    // 0x1f08a0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f08a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f08a4: 0xafc201b8  sw          $v0, 0x1B8($fp)
    ctx->pc = 0x1f08a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 440), GPR_U32(ctx, 2));
    // 0x1f08a8: 0x1000ffcd  b           . + 4 + (-0x33 << 2)
    ctx->pc = 0x1F08A8u;
    {
        const bool branch_taken_0x1f08a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f08a8) {
            ctx->pc = 0x1F07E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f07e0;
        }
    }
    ctx->pc = 0x1F08B0u;
label_1f08b0:
    // 0x1f08b0: 0x8fc401bc  lw          $a0, 0x1BC($fp)
    ctx->pc = 0x1f08b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 444)));
    // 0x1f08b4: 0xc041bce  jal         func_106F38
    ctx->pc = 0x1F08B4u;
    SET_GPR_U32(ctx, 31, 0x1F08BCu);
    ctx->pc = 0x106F38u;
    if (runtime->hasFunction(0x106F38u)) {
        auto targetFn = runtime->lookupFunction(0x106F38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F08BCu; }
        if (ctx->pc != 0x1F08BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106F38_0x106f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F08BCu; }
        if (ctx->pc != 0x1F08BCu) { return; }
    }
    ctx->pc = 0x1F08BCu;
label_1f08bc:
    // 0x1f08bc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f08bcu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f08c0: 0xdfbe01d0  ld          $fp, 0x1D0($sp)
    ctx->pc = 0x1f08c0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 464)));
    // 0x1f08c4: 0xdfbf01d8  ld          $ra, 0x1D8($sp)
    ctx->pc = 0x1f08c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 472)));
    // 0x1f08c8: 0x27bd01e0  addiu       $sp, $sp, 0x1E0
    ctx->pc = 0x1f08c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 480));
    // 0x1f08cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1F08CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F074Cu: goto label_1f074c;
            case 0x1F0760u: goto label_1f0760;
            case 0x1F0778u: goto label_1f0778;
            case 0x1F0790u: goto label_1f0790;
            case 0x1F07A8u: goto label_1f07a8;
            case 0x1F07C0u: goto label_1f07c0;
            case 0x1F07E0u: goto label_1f07e0;
            case 0x1F07F4u: goto label_1f07f4;
            case 0x1F081Cu: goto label_1f081c;
            case 0x1F082Cu: goto label_1f082c;
            case 0x1F084Cu: goto label_1f084c;
            case 0x1F0858u: goto label_1f0858;
            case 0x1F0868u: goto label_1f0868;
            case 0x1F08B0u: goto label_1f08b0;
            case 0x1F08BCu: goto label_1f08bc;
            case 0x1F0918u: goto label_1f0918;
            case 0x1F0924u: goto label_1f0924;
            case 0x1F0938u: goto label_1f0938;
            case 0x1F0950u: goto label_1f0950;
            case 0x1F0984u: goto label_1f0984;
            case 0x1F098Cu: goto label_1f098c;
            case 0x1F09ACu: goto label_1f09ac;
            case 0x1F09D4u: goto label_1f09d4;
            case 0x1F09D8u: goto label_1f09d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F08D4u;
    // 0x1f08d4: 0x0  nop
    ctx->pc = 0x1f08d4u;
    // NOP
    // 0x1f08d8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f08d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f08dc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f08dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f08e0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f08e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f08e4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f08e4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f08e8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f08e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f08ec: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f08ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f08f0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f08f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f08f4: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1f08f4u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f08f8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f08f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f08fc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f08fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f0900: 0x27c2000c  addiu       $v0, $fp, 0xC
    ctx->pc = 0x1f0900u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f0904: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0904u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0908: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f0908u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f090c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f090cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0910: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0910u;
    SET_GPR_U32(ctx, 31, 0x1F0918u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0918u; }
        if (ctx->pc != 0x1F0918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0918u; }
        if (ctx->pc != 0x1F0918u) { return; }
    }
    ctx->pc = 0x1F0918u;
label_1f0918:
    // 0x1f0918: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f091c: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f091cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0920: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0920u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1f0924:
    // 0x1f0924: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1f0924u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0928: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F0928u;
    {
        const bool branch_taken_0x1f0928 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1f0928) {
            ctx->pc = 0x1F0938u;
            goto label_1f0938;
        }
    }
    ctx->pc = 0x1F0930u;
    // 0x1f0930: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1F0930u;
    {
        const bool branch_taken_0x1f0930 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0930) {
            ctx->pc = 0x1F09ACu;
            goto label_1f09ac;
        }
    }
    ctx->pc = 0x1F0938u;
label_1f0938:
    // 0x1f0938: 0x27c2000e  addiu       $v0, $fp, 0xE
    ctx->pc = 0x1f0938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 14));
    // 0x1f093c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f093cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0940: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f0940u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0944: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0944u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0948: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0948u;
    SET_GPR_U32(ctx, 31, 0x1F0950u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0950u; }
        if (ctx->pc != 0x1F0950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0950u; }
        if (ctx->pc != 0x1F0950u) { return; }
    }
    ctx->pc = 0x1F0950u;
label_1f0950:
    // 0x1f0950: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0954: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0954u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0958: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0958u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f095c: 0x87c3000e  lh          $v1, 0xE($fp)
    ctx->pc = 0x1f095cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1f0960: 0x87c20004  lh          $v0, 0x4($fp)
    ctx->pc = 0x1f0960u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0964: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1F0964u;
    {
        const bool branch_taken_0x1f0964 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f0964) {
            ctx->pc = 0x1F098Cu;
            goto label_1f098c;
        }
    }
    ctx->pc = 0x1F096Cu;
    // 0x1f096c: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1f096cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1f0970: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0970u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0974: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f0974u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0978: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f0978u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f097c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F097Cu;
    SET_GPR_U32(ctx, 31, 0x1F0984u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0984u; }
        if (ctx->pc != 0x1F0984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0984u; }
        if (ctx->pc != 0x1F0984u) { return; }
    }
    ctx->pc = 0x1F0984u;
label_1f0984:
    // 0x1f0984: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F0984u;
    {
        const bool branch_taken_0x1f0984 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0984) {
            ctx->pc = 0x1F09ACu;
            goto label_1f09ac;
        }
    }
    ctx->pc = 0x1F098Cu;
label_1f098c:
    // 0x1f098c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f098cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0990: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0990u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0994: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f0994u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f0998: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1f0998u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f099c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f099cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f09a0: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1f09a0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f09a4: 0x1000ffdf  b           . + 4 + (-0x21 << 2)
    ctx->pc = 0x1F09A4u;
    {
        const bool branch_taken_0x1f09a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f09a4) {
            ctx->pc = 0x1F0924u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f0924;
        }
    }
    ctx->pc = 0x1F09ACu;
label_1f09ac:
    // 0x1f09ac: 0x87c3000e  lh          $v1, 0xE($fp)
    ctx->pc = 0x1f09acu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1f09b0: 0x87c20004  lh          $v0, 0x4($fp)
    ctx->pc = 0x1f09b0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f09b4: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F09B4u;
    {
        const bool branch_taken_0x1f09b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f09b4) {
            ctx->pc = 0x1F09D4u;
            goto label_1f09d4;
        }
    }
    ctx->pc = 0x1F09BCu;
    // 0x1f09bc: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f09bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f09c0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f09c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f09c4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f09c4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f09c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f09c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f09cc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F09CCu;
    {
        const bool branch_taken_0x1f09cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f09cc) {
            ctx->pc = 0x1F09D8u;
            goto label_1f09d8;
        }
    }
    ctx->pc = 0x1F09D4u;
label_1f09d4:
    // 0x1f09d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1f09d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1f09d8:
    // 0x1f09d8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f09d8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f09dc: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f09dcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f09e0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f09e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f09e4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f09e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f09e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F09E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F074Cu: goto label_1f074c;
            case 0x1F0760u: goto label_1f0760;
            case 0x1F0778u: goto label_1f0778;
            case 0x1F0790u: goto label_1f0790;
            case 0x1F07A8u: goto label_1f07a8;
            case 0x1F07C0u: goto label_1f07c0;
            case 0x1F07E0u: goto label_1f07e0;
            case 0x1F07F4u: goto label_1f07f4;
            case 0x1F081Cu: goto label_1f081c;
            case 0x1F082Cu: goto label_1f082c;
            case 0x1F084Cu: goto label_1f084c;
            case 0x1F0858u: goto label_1f0858;
            case 0x1F0868u: goto label_1f0868;
            case 0x1F08B0u: goto label_1f08b0;
            case 0x1F08BCu: goto label_1f08bc;
            case 0x1F0918u: goto label_1f0918;
            case 0x1F0924u: goto label_1f0924;
            case 0x1F0938u: goto label_1f0938;
            case 0x1F0950u: goto label_1f0950;
            case 0x1F0984u: goto label_1f0984;
            case 0x1F098Cu: goto label_1f098c;
            case 0x1F09ACu: goto label_1f09ac;
            case 0x1F09D4u: goto label_1f09d4;
            case 0x1F09D8u: goto label_1f09d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F09F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
