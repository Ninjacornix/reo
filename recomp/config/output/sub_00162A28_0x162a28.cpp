#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162A28
// Address: 0x162a28 - 0x162a40
void sub_00162A28_0x162a28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162A28_0x162a28");
#endif

    ctx->pc = 0x162a28u;

    // 0x162a28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a2c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162a30: 0x8c84004c  lw          $a0, 0x4C($a0)
    ctx->pc = 0x162a30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x162a34: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162a34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162a38: 0x804f464  j           func_13D190
    ctx->pc = 0x162A38u;
    ctx->pc = 0x162A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162A38u;
            // 0x162a3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D190u;
    if (runtime->hasFunction(0x13D190u)) {
        auto targetFn = runtime->lookupFunction(0x13D190u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D190_0x13d190(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162A40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
