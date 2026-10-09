#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8810
// Address: 0x1c8810 - 0x1c8820
void sub_001C8810_0x1c8810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8810_0x1c8810");
#endif

    ctx->pc = 0x1c8810u;

    // 0x1c8810: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8810u;
            // 0x1c8814: 0x8c820040  lw          $v0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C8818u;
    // 0x1c8818: 0x0  nop
    ctx->pc = 0x1c8818u;
    // NOP
    // 0x1c881c: 0x0  nop
    ctx->pc = 0x1c881cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
