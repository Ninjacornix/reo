#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AA4C0
// Address: 0x1aa4c0 - 0x1aaad0
void sub_001AA4C0_0x1aa4c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AA4C0_0x1aa4c0");
#endif

    switch (ctx->pc) {
        case 0x1aa50cu: goto label_1aa50c;
        case 0x1aa518u: goto label_1aa518;
        case 0x1aa52cu: goto label_1aa52c;
        case 0x1aa584u: goto label_1aa584;
        case 0x1aa598u: goto label_1aa598;
        case 0x1aa5a4u: goto label_1aa5a4;
        case 0x1aa5b0u: goto label_1aa5b0;
        case 0x1aa5ccu: goto label_1aa5cc;
        case 0x1aa5e0u: goto label_1aa5e0;
        case 0x1aa5f4u: goto label_1aa5f4;
        case 0x1aa61cu: goto label_1aa61c;
        case 0x1aa624u: goto label_1aa624;
        case 0x1aa638u: goto label_1aa638;
        case 0x1aa67cu: goto label_1aa67c;
        case 0x1aa688u: goto label_1aa688;
        case 0x1aa694u: goto label_1aa694;
        case 0x1aa6a0u: goto label_1aa6a0;
        case 0x1aa6acu: goto label_1aa6ac;
        case 0x1aa6b8u: goto label_1aa6b8;
        case 0x1aa6c4u: goto label_1aa6c4;
        case 0x1aa6d0u: goto label_1aa6d0;
        case 0x1aa6e4u: goto label_1aa6e4;
        case 0x1aa70cu: goto label_1aa70c;
        case 0x1aa7d0u: goto label_1aa7d0;
        case 0x1aa7fcu: goto label_1aa7fc;
        case 0x1aa818u: goto label_1aa818;
        case 0x1aa858u: goto label_1aa858;
        case 0x1aa880u: goto label_1aa880;
        case 0x1aa8a4u: goto label_1aa8a4;
        case 0x1aa8b0u: goto label_1aa8b0;
        case 0x1aa8c4u: goto label_1aa8c4;
        case 0x1aa8ecu: goto label_1aa8ec;
        case 0x1aa914u: goto label_1aa914;
        case 0x1aa924u: goto label_1aa924;
        case 0x1aa930u: goto label_1aa930;
        case 0x1aa954u: goto label_1aa954;
        case 0x1aa980u: goto label_1aa980;
        case 0x1aa9b4u: goto label_1aa9b4;
        case 0x1aa9bcu: goto label_1aa9bc;
        case 0x1aa9c8u: goto label_1aa9c8;
        case 0x1aaa18u: goto label_1aaa18;
        case 0x1aaa54u: goto label_1aaa54;
        case 0x1aaaa4u: goto label_1aaaa4;
        default: break;
    }

    ctx->pc = 0x1aa4c0u;

    // 0x1aa4c0: 0x27bdfe30  addiu       $sp, $sp, -0x1D0
    ctx->pc = 0x1aa4c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966832));
    // 0x1aa4c4: 0x30a700ff  andi        $a3, $a1, 0xFF
    ctx->pc = 0x1aa4c4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1aa4c8: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1aa4c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1aa4cc: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1aa4ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1aa4d0: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1aa4d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1aa4d4: 0x30c800ff  andi        $t0, $a2, 0xFF
    ctx->pc = 0x1aa4d4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1aa4d8: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1aa4d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1aa4dc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa4dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa4e0: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1aa4e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1aa4e4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aa4e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aa4e8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1aa4e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1aa4ec: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1aa4ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1aa4f0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1aa4f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1aa4f4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1aa4f4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa4f8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aa4f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aa4fc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aa4fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aa500: 0x8c34440c  lw          $s4, 0x440C($at)
    ctx->pc = 0x1aa500u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1aa504: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA504u;
    SET_GPR_U32(ctx, 31, 0x1AA50Cu);
    ctx->pc = 0x1AA508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA504u;
            // 0x1aa508: 0x24a5d010  addiu       $a1, $a1, -0x2FF0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA50Cu; }
        if (ctx->pc != 0x1AA50Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA50Cu; }
        if (ctx->pc != 0x1AA50Cu) { return; }
    }
    ctx->pc = 0x1AA50Cu;
label_1aa50c:
    // 0x1aa50c: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1aa50cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1aa510: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1AA510u;
    SET_GPR_U32(ctx, 31, 0x1AA518u);
    ctx->pc = 0x1AA514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA510u;
            // 0x1aa514: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA518u; }
        if (ctx->pc != 0x1AA518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA518u; }
        if (ctx->pc != 0x1AA518u) { return; }
    }
    ctx->pc = 0x1AA518u;
label_1aa518:
    // 0x1aa518: 0x1840007c  blez        $v0, . + 4 + (0x7C << 2)
    ctx->pc = 0x1AA518u;
    {
        const bool branch_taken_0x1aa518 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1AA51Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA518u;
            // 0x1aa51c: 0x27a40180  addiu       $a0, $sp, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa518) {
            ctx->pc = 0x1AA70Cu;
            goto label_1aa70c;
        }
    }
    ctx->pc = 0x1AA520u;
    // 0x1aa520: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1aa520u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa524: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AA524u;
    SET_GPR_U32(ctx, 31, 0x1AA52Cu);
    ctx->pc = 0x1AA528u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA524u;
            // 0x1aa528: 0x24060050  addiu       $a2, $zero, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA52Cu; }
        if (ctx->pc != 0x1AA52Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA52Cu; }
        if (ctx->pc != 0x1AA52Cu) { return; }
    }
    ctx->pc = 0x1AA52Cu;
label_1aa52c:
    // 0x1aa52c: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1aa52cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1aa530: 0x3c030018  lui         $v1, 0x18
    ctx->pc = 0x1aa530u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)24 << 16));
    // 0x1aa534: 0x902597b8  lbu         $a1, -0x6848($at)
    ctx->pc = 0x1aa534u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1aa538: 0x27a60184  addiu       $a2, $sp, 0x184
    ctx->pc = 0x1aa538u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 388));
    // 0x1aa53c: 0x3c02000c  lui         $v0, 0xC
    ctx->pc = 0x1aa53cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)12 << 16));
    // 0x1aa540: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x1aa540u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa544: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aa544u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aa548: 0x38a50001  xori        $a1, $a1, 0x1
    ctx->pc = 0x1aa548u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)1);
    // 0x1aa54c: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1aa54cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1aa550: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1aa550u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1aa554: 0x839821  addu        $s3, $a0, $v1
    ctx->pc = 0x1aa554u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1aa558: 0xa02597b8  sb          $a1, -0x6848($at)
    ctx->pc = 0x1aa558u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294940600), (uint8_t)GPR_U32(ctx, 5));
    // 0x1aa55c: 0x2629021  addu        $s2, $s3, $v0
    ctx->pc = 0x1aa55cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1aa560: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1aa560u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1aa564: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1aa564u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1aa568: 0x902297b8  lbu         $v0, -0x6848($at)
    ctx->pc = 0x1aa568u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1aa56c: 0x2838821  addu        $s1, $s4, $v1
    ctx->pc = 0x1aa56cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1aa570: 0x8e360000  lw          $s6, 0x0($s1)
    ctx->pc = 0x1aa570u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1aa574: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x1aa574u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x1aa578: 0x24501800  addiu       $s0, $v0, 0x1800
    ctx->pc = 0x1aa578u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 6144));
    // 0x1aa57c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1AA57Cu;
    {
        const bool branch_taken_0x1aa57c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA57Cu;
            // 0x1aa580: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa57c) {
            ctx->pc = 0x1AA5B8u;
            goto label_1aa5b8;
        }
    }
    ctx->pc = 0x1AA584u;
