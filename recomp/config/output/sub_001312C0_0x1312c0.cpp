#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001312C0
// Address: 0x1312c0 - 0x1312d4
void sub_001312C0_0x1312c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001312C0_0x1312c0");
#endif

    ctx->pc = 0x1312c0u;

    // 0x1312c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1312c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1312c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1312c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1312c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1312c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1312cc: 0x804eb72  j           func_13ADC8
    ctx->pc = 0x1312CCu;
    ctx->pc = 0x1312D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312CCu;
            // 0x1312d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ADC8u;
    if (runtime->hasFunction(0x13ADC8u)) {
        auto targetFn = runtime->lookupFunction(0x13ADC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013ADC8_0x13adc8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1312D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
