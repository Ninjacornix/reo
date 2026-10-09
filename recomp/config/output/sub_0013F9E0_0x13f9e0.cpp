#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F9E0
// Address: 0x13f9e0 - 0x13f9ec
void sub_0013F9E0_0x13f9e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F9E0_0x13f9e0");
#endif

    ctx->pc = 0x13f9e0u;

    // 0x13f9e0: 0xac86003c  sw          $a2, 0x3C($a0)
    ctx->pc = 0x13f9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 6));
    // 0x13f9e4: 0x3e00008  jr          $ra
    ctx->pc = 0x13F9E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9E4u;
            // 0x13f9e8: 0xac850038  sw          $a1, 0x38($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F9ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
