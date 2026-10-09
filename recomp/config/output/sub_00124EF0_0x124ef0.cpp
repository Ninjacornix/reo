#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124EF0
// Address: 0x124ef0 - 0x124ef8
void sub_00124EF0_0x124ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124EF0_0x124ef0");
#endif

    ctx->pc = 0x124ef0u;

    // 0x124ef0: 0x3e00008  jr          $ra
    ctx->pc = 0x124EF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124EF0u;
            // 0x124ef4: 0x8082000f  lb          $v0, 0xF($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124EF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
