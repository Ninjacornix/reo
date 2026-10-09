#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001647E0
// Address: 0x1647e0 - 0x1647fc
void sub_001647E0_0x1647e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001647E0_0x1647e0");
#endif

    ctx->pc = 0x1647e0u;

    // 0x1647e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1647e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1647e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1647e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1647e8: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x1647e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x1647ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1647ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1647f0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1647f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1647f4: 0x804c98e  j           func_132638
    ctx->pc = 0x1647F4u;
    ctx->pc = 0x1647F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1647F4u;
            // 0x1647f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132638u;
    if (runtime->hasFunction(0x132638u)) {
        auto targetFn = runtime->lookupFunction(0x132638u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00132638_0x132638(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1647FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
