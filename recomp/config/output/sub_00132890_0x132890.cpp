#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132890
// Address: 0x132890 - 0x1328a8
void sub_00132890_0x132890(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132890_0x132890");
#endif

    ctx->pc = 0x132890u;

    // 0x132890: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132890u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132894: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132898: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x132898u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x13289c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13289cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1328a0: 0x804b66e  j           func_12D9B8
    ctx->pc = 0x1328A0u;
    ctx->pc = 0x1328A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1328A0u;
            // 0x1328a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D9B8u;
    if (runtime->hasFunction(0x12D9B8u)) {
        auto targetFn = runtime->lookupFunction(0x12D9B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D9B8_0x12d9b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1328A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
