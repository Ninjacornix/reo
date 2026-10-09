#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178FD0
// Address: 0x178fd0 - 0x178fec
void sub_00178FD0_0x178fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178FD0_0x178fd0");
#endif

    ctx->pc = 0x178fd0u;

    // 0x178fd0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x178fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x178fd4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x178fd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178fd8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x178fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x178fdc: 0x8c851c48  lw          $a1, 0x1C48($a0)
    ctx->pc = 0x178fdcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7240)));
    // 0x178fe0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x178fe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178fe4: 0x8059f0c  j           func_167C30
    ctx->pc = 0x178FE4u;
    ctx->pc = 0x178FE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178FE4u;
            // 0x178fe8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167C30u;
    if (runtime->hasFunction(0x167C30u)) {
        auto targetFn = runtime->lookupFunction(0x167C30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00167C30_0x167c30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178FECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
