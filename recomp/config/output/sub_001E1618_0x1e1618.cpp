#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E1618
// Address: 0x1e1618 - 0x1e1b3c
void sub_001E1618_0x1e1618(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E1618_0x1e1618");
#endif

    switch (ctx->pc) {
        case 0x1e16e0u: goto label_1e16e0;
        case 0x1e1700u: goto label_1e1700;
        case 0x1e1724u: goto label_1e1724;
        case 0x1e1804u: goto label_1e1804;
        case 0x1e1888u: goto label_1e1888;
        case 0x1e1898u: goto label_1e1898;
        case 0x1e18d8u: goto label_1e18d8;
        case 0x1e18f4u: goto label_1e18f4;
        case 0x1e1904u: goto label_1e1904;
        case 0x1e1928u: goto label_1e1928;
        case 0x1e1950u: goto label_1e1950;
        case 0x1e1998u: goto label_1e1998;
        case 0x1e19b4u: goto label_1e19b4;
        case 0x1e19ccu: goto label_1e19cc;
        case 0x1e19fcu: goto label_1e19fc;
        case 0x1e1a18u: goto label_1e1a18;
        case 0x1e1a38u: goto label_1e1a38;
        case 0x1e1a58u: goto label_1e1a58;
        case 0x1e1a78u: goto label_1e1a78;
        case 0x1e1a8cu: goto label_1e1a8c;
        case 0x1e1aa4u: goto label_1e1aa4;
        case 0x1e1ad0u: goto label_1e1ad0;
        case 0x1e1b00u: goto label_1e1b00;
        case 0x1e1b20u: goto label_1e1b20;
        default: break;
    }

    ctx->pc = 0x1e1618u;

    // 0x1e1618: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1e1618u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1e161c: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1e161cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1e1620: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1e1620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1e1624: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1624u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1628: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1628u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e162c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e162cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e1630: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e1630u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e1634: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e1634u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e1638: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e1638u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e163c: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1e163cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1e1640: 0xafca0018  sw          $t2, 0x18($fp)
    ctx->pc = 0x1e1640u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 10));
    // 0x1e1644: 0xafcb001c  sw          $t3, 0x1C($fp)
    ctx->pc = 0x1e1644u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 11));
    // 0x1e1648: 0xafc00024  sw          $zero, 0x24($fp)
    ctx->pc = 0x1e1648u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
    // 0x1e164c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e164cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1650: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1654: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1654u;
    {
        const bool branch_taken_0x1e1654 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1654) {
            ctx->pc = 0x1E167Cu;
            goto label_1e167c;
        }
    }
    ctx->pc = 0x1E165Cu;
    // 0x1e165c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e165cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1660: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1660u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1664: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1664u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1668: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e166c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e166cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1670: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1670u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1674: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1674u;
    {
        const bool branch_taken_0x1e1674 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1674) {
            ctx->pc = 0x1E1690u;
            goto label_1e1690;
        }
    }
    ctx->pc = 0x1E167Cu;
label_1e167c:
    // 0x1e167c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e167cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1680: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1680u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1684: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1688: 0x10000126  b           . + 4 + (0x126 << 2)
    ctx->pc = 0x1E1688u;
    {
        const bool branch_taken_0x1e1688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1688) {
            ctx->pc = 0x1E1B24u;
            goto label_1e1b24;
        }
    }
    ctx->pc = 0x1E1690u;
