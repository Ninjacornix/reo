#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138228
// Address: 0x138228 - 0x138238
void sub_00138228_0x138228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138228_0x138228");
#endif

    ctx->pc = 0x138228u;

    // 0x138228: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138228u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13822c: 0x2463bbf4  addiu       $v1, $v1, -0x440C
    ctx->pc = 0x13822cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949876));
    // 0x138230: 0x3e00008  jr          $ra
    ctx->pc = 0x138230u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138230u;
            // 0x138234: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x138238u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
