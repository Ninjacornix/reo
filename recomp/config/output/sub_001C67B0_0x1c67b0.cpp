#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C67B0
// Address: 0x1c67b0 - 0x1c67c0
void sub_001C67B0_0x1c67b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C67B0_0x1c67b0");
#endif

    ctx->pc = 0x1c67b0u;

    // 0x1c67b0: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c67b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c67b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C67B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C67B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C67B4u;
            // 0x1c67b8: 0x902251a1  lbu         $v0, 0x51A1($at) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20897)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C67BCu;
    // 0x1c67bc: 0x0  nop
    ctx->pc = 0x1c67bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
