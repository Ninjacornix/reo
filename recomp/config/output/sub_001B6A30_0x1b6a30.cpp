#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6A30
// Address: 0x1b6a30 - 0x1b6a40
void sub_001B6A30_0x1b6a30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6A30_0x1b6a30");
#endif

    ctx->pc = 0x1b6a30u;

    // 0x1b6a30: 0x8c82008c  lw          $v0, 0x8C($a0)
    ctx->pc = 0x1b6a30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x1b6a34: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6A34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6A34u;
            // 0x1b6a38: 0xa2102b  sltu        $v0, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B6A3Cu;
    // 0x1b6a3c: 0x0  nop
    ctx->pc = 0x1b6a3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
