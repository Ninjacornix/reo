#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D7B0
// Address: 0x15d7b0 - 0x15d7c0
void sub_0015D7B0_0x15d7b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D7B0_0x15d7b0");
#endif

    ctx->pc = 0x15d7b0u;

    // 0x15d7b0: 0x8c820168  lw          $v0, 0x168($a0)
    ctx->pc = 0x15d7b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 360)));
    // 0x15d7b4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x15d7b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x15d7b8: 0x3e00008  jr          $ra
    ctx->pc = 0x15D7B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D7B8u;
            // 0x15d7bc: 0xac820168  sw          $v0, 0x168($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 360), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15D7C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
