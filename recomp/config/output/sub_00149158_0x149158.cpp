#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00149158
// Address: 0x149158 - 0x149164
void sub_00149158_0x149158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00149158_0x149158");
#endif

    ctx->pc = 0x149158u;

    // 0x149158: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x149158u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x14915c: 0x805221c  j           func_148870
    ctx->pc = 0x14915Cu;
    ctx->pc = 0x149160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14915Cu;
            // 0x149160: 0x24a5e1f0  addiu       $a1, $a1, -0x1E10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959600));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00148870_0x148870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x149164u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
