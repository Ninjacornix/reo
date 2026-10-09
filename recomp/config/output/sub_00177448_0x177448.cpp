#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177448
// Address: 0x177448 - 0x177450
void sub_00177448_0x177448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177448_0x177448");
#endif

    ctx->pc = 0x177448u;

    // 0x177448: 0x3e00008  jr          $ra
    ctx->pc = 0x177448u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17744Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177448u;
            // 0x17744c: 0x8c820f28  lw          $v0, 0xF28($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 3880)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177450u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