label_1e1690:
    // 0x1e1690: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1690u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1694: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1694u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1698: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1698u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e169c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e169cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e16a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e16a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e16a4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e16a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e16a8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e16a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e16ac: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e16acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e16b0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e16b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e16b4: 0x8c420514  lw          $v0, 0x514($v0)
    ctx->pc = 0x1e16b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1300)));
    // 0x1e16b8: 0xac620510  sw          $v0, 0x510($v1)
    ctx->pc = 0x1e16b8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1296), GPR_U32(ctx, 2));
    // 0x1e16bc: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e16bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e16c0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e16c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e16c4: 0x8c420510  lw          $v0, 0x510($v0)
    ctx->pc = 0x1e16c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1296)));
    // 0x1e16c8: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x1e16c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1e16cc: 0x24420fa0  addiu       $v0, $v0, 0xFA0
    ctx->pc = 0x1e16ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4000));
    // 0x1e16d0: 0xac62051c  sw          $v0, 0x51C($v1)
    ctx->pc = 0x1e16d0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1308), GPR_U32(ctx, 2));
    // 0x1e16d4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e16d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e16d8: 0xc07a1d6  jal         func_1E8758
    ctx->pc = 0x1E16D8u;
    SET_GPR_U32(ctx, 31, 0x1E16E0u);
    ctx->pc = 0x1E8758u;
    if (runtime->hasFunction(0x1E8758u)) {
        auto targetFn = runtime->lookupFunction(0x1E8758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E16E0u; }
        if (ctx->pc != 0x1E16E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8758_0x1e8758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E16E0u; }
        if (ctx->pc != 0x1E16E0u) { return; }
    }
    ctx->pc = 0x1E16E0u;
label_1e16e0:
    // 0x1e16e0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1e16e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1e16e4: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1e16e4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1e16e8: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e16e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e16ec: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e16ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e16f0: 0x8fc50034  lw          $a1, 0x34($fp)
    ctx->pc = 0x1e16f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e16f4: 0x24062382  addiu       $a2, $zero, 0x2382
    ctx->pc = 0x1e16f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9090));
    // 0x1e16f8: 0xc076bab  jal         func_1DAEAC
    ctx->pc = 0x1E16F8u;
    SET_GPR_U32(ctx, 31, 0x1E1700u);
    ctx->pc = 0x1DAEACu;
    if (runtime->hasFunction(0x1DAEACu)) {
        auto targetFn = runtime->lookupFunction(0x1DAEACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1700u; }
        if (ctx->pc != 0x1E1700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAEAC_0x1daeac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1700u; }
        if (ctx->pc != 0x1E1700u) { return; }
    }
    ctx->pc = 0x1E1700u;
label_1e1700:
    // 0x1e1700: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e1700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1704: 0x24420084  addiu       $v0, $v0, 0x84
    ctx->pc = 0x1e1704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 132));
    // 0x1e1708: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e1708u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e170c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e170cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1710: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1e1710u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1e1714: 0x8fc40030  lw          $a0, 0x30($fp)
    ctx->pc = 0x1e1714u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e1718: 0x24050128  addiu       $a1, $zero, 0x128
    ctx->pc = 0x1e1718u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 296));
    // 0x1e171c: 0xc040e26  jal         func_103898
    ctx->pc = 0x1E171Cu;
    SET_GPR_U32(ctx, 31, 0x1E1724u);
    ctx->pc = 0x103898u;
    if (runtime->hasFunction(0x103898u)) {
        auto targetFn = runtime->lookupFunction(0x103898u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1724u; }
        if (ctx->pc != 0x1E1724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103898_0x103898(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1724u; }
        if (ctx->pc != 0x1E1724u) { return; }
    }
    ctx->pc = 0x1E1724u;
label_1e1724:
    // 0x1e1724: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e1724u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1728: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e1728u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e172c: 0x8c42003c  lw          $v0, 0x3C($v0)
    ctx->pc = 0x1e172cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 60)));
    // 0x1e1730: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e1730u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e1734: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e1734u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1738: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e1738u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e173c: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1e173cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1e1740: 0x8fc50020  lw          $a1, 0x20($fp)
    ctx->pc = 0x1e1740u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1744: 0x8fc20058  lw          $v0, 0x58($fp)
    ctx->pc = 0x1e1744u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1e1748: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e1748u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e174c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e174cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e1750: 0x8fc20058  lw          $v0, 0x58($fp)
    ctx->pc = 0x1e1750u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1e1754: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e1754u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e1758: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e1758u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e175c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e175cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e1760: 0x8fc30058  lw          $v1, 0x58($fp)
    ctx->pc = 0x1e1760u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1e1764: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e1764u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e1768: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e1768u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e176c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e176cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e1770: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e1770u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e1774: 0x8fc30058  lw          $v1, 0x58($fp)
    ctx->pc = 0x1e1774u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1e1778: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e1778u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e177c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e177cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e1780: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e1780u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e1784: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e1784u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e1788: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x1e1788u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x1e178c: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e178cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1790: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e1790u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1794: 0x9442000a  lhu         $v0, 0xA($v0)
    ctx->pc = 0x1e1794u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 10)));
    // 0x1e1798: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e1798u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e179c: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1e179cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e17a0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e17a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e17a4: 0x9442000a  lhu         $v0, 0xA($v0)
    ctx->pc = 0x1e17a4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 10)));
    // 0x1e17a8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e17a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e17ac: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e17acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e17b0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e17b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e17b4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1e17b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e17b8: 0xa482000c  sh          $v0, 0xC($a0)
    ctx->pc = 0x1e17b8u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e17bc: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e17bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e17c0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e17c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e17c4: 0x94420040  lhu         $v0, 0x40($v0)
    ctx->pc = 0x1e17c4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x1e17c8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e17c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e17cc: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1e17ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e17d0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e17d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e17d4: 0x94420040  lhu         $v0, 0x40($v0)
    ctx->pc = 0x1e17d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x1e17d8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e17d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e17dc: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e17dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e17e0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e17e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e17e4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1e17e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e17e8: 0xa482000e  sh          $v0, 0xE($a0)
    ctx->pc = 0x1e17e8u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e17ec: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e17ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e17f0: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e17f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e17f4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e17f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e17f8: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e17f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e17fc: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E17FCu;
    SET_GPR_U32(ctx, 31, 0x1E1804u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1804u; }
        if (ctx->pc != 0x1E1804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1804u; }
        if (ctx->pc != 0x1E1804u) { return; }
    }
    ctx->pc = 0x1E1804u;
