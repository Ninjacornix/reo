#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2520
// Address: 0x1d2520 - 0x1d2550
void sub_001D2520_0x1d2520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2520_0x1d2520");
#endif

    switch (ctx->pc) {
        case 0x1d2544u: goto label_1d2544;
        default: break;
    }

    ctx->pc = 0x1d2520u;

    // 0x1d2520: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2524: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d2524u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2528: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d252c: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d252cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2530: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2530u;
    {
        const bool branch_taken_0x1d2530 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D2534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2530u;
            // 0x1d2534: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2530) {
            ctx->pc = 0x1D2544u;
            goto label_1d2544;
        }
    }
    ctx->pc = 0x1D2538u;
    // 0x1d2538: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1d2538u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d253c: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D253Cu;
    SET_GPR_U32(ctx, 31, 0x1D2544u);
    ctx->pc = 0x1D2540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D253Cu;
            // 0x1d2540: 0x24052400  addiu       $a1, $zero, 0x2400 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2544u; }
        if (ctx->pc != 0x1D2544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2544u; }
        if (ctx->pc != 0x1D2544u) { return; }
    }
    ctx->pc = 0x1D2544u;
label_1d2544:
    // 0x1d2544: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d2544u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2548: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2548u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D254Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2548u;
            // 0x1d254c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2544u: goto label_1d2544;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2550u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
