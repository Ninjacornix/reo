#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C8B0
// Address: 0x18c8b0 - 0x18c8c0
void sub_0018C8B0_0x18c8b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C8B0_0x18c8b0");
#endif

    ctx->pc = 0x18c8b0u;

    // 0x18c8b0: 0x3e00008  jr          $ra
    ctx->pc = 0x18C8B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C8B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C8B0u;
            // 0x18c8b4: 0x24020040  addiu       $v0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18C8B8u;
    // 0x18c8b8: 0x0  nop
    ctx->pc = 0x18c8b8u;
    // NOP
    // 0x18c8bc: 0x0  nop
    ctx->pc = 0x18c8bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
