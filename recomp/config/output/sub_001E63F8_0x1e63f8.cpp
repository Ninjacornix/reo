#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E63F8
// Address: 0x1e63f8 - 0x1e65a4
void sub_001E63F8_0x1e63f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E63F8_0x1e63f8");
#endif

    switch (ctx->pc) {
        case 0x1e64c4u: goto label_1e64c4;
        case 0x1e64fcu: goto label_1e64fc;
        case 0x1e6520u: goto label_1e6520;
        case 0x1e6548u: goto label_1e6548;
        case 0x1e656cu: goto label_1e656c;
        default: break;
    }

    ctx->pc = 0x1e63f8u;

    // 0x1e63f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e63f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e63fc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e63fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e6400: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e6400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e6404: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6404u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6408: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6408u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e640c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e640cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6410: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e6410u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e6414: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e6414u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e6418: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e6418u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e641c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e641cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6420: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E6420u;
    {
        const bool branch_taken_0x1e6420 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e6420) {
            ctx->pc = 0x1E6448u;
            goto label_1e6448;
        }
    }
    ctx->pc = 0x1E6428u;
    // 0x1e6428: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6428u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e642c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e642cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6430: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6434: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6434u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6438: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6438u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e643c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e643cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6440: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6440u;
    {
        const bool branch_taken_0x1e6440 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6440) {
            ctx->pc = 0x1E645Cu;
            goto label_1e645c;
        }
    }
    ctx->pc = 0x1E6448u;
label_1e6448:
    // 0x1e6448: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e6448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e644c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e644cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6450: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6450u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6454: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1E6454u;
    {
        const bool branch_taken_0x1e6454 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6454) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E645Cu;
label_1e645c:
    // 0x1e645c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e645cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6460: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6460u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6464: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6468: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e646c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e646cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6470: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6474: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e6474u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6478: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e647c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e647cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6480: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6480u;
    {
        const bool branch_taken_0x1e6480 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6480) {
            ctx->pc = 0x1E649Cu;
            goto label_1e649c;
        }
    }
    ctx->pc = 0x1E6488u;
    // 0x1e6488: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e648c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e648cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6490: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6490u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6494: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1E6494u;
    {
        const bool branch_taken_0x1e6494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6494) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E649Cu;
label_1e649c:
    // 0x1e649c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e649cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e64a0: 0x2c42036c  sltiu       $v0, $v0, 0x36C
    ctx->pc = 0x1e64a0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)876) ? 1 : 0);
    // 0x1e64a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E64A4u;
    {
        const bool branch_taken_0x1e64a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e64a4) {
            ctx->pc = 0x1E64B4u;
            goto label_1e64b4;
        }
    }
    ctx->pc = 0x1E64ACu;
    // 0x1e64ac: 0x2402036c  addiu       $v0, $zero, 0x36C
    ctx->pc = 0x1e64acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 876));
    // 0x1e64b0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e64b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
label_1e64b4:
    // 0x1e64b4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e64b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e64b8: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e64b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e64bc: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E64BCu;
    SET_GPR_U32(ctx, 31, 0x1E64C4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E64C4u; }
        if (ctx->pc != 0x1E64C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E64C4u; }
        if (ctx->pc != 0x1E64C4u) { return; }
    }
    ctx->pc = 0x1E64C4u;
label_1e64c4:
    // 0x1e64c4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e64c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e64c8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e64c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e64cc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E64CCu;
    {
        const bool branch_taken_0x1e64cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e64cc) {
            ctx->pc = 0x1E64E8u;
            goto label_1e64e8;
        }
    }
    ctx->pc = 0x1E64D4u;
    // 0x1e64d4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e64d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e64d8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e64d8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e64dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e64dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e64e0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1E64E0u;
    {
        const bool branch_taken_0x1e64e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e64e0) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E64E8u;
label_1e64e8:
    // 0x1e64e8: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e64e8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e64ec: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e64ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e64f0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e64f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e64f4: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E64F4u;
    SET_GPR_U32(ctx, 31, 0x1E64FCu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E64FCu; }
        if (ctx->pc != 0x1E64FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E64FCu; }
        if (ctx->pc != 0x1E64FCu) { return; }
    }
    ctx->pc = 0x1E64FCu;
label_1e64fc:
    // 0x1e64fc: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e64fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e6500: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e6500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6504: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E6504u;
    {
        const bool branch_taken_0x1e6504 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6504) {
            ctx->pc = 0x1E6534u;
            goto label_1e6534;
        }
    }
    ctx->pc = 0x1E650Cu;
    // 0x1e650c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e650cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6510: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e6510u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e6514: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6514u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6518: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E6518u;
    SET_GPR_U32(ctx, 31, 0x1E6520u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6520u; }
        if (ctx->pc != 0x1E6520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6520u; }
        if (ctx->pc != 0x1E6520u) { return; }
    }
    ctx->pc = 0x1E6520u;
label_1e6520:
    // 0x1e6520: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6520u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6524: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6524u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6528: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e652c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E652Cu;
    {
        const bool branch_taken_0x1e652c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e652c) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E6534u;
label_1e6534:
    // 0x1e6534: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e6534u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6538: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e6538u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e653c: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e653cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e6540: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6540u;
    SET_GPR_U32(ctx, 31, 0x1E6548u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6548u; }
        if (ctx->pc != 0x1E6548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6548u; }
        if (ctx->pc != 0x1E6548u) { return; }
    }
    ctx->pc = 0x1E6548u;
label_1e6548:
    // 0x1e6548: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e6548u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e654c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e654cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6550: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6550u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6554: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e6554u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e6558: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e6558u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e655c: 0x2408003e  addiu       $t0, $zero, 0x3E
    ctx->pc = 0x1e655cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
    // 0x1e6560: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e6560u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6564: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E6564u;
    SET_GPR_U32(ctx, 31, 0x1E656Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E656Cu; }
        if (ctx->pc != 0x1E656Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E656Cu; }
        if (ctx->pc != 0x1E656Cu) { return; }
    }
    ctx->pc = 0x1E656Cu;
label_1e656c:
    // 0x1e656c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E656Cu;
    {
        const bool branch_taken_0x1e656c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e656c) {
            ctx->pc = 0x1E6588u;
            goto label_1e6588;
        }
    }
    ctx->pc = 0x1E6574u;
    // 0x1e6574: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6574u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6578: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6578u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e657c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e657cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6580: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E6580u;
    {
        const bool branch_taken_0x1e6580 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6580) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E6588u;
label_1e6588:
    // 0x1e6588: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e6588u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e658c:
    // 0x1e658c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e658cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6590: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e6590u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e6594: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e6594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e6598: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e6598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e659c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E659Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E65A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