label_1e1804:
    // 0x1e1804: 0x8fc50020  lw          $a1, 0x20($fp)
    ctx->pc = 0x1e1804u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1808: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e1808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e180c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e180cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e1810: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e1810u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e1814: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e1814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e1818: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e1818u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e181c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e181cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e1820: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e1820u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e1824: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e1824u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e1828: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e1828u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e182c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e182cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e1830: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e1830u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e1834: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e1834u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e1838: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e1838u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e183c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e183cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e1840: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e1840u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e1844: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e1844u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e1848: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e1848u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e184c: 0xaca20020  sw          $v0, 0x20($a1)
    ctx->pc = 0x1e184cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 32), GPR_U32(ctx, 2));
    // 0x1e1850: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e1850u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1854: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e1854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1858: 0xac620064  sw          $v0, 0x64($v1)
    ctx->pc = 0x1e1858u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 100), GPR_U32(ctx, 2));
    // 0x1e185c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e185cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1860: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1860u;
    {
        const bool branch_taken_0x1e1860 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1860) {
            ctx->pc = 0x1E1888u;
            goto label_1e1888;
        }
    }
    ctx->pc = 0x1E1868u;
    // 0x1e1868: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e1868u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e186c: 0x24420128  addiu       $v0, $v0, 0x128
    ctx->pc = 0x1e186cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 296));
    // 0x1e1870: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1e1870u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1e1874: 0x8fc40030  lw          $a0, 0x30($fp)
    ctx->pc = 0x1e1874u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e1878: 0x8fc50050  lw          $a1, 0x50($fp)
    ctx->pc = 0x1e1878u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1e187c: 0x8fc6001c  lw          $a2, 0x1C($fp)
    ctx->pc = 0x1e187cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1880: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E1880u;
    SET_GPR_U32(ctx, 31, 0x1E1888u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1888u; }
        if (ctx->pc != 0x1E1888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1888u; }
        if (ctx->pc != 0x1E1888u) { return; }
    }
    ctx->pc = 0x1E1888u;
