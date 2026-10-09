#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EF28
// Address: 0x15ef28 - 0x15ef54
void sub_0015EF28_0x15ef28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EF28_0x15ef28");
#endif

    ctx->pc = 0x15ef28u;

    // 0x15ef28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ef28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ef2c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ef2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ef30: 0x4a00005  bltz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x15EF30u;
    {
        const bool branch_taken_0x15ef30 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x15EF34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF30u;
            // 0x15ef34: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ef30) {
            ctx->pc = 0x15EF48u;
            goto label_15ef48;
        }
    }
    ctx->pc = 0x15EF38u;
    // 0x15ef38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ef38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ef3c: 0x805cfaa  j           func_173EA8
    ctx->pc = 0x15EF3Cu;
    ctx->pc = 0x15EF40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF3Cu;
            // 0x15ef40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173EA8u;
    if (runtime->hasFunction(0x173EA8u)) {
        auto targetFn = runtime->lookupFunction(0x173EA8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00173EA8_0x173ea8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15EF44u;
    // 0x15ef44: 0x0  nop
    ctx->pc = 0x15ef44u;
    // NOP
label_15ef48:
    // 0x15ef48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ef48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ef4c: 0x3e00008  jr          $ra
    ctx->pc = 0x15EF4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EF50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF4Cu;
            // 0x15ef50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EF48u: goto label_15ef48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EF54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
