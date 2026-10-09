#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150340
// Address: 0x150340 - 0x150368
void sub_00150340_0x150340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150340_0x150340");
#endif

    switch (ctx->pc) {
        case 0x15035cu: goto label_15035c;
        default: break;
    }

    ctx->pc = 0x150340u;

    // 0x150340: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150340u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x150344: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150344u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150348: 0x8c42d820  lw          $v0, -0x27E0($v0)
    ctx->pc = 0x150348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957088)));
    // 0x15034c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15034Cu;
    {
        const bool branch_taken_0x15034c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15034Cu;
            // 0x150350: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15034c) {
            ctx->pc = 0x15035Cu;
            goto label_15035c;
        }
    }
    ctx->pc = 0x150354u;
    // 0x150354: 0x40f809  jalr        $v0
    ctx->pc = 0x150354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15035Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15035Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15035Cu: goto label_15035c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15035Cu; }
            if (ctx->pc != 0x15035Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15035Cu;
label_15035c:
    // 0x15035c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15035cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150360: 0x3e00008  jr          $ra
    ctx->pc = 0x150360u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150360u;
            // 0x150364: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15035Cu: goto label_15035c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150368u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