label_1e1888:
    // 0x1e1888: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e1888u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e188c: 0x24050086  addiu       $a1, $zero, 0x86
    ctx->pc = 0x1e188cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 134));
    // 0x1e1890: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E1890u;
    SET_GPR_U32(ctx, 31, 0x1E1898u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1898u; }
        if (ctx->pc != 0x1E1898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1898u; }
        if (ctx->pc != 0x1E1898u) { return; }
    }
    ctx->pc = 0x1E1898u;
label_1e1898:
    // 0x1e1898: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e1898u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e189c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e189cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e18a0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E18A0u;
    {
        const bool branch_taken_0x1e18a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e18a0) {
            ctx->pc = 0x1E18BCu;
            goto label_1e18bc;
        }
    }
    ctx->pc = 0x1E18A8u;
    // 0x1e18a8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e18a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e18ac: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e18acu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e18b0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e18b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e18b4: 0x1000009b  b           . + 4 + (0x9B << 2)
    ctx->pc = 0x1E18B4u;
    {
        const bool branch_taken_0x1e18b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e18b4) {
            ctx->pc = 0x1E1B24u;
            goto label_1e1b24;
        }
    }
    ctx->pc = 0x1E18BCu;
label_1e18bc:
    // 0x1e18bc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e18bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e18c0: 0x24420484  addiu       $v0, $v0, 0x484
    ctx->pc = 0x1e18c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1156));
    // 0x1e18c4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e18c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e18c8: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e18c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e18cc: 0x24060028  addiu       $a2, $zero, 0x28
    ctx->pc = 0x1e18ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e18d0: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E18D0u;
    SET_GPR_U32(ctx, 31, 0x1E18D8u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E18D8u; }
        if (ctx->pc != 0x1E18D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E18D8u; }
        if (ctx->pc != 0x1E18D8u) { return; }
    }
    ctx->pc = 0x1E18D8u;
label_1e18d8:
    // 0x1e18d8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e18d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e18dc: 0x244204ac  addiu       $v0, $v0, 0x4AC
    ctx->pc = 0x1e18dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1196));
    // 0x1e18e0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e18e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e18e4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e18e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e18e8: 0x24060028  addiu       $a2, $zero, 0x28
    ctx->pc = 0x1e18e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e18ec: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E18ECu;
    SET_GPR_U32(ctx, 31, 0x1E18F4u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E18F4u; }
        if (ctx->pc != 0x1E18F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E18F4u; }
        if (ctx->pc != 0x1E18F4u) { return; }
    }
    ctx->pc = 0x1E18F4u;
label_1e18f4:
    // 0x1e18f4: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e18f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e18f8: 0x24050086  addiu       $a1, $zero, 0x86
    ctx->pc = 0x1e18f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 134));
    // 0x1e18fc: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E18FCu;
    SET_GPR_U32(ctx, 31, 0x1E1904u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1904u; }
        if (ctx->pc != 0x1E1904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1904u; }
        if (ctx->pc != 0x1E1904u) { return; }
    }
    ctx->pc = 0x1E1904u;
label_1e1904:
    // 0x1e1904: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1904u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1e1908: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1908u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e190c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E190Cu;
    {
        const bool branch_taken_0x1e190c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e190c) {
            ctx->pc = 0x1E193Cu;
            goto label_1e193c;
        }
    }
    ctx->pc = 0x1E1914u;
    // 0x1e1914: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e1914u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1918: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e1918u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e191c: 0x8fc50028  lw          $a1, 0x28($fp)
    ctx->pc = 0x1e191cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e1920: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E1920u;
    SET_GPR_U32(ctx, 31, 0x1E1928u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1928u; }
        if (ctx->pc != 0x1E1928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1928u; }
        if (ctx->pc != 0x1E1928u) { return; }
    }
    ctx->pc = 0x1E1928u;
label_1e1928:
    // 0x1e1928: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e1928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e192c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e192cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1930: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1934: 0x1000007b  b           . + 4 + (0x7B << 2)
    ctx->pc = 0x1E1934u;
    {
        const bool branch_taken_0x1e1934 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1934) {
            ctx->pc = 0x1E1B24u;
            goto label_1e1b24;
        }
    }
    ctx->pc = 0x1E193Cu;
