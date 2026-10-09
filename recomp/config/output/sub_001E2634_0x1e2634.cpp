#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E2634
// Address: 0x1e2634 - 0x1e282c
void sub_001E2634_0x1e2634(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E2634_0x1e2634");
#endif

    switch (ctx->pc) {
        case 0x1e26e8u: goto label_1e26e8;
        case 0x1e271cu: goto label_1e271c;
        case 0x1e2740u: goto label_1e2740;
        case 0x1e27c8u: goto label_1e27c8;
        case 0x1e27f8u: goto label_1e27f8;
        default: break;
    }

    ctx->pc = 0x1e2634u;

    // 0x1e2634: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e2634u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2638: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2638u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e263c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e263cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e2640: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2640u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2644: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2644u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2648: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2648u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e264c: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e264cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2650: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e2650u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e2654: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2654u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2658: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2658u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e265c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E265Cu;
    {
        const bool branch_taken_0x1e265c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e265c) {
            ctx->pc = 0x1E2684u;
            goto label_1e2684;
        }
    }
    ctx->pc = 0x1E2664u;
    // 0x1e2664: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2668: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2668u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e266c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e266cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2670: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2670u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2674: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2674u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2678: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e267c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E267Cu;
    {
        const bool branch_taken_0x1e267c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e267c) {
            ctx->pc = 0x1E2698u;
            goto label_1e2698;
        }
    }
    ctx->pc = 0x1E2684u;
label_1e2684:
    // 0x1e2684: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2688: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2688u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e268c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e268cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2690: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1E2690u;
    {
        const bool branch_taken_0x1e2690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2690) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E2698u;
label_1e2698:
    // 0x1e2698: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e269c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e269cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e26a0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e26a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e26a4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e26a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e26a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e26a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e26ac: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e26acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e26b0: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e26b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e26b4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e26b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e26b8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e26b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e26bc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E26BCu;
    {
        const bool branch_taken_0x1e26bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e26bc) {
            ctx->pc = 0x1E26D8u;
            goto label_1e26d8;
        }
    }
    ctx->pc = 0x1E26C4u;
    // 0x1e26c4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e26c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e26c8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e26c8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e26cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e26ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e26d0: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1E26D0u;
    {
        const bool branch_taken_0x1e26d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e26d0) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E26D8u;
label_1e26d8:
    // 0x1e26d8: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e26d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e26dc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e26dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e26e0: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E26E0u;
    SET_GPR_U32(ctx, 31, 0x1E26E8u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E26E8u; }
        if (ctx->pc != 0x1E26E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E26E8u; }
        if (ctx->pc != 0x1E26E8u) { return; }
    }
    ctx->pc = 0x1E26E8u;
label_1e26e8:
    // 0x1e26e8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e26e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e26ec: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e26ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e26f0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E26F0u;
    {
        const bool branch_taken_0x1e26f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e26f0) {
            ctx->pc = 0x1E270Cu;
            goto label_1e270c;
        }
    }
    ctx->pc = 0x1E26F8u;
    // 0x1e26f8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e26f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e26fc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e26fcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2700: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2704: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E2704u;
    {
        const bool branch_taken_0x1e2704 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2704) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E270Cu;
label_1e270c:
    // 0x1e270c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e270cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2710: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e2710u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e2714: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2714u;
    SET_GPR_U32(ctx, 31, 0x1E271Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E271Cu; }
        if (ctx->pc != 0x1E271Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E271Cu; }
        if (ctx->pc != 0x1E271Cu) { return; }
    }
    ctx->pc = 0x1E271Cu;
label_1e271c:
    // 0x1e271c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e271cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e2720: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2724: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2724u;
    {
        const bool branch_taken_0x1e2724 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2724) {
            ctx->pc = 0x1E2754u;
            goto label_1e2754;
        }
    }
    ctx->pc = 0x1E272Cu;
    // 0x1e272c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e272cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2730: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e2730u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2734: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e2734u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2738: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2738u;
    SET_GPR_U32(ctx, 31, 0x1E2740u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2740u; }
        if (ctx->pc != 0x1E2740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2740u; }
        if (ctx->pc != 0x1E2740u) { return; }
    }
    ctx->pc = 0x1E2740u;
label_1e2740:
    // 0x1e2740: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2744: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2744u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2748: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e274c: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E274Cu;
    {
        const bool branch_taken_0x1e274c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e274c) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E2754u;
label_1e2754:
    // 0x1e2754: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e2754u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2758: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e275c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e275cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2760: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2760u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2764: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2764u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2768: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2768u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e276c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e276cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2770: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2770u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2774: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2774u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2778: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2778u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e277c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e277cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2780: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e2780u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e2784: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2784u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2788: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2788u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e278c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e278cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2790: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2790u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2794: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e2794u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2798: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2798u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e279c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e279cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e27a0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e27a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e27a4: 0x90420617  lbu         $v0, 0x617($v0)
    ctx->pc = 0x1e27a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1559)));
    // 0x1e27a8: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e27a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e27ac: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e27acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e27b0: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e27b0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e27b4: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e27b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e27b8: 0x24080005  addiu       $t0, $zero, 0x5
    ctx->pc = 0x1e27b8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1e27bc: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e27bcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e27c0: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E27C0u;
    SET_GPR_U32(ctx, 31, 0x1E27C8u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E27C8u; }
        if (ctx->pc != 0x1E27C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E27C8u; }
        if (ctx->pc != 0x1E27C8u) { return; }
    }
    ctx->pc = 0x1E27C8u;
label_1e27c8:
    // 0x1e27c8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E27C8u;
    {
        const bool branch_taken_0x1e27c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e27c8) {
            ctx->pc = 0x1E27E4u;
            goto label_1e27e4;
        }
    }
    ctx->pc = 0x1E27D0u;
    // 0x1e27d0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e27d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e27d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e27d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e27d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e27d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e27dc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E27DCu;
    {
        const bool branch_taken_0x1e27dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e27dc) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E27E4u;
label_1e27e4:
    // 0x1e27e4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e27e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e27e8: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1e27e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1e27ec: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e27ecu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e27f0: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E27F0u;
    SET_GPR_U32(ctx, 31, 0x1E27F8u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E27F8u; }
        if (ctx->pc != 0x1E27F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E27F8u; }
        if (ctx->pc != 0x1E27F8u) { return; }
    }
    ctx->pc = 0x1E27F8u;
label_1e27f8:
    // 0x1e27f8: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e27f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e27fc: 0x90640617  lbu         $a0, 0x617($v1)
    ctx->pc = 0x1e27fcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1559)));
    // 0x1e2800: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2804: 0xa0620617  sb          $v0, 0x617($v1)
    ctx->pc = 0x1e2804u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1559), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2808: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2808u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e280c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e280cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e2810: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2810u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
label_1e2814:
    // 0x1e2814: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2814u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2818: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2818u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e281c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e281cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e2820: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e2820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e2824: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2824u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E282Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
