#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138BD0
// Address: 0x138bd0 - 0x138be0
void sub_00138BD0_0x138bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138BD0_0x138bd0");
#endif

    ctx->pc = 0x138bd0u;

    // 0x138bd0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x138bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138bd4: 0xac80003c  sw          $zero, 0x3C($a0)
    ctx->pc = 0x138bd4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 0));
    // 0x138bd8: 0x3e00008  jr          $ra
    ctx->pc = 0x138BD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138BD8u;
            // 0x138bdc: 0xa0820001  sb          $v0, 0x1($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x138BE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
