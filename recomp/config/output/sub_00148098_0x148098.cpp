#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148098
// Address: 0x148098 - 0x1480b0
void sub_00148098_0x148098(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148098_0x148098");
#endif

    ctx->pc = 0x148098u;

    // 0x148098: 0x8c860040  lw          $a2, 0x40($a0)
    ctx->pc = 0x148098u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14809c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x14809cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1480a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1480a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1480a4: 0xacc30110  sw          $v1, 0x110($a2)
    ctx->pc = 0x1480a4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 272), GPR_U32(ctx, 3));
    // 0x1480a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1480A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1480ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1480A8u;
            // 0x1480ac: 0xfcc50108  sd          $a1, 0x108($a2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 6), 264), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1480B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
