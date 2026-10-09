#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1688
// Address: 0x1f1688 - 0x1f1870
void sub_001F1688_0x1f1688(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1688_0x1f1688");
#endif

    switch (ctx->pc) {
        case 0x1f16e0u: goto label_1f16e0;
        case 0x1f1728u: goto label_1f1728;
        case 0x1f178cu: goto label_1f178c;
        case 0x1f17b4u: goto label_1f17b4;
        case 0x1f17e8u: goto label_1f17e8;
        case 0x1f1810u: goto label_1f1810;
        case 0x1f1848u: goto label_1f1848;
        default: break;
    }

    ctx->pc = 0x1f1688u;

    // 0x1f1688: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f168c: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f168cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1690: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1690u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1694: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1f1694u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1698: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f1698u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f169c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f169cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f16a0: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1f16a0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1f16a4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f16a4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f16a8: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f16a8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f16ac: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f16acu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f16b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F16B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F16E0u: goto label_1f16e0;
            case 0x1F1728u: goto label_1f1728;
            case 0x1F177Cu: goto label_1f177c;
            case 0x1F178Cu: goto label_1f178c;
            case 0x1F17A8u: goto label_1f17a8;
            case 0x1F17B4u: goto label_1f17b4;
            case 0x1F17B8u: goto label_1f17b8;
            case 0x1F17E8u: goto label_1f17e8;
            case 0x1F17FCu: goto label_1f17fc;
            case 0x1F1810u: goto label_1f1810;
            case 0x1F1830u: goto label_1f1830;
            case 0x1F1848u: goto label_1f1848;
            case 0x1F1854u: goto label_1f1854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F16B8u;
    // 0x1f16b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f16b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f16bc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f16bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f16c0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f16c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f16c4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f16c4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f16c8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f16c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f16cc: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f16ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1f16d0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f16d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f16d4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f16d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f16d8: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F16D8u;
    SET_GPR_U32(ctx, 31, 0x1F16E0u);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F16E0u; }
        if (ctx->pc != 0x1F16E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F16E0u; }
        if (ctx->pc != 0x1F16E0u) { return; }
    }
    ctx->pc = 0x1F16E0u;
label_1f16e0:
    // 0x1f16e0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f16e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f16e4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f16e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f16e8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f16e8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f16ec: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f16ecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f16f0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f16f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f16f4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f16f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f16f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F16F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F16E0u: goto label_1f16e0;
            case 0x1F1728u: goto label_1f1728;
            case 0x1F177Cu: goto label_1f177c;
            case 0x1F178Cu: goto label_1f178c;
            case 0x1F17A8u: goto label_1f17a8;
            case 0x1F17B4u: goto label_1f17b4;
            case 0x1F17B8u: goto label_1f17b8;
            case 0x1F17E8u: goto label_1f17e8;
            case 0x1F17FCu: goto label_1f17fc;
            case 0x1F1810u: goto label_1f1810;
            case 0x1F1830u: goto label_1f1830;
            case 0x1F1848u: goto label_1f1848;
            case 0x1F1854u: goto label_1f1854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1700u;
    // 0x1f1700: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f1700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f1704: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f1704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f1708: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f1708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f170c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f170cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1710: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f1710u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f1714: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f1714u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1f1718: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f1718u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f171c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1f171cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f1720: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F1720u;
    SET_GPR_U32(ctx, 31, 0x1F1728u);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1728u; }
        if (ctx->pc != 0x1F1728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1728u; }
        if (ctx->pc != 0x1F1728u) { return; }
    }
    ctx->pc = 0x1F1728u;
label_1f1728:
    // 0x1f1728: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f1728u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f172c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f172cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1730: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1730u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1734: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f1734u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f1738: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f1738u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f173c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f173cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f1740: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1740u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F16E0u: goto label_1f16e0;
            case 0x1F1728u: goto label_1f1728;
            case 0x1F177Cu: goto label_1f177c;
            case 0x1F178Cu: goto label_1f178c;
            case 0x1F17A8u: goto label_1f17a8;
            case 0x1F17B4u: goto label_1f17b4;
            case 0x1F17B8u: goto label_1f17b8;
            case 0x1F17E8u: goto label_1f17e8;
            case 0x1F17FCu: goto label_1f17fc;
            case 0x1F1810u: goto label_1f1810;
            case 0x1F1830u: goto label_1f1830;
            case 0x1F1848u: goto label_1f1848;
            case 0x1F1854u: goto label_1f1854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1748u;
    // 0x1f1748: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f1748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f174c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f174cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f1750: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f1750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f1754: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1754u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1758: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f1758u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f175c: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f175cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1f1760: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1764: 0x9442000c  lhu         $v0, 0xC($v0)
    ctx->pc = 0x1f1764u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f1768: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1768u;
    {
        const bool branch_taken_0x1f1768 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1768) {
            ctx->pc = 0x1F177Cu;
            goto label_1f177c;
        }
    }
    ctx->pc = 0x1F1770u;
    // 0x1f1770: 0x2402e4ab  addiu       $v0, $zero, -0x1B55
    ctx->pc = 0x1f1770u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960299));
    // 0x1f1774: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F1774u;
    {
        const bool branch_taken_0x1f1774 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1774) {
            ctx->pc = 0x1F17B8u;
            goto label_1f17b8;
        }
    }
    ctx->pc = 0x1F177Cu;
label_1f177c:
    // 0x1f177c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f177cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1780: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1f1780u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f1784: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F1784u;
    SET_GPR_U32(ctx, 31, 0x1F178Cu);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F178Cu; }
        if (ctx->pc != 0x1F178Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F178Cu; }
        if (ctx->pc != 0x1F178Cu) { return; }
    }
    ctx->pc = 0x1F178Cu;
