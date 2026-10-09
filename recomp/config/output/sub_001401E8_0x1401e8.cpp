#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001401E8
// Address: 0x1401e8 - 0x1401f4
void sub_001401E8_0x1401e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001401E8_0x1401e8");
#endif

    ctx->pc = 0x1401e8u;

    // 0x1401e8: 0xac86002c  sw          $a2, 0x2C($a0)
    ctx->pc = 0x1401e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 6));
    // 0x1401ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1401ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1401F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1401ECu;
            // 0x1401f0: 0xac850028  sw          $a1, 0x28($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1401F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