label_1e193c:
    // 0x1e193c: 0x8fc4002c  lw          $a0, 0x2C($fp)
    ctx->pc = 0x1e193cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1940: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e1940u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1944: 0x24060028  addiu       $a2, $zero, 0x28
    ctx->pc = 0x1e1944u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e1948: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E1948u;
    SET_GPR_U32(ctx, 31, 0x1E1950u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1950u; }
        if (ctx->pc != 0x1E1950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1950u; }
        if (ctx->pc != 0x1E1950u) { return; }
    }
    ctx->pc = 0x1E1950u;
label_1e1950:
    // 0x1e1950: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e1950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e1954: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1E1954u;
    {
        const bool branch_taken_0x1e1954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1954) {
            ctx->pc = 0x1E19A0u;
            goto label_1e19a0;
        }
    }
    ctx->pc = 0x1E195Cu;
    // 0x1e195c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e195cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e1960: 0x80420000  lb          $v0, 0x0($v0)
    ctx->pc = 0x1e1960u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1964: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1E1964u;
    {
        const bool branch_taken_0x1e1964 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1964) {
            ctx->pc = 0x1E197Cu;
            goto label_1e197c;
        }
    }
    ctx->pc = 0x1E196Cu;
    // 0x1e196c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e196cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1970: 0xa0400028  sb          $zero, 0x28($v0)
    ctx->pc = 0x1e1970u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 40), (uint8_t)GPR_U32(ctx, 0));
    // 0x1e1974: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1E1974u;
    {
        const bool branch_taken_0x1e1974 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1974) {
            ctx->pc = 0x1E19A8u;
            goto label_1e19a8;
        }
    }
    ctx->pc = 0x1E197Cu;
label_1e197c:
    // 0x1e197c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e197cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1980: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1e1980u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1e1984: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e1984u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1988: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e1988u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e198c: 0x2406003c  addiu       $a2, $zero, 0x3C
    ctx->pc = 0x1e198cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1e1990: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E1990u;
    SET_GPR_U32(ctx, 31, 0x1E1998u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1998u; }
        if (ctx->pc != 0x1E1998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1998u; }
        if (ctx->pc != 0x1E1998u) { return; }
    }
    ctx->pc = 0x1E1998u;
label_1e1998:
    // 0x1e1998: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1E1998u;
    {
        const bool branch_taken_0x1e1998 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1998) {
            ctx->pc = 0x1E19A8u;
            goto label_1e19a8;
        }
    }
    ctx->pc = 0x1E19A0u;
label_1e19a0:
    // 0x1e19a0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e19a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e19a4: 0xa0400028  sb          $zero, 0x28($v0)
    ctx->pc = 0x1e19a4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 40), (uint8_t)GPR_U32(ctx, 0));
label_1e19a8:
    // 0x1e19a8: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e19a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e19ac: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E19ACu;
    SET_GPR_U32(ctx, 31, 0x1E19B4u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E19B4u; }
        if (ctx->pc != 0x1E19B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E19B4u; }
        if (ctx->pc != 0x1E19B4u) { return; }
    }
    ctx->pc = 0x1E19B4u;
label_1e19b4:
    // 0x1e19b4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e19b4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e19b8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e19b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e19bc: 0xac430064  sw          $v1, 0x64($v0)
    ctx->pc = 0x1e19bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 100), GPR_U32(ctx, 3));
    // 0x1e19c0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1e19c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e19c4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E19C4u;
    SET_GPR_U32(ctx, 31, 0x1E19CCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E19CCu; }
        if (ctx->pc != 0x1E19CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E19CCu; }
        if (ctx->pc != 0x1E19CCu) { return; }
    }
    ctx->pc = 0x1E19CCu;
