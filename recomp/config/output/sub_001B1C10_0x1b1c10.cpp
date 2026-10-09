#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1C10
// Address: 0x1b1c10 - 0x1b1c20
void sub_001B1C10_0x1b1c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1C10_0x1b1c10");
#endif

    ctx->pc = 0x1b1c10u;

    // 0x1b1c10: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1c10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1c14: 0x806c6d0  j           func_1B1B40
    ctx->pc = 0x1B1C14u;
    ctx->pc = 0x1B1C18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1C14u;
            // 0x1b1c18: 0x240601f4  addiu       $a2, $zero, 0x1F4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1B40u;
    if (runtime->hasFunction(0x1B1B40u)) {
        auto targetFn = runtime->lookupFunction(0x1B1B40u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B1B40_0x1b1b40(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B1C1Cu;
    // 0x1b1c1c: 0x0  nop
    ctx->pc = 0x1b1c1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