label_1aa584:
    // 0x1aa584: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x1aa584u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1aa588: 0x8c2416a0  lw          $a0, 0x16A0($at)
    ctx->pc = 0x1aa588u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa58c: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1aa58cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa590: 0xc06a810  jal         func_1AA040
    ctx->pc = 0x1AA590u;
    SET_GPR_U32(ctx, 31, 0x1AA598u);
    ctx->pc = 0x1AA594u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA590u;
            // 0x1aa594: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA040u;
    if (runtime->hasFunction(0x1AA040u)) {
        auto targetFn = runtime->lookupFunction(0x1AA040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA598u; }
        if (ctx->pc != 0x1AA598u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA040_0x1aa040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA598u; }
        if (ctx->pc != 0x1AA598u) { return; }
    }
    ctx->pc = 0x1AA598u;
label_1aa598:
    // 0x1aa598: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1aa598u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa59c: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1AA59Cu;
    SET_GPR_U32(ctx, 31, 0x1AA5A4u);
    ctx->pc = 0x1AA5A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA59Cu;
            // 0x1aa5a0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5A4u; }
        if (ctx->pc != 0x1AA5A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5A4u; }
        if (ctx->pc != 0x1AA5A4u) { return; }
    }
    ctx->pc = 0x1AA5A4u;
label_1aa5a4:
    // 0x1aa5a4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1aa5a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa5a8: 0xc0733f4  jal         func_1CCFD0
    ctx->pc = 0x1AA5A8u;
    SET_GPR_U32(ctx, 31, 0x1AA5B0u);
    ctx->pc = 0x1AA5ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA5A8u;
            // 0x1aa5ac: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCFD0u;
    if (runtime->hasFunction(0x1CCFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1CCFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5B0u; }
        if (ctx->pc != 0x1AA5B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCFD0_0x1ccfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5B0u; }
        if (ctx->pc != 0x1AA5B0u) { return; }
    }
    ctx->pc = 0x1AA5B0u;
label_1aa5b0:
    // 0x1aa5b0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1aa5b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1aa5b4: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x1aa5b4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
label_1aa5b8:
    // 0x1aa5b8: 0x2b6102a  slt         $v0, $s5, $s6
    ctx->pc = 0x1aa5b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x1aa5bc: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
    ctx->pc = 0x1AA5BCu;
    {
        const bool branch_taken_0x1aa5bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AA5C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA5BCu;
            // 0x1aa5c0: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa5bc) {
            ctx->pc = 0x1AA584u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aa584;
        }
    }
    ctx->pc = 0x1AA5C4u;
    // 0x1aa5c4: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1AA5C4u;
    SET_GPR_U32(ctx, 31, 0x1AA5CCu);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5CCu; }
        if (ctx->pc != 0x1AA5CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5CCu; }
        if (ctx->pc != 0x1AA5CCu) { return; }
    }
    ctx->pc = 0x1AA5CCu;
label_1aa5cc:
    // 0x1aa5cc: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1aa5ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1aa5d0: 0x902297b8  lbu         $v0, -0x6848($at)
    ctx->pc = 0x1aa5d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1aa5d4: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x1aa5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x1aa5d8: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1AA5D8u;
    SET_GPR_U32(ctx, 31, 0x1AA5E0u);
    ctx->pc = 0x1AA5DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA5D8u;
            // 0x1aa5dc: 0x24441800  addiu       $a0, $v0, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 6144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5E0u; }
        if (ctx->pc != 0x1AA5E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5E0u; }
        if (ctx->pc != 0x1AA5E0u) { return; }
    }
    ctx->pc = 0x1AA5E0u;
label_1aa5e0:
    // 0x1aa5e0: 0x3c10004a  lui         $s0, 0x4A
    ctx->pc = 0x1aa5e0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)74 << 16));
    // 0x1aa5e4: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x1aa5e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1aa5e8: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1aa5e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1aa5ec: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1AA5ECu;
    SET_GPR_U32(ctx, 31, 0x1AA5F4u);
    ctx->pc = 0x1AA5F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA5ECu;
            // 0x1aa5f0: 0x2610ef50  addiu       $s0, $s0, -0x10B0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5F4u; }
        if (ctx->pc != 0x1AA5F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA5F4u; }
        if (ctx->pc != 0x1AA5F4u) { return; }
    }
    ctx->pc = 0x1AA5F4u;
label_1aa5f4:
    // 0x1aa5f4: 0xae020808  sw          $v0, 0x808($s0)
    ctx->pc = 0x1aa5f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2056), GPR_U32(ctx, 2));
    // 0x1aa5f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1aa5f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa5fc: 0xae000818  sw          $zero, 0x818($s0)
    ctx->pc = 0x1aa5fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2072), GPR_U32(ctx, 0));
    // 0x1aa600: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1aa600u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1aa604: 0x8fa30194  lw          $v1, 0x194($sp)
    ctx->pc = 0x1aa604u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 404)));
    // 0x1aa608: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1aa608u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa60c: 0x8fa201a4  lw          $v0, 0x1A4($sp)
    ctx->pc = 0x1aa60cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 420)));
    // 0x1aa610: 0x2833021  addu        $a2, $s4, $v1
    ctx->pc = 0x1aa610u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1aa614: 0xc073d58  jal         func_1CF560
    ctx->pc = 0x1AA614u;
    SET_GPR_U32(ctx, 31, 0x1AA61Cu);
    ctx->pc = 0x1AA618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA614u;
            // 0x1aa618: 0x2823821  addu        $a3, $s4, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF560u;
    if (runtime->hasFunction(0x1CF560u)) {
        auto targetFn = runtime->lookupFunction(0x1CF560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA61Cu; }
        if (ctx->pc != 0x1AA61Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF560_0x1cf560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA61Cu; }
        if (ctx->pc != 0x1AA61Cu) { return; }
    }
    ctx->pc = 0x1AA61Cu;
label_1aa61c:
    // 0x1aa61c: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1AA61Cu;
    SET_GPR_U32(ctx, 31, 0x1AA624u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA624u; }
        if (ctx->pc != 0x1AA624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA624u; }
        if (ctx->pc != 0x1AA624u) { return; }
    }
    ctx->pc = 0x1AA624u;
label_1aa624:
    // 0x1aa624: 0x3c04004a  lui         $a0, 0x4A
    ctx->pc = 0x1aa624u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)74 << 16));
    // 0x1aa628: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1aa628u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa62c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1aa62cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aa630: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AA630u;
    {
        const bool branch_taken_0x1aa630 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA630u;
            // 0x1aa634: 0x2484eef0  addiu       $a0, $a0, -0x1110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962928));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa630) {
            ctx->pc = 0x1AA644u;
            goto label_1aa644;
        }
    }
    ctx->pc = 0x1AA638u;
