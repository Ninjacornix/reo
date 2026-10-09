#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130DF8
// Address: 0x130df8 - 0x130e10
void sub_00130DF8_0x130df8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130DF8_0x130df8");
#endif

    ctx->pc = 0x130df8u;

    // 0x130df8: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x130df8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x130dfc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130e00: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x130e00u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x130e04: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x130e04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x130e08: 0x3e00008  jr          $ra
    ctx->pc = 0x130E08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E08u;
            // 0x130e0c: 0xacc50000  sw          $a1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130E10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
