#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D68A0
// Address: 0x1d68a0 - 0x1d68b0
void sub_001D68A0_0x1d68a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D68A0_0x1d68a0");
#endif

    ctx->pc = 0x1d68a0u;

    // 0x1d68a0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d68a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d68a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D68A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D68A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D68A4u;
            // 0x1d68a8: 0x8c2245f8  lw          $v0, 0x45F8($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17912)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D68ACu;
    // 0x1d68ac: 0x0  nop
    ctx->pc = 0x1d68acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
