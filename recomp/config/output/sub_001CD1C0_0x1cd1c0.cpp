#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD1C0
// Address: 0x1cd1c0 - 0x1cd1d0
void sub_001CD1C0_0x1cd1c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD1C0_0x1cd1c0");
#endif

    ctx->pc = 0x1cd1c0u;

    // 0x1cd1c0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cd1c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cd1c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD1C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD1C4u;
            // 0x1cd1c8: 0xac2466c8  sw          $a0, 0x66C8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26312), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1CD1CCu;
    // 0x1cd1cc: 0x0  nop
    ctx->pc = 0x1cd1ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
