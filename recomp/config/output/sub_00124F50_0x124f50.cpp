#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124F50
// Address: 0x124f50 - 0x124f58
void sub_00124F50_0x124f50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124F50_0x124f50");
#endif

    ctx->pc = 0x124f50u;

    // 0x124f50: 0x3e00008  jr          $ra
    ctx->pc = 0x124F50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F50u;
            // 0x124f54: 0x848200dc  lh          $v0, 0xDC($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 220)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124F58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
