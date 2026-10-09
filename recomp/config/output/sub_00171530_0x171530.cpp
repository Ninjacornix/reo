#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171530
// Address: 0x171530 - 0x171540
void sub_00171530_0x171530(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171530_0x171530");
#endif

    ctx->pc = 0x171530u;

    // 0x171530: 0x8c831b30  lw          $v1, 0x1B30($a0)
    ctx->pc = 0x171530u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x171534: 0x8c6209d8  lw          $v0, 0x9D8($v1)
    ctx->pc = 0x171534u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 2520)));
    // 0x171538: 0x3e00008  jr          $ra
    ctx->pc = 0x171538u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17153Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171538u;
            // 0x17153c: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x171540u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
