#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F0F0
// Address: 0x13f0f0 - 0x13f100
void sub_0013F0F0_0x13f0f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F0F0_0x13f0f0");
#endif

    ctx->pc = 0x13f0f0u;

    // 0x13f0f0: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x13f0f0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x13f0f4: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x13f0f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x13f0f8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0F8u;
            // 0x13f0fc: 0x8ca20038  lw          $v0, 0x38($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 56)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F100u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
