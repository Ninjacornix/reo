#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180680
// Address: 0x180680 - 0x1808a0
void sub_00180680_0x180680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180680_0x180680");
#endif

    switch (ctx->pc) {
        case 0x1806c0u: goto label_1806c0;
        case 0x1806d0u: goto label_1806d0;
        case 0x1806e0u: goto label_1806e0;
        case 0x1806f8u: goto label_1806f8;
        case 0x180778u: goto label_180778;
        case 0x18079cu: goto label_18079c;
        default: break;
    }

    ctx->pc = 0x180680u;

    // 0x180680: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x180680u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x180684: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x180684u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x180688: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x180688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x18068c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x18068cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180690: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x180690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x180694: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x180694u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x180698: 0x3c120027  lui         $s2, 0x27
    ctx->pc = 0x180698u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)39 << 16));
    // 0x18069c: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x18069cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1806a0: 0x26426188  addiu       $v0, $s2, 0x6188
    ctx->pc = 0x1806a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 24968));
    // 0x1806a4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1806a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1806a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1806a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1806ac: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x1806acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1806b0: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1806B0u;
    {
        const bool branch_taken_0x1806b0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1806b0) {
            ctx->pc = 0x1806C8u;
            goto label_1806c8;
        }
    }
    ctx->pc = 0x1806B8u;
    // 0x1806b8: 0xc060246  jal         func_180918
    ctx->pc = 0x1806B8u;
    SET_GPR_U32(ctx, 31, 0x1806C0u);
    ctx->pc = 0x1806BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1806B8u;
            // 0x1806bc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180918u;
    if (runtime->hasFunction(0x180918u)) {
        auto targetFn = runtime->lookupFunction(0x180918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1806C0u; }
        if (ctx->pc != 0x1806C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180918_0x180918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1806C0u; }
        if (ctx->pc != 0x1806C0u) { return; }
    }
    ctx->pc = 0x1806C0u;
label_1806c0:
    // 0x1806c0: 0x4400039  bltz        $v0, . + 4 + (0x39 << 2)
    ctx->pc = 0x1806C0u;
    {
        const bool branch_taken_0x1806c0 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1806C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1806C0u;
            // 0x1806c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1806c0) {
            ctx->pc = 0x1807A8u;
            goto label_1807a8;
        }
    }
    ctx->pc = 0x1806C8u;
label_1806c8:
    // 0x1806c8: 0xc060290  jal         func_180A40
    ctx->pc = 0x1806C8u;
    SET_GPR_U32(ctx, 31, 0x1806D0u);
    ctx->pc = 0x1806CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1806C8u;
            // 0x1806cc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180A40u;
    if (runtime->hasFunction(0x180A40u)) {
        auto targetFn = runtime->lookupFunction(0x180A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1806D0u; }
        if (ctx->pc != 0x1806D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180A40_0x180a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1806D0u; }
        if (ctx->pc != 0x1806D0u) { return; }
    }
    ctx->pc = 0x1806D0u;
label_1806d0:
    // 0x1806d0: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1806D0u;
    {
        const bool branch_taken_0x1806d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1806D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1806D0u;
            // 0x1806d4: 0x2402c000  addiu       $v0, $zero, -0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294950912));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1806d0) {
            ctx->pc = 0x18070Cu;
            goto label_18070c;
        }
    }
    ctx->pc = 0x1806D8u;
    // 0x1806d8: 0xc060276  jal         func_1809D8
    ctx->pc = 0x1806D8u;
    SET_GPR_U32(ctx, 31, 0x1806E0u);
    ctx->pc = 0x1806DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1806D8u;
            // 0x1806dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1809D8u;
    if (runtime->hasFunction(0x1809D8u)) {
        auto targetFn = runtime->lookupFunction(0x1809D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1806E0u; }
        if (ctx->pc != 0x1806E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001809D8_0x1809d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1806E0u; }
        if (ctx->pc != 0x1806E0u) { return; }
    }
    ctx->pc = 0x1806E0u;
