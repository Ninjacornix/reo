#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001028E0
// Address: 0x1028e0 - 0x1028f0
void sub_001028E0_0x1028e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001028E0_0x1028e0");
#endif

    ctx->pc = 0x1028e0u;

    // 0x1028e0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1028e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1028e4: 0x34633820  ori         $v1, $v1, 0x3820
    ctx->pc = 0x1028e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14368);
    // 0x1028e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1028E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1028ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1028E8u;
            // 0x1028ec: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1028F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
