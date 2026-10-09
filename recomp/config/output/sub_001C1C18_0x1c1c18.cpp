#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1C18
// Address: 0x1c1c18 - 0x1c1c20
void sub_001C1C18_0x1c1c18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1C18_0x1c1c18");
#endif

    ctx->pc = 0x1c1c18u;

    // 0x1c1c18: 0x80706e2  j           func_1C1B88
    ctx->pc = 0x1C1C18u;
    ctx->pc = 0x1C1C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1C18u;
            // 0x1c1c1c: 0x2405fde4  addiu       $a1, $zero, -0x21C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966756));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1B88u;
    if (runtime->hasFunction(0x1C1B88u)) {
        auto targetFn = runtime->lookupFunction(0x1C1B88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C1B88_0x1c1b88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C1C20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
