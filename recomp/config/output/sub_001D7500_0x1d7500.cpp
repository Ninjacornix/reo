#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7500
// Address: 0x1d7500 - 0x1d7540
void sub_001D7500_0x1d7500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7500_0x1d7500");
#endif

    switch (ctx->pc) {
        case 0x1d7510u: goto label_1d7510;
        default: break;
    }

    ctx->pc = 0x1d7500u;

    // 0x1d7500: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7504: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7508: 0xc0760d8  jal         func_1D8360
    ctx->pc = 0x1D7508u;
    SET_GPR_U32(ctx, 31, 0x1D7510u);
    ctx->pc = 0x1D8360u;
    if (runtime->hasFunction(0x1D8360u)) {
        auto targetFn = runtime->lookupFunction(0x1D8360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7510u; }
        if (ctx->pc != 0x1D7510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8360_0x1d8360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7510u; }
        if (ctx->pc != 0x1D7510u) { return; }
    }
    ctx->pc = 0x1D7510u;
label_1d7510:
    // 0x1d7510: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7510u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7514: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7514u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7518: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D7518u;
    {
        const bool branch_taken_0x1d7518 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d7518) {
            ctx->pc = 0x1D7528u;
            goto label_1d7528;
        }
    }
    ctx->pc = 0x1D7520u;
    // 0x1d7520: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D7520u;
    {
        const bool branch_taken_0x1d7520 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7520u;
            // 0x1d7524: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7520) {
            ctx->pc = 0x1D7530u;
            goto label_1d7530;
        }
    }
    ctx->pc = 0x1D7528u;
label_1d7528:
    // 0x1d7528: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7528u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d752c: 0xa0204605  sb          $zero, 0x4605($at)
    ctx->pc = 0x1d752cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17925), (uint8_t)GPR_U32(ctx, 0));
label_1d7530:
    // 0x1d7530: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d7530u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7534: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7534u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7534u;
            // 0x1d7538: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7510u: goto label_1d7510;
            case 0x1D7528u: goto label_1d7528;
            case 0x1D7530u: goto label_1d7530;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D753Cu;
    // 0x1d753c: 0x0  nop
    ctx->pc = 0x1d753cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
