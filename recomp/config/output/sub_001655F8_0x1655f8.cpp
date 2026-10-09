#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001655F8
// Address: 0x1655f8 - 0x165610
void sub_001655F8_0x1655f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001655F8_0x1655f8");
#endif

    ctx->pc = 0x1655f8u;

    // 0x1655f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1655f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1655fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1655fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x165600: 0x8c851b80  lw          $a1, 0x1B80($a0)
    ctx->pc = 0x165600u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7040)));
    // 0x165604: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x165604u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165608: 0x8059f40  j           func_167D00
    ctx->pc = 0x165608u;
    ctx->pc = 0x16560Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165608u;
            // 0x16560c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00167D00_0x167d00(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x165610u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
