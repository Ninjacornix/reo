#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139FE0
// Address: 0x139fe0 - 0x139fe8
void sub_00139FE0_0x139fe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139FE0_0x139fe0");
#endif

    ctx->pc = 0x139fe0u;

    // 0x139fe0: 0x3e00008  jr          $ra
    ctx->pc = 0x139FE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139FE0u;
            // 0x139fe4: 0x24020800  addiu       $v0, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x139FE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
