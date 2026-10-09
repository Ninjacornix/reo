#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114D18
// Address: 0x114d18 - 0x114d20
void sub_00114D18_0x114d18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114D18_0x114d18");
#endif

    ctx->pc = 0x114d18u;

    // 0x114d18: 0x3e00008  jr          $ra
    ctx->pc = 0x114D18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114D18u;
            // 0x114d1c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114D20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
