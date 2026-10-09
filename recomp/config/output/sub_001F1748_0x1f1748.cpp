#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1748
// Address: 0x1f1748 - 0x1f17d0
void sub_001F1748_0x1f1748(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1748_0x1f1748");
#endif

    switch (ctx->pc) {
        case 0x1f178cu: goto label_1f178c;
        case 0x1f17b4u: goto label_1f17b4;
        default: break;
    }

    ctx->pc = 0x1f1748u;

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
            case 0x1F177Cu: goto label_1f177c;
            case 0x1F178Cu: goto label_1f178c;
            case 0x1F17A8u: goto label_1f17a8;
            case 0x1F17B4u: goto label_1f17b4;
            case 0x1F17B8u: goto label_1f17b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F17D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
