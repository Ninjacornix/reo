#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C700
// Address: 0x12c700 - 0x12c718
void sub_0012C700_0x12c700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C700_0x12c700");
#endif

    ctx->pc = 0x12c700u;

    // 0x12c700: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c704: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c708: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c708u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c70c: 0x804fb14  j           func_13EC50
    ctx->pc = 0x12C70Cu;
    ctx->pc = 0x12C710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C70Cu;
            // 0x12c710: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EC50u;
    if (runtime->hasFunction(0x13EC50u)) {
        auto targetFn = runtime->lookupFunction(0x13EC50u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EC50_0x13ec50(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C714u;
    // 0x12c714: 0x0  nop
    ctx->pc = 0x12c714u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
