#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7CC0
// Address: 0x1c7cc0 - 0x1c7cd0
void sub_001C7CC0_0x1c7cc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7CC0_0x1c7cc0");
#endif

    ctx->pc = 0x1c7cc0u;

    // 0x1c7cc0: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1c7cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1c7cc4: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1c7cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c7cc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7CC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7CC8u;
            // 0x1c7ccc: 0x621021  addu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C7CD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
