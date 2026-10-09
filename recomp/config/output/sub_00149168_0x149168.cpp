#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00149168
// Address: 0x149168 - 0x149174
void sub_00149168_0x149168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00149168_0x149168");
#endif

    ctx->pc = 0x149168u;

    // 0x149168: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x149168u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x14916c: 0x805221c  j           func_148870
    ctx->pc = 0x14916Cu;
    ctx->pc = 0x149170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14916Cu;
            // 0x149170: 0x24a5e228  addiu       $a1, $a1, -0x1DD8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959656));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00148870_0x148870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x149174u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
