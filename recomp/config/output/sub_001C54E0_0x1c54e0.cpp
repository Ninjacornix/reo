#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C54E0
// Address: 0x1c54e0 - 0x1c5500
void sub_001C54E0_0x1c54e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C54E0_0x1c54e0");
#endif

    ctx->pc = 0x1c54e0u;

    // 0x1c54e0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1c54e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c54e4: 0x24064234  addiu       $a2, $zero, 0x4234
    ctx->pc = 0x1c54e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16948));
    // 0x1c54e8: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c54e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c54ec: 0x8041eac  j           func_107AB0
    ctx->pc = 0x1C54ECu;
    ctx->pc = 0x1C54F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C54ECu;
            // 0x1c54f0: 0x2484fb60  addiu       $a0, $a0, -0x4A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C54F4u;
    // 0x1c54f4: 0x0  nop
    ctx->pc = 0x1c54f4u;
    // NOP
    // 0x1c54f8: 0x0  nop
    ctx->pc = 0x1c54f8u;
    // NOP
    // 0x1c54fc: 0x0  nop
    ctx->pc = 0x1c54fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
