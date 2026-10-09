#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C930
// Address: 0x12c930 - 0x12c948
void sub_0012C930_0x12c930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C930_0x12c930");
#endif

    ctx->pc = 0x12c930u;

    // 0x12c930: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12c930u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12c934: 0x24637d80  addiu       $v1, $v1, 0x7D80
    ctx->pc = 0x12c934u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32128));
    // 0x12c938: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12c938u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12c93c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x12c93cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12c940: 0x3e00008  jr          $ra
    ctx->pc = 0x12C940u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C940u;
            // 0x12c944: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12C948u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
