#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F17D0
// Address: 0x1f17d0 - 0x1f1870
void sub_001F17D0_0x1f17d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F17D0_0x1f17d0");
#endif

    switch (ctx->pc) {
        case 0x1f17e8u: goto label_1f17e8;
        case 0x1f1810u: goto label_1f1810;
        case 0x1f1848u: goto label_1f1848;
        default: break;
    }

    ctx->pc = 0x1f17d0u;

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
