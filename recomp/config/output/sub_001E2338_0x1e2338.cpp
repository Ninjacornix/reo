#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E2338
// Address: 0x1e2338 - 0x1e2634
void sub_001E2338_0x1e2338(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E2338_0x1e2338");
#endif

    switch (ctx->pc) {
        case 0x1e2404u: goto label_1e2404;
        case 0x1e2438u: goto label_1e2438;
        case 0x1e245cu: goto label_1e245c;
        case 0x1e2480u: goto label_1e2480;
        case 0x1e24f8u: goto label_1e24f8;
        case 0x1e25d0u: goto label_1e25d0;
        case 0x1e2600u: goto label_1e2600;
        default: break;
    }

    ctx->pc = 0x1e2338u;

    // 0x1e2338: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e2338u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e233c: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e233cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e2340: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e2340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e2344: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2344u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2348: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2348u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e234c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e234cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2350: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2350u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2354: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e2354u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2358: 0x100182d  daddu       $v1, $t0, $zero
    ctx->pc = 0x1e2358u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e235c: 0xafc90010  sw          $t1, 0x10($fp)
    ctx->pc = 0x1e235cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 9));
    // 0x1e2360: 0xafca0014  sw          $t2, 0x14($fp)
    ctx->pc = 0x1e2360u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 10));
    // 0x1e2364: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e2364u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e2368: 0xa7c3000e  sh          $v1, 0xE($fp)
    ctx->pc = 0x1e2368u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 14), (uint16_t)GPR_U32(ctx, 3));
    // 0x1e236c: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e236cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0x1e2370: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2370u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2374: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2378: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2378u;
    {
        const bool branch_taken_0x1e2378 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2378) {
            ctx->pc = 0x1E23A0u;
            goto label_1e23a0;
        }
    }
    ctx->pc = 0x1E2380u;
    // 0x1e2380: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2380u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2384: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2384u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2388: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2388u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e238c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e238cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2390: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2394: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2398: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2398u;
    {
        const bool branch_taken_0x1e2398 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2398) {
            ctx->pc = 0x1E23B4u;
            goto label_1e23b4;
        }
    }
    ctx->pc = 0x1E23A0u;
label_1e23a0:
    // 0x1e23a0: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e23a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e23a4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e23a4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e23a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e23a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e23ac: 0x1000009b  b           . + 4 + (0x9B << 2)
    ctx->pc = 0x1E23ACu;
    {
        const bool branch_taken_0x1e23ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e23ac) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E23B4u;
label_1e23b4:
    // 0x1e23b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e23b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e23b8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e23b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e23bc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e23bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e23c0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e23c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e23c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e23c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e23c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e23c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e23cc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e23ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e23d0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e23d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e23d4: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e23d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e23d8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E23D8u;
    {
        const bool branch_taken_0x1e23d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e23d8) {
            ctx->pc = 0x1E23F4u;
            goto label_1e23f4;
        }
    }
    ctx->pc = 0x1E23E0u;
    // 0x1e23e0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e23e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e23e4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e23e4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e23e8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e23e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e23ec: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x1E23ECu;
    {
        const bool branch_taken_0x1e23ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e23ec) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E23F4u;
label_1e23f4:
    // 0x1e23f4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e23f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e23f8: 0x2405002c  addiu       $a1, $zero, 0x2C
    ctx->pc = 0x1e23f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e23fc: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E23FCu;
    SET_GPR_U32(ctx, 31, 0x1E2404u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2404u; }
        if (ctx->pc != 0x1E2404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2404u; }
        if (ctx->pc != 0x1E2404u) { return; }
    }
    ctx->pc = 0x1E2404u;