label_1e19cc:
    // 0x1e19cc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e19ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e19d0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e19d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e19d4: 0xac430068  sw          $v1, 0x68($v0)
    ctx->pc = 0x1e19d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 104), GPR_U32(ctx, 3));
    // 0x1e19d8: 0x8fc3002c  lw          $v1, 0x2C($fp)
    ctx->pc = 0x1e19d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e19dc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e19dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e19e0: 0x8c42003c  lw          $v0, 0x3C($v0)
    ctx->pc = 0x1e19e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 60)));
    // 0x1e19e4: 0xac62006c  sw          $v0, 0x6C($v1)
    ctx->pc = 0x1e19e4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 108), GPR_U32(ctx, 2));
    // 0x1e19e8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e19e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e19ec: 0x9442000a  lhu         $v0, 0xA($v0)
    ctx->pc = 0x1e19ecu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 10)));
    // 0x1e19f0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e19f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e19f4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E19F4u;
    SET_GPR_U32(ctx, 31, 0x1E19FCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E19FCu; }
        if (ctx->pc != 0x1E19FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E19FCu; }
        if (ctx->pc != 0x1E19FCu) { return; }
    }
    ctx->pc = 0x1E19FCu;
label_1e19fc:
    // 0x1e19fc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e19fcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1a00: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1a00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1a04: 0xac430070  sw          $v1, 0x70($v0)
    ctx->pc = 0x1e1a04u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 112), GPR_U32(ctx, 3));
    // 0x1e1a08: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e1a08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1a0c: 0x8c440040  lw          $a0, 0x40($v0)
    ctx->pc = 0x1e1a0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x1e1a10: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E1A10u;
    SET_GPR_U32(ctx, 31, 0x1E1A18u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A18u; }
        if (ctx->pc != 0x1E1A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A18u; }
        if (ctx->pc != 0x1E1A18u) { return; }
    }
    ctx->pc = 0x1E1A18u;
label_1e1a18:
    // 0x1e1a18: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e1a18u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1a1c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1a20: 0xac430074  sw          $v1, 0x74($v0)
    ctx->pc = 0x1e1a20u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 116), GPR_U32(ctx, 3));
    // 0x1e1a24: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1a24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1a28: 0x24420078  addiu       $v0, $v0, 0x78
    ctx->pc = 0x1e1a28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x1e1a2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e1a2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1a30: 0xc07c27c  jal         func_1F09F0
    ctx->pc = 0x1E1A30u;
    SET_GPR_U32(ctx, 31, 0x1E1A38u);
    ctx->pc = 0x1F09F0u;
    if (runtime->hasFunction(0x1F09F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F09F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A38u; }
        if (ctx->pc != 0x1E1A38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F09F0_0x1f09f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A38u; }
        if (ctx->pc != 0x1E1A38u) { return; }
    }
    ctx->pc = 0x1E1A38u;
label_1e1a38:
    // 0x1e1a38: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1a38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1a3c: 0x24420078  addiu       $v0, $v0, 0x78
    ctx->pc = 0x1e1a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x1e1a40: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e1a40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1a44: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e1a44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1a48: 0x24054c43  addiu       $a1, $zero, 0x4C43
    ctx->pc = 0x1e1a48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 19523));
    // 0x1e1a4c: 0x8c660510  lw          $a2, 0x510($v1)
    ctx->pc = 0x1e1a4cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1296)));
    // 0x1e1a50: 0xc07c28f  jal         func_1F0A3C
    ctx->pc = 0x1E1A50u;
    SET_GPR_U32(ctx, 31, 0x1E1A58u);
    ctx->pc = 0x1F0A3Cu;
    if (runtime->hasFunction(0x1F0A3Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F0A3Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A58u; }
        if (ctx->pc != 0x1E1A58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0A3C_0x1f0a3c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A58u; }
        if (ctx->pc != 0x1E1A58u) { return; }
    }
    ctx->pc = 0x1E1A58u;
