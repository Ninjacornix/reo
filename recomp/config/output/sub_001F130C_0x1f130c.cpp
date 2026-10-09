#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F130C
// Address: 0x1f130c - 0x1f13dc
void sub_001F130C_0x1f130c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F130C_0x1f130c");
#endif

    switch (ctx->pc) {
        case 0x1f1338u: goto label_1f1338;
        case 0x1f13a4u: goto label_1f13a4;
        default: break;
    }

    ctx->pc = 0x1f130cu;

    // 0x1f130c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f130cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f1310: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f1310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f1314: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f1314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f1318: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1318u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f131c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f131cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f1320: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f1320u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f1324: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1f1324u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1f1328: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f1328u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f132c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f132cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f1330: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F1330u;
    SET_GPR_U32(ctx, 31, 0x1F1338u);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1338u; }
        if (ctx->pc != 0x1F1338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1338u; }
        if (ctx->pc != 0x1F1338u) { return; }
    }
    ctx->pc = 0x1F1338u;
label_1f1338:
    // 0x1f1338: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f1338u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f133c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f133cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1340: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1340u;
    {
        const bool branch_taken_0x1f1340 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1340) {
            ctx->pc = 0x1F1354u;
            goto label_1f1354;
        }
    }
    ctx->pc = 0x1F1348u;
    // 0x1f1348: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f1348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f134c: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1F134Cu;
    {
        const bool branch_taken_0x1f134c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f134c) {
            ctx->pc = 0x1F13C4u;
            goto label_1f13c4;
        }
    }
    ctx->pc = 0x1F1354u;
label_1f1354:
    // 0x1f1354: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1358: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1f1358u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1f135c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f135cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1360: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f1360u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1364: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f1364u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f1368: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f136c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1f136cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1370: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1374: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1f1374u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1f1378: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1f1378u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1f137c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f137cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1380: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1380u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1384: 0x9443000c  lhu         $v1, 0xC($v0)
    ctx->pc = 0x1f1384u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f1388: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1f1388u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1f138c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f138cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f1390: 0xa482000c  sh          $v0, 0xC($a0)
    ctx->pc = 0x1f1390u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1394: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f1394u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1398: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1f1398u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f139c: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F139Cu;
    SET_GPR_U32(ctx, 31, 0x1F13A4u);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F13A4u; }
        if (ctx->pc != 0x1F13A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F13A4u; }
        if (ctx->pc != 0x1F13A4u) { return; }
    }
    ctx->pc = 0x1F13A4u;
label_1f13a4:
    // 0x1f13a4: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f13a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f13a8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f13a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f13ac: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F13ACu;
    {
        const bool branch_taken_0x1f13ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f13ac) {
            ctx->pc = 0x1F13C0u;
            goto label_1f13c0;
        }
    }
    ctx->pc = 0x1F13B4u;
    // 0x1f13b4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f13b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f13b8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F13B8u;
    {
        const bool branch_taken_0x1f13b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f13b8) {
            ctx->pc = 0x1F13C4u;
            goto label_1f13c4;
        }
    }
    ctx->pc = 0x1F13C0u;
label_1f13c0:
    // 0x1f13c0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f13c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
label_1f13c4:
    // 0x1f13c4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f13c4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f13c8: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f13c8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f13cc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f13ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f13d0: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f13d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f13d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F13D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1338u: goto label_1f1338;
            case 0x1F1354u: goto label_1f1354;
            case 0x1F13A4u: goto label_1f13a4;
            case 0x1F13C0u: goto label_1f13c0;
            case 0x1F13C4u: goto label_1f13c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F13DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
