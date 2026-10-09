#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BE30
// Address: 0x15be30 - 0x15be38
void sub_0015BE30_0x15be30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BE30_0x15be30");
#endif

    ctx->pc = 0x15be30u;

    // 0x15be30: 0x3e00008  jr          $ra
    ctx->pc = 0x15BE30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BE34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BE30u;
            // 0x15be34: 0x24020100  addiu       $v0, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15BE38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
