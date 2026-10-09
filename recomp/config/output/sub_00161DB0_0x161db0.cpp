#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161DB0
// Address: 0x161db0 - 0x161dc8
void sub_00161DB0_0x161db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161DB0_0x161db0");
#endif

    ctx->pc = 0x161db0u;

    // 0x161db0: 0x24840100  addiu       $a0, $a0, 0x100
    ctx->pc = 0x161db0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 256));
    // 0x161db4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x161db4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x161db8: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x161db8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x161dbc: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x161dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x161dc0: 0x3e00008  jr          $ra
    ctx->pc = 0x161DC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161DC0u;
            // 0x161dc4: 0xaca30000  sw          $v1, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x161DC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