label_1aa638:
    // 0x1aa638: 0x861821  addu        $v1, $a0, $a2
    ctx->pc = 0x1aa638u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1aa63c: 0xa06508a0  sb          $a1, 0x8A0($v1)
    ctx->pc = 0x1aa63cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 2208), (uint8_t)GPR_U32(ctx, 5));
    // 0x1aa640: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1aa640u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1aa644:
    // 0x1aa644: 0x96030812  lhu         $v1, 0x812($s0)
    ctx->pc = 0x1aa644u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2066)));
    // 0x1aa648: 0xc3182a  slt         $v1, $a2, $v1
    ctx->pc = 0x1aa648u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1aa64c: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AA64Cu;
    {
        const bool branch_taken_0x1aa64c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aa64c) {
            ctx->pc = 0x1AA638u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aa638;
        }
    }
    ctx->pc = 0x1AA654u;
    // 0x1aa654: 0x27b001b4  addiu       $s0, $sp, 0x1B4
    ctx->pc = 0x1aa654u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 436));
    // 0x1aa658: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1aa658u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aa65c: 0x1060002b  beqz        $v1, . + 4 + (0x2B << 2)
    ctx->pc = 0x1AA65Cu;
    {
        const bool branch_taken_0x1aa65c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA65Cu;
            // 0x1aa660: 0x3c010057  lui         $at, 0x57 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa65c) {
            ctx->pc = 0x1AA70Cu;
            goto label_1aa70c;
        }
    }
    ctx->pc = 0x1AA664u;
    // 0x1aa664: 0x902397b8  lbu         $v1, -0x6848($at)
    ctx->pc = 0x1aa664u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1aa668: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1aa668u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1aa66c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1aa66cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1aa670: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1aa670u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1aa674: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1AA674u;
    SET_GPR_U32(ctx, 31, 0x1AA67Cu);
    ctx->pc = 0x1AA678u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA674u;
            // 0x1aa678: 0x24442100  addiu       $a0, $v0, 0x2100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 8448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA67Cu; }
        if (ctx->pc != 0x1AA67Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA67Cu; }
        if (ctx->pc != 0x1AA67Cu) { return; }
    }
    ctx->pc = 0x1AA67Cu;
label_1aa67c:
    // 0x1aa67c: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1aa67cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1aa680: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AA680u;
    SET_GPR_U32(ctx, 31, 0x1AA688u);
    ctx->pc = 0x1AA684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA680u;
            // 0x1aa684: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA688u; }
        if (ctx->pc != 0x1AA688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA688u; }
        if (ctx->pc != 0x1AA688u) { return; }
    }
    ctx->pc = 0x1AA688u;
label_1aa688:
    // 0x1aa688: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1aa688u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aa68c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AA68Cu;
    SET_GPR_U32(ctx, 31, 0x1AA694u);
    ctx->pc = 0x1AA690u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA68Cu;
            // 0x1aa690: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA694u; }
        if (ctx->pc != 0x1AA694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA694u; }
        if (ctx->pc != 0x1AA694u) { return; }
    }
    ctx->pc = 0x1AA694u;
label_1aa694:
    // 0x1aa694: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1aa694u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1aa698: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AA698u;
    SET_GPR_U32(ctx, 31, 0x1AA6A0u);
    ctx->pc = 0x1AA69Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA698u;
            // 0x1aa69c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6A0u; }
        if (ctx->pc != 0x1AA6A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6A0u; }
        if (ctx->pc != 0x1AA6A0u) { return; }
    }
    ctx->pc = 0x1AA6A0u;
label_1aa6a0:
    // 0x1aa6a0: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1aa6a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1aa6a4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AA6A4u;
    SET_GPR_U32(ctx, 31, 0x1AA6ACu);
    ctx->pc = 0x1AA6A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA6A4u;
            // 0x1aa6a8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6ACu; }
        if (ctx->pc != 0x1AA6ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6ACu; }
        if (ctx->pc != 0x1AA6ACu) { return; }
    }
    ctx->pc = 0x1AA6ACu;
label_1aa6ac:
    // 0x1aa6ac: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1aa6acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1aa6b0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AA6B0u;
    SET_GPR_U32(ctx, 31, 0x1AA6B8u);
    ctx->pc = 0x1AA6B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA6B0u;
            // 0x1aa6b4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6B8u; }
        if (ctx->pc != 0x1AA6B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6B8u; }
        if (ctx->pc != 0x1AA6B8u) { return; }
    }
    ctx->pc = 0x1AA6B8u;
label_1aa6b8:
    // 0x1aa6b8: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1aa6b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1aa6bc: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AA6BCu;
    SET_GPR_U32(ctx, 31, 0x1AA6C4u);
    ctx->pc = 0x1AA6C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA6BCu;
            // 0x1aa6c0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6C4u; }
        if (ctx->pc != 0x1AA6C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6C4u; }
        if (ctx->pc != 0x1AA6C4u) { return; }
    }
    ctx->pc = 0x1AA6C4u;
label_1aa6c4:
    // 0x1aa6c4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1aa6c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1aa6c8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AA6C8u;
    SET_GPR_U32(ctx, 31, 0x1AA6D0u);
    ctx->pc = 0x1AA6CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA6C8u;
            // 0x1aa6cc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6D0u; }
        if (ctx->pc != 0x1AA6D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6D0u; }
        if (ctx->pc != 0x1AA6D0u) { return; }
    }
    ctx->pc = 0x1AA6D0u;
label_1aa6d0:
    // 0x1aa6d0: 0x3c11003c  lui         $s1, 0x3C
    ctx->pc = 0x1aa6d0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)60 << 16));
    // 0x1aa6d4: 0x24040400  addiu       $a0, $zero, 0x400
    ctx->pc = 0x1aa6d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1aa6d8: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x1aa6d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1aa6dc: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1AA6DCu;
    SET_GPR_U32(ctx, 31, 0x1AA6E4u);
    ctx->pc = 0x1AA6E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA6DCu;
            // 0x1aa6e0: 0x2631d5d4  addiu       $s1, $s1, -0x2A2C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294956500));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6E4u; }
        if (ctx->pc != 0x1AA6E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA6E4u; }
        if (ctx->pc != 0x1AA6E4u) { return; }
    }
    ctx->pc = 0x1AA6E4u;
label_1aa6e4:
    // 0x1aa6e4: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1aa6e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1aa6e8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1aa6e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa6ec: 0xae200818  sw          $zero, 0x818($s1)
    ctx->pc = 0x1aa6ecu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 0));
    // 0x1aa6f0: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1aa6f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1aa6f4: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1aa6f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aa6f8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1aa6f8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa6fc: 0x8fa201c4  lw          $v0, 0x1C4($sp)
    ctx->pc = 0x1aa6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 452)));
    // 0x1aa700: 0x2833021  addu        $a2, $s4, $v1
    ctx->pc = 0x1aa700u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1aa704: 0xc073d58  jal         func_1CF560
    ctx->pc = 0x1AA704u;
    SET_GPR_U32(ctx, 31, 0x1AA70Cu);
    ctx->pc = 0x1AA708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA704u;
            // 0x1aa708: 0x2823821  addu        $a3, $s4, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF560u;
    if (runtime->hasFunction(0x1CF560u)) {
        auto targetFn = runtime->lookupFunction(0x1CF560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA70Cu; }
        if (ctx->pc != 0x1AA70Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF560_0x1cf560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA70Cu; }
        if (ctx->pc != 0x1AA70Cu) { return; }
    }
    ctx->pc = 0x1AA70Cu;
