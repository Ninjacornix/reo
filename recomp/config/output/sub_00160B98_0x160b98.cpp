#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160B98
// Address: 0x160b98 - 0x160ba0
void sub_00160B98_0x160b98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160B98_0x160b98");
#endif

    ctx->pc = 0x160b98u;

    // 0x160b98: 0x3e00008  jr          $ra
    ctx->pc = 0x160B98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160B98u;
            // 0x160b9c: 0xac8500a8  sw          $a1, 0xA8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 168), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x160BA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
