#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3830
// Address: 0x1b3830 - 0x1b3860
void sub_001B3830_0x1b3830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3830_0x1b3830");
#endif

    ctx->pc = 0x1b3830u;

    // 0x1b3830: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b3830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b3834: 0xffa50018  sd          $a1, 0x18($sp)
    ctx->pc = 0x1b3834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 5));
    // 0x1b3838: 0xffa60020  sd          $a2, 0x20($sp)
    ctx->pc = 0x1b3838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 6));
    // 0x1b383c: 0xffa70028  sd          $a3, 0x28($sp)
    ctx->pc = 0x1b383cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 7));
    // 0x1b3840: 0xffa80030  sd          $t0, 0x30($sp)
    ctx->pc = 0x1b3840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 8));
    // 0x1b3844: 0xffa90038  sd          $t1, 0x38($sp)
    ctx->pc = 0x1b3844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 9));
    // 0x1b3848: 0xffaa0040  sd          $t2, 0x40($sp)
    ctx->pc = 0x1b3848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 10));
    // 0x1b384c: 0xffab0048  sd          $t3, 0x48($sp)
    ctx->pc = 0x1b384cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 11));
    // 0x1b3850: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3850u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B3854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3850u;
            // 0x1b3854: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B3858u;
    // 0x1b3858: 0x0  nop
    ctx->pc = 0x1b3858u;
    // NOP
    // 0x1b385c: 0x0  nop
    ctx->pc = 0x1b385cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
