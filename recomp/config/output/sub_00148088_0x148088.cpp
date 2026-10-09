#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148088
// Address: 0x148088 - 0x148098
void sub_00148088_0x148088(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148088_0x148088");
#endif

    ctx->pc = 0x148088u;

    // 0x148088: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14808c: 0x8c620100  lw          $v0, 0x100($v1)
    ctx->pc = 0x14808cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 256)));
    // 0x148090: 0x3e00008  jr          $ra
    ctx->pc = 0x148090u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148090u;
            // 0x148094: 0xac650100  sw          $a1, 0x100($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 256), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148098u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
