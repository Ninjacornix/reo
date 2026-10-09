#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A6F0
// Address: 0x10a6f0 - 0x10a70c
void sub_0010A6F0_0x10a6f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A6F0_0x10a6f0");
#endif

    ctx->pc = 0x10a6f0u;

    // 0x10a6f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a6f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a6f4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10a6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x10a6f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10a6f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10a6fc: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x10a6fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10a700: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10a700u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a704: 0x8042912  j           func_10A448
    ctx->pc = 0x10A704u;
    ctx->pc = 0x10A708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A704u;
            // 0x10a708: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A448u;
    if (runtime->hasFunction(0x10A448u)) {
        auto targetFn = runtime->lookupFunction(0x10A448u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010A448_0x10a448(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10A70Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