label_1e2404:
    // 0x1e2404: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2404u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e2408: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2408u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e240c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E240Cu;
    {
        const bool branch_taken_0x1e240c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e240c) {
            ctx->pc = 0x1E2428u;
            goto label_1e2428;
        }
    }
    ctx->pc = 0x1E2414u;
    // 0x1e2414: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2414u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2418: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2418u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e241c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e241cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2420: 0x1000007e  b           . + 4 + (0x7E << 2)
    ctx->pc = 0x1E2420u;
    {
        const bool branch_taken_0x1e2420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2420) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E2428u;
label_1e2428:
    // 0x1e2428: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e2428u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e242c: 0x2405002c  addiu       $a1, $zero, 0x2C
    ctx->pc = 0x1e242cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e2430: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2430u;
    SET_GPR_U32(ctx, 31, 0x1E2438u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2438u; }
        if (ctx->pc != 0x1E2438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2438u; }
        if (ctx->pc != 0x1E2438u) { return; }
    }
    ctx->pc = 0x1E2438u;
label_1e2438:
    // 0x1e2438: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2438u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e243c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e243cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2440: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2440u;
    {
        const bool branch_taken_0x1e2440 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2440) {
            ctx->pc = 0x1E2470u;
            goto label_1e2470;
        }
    }
    ctx->pc = 0x1E2448u;
    // 0x1e2448: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e2448u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e244c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e244cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2450: 0x8fc5001c  lw          $a1, 0x1C($fp)
    ctx->pc = 0x1e2450u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2454: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2454u;
    SET_GPR_U32(ctx, 31, 0x1E245Cu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E245Cu; }
        if (ctx->pc != 0x1E245Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E245Cu; }
        if (ctx->pc != 0x1E245Cu) { return; }
    }
    ctx->pc = 0x1E245Cu;
label_1e245c:
    // 0x1e245c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e245cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2460: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2460u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2464: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2464u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2468: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1E2468u;
    {
        const bool branch_taken_0x1e2468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2468) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E2470u;
label_1e2470:
    // 0x1e2470: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e2470u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2474: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e2474u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2478: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E2478u;
    SET_GPR_U32(ctx, 31, 0x1E2480u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2480u; }
        if (ctx->pc != 0x1E2480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2480u; }
        if (ctx->pc != 0x1E2480u) { return; }
    }
    ctx->pc = 0x1E2480u;
label_1e2480:
    // 0x1e2480: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e2480u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2484: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e2484u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2488: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2488u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e248c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e248cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e2490: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2490u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2494: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e2494u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2498: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2498u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e249c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e249cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e24a0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e24a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e24a4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e24a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e24a8: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e24a8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e24ac: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e24acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e24b0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e24b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e24b4: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e24b4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e24b8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e24b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e24bc: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e24bcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e24c0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e24c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e24c4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e24c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e24c8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e24c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e24cc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e24ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e24d0: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1e24d0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1e24d4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e24d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e24d8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E24D8u;
    {
        const bool branch_taken_0x1e24d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e24d8) {
            ctx->pc = 0x1E2500u;
            goto label_1e2500;
        }
    }
    ctx->pc = 0x1E24E0u;
    // 0x1e24e0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e24e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e24e4: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1e24e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1e24e8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e24e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e24ec: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e24ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e24f0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E24F0u;
    SET_GPR_U32(ctx, 31, 0x1E24F8u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E24F8u; }
        if (ctx->pc != 0x1E24F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E24F8u; }
        if (ctx->pc != 0x1E24F8u) { return; }
    }
    ctx->pc = 0x1E24F8u;
label_1e24f8:
    // 0x1e24f8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1E24F8u;
    {
        const bool branch_taken_0x1e24f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e24f8) {
            ctx->pc = 0x1E2508u;
            goto label_1e2508;
        }
    }
    ctx->pc = 0x1E2500u;
label_1e2500:
    // 0x1e2500: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2504: 0xa0400014  sb          $zero, 0x14($v0)
    ctx->pc = 0x1e2504u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 20), (uint8_t)GPR_U32(ctx, 0));
