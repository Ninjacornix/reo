#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001168C8
// Address: 0x1168c8 - 0x1168d4
void sub_001168C8_0x1168c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001168C8_0x1168c8");
#endif

    ctx->pc = 0x1168c8u;

    // 0x1168c8: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x1168c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1168cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1168CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1168CCu;
            // 0x1168d0: 0xaca20008  sw          $v0, 0x8($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1168D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
