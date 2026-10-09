#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C718
// Address: 0x12c718 - 0x12c730
void sub_0012C718_0x12c718(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C718_0x12c718");
#endif

    ctx->pc = 0x12c718u;

    // 0x12c718: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c718u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c71c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c71cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c720: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c720u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c724: 0x804fb28  j           func_13ECA0
    ctx->pc = 0x12C724u;
    ctx->pc = 0x12C728u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C724u;
            // 0x12c728: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ECA0u;
    if (runtime->hasFunction(0x13ECA0u)) {
        auto targetFn = runtime->lookupFunction(0x13ECA0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013ECA0_0x13eca0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C72Cu;
    // 0x12c72c: 0x0  nop
    ctx->pc = 0x12c72cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
