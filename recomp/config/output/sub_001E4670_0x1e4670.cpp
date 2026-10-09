#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E4670
// Address: 0x1e4670 - 0x1e4818
void sub_001E4670_0x1e4670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E4670_0x1e4670");
#endif

    switch (ctx->pc) {
        case 0x1e472cu: goto label_1e472c;
        case 0x1e4764u: goto label_1e4764;
        case 0x1e4788u: goto label_1e4788;
        case 0x1e47b0u: goto label_1e47b0;
        case 0x1e47e0u: goto label_1e47e0;
        default: break;
    }

    ctx->pc = 0x1e4670u;

    // 0x1e4670: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e4670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e4674: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e4674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e4678: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e4678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e467c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e467cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4680: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4680u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e4684: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e4684u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4688: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4688u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e468c: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e468cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4690: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e4690u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e4694: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e4694u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e4698: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4698u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e469c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e469cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e46a0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E46A0u;
    {
        const bool branch_taken_0x1e46a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e46a0) {
            ctx->pc = 0x1E46C8u;
            goto label_1e46c8;
        }
    }
    ctx->pc = 0x1E46A8u;
    // 0x1e46a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e46a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e46ac: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e46acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e46b0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e46b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e46b4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e46b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e46b8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e46b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e46bc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e46bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e46c0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E46C0u;
    {
        const bool branch_taken_0x1e46c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e46c0) {
            ctx->pc = 0x1E46DCu;
            goto label_1e46dc;
        }
    }
    ctx->pc = 0x1E46C8u;
label_1e46c8:
    // 0x1e46c8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e46c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e46cc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e46ccu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e46d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e46d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e46d4: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1E46D4u;
    {
        const bool branch_taken_0x1e46d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e46d4) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E46DCu;
label_1e46dc:
    // 0x1e46dc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e46dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e46e0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e46e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e46e4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e46e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e46e8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e46e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e46ec: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e46ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e46f0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e46f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e46f4: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e46f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e46f8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e46f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e46fc: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e46fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4700: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4700u;
    {
        const bool branch_taken_0x1e4700 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4700) {
            ctx->pc = 0x1E471Cu;
            goto label_1e471c;
        }
    }
    ctx->pc = 0x1E4708u;
    // 0x1e4708: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e470c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e470cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4710: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4710u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4714: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1E4714u;
    {
        const bool branch_taken_0x1e4714 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4714) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E471Cu;
label_1e471c:
    // 0x1e471c: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e471cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4720: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e4720u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4724: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4724u;
    SET_GPR_U32(ctx, 31, 0x1E472Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E472Cu; }
        if (ctx->pc != 0x1E472Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E472Cu; }
        if (ctx->pc != 0x1E472Cu) { return; }
    }
    ctx->pc = 0x1E472Cu;
label_1e472c:
    // 0x1e472c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e472cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e4730: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4730u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4734: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4734u;
    {
        const bool branch_taken_0x1e4734 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4734) {
            ctx->pc = 0x1E4750u;
            goto label_1e4750;
        }
    }
    ctx->pc = 0x1E473Cu;
    // 0x1e473c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e473cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4740: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4740u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4744: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4744u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4748: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1E4748u;
    {
        const bool branch_taken_0x1e4748 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4748) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E4750u;
label_1e4750:
    // 0x1e4750: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4750u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4754: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e4754u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4758: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4758u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e475c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E475Cu;
    SET_GPR_U32(ctx, 31, 0x1E4764u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4764u; }
        if (ctx->pc != 0x1E4764u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4764u; }
        if (ctx->pc != 0x1E4764u) { return; }
    }
    ctx->pc = 0x1E4764u;
label_1e4764:
    // 0x1e4764: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4764u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4768: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e476c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E476Cu;
    {
        const bool branch_taken_0x1e476c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e476c) {
            ctx->pc = 0x1E479Cu;
            goto label_1e479c;
        }
    }
    ctx->pc = 0x1E4774u;
    // 0x1e4774: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e4774u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4778: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4778u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e477c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e477cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4780: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E4780u;
    SET_GPR_U32(ctx, 31, 0x1E4788u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4788u; }
        if (ctx->pc != 0x1E4788u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4788u; }
        if (ctx->pc != 0x1E4788u) { return; }
    }
    ctx->pc = 0x1E4788u;
label_1e4788:
    // 0x1e4788: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4788u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e478c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e478cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4790: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4790u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4794: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1E4794u;
    {
        const bool branch_taken_0x1e4794 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4794) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E479Cu;
label_1e479c:
    // 0x1e479c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e479cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e47a0: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e47a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e47a4: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e47a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e47a8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E47A8u;
    SET_GPR_U32(ctx, 31, 0x1E47B0u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E47B0u; }
        if (ctx->pc != 0x1E47B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E47B0u; }
        if (ctx->pc != 0x1E47B0u) { return; }
    }
    ctx->pc = 0x1E47B0u;
label_1e47b0:
    // 0x1e47b0: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e47b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e47b4: 0x3442a400  ori         $v0, $v0, 0xA400
    ctx->pc = 0x1e47b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)41984);
    // 0x1e47b8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e47b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e47bc: 0x97c30008  lhu         $v1, 0x8($fp)
    ctx->pc = 0x1e47bcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e47c0: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e47c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e47c4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e47c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e47c8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1e47c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e47cc: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e47ccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e47d0: 0x2408000f  addiu       $t0, $zero, 0xF
    ctx->pc = 0x1e47d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1e47d4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e47d4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e47d8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E47D8u;
    SET_GPR_U32(ctx, 31, 0x1E47E0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E47E0u; }
        if (ctx->pc != 0x1E47E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E47E0u; }
        if (ctx->pc != 0x1E47E0u) { return; }
    }
    ctx->pc = 0x1E47E0u;
label_1e47e0:
    // 0x1e47e0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E47E0u;
    {
        const bool branch_taken_0x1e47e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e47e0) {
            ctx->pc = 0x1E47FCu;
            goto label_1e47fc;
        }
    }
    ctx->pc = 0x1E47E8u;
    // 0x1e47e8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e47e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e47ec: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e47ecu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e47f0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e47f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e47f4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E47F4u;
    {
        const bool branch_taken_0x1e47f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e47f4) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E47FCu;
label_1e47fc:
    // 0x1e47fc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e47fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4800:
    // 0x1e4800: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4800u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4804: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e4804u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4808: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4808u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e480c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e480cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e4810: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4818u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
