#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C918
// Address: 0x12c918 - 0x12c930
void sub_0012C918_0x12c918(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C918_0x12c918");
#endif

    ctx->pc = 0x12c918u;

    // 0x12c918: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12c918u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12c91c: 0x24637d80  addiu       $v1, $v1, 0x7D80
    ctx->pc = 0x12c91cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32128));
    // 0x12c920: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12c920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12c924: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12c924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12c928: 0x3e00008  jr          $ra
    ctx->pc = 0x12C928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C928u;
            // 0x12c92c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12C930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
