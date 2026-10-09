#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114D10
// Address: 0x114d10 - 0x114d18
void sub_00114D10_0x114d10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114D10_0x114d10");
#endif

    ctx->pc = 0x114d10u;

    // 0x114d10: 0x3e00008  jr          $ra
    ctx->pc = 0x114D10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114D10u;
            // 0x114d14: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114D18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
