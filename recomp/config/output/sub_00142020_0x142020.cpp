#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142020
// Address: 0x142020 - 0x142038
void sub_00142020_0x142020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142020_0x142020");
#endif

    ctx->pc = 0x142020u;

    // 0x142020: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x142020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x142024: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x142024u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x142028: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x142028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14202c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14202cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142030: 0x8050788  j           func_141E20
    ctx->pc = 0x142030u;
    ctx->pc = 0x142034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142030u;
            // 0x142034: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141E20u;
    if (runtime->hasFunction(0x141E20u)) {
        auto targetFn = runtime->lookupFunction(0x141E20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141E20_0x141e20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x142038u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
