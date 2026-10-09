#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147E20
// Address: 0x147e20 - 0x147e34
void sub_00147E20_0x147e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147E20_0x147e20");
#endif

    ctx->pc = 0x147e20u;

    // 0x147e20: 0x8c820040  lw          $v0, 0x40($a0)
    ctx->pc = 0x147e20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147e24: 0xac4700b4  sw          $a3, 0xB4($v0)
    ctx->pc = 0x147e24u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 180), GPR_U32(ctx, 7));
    // 0x147e28: 0xac4500ac  sw          $a1, 0xAC($v0)
    ctx->pc = 0x147e28u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 172), GPR_U32(ctx, 5));
    // 0x147e2c: 0x3e00008  jr          $ra
    ctx->pc = 0x147E2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147E2Cu;
            // 0x147e30: 0xac4600b0  sw          $a2, 0xB0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 176), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x147E34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
