#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CB40
// Address: 0x13cb40 - 0x13cb4c
void sub_0013CB40_0x13cb40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CB40_0x13cb40");
#endif

    ctx->pc = 0x13cb40u;

    // 0x13cb40: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13cb40u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13cb44: 0x3e00008  jr          $ra
    ctx->pc = 0x13CB44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CB48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB44u;
            // 0x13cb48: 0x8c62dea4  lw          $v0, -0x215C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294958756)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13CB4Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
