#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EDF0
// Address: 0x15edf0 - 0x15edfc
void sub_0015EDF0_0x15edf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EDF0_0x15edf0");
#endif

    ctx->pc = 0x15edf0u;

    // 0x15edf0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15edf0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15edf4: 0x3e00008  jr          $ra
    ctx->pc = 0x15EDF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EDF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EDF4u;
            // 0x15edf8: 0x8c62ef40  lw          $v0, -0x10C0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294963008)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15EDFCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
