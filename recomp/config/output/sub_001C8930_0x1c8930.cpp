#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8930
// Address: 0x1c8930 - 0x1c8940
void sub_001C8930_0x1c8930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8930_0x1c8930");
#endif

    ctx->pc = 0x1c8930u;

    // 0x1c8930: 0xac850008  sw          $a1, 0x8($a0)
    ctx->pc = 0x1c8930u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 5));
    // 0x1c8934: 0x8072250  j           func_1C8940
    ctx->pc = 0x1C8934u;
    ctx->pc = 0x1C8938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8934u;
            // 0x1c8938: 0xac860010  sw          $a2, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8940u;
    if (runtime->hasFunction(0x1C8940u)) {
        auto targetFn = runtime->lookupFunction(0x1C8940u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8940_0x1c8940(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C893Cu;
    // 0x1c893c: 0x0  nop
    ctx->pc = 0x1c893cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