label_1aa70c:
    // 0x1aa70c: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1aa70cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1aa710: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1aa710u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1aa714: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1aa714u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1aa718: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1aa718u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1aa71c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1aa71cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1aa720: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1aa720u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aa724: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aa724u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aa728: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aa728u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aa72c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AA72Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AA730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA72Cu;
            // 0x1aa730: 0x27bd01d0  addiu       $sp, $sp, 0x1D0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 464));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AA50Cu: goto label_1aa50c;
            case 0x1AA518u: goto label_1aa518;
            case 0x1AA52Cu: goto label_1aa52c;
            case 0x1AA584u: goto label_1aa584;
            case 0x1AA598u: goto label_1aa598;
            case 0x1AA5A4u: goto label_1aa5a4;
            case 0x1AA5B0u: goto label_1aa5b0;
            case 0x1AA5B8u: goto label_1aa5b8;
            case 0x1AA5CCu: goto label_1aa5cc;
            case 0x1AA5E0u: goto label_1aa5e0;
            case 0x1AA5F4u: goto label_1aa5f4;
            case 0x1AA61Cu: goto label_1aa61c;
            case 0x1AA624u: goto label_1aa624;
            case 0x1AA638u: goto label_1aa638;
            case 0x1AA644u: goto label_1aa644;
            case 0x1AA67Cu: goto label_1aa67c;
            case 0x1AA688u: goto label_1aa688;
            case 0x1AA694u: goto label_1aa694;
            case 0x1AA6A0u: goto label_1aa6a0;
            case 0x1AA6ACu: goto label_1aa6ac;
            case 0x1AA6B8u: goto label_1aa6b8;
            case 0x1AA6C4u: goto label_1aa6c4;
            case 0x1AA6D0u: goto label_1aa6d0;
            case 0x1AA6E4u: goto label_1aa6e4;
            case 0x1AA70Cu: goto label_1aa70c;
            case 0x1AA78Cu: goto label_1aa78c;
            case 0x1AA7B4u: goto label_1aa7b4;
            case 0x1AA7D0u: goto label_1aa7d0;
            case 0x1AA7D8u: goto label_1aa7d8;
            case 0x1AA7FCu: goto label_1aa7fc;
            case 0x1AA804u: goto label_1aa804;
            case 0x1AA818u: goto label_1aa818;
            case 0x1AA820u: goto label_1aa820;
            case 0x1AA83Cu: goto label_1aa83c;
            case 0x1AA858u: goto label_1aa858;
            case 0x1AA860u: goto label_1aa860;
            case 0x1AA880u: goto label_1aa880;
            case 0x1AA888u: goto label_1aa888;
            case 0x1AA8A4u: goto label_1aa8a4;
            case 0x1AA8A8u: goto label_1aa8a8;
            case 0x1AA8B0u: goto label_1aa8b0;
            case 0x1AA8C4u: goto label_1aa8c4;
            case 0x1AA8E0u: goto label_1aa8e0;
            case 0x1AA8E4u: goto label_1aa8e4;
            case 0x1AA8ECu: goto label_1aa8ec;
            case 0x1AA914u: goto label_1aa914;
            case 0x1AA924u: goto label_1aa924;
            case 0x1AA930u: goto label_1aa930;
            case 0x1AA940u: goto label_1aa940;
            case 0x1AA954u: goto label_1aa954;
            case 0x1AA980u: goto label_1aa980;
            case 0x1AA9B4u: goto label_1aa9b4;
            case 0x1AA9BCu: goto label_1aa9bc;
            case 0x1AA9C8u: goto label_1aa9c8;
            case 0x1AAA18u: goto label_1aaa18;
            case 0x1AAA2Cu: goto label_1aaa2c;
            case 0x1AAA54u: goto label_1aaa54;
            case 0x1AAAA4u: goto label_1aaaa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AA734u;
    // 0x1aa734: 0x0  nop
    ctx->pc = 0x1aa734u;
    // NOP
    // 0x1aa738: 0x0  nop
    ctx->pc = 0x1aa738u;
    // NOP
    // 0x1aa73c: 0x0  nop
    ctx->pc = 0x1aa73cu;
    // NOP
    // 0x1aa740: 0x27bdfdf0  addiu       $sp, $sp, -0x210
    ctx->pc = 0x1aa740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966768));
    // 0x1aa744: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1aa744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1aa748: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1aa748u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1aa74c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1aa74cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1aa750: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1aa750u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1aa754: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1aa754u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1aa758: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1aa758u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa75c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1aa75cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1aa760: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1aa760u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1aa764: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aa764u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aa768: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aa768u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aa76c: 0x90a20003  lbu         $v0, 0x3($a1)
    ctx->pc = 0x1aa76cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 3)));
    // 0x1aa770: 0x28420014  slti        $v0, $v0, 0x14
    ctx->pc = 0x1aa770u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1aa774: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AA774u;
    {
        const bool branch_taken_0x1aa774 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AA778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA774u;
            // 0x1aa778: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa774) {
            ctx->pc = 0x1AA78Cu;
            goto label_1aa78c;
        }
    }
    ctx->pc = 0x1AA77Cu;
    // 0x1aa77c: 0x8ea20034  lw          $v0, 0x34($s5)
    ctx->pc = 0x1aa77cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 52)));
    // 0x1aa780: 0xac401460  sw          $zero, 0x1460($v0)
    ctx->pc = 0x1aa780u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 5216), GPR_U32(ctx, 0));
    // 0x1aa784: 0x8ea20034  lw          $v0, 0x34($s5)
    ctx->pc = 0x1aa784u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 52)));
    // 0x1aa788: 0xac401464  sw          $zero, 0x1464($v0)
    ctx->pc = 0x1aa788u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 5220), GPR_U32(ctx, 0));
label_1aa78c:
    // 0x1aa78c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aa78cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aa790: 0x96a40bb4  lhu         $a0, 0xBB4($s5)
    ctx->pc = 0x1aa790u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 2996)));
    // 0x1aa794: 0x10800022  beqz        $a0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1AA794u;
    {
        const bool branch_taken_0x1aa794 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA794u;
            // 0x1aa798: 0x8c33440c  lw          $s3, 0x440C($at) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa794) {
            ctx->pc = 0x1AA820u;
            goto label_1aa820;
        }
    }
    ctx->pc = 0x1AA79Cu;
    // 0x1aa79c: 0x92a3054d  lbu         $v1, 0x54D($s5)
    ctx->pc = 0x1aa79cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 1357)));
    // 0x1aa7a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1aa7a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aa7a4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AA7A4u;
    {
        const bool branch_taken_0x1aa7a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1aa7a4) {
            ctx->pc = 0x1AA7B4u;
            goto label_1aa7b4;
        }
    }
    ctx->pc = 0x1AA7ACu;
    // 0x1aa7ac: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1AA7ACu;
    {
        const bool branch_taken_0x1aa7ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA7ACu;
            // 0x1aa7b0: 0x2487ffff  addiu       $a3, $a0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa7ac) {
            ctx->pc = 0x1AA7D8u;
            goto label_1aa7d8;
        }
    }
    ctx->pc = 0x1AA7B4u;
label_1aa7b4:
    // 0x1aa7b4: 0x92a70b98  lbu         $a3, 0xB98($s5)
    ctx->pc = 0x1aa7b4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2968)));
    // 0x1aa7b8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa7b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa7bc: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aa7bcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aa7c0: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1aa7c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1aa7c4: 0x24a5d030  addiu       $a1, $a1, -0x2FD0
    ctx->pc = 0x1aa7c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955056));
    // 0x1aa7c8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA7C8u;
    SET_GPR_U32(ctx, 31, 0x1AA7D0u);
    ctx->pc = 0x1AA7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA7C8u;
            // 0x1aa7cc: 0x24c6d040  addiu       $a2, $a2, -0x2FC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA7D0u; }
        if (ctx->pc != 0x1AA7D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA7D0u; }
        if (ctx->pc != 0x1AA7D0u) { return; }
    }
    ctx->pc = 0x1AA7D0u;
label_1aa7d0:
    // 0x1aa7d0: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1AA7D0u;
    {
        const bool branch_taken_0x1aa7d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA7D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA7D0u;
            // 0x1aa7d4: 0x27a40090  addiu       $a0, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa7d0) {
            ctx->pc = 0x1AA8A8u;
            goto label_1aa8a8;
        }
    }
    ctx->pc = 0x1AA7D8u;
