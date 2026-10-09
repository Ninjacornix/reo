#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6720
// Address: 0x1c6720 - 0x1c673c
void sub_001C6720_0x1c6720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6720_0x1c6720");
#endif

    ctx->pc = 0x1c6720u;

    // 0x1c6720: 0xac8501b8  sw          $a1, 0x1B8($a0)
    ctx->pc = 0x1c6720u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 440), GPR_U32(ctx, 5));
    // 0x1c6724: 0xac8501bc  sw          $a1, 0x1BC($a0)
    ctx->pc = 0x1c6724u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 444), GPR_U32(ctx, 5));
    // 0x1c6728: 0xa48601c0  sh          $a2, 0x1C0($a0)
    ctx->pc = 0x1c6728u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 448), (uint16_t)GPR_U32(ctx, 6));
    // 0x1c672c: 0x948601c0  lhu         $a2, 0x1C0($a0)
    ctx->pc = 0x1c672cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 448)));
    // 0x1c6730: 0x8c8401b8  lw          $a0, 0x1B8($a0)
    ctx->pc = 0x1c6730u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 440)));
    // 0x1c6734: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1C6734u;
    ctx->pc = 0x1C6738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6734u;
            // 0x1c6738: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C673Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
