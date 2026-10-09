#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DD50
// Address: 0x12dd50 - 0x12dd5c
void sub_0012DD50_0x12dd50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DD50_0x12dd50");
#endif

    ctx->pc = 0x12dd50u;

    // 0x12dd50: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x12dd50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x12dd54: 0x3e00008  jr          $ra
    ctx->pc = 0x12DD54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DD58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD54u;
            // 0x12dd58: 0x2442add8  addiu       $v0, $v0, -0x5228 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294946264));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12DD5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
