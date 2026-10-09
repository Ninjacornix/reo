#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E4478
// Address: 0x1e4478 - 0x1e4670
void sub_001E4478_0x1e4478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E4478_0x1e4478");
#endif

    switch (ctx->pc) {
        case 0x1e452cu: goto label_1e452c;
        case 0x1e4560u: goto label_1e4560;
        case 0x1e4584u: goto label_1e4584;
        case 0x1e460cu: goto label_1e460c;
        case 0x1e463cu: goto label_1e463c;
        default: break;
    }

    ctx->pc = 0x1e4478u;

    // 0x1e4478: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e4478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e447c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e447cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e4480: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e4480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e4484: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e4484u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4488: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4488u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e448c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e448cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4490: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4490u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e4494: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e4494u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e4498: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4498u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e449c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e449cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e44a0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E44A0u;
    {
        const bool branch_taken_0x1e44a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e44a0) {
            ctx->pc = 0x1E44C8u;
            goto label_1e44c8;
        }
    }
    ctx->pc = 0x1E44A8u;
    // 0x1e44a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e44a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e44ac: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e44acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e44b0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e44b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e44b4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e44b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e44b8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e44b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e44bc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e44bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e44c0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E44C0u;
    {
        const bool branch_taken_0x1e44c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e44c0) {
            ctx->pc = 0x1E44DCu;
            goto label_1e44dc;
        }
    }
    ctx->pc = 0x1E44C8u;
label_1e44c8:
    // 0x1e44c8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e44c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e44cc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e44ccu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e44d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e44d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e44d4: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1E44D4u;
    {
        const bool branch_taken_0x1e44d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e44d4) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E44DCu;
label_1e44dc:
    // 0x1e44dc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e44dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e44e0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e44e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e44e4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e44e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e44e8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e44e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e44ec: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e44ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e44f0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e44f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e44f4: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e44f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e44f8: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e44f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e44fc: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e44fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4500: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4500u;
    {
        const bool branch_taken_0x1e4500 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4500) {
            ctx->pc = 0x1E451Cu;
            goto label_1e451c;
        }
    }
    ctx->pc = 0x1E4508u;
    // 0x1e4508: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4508u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e450c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e450cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4510: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4514: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1E4514u;
    {
        const bool branch_taken_0x1e4514 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4514) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E451Cu;
label_1e451c:
    // 0x1e451c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e451cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4520: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e4520u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e4524: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4524u;
    SET_GPR_U32(ctx, 31, 0x1E452Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E452Cu; }
        if (ctx->pc != 0x1E452Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E452Cu; }
        if (ctx->pc != 0x1E452Cu) { return; }
    }
    ctx->pc = 0x1E452Cu;
label_1e452c:
    // 0x1e452c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e452cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e4530: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e4530u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4534: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4534u;
    {
        const bool branch_taken_0x1e4534 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4534) {
            ctx->pc = 0x1E4550u;
            goto label_1e4550;
        }
    }
    ctx->pc = 0x1E453Cu;
    // 0x1e453c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e453cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4540: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4540u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4544: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4548: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E4548u;
    {
        const bool branch_taken_0x1e4548 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4548) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E4550u;
label_1e4550:
    // 0x1e4550: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e4550u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4554: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e4554u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e4558: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E4558u;
    SET_GPR_U32(ctx, 31, 0x1E4560u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4560u; }
        if (ctx->pc != 0x1E4560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4560u; }
        if (ctx->pc != 0x1E4560u) { return; }
    }
    ctx->pc = 0x1E4560u;
label_1e4560:
    // 0x1e4560: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e4560u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e4564: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4564u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4568: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E4568u;
    {
        const bool branch_taken_0x1e4568 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4568) {
            ctx->pc = 0x1E4598u;
            goto label_1e4598;
        }
    }
    ctx->pc = 0x1E4570u;
    // 0x1e4570: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4574: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4574u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e4578: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4578u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e457c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E457Cu;
    SET_GPR_U32(ctx, 31, 0x1E4584u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4584u; }
        if (ctx->pc != 0x1E4584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4584u; }
        if (ctx->pc != 0x1E4584u) { return; }
    }
    ctx->pc = 0x1E4584u;
label_1e4584:
    // 0x1e4584: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4584u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4588: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4588u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e458c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e458cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4590: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E4590u;
    {
        const bool branch_taken_0x1e4590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4590) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E4598u;
label_1e4598:
    // 0x1e4598: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4598u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e459c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e459cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e45a0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e45a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e45a4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e45a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e45a8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e45a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e45ac: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e45acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e45b0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e45b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e45b4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e45b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e45b8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e45b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e45bc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e45bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e45c0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e45c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e45c4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e45c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e45c8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e45c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e45cc: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e45ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e45d0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e45d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e45d4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e45d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e45d8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e45d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e45dc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e45dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e45e0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e45e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e45e4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e45e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e45e8: 0x90420620  lbu         $v0, 0x620($v0)
    ctx->pc = 0x1e45e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1568)));
    // 0x1e45ec: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e45ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e45f0: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e45f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e45f4: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e45f4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e45f8: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e45f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e45fc: 0x2408000d  addiu       $t0, $zero, 0xD
    ctx->pc = 0x1e45fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1e4600: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e4600u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4604: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4604u;
    SET_GPR_U32(ctx, 31, 0x1E460Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E460Cu; }
        if (ctx->pc != 0x1E460Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E460Cu; }
        if (ctx->pc != 0x1E460Cu) { return; }
    }
    ctx->pc = 0x1E460Cu;
label_1e460c:
    // 0x1e460c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E460Cu;
    {
        const bool branch_taken_0x1e460c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e460c) {
            ctx->pc = 0x1E4628u;
            goto label_1e4628;
        }
    }
    ctx->pc = 0x1E4614u;
    // 0x1e4614: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4618: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4618u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e461c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e461cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4620: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E4620u;
    {
        const bool branch_taken_0x1e4620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4620) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E4628u;
label_1e4628:
    // 0x1e4628: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e4628u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e462c: 0x24050027  addiu       $a1, $zero, 0x27
    ctx->pc = 0x1e462cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x1e4630: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4630u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4634: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E4634u;
    SET_GPR_U32(ctx, 31, 0x1E463Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E463Cu; }
        if (ctx->pc != 0x1E463Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E463Cu; }
        if (ctx->pc != 0x1E463Cu) { return; }
    }
    ctx->pc = 0x1E463Cu;
label_1e463c:
    // 0x1e463c: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e463cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4640: 0x90640620  lbu         $a0, 0x620($v1)
    ctx->pc = 0x1e4640u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1568)));
    // 0x1e4644: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e4644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e4648: 0xa0620620  sb          $v0, 0x620($v1)
    ctx->pc = 0x1e4648u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1568), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e464c: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e464cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e4650: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e4650u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e4654: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e4654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e4658:
    // 0x1e4658: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4658u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e465c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e465cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4660: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4660u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e4664: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e4664u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e4668: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4668u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4670u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
