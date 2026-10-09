#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001382E0
// Address: 0x1382e0 - 0x1382ec
void sub_001382E0_0x1382e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001382E0_0x1382e0");
#endif

    ctx->pc = 0x1382e0u;

    // 0x1382e0: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1382e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1382e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1382E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1382E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1382E4u;
            // 0x1382e8: 0x8c62bbfc  lw          $v0, -0x4404($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294949884)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1382ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
