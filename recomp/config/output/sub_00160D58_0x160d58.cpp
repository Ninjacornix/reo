#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160D58
// Address: 0x160d58 - 0x160d68
void sub_00160D58_0x160d58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160D58_0x160d58");
#endif

    ctx->pc = 0x160d58u;

    // 0x160d58: 0xac870008  sw          $a3, 0x8($a0)
    ctx->pc = 0x160d58u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 7));
    // 0x160d5c: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x160d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x160d60: 0x3e00008  jr          $ra
    ctx->pc = 0x160D60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160D60u;
            // 0x160d64: 0xac860004  sw          $a2, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x160D68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
