#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0A80
// Address: 0x1b0a80 - 0x1b0aa0
void sub_001B0A80_0x1b0a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0A80_0x1b0a80");
#endif

    ctx->pc = 0x1b0a80u;

    // 0x1b0a80: 0x3c04002c  lui         $a0, 0x2C
    ctx->pc = 0x1b0a80u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)44 << 16));
    // 0x1b0a84: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1b0a84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b0a88: 0x24848e90  addiu       $a0, $a0, -0x7170
    ctx->pc = 0x1b0a88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294938256));
    // 0x1b0a8c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1B0A8Cu;
    ctx->pc = 0x1B0A90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0A8Cu;
            // 0x1b0a90: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B0A94u;
    // 0x1b0a94: 0x0  nop
    ctx->pc = 0x1b0a94u;
    // NOP
    // 0x1b0a98: 0x0  nop
    ctx->pc = 0x1b0a98u;
    // NOP
    // 0x1b0a9c: 0x0  nop
    ctx->pc = 0x1b0a9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
