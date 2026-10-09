#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FB00
// Address: 0x12fb00 - 0x12fb08
void sub_0012FB00_0x12fb00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FB00_0x12fb00");
#endif

    ctx->pc = 0x12fb00u;

    // 0x12fb00: 0x3e00008  jr          $ra
    ctx->pc = 0x12FB00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FB04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB00u;
            // 0x12fb04: 0xac850048  sw          $a1, 0x48($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FB08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
