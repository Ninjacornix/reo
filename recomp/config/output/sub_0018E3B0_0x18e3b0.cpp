#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E3B0
// Address: 0x18e3b0 - 0x18e3c0
void sub_0018E3B0_0x18e3b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E3B0_0x18e3b0");
#endif

    ctx->pc = 0x18e3b0u;

    // 0x18e3b0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18e3b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18e3b4: 0x3e00008  jr          $ra
    ctx->pc = 0x18E3B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18E3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E3B4u;
            // 0x18e3b8: 0xac244160  sw          $a0, 0x4160($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 16736), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18E3BCu;
    // 0x18e3bc: 0x0  nop
    ctx->pc = 0x18e3bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
