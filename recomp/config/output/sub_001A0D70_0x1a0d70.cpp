#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0D70
// Address: 0x1a0d70 - 0x1a0d80
void sub_001A0D70_0x1a0d70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0D70_0x1a0d70");
#endif

    ctx->pc = 0x1a0d70u;

    // 0x1a0d70: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1a0d70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0d74: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a0d74u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a0d78: 0x80684cc  j           func_1A1330
    ctx->pc = 0x1A0D78u;
    ctx->pc = 0x1A0D7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0D78u;
            // 0x1a0d7c: 0x2484fef0  addiu       $a0, $a0, -0x110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1330u;
    if (runtime->hasFunction(0x1A1330u)) {
        auto targetFn = runtime->lookupFunction(0x1A1330u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A1330_0x1a1330(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A0D80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
