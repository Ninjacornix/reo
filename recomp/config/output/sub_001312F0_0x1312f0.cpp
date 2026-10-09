#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001312F0
// Address: 0x1312f0 - 0x131304
void sub_001312F0_0x1312f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001312F0_0x1312f0");
#endif

    ctx->pc = 0x1312f0u;

    // 0x1312f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1312f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1312f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1312f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1312f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1312f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1312fc: 0x804e81e  j           func_13A078
    ctx->pc = 0x1312FCu;
    ctx->pc = 0x131300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312FCu;
            // 0x131300: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A078u;
    if (runtime->hasFunction(0x13A078u)) {
        auto targetFn = runtime->lookupFunction(0x13A078u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013A078_0x13a078(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131304u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
