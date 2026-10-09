#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131070
// Address: 0x131070 - 0x131088
void sub_00131070_0x131070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131070_0x131070");
#endif

    ctx->pc = 0x131070u;

    // 0x131070: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131070u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131074: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x131074u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131078: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x131078u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13107c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13107cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131080: 0x804a034  j           func_1280D0
    ctx->pc = 0x131080u;
    ctx->pc = 0x131084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131080u;
            // 0x131084: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131088u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
