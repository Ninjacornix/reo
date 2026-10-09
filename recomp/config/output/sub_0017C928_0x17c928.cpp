#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C928
// Address: 0x17c928 - 0x17c940
void sub_0017C928_0x17c928(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C928_0x17c928");
#endif

    ctx->pc = 0x17c928u;

    // 0x17c928: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c92c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c92cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c930: 0x8c84003c  lw          $a0, 0x3C($a0)
    ctx->pc = 0x17c930u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c934: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c934u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c938: 0x8053fa2  j           func_14FE88
    ctx->pc = 0x17C938u;
    ctx->pc = 0x17C93Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C938u;
            // 0x17c93c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14FE88u;
    {
        auto targetFn = runtime->lookupFunction(0x14FE88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x17C940u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
