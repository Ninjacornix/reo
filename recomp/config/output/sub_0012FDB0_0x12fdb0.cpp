#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FDB0
// Address: 0x12fdb0 - 0x12fdb8
void sub_0012FDB0_0x12fdb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FDB0_0x12fdb0");
#endif

    ctx->pc = 0x12fdb0u;

    // 0x12fdb0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDB0u;
            // 0x12fdb4: 0x8c820030  lw          $v0, 0x30($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FDB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
