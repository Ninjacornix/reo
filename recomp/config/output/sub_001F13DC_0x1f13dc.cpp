#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F13DC
// Address: 0x1f13dc - 0x1f15b4
void sub_001F13DC_0x1f13dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F13DC_0x1f13dc");
#endif

    switch (ctx->pc) {
        case 0x1f1408u: goto label_1f1408;
        case 0x1f1480u: goto label_1f1480;
        case 0x1f14e8u: goto label_1f14e8;
        case 0x1f1510u: goto label_1f1510;
        case 0x1f153cu: goto label_1f153c;
        case 0x1f157cu: goto label_1f157c;
        default: break;
    }

    ctx->pc = 0x1f13dcu;

    // 0x1f13dc: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f13dcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f13e0: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f13e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f13e4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f13e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f13e8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f13e8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f13ec: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f13ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f13f0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f13f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f13f4: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f13f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f13f8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f13f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f13fc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f13fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f1400: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F1400u;
    SET_GPR_U32(ctx, 31, 0x1F1408u);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1408u; }
        if (ctx->pc != 0x1F1408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1408u; }
        if (ctx->pc != 0x1F1408u) { return; }
    }
    ctx->pc = 0x1F1408u;
label_1f1408:
    // 0x1f1408: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1408u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f140c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f140cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1410: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1410u;
    {
        const bool branch_taken_0x1f1410 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1410) {
            ctx->pc = 0x1F1424u;
            goto label_1f1424;
        }
    }
    ctx->pc = 0x1F1418u;
    // 0x1f1418: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1418u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f141c: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1F141Cu;
    {
        const bool branch_taken_0x1f141c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f141c) {
            ctx->pc = 0x1F14A0u;
            goto label_1f14a0;
        }
    }
    ctx->pc = 0x1F1424u;
label_1f1424:
    // 0x1f1424: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f1424u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1428: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1428u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f142c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f142cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1430: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f1430u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f1434: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f1434u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1438: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1438u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f143c: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1f143cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1f1440: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f1440u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1444: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f1444u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1448: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f1448u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f144c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f144cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1450: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1f1450u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1454: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f1454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1458: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1f1458u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1f145c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f145cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1460: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1460u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1464: 0x9442000c  lhu         $v0, 0xC($v0)
    ctx->pc = 0x1f1464u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f1468: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f1468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f146c: 0xa462000c  sh          $v0, 0xC($v1)
    ctx->pc = 0x1f146cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1470: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f1470u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1474: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1f1474u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f1478: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F1478u;
    SET_GPR_U32(ctx, 31, 0x1F1480u);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1480u; }
        if (ctx->pc != 0x1F1480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1480u; }
        if (ctx->pc != 0x1F1480u) { return; }
    }
    ctx->pc = 0x1F1480u;
label_1f1480:
    // 0x1f1480: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1480u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1484: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1484u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1488: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1488u;
    {
        const bool branch_taken_0x1f1488 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1488) {
            ctx->pc = 0x1F149Cu;
            goto label_1f149c;
        }
    }
    ctx->pc = 0x1F1490u;
    // 0x1f1490: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1494: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F1494u;
    {
        const bool branch_taken_0x1f1494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1494) {
            ctx->pc = 0x1F14A0u;
            goto label_1f14a0;
        }
    }
    ctx->pc = 0x1F149Cu;
label_1f149c:
    // 0x1f149c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f149cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_1f14a0:
    // 0x1f14a0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f14a0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f14a4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f14a4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f14a8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f14a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f14ac: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f14acu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f14b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F14B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1408u: goto label_1f1408;
            case 0x1F1424u: goto label_1f1424;
            case 0x1F1480u: goto label_1f1480;
            case 0x1F149Cu: goto label_1f149c;
            case 0x1F14A0u: goto label_1f14a0;
            case 0x1F14E8u: goto label_1f14e8;
            case 0x1F1504u: goto label_1f1504;
            case 0x1F1510u: goto label_1f1510;
            case 0x1F1528u: goto label_1f1528;
            case 0x1F153Cu: goto label_1f153c;
            case 0x1F1558u: goto label_1f1558;
            case 0x1F156Cu: goto label_1f156c;
            case 0x1F157Cu: goto label_1f157c;
            case 0x1F1598u: goto label_1f1598;
            case 0x1F159Cu: goto label_1f159c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F14B8u;
    // 0x1f14b8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f14b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f14bc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f14bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f14c0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f14c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f14c4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f14c4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f14c8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f14c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f14cc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f14ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f14d0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f14d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f14d4: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1f14d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1f14d8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f14d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f14dc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f14dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f14e0: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F14E0u;
    SET_GPR_U32(ctx, 31, 0x1F14E8u);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F14E8u; }
        if (ctx->pc != 0x1F14E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F14E8u; }
        if (ctx->pc != 0x1F14E8u) { return; }
    }
    ctx->pc = 0x1F14E8u;