label_1806e0:
    // 0x1806e0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1806e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1806e4: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1806e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1806e8: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x1806E8u;
    {
        const bool branch_taken_0x1806e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1806e8) {
            ctx->pc = 0x1806ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1806E8u;
            // 0x1806ec: 0x92020000  lbu         $v0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180704u;
            goto label_180704;
        }
    }
    ctx->pc = 0x1806F0u;
    // 0x1806f0: 0xc060246  jal         func_180918
    ctx->pc = 0x1806F0u;
    SET_GPR_U32(ctx, 31, 0x1806F8u);
    ctx->pc = 0x1806F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1806F0u;
            // 0x1806f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180918u;
    if (runtime->hasFunction(0x180918u)) {
        auto targetFn = runtime->lookupFunction(0x180918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1806F8u; }
        if (ctx->pc != 0x1806F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180918_0x180918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1806F8u; }
        if (ctx->pc != 0x1806F8u) { return; }
    }
    ctx->pc = 0x1806F8u;
label_1806f8:
    // 0x1806f8: 0x4400022  bltz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1806F8u;
    {
        const bool branch_taken_0x1806f8 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1806FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1806F8u;
            // 0x1806fc: 0x24020334  addiu       $v0, $zero, 0x334 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1806f8) {
            ctx->pc = 0x180784u;
            goto label_180784;
        }
    }
    ctx->pc = 0x180700u;
    // 0x180700: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x180700u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_180704:
    // 0x180704: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x180704u;
    {
        const bool branch_taken_0x180704 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180704u;
            // 0x180708: 0xa3a20000  sb          $v0, 0x0($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180704) {
            ctx->pc = 0x1807A4u;
            goto label_1807a4;
        }
    }
    ctx->pc = 0x18070Cu;
label_18070c:
    // 0x18070c: 0x2403000c  addiu       $v1, $zero, 0xC
    ctx->pc = 0x18070cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x180710: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x180710u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x180714: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x180714u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x180718: 0x34843fff  ori         $a0, $a0, 0x3FFF
    ctx->pc = 0x180718u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)16383);
    // 0x18071c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x18071cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x180720: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x180720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x180724: 0x2048024  and         $s0, $s0, $a0
    ctx->pc = 0x180724u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 4));
    // 0x180728: 0x3c03ff00  lui         $v1, 0xFF00
    ctx->pc = 0x180728u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65280 << 16));
    // 0x18072c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x18072cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x180730: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x180730u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x180734: 0x3c040001  lui         $a0, 0x1
    ctx->pc = 0x180734u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x180738: 0x2038024  and         $s0, $s0, $v1
    ctx->pc = 0x180738u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x18073c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x18073cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x180740: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x180740u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x180744: 0x344200ff  ori         $v0, $v0, 0xFF
    ctx->pc = 0x180744u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)255);
    // 0x180748: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x180748u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x18074c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x18074cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x180750: 0x2048025  or          $s0, $s0, $a0
    ctx->pc = 0x180750u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 4));
    // 0x180754: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x180754u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x180758: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x180758u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x18075c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x18075cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180760: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x180760u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x180764: 0x37a60004  ori         $a2, $sp, 0x4
    ctx->pc = 0x180764u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)4);
    // 0x180768: 0x10283c  dsll32      $a1, $s0, 0
    ctx->pc = 0x180768u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 0));
    // 0x18076c: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x18076cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x180770: 0xc0625ba  jal         func_1896E8
    ctx->pc = 0x180770u;
    SET_GPR_U32(ctx, 31, 0x180778u);
    ctx->pc = 0x180774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180770u;
            // 0x180774: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1896E8u;
    if (runtime->hasFunction(0x1896E8u)) {
        auto targetFn = runtime->lookupFunction(0x1896E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180778u; }
        if (ctx->pc != 0x180778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001896E8_0x1896e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180778u; }
        if (ctx->pc != 0x180778u) { return; }
    }
    ctx->pc = 0x180778u;
label_180778:
    // 0x180778: 0x443000b  bgezl       $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x180778u;
    {
        const bool branch_taken_0x180778 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x180778) {
            ctx->pc = 0x18077Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x180778u;
            // 0x18077c: 0x93a20000  lbu         $v0, 0x0($sp) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1807A8u;
            goto label_1807a8;
        }
    }
    ctx->pc = 0x180780u;
    // 0x180780: 0x24020334  addiu       $v0, $zero, 0x334
    ctx->pc = 0x180780u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
