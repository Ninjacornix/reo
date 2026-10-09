#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D820
// Address: 0x12d820 - 0x12d838
void sub_0012D820_0x12d820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D820_0x12d820");
#endif

    ctx->pc = 0x12d820u;

    // 0x12d820: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d824: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d828: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d828u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d82c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d82cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d830: 0x80493c0  j           func_124F00
    ctx->pc = 0x12D830u;
    ctx->pc = 0x12D834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D830u;
            // 0x12d834: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F00u;
    {
        auto targetFn = runtime->lookupFunction(0x124F00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x12D838u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
