#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001251A0
// Address: 0x1251a0 - 0x1251a8
void sub_001251A0_0x1251a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001251A0_0x1251a0");
#endif

    ctx->pc = 0x1251a0u;

    // 0x1251a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1251A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1251A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1251A0u;
            // 0x1251a4: 0x8c820004  lw          $v0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1251A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
