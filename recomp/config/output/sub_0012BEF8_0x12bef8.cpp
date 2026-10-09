#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BEF8
// Address: 0x12bef8 - 0x12bf10
void sub_0012BEF8_0x12bef8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BEF8_0x12bef8");
#endif

    ctx->pc = 0x12bef8u;

    // 0x12bef8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12bef8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12befc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12befcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12bf00: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12bf00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12bf04: 0x8050802  j           func_142008
    ctx->pc = 0x12BF04u;
    ctx->pc = 0x12BF08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BF04u;
            // 0x12bf08: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142008u;
    if (runtime->hasFunction(0x142008u)) {
        auto targetFn = runtime->lookupFunction(0x142008u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00142008_0x142008(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12BF0Cu;
    // 0x12bf0c: 0x0  nop
    ctx->pc = 0x12bf0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
