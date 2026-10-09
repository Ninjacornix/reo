#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001618B0
// Address: 0x1618b0 - 0x1618c0
void sub_001618B0_0x1618b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001618B0_0x1618b0");
#endif

    ctx->pc = 0x1618b0u;

    // 0x1618b0: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x1618b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1618b4: 0x38420002  xori        $v0, $v0, 0x2
    ctx->pc = 0x1618b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)2);
    // 0x1618b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1618B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1618BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1618B8u;
            // 0x1618bc: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1618C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
