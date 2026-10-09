#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD120
// Address: 0x1cd120 - 0x1cd148
void sub_001CD120_0x1cd120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD120_0x1cd120");
#endif

    ctx->pc = 0x1cd120u;

    // 0x1cd120: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1cd120u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1cd124: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd124u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd128: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x1cd128u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1cd12c: 0x24636640  addiu       $v1, $v1, 0x6640
    ctx->pc = 0x1cd12cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 26176));
    // 0x1cd130: 0x24426644  addiu       $v0, $v0, 0x6644
    ctx->pc = 0x1cd130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26180));
    // 0x1cd134: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1cd134u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1cd138: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1cd138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1cd13c: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1cd13cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd140: 0x8073420  j           func_1CD080
    ctx->pc = 0x1CD140u;
    ctx->pc = 0x1CD144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD140u;
            // 0x1cd144: 0x8c640000  lw          $a0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CD080_0x1cd080(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1CD148u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