label_1aa7d8:
    // 0x1aa7d8: 0x28e1000a  slti        $at, $a3, 0xA
    ctx->pc = 0x1aa7d8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1aa7dc: 0x10200009  beqz        $at, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AA7DCu;
    {
        const bool branch_taken_0x1aa7dc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA7E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA7DCu;
            // 0x1aa7e0: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa7dc) {
            ctx->pc = 0x1AA804u;
            goto label_1aa804;
        }
    }
    ctx->pc = 0x1AA7E4u;
    // 0x1aa7e4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa7e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa7e8: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aa7e8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aa7ec: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1aa7ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1aa7f0: 0x24a5d050  addiu       $a1, $a1, -0x2FB0
    ctx->pc = 0x1aa7f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955088));
    // 0x1aa7f4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA7F4u;
    SET_GPR_U32(ctx, 31, 0x1AA7FCu);
    ctx->pc = 0x1AA7F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA7F4u;
            // 0x1aa7f8: 0x24c6d040  addiu       $a2, $a2, -0x2FC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA7FCu; }
        if (ctx->pc != 0x1AA7FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA7FCu; }
        if (ctx->pc != 0x1AA7FCu) { return; }
    }
    ctx->pc = 0x1AA7FCu;
label_1aa7fc:
    // 0x1aa7fc: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1AA7FCu;
    {
        const bool branch_taken_0x1aa7fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa7fc) {
            ctx->pc = 0x1AA8A4u;
            goto label_1aa8a4;
        }
    }
    ctx->pc = 0x1AA804u;
label_1aa804:
    // 0x1aa804: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aa804u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aa808: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1aa808u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1aa80c: 0x24a5d060  addiu       $a1, $a1, -0x2FA0
    ctx->pc = 0x1aa80cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955104));
    // 0x1aa810: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA810u;
    SET_GPR_U32(ctx, 31, 0x1AA818u);
    ctx->pc = 0x1AA814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA810u;
            // 0x1aa814: 0x24c6d040  addiu       $a2, $a2, -0x2FC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA818u; }
        if (ctx->pc != 0x1AA818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA818u; }
        if (ctx->pc != 0x1AA818u) { return; }
    }
    ctx->pc = 0x1AA818u;
label_1aa818:
    // 0x1aa818: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1AA818u;
    {
        const bool branch_taken_0x1aa818 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa818) {
            ctx->pc = 0x1AA8A4u;
            goto label_1aa8a4;
        }
    }
    ctx->pc = 0x1AA820u;
label_1aa820:
    // 0x1aa820: 0x92a3054d  lbu         $v1, 0x54D($s5)
    ctx->pc = 0x1aa820u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 1357)));
    // 0x1aa824: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1AA824u;
    {
        const bool branch_taken_0x1aa824 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA824u;
            // 0x1aa828: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa824) {
            ctx->pc = 0x1AA860u;
            goto label_1aa860;
        }
    }
    ctx->pc = 0x1AA82Cu;
    // 0x1aa82c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AA82Cu;
    {
        const bool branch_taken_0x1aa82c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1aa82c) {
            ctx->pc = 0x1AA83Cu;
            goto label_1aa83c;
        }
    }
    ctx->pc = 0x1AA834u;
    // 0x1aa834: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1AA834u;
    {
        const bool branch_taken_0x1aa834 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA834u;
            // 0x1aa838: 0x92a70b98  lbu         $a3, 0xB98($s5) (Delay Slot)
        SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2968)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa834) {
            ctx->pc = 0x1AA888u;
            goto label_1aa888;
        }
    }
    ctx->pc = 0x1AA83Cu;
label_1aa83c:
    // 0x1aa83c: 0x92a70b98  lbu         $a3, 0xB98($s5)
    ctx->pc = 0x1aa83cu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2968)));
    // 0x1aa840: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa840u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa844: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aa844u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aa848: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1aa848u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1aa84c: 0x24a5d030  addiu       $a1, $a1, -0x2FD0
    ctx->pc = 0x1aa84cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955056));
    // 0x1aa850: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA850u;
    SET_GPR_U32(ctx, 31, 0x1AA858u);
    ctx->pc = 0x1AA854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA850u;
            // 0x1aa854: 0x24c6d040  addiu       $a2, $a2, -0x2FC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA858u; }
        if (ctx->pc != 0x1AA858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA858u; }
        if (ctx->pc != 0x1AA858u) { return; }
    }
    ctx->pc = 0x1AA858u;
label_1aa858:
    // 0x1aa858: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1AA858u;
    {
        const bool branch_taken_0x1aa858 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa858) {
            ctx->pc = 0x1AA8A4u;
            goto label_1aa8a4;
        }
    }
    ctx->pc = 0x1AA860u;
label_1aa860:
    // 0x1aa860: 0x92a70b98  lbu         $a3, 0xB98($s5)
    ctx->pc = 0x1aa860u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2968)));
    // 0x1aa864: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa864u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa868: 0x92a80bbc  lbu         $t0, 0xBBC($s5)
    ctx->pc = 0x1aa868u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 3004)));
    // 0x1aa86c: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aa86cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aa870: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1aa870u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1aa874: 0x24a5d070  addiu       $a1, $a1, -0x2F90
    ctx->pc = 0x1aa874u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955120));
    // 0x1aa878: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA878u;
    SET_GPR_U32(ctx, 31, 0x1AA880u);
    ctx->pc = 0x1AA87Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA878u;
            // 0x1aa87c: 0x24c6d040  addiu       $a2, $a2, -0x2FC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA880u; }
        if (ctx->pc != 0x1AA880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA880u; }
        if (ctx->pc != 0x1AA880u) { return; }
    }
    ctx->pc = 0x1AA880u;
label_1aa880:
    // 0x1aa880: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AA880u;
    {
        const bool branch_taken_0x1aa880 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa880) {
            ctx->pc = 0x1AA8A4u;
            goto label_1aa8a4;
        }
    }
    ctx->pc = 0x1AA888u;
label_1aa888:
    // 0x1aa888: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa888u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa88c: 0x92a80bbc  lbu         $t0, 0xBBC($s5)
    ctx->pc = 0x1aa88cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 3004)));
    // 0x1aa890: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aa890u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aa894: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1aa894u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1aa898: 0x24a5d090  addiu       $a1, $a1, -0x2F70
    ctx->pc = 0x1aa898u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955152));
    // 0x1aa89c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA89Cu;
    SET_GPR_U32(ctx, 31, 0x1AA8A4u);
    ctx->pc = 0x1AA8A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA89Cu;
            // 0x1aa8a0: 0x24c6d040  addiu       $a2, $a2, -0x2FC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA8A4u; }
        if (ctx->pc != 0x1AA8A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA8A4u; }
        if (ctx->pc != 0x1AA8A4u) { return; }
    }
    ctx->pc = 0x1AA8A4u;
label_1aa8a4:
    // 0x1aa8a4: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1aa8a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
label_1aa8a8:
    // 0x1aa8a8: 0xc06a920  jal         func_1AA480
    ctx->pc = 0x1AA8A8u;
    SET_GPR_U32(ctx, 31, 0x1AA8B0u);
    ctx->pc = 0x1AA8ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA8A8u;
            // 0x1aa8ac: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA480u;
    if (runtime->hasFunction(0x1AA480u)) {
        auto targetFn = runtime->lookupFunction(0x1AA480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA8B0u; }
        if (ctx->pc != 0x1AA8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA480_0x1aa480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA8B0u; }
        if (ctx->pc != 0x1AA8B0u) { return; }
    }
    ctx->pc = 0x1AA8B0u;
