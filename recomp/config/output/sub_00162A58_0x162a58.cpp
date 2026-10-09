#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162A58
// Address: 0x162a58 - 0x162a70
void sub_00162A58_0x162a58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162A58_0x162a58");
#endif

    ctx->pc = 0x162a58u;

    // 0x162a58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a5c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162a60: 0x8c84004c  lw          $a0, 0x4C($a0)
    ctx->pc = 0x162a60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x162a64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162a64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162a68: 0x804f4b0  j           func_13D2C0
    ctx->pc = 0x162A68u;
    ctx->pc = 0x162A6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162A68u;
            // 0x162a6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D2C0u;
    if (runtime->hasFunction(0x13D2C0u)) {
        auto targetFn = runtime->lookupFunction(0x13D2C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D2C0_0x13d2c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162A70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
