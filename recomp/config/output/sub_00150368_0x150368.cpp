#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150368
// Address: 0x150368 - 0x150390
void sub_00150368_0x150368(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150368_0x150368");
#endif

    switch (ctx->pc) {
        case 0x150384u: goto label_150384;
        default: break;
    }

    ctx->pc = 0x150368u;

    // 0x150368: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150368u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15036c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15036cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150370: 0x8c42d828  lw          $v0, -0x27D8($v0)
    ctx->pc = 0x150370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957096)));
    // 0x150374: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x150374u;
    {
        const bool branch_taken_0x150374 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150374u;
            // 0x150378: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150374) {
            ctx->pc = 0x150384u;
            goto label_150384;
        }
    }
    ctx->pc = 0x15037Cu;
    // 0x15037c: 0x40f809  jalr        $v0
    ctx->pc = 0x15037Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150384u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x150384u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150384u: goto label_150384;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150384u; }
            if (ctx->pc != 0x150384u) { return; }
        }
        }
    }
    ctx->pc = 0x150384u;
label_150384:
    // 0x150384: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x150384u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150388: 0x3e00008  jr          $ra
    ctx->pc = 0x150388u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15038Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150388u;
            // 0x15038c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150384u: goto label_150384;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150390u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
