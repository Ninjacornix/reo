#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150408
// Address: 0x150408 - 0x150430
void sub_00150408_0x150408(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150408_0x150408");
#endif

    switch (ctx->pc) {
        case 0x150424u: goto label_150424;
        default: break;
    }

    ctx->pc = 0x150408u;

    // 0x150408: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150408u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15040c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15040cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150410: 0x8c42d838  lw          $v0, -0x27C8($v0)
    ctx->pc = 0x150410u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957112)));
    // 0x150414: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x150414u;
    {
        const bool branch_taken_0x150414 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150414u;
            // 0x150418: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150414) {
            ctx->pc = 0x150424u;
            goto label_150424;
        }
    }
    ctx->pc = 0x15041Cu;
    // 0x15041c: 0x40f809  jalr        $v0
    ctx->pc = 0x15041Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150424u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x150424u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150424u: goto label_150424;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150424u; }
            if (ctx->pc != 0x150424u) { return; }
        }
        }
    }
    ctx->pc = 0x150424u;
label_150424:
    // 0x150424: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x150424u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150428: 0x3e00008  jr          $ra
    ctx->pc = 0x150428u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15042Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150428u;
            // 0x15042c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150424u: goto label_150424;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150430u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
