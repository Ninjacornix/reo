#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C7E0
// Address: 0x17c7e0 - 0x17c800
void sub_0017C7E0_0x17c7e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C7E0_0x17c7e0");
#endif

    ctx->pc = 0x17c7e0u;

    // 0x17c7e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c7e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c7e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c7e8: 0x8c86003c  lw          $a2, 0x3C($a0)
    ctx->pc = 0x17c7e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c7ec: 0x8ca5004c  lw          $a1, 0x4C($a1)
    ctx->pc = 0x17c7ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x17c7f0: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x17c7f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x17c7f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c7f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c7f8: 0x805f834  j           func_17E0D0
    ctx->pc = 0x17C7F8u;
    ctx->pc = 0x17C7FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C7F8u;
            // 0x17c7fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E0D0u;
    if (runtime->hasFunction(0x17E0D0u)) {
        auto targetFn = runtime->lookupFunction(0x17E0D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E0D0_0x17e0d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C800u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
