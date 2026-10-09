#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A078
// Address: 0x13a078 - 0x13a084
void sub_0013A078_0x13a078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A078_0x13a078");
#endif

    ctx->pc = 0x13a078u;

    // 0x13a078: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13a078u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13a07c: 0x3e00008  jr          $ra
    ctx->pc = 0x13A07Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A07Cu;
            // 0x13a080: 0x8c62cbec  lw          $v0, -0x3414($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294953964)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13A084u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
