#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7CA0
// Address: 0x1c7ca0 - 0x1c7cb0
void sub_001C7CA0_0x1c7ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7CA0_0x1c7ca0");
#endif

    ctx->pc = 0x1c7ca0u;

    // 0x1c7ca0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7CA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7CA0u;
            // 0x1c7ca4: 0x8c82000c  lw          $v0, 0xC($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C7CA8u;
    // 0x1c7ca8: 0x0  nop
    ctx->pc = 0x1c7ca8u;
    // NOP
    // 0x1c7cac: 0x0  nop
    ctx->pc = 0x1c7cacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
