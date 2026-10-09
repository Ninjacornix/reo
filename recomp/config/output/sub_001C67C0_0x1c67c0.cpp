#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C67C0
// Address: 0x1c67c0 - 0x1c67d0
void sub_001C67C0_0x1c67c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C67C0_0x1c67c0");
#endif

    ctx->pc = 0x1c67c0u;

    // 0x1c67c0: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c67c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c67c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C67C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C67C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C67C4u;
            // 0x1c67c8: 0xa02051a0  sb          $zero, 0x51A0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 20896), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C67CCu;
    // 0x1c67cc: 0x0  nop
    ctx->pc = 0x1c67ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
