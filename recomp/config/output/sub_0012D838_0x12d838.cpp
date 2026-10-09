#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D838
// Address: 0x12d838 - 0x12d868
void sub_0012D838_0x12d838(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D838_0x12d838");
#endif

    ctx->pc = 0x12d838u;

    // 0x12d838: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d838u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d83c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d83cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d840: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d840u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d844: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d844u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d848: 0x80493c4  j           func_124F10
    ctx->pc = 0x12D848u;
    ctx->pc = 0x12D84Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D848u;
            // 0x12d84c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F10u;
    if (runtime->hasFunction(0x124F10u)) {
        auto targetFn = runtime->lookupFunction(0x124F10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124F10_0x124f10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D850u;
    // 0x12d850: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d854: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d858: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d858u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d85c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d85cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d860: 0x80493c2  j           func_124F08
    ctx->pc = 0x12D860u;
    ctx->pc = 0x12D864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D860u;
            // 0x12d864: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F08u;
    if (runtime->hasFunction(0x124F08u)) {
        auto targetFn = runtime->lookupFunction(0x124F08u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124F08_0x124f08(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D868u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
