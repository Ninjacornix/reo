#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3CF0
// Address: 0x1d3cf0 - 0x1d3d00
void sub_001D3CF0_0x1d3cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3CF0_0x1d3cf0");
#endif

    ctx->pc = 0x1d3cf0u;

    // 0x1d3cf0: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d3cf0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d3cf4: 0x2405000d  addiu       $a1, $zero, 0xD
    ctx->pc = 0x1d3cf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d3cf8: 0x8074f70  j           func_1D3DC0
    ctx->pc = 0x1D3CF8u;
    ctx->pc = 0x1D3CFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3CF8u;
            // 0x1d3cfc: 0x24846698  addiu       $a0, $a0, 0x6698 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D3D00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
