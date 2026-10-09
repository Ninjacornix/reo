#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D8E0
// Address: 0x12d8e0 - 0x12d8f8
void sub_0012D8E0_0x12d8e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D8E0_0x12d8e0");
#endif

    ctx->pc = 0x12d8e0u;

    // 0x12d8e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d8e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d8e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d8e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d8e8: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d8e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d8ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d8ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d8f0: 0x80493d2  j           func_124F48
    ctx->pc = 0x12D8F0u;
    ctx->pc = 0x12D8F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D8F0u;
            // 0x12d8f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F48u;
    if (runtime->hasFunction(0x124F48u)) {
        auto targetFn = runtime->lookupFunction(0x124F48u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124F48_0x124f48(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D8F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