label_1aa8b0:
    // 0x1aa8b0: 0x1840007c  blez        $v0, . + 4 + (0x7C << 2)
    ctx->pc = 0x1AA8B0u;
    {
        const bool branch_taken_0x1aa8b0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1AA8B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA8B0u;
            // 0x1aa8b4: 0x27a40190  addiu       $a0, $sp, 0x190 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa8b0) {
            ctx->pc = 0x1AAAA4u;
            goto label_1aaaa4;
        }
    }
    ctx->pc = 0x1AA8B8u;
    // 0x1aa8b8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1aa8b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa8bc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AA8BCu;
    SET_GPR_U32(ctx, 31, 0x1AA8C4u);
    ctx->pc = 0x1AA8C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA8BCu;
            // 0x1aa8c0: 0x24060080  addiu       $a2, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA8C4u; }
        if (ctx->pc != 0x1AA8C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA8C4u; }
        if (ctx->pc != 0x1AA8C4u) { return; }
    }
    ctx->pc = 0x1AA8C4u;
label_1aa8c4:
    // 0x1aa8c4: 0x92a3054d  lbu         $v1, 0x54D($s5)
    ctx->pc = 0x1aa8c4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 1357)));
    // 0x1aa8c8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1aa8c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aa8cc: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AA8CCu;
    {
        const bool branch_taken_0x1aa8cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1AA8D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA8CCu;
            // 0x1aa8d0: 0x1010c0  sll         $v0, $s0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa8cc) {
            ctx->pc = 0x1AA8E0u;
            goto label_1aa8e0;
        }
    }
    ctx->pc = 0x1AA8D4u;
    // 0x1aa8d4: 0x1010c0  sll         $v0, $s0, 3
    ctx->pc = 0x1aa8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1aa8d8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1AA8D8u;
    {
        const bool branch_taken_0x1aa8d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA8DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA8D8u;
            // 0x1aa8dc: 0x24501100  addiu       $s0, $v0, 0x1100 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4352));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa8d8) {
            ctx->pc = 0x1AA8E4u;
            goto label_1aa8e4;
        }
    }
    ctx->pc = 0x1AA8E0u;
label_1aa8e0:
    // 0x1aa8e0: 0x24501000  addiu       $s0, $v0, 0x1000
    ctx->pc = 0x1aa8e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4096));
label_1aa8e4:
    // 0x1aa8e4: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1AA8E4u;
    SET_GPR_U32(ctx, 31, 0x1AA8ECu);
    ctx->pc = 0x1AA8E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA8E4u;
            // 0x1aa8e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA8ECu; }
        if (ctx->pc != 0x1AA8ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA8ECu; }
        if (ctx->pc != 0x1AA8ECu) { return; }
    }
    ctx->pc = 0x1AA8ECu;
label_1aa8ec:
    // 0x1aa8ec: 0x8fa30194  lw          $v1, 0x194($sp)
    ctx->pc = 0x1aa8ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 404)));
    // 0x1aa8f0: 0x1060006c  beqz        $v1, . + 4 + (0x6C << 2)
    ctx->pc = 0x1AA8F0u;
    {
        const bool branch_taken_0x1aa8f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA8F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA8F0u;
            // 0x1aa8f4: 0x8fb7019c  lw          $s7, 0x19C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 412)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa8f0) {
            ctx->pc = 0x1AAAA4u;
            goto label_1aaaa4;
        }
    }
    ctx->pc = 0x1AA8F8u;
    // 0x1aa8f8: 0x2638821  addu        $s1, $s3, $v1
    ctx->pc = 0x1aa8f8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1aa8fc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aa8fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aa900: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1aa900u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1aa904: 0x3c020018  lui         $v0, 0x18
    ctx->pc = 0x1aa904u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)24 << 16));
    // 0x1aa908: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1aa908u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa90c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1AA90Cu;
    {
        const bool branch_taken_0x1aa90c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA90Cu;
            // 0x1aa910: 0x629021  addu        $s2, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa90c) {
            ctx->pc = 0x1AA940u;
            goto label_1aa940;
        }
    }
    ctx->pc = 0x1AA914u;
label_1aa914:
    // 0x1aa914: 0x8e360000  lw          $s6, 0x0($s1)
    ctx->pc = 0x1aa914u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1aa918: 0x26240004  addiu       $a0, $s1, 0x4
    ctx->pc = 0x1aa918u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x1aa91c: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1AA91Cu;
    SET_GPR_U32(ctx, 31, 0x1AA924u);
    ctx->pc = 0x1AA920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA91Cu;
            // 0x1aa920: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA924u; }
        if (ctx->pc != 0x1AA924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA924u; }
        if (ctx->pc != 0x1AA924u) { return; }
    }
    ctx->pc = 0x1AA924u;
label_1aa924:
    // 0x1aa924: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1aa924u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa928: 0xc0733f4  jal         func_1CCFD0
    ctx->pc = 0x1AA928u;
    SET_GPR_U32(ctx, 31, 0x1AA930u);
    ctx->pc = 0x1AA92Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA928u;
            // 0x1aa92c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCFD0u;
    if (runtime->hasFunction(0x1CCFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1CCFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA930u; }
        if (ctx->pc != 0x1AA930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCFD0_0x1ccfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA930u; }
        if (ctx->pc != 0x1AA930u) { return; }
    }
    ctx->pc = 0x1AA930u;
label_1aa930:
    // 0x1aa930: 0x26220004  addiu       $v0, $s1, 0x4
    ctx->pc = 0x1aa930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x1aa934: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1aa934u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1aa938: 0x568821  addu        $s1, $v0, $s6
    ctx->pc = 0x1aa938u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x1aa93c: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1aa93cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_1aa940:
    // 0x1aa940: 0x297102a  slt         $v0, $s4, $s7
    ctx->pc = 0x1aa940u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 23)) ? 1 : 0);
    // 0x1aa944: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1AA944u;
    {
        const bool branch_taken_0x1aa944 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aa944) {
            ctx->pc = 0x1AA914u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aa914;
        }
    }
    ctx->pc = 0x1AA94Cu;
    // 0x1aa94c: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1AA94Cu;
    SET_GPR_U32(ctx, 31, 0x1AA954u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA954u; }
        if (ctx->pc != 0x1AA954u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA954u; }
        if (ctx->pc != 0x1AA954u) { return; }
    }
    ctx->pc = 0x1AA954u;
label_1aa954:
    // 0x1aa954: 0x27b101a4  addiu       $s1, $sp, 0x1A4
    ctx->pc = 0x1aa954u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 420));
    // 0x1aa958: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1aa958u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1aa95c: 0x10600051  beqz        $v1, . + 4 + (0x51 << 2)
    ctx->pc = 0x1AA95Cu;
    {
        const bool branch_taken_0x1aa95c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA95Cu;
            // 0x1aa960: 0x27b001b4  addiu       $s0, $sp, 0x1B4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 436));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa95c) {
            ctx->pc = 0x1AAAA4u;
            goto label_1aaaa4;
        }
    }
    ctx->pc = 0x1AA964u;
    // 0x1aa964: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1aa964u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aa968: 0x1060004e  beqz        $v1, . + 4 + (0x4E << 2)
    ctx->pc = 0x1AA968u;
    {
        const bool branch_taken_0x1aa968 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa968) {
            ctx->pc = 0x1AAAA4u;
            goto label_1aaaa4;
        }
    }
    ctx->pc = 0x1AA970u;
    // 0x1aa970: 0x92a50b98  lbu         $a1, 0xB98($s5)
    ctx->pc = 0x1aa970u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2968)));
    // 0x1aa974: 0x92a60bbc  lbu         $a2, 0xBBC($s5)
    ctx->pc = 0x1aa974u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 3004)));
    // 0x1aa978: 0xc074108  jal         func_1D0420
    ctx->pc = 0x1AA978u;
    SET_GPR_U32(ctx, 31, 0x1AA980u);
    ctx->pc = 0x1AA97Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA978u;
            // 0x1aa97c: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D0420u;
    if (runtime->hasFunction(0x1D0420u)) {
        auto targetFn = runtime->lookupFunction(0x1D0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA980u; }
        if (ctx->pc != 0x1AA980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D0420_0x1d0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA980u; }
        if (ctx->pc != 0x1AA980u) { return; }
    }
    ctx->pc = 0x1AA980u;
