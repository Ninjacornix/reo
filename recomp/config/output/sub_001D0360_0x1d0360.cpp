#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D0360
// Address: 0x1d0360 - 0x1d0380
void sub_001D0360_0x1d0360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D0360_0x1d0360");
#endif

    ctx->pc = 0x1d0360u;

    // 0x1d0360: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d0360u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0364: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0364u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0368: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d0368u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d036c: 0xac254484  sw          $a1, 0x4484($at)
    ctx->pc = 0x1d036cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17540), GPR_U32(ctx, 5));
    // 0x1d0370: 0x248461f0  addiu       $a0, $a0, 0x61F0
    ctx->pc = 0x1d0370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 25072));
    // 0x1d0374: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d0374u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0378: 0x807323c  j           func_1CC8F0
    ctx->pc = 0x1D0378u;
    ctx->pc = 0x1D037Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0378u;
            // 0x1d037c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D0380u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
