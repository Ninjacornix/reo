#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001381E8
// Address: 0x1381e8 - 0x1381f8
void sub_001381E8_0x1381e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001381E8_0x1381e8");
#endif

    ctx->pc = 0x1381e8u;

    // 0x1381e8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1381e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1381ec: 0x2463bbe4  addiu       $v1, $v1, -0x441C
    ctx->pc = 0x1381ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949860));
    // 0x1381f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1381F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1381F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1381F0u;
            // 0x1381f4: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1381F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
