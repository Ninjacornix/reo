#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AA480
// Address: 0x1aa480 - 0x1aa4a0
void sub_001AA480_0x1aa480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AA480_0x1aa480");
#endif

    ctx->pc = 0x1aa480u;

    // 0x1aa480: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1aa480u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa484: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa484u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa488: 0x8c241698  lw          $a0, 0x1698($at)
    ctx->pc = 0x1aa488u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1aa48c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1aa48cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa490: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1aa490u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa494: 0x806a7c8  j           func_1A9F20
    ctx->pc = 0x1AA494u;
    ctx->pc = 0x1AA498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA494u;
            // 0x1aa498: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9F20u;
    if (runtime->hasFunction(0x1A9F20u)) {
        auto targetFn = runtime->lookupFunction(0x1A9F20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A9F20_0x1a9f20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AA49Cu;
    // 0x1aa49c: 0x0  nop
    ctx->pc = 0x1aa49cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
