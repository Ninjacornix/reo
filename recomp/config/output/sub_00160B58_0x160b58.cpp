#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160B58
// Address: 0x160b58 - 0x160b60
void sub_00160B58_0x160b58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160B58_0x160b58");
#endif

    ctx->pc = 0x160b58u;

    // 0x160b58: 0x3e00008  jr          $ra
    ctx->pc = 0x160B58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160B58u;
            // 0x160b5c: 0x2402181f  addiu       $v0, $zero, 0x181F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6175));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x160B60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
