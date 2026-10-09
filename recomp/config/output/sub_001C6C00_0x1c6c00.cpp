#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6C00
// Address: 0x1c6c00 - 0x1c6c10
void sub_001C6C00_0x1c6c00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6C00_0x1c6c00");
#endif

    ctx->pc = 0x1c6c00u;

    // 0x1c6c00: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6c00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6c04: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1c6c04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c6c08: 0x8071ea0  j           func_1C7A80
    ctx->pc = 0x1C6C08u;
    ctx->pc = 0x1C6C0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6C08u;
            // 0x1c6c0c: 0xa02051a1  sb          $zero, 0x51A1($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 20897), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7A80u;
    if (runtime->hasFunction(0x1C7A80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7A80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C7A80_0x1c7a80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6C10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
