#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CBB8
// Address: 0x12cbb8 - 0x12cbc0
void sub_0012CBB8_0x12cbb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CBB8_0x12cbb8");
#endif

    ctx->pc = 0x12cbb8u;

    // 0x12cbb8: 0x3e00008  jr          $ra
    ctx->pc = 0x12CBB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12CBBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CBB8u;
            // 0x12cbbc: 0x80820001  lb          $v0, 0x1($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12CBC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
