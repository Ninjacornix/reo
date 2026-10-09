#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB2F0
// Address: 0x1ab2f0 - 0x1ab310
void sub_001AB2F0_0x1ab2f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB2F0_0x1ab2f0");
#endif

    ctx->pc = 0x1ab2f0u;

    // 0x1ab2f0: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1ab2f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab2f4: 0x240501a6  addiu       $a1, $zero, 0x1A6
    ctx->pc = 0x1ab2f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 422));
    // 0x1ab2f8: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1ab2f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1ab2fc: 0x806ac14  j           func_1AB050
    ctx->pc = 0x1AB2FCu;
    ctx->pc = 0x1AB300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB2FCu;
            // 0x1ab300: 0x248437c0  addiu       $a0, $a0, 0x37C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB050u;
    if (runtime->hasFunction(0x1AB050u)) {
        auto targetFn = runtime->lookupFunction(0x1AB050u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AB050_0x1ab050(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AB304u;
    // 0x1ab304: 0x0  nop
    ctx->pc = 0x1ab304u;
    // NOP
    // 0x1ab308: 0x0  nop
    ctx->pc = 0x1ab308u;
    // NOP
    // 0x1ab30c: 0x0  nop
    ctx->pc = 0x1ab30cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
