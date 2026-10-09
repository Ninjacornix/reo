#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148058
// Address: 0x148058 - 0x148064
void sub_00148058_0x148058(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148058_0x148058");
#endif

    ctx->pc = 0x148058u;

    // 0x148058: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148058u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14805c: 0x3e00008  jr          $ra
    ctx->pc = 0x14805Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14805Cu;
            // 0x148060: 0x8c6200e8  lw          $v0, 0xE8($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 232)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148064u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
