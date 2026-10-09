#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E42A0
// Address: 0x1e42a0 - 0x1e4478
void sub_001E42A0_0x1e42a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E42A0_0x1e42a0");
#endif

    switch (ctx->pc) {
        case 0x1e4358u: goto label_1e4358;
        case 0x1e4394u: goto label_1e4394;
        case 0x1e43b8u: goto label_1e43b8;
        case 0x1e43e4u: goto label_1e43e4;
        case 0x1e4414u: goto label_1e4414;
        case 0x1e4444u: goto label_1e4444;
        default: break;
    }

    ctx->pc = 0x1e42a0u;

    // 0x1e42a0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e42a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e42a4: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e42a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e42a8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e42a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e42ac: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e42acu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e42b0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e42b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e42b4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e42b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e42b8: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e42b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e42bc: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e42bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e42c0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e42c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e42c4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e42c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e42c8: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E42C8u;
    {
        const bool branch_taken_0x1e42c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e42c8) {
            ctx->pc = 0x1E42F0u;
            goto label_1e42f0;
        }
    }
    ctx->pc = 0x1E42D0u;
    // 0x1e42d0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e42d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e42d4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e42d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e42d8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e42d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e42dc: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e42dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e42e0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e42e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e42e4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e42e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e42e8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E42E8u;
    {
        const bool branch_taken_0x1e42e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e42e8) {
            ctx->pc = 0x1E4304u;
            goto label_1e4304;
        }
    }
    ctx->pc = 0x1E42F0u;
label_1e42f0:
    // 0x1e42f0: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e42f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e42f4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e42f4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e42f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e42f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e42fc: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E42FCu;
    {
        const bool branch_taken_0x1e42fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e42fc) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E4304u;
label_1e4304:
    // 0x1e4304: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4308: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4308u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e430c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e430cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4310: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4310u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4314: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4318: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4318u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e431c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e431cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4320: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4324: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e4324u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4328: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4328u;
    {
        const bool branch_taken_0x1e4328 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4328) {
            ctx->pc = 0x1E4344u;
            goto label_1e4344;
        }
    }
    ctx->pc = 0x1E4330u;
    // 0x1e4330: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4334: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4334u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4338: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4338u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e433c: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E433Cu;
    {
        const bool branch_taken_0x1e433c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e433c) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E4344u;
label_1e4344:
    // 0x1e4344: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4348: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4348u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e434c: 0x8c450064  lw          $a1, 0x64($v0)
    ctx->pc = 0x1e434cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1e4350: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4350u;
    SET_GPR_U32(ctx, 31, 0x1E4358u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4358u; }
        if (ctx->pc != 0x1E4358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4358u; }
        if (ctx->pc != 0x1E4358u) { return; }
    }
    ctx->pc = 0x1E4358u;
label_1e4358:
    // 0x1e4358: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e4358u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e435c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e435cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4360: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4360u;
    {
        const bool branch_taken_0x1e4360 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4360) {
            ctx->pc = 0x1E437Cu;
            goto label_1e437c;
        }
    }
    ctx->pc = 0x1E4368u;
    // 0x1e4368: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e436c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e436cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4370: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4374: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1E4374u;
    {
        const bool branch_taken_0x1e4374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4374) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E437Cu;
label_1e437c:
    // 0x1e437c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e437cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4380: 0x94420064  lhu         $v0, 0x64($v0)
    ctx->pc = 0x1e4380u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1e4384: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e4384u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4388: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4388u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e438c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E438Cu;
    SET_GPR_U32(ctx, 31, 0x1E4394u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4394u; }
        if (ctx->pc != 0x1E4394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4394u; }
        if (ctx->pc != 0x1E4394u) { return; }
    }
    ctx->pc = 0x1E4394u;
label_1e4394:
    // 0x1e4394: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e4394u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e4398: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e439c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E439Cu;
    {
        const bool branch_taken_0x1e439c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e439c) {
            ctx->pc = 0x1E43CCu;
            goto label_1e43cc;
        }
    }
    ctx->pc = 0x1E43A4u;
    // 0x1e43a4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e43a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43a8: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e43a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e43ac: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e43acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e43b0: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E43B0u;
    SET_GPR_U32(ctx, 31, 0x1E43B8u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E43B8u; }
        if (ctx->pc != 0x1E43B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E43B8u; }
        if (ctx->pc != 0x1E43B8u) { return; }
    }
    ctx->pc = 0x1E43B8u;
label_1e43b8:
    // 0x1e43b8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e43b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e43bc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e43bcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e43c0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e43c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e43c4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1E43C4u;
    {
        const bool branch_taken_0x1e43c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e43c4) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E43CCu;
label_1e43cc:
    // 0x1e43cc: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e43ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43d0: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e43d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e43d4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e43d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e43d8: 0x8c460064  lw          $a2, 0x64($v0)
    ctx->pc = 0x1e43d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1e43dc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E43DCu;
    SET_GPR_U32(ctx, 31, 0x1E43E4u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E43E4u; }
        if (ctx->pc != 0x1E43E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E43E4u; }
        if (ctx->pc != 0x1E43E4u) { return; }
    }
    ctx->pc = 0x1E43E4u;
label_1e43e4:
    // 0x1e43e4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e43e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43e8: 0x94430064  lhu         $v1, 0x64($v0)
    ctx->pc = 0x1e43e8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1e43ec: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e43ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43f0: 0x9042061f  lbu         $v0, 0x61F($v0)
    ctx->pc = 0x1e43f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1567)));
    // 0x1e43f4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e43f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43f8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e43f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e43fc: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e43fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e4400: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e4400u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4404: 0x2408000c  addiu       $t0, $zero, 0xC
    ctx->pc = 0x1e4404u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1e4408: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e4408u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e440c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E440Cu;
    SET_GPR_U32(ctx, 31, 0x1E4414u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4414u; }
        if (ctx->pc != 0x1E4414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4414u; }
        if (ctx->pc != 0x1E4414u) { return; }
    }
    ctx->pc = 0x1E4414u;
label_1e4414:
    // 0x1e4414: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4414u;
    {
        const bool branch_taken_0x1e4414 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4414) {
            ctx->pc = 0x1E4430u;
            goto label_1e4430;
        }
    }
    ctx->pc = 0x1E441Cu;
    // 0x1e441c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e441cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4420: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4420u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4424: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4424u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4428: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E4428u;
    {
        const bool branch_taken_0x1e4428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4428) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E4430u;
label_1e4430:
    // 0x1e4430: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e4430u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4434: 0x24050026  addiu       $a1, $zero, 0x26
    ctx->pc = 0x1e4434u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 38));
    // 0x1e4438: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4438u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e443c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E443Cu;
    SET_GPR_U32(ctx, 31, 0x1E4444u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4444u; }
        if (ctx->pc != 0x1E4444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4444u; }
        if (ctx->pc != 0x1E4444u) { return; }
    }
    ctx->pc = 0x1E4444u;
label_1e4444:
    // 0x1e4444: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e4444u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4448: 0x9064061f  lbu         $a0, 0x61F($v1)
    ctx->pc = 0x1e4448u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1567)));
    // 0x1e444c: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e444cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e4450: 0xa062061f  sb          $v0, 0x61F($v1)
    ctx->pc = 0x1e4450u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1567), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e4454: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e4454u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e4458: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e4458u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e445c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e445cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e4460:
    // 0x1e4460: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4460u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4464: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e4464u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4468: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e446c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e446cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e4470: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4478u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