label_180784:
    // 0x180784: 0x26436188  addiu       $v1, $s2, 0x6188
    ctx->pc = 0x180784u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 24968));
    // 0x180788: 0x2221018  mult        $v0, $s1, $v0
    ctx->pc = 0x180788u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x18078c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x18078cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180790: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x180790u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x180794: 0xc060228  jal         func_1808A0
    ctx->pc = 0x180794u;
    SET_GPR_U32(ctx, 31, 0x18079Cu);
    ctx->pc = 0x180798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180794u;
            // 0x180798: 0xac600004  sw          $zero, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1808A0u;
    if (runtime->hasFunction(0x1808A0u)) {
        auto targetFn = runtime->lookupFunction(0x1808A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18079Cu; }
        if (ctx->pc != 0x18079Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001808A0_0x1808a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18079Cu; }
        if (ctx->pc != 0x18079Cu) { return; }
    }
    ctx->pc = 0x18079Cu;
label_18079c:
    // 0x18079c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18079Cu;
    {
        const bool branch_taken_0x18079c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1807A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18079Cu;
            // 0x1807a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18079c) {
            ctx->pc = 0x1807A8u;
            goto label_1807a8;
        }
    }
    ctx->pc = 0x1807A4u;
label_1807a4:
    // 0x1807a4: 0x93a20000  lbu         $v0, 0x0($sp)
    ctx->pc = 0x1807a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
label_1807a8:
    // 0x1807a8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1807a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1807ac: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1807acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1807b0: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1807b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1807b4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1807b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1807b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1807B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1807BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1807B8u;
            // 0x1807bc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1806C0u: goto label_1806c0;
            case 0x1806C8u: goto label_1806c8;
            case 0x1806D0u: goto label_1806d0;
            case 0x1806E0u: goto label_1806e0;
            case 0x1806F8u: goto label_1806f8;
            case 0x180704u: goto label_180704;
            case 0x18070Cu: goto label_18070c;
            case 0x180778u: goto label_180778;
            case 0x180784u: goto label_180784;
            case 0x18079Cu: goto label_18079c;
            case 0x1807A4u: goto label_1807a4;
            case 0x1807A8u: goto label_1807a8;
            case 0x180830u: goto label_180830;
            case 0x180850u: goto label_180850;
            case 0x18088Cu: goto label_18088c;
            case 0x180894u: goto label_180894;
            case 0x180898u: goto label_180898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1807C0u;
    // 0x1807c0: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x1807c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x1807c4: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x1807c4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x1807c8: 0x832018  mult        $a0, $a0, $v1
    ctx->pc = 0x1807c8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1807cc: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x1807ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x1807d0: 0x24426188  addiu       $v0, $v0, 0x6188
    ctx->pc = 0x1807d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24968));
    // 0x1807d4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1807d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1807d8: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1807d8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1807dc: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x1807dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1807e0: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1807e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1807e4: 0x68c2001b  ldl         $v0, 0x1B($a2)
    ctx->pc = 0x1807e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1807e8: 0x6cc20014  ldr         $v0, 0x14($a2)
    ctx->pc = 0x1807e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1807ec: 0x68c30023  ldl         $v1, 0x23($a2)
    ctx->pc = 0x1807ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 35); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1807f0: 0x6cc3001c  ldr         $v1, 0x1C($a2)
    ctx->pc = 0x1807f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 28); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1807f4: 0xb3a20007  sdl         $v0, 0x7($sp)
    ctx->pc = 0x1807f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1807f8: 0xb7a20000  sdr         $v0, 0x0($sp)
    ctx->pc = 0x1807f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1807fc: 0xb3a3000f  sdl         $v1, 0xF($sp)
    ctx->pc = 0x1807fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x180800: 0xb7a30008  sdr         $v1, 0x8($sp)
    ctx->pc = 0x180800u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x180804: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x180804u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180808: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x180808u;
    {
        const bool branch_taken_0x180808 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18080Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180808u;
            // 0x18080c: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180808) {
            ctx->pc = 0x180894u;
            goto label_180894;
        }
    }
    ctx->pc = 0x180810u;
    // 0x180810: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x180810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x180814: 0x10e20006  beq         $a3, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x180814u;
    {
        const bool branch_taken_0x180814 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x180818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180814u;
            // 0x180818: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180814) {
            ctx->pc = 0x180830u;
            goto label_180830;
        }
    }
    ctx->pc = 0x18081Cu;
    // 0x18081c: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x18081cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x180820: 0x10e2000b  beq         $a3, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x180820u;
    {
        const bool branch_taken_0x180820 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x180824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180820u;
            // 0x180824: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180820) {
            ctx->pc = 0x180850u;
            goto label_180850;
        }
    }
    ctx->pc = 0x180828u;
    // 0x180828: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x180828u;
    {
        const bool branch_taken_0x180828 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x180828) {
            ctx->pc = 0x180898u;
            goto label_180898;
        }
    }
    ctx->pc = 0x180830u;
