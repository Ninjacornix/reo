#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DBE0
// Address: 0x18dbe0 - 0x18dbf4
void sub_0018DBE0_0x18dbe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DBE0_0x18dbe0");
#endif

    ctx->pc = 0x18dbe0u;

    // 0x18dbe0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x18dbe0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dbe4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18dbe4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dbe8: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x18dbe8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x18dbec: 0x806267c  j           func_1899F0
    ctx->pc = 0x18DBECu;
    ctx->pc = 0x18DBF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DBECu;
            // 0x18dbf0: 0x2484fe50  addiu       $a0, $a0, -0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1899F0u;
    if (runtime->hasFunction(0x1899F0u)) {
        auto targetFn = runtime->lookupFunction(0x1899F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001899F0_0x1899f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x18DBF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
