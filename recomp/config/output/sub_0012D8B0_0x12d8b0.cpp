#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D8B0
// Address: 0x12d8b0 - 0x12d8c8
void sub_0012D8B0_0x12d8b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D8B0_0x12d8b0");
#endif

    ctx->pc = 0x12d8b0u;

    // 0x12d8b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d8b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d8b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d8b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d8b8: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d8b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d8bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d8bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d8c0: 0x80493ce  j           func_124F38
    ctx->pc = 0x12D8C0u;
    ctx->pc = 0x12D8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D8C0u;
            // 0x12d8c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F38u;
    if (runtime->hasFunction(0x124F38u)) {
        auto targetFn = runtime->lookupFunction(0x124F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124F38_0x124f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D8C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