label_1e2508:
    // 0x1e2508: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e2508u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e250c: 0x97c2000e  lhu         $v0, 0xE($fp)
    ctx->pc = 0x1e250cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e2510: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2510u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2514: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e2514u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e2518: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2518u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e251c: 0x97c2000e  lhu         $v0, 0xE($fp)
    ctx->pc = 0x1e251cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e2520: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2520u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2524: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e2524u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e2528: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2528u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e252c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e252cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2530: 0x97c3000e  lhu         $v1, 0xE($fp)
    ctx->pc = 0x1e2530u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e2534: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2534u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2538: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2538u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e253c: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e253cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e2540: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2540u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2544: 0x97c3000e  lhu         $v1, 0xE($fp)
    ctx->pc = 0x1e2544u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e2548: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2548u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e254c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e254cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2550: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e2550u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2554: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2554u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2558: 0xaca20024  sw          $v0, 0x24($a1)
    ctx->pc = 0x1e2558u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 2));
    // 0x1e255c: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e255cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2560: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2560u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2564: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2564u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2568: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2568u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e256c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e256cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2570: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2570u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2574: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2574u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2578: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2578u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e257c: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e257cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2580: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2580u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2584: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2584u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2588: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e2588u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e258c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e258cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2590: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e2590u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2594: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2594u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2598: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2598u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e259c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e259cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e25a0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e25a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e25a4: 0xaca20028  sw          $v0, 0x28($a1)
    ctx->pc = 0x1e25a4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 40), GPR_U32(ctx, 2));
    // 0x1e25a8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e25a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e25ac: 0x90420616  lbu         $v0, 0x616($v0)
    ctx->pc = 0x1e25acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1558)));
    // 0x1e25b0: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e25b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e25b4: 0x8fc5001c  lw          $a1, 0x1C($fp)
    ctx->pc = 0x1e25b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e25b8: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e25b8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e25bc: 0x2407002c  addiu       $a3, $zero, 0x2C
    ctx->pc = 0x1e25bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e25c0: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x1e25c0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e25c4: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e25c4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e25c8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E25C8u;
    SET_GPR_U32(ctx, 31, 0x1E25D0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E25D0u; }
        if (ctx->pc != 0x1E25D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E25D0u; }
        if (ctx->pc != 0x1E25D0u) { return; }
    }
    ctx->pc = 0x1E25D0u;
label_1e25d0:
    // 0x1e25d0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E25D0u;
    {
        const bool branch_taken_0x1e25d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e25d0) {
            ctx->pc = 0x1E25ECu;
            goto label_1e25ec;
        }
    }
    ctx->pc = 0x1E25D8u;
    // 0x1e25d8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e25d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e25dc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e25dcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e25e0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e25e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e25e4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E25E4u;
    {
        const bool branch_taken_0x1e25e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e25e4) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E25ECu;
label_1e25ec:
    // 0x1e25ec: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e25ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e25f0: 0x2405001f  addiu       $a1, $zero, 0x1F
    ctx->pc = 0x1e25f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1e25f4: 0x8fc60014  lw          $a2, 0x14($fp)
    ctx->pc = 0x1e25f4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e25f8: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E25F8u;
    SET_GPR_U32(ctx, 31, 0x1E2600u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2600u; }
        if (ctx->pc != 0x1E2600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2600u; }
        if (ctx->pc != 0x1E2600u) { return; }
    }
    ctx->pc = 0x1E2600u;
label_1e2600:
    // 0x1e2600: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e2600u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e2604: 0x90640616  lbu         $a0, 0x616($v1)
    ctx->pc = 0x1e2604u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1558)));
    // 0x1e2608: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2608u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e260c: 0xa0620616  sb          $v0, 0x616($v1)
    ctx->pc = 0x1e260cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1558), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2610: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2610u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2614: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e2614u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e2618: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e2618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
label_1e261c:
    // 0x1e261c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e261cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2620: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e2620u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e2624: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e2624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e2628: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e2628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e262c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E262Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2634u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
