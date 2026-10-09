#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8C20
// Address: 0x1c8c20 - 0x1c8c30
void sub_001C8C20_0x1c8c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8C20_0x1c8c20");
#endif

    ctx->pc = 0x1c8c20u;

    // 0x1c8c20: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8c20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8c24: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8C24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8C28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8C24u;
            // 0x1c8c28: 0xa024b650  sb          $a0, -0x49B0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294948432), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C8C2Cu;
    // 0x1c8c2c: 0x0  nop
    ctx->pc = 0x1c8c2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
