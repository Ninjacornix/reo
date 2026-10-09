#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138AA0
// Address: 0x138aa0 - 0x138ab8
void sub_00138AA0_0x138aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138AA0_0x138aa0");
#endif

    ctx->pc = 0x138aa0u;

    // 0x138aa0: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x138aa4: 0x2463bc04  addiu       $v1, $v1, -0x43FC
    ctx->pc = 0x138aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949892));
    // 0x138aa8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x138aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x138aac: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x138aacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x138ab0: 0x3e00008  jr          $ra
    ctx->pc = 0x138AB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138AB0u;
            // 0x138ab4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x138AB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
