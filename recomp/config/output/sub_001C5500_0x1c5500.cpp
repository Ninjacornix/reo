#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5500
// Address: 0x1c5500 - 0x1c5520
void sub_001C5500_0x1c5500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5500_0x1c5500");
#endif

    ctx->pc = 0x1c5500u;

    // 0x1c5500: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1c5500u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1c5504: 0x24067000  addiu       $a2, $zero, 0x7000
    ctx->pc = 0x1c5504u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 28672));
    // 0x1c5508: 0x812821  addu        $a1, $a0, $at
    ctx->pc = 0x1c5508u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 1)));
    // 0x1c550c: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c550cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c5510: 0x8041eac  j           func_107AB0
    ctx->pc = 0x1C5510u;
    ctx->pc = 0x1C5514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5510u;
            // 0x1c5514: 0x24848b60  addiu       $a0, $a0, -0x74A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937440));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C5518u;
    // 0x1c5518: 0x0  nop
    ctx->pc = 0x1c5518u;
    // NOP
    // 0x1c551c: 0x0  nop
    ctx->pc = 0x1c551cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
