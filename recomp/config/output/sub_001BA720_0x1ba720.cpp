#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA720
// Address: 0x1ba720 - 0x1ba740
void sub_001BA720_0x1ba720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA720_0x1ba720");
#endif

    ctx->pc = 0x1ba720u;

    // 0x1ba720: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1ba720u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1ba724: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ba724u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba728: 0x24846570  addiu       $a0, $a0, 0x6570
    ctx->pc = 0x1ba728u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 25968));
    // 0x1ba72c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1BA72Cu;
    ctx->pc = 0x1BA730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA72Cu;
            // 0x1ba730: 0x2406001c  addiu       $a2, $zero, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BA734u;
    // 0x1ba734: 0x0  nop
    ctx->pc = 0x1ba734u;
    // NOP
    // 0x1ba738: 0x0  nop
    ctx->pc = 0x1ba738u;
    // NOP
    // 0x1ba73c: 0x0  nop
    ctx->pc = 0x1ba73cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
