#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1900
// Address: 0x1a1900 - 0x1a1910
void sub_001A1900_0x1a1900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1900_0x1a1900");
#endif

    ctx->pc = 0x1a1900u;

    // 0x1a1900: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a1900u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a1904: 0x24050078  addiu       $a1, $zero, 0x78
    ctx->pc = 0x1a1904u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
    // 0x1a1908: 0x8068608  j           func_1A1820
    ctx->pc = 0x1A1908u;
    ctx->pc = 0x1A190Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1908u;
            // 0x1a190c: 0x2484ff30  addiu       $a0, $a0, -0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1820u;
    if (runtime->hasFunction(0x1A1820u)) {
        auto targetFn = runtime->lookupFunction(0x1A1820u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A1820_0x1a1820(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A1910u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
