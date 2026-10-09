#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB8D0
// Address: 0x1bb8d0 - 0x1bb8e4
void sub_001BB8D0_0x1bb8d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB8D0_0x1bb8d0");
#endif

    ctx->pc = 0x1bb8d0u;

    // 0x1bb8d0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb8d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb8d4: 0x8c226654  lw          $v0, 0x6654($at)
    ctx->pc = 0x1bb8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26196)));
    // 0x1bb8d8: 0x38420063  xori        $v0, $v0, 0x63
    ctx->pc = 0x1bb8d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)99);
    // 0x1bb8dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB8DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB8E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB8DCu;
            // 0x1bb8e0: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BB8E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
