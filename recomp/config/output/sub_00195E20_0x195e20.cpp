#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00195E20
// Address: 0x195e20 - 0x195e30
void sub_00195E20_0x195e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00195E20_0x195e20");
#endif

    ctx->pc = 0x195e20u;

    // 0x195e20: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x195e20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x195e24: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195e24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195e28: 0x3e00008  jr          $ra
    ctx->pc = 0x195E28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x195E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195E28u;
            // 0x195e2c: 0xac22fdb0  sw          $v0, -0x250($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966704), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x195E30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