label_1aa980:
    // 0x1aa980: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1aa980u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aa984: 0x3c04004b  lui         $a0, 0x4B
    ctx->pc = 0x1aa984u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)75 << 16));
    // 0x1aa988: 0x92aa0003  lbu         $t2, 0x3($s5)
    ctx->pc = 0x1aa988u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 3)));
    // 0x1aa98c: 0x24091468  addiu       $t1, $zero, 0x1468
    ctx->pc = 0x1aa98cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 5224));
    // 0x1aa990: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1aa990u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1aa994: 0x2484e330  addiu       $a0, $a0, -0x1CD0
    ctx->pc = 0x1aa994u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959920));
    // 0x1aa998: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1aa998u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1aa99c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1aa99cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa9a0: 0x2623821  addu        $a3, $s3, $v0
    ctx->pc = 0x1aa9a0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1aa9a4: 0x1491018  mult        $v0, $t2, $t1
    ctx->pc = 0x1aa9a4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1aa9a8: 0x2633021  addu        $a2, $s3, $v1
    ctx->pc = 0x1aa9a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1aa9ac: 0xc073d58  jal         func_1CF560
    ctx->pc = 0x1AA9ACu;
    SET_GPR_U32(ctx, 31, 0x1AA9B4u);
    ctx->pc = 0x1AA9B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA9ACu;
            // 0x1aa9b0: 0x822021  addu        $a0, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF560u;
    if (runtime->hasFunction(0x1CF560u)) {
        auto targetFn = runtime->lookupFunction(0x1CF560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA9B4u; }
        if (ctx->pc != 0x1AA9B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF560_0x1cf560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA9B4u; }
        if (ctx->pc != 0x1AA9B4u) { return; }
    }
    ctx->pc = 0x1AA9B4u;
label_1aa9b4:
    // 0x1aa9b4: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1AA9B4u;
    SET_GPR_U32(ctx, 31, 0x1AA9BCu);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA9BCu; }
        if (ctx->pc != 0x1AA9BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA9BCu; }
        if (ctx->pc != 0x1AA9BCu) { return; }
    }
    ctx->pc = 0x1AA9BCu;
label_1aa9bc:
    // 0x1aa9bc: 0x92a50b98  lbu         $a1, 0xB98($s5)
    ctx->pc = 0x1aa9bcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2968)));
    // 0x1aa9c0: 0xc19a9d4  jal         func_66A750
    ctx->pc = 0x1AA9C0u;
    SET_GPR_U32(ctx, 31, 0x1AA9C8u);
    ctx->pc = 0x1AA9C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA9C0u;
            // 0x1aa9c4: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x66A750u;
    {
        auto targetFn = runtime->lookupFunction(0x66A750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA9C8u; }
        if (ctx->pc != 0x1AA9C8u) { return; }
    }
    ctx->pc = 0x1AA9C8u;
label_1aa9c8:
    // 0x1aa9c8: 0x96a30bb4  lhu         $v1, 0xBB4($s5)
    ctx->pc = 0x1aa9c8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 2996)));
    // 0x1aa9cc: 0x14600035  bnez        $v1, . + 4 + (0x35 << 2)
    ctx->pc = 0x1AA9CCu;
    {
        const bool branch_taken_0x1aa9cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AA9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA9CCu;
            // 0x1aa9d0: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa9cc) {
            ctx->pc = 0x1AAAA4u;
            goto label_1aaaa4;
        }
    }
    ctx->pc = 0x1AA9D4u;
    // 0x1aa9d4: 0x8c234470  lw          $v1, 0x4470($at)
    ctx->pc = 0x1aa9d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17520)));
    // 0x1aa9d8: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1aa9d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1aa9dc: 0xac23aef8  sw          $v1, -0x5108($at)
    ctx->pc = 0x1aa9dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294946552), GPR_U32(ctx, 3));
    // 0x1aa9e0: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1aa9e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1aa9e4: 0x8c23aef8  lw          $v1, -0x5108($at)
    ctx->pc = 0x1aa9e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294946552)));
    // 0x1aa9e8: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AA9E8u;
    {
        const bool branch_taken_0x1aa9e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa9e8) {
            ctx->pc = 0x1AAA2Cu;
            goto label_1aaa2c;
        }
    }
    ctx->pc = 0x1AA9F0u;
    // 0x1aa9f0: 0x8fa401d4  lw          $a0, 0x1D4($sp)
    ctx->pc = 0x1aa9f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 468)));
    // 0x1aa9f4: 0x1080000d  beqz        $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x1AA9F4u;
    {
        const bool branch_taken_0x1aa9f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa9f4) {
            ctx->pc = 0x1AAA2Cu;
            goto label_1aaa2c;
        }
    }
    ctx->pc = 0x1AA9FCu;
    // 0x1aa9fc: 0x92a20003  lbu         $v0, 0x3($s5)
    ctx->pc = 0x1aa9fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 3)));
    // 0x1aaa00: 0x24061324  addiu       $a2, $zero, 0x1324
    ctx->pc = 0x1aaa00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4900));
    // 0x1aaa04: 0x2642821  addu        $a1, $s3, $a0
    ctx->pc = 0x1aaa04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
    // 0x1aaa08: 0x461018  mult        $v0, $v0, $a2
    ctx->pc = 0x1aaa08u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1aaa0c: 0x628021  addu        $s0, $v1, $v0
    ctx->pc = 0x1aaa0cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1aaa10: 0xc0636ec  jal         func_18DBB0
    ctx->pc = 0x1AAA10u;
    SET_GPR_U32(ctx, 31, 0x1AAA18u);
    ctx->pc = 0x1AAA14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAA10u;
            // 0x1aaa14: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DBB0u;
    if (runtime->hasFunction(0x18DBB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAA18u; }
        if (ctx->pc != 0x1AAA18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAA18u; }
        if (ctx->pc != 0x1AAA18u) { return; }
    }
    ctx->pc = 0x1AAA18u;
label_1aaa18:
    // 0x1aaa18: 0x8ea30034  lw          $v1, 0x34($s5)
    ctx->pc = 0x1aaa18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 52)));
    // 0x1aaa1c: 0x26040074  addiu       $a0, $s0, 0x74
    ctx->pc = 0x1aaa1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 116));
    // 0x1aaa20: 0xac701460  sw          $s0, 0x1460($v1)
    ctx->pc = 0x1aaa20u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 5216), GPR_U32(ctx, 16));
    // 0x1aaa24: 0x8ea30034  lw          $v1, 0x34($s5)
    ctx->pc = 0x1aaa24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 52)));
    // 0x1aaa28: 0xac641464  sw          $a0, 0x1464($v1)
    ctx->pc = 0x1aaa28u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 5220), GPR_U32(ctx, 4));
