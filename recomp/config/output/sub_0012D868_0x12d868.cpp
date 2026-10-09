#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D868
// Address: 0x12d868 - 0x12d880
void sub_0012D868_0x12d868(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D868_0x12d868");
#endif

    ctx->pc = 0x12d868u;

    // 0x12d868: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d868u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d86c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d86cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d870: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d870u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d874: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d874u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d878: 0x80493c6  j           func_124F18
    ctx->pc = 0x12D878u;
    ctx->pc = 0x12D87Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D878u;
            // 0x12d87c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F18u;
    if (runtime->hasFunction(0x124F18u)) {
        auto targetFn = runtime->lookupFunction(0x124F18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124F18_0x124f18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D880u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
