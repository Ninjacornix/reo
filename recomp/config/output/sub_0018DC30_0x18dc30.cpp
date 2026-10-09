#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DC30
// Address: 0x18dc30 - 0x18dc50
void sub_0018DC30_0x18dc30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DC30_0x18dc30");
#endif

    ctx->pc = 0x18dc30u;

    // 0x18dc30: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x18dc30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dc34: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x18dc34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18dc38: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x18dc38u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x18dc3c: 0x806267c  j           func_1899F0
    ctx->pc = 0x18DC3Cu;
    ctx->pc = 0x18DC40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DC3Cu;
            // 0x18dc40: 0x2484fe50  addiu       $a0, $a0, -0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1899F0u;
    if (runtime->hasFunction(0x1899F0u)) {
        auto targetFn = runtime->lookupFunction(0x1899F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001899F0_0x1899f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x18DC44u;
    // 0x18dc44: 0x0  nop
    ctx->pc = 0x18dc44u;
    // NOP
    // 0x18dc48: 0x0  nop
    ctx->pc = 0x18dc48u;
    // NOP
    // 0x18dc4c: 0x0  nop
    ctx->pc = 0x18dc4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