label_1aaa2c:
    // 0x1aaa2c: 0x92a4054d  lbu         $a0, 0x54D($s5)
    ctx->pc = 0x1aaa2cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 1357)));
    // 0x1aaa30: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1aaa30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aaa34: 0x1483001b  bne         $a0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1AAA34u;
    {
        const bool branch_taken_0x1aaa34 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1AAA38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAA34u;
            // 0x1aaa38: 0x27b001e4  addiu       $s0, $sp, 0x1E4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 484));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aaa34) {
            ctx->pc = 0x1AAAA4u;
            goto label_1aaaa4;
        }
    }
    ctx->pc = 0x1AAA3Cu;
    // 0x1aaa3c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1aaa3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aaa40: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1AAA40u;
    {
        const bool branch_taken_0x1aaa40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aaa40) {
            ctx->pc = 0x1AAAA4u;
            goto label_1aaaa4;
        }
    }
    ctx->pc = 0x1AAA48u;
    // 0x1aaa48: 0x92a50b98  lbu         $a1, 0xB98($s5)
    ctx->pc = 0x1aaa48u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 2968)));
    // 0x1aaa4c: 0xc07416c  jal         func_1D05B0
    ctx->pc = 0x1AAA4Cu;
    SET_GPR_U32(ctx, 31, 0x1AAA54u);
    ctx->pc = 0x1AAA50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAA4Cu;
            // 0x1aaa50: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D05B0u;
    if (runtime->hasFunction(0x1D05B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D05B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAA54u; }
        if (ctx->pc != 0x1AAA54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D05B0_0x1d05b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAA54u; }
        if (ctx->pc != 0x1AAA54u) { return; }
    }
    ctx->pc = 0x1AAA54u;
label_1aaa54:
    // 0x1aaa54: 0x92a60003  lbu         $a2, 0x3($s5)
    ctx->pc = 0x1aaa54u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 3)));
    // 0x1aaa58: 0x3c04003f  lui         $a0, 0x3F
    ctx->pc = 0x1aaa58u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)63 << 16));
    // 0x1aaa5c: 0x2484a380  addiu       $a0, $a0, -0x5C80
    ctx->pc = 0x1aaa5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943616));
    // 0x1aaa60: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1aaa60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aaa64: 0x62980  sll         $a1, $a2, 6
    ctx->pc = 0x1aaa64u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 6));
    // 0x1aaa68: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1aaa68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1aaa6c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x1aaa6cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1aaa70: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1aaa70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1aaa74: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1aaa74u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1aaa78: 0x852821  addu        $a1, $a0, $a1
    ctx->pc = 0x1aaa78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1aaa7c: 0x80a40000  lb          $a0, 0x0($a1)
    ctx->pc = 0x1aaa7cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1aaa80: 0x14830008  bne         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AAA80u;
    {
        const bool branch_taken_0x1aaa80 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1aaa80) {
            ctx->pc = 0x1AAAA4u;
            goto label_1aaaa4;
        }
    }
    ctx->pc = 0x1AAA88u;
    // 0x1aaa88: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1aaa88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aaa8c: 0x24a40004  addiu       $a0, $a1, 0x4
    ctx->pc = 0x1aaa8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1aaa90: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1aaa90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1aaa94: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1aaa94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaa98: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1aaa98u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaa9c: 0xc073d58  jal         func_1CF560
    ctx->pc = 0x1AAA9Cu;
    SET_GPR_U32(ctx, 31, 0x1AAAA4u);
    ctx->pc = 0x1AAAA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAA9Cu;
            // 0x1aaaa0: 0x2623021  addu        $a2, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF560u;
    if (runtime->hasFunction(0x1CF560u)) {
        auto targetFn = runtime->lookupFunction(0x1CF560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAAA4u; }
        if (ctx->pc != 0x1AAAA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF560_0x1cf560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAAA4u; }
        if (ctx->pc != 0x1AAAA4u) { return; }
    }
    ctx->pc = 0x1AAAA4u;
label_1aaaa4:
    // 0x1aaaa4: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1aaaa4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1aaaa8: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1aaaa8u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1aaaac: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1aaaacu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1aaab0: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1aaab0u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1aaab4: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1aaab4u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1aaab8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1aaab8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1aaabc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1aaabcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aaac0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aaac0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aaac4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aaac4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aaac8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AAAC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AAACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAAC8u;
            // 0x1aaacc: 0x27bd0210  addiu       $sp, $sp, 0x210 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 528));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AA50Cu: goto label_1aa50c;
            case 0x1AA518u: goto label_1aa518;
            case 0x1AA52Cu: goto label_1aa52c;
            case 0x1AA584u: goto label_1aa584;
            case 0x1AA598u: goto label_1aa598;
            case 0x1AA5A4u: goto label_1aa5a4;
            case 0x1AA5B0u: goto label_1aa5b0;
            case 0x1AA5B8u: goto label_1aa5b8;
            case 0x1AA5CCu: goto label_1aa5cc;
            case 0x1AA5E0u: goto label_1aa5e0;
            case 0x1AA5F4u: goto label_1aa5f4;
            case 0x1AA61Cu: goto label_1aa61c;
            case 0x1AA624u: goto label_1aa624;
            case 0x1AA638u: goto label_1aa638;
            case 0x1AA644u: goto label_1aa644;
            case 0x1AA67Cu: goto label_1aa67c;
            case 0x1AA688u: goto label_1aa688;
            case 0x1AA694u: goto label_1aa694;
            case 0x1AA6A0u: goto label_1aa6a0;
            case 0x1AA6ACu: goto label_1aa6ac;
            case 0x1AA6B8u: goto label_1aa6b8;
            case 0x1AA6C4u: goto label_1aa6c4;
            case 0x1AA6D0u: goto label_1aa6d0;
            case 0x1AA6E4u: goto label_1aa6e4;
            case 0x1AA70Cu: goto label_1aa70c;
            case 0x1AA78Cu: goto label_1aa78c;
            case 0x1AA7B4u: goto label_1aa7b4;
            case 0x1AA7D0u: goto label_1aa7d0;
            case 0x1AA7D8u: goto label_1aa7d8;
            case 0x1AA7FCu: goto label_1aa7fc;
            case 0x1AA804u: goto label_1aa804;
            case 0x1AA818u: goto label_1aa818;
            case 0x1AA820u: goto label_1aa820;
            case 0x1AA83Cu: goto label_1aa83c;
            case 0x1AA858u: goto label_1aa858;
            case 0x1AA860u: goto label_1aa860;
            case 0x1AA880u: goto label_1aa880;
            case 0x1AA888u: goto label_1aa888;
            case 0x1AA8A4u: goto label_1aa8a4;
            case 0x1AA8A8u: goto label_1aa8a8;
            case 0x1AA8B0u: goto label_1aa8b0;
            case 0x1AA8C4u: goto label_1aa8c4;
            case 0x1AA8E0u: goto label_1aa8e0;
            case 0x1AA8E4u: goto label_1aa8e4;
            case 0x1AA8ECu: goto label_1aa8ec;
            case 0x1AA914u: goto label_1aa914;
            case 0x1AA924u: goto label_1aa924;
            case 0x1AA930u: goto label_1aa930;
            case 0x1AA940u: goto label_1aa940;
            case 0x1AA954u: goto label_1aa954;
            case 0x1AA980u: goto label_1aa980;
            case 0x1AA9B4u: goto label_1aa9b4;
            case 0x1AA9BCu: goto label_1aa9bc;
            case 0x1AA9C8u: goto label_1aa9c8;
            case 0x1AAA18u: goto label_1aaa18;
            case 0x1AAA2Cu: goto label_1aaa2c;
            case 0x1AAA54u: goto label_1aaa54;
            case 0x1AAAA4u: goto label_1aaaa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AAAD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
