#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7830
// Address: 0x1b7830 - 0x1b784c
void sub_001B7830_0x1b7830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7830_0x1b7830");
#endif

    ctx->pc = 0x1b7830u;

    // 0x1b7830: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7834: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7834u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7838: 0xac64006c  sw          $a0, 0x6C($v1)
    ctx->pc = 0x1b7838u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 108), GPR_U32(ctx, 4));
    // 0x1b783c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b783cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7840: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7840u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7844: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7844u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7844u;
            // 0x1b7848: 0xac650098  sw          $a1, 0x98($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 152), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B784Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
