#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001417F0
// Address: 0x1417f0 - 0x141800
void sub_001417F0_0x1417f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001417F0_0x1417f0");
#endif

    ctx->pc = 0x1417f0u;

    // 0x1417f0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1417f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1417f4: 0x2463a5f4  addiu       $v1, $v1, -0x5A0C
    ctx->pc = 0x1417f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944244));
    // 0x1417f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1417F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1417FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1417F8u;
            // 0x1417fc: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x141800u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
