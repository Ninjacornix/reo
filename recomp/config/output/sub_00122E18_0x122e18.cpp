#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122E18
// Address: 0x122e18 - 0x122e20
void sub_00122E18_0x122e18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122E18_0x122e18");
#endif

    ctx->pc = 0x122e18u;

    // 0x122e18: 0x3e00008  jr          $ra
    ctx->pc = 0x122E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E18u;
            // 0x122e1c: 0x8c820020  lw          $v0, 0x20($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x122E20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
