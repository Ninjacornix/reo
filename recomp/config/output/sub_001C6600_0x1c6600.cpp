#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6600
// Address: 0x1c6600 - 0x1c6610
void sub_001C6600_0x1c6600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6600_0x1c6600");
#endif

    ctx->pc = 0x1c6600u;

    // 0x1c6600: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1c6600u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6604: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1c6604u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6608: 0x8071688  j           func_1C5A20
    ctx->pc = 0x1C6608u;
    ctx->pc = 0x1C660Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6608u;
            // 0x1c660c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5A20u;
    if (runtime->hasFunction(0x1C5A20u)) {
        auto targetFn = runtime->lookupFunction(0x1C5A20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C5A20_0x1c5a20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6610u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
