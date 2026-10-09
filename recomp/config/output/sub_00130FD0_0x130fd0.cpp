#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130FD0
// Address: 0x130fd0 - 0x130fdc
void sub_00130FD0_0x130fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130FD0_0x130fd0");
#endif

    ctx->pc = 0x130fd0u;

    // 0x130fd0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x130fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x130fd4: 0x3e00008  jr          $ra
    ctx->pc = 0x130FD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130FD4u;
            // 0x130fd8: 0xac44a8b4  sw          $a0, -0x574C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294944948), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130FDCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
