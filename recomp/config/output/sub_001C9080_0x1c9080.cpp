#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C9080
// Address: 0x1c9080 - 0x1c90a0
void sub_001C9080_0x1c9080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C9080_0x1c9080");
#endif

    ctx->pc = 0x1c9080u;

    // 0x1c9080: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1c9080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1c9084: 0xffa80040  sd          $t0, 0x40($sp)
    ctx->pc = 0x1c9084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 8));
    // 0x1c9088: 0xffa90048  sd          $t1, 0x48($sp)
    ctx->pc = 0x1c9088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 9));
    // 0x1c908c: 0xffaa0050  sd          $t2, 0x50($sp)
    ctx->pc = 0x1c908cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 10));
    // 0x1c9090: 0xffab0058  sd          $t3, 0x58($sp)
    ctx->pc = 0x1c9090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 11));
    // 0x1c9094: 0x3e00008  jr          $ra
    ctx->pc = 0x1C9094u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C9098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9094u;
            // 0x1c9098: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C909Cu;
    // 0x1c909c: 0x0  nop
    ctx->pc = 0x1c909cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