label_180830:
    // 0x180830: 0x8fa4000c  lw          $a0, 0xC($sp)
    ctx->pc = 0x180830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x180834: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x180834u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x180838: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x180838u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18083c: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x18083cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180840: 0x831807  srav        $v1, $v1, $a0
    ctx->pc = 0x180840u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
    // 0x180844: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x180844u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x180848: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x180848u;
    {
        const bool branch_taken_0x180848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18084Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180848u;
            // 0x18084c: 0x3100b  movn        $v0, $zero, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180848) {
            ctx->pc = 0x180898u;
            goto label_180898;
        }
    }
    ctx->pc = 0x180850u;
label_180850:
    // 0x180850: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x180850u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x180854: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x180854u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x180858: 0x1041821  addu        $v1, $t0, $a0
    ctx->pc = 0x180858u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 4)));
    // 0x18085c: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x18085cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x180860: 0xa21007  srav        $v0, $v0, $a1
    ctx->pc = 0x180860u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x180864: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x180864u;
    {
        const bool branch_taken_0x180864 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x180868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180864u;
            // 0x180868: 0x304600ff  andi        $a2, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180864) {
            ctx->pc = 0x18088Cu;
            goto label_18088c;
        }
    }
    ctx->pc = 0x18086Cu;
    // 0x18086c: 0x24830001  addiu       $v1, $a0, 0x1
    ctx->pc = 0x18086cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x180870: 0xe52823  subu        $a1, $a3, $a1
    ctx->pc = 0x180870u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x180874: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x180874u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x180878: 0x1032021  addu        $a0, $t0, $v1
    ctx->pc = 0x180878u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x18087c: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x18087cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x180880: 0xa21004  sllv        $v0, $v0, $a1
    ctx->pc = 0x180880u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x180884: 0xc21025  or          $v0, $a2, $v0
    ctx->pc = 0x180884u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x180888: 0x304600ff  andi        $a2, $v0, 0xFF
    ctx->pc = 0x180888u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
label_18088c:
    // 0x18088c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18088Cu;
    {
        const bool branch_taken_0x18088c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18088Cu;
            // 0x180890: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18088c) {
            ctx->pc = 0x180898u;
            goto label_180898;
        }
    }
    ctx->pc = 0x180894u;
label_180894:
    // 0x180894: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x180894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_180898:
    // 0x180898: 0x3e00008  jr          $ra
    ctx->pc = 0x180898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18089Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180898u;
            // 0x18089c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1806C0u: goto label_1806c0;
            case 0x1806C8u: goto label_1806c8;
            case 0x1806D0u: goto label_1806d0;
            case 0x1806E0u: goto label_1806e0;
            case 0x1806F8u: goto label_1806f8;
            case 0x180704u: goto label_180704;
            case 0x18070Cu: goto label_18070c;
            case 0x180778u: goto label_180778;
            case 0x180784u: goto label_180784;
            case 0x18079Cu: goto label_18079c;
            case 0x1807A4u: goto label_1807a4;
            case 0x1807A8u: goto label_1807a8;
            case 0x180830u: goto label_180830;
            case 0x180850u: goto label_180850;
            case 0x18088Cu: goto label_18088c;
            case 0x180894u: goto label_180894;
            case 0x180898u: goto label_180898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1808A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
