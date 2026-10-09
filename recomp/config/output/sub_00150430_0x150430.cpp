#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150430
// Address: 0x150430 - 0x150458
void sub_00150430_0x150430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150430_0x150430");
#endif

    switch (ctx->pc) {
        case 0x15044cu: goto label_15044c;
        default: break;
    }

    ctx->pc = 0x150430u;

    // 0x150430: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x150434: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150434u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150438: 0x8c42d83c  lw          $v0, -0x27C4($v0)
    ctx->pc = 0x150438u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957116)));
    // 0x15043c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15043Cu;
    {
        const bool branch_taken_0x15043c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15043Cu;
            // 0x150440: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15043c) {
            ctx->pc = 0x15044Cu;
            goto label_15044c;
        }
    }
    ctx->pc = 0x150444u;
    // 0x150444: 0x40f809  jalr        $v0
    ctx->pc = 0x150444u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15044Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15044Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15044Cu: goto label_15044c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15044Cu; }
            if (ctx->pc != 0x15044Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15044Cu;
label_15044c:
    // 0x15044c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15044cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150450: 0x3e00008  jr          $ra
    ctx->pc = 0x150450u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150450u;
            // 0x150454: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15044Cu: goto label_15044c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150458u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
