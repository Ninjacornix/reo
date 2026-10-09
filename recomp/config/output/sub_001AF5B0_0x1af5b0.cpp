#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF5B0
// Address: 0x1af5b0 - 0x1af5c0
void sub_001AF5B0_0x1af5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF5B0_0x1af5b0");
#endif

    ctx->pc = 0x1af5b0u;

    // 0x1af5b0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1af5b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1af5b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af5b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af5b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF5B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF5BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF5B8u;
            // 0x1af5bc: 0xa02343cd  sb          $v1, 0x43CD($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17357), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1AF5C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
