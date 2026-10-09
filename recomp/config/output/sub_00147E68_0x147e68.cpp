#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147E68
// Address: 0x147e68 - 0x147e78
void sub_00147E68_0x147e68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147E68_0x147e68");
#endif

    ctx->pc = 0x147e68u;

    // 0x147e68: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x147e68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147e6c: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x147e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x147e70: 0x3e00008  jr          $ra
    ctx->pc = 0x147E70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147E70u;
            // 0x147e74: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x147E78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
