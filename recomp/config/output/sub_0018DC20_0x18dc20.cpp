#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DC20
// Address: 0x18dc20 - 0x18dc30
void sub_0018DC20_0x18dc20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DC20_0x18dc20");
#endif

    ctx->pc = 0x18dc20u;

    // 0x18dc20: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x18dc20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dc24: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x18dc24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x18dc28: 0x806269c  j           func_189A70
    ctx->pc = 0x18DC28u;
    ctx->pc = 0x18DC2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DC28u;
            // 0x18dc2c: 0x2484fe50  addiu       $a0, $a0, -0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189A70u;
    if (runtime->hasFunction(0x189A70u)) {
        auto targetFn = runtime->lookupFunction(0x189A70u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00189A70_0x189a70(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x18DC30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
