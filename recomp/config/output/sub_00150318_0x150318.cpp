#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150318
// Address: 0x150318 - 0x150340
void sub_00150318_0x150318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150318_0x150318");
#endif

    switch (ctx->pc) {
        case 0x150334u: goto label_150334;
        default: break;
    }

    ctx->pc = 0x150318u;

    // 0x150318: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150318u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15031c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15031cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150320: 0x8c42d824  lw          $v0, -0x27DC($v0)
    ctx->pc = 0x150320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957092)));
    // 0x150324: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x150324u;
    {
        const bool branch_taken_0x150324 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150324u;
            // 0x150328: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150324) {
            ctx->pc = 0x150334u;
            goto label_150334;
        }
    }
    ctx->pc = 0x15032Cu;
    // 0x15032c: 0x40f809  jalr        $v0
    ctx->pc = 0x15032Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150334u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x150334u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150334u: goto label_150334;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150334u; }
            if (ctx->pc != 0x150334u) { return; }
        }
        }
    }
    ctx->pc = 0x150334u;
label_150334:
    // 0x150334: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x150334u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150338: 0x3e00008  jr          $ra
    ctx->pc = 0x150338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15033Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150338u;
            // 0x15033c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150334u: goto label_150334;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150340u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
