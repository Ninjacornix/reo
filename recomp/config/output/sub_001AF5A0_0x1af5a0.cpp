#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF5A0
// Address: 0x1af5a0 - 0x1af5ac
void sub_001AF5A0_0x1af5a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF5A0_0x1af5a0");
#endif

    ctx->pc = 0x1af5a0u;

    // 0x1af5a0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af5a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af5a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF5A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF5A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF5A4u;
            // 0x1af5a8: 0xa02043cd  sb          $zero, 0x43CD($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17357), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1AF5ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