label_1f14e8:
    // 0x1f14e8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f14e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f14ec: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f14ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f14f0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F14F0u;
    {
        const bool branch_taken_0x1f14f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f14f0) {
            ctx->pc = 0x1F1504u;
            goto label_1f1504;
        }
    }
    ctx->pc = 0x1F14F8u;
    // 0x1f14f8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f14f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f14fc: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1F14FCu;
    {
        const bool branch_taken_0x1f14fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f14fc) {
            ctx->pc = 0x1F159Cu;
            goto label_1f159c;
        }
    }
    ctx->pc = 0x1F1504u;
label_1f1504:
    // 0x1f1504: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1504u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1508: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f1508u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f150c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f150cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_1f1510:
    // 0x1f1510: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1510u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1514: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1514u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1518: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F1518u;
    {
        const bool branch_taken_0x1f1518 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f1518) {
            ctx->pc = 0x1F1528u;
            goto label_1f1528;
        }
    }
    ctx->pc = 0x1F1520u;
    // 0x1f1520: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1F1520u;
    {
        const bool branch_taken_0x1f1520 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1520) {
            ctx->pc = 0x1F156Cu;
            goto label_1f156c;
        }
    }
    ctx->pc = 0x1F1528u;
label_1f1528:
    // 0x1f1528: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1528u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f152c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1f152cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1530: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1f1530u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1534: 0x40f809  jalr        $v0
    ctx->pc = 0x1F1534u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1F153Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1F153Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1408u: goto label_1f1408;
            case 0x1F1424u: goto label_1f1424;
            case 0x1F1480u: goto label_1f1480;
            case 0x1F149Cu: goto label_1f149c;
            case 0x1F14A0u: goto label_1f14a0;
            case 0x1F14E8u: goto label_1f14e8;
            case 0x1F1504u: goto label_1f1504;
            case 0x1F1510u: goto label_1f1510;
            case 0x1F1528u: goto label_1f1528;
            case 0x1F153Cu: goto label_1f153c;
            case 0x1F1558u: goto label_1f1558;
            case 0x1F156Cu: goto label_1f156c;
            case 0x1F157Cu: goto label_1f157c;
            case 0x1F1598u: goto label_1f1598;
            case 0x1F159Cu: goto label_1f159c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1F153Cu; }
            if (ctx->pc != 0x1F153Cu) { return; }
        }
        }
    }
    ctx->pc = 0x1F153Cu;
label_1f153c:
    // 0x1f153c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f153cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1540: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1544: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1544u;
    {
        const bool branch_taken_0x1f1544 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1544) {
            ctx->pc = 0x1F1558u;
            goto label_1f1558;
        }
    }
    ctx->pc = 0x1F154Cu;
    // 0x1f154c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f154cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1550: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1F1550u;
    {
        const bool branch_taken_0x1f1550 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1550) {
            ctx->pc = 0x1F159Cu;
            goto label_1f159c;
        }
    }
    ctx->pc = 0x1F1558u;
label_1f1558:
    // 0x1f1558: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1558u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f155c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f155cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1560: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f1560u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f1564: 0x1000ffea  b           . + 4 + (-0x16 << 2)
    ctx->pc = 0x1F1564u;
    {
        const bool branch_taken_0x1f1564 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1564) {
            ctx->pc = 0x1F1510u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f1510;
        }
    }
    ctx->pc = 0x1F156Cu;
label_1f156c:
    // 0x1f156c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f156cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1570: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1f1570u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f1574: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F1574u;
    SET_GPR_U32(ctx, 31, 0x1F157Cu);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F157Cu; }
        if (ctx->pc != 0x1F157Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F157Cu; }
        if (ctx->pc != 0x1F157Cu) { return; }
    }
    ctx->pc = 0x1F157Cu;
label_1f157c:
    // 0x1f157c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f157cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1580: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1580u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1584: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1584u;
    {
        const bool branch_taken_0x1f1584 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1584) {
            ctx->pc = 0x1F1598u;
            goto label_1f1598;
        }
    }
    ctx->pc = 0x1F158Cu;
    // 0x1f158c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f158cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1590: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F1590u;
    {
        const bool branch_taken_0x1f1590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1590) {
            ctx->pc = 0x1F159Cu;
            goto label_1f159c;
        }
    }
    ctx->pc = 0x1F1598u;
label_1f1598:
    // 0x1f1598: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1598u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_1f159c:
    // 0x1f159c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f159cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f15a0: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f15a0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f15a4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f15a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f15a8: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f15a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f15ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1F15ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1408u: goto label_1f1408;
            case 0x1F1424u: goto label_1f1424;
            case 0x1F1480u: goto label_1f1480;
            case 0x1F149Cu: goto label_1f149c;
            case 0x1F14A0u: goto label_1f14a0;
            case 0x1F14E8u: goto label_1f14e8;
            case 0x1F1504u: goto label_1f1504;
            case 0x1F1510u: goto label_1f1510;
            case 0x1F1528u: goto label_1f1528;
            case 0x1F153Cu: goto label_1f153c;
            case 0x1F1558u: goto label_1f1558;
            case 0x1F156Cu: goto label_1f156c;
            case 0x1F157Cu: goto label_1f157c;
            case 0x1F1598u: goto label_1f1598;
            case 0x1F159Cu: goto label_1f159c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F15B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
