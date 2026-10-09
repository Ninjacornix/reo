#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CA98
// Address: 0x13ca98 - 0x13caa4
void sub_0013CA98_0x13ca98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CA98_0x13ca98");
#endif

    ctx->pc = 0x13ca98u;

    // 0x13ca98: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ca98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ca9c: 0x3e00008  jr          $ra
    ctx->pc = 0x13CA9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CAA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA9Cu;
            // 0x13caa0: 0x2442dea8  addiu       $v0, $v0, -0x2158 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958760));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13CAA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