label_1e1a58:
    // 0x1e1a58: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1a58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1a5c: 0x24420078  addiu       $v0, $v0, 0x78
    ctx->pc = 0x1e1a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x1e1a60: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e1a60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1a64: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e1a64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1a68: 0x24054d52  addiu       $a1, $zero, 0x4D52
    ctx->pc = 0x1e1a68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 19794));
    // 0x1e1a6c: 0x8c660518  lw          $a2, 0x518($v1)
    ctx->pc = 0x1e1a6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1304)));
    // 0x1e1a70: 0xc07c28f  jal         func_1F0A3C
    ctx->pc = 0x1E1A70u;
    SET_GPR_U32(ctx, 31, 0x1E1A78u);
    ctx->pc = 0x1F0A3Cu;
    if (runtime->hasFunction(0x1F0A3Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F0A3Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A78u; }
        if (ctx->pc != 0x1E1A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0A3C_0x1f0a3c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A78u; }
        if (ctx->pc != 0x1E1A78u) { return; }
    }
    ctx->pc = 0x1E1A78u;
label_1e1a78:
    // 0x1e1a78: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1a78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1a7c: 0x24420078  addiu       $v0, $v0, 0x78
    ctx->pc = 0x1e1a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x1e1a80: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e1a80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1a84: 0xc07c2e8  jal         func_1F0BA0
    ctx->pc = 0x1E1A84u;
    SET_GPR_U32(ctx, 31, 0x1E1A8Cu);
    ctx->pc = 0x1F0BA0u;
    if (runtime->hasFunction(0x1F0BA0u)) {
        auto targetFn = runtime->lookupFunction(0x1F0BA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A8Cu; }
        if (ctx->pc != 0x1E1A8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0BA0_0x1f0ba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1A8Cu; }
        if (ctx->pc != 0x1E1A8Cu) { return; }
    }
    ctx->pc = 0x1E1A8Cu;
label_1e1a8c:
    // 0x1e1a8c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1e1a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1e1a90: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e1a90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e1a94: 0x24420078  addiu       $v0, $v0, 0x78
    ctx->pc = 0x1e1a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x1e1a98: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e1a98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1a9c: 0xc07c303  jal         func_1F0C0C
    ctx->pc = 0x1E1A9Cu;
    SET_GPR_U32(ctx, 31, 0x1E1AA4u);
    ctx->pc = 0x1F0C0Cu;
    if (runtime->hasFunction(0x1F0C0Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F0C0Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1AA4u; }
        if (ctx->pc != 0x1E1AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0C0C_0x1f0c0c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1AA4u; }
        if (ctx->pc != 0x1E1AA4u) { return; }
    }
    ctx->pc = 0x1E1AA4u;
label_1e1aa4:
    // 0x1e1aa4: 0x97c20038  lhu         $v0, 0x38($fp)
    ctx->pc = 0x1e1aa4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e1aa8: 0x24420078  addiu       $v0, $v0, 0x78
    ctx->pc = 0x1e1aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 120));
    // 0x1e1aac: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e1aacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e1ab0: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e1ab0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1ab4: 0x8fc50028  lw          $a1, 0x28($fp)
    ctx->pc = 0x1e1ab4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e1ab8: 0x24063000  addiu       $a2, $zero, 0x3000
    ctx->pc = 0x1e1ab8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12288));
    // 0x1e1abc: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e1abcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1ac0: 0x2408002c  addiu       $t0, $zero, 0x2C
    ctx->pc = 0x1e1ac0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e1ac4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e1ac4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1ac8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E1AC8u;
    SET_GPR_U32(ctx, 31, 0x1E1AD0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1AD0u; }
        if (ctx->pc != 0x1E1AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1AD0u; }
        if (ctx->pc != 0x1E1AD0u) { return; }
    }
    ctx->pc = 0x1E1AD0u;
label_1e1ad0:
    // 0x1e1ad0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1AD0u;
    {
        const bool branch_taken_0x1e1ad0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1ad0) {
            ctx->pc = 0x1E1AECu;
            goto label_1e1aec;
        }
    }
    ctx->pc = 0x1E1AD8u;
    // 0x1e1ad8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1adc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1adcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1ae0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1ae4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1E1AE4u;
    {
        const bool branch_taken_0x1e1ae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1ae4) {
            ctx->pc = 0x1E1B24u;
            goto label_1e1b24;
        }
    }
    ctx->pc = 0x1E1AECu;
