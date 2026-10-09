#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001635E8
// Address: 0x1635e8 - 0x163608
void sub_001635E8_0x1635e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001635E8_0x1635e8");
#endif

    ctx->pc = 0x1635e8u;

    // 0x1635e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1635e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1635ec: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x1635ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x1635f0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1635f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1635f4: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x1635f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1635f8: 0x8c450748  lw          $a1, 0x748($v0)
    ctx->pc = 0x1635f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1864)));
    // 0x1635fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1635fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163600: 0x80506f8  j           func_141BE0
    ctx->pc = 0x163600u;
    ctx->pc = 0x163604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163600u;
            // 0x163604: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141BE0u;
    if (runtime->hasFunction(0x141BE0u)) {
        auto targetFn = runtime->lookupFunction(0x141BE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141BE0_0x141be0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163608u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
