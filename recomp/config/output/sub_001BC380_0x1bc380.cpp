#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC380
// Address: 0x1bc380 - 0x1bc3a0
void sub_001BC380_0x1bc380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC380_0x1bc380");
#endif

    ctx->pc = 0x1bc380u;

    // 0x1bc380: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bc380u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bc384: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bc384u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bc388: 0x248465c0  addiu       $a0, $a0, 0x65C0
    ctx->pc = 0x1bc388u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26048));
    // 0x1bc38c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1BC38Cu;
    ctx->pc = 0x1BC390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC38Cu;
            // 0x1bc390: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BC394u;
    // 0x1bc394: 0x0  nop
    ctx->pc = 0x1bc394u;
    // NOP
    // 0x1bc398: 0x0  nop
    ctx->pc = 0x1bc398u;
    // NOP
    // 0x1bc39c: 0x0  nop
    ctx->pc = 0x1bc39cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
