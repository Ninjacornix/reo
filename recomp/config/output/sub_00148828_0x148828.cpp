#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148828
// Address: 0x148828 - 0x148838
void sub_00148828_0x148828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148828_0x148828");
#endif

    ctx->pc = 0x148828u;

    // 0x148828: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x148828u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14882c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x14882cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x148830: 0x8045a12  j           func_116848
    ctx->pc = 0x148830u;
    ctx->pc = 0x148834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148830u;
            // 0x148834: 0x2484e138  addiu       $a0, $a0, -0x1EC8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959416));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x148838u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