label_1f178c:
    // 0x1f178c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f178cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f1790: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1790u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1794: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1794u;
    {
        const bool branch_taken_0x1f1794 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1794) {
            ctx->pc = 0x1F17A8u;
            goto label_1f17a8;
        }
    }
    ctx->pc = 0x1F179Cu;
    // 0x1f179c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f179cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f17a0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F17A0u;
    {
        const bool branch_taken_0x1f17a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f17a0) {
            ctx->pc = 0x1F17B8u;
            goto label_1f17b8;
        }
    }
    ctx->pc = 0x1F17A8u;
label_1f17a8:
    // 0x1f17a8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f17a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f17ac: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1F17ACu;
    SET_GPR_U32(ctx, 31, 0x1F17B4u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F17B4u; }
        if (ctx->pc != 0x1F17B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F17B4u; }
        if (ctx->pc != 0x1F17B4u) { return; }
    }
    ctx->pc = 0x1F17B4u;
label_1f17b4:
    // 0x1f17b4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f17b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
label_1f17b8:
    // 0x1f17b8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f17b8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f17bc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f17bcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f17c0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f17c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f17c4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f17c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f17c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F17C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F16E0u: goto label_1f16e0;
            case 0x1F1728u: goto label_1f1728;
            case 0x1F177Cu: goto label_1f177c;
            case 0x1F178Cu: goto label_1f178c;
            case 0x1F17A8u: goto label_1f17a8;
            case 0x1F17B4u: goto label_1f17b4;
            case 0x1F17B8u: goto label_1f17b8;
            case 0x1F17E8u: goto label_1f17e8;
            case 0x1F17FCu: goto label_1f17fc;
            case 0x1F1810u: goto label_1f1810;
            case 0x1F1830u: goto label_1f1830;
            case 0x1F1848u: goto label_1f1848;
            case 0x1F1854u: goto label_1f1854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F17D0u;
    // 0x1f17d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f17d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f17d4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f17d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f17d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f17d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f17dc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f17dcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f17e0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f17e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f17e4: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f17e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1f17e8:
    // 0x1f17e8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f17e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f17ec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F17ECu;
    {
        const bool branch_taken_0x1f17ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f17ec) {
            ctx->pc = 0x1F17FCu;
            goto label_1f17fc;
        }
    }
    ctx->pc = 0x1F17F4u;
    // 0x1f17f4: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1F17F4u;
    {
        const bool branch_taken_0x1f17f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f17f4) {
            ctx->pc = 0x1F1854u;
            goto label_1f1854;
        }
    }
    ctx->pc = 0x1F17FCu;
label_1f17fc:
    // 0x1f17fc: 0x27c20008  addiu       $v0, $fp, 0x8
    ctx->pc = 0x1f17fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f1800: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f1800u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1804: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f1804u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1808: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1F1808u;
    SET_GPR_U32(ctx, 31, 0x1F1810u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1810u; }
        if (ctx->pc != 0x1F1810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1810u; }
        if (ctx->pc != 0x1F1810u) { return; }
    }
    ctx->pc = 0x1F1810u;
label_1f1810:
    // 0x1f1810: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f1810u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f1814: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f1814u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1818: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1f1818u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1f181c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F181Cu;
    {
        const bool branch_taken_0x1f181c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f181c) {
            ctx->pc = 0x1F1830u;
            goto label_1f1830;
        }
    }
    ctx->pc = 0x1F1824u;
    // 0x1f1824: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f1824u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1f1828: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1F1828u;
    {
        const bool branch_taken_0x1f1828 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1828) {
            ctx->pc = 0x1F1854u;
            goto label_1f1854;
        }
    }
    ctx->pc = 0x1F1830u;
label_1f1830:
    // 0x1f1830: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1830u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1834: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1F1834u;
    {
        const bool branch_taken_0x1f1834 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f1834) {
            ctx->pc = 0x1F17E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f17e8;
        }
    }
    ctx->pc = 0x1F183Cu;
    // 0x1f183c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1f183cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1840: 0xc07c716  jal         func_1F1C58
    ctx->pc = 0x1F1840u;
    SET_GPR_U32(ctx, 31, 0x1F1848u);
    ctx->pc = 0x1F1C58u;
    if (runtime->hasFunction(0x1F1C58u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1848u; }
        if (ctx->pc != 0x1F1848u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C58_0x1f1c58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1848u; }
        if (ctx->pc != 0x1F1848u) { return; }
    }
    ctx->pc = 0x1F1848u;
label_1f1848:
    // 0x1f1848: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f1848u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f184c: 0x1000ffe6  b           . + 4 + (-0x1A << 2)
    ctx->pc = 0x1F184Cu;
    {
        const bool branch_taken_0x1f184c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f184c) {
            ctx->pc = 0x1F17E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f17e8;
        }
    }
    ctx->pc = 0x1F1854u;
label_1f1854:
    // 0x1f1854: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1858: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1858u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f185c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f185cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f1860: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f1860u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f1864: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f1864u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f1868: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1868u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F16E0u: goto label_1f16e0;
            case 0x1F1728u: goto label_1f1728;
            case 0x1F177Cu: goto label_1f177c;
            case 0x1F178Cu: goto label_1f178c;
            case 0x1F17A8u: goto label_1f17a8;
            case 0x1F17B4u: goto label_1f17b4;
            case 0x1F17B8u: goto label_1f17b8;
            case 0x1F17E8u: goto label_1f17e8;
            case 0x1F17FCu: goto label_1f17fc;
            case 0x1F1810u: goto label_1f1810;
            case 0x1F1830u: goto label_1f1830;
            case 0x1F1848u: goto label_1f1848;
            case 0x1F1854u: goto label_1f1854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1870u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