label_1e1aec:
    // 0x1e1aec: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e1aecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1af0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1af4: 0xac620080  sw          $v0, 0x80($v1)
    ctx->pc = 0x1e1af4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 128), GPR_U32(ctx, 2));
    // 0x1e1af8: 0xc076c7f  jal         func_1DB1FC
    ctx->pc = 0x1E1AF8u;
    SET_GPR_U32(ctx, 31, 0x1E1B00u);
    ctx->pc = 0x1DB1FCu;
    if (runtime->hasFunction(0x1DB1FCu)) {
        auto targetFn = runtime->lookupFunction(0x1DB1FCu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1B00u; }
        if (ctx->pc != 0x1E1B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB1FC_0x1db1fc(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1B00u; }
        if (ctx->pc != 0x1E1B00u) { return; }
    }
    ctx->pc = 0x1E1B00u;
label_1e1b00:
    // 0x1e1b00: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e1b00u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1b04: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e1b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e1b08: 0xac43007c  sw          $v1, 0x7C($v0)
    ctx->pc = 0x1e1b08u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 124), GPR_U32(ctx, 3));
    // 0x1e1b0c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e1b0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1b10: 0x2405001c  addiu       $a1, $zero, 0x1C
    ctx->pc = 0x1e1b10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x1e1b14: 0x8fc60060  lw          $a2, 0x60($fp)
    ctx->pc = 0x1e1b14u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 96)));
    // 0x1e1b18: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E1B18u;
    SET_GPR_U32(ctx, 31, 0x1E1B20u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1B20u; }
        if (ctx->pc != 0x1E1B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1B20u; }
        if (ctx->pc != 0x1E1B20u) { return; }
    }
    ctx->pc = 0x1E1B20u;
label_1e1b20:
    // 0x1e1b20: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e1b20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e1b24:
    // 0x1e1b24: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e1b24u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1b28: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1e1b28u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1e1b2c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1e1b2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1e1b30: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1e1b30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1e1b34: 0x3e00008  jr          $ra
    ctx->pc = 0x1E1B34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E167Cu: goto label_1e167c;
            case 0x1E1690u: goto label_1e1690;
            case 0x1E16E0u: goto label_1e16e0;
            case 0x1E1700u: goto label_1e1700;
            case 0x1E1724u: goto label_1e1724;
            case 0x1E1804u: goto label_1e1804;
            case 0x1E1888u: goto label_1e1888;
            case 0x1E1898u: goto label_1e1898;
            case 0x1E18BCu: goto label_1e18bc;
            case 0x1E18D8u: goto label_1e18d8;
            case 0x1E18F4u: goto label_1e18f4;
            case 0x1E1904u: goto label_1e1904;
            case 0x1E1928u: goto label_1e1928;
            case 0x1E193Cu: goto label_1e193c;
            case 0x1E1950u: goto label_1e1950;
            case 0x1E197Cu: goto label_1e197c;
            case 0x1E1998u: goto label_1e1998;
            case 0x1E19A0u: goto label_1e19a0;
            case 0x1E19A8u: goto label_1e19a8;
            case 0x1E19B4u: goto label_1e19b4;
            case 0x1E19CCu: goto label_1e19cc;
            case 0x1E19FCu: goto label_1e19fc;
            case 0x1E1A18u: goto label_1e1a18;
            case 0x1E1A38u: goto label_1e1a38;
            case 0x1E1A58u: goto label_1e1a58;
            case 0x1E1A78u: goto label_1e1a78;
            case 0x1E1A8Cu: goto label_1e1a8c;
            case 0x1E1AA4u: goto label_1e1aa4;
            case 0x1E1AD0u: goto label_1e1ad0;
            case 0x1E1AECu: goto label_1e1aec;
            case 0x1E1B00u: goto label_1e1b00;
            case 0x1E1B20u: goto label_1e1b20;
            case 0x1E1B24u: goto label_1e1b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E1B3Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
