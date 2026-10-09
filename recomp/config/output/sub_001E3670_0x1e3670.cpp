#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E3670
// Address: 0x1e3670 - 0x1e38b8
void sub_001E3670_0x1e3670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E3670_0x1e3670");
#endif

    switch (ctx->pc) {
        case 0x1e3728u: goto label_1e3728;
        case 0x1e375cu: goto label_1e375c;
        case 0x1e3780u: goto label_1e3780;
        case 0x1e3854u: goto label_1e3854;
        case 0x1e3884u: goto label_1e3884;
        default: break;
    }

    ctx->pc = 0x1e3670u;

    // 0x1e3670: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3674: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3678: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e367c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e367cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3680: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3680u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3684: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3684u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3688: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3688u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e368c: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e368cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e3690: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e3690u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e3694: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3698: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e369c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E369Cu;
    {
        const bool branch_taken_0x1e369c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e369c) {
            ctx->pc = 0x1E36C4u;
            goto label_1e36c4;
        }
    }
    ctx->pc = 0x1E36A4u;
    // 0x1e36a4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e36a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e36a8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e36a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e36ac: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e36acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e36b0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e36b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e36b4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e36b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e36b8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e36b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e36bc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E36BCu;
    {
        const bool branch_taken_0x1e36bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e36bc) {
            ctx->pc = 0x1E36D8u;
            goto label_1e36d8;
        }
    }
    ctx->pc = 0x1E36C4u;
label_1e36c4:
    // 0x1e36c4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e36c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e36c8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e36c8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e36cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e36ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e36d0: 0x10000073  b           . + 4 + (0x73 << 2)
    ctx->pc = 0x1E36D0u;
    {
        const bool branch_taken_0x1e36d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e36d0) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E36D8u;
label_1e36d8:
    // 0x1e36d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e36d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e36dc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e36dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e36e0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e36e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e36e4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e36e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e36e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e36e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e36ec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e36ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e36f0: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e36f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e36f4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e36f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e36f8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e36f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e36fc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E36FCu;
    {
        const bool branch_taken_0x1e36fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e36fc) {
            ctx->pc = 0x1E3718u;
            goto label_1e3718;
        }
    }
    ctx->pc = 0x1E3704u;
    // 0x1e3704: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3708: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3708u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e370c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e370cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3710: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E3710u;
    {
        const bool branch_taken_0x1e3710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3710) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E3718u;
label_1e3718:
    // 0x1e3718: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e3718u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e371c: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e371cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e3720: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3720u;
    SET_GPR_U32(ctx, 31, 0x1E3728u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3728u; }
        if (ctx->pc != 0x1E3728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3728u; }
        if (ctx->pc != 0x1E3728u) { return; }
    }
    ctx->pc = 0x1E3728u;
label_1e3728:
    // 0x1e3728: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3728u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e372c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e372cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3730: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3730u;
    {
        const bool branch_taken_0x1e3730 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3730) {
            ctx->pc = 0x1E374Cu;
            goto label_1e374c;
        }
    }
    ctx->pc = 0x1E3738u;
    // 0x1e3738: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3738u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e373c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e373cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3740: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3744: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1E3744u;
    {
        const bool branch_taken_0x1e3744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3744) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E374Cu;
label_1e374c:
    // 0x1e374c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e374cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3750: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e3750u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e3754: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3754u;
    SET_GPR_U32(ctx, 31, 0x1E375Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E375Cu; }
        if (ctx->pc != 0x1E375Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E375Cu; }
        if (ctx->pc != 0x1E375Cu) { return; }
    }
    ctx->pc = 0x1E375Cu;
label_1e375c:
    // 0x1e375c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e375cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e3760: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e3760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3764: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E3764u;
    {
        const bool branch_taken_0x1e3764 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3764) {
            ctx->pc = 0x1E3794u;
            goto label_1e3794;
        }
    }
    ctx->pc = 0x1E376Cu;
    // 0x1e376c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e376cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3770: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e3770u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e3774: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e3774u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3778: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3778u;
    SET_GPR_U32(ctx, 31, 0x1E3780u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3780u; }
        if (ctx->pc != 0x1E3780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3780u; }
        if (ctx->pc != 0x1E3780u) { return; }
    }
    ctx->pc = 0x1E3780u;
label_1e3780:
    // 0x1e3780: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3780u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3784: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3784u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3788: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3788u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e378c: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1E378Cu;
    {
        const bool branch_taken_0x1e378c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e378c) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E3794u;
label_1e3794:
    // 0x1e3794: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e3794u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3798: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e3798u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e379c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e379cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e37a0: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e37a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e37a4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e37a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e37a8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e37a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e37ac: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e37acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e37b0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e37b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e37b4: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e37b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e37b8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e37b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e37bc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e37bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e37c0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e37c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e37c4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e37c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e37c8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e37c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e37cc: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e37ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e37d0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e37d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e37d4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e37d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e37d8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e37d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e37dc: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e37dcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e37e0: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e37e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e37e4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e37e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e37e8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e37e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e37ec: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e37ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e37f0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e37f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e37f4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e37f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e37f8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e37f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e37fc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e37fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e3800: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e3800u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3804: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e3804u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3808: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3808u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e380c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e380cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e3810: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e3810u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3814: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e3814u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3818: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3818u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e381c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e381cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3820: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e3820u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3824: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3824u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3828: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1e3828u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1e382c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e382cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3830: 0x9042061e  lbu         $v0, 0x61E($v0)
    ctx->pc = 0x1e3830u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1566)));
    // 0x1e3834: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e3834u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3838: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e3838u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e383c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e383cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3840: 0x24070008  addiu       $a3, $zero, 0x8
    ctx->pc = 0x1e3840u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e3844: 0x24080009  addiu       $t0, $zero, 0x9
    ctx->pc = 0x1e3844u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e3848: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e3848u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e384c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E384Cu;
    SET_GPR_U32(ctx, 31, 0x1E3854u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3854u; }
        if (ctx->pc != 0x1E3854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3854u; }
        if (ctx->pc != 0x1E3854u) { return; }
    }
    ctx->pc = 0x1E3854u;
label_1e3854:
    // 0x1e3854: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3854u;
    {
        const bool branch_taken_0x1e3854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3854) {
            ctx->pc = 0x1E3870u;
            goto label_1e3870;
        }
    }
    ctx->pc = 0x1E385Cu;
    // 0x1e385c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e385cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3860: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3860u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3864: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3864u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3868: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E3868u;
    {
        const bool branch_taken_0x1e3868 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3868) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E3870u;
label_1e3870:
    // 0x1e3870: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3870u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3874: 0x24050017  addiu       $a1, $zero, 0x17
    ctx->pc = 0x1e3874u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x1e3878: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e3878u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e387c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E387Cu;
    SET_GPR_U32(ctx, 31, 0x1E3884u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3884u; }
        if (ctx->pc != 0x1E3884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3884u; }
        if (ctx->pc != 0x1E3884u) { return; }
    }
    ctx->pc = 0x1E3884u;
label_1e3884:
    // 0x1e3884: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e3884u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3888: 0x9064061e  lbu         $a0, 0x61E($v1)
    ctx->pc = 0x1e3888u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1566)));
    // 0x1e388c: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e388cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e3890: 0xa062061e  sb          $v0, 0x61E($v1)
    ctx->pc = 0x1e3890u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1566), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e3894: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e3894u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e3898: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e3898u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e389c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e389cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
label_1e38a0:
    // 0x1e38a0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e38a0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e38a4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e38a4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e38a8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e38a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e38ac: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e38acu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e38b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E38B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E38B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
