#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F7D8
// Address: 0x15f7d8 - 0x15f7f0
void sub_0015F7D8_0x15f7d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F7D8_0x15f7d8");
#endif

    ctx->pc = 0x15f7d8u;

    // 0x15f7d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f7d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f7dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15f7dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15f7e0: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15f7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f7e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15f7e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f7e8: 0x805987a  j           func_1661E8
    ctx->pc = 0x15F7E8u;
    ctx->pc = 0x15F7ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F7E8u;
            // 0x15f7ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1661E8u;
    if (runtime->hasFunction(0x1661E8u)) {
        auto targetFn = runtime->lookupFunction(0x1661E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001661E8_0x1661e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F7F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
