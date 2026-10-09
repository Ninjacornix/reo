#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2740
// Address: 0x1b2740 - 0x1b278c
void sub_001B2740_0x1b2740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2740_0x1b2740");
#endif

    switch (ctx->pc) {
        case 0x1b2754u: goto label_1b2754;
        case 0x1b275cu: goto label_1b275c;
        case 0x1b2778u: goto label_1b2778;
        default: break;
    }

    ctx->pc = 0x1b2740u;

    // 0x1b2740: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b2740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b2744: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b2744u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b2748: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b2748u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b274c: 0x244288e0  addiu       $v0, $v0, -0x7720
    ctx->pc = 0x1b274cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936800));
    // 0x1b2750: 0xafa2001c  sw          $v0, 0x1C($sp)
    ctx->pc = 0x1b2750u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
label_1b2754:
    // 0x1b2754: 0xc06970c  jal         func_1A5C30
    ctx->pc = 0x1B2754u;
    SET_GPR_U32(ctx, 31, 0x1B275Cu);
    ctx->pc = 0x1B2758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2754u;
            // 0x1b2758: 0x27a4001c  addiu       $a0, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5C30u;
    if (runtime->hasFunction(0x1A5C30u)) {
        auto targetFn = runtime->lookupFunction(0x1A5C30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B275Cu; }
        if (ctx->pc != 0x1B275Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5C30_0x1a5c30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B275Cu; }
        if (ctx->pc != 0x1B275Cu) { return; }
    }
    ctx->pc = 0x1B275Cu;
label_1b275c:
    // 0x1b275c: 0xafa2001c  sw          $v0, 0x1C($sp)
    ctx->pc = 0x1b275cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x1b2760: 0x8fa4001c  lw          $a0, 0x1C($sp)
    ctx->pc = 0x1b2760u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1b2764: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B2764u;
    {
        const bool branch_taken_0x1b2764 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2764) {
            ctx->pc = 0x1B2780u;
            goto label_1b2780;
        }
    }
    ctx->pc = 0x1B276Cu;
    // 0x1b276c: 0x8c82001c  lw          $v0, 0x1C($a0)
    ctx->pc = 0x1b276cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1b2770: 0x40f809  jalr        $v0
    ctx->pc = 0x1B2770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B2778u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1B2778u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2754u: goto label_1b2754;
            case 0x1B275Cu: goto label_1b275c;
            case 0x1B2778u: goto label_1b2778;
            case 0x1B2780u: goto label_1b2780;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B2778u; }
            if (ctx->pc != 0x1B2778u) { return; }
        }
        }
    }
    ctx->pc = 0x1B2778u;
label_1b2778:
    // 0x1b2778: 0x1000fff6  b           . + 4 + (-0xA << 2)
    ctx->pc = 0x1B2778u;
    {
        const bool branch_taken_0x1b2778 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2778) {
            ctx->pc = 0x1B2754u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2754;
        }
    }
    ctx->pc = 0x1B2780u;
label_1b2780:
    // 0x1b2780: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b2780u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2784: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2784u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2784u;
            // 0x1b2788: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2754u: goto label_1b2754;
            case 0x1B275Cu: goto label_1b275c;
            case 0x1B2778u: goto label_1b2778;
            case 0x1B2780u: goto label_1b2780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B278Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
