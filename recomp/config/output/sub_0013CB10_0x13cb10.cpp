#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CB10
// Address: 0x13cb10 - 0x13cb1c
void sub_0013CB10_0x13cb10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CB10_0x13cb10");
#endif

    ctx->pc = 0x13cb10u;

    // 0x13cb10: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13cb10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13cb14: 0x3e00008  jr          $ra
    ctx->pc = 0x13CB14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CB18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB14u;
            // 0x13cb18: 0x2442dfb0  addiu       $v0, $v0, -0x2050 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294959024));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13CB1Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
