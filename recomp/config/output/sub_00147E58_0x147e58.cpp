#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147E58
// Address: 0x147e58 - 0x147e64
void sub_00147E58_0x147e58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147E58_0x147e58");
#endif

    ctx->pc = 0x147e58u;

    // 0x147e58: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x147e58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147e5c: 0x3e00008  jr          $ra
    ctx->pc = 0x147E5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147E5Cu;
            // 0x147e60: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x147E64u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
