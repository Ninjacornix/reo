#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1700
// Address: 0x1f1700 - 0x1f1748
void sub_001F1700_0x1f1700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1700_0x1f1700");
#endif

    switch (ctx->pc) {
        case 0x1f1728u: goto label_1f1728;
        default: break;
    }

    ctx->pc = 0x1f1700u;

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
            case 0x1F1728u: goto label_1f1728;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1748u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
