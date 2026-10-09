#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001791F8
// Address: 0x1791f8 - 0x179208
void sub_001791F8_0x1791f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001791F8_0x1791f8");
#endif

    ctx->pc = 0x1791f8u;

    // 0x1791f8: 0xac860008  sw          $a2, 0x8($a0)
    ctx->pc = 0x1791f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 6));
    // 0x1791fc: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x1791fcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x179200: 0x3e00008  jr          $ra
    ctx->pc = 0x179200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179200u;
            // 0x179204: 0xac800004  sw          $zero, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x179208u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
