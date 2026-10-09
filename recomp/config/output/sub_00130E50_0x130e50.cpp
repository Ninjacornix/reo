#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130E50
// Address: 0x130e50 - 0x130e58
void sub_00130E50_0x130e50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130E50_0x130e50");
#endif

    ctx->pc = 0x130e50u;

    // 0x130e50: 0x3e00008  jr          $ra
    ctx->pc = 0x130E50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E50u;
            // 0x130e54: 0x80820040  lb          $v0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130E58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
