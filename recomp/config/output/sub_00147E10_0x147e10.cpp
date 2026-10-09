#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147E10
// Address: 0x147e10 - 0x147e20
void sub_00147E10_0x147e10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147E10_0x147e10");
#endif

    ctx->pc = 0x147e10u;

    // 0x147e10: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x147e10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147e14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x147e14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x147e18: 0x3e00008  jr          $ra
    ctx->pc = 0x147E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147E18u;
            // 0x147e1c: 0xac6210a0  sw          $v0, 0x10A0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4256), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x147E20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
