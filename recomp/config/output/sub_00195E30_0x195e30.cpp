#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00195E30
// Address: 0x195e30 - 0x195e50
void sub_00195E30_0x195e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00195E30_0x195e30");
#endif

    ctx->pc = 0x195e30u;

    // 0x195e30: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x195e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x195e34: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195e34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195e38: 0xac22fdb0  sw          $v0, -0x250($at)
    ctx->pc = 0x195e38u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966704), GPR_U32(ctx, 2));
    // 0x195e3c: 0x3e00008  jr          $ra
    ctx->pc = 0x195E3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x195E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195E3Cu;
            // 0x195e40: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x195E44u;
    // 0x195e44: 0x0  nop
    ctx->pc = 0x195e44u;
    // NOP
    // 0x195e48: 0x0  nop
    ctx->pc = 0x195e48u;
    // NOP
    // 0x195e4c: 0x0  nop
    ctx->pc = 0x195e4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
