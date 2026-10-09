#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7C90
// Address: 0x1c7c90 - 0x1c7ca0
void sub_001C7C90_0x1c7c90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7C90_0x1c7c90");
#endif

    ctx->pc = 0x1c7c90u;

    // 0x1c7c90: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x1c7c90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1c7c94: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1c7c94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c7c98: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7C98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7C98u;
            // 0x1c7c9c: 0x621023  subu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C7CA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
