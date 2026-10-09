#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E3428
// Address: 0x1e3428 - 0x1e3670
void sub_001E3428_0x1e3428(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E3428_0x1e3428");
#endif

    switch (ctx->pc) {
        case 0x1e34e0u: goto label_1e34e0;
        case 0x1e3514u: goto label_1e3514;
        case 0x1e3538u: goto label_1e3538;
        case 0x1e360cu: goto label_1e360c;
        case 0x1e363cu: goto label_1e363c;
        default: break;
    }

    ctx->pc = 0x1e3428u;

    // 0x1e3428: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3428u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e342c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e342cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3430: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3430u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3434: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3434u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3438: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3438u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e343c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e343cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3440: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3440u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e3444: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e3444u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e3448: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e3448u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e344c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e344cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3450: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3450u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3454: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3454u;
    {
        const bool branch_taken_0x1e3454 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3454) {
            ctx->pc = 0x1E347Cu;
            goto label_1e347c;
        }
    }
    ctx->pc = 0x1E345Cu;
    // 0x1e345c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e345cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3460: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3460u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3464: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3468: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e346c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e346cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3470: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3474: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3474u;
    {
        const bool branch_taken_0x1e3474 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3474) {
            ctx->pc = 0x1E3490u;
            goto label_1e3490;
        }
    }
    ctx->pc = 0x1E347Cu;
label_1e347c:
    // 0x1e347c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e347cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3480: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3480u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3484: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3488: 0x10000073  b           . + 4 + (0x73 << 2)
    ctx->pc = 0x1E3488u;
    {
        const bool branch_taken_0x1e3488 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3488) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E3490u;
label_1e3490:
    // 0x1e3490: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3494: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3494u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3498: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3498u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e349c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e349cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e34a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e34a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e34a4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e34a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e34a8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e34a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e34ac: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e34acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e34b0: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e34b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e34b4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E34B4u;
    {
        const bool branch_taken_0x1e34b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e34b4) {
            ctx->pc = 0x1E34D0u;
            goto label_1e34d0;
        }
    }
    ctx->pc = 0x1E34BCu;
    // 0x1e34bc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e34bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e34c0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e34c0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e34c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e34c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e34c8: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E34C8u;
    {
        const bool branch_taken_0x1e34c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e34c8) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E34D0u;
label_1e34d0:
    // 0x1e34d0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e34d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e34d4: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e34d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e34d8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E34D8u;
    SET_GPR_U32(ctx, 31, 0x1E34E0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E34E0u; }
        if (ctx->pc != 0x1E34E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E34E0u; }
        if (ctx->pc != 0x1E34E0u) { return; }
    }
    ctx->pc = 0x1E34E0u;
label_1e34e0:
    // 0x1e34e0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e34e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e34e4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e34e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e34e8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E34E8u;
    {
        const bool branch_taken_0x1e34e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e34e8) {
            ctx->pc = 0x1E3504u;
            goto label_1e3504;
        }
    }
    ctx->pc = 0x1E34F0u;
    // 0x1e34f0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e34f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e34f4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e34f4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e34f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e34f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e34fc: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1E34FCu;
    {
        const bool branch_taken_0x1e34fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e34fc) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E3504u;
label_1e3504:
    // 0x1e3504: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e3504u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3508: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e3508u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e350c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E350Cu;
    SET_GPR_U32(ctx, 31, 0x1E3514u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3514u; }
        if (ctx->pc != 0x1E3514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3514u; }
        if (ctx->pc != 0x1E3514u) { return; }
    }
    ctx->pc = 0x1E3514u;
label_1e3514:
    // 0x1e3514: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e3514u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e3518: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e3518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e351c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E351Cu;
    {
        const bool branch_taken_0x1e351c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e351c) {
            ctx->pc = 0x1E354Cu;
            goto label_1e354c;
        }
    }
    ctx->pc = 0x1E3524u;
    // 0x1e3524: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e3524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3528: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e3528u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e352c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e352cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3530: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3530u;
    SET_GPR_U32(ctx, 31, 0x1E3538u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3538u; }
        if (ctx->pc != 0x1E3538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3538u; }
        if (ctx->pc != 0x1E3538u) { return; }
    }
    ctx->pc = 0x1E3538u;
label_1e3538:
    // 0x1e3538: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e353c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e353cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3540: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3544: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1E3544u;
    {
        const bool branch_taken_0x1e3544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3544) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E354Cu;
label_1e354c:
    // 0x1e354c: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e354cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3550: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e3550u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3554: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e3554u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e3558: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e3558u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e355c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e355cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3560: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e3560u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e3564: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e3564u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e3568: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e3568u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e356c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e356cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3570: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e3570u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3574: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3574u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3578: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e3578u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e357c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e357cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3580: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e3580u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3584: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3584u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e3588: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3588u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e358c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e358cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3590: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3590u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3594: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e3594u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e3598: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e3598u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e359c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e359cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e35a0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e35a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e35a4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e35a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e35a8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e35a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e35ac: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e35acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e35b0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e35b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e35b4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e35b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e35b8: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e35b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e35bc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e35bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e35c0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e35c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e35c4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e35c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e35c8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e35c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e35cc: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e35ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e35d0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e35d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e35d4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e35d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e35d8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e35d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e35dc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e35dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e35e0: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1e35e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1e35e4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e35e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e35e8: 0x9042061d  lbu         $v0, 0x61D($v0)
    ctx->pc = 0x1e35e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1565)));
    // 0x1e35ec: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e35ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e35f0: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e35f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e35f4: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e35f4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e35f8: 0x24070008  addiu       $a3, $zero, 0x8
    ctx->pc = 0x1e35f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e35fc: 0x24080009  addiu       $t0, $zero, 0x9
    ctx->pc = 0x1e35fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e3600: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e3600u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3604: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3604u;
    SET_GPR_U32(ctx, 31, 0x1E360Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E360Cu; }
        if (ctx->pc != 0x1E360Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E360Cu; }
        if (ctx->pc != 0x1E360Cu) { return; }
    }
    ctx->pc = 0x1E360Cu;
label_1e360c:
    // 0x1e360c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E360Cu;
    {
        const bool branch_taken_0x1e360c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e360c) {
            ctx->pc = 0x1E3628u;
            goto label_1e3628;
        }
    }
    ctx->pc = 0x1E3614u;
    // 0x1e3614: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3618: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3618u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e361c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e361cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3620: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E3620u;
    {
        const bool branch_taken_0x1e3620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3620) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E3628u;
label_1e3628:
    // 0x1e3628: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3628u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e362c: 0x24050016  addiu       $a1, $zero, 0x16
    ctx->pc = 0x1e362cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1e3630: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e3630u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3634: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3634u;
    SET_GPR_U32(ctx, 31, 0x1E363Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E363Cu; }
        if (ctx->pc != 0x1E363Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E363Cu; }
        if (ctx->pc != 0x1E363Cu) { return; }
    }
    ctx->pc = 0x1E363Cu;
label_1e363c:
    // 0x1e363c: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e363cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3640: 0x9064061d  lbu         $a0, 0x61D($v1)
    ctx->pc = 0x1e3640u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1565)));
    // 0x1e3644: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e3644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e3648: 0xa062061d  sb          $v0, 0x61D($v1)
    ctx->pc = 0x1e3648u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1565), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e364c: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e364cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e3650: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e3650u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e3654: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e3654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
label_1e3658:
    // 0x1e3658: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3658u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e365c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e365cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e3660: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e3660u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3664: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3664u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3668: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3668u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3670u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
